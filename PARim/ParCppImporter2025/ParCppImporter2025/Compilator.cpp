#include "Compilator.hpp"
#include "CompilatorValueTypes.hpp"
#include "TextFile.hpp"

using namespace std;

Compilator::Compilator(
	std::filesystem::path& arg_input_path,
	BinFile& arg_output_file_buffer,
	HashMaps& arg_hash_maps,
	uint64_t& arg_number_of_sections,
	bool& arg_error_handler
) :

	m_hash_maps(arg_hash_maps),
	m_output_file_buffer(arg_output_file_buffer),
	m_number_of_sections(arg_number_of_sections),
	m_number_of_obj_in_section(0),
	m_binary_value(0),
	m_bits_counter(0),

	m_special_function_lock(false),

	m_error_handler(arg_error_handler)
{
	TextFile input_file(arg_input_path);
	input_file.Informations();
	//input_file.ExitWhenFileDontExist();
	this->m_error_handler = !(input_file.GetIsOpened());
	
	if ((input_file.Empty() == false) && (this->m_error_handler == Globals::success_code))
	{
		input_file.DeleteComments();

		this->m_number_of_obj_in_section = input_file.CountOccurrencesOfText("struct ") - 1;

		input_file.DeleteContrCharAndPutToCleanFileVector();

		//const vector <char>& clean_file = input_file.GetCleanFileBuffer();
		CompileCppFileToBin(input_file.GetCleanFileBuffer());
	}
}


void Compilator::GetValuesFromString(
	string& arg_instruction,
	string& arg_value_type, 
	Enums::value_types_enum& arg_en_value_type,
	string& arg_name,
	string& arg_value
)
{
	while (1)
	{

		bool nopswitch = true;

		// Sprawdzenie czy jest prawidlowy typ
		for (uint32_t i = 0; i < CVT::number_of_compilator_value_types; ++i)
		{
			if (arg_instruction.starts_with(CVT::compilator_value_types[i]) )
			{
				arg_value_type = CVT::compilator_value_types[i];
				nopswitch = false;
				break;
			}
		}

		// Jesli typ byl nieprawidlowy czyli nopswitch == true to wychodze
		if (nopswitch == true)
		{
			arg_value_type = string();

			arg_en_value_type = Enums::value_types_enum::e_invalid;

			arg_name = string();
			arg_value = string();
			return;
		}
		//-----------------------------------

		// Wyodrebnienie nazwy od instrukcji
		const size_t val_type_len = arg_value_type.length();
		size_t eq_index = arg_instruction.find('=');
		size_t bracket_index = arg_instruction.find('[');
		if (eq_index != string::npos)
		{
			arg_name = arg_instruction.substr(val_type_len, eq_index - val_type_len);
		}

		if (bracket_index != string::npos)
		{
			arg_value_type += "[]";
			arg_name = arg_instruction.substr(val_type_len, bracket_index - val_type_len);
		}	
		//----------------------------------

		arg_en_value_type = this->m_hash_maps.m_hash_map_of_value_types_enums[arg_value_type];


		// Wyodrebnienie wartosci od instrukcji
		uint64_t valueindex = eq_index + 1;
		arg_value = arg_instruction.substr(valueindex, arg_instruction.length() - valueindex - 1);
		//-------------------------------------


		// Typ string lub tablica char[] lub GUID lub samo char
		if ( 
			arg_en_value_type == Enums::value_types_enum::e_string   ||
			arg_en_value_type == Enums::value_types_enum::e_char_arr ||
			arg_en_value_type == Enums::value_types_enum::e_GUID     ||
			arg_en_value_type == Enums::value_types_enum::e_char
			)
		{
			arg_value = arg_instruction.substr(valueindex + 1, arg_instruction.length() - (valueindex + 1) - 2);
			return;
		}

		// Typ struktury
		if (arg_en_value_type == Enums::value_types_enum::e_struct)
		{
			valueindex = arg_instruction.find("{") + 1;
			arg_instruction = arg_instruction.substr(valueindex, arg_instruction.length() - valueindex);

			arg_value_type = string();

			arg_en_value_type = Enums::value_types_enum::e_invalid;

			arg_name = string();
			arg_value = string();

			continue;
		}

		// Typ 1bitmask
		if (arg_en_value_type == Enums::value_types_enum::e_1bitmask)
		{
			this->m_binary_value.set(this->m_bits_counter, static_cast<bool>(arg_value[0] - '0' ));
			++this->m_bits_counter;
			return;
		}

		// This part is performed once per file.
		if (!this->m_special_function_lock)
		{
			if (arg_value == "count()" && arg_name.starts_with("number_of_"))
			{
				// Number of objs
				if (arg_name.ends_with("objects"))
				{
					this->m_special_function_lock = true; // <- lock special functions
					arg_value = to_string(this->m_number_of_obj_in_section);
					return;
				}

				// Number of sections
				if (arg_name.ends_with("sections"))
				{
					this->m_special_function_lock = true; // <- lock special functions
					arg_value = to_string(this->m_number_of_sections);
					return;
				}
			}
		}

		break;
	}

}


template <typename T>
void Compilator::WriteTabToFile(const string& str)
{
	this->m_output_file_buffer.WriteValue(static_cast<uint32_t>(CountValuesInTab(str)));

	T writed_value = 0;

	if (str == "{}") return;

	size_t instruction_index = 0;
	size_t instruction_len = 0;
	const size_t str_len = str.length();
	for (size_t i = 0; i < str_len; ++i)
	{
		if (str[i] == '{')
		{
			++instruction_index;
			continue;
		}

		if ((str[i] == ',') || (str[i] == '}'))
		{
			string scaned_value = str.substr(instruction_index, instruction_len);

			if (std::is_unsigned_v<T>)
			{
				writed_value = static_cast<T>(stoul(scaned_value));
			}
			else
			{
				writed_value = static_cast<T>(stol(scaned_value));
			}

			this->m_output_file_buffer.WriteValue(writed_value);

			instruction_len = 0;
			instruction_index = i + 1;

			continue;
		}

		++instruction_len;
	}
}

void Compilator::WriteBooleanTabToFile(const string& str)
{
	this->m_output_file_buffer.WriteValue(static_cast<uint32_t>(CountValuesInTab(str)));

	if (str == "{}") return;

	const char* ptr = str.data() + 1;
	const char* end = str.data() + str.size() - 1;

	while (ptr < end)
	{
		this->m_output_file_buffer.WriteValue( static_cast<uint8_t>( *ptr - '0' ) );
		ptr += 2;
	}
}


template <typename T>
void Compilator::WriteNBitMaskToFile(string& str)
{
	T writed_value = 0;

	if (str == "()") return;

	size_t instruction_index = 0;
	size_t instruction_len = 0;
	const size_t str_len = str.length();
	for (size_t i = 0; i < str_len; ++i)
	{
		if (str[i] == '(')
		{
			++instruction_index;
			continue;
		}

		if ((str[i] == '|') || (str[i] == ')'))
		{
			string scanedvalue = str.substr(instruction_index, instruction_len);

			writed_value |= this->m_hash_maps.m_list_of_masks[scanedvalue];

			instruction_len = 0;
			instruction_index = i + 1;

			continue;
		}

		++instruction_len;
	}

	this->m_output_file_buffer.WriteValue(writed_value);

}



void Compilator::WriteInstructionToBin(string& value_type, Enums::value_types_enum& en_value_type, string& value)
{

	if (en_value_type == Enums::value_types_enum::e_invalid)
		return;

	// 1bitmask
	if ((en_value_type == Enums::value_types_enum::e_1bitmask) && (m_bits_counter == Globals::byte_to_bits))
	{
		this->m_output_file_buffer.WriteValue( static_cast<uint8_t>(m_binary_value.to_ulong()) );
		m_binary_value.reset();
		m_bits_counter = 0;
		return;
	}

	// uints
	if (value_type.starts_with('u'))
	{
		// uint32_t
		if (en_value_type == Enums::value_types_enum::e_uint32_t)
		{
			this->m_output_file_buffer.WriteValue(static_cast<uint32_t>(stoul(value)));
			return;
		}

		// uint8_t
		if (en_value_type == Enums::value_types_enum::e_uint8_t)
		{
			this->m_output_file_buffer.WriteValue( static_cast<uint8_t>( stoul(value) ) );
			return;
		}

		// uint16_t
		if (en_value_type == Enums::value_types_enum::e_uint16_t)
		{
			this->m_output_file_buffer.WriteValue(static_cast<uint16_t>(stoul(value)));
			return;
		}

		// uint64_t
		if (en_value_type == Enums::value_types_enum::e_uint64_t)
		{
			this->m_output_file_buffer.WriteValue(static_cast<uint64_t>(stoull(value)));
			return;
		}

		// uint32_t[]
		if (en_value_type == Enums::value_types_enum::e_uint32_t_arr)
		{
			WriteTabToFile<uint32_t>(value);
			return;
		}


		// uint8_t[]
		if (en_value_type == Enums::value_types_enum::e_uint8_t_arr)
		{
			WriteTabToFile<uint8_t>(value);

			return;
		}

		// uint16_t[]
		if (en_value_type == Enums::value_types_enum::e_uint16_t_arr)
		{
			WriteTabToFile<uint16_t>(value);

			return;
		}

		// uint64_t[]
		if (en_value_type == Enums::value_types_enum::e_uint64_t_arr)
		{
			WriteTabToFile<uint64_t>(value);

			return;
		}
	}

	// string
	if (en_value_type == Enums::value_types_enum::e_string)
	{
		uint32_t string_len = static_cast<uint32_t>(value.size());
		this->m_output_file_buffer.WriteValue(string_len);
		this->m_output_file_buffer.WriteString(value);
		return;
	}

	// 32bituniquekey
	if (en_value_type == Enums::value_types_enum::e_32bituniquekey)
	{
		this->m_output_file_buffer.WriteValue(this->m_hash_maps.m_list_of_consts[value]);
		return;
	}

	// bool
	if (en_value_type == Enums::value_types_enum::e_bool)
	{
		bool boolean_val = this->m_hash_maps.m_hash_map_of_boolean_values[value];
		this->m_output_file_buffer.WriteValue(boolean_val);
		return;
	}

	// bool[]
	if (en_value_type == Enums::value_types_enum::e_bool_arr)
	{
		WriteBooleanTabToFile(value);
		return;
	}


	if ( value_type.starts_with('i') )
	{

		// int32_t albo int
		if (en_value_type == Enums::value_types_enum::e_int32_t)
		{
			this->m_output_file_buffer.WriteValue(static_cast<int32_t>(stol(value)));
			return;
		}

		// int8_t
		if (en_value_type == Enums::value_types_enum::e_int8_t)
		{
			this->m_output_file_buffer.WriteValue(static_cast<int8_t>(stol(value)));
			return;
		}

		// int16_t
		if (en_value_type == Enums::value_types_enum::e_int16_t)
		{
			this->m_output_file_buffer.WriteValue(static_cast<int16_t>(stol(value)));
			return;
		}

		// int64_t
		if (en_value_type == Enums::value_types_enum::e_int64_t)
		{
			this->m_output_file_buffer.WriteValue(static_cast<int64_t>(stoll(value)));
			return;
		}


		// int32_t[] albo int[]
		if (en_value_type == Enums::value_types_enum::e_int32_t_arr)
		{
			WriteTabToFile<int32_t>(value);
			return;
		}

		// int8_t[]
		if (en_value_type == Enums::value_types_enum::e_int8_t_arr)
		{
			WriteTabToFile<int8_t>(value);

			return;
		}


		// int16_t[]
		if (en_value_type == Enums::value_types_enum::e_int16_t_arr)
		{
			WriteTabToFile<int16_t>(value);

			return;
		}


		// int64_t[]
		if (en_value_type == Enums::value_types_enum::e_int64_t_arr)
		{
			WriteTabToFile<int64_t>(value);

			return;
		}

	}

	// 8bitmask
	if (en_value_type == Enums::value_types_enum::e_8bitmask)
	{
		WriteNBitMaskToFile<uint8_t>(value);

		return;
	}

	// 32bitmask
	if (en_value_type == Enums::value_types_enum::e_32bitmask)
	{
		WriteNBitMaskToFile<uint32_t>(value);

		return;
	}


	//  char || char[]
	if (en_value_type == Enums::value_types_enum::e_char || en_value_type == Enums::value_types_enum::e_char_arr)
	{
		this->m_output_file_buffer.WriteString(value);
		return;
	}

	// GUID
	if (en_value_type == Enums::value_types_enum::e_GUID)
	{
		this->m_output_file_buffer.WriteGuid(value);
		return;
	}


}

/*
void Compilator::CompileCppFileToBin(const vector <char>& arg_clean_file)
{
	const size_t clean_file_size = arg_clean_file.size();

	size_t instruction_index = 0;
	size_t instruction_len = 0;

	string ins_value_type = string();
	Enums::value_types_enum	en_ins_value_type = Enums::value_types_enum::e_invalid;
	string ins_name = string();
	string ins_value = string();


	for (size_t i = 0; i < clean_file_size; ++i)
	{
		++instruction_len;

		if (arg_clean_file[i] == ';')
		{
			const char* str_data = reinterpret_cast<const char*>(&arg_clean_file[instruction_index]);
			string instruction(str_data, instruction_len);

			DEBUG_PRINT("----", Mess::endl, instruction, Mess::endl);

			GetValuesFromString(instruction, ins_value_type, en_ins_value_type, ins_name, ins_value);

			WriteInstructionToBin(ins_value_type, en_ins_value_type, ins_value);

			DEBUG_PRINT(ins_value_type, Mess::endl, ins_name, Mess::endl, ins_value, Mess::endl, "----", Mess::endl);

			en_ins_value_type = Enums::value_types_enum::e_invalid;

			ins_value_type = string();
			ins_name = string();
			ins_value = string();

			instruction_len = 0;
			instruction_index = i + 1;
		}
	}
}
*/


void Compilator::CompileCppFileToBin(const vector<char>& arg_clean_file)
{
	string_view file_view(arg_clean_file.data(), arg_clean_file.size());

	string ins_value_type;
	string ins_name;
	string ins_value;
	Enums::value_types_enum en_ins_value_type = Enums::value_types_enum::e_invalid;

	size_t start = 0;
	while (true)
	{
		size_t end = file_view.find(';', start);

		if (end == string_view::npos)
			break;

		string instruction(file_view.substr(start, end - start + 1)); 

		DEBUG_PRINT("----", Mess::endl, instruction, Mess::endl);

		GetValuesFromString(instruction, ins_value_type, en_ins_value_type, ins_name, ins_value);
		WriteInstructionToBin(ins_value_type, en_ins_value_type, ins_value);

		DEBUG_PRINT(ins_value_type, Mess::endl, ins_name, Mess::endl, ins_value, Mess::endl, "----", Mess::endl);

		// Reset wartosci
		en_ins_value_type = Enums::value_types_enum::e_invalid;
		ins_value_type.clear();
		ins_name.clear();
		ins_value.clear();

		start = end + 1;
	}
}
