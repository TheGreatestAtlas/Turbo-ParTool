#include "ParCppImporter2025.hpp"

//------------------------
// Input File Buffer Class
//------------------------

constexpr int byte_to_bits = 8;

std::unordered_map<std::string, uint32_t> list_of_consts = {};
std::unordered_map<std::string, uint32_t> list_of_masks = {};

constexpr size_t number_of_value_types = 33;
const char* value_types[] = {
    "char",
	"char[]",

    "uint8_t",
	"uint8_t[]",

    "uint16_t",
	"uint16_t[]",

    "uint32_t",
	"uint32_t[]",

    "uint64_t",
	"uint64_t[]",

    "GUID",
    "string",
    "struct",

	"int8_t",
	"int8_t[]",

	"int16_t",
	"int16_t[]",

	"int32_t",
	"int32_t[]",

	"int64_t",
	"int64_t[]",

	"short",
	"short[]",

	"int",
	"int[]",

	"longint",
	"longint[]",

	"bool",
	"bool[]",

	"1bitmask",

	"32bitmask",

	"8bitmask",

	"32bituniquekey"
};

InputBinFile::InputBinFile(std::string argfilename) : m_file_name( argfilename ), m_is_opened(false),
m_is_open_now(false), m_file_length(0),
m_file_buffer(nullptr)
{
	DEBUG_PRINT("Nazwa pliku:");
	DEBUG_PRINT( m_file_name.c_str() );
	DEBUG_PRINT("\n");

	OpenAndReadFile();
	
}

void InputBinFile::OpenAndReadFile()
{
	m_input_file.open(m_file_name, std::ios::in | std::ios::binary | std::ios::ate);

	if (m_input_file)
	{
		m_is_opened = m_is_open_now = true;
		m_file_length = m_input_file.tellg();
		m_input_file.seekg(0);
		m_file_buffer = new uint8_t[m_file_length];
		m_input_file.read(reinterpret_cast<char*>(m_file_buffer), m_file_length);
		m_input_file.close();
		m_is_open_now = false;
	}

}

bool InputBinFile::GetIsOpened() const { return m_is_opened; }
bool InputBinFile::GetIsOpenNow() const { return m_is_open_now; }
uint64_t InputBinFile::GetFileLength() const { return m_file_length; }

InputBinFile::~InputBinFile()
{
	if (m_is_open_now == false && m_is_opened == true)
		delete[] m_file_buffer;
	
}

void InputBinFile::Informations(std::ostream& o) const
{
	if (m_is_opened == 0)
	{
		o << std::endl
			<< "ERROR: The specified file could not be opened." << std::endl
			<< "-------------------------------------" << std::endl
			<< "Opening the file:" << m_file_name << std::endl
			<< "Was the file successfully opened?: " << m_is_opened << std::endl
			<< "Is the file currently open?: " << m_is_open_now << std::endl
			<< "-------------------------------------" << std::endl
			<< std::endl;
	}

}

void InputBinFile::ExitWhenFileDontExist(std::ostream& o) const
{
	if (m_is_opened == false && m_is_open_now == false)
	{
		o << "The specified file does not exist!" << std::endl;
		exit(EXIT_FAILURE);
	}
}

//------------------
// Klasa Compilator
//------------------

static size_t CountOccurrences(const uint8_t* buffer, size_t& size, const std::string& word)
{
	std::string data(reinterpret_cast<const char*>(buffer), size);

	size_t count = 0;
	size_t pos = data.find(word, 0);

	while (pos != std::string::npos)
	{
		++count;
		pos = data.find(word, pos + word.length()); // Przesuwamy indeks za znalezione s³owo
	}

	return count;
}


Compilator::Compilator(uint8_t* argfilebuffer, int64_t argfilelength):
    m_file_buffer(argfilebuffer), m_file_length(argfilelength), //Argumenty wejsciowe konstruktora
	
    //Lista inicjalizacyjna reszty zmiennych:
	m_its_string(false), m_its_comment(false), 
    m_instruction( std::string() ), m_value_type( std::string() ), m_name( std::string() ), m_value( std::string() ),
	m_number_of_obj_in_section(0), m_binary_value(std::string()), m_bits_counter(0)
{

	if (m_file_buffer != nullptr && m_file_length != 0)
	{
		DeleteComments();

		m_number_of_obj_in_section = CountOccurrences(m_file_buffer, m_file_length,"struct ") - 1;

		DeleteContrCharAndPutToVector();
	}

}


void Compilator::DeleteComments()
{
	for (uint64_t i = 0; i < m_file_length - 1; ++i)
	{
		if ((m_file_buffer[i] == '/') && (m_file_buffer[i + 1] == '/'))
		{
			m_its_comment = !(m_its_comment);
		}

		if ((m_file_buffer[i] == 0x0D) && (m_file_buffer[i + 1] == 0x0A) && (m_its_comment == true))
		{
			m_its_comment = !(m_its_comment);
		}

		if (m_its_comment == true)
		{
			m_file_buffer[i] = ' ';
			continue;
		}
	}

}


void Compilator::DeleteContrCharAndPutToVector()
{
	for (uint64_t i = 0; i < m_file_length - 1; ++i)
	{
		if (m_file_buffer[i] == '\"')
		{
			m_its_string = !m_its_string;
		}

		if((m_file_buffer[i] <= 32) && (m_its_string == false))
		{
			continue;
		}

		m_clean_file.push_back(m_file_buffer[i]);
	}
}

void Compilator::GetValuesFromString()
{
	while (1)
	{

		bool nopswitch = true;

		//Sprawdzenie czy jest prawidlowy typ
		for (uint32_t i = 0; i < number_of_value_types; ++i)
		{
			if (m_instruction.substr(0, std::string(value_types[i]).length()) == value_types[i])
			{
				m_value_type = value_types[i];
				nopswitch = false;
				break;
			}
		}

		// Jesli typ byl nieprawidlowy czyli nopswitch == true to wychodze
		if (nopswitch == true)
		{
			m_value_type = "nop";
			m_name = std::string();
			m_value = std::string();
			return;
		}

		//Wyodrebnienie nazwy od instrukcji
		for (uint64_t i = m_value_type.length(); i < m_instruction.length(); ++i)
		{
			if ((m_instruction[i] == '=') || (m_instruction[i] == '['))
			{
				if (m_instruction[i] == '[')
				{
					m_value_type += "[]";
				}

				break;
			}

			m_name += m_instruction[i];
		}

		//Wyodrebnienie wartosci od instrukcji
		uint64_t valueindex = m_instruction.find("=") + 1;
		m_value = m_instruction.substr(valueindex, m_instruction.length() - valueindex - 1);


		// Typ string lub tablica char[] lub GUID lub samo char
		if ((m_value_type == "string") || (m_value_type == "char[]") || (m_value_type == "GUID") || (m_value_type == "char"))
		{
			m_value = m_instruction.substr(valueindex + 1, m_instruction.length() - (valueindex + 1) - 2);
			return;
		}

		// Typ struktury
		if (m_value_type == "struct")
		{
			valueindex = m_instruction.find("{") + 1;
			m_instruction = m_instruction.substr(valueindex, m_instruction.length() - valueindex);

			m_value_type = std::string();
			m_name = std::string();
			m_value = std::string();

			continue;

			//GetValuesFromString();
		}

		// Typ 1bitmask
		if (m_value_type == "1bitmask")
		{
			m_binary_value += m_value;
			++m_bits_counter;
			return;
		}

		// Number of objs
		if (m_value_type == "uint32_t" && m_name == "number_of_objects" && m_value == "count()")
		{
			m_value = std::to_string(m_number_of_obj_in_section);
			return;
		}

		// Number of sections
		if (m_value_type == "uint64_t" && m_name == "number_of_sections" && m_value == "count()")
		{
			m_value = std::to_string(ParCompilatorOverlay::m_number_of_sections);
			return;
		}

		// Typ boolean
		if (m_value_type == "bool")
		{
			if (m_value == "true")
			{
				m_value = "1";
			}
			if (m_value == "false")
			{
				m_value = "0";
			}
			return;
		}


		break;
	}

}

std::vector<char> Compilator::output_file_buffer = {};

template<typename T>
void Compilator::WriteRaw(std::vector<char>& buf, const T& val)
{
	const char* ptr = reinterpret_cast<const char*>(&val);
	buf.insert(buf.end(), ptr, ptr + sizeof(T));
}

void Compilator::WriteGUID(std::string& slowo)
{
	uint32_t four_bytes = stoul(slowo.substr(0, 8), nullptr, 16);
	//outputfile.write(reinterpret_cast<char*>(&four_bytes),sizeof(four_bytes) );
	WriteRaw<uint32_t>(output_file_buffer, four_bytes);

	uint16_t two_bytes = static_cast<uint16_t>(stoul( slowo.substr(9, 4), nullptr, 16));
	//outputfile.write(reinterpret_cast<char*>(&two_bytes), sizeof(two_bytes));
	WriteRaw<uint16_t>(output_file_buffer, two_bytes);

	two_bytes = static_cast<uint16_t>(stoul(slowo.substr(14, 4), nullptr, 16));
	//outputfile.write(reinterpret_cast<char*>(&two_bytes), sizeof(two_bytes));
	WriteRaw<uint16_t>(output_file_buffer, two_bytes);

	two_bytes = static_cast<uint16_t>(_byteswap_ushort(  static_cast<unsigned short>(stoul(slowo.substr(19, 4), nullptr, 16) )   ));
	//outputfile.write(reinterpret_cast<char*>(&two_bytes), sizeof(two_bytes));
	WriteRaw<uint16_t>(output_file_buffer, two_bytes);

	four_bytes = static_cast<uint32_t>(_byteswap_ulong(stoul(slowo.substr(24, 8), nullptr, 16)));
	//outputfile.write(reinterpret_cast<char*>(&four_bytes), sizeof(four_bytes));
	WriteRaw<uint32_t>(output_file_buffer, four_bytes);

	two_bytes = static_cast<uint32_t>(_byteswap_ushort(  static_cast<unsigned short>( stoul(slowo.substr(32, 4), nullptr, 16) ) ));
	//outputfile.write(reinterpret_cast<char*>(&two_bytes), sizeof(two_bytes));
	WriteRaw<uint16_t>(output_file_buffer, two_bytes);

}


void Compilator::WriteString(std::string& str)
{

	WriteRaw<uint32_t>(output_file_buffer, static_cast<uint32_t>(str.length()));
	//uint32_t stringsize = static_cast<uint32_t>(str.length());
	//WriteRaw<uint32_t>(output_file_buffer, stringsize);

	//outputfile.write(reinterpret_cast<char*>(&stringsize), sizeof(stringsize));
	
	output_file_buffer.insert(output_file_buffer.end(), str.begin(), str.end());
	
	//outputfile << str;
}

template <typename T>
void Compilator::WriteValueToFile(std::string& value, uint8_t mode)
{
	T typevalue;

	switch (mode)
	{
		case 'u':
			typevalue = static_cast<T>(std::stoul(value));
		break;

		case 'd':
			typevalue = static_cast<T>(std::stol(value));
		break;

		default: break;
	}

	WriteRaw<T>(output_file_buffer, typevalue);

	//output.write(reinterpret_cast<char*>(&typevalue), sizeof(typevalue));
}



template <typename T>
void Compilator::WriteTabToFile(std::string& str, uint8_t mode)
{
	T writedvalue = 0;

	if (m_value == "{}") return;

	std::string scanedvalue = std::string();
	for (uint64_t i = 0;i < str.length(); ++i)
	{
		if (str[i] == '{') continue;


		if ((str[i] == ',') || (str[i] == '}'))
		{

			switch (mode)
			{

			case 'd': writedvalue = static_cast<T>(stol(scanedvalue));  break;
			case 'u': writedvalue = static_cast<T>(stoul(scanedvalue)); break;
			default: break;
			}

			WriteRaw<T>(output_file_buffer, writedvalue);
			
			//outputfile.write(reinterpret_cast<char*>(&writedvalue), sizeof(writedvalue));

			scanedvalue = std::string();
			continue;
		}

		scanedvalue += str[i];
	}
}


template <typename T>
void Compilator::WriteNBitMaskToFile(std::string& str)
{

	T writedvalue = 0;
	//T single_mask_value = 0;

	if (m_value == "()") return;

	std::string scanedvalue = std::string();
	for (uint64_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == '(') continue;


		if ((str[i] == '|') || (str[i] == ')'))
		{
			//single_mask_value = list_of_masks[scanedvalue];
			//writedvalue |= single_mask_value;

			writedvalue |= list_of_masks[scanedvalue];
			
			scanedvalue = std::string();
			continue;
		}

		scanedvalue += str[i];
	}

	WriteRaw<T>(output_file_buffer, writedvalue);

	//outputfile.write(reinterpret_cast<char*>(&writedvalue), sizeof(writedvalue));
}



uint64_t Compilator::CountValuesInTab(std::string& value)
{
	uint64_t tabsize = 0;

	for (uint64_t i = 0; i < value.length(); ++i)
	{
		if (value[i] == ',') 
			++tabsize;
	}

	if(tabsize != 0) ++tabsize;

	return tabsize;
}


void Compilator::WriteInstructionToBin(std::string& valuetype, std::string& name, std::string& value)
{
	// 1bitmask
	if ((valuetype == value_types[29]) && (m_bits_counter == byte_to_bits))
	{
		m_binary_value = std::string(m_binary_value.rbegin(), m_binary_value.rend());

		output_file_buffer.push_back(static_cast<uint8_t>(std::stoul(m_binary_value, nullptr, 2)));
		m_binary_value = std::string();
		m_bits_counter = 0;

		return;
	}

	// uints
	if (valuetype.substr(0, 4) == "uint")
	{
		// uint32_t
		if (valuetype == value_types[6])
		{
			WriteValueToFile<uint32_t>(value, 'u');
			return;
		}

		// uint8_t
		if (valuetype == value_types[2])
		{
			output_file_buffer.push_back(static_cast<uint8_t>(std::stoul(value)));
			return;
		}

		// uint16_t
		if (valuetype == value_types[4])
		{
			WriteValueToFile<uint16_t>(value, 'u');
			return;
		}

		// uint64_t
		if (valuetype == value_types[8])
		{
			WriteValueToFile<uint64_t>(value, 'u');
			return;
		}

		// uint32_t[]
		if (valuetype == value_types[7])
		{
			//uint32_t tabsize = static_cast<uint32_t>(CountValuesInTab(value));

			WriteRaw<uint32_t>(output_file_buffer, static_cast<uint32_t>(CountValuesInTab(value)));
			//outputfile.write(reinterpret_cast<char*>(&tabsize), sizeof(tabsize));

			WriteTabToFile<uint32_t>(value, 'u');

			return;
		}


		// uint8_t[]
		if (valuetype == value_types[3])
		{
			//uint32_t tabsize = static_cast<uint32_t>(CountValuesInTab(value));

			WriteRaw<uint32_t>(output_file_buffer, static_cast<uint32_t>(CountValuesInTab(value)));
			//outputfile.write(reinterpret_cast<char*>(&tabsize), sizeof(tabsize));

			WriteTabToFile<uint8_t>(value, 'u');

			return;
		}

		// uint16_t[]
		if (valuetype == value_types[5])
		{
			//uint32_t tabsize = static_cast<uint32_t>(CountValuesInTab(value));

			WriteRaw<uint32_t>(output_file_buffer, static_cast<uint32_t>(CountValuesInTab(value)));
			//outputfile.write(reinterpret_cast<char*>(&tabsize), sizeof(tabsize));

			WriteTabToFile<uint16_t>(value, 'u');

			return;
		}

		// uint64_t[]
		if (valuetype == value_types[9])
		{
			//uint32_t tabsize = static_cast<uint32_t>(CountValuesInTab(value));

			WriteRaw<uint32_t>(output_file_buffer, static_cast<uint32_t>(CountValuesInTab(value)));
			//outputfile.write(reinterpret_cast<char*>(&tabsize), sizeof(tabsize));

			WriteTabToFile<uint64_t>(value, 'u');

			return;
		}
	}

	// string
	if (valuetype == value_types[11])
	{
		WriteString(value);
		return;
	}

	// 32bituniquekey
	if (valuetype == value_types[32])
	{
		WriteRaw<uint32_t>(output_file_buffer, list_of_consts[value]);
		return;
	}

	// bool
	if (valuetype == value_types[27])
	{
		output_file_buffer.push_back(static_cast<int8_t>(std::stol(value)));
		return;
	}

	// bool[]
	if (valuetype == value_types[28])
	{
		//uint32_t tabsize = static_cast<uint32_t>(CountValuesInTab(value));

		WriteRaw<uint32_t>(output_file_buffer, static_cast<uint32_t>(CountValuesInTab(value)) );
		//outputfile.write(reinterpret_cast<char*>(&tabsize), sizeof(tabsize));

		WriteTabToFile<int8_t>(value, 'd');

		return;
	}


	if (valuetype.substr(0, 3) == "int")
	{

		// int32_t albo int
		if ((valuetype == value_types[17]) || (valuetype == value_types[23]))
		{
			WriteValueToFile<int32_t>(value, 'd');
			return;
		}

		// int8_t
		if (valuetype == value_types[13])
		{
			output_file_buffer.push_back(static_cast<int8_t>(std::stol(value)));
			return;
		}

		// int16_t 
		if (valuetype == value_types[15])
		{
			WriteValueToFile<int16_t>(value, 'd');
			return;
		}

		// int64_t 
		if (valuetype == value_types[19])
		{
			WriteValueToFile<int64_t>(value, 'd');
			return;
		}


		// int32_t[] albo int[]
		if ((valuetype == value_types[18]) || (valuetype == value_types[24]))
		{
			//uint32_t tabsize = static_cast<uint32_t>(CountValuesInTab(value));

			WriteRaw<uint32_t>(output_file_buffer, static_cast<uint32_t>(CountValuesInTab(value)));
			//outputfile.write(reinterpret_cast<char*>(&tabsize), sizeof(tabsize));

			WriteTabToFile<int32_t>(value, 'd');

			return;
		}

		// int8_t[]
		if (valuetype == value_types[14])
		{
			//uint32_t tabsize = static_cast<uint32_t>(CountValuesInTab(value));

			WriteRaw<uint32_t>(output_file_buffer, static_cast<uint32_t>(CountValuesInTab(value)));
			//outputfile.write(reinterpret_cast<char*>(&tabsize), sizeof(tabsize));

			WriteTabToFile<int8_t>(value, 'd');

			return;
		}


		// int16_t[] 
		if (valuetype == value_types[16])
		{
			//uint32_t tabsize = static_cast<uint32_t>(CountValuesInTab(value));

			WriteRaw<uint32_t>(output_file_buffer, static_cast<uint32_t>(CountValuesInTab(value)));
			//outputfile.write(reinterpret_cast<char*>(&tabsize), sizeof(tabsize));

			WriteTabToFile<int16_t>(value, 'd');

			return;
		}


		// int64_t[] 
		if (valuetype == value_types[20])
		{
			//uint32_t tabsize = static_cast<uint32_t>(CountValuesInTab(value));

			WriteRaw<uint32_t>(output_file_buffer, static_cast<uint32_t>(CountValuesInTab(value)));
			//outputfile.write(reinterpret_cast<char*>(&tabsize), sizeof(tabsize));

			WriteTabToFile<int64_t>(value, 'd');

			return;
		}

	}

	// 8bitmask
	if (valuetype == value_types[31])
	{
		WriteNBitMaskToFile<uint8_t>(value);

		return;
	}

	// 32bitmask
	if (valuetype == value_types[30])
	{
		WriteNBitMaskToFile<uint32_t>(value);

		return;
	}


	//  char || char[]
	if ((valuetype == value_types[0]) || (valuetype == value_types[1]))
	{
		output_file_buffer.insert(output_file_buffer.end(), value.begin(), value.end());
		return;
	}

	// short
	if (valuetype == value_types[21])
	{
		WriteValueToFile<int16_t>(value, 'd');
		return;
	}

	// short[]
	if (valuetype == value_types[22])
	{
		//uint32_t tabsize = static_cast<uint32_t>(CountValuesInTab(value));

		WriteRaw<uint32_t>(output_file_buffer, static_cast<uint32_t>(CountValuesInTab(value)));
		//outputfile.write(reinterpret_cast<char*>(&tabsize), sizeof(tabsize));

		WriteTabToFile<int16_t>(value, 'd');

		return;
	}

	// long int
	if (valuetype == value_types[25])
	{
		WriteValueToFile<int64_t>(value, 'd');
		return;
	}

	// long int[]
	if (valuetype == value_types[26])
	{
		//uint32_t tabsize = static_cast<uint32_t>(CountValuesInTab(value));

		WriteRaw<uint32_t>(output_file_buffer, static_cast<uint32_t>(CountValuesInTab(value)));
		//outputfile.write(reinterpret_cast<char*>(&tabsize), sizeof(tabsize));

		WriteTabToFile<int64_t>(value, 'd');

		return;
	}


	// GUID
	if (valuetype == value_types[10])
	{
		WriteGUID(value);
		return;
	}


}

//Txt
void Compilator::CompileTxtFileToBin()
{
	for (uint64_t i = 0; i < m_clean_file.size(); ++i)
	{
		m_instruction += m_clean_file[i];

		if (m_clean_file[i] == ';')
		{
			DEBUG_PRINT("----\n");
			DEBUG_PRINT(m_instruction.c_str());
			DEBUG_PRINT("\n");

			GetValuesFromString();
			WriteInstructionToBin(m_value_type, m_name, m_value);

			DEBUG_PRINT(m_value_type.c_str()); DEBUG_PRINT("\n");
			DEBUG_PRINT(m_name.c_str()); DEBUG_PRINT("\n");
			DEBUG_PRINT(m_value.c_str()); DEBUG_PRINT("\n");
			DEBUG_PRINT("----\n");

			m_instruction = std::string();
			m_value_type = std::string();
			m_name = std::string();
			m_value = std::string();
		}
	}
}

void Compilator::SaveOutputFileBufferToBin(std::fstream& outputfile, std::string& output_file_name)
{

	outputfile.open(output_file_name, std::ios::out | std::ios::binary);

	outputfile.write(reinterpret_cast<char*>(&output_file_buffer[0]), output_file_buffer.size());

	outputfile.close();

}


//--------------------------
//Klasa MapCompilatorOverlay
//--------------------------
void ParCompilatorOverlay::InitializeHashMap()
{
	list_of_consts["NULL"] = 0;
	list_of_consts["magicImmortalShield"] = 1;
	list_of_consts["magicFreeze"] = 2;
	list_of_consts["magicCapturing"] = 3;
	list_of_consts["magicStorm"] = 4;
	list_of_consts["magicSeeing"] = 5;
	list_of_consts["magicConversion"] = 6;
	list_of_consts["magicFireRain"] = 7;
	list_of_consts["magicRemoveStormFireRain"] = 8;
	list_of_consts["magicTeleportation"] = 9;
	list_of_consts["magicGhost"] = 10;
	list_of_consts["magicWildAnimal"] = 11;
	list_of_consts["magicTrap"] = 12;
	list_of_consts["magicGetHP"] = 13;
	list_of_consts["magicSingleFreeze"] = 14;
	list_of_consts["magicBlindAttack"] = 15;
	list_of_consts["magicTimedCapturing"] = 16;
	list_of_consts["magicOurWildAnimal"] = 17;
	list_of_consts["magicOurHoldWildAnimal"] = 18;
	list_of_consts["magicOurMagicMirror"] = 19;
	list_of_consts["magicRandConversion"] = 20;
	list_of_consts["magicAroundDamage"] = 21;
	list_of_consts["magicSelfHealing"] = 22;
	list_of_consts["magicFireWall"] = 23;
	list_of_consts["noEarthquake"] = 0x00;
	list_of_consts["smallEarthquake"] = 0x01;
	list_of_consts["mediumEarthquake"] = 0x02;
	list_of_consts["bigEarthquake"] = 0x03;
	list_of_consts["typeHoldTrap"] = 1;
	list_of_consts["typeDamageTrap"] = 2;
	list_of_consts["typeHoldTrapOnce"] = 3;
	list_of_consts["missileSword"] = 1;
	list_of_consts["missileInvisible"] = 2;
	list_of_consts["missileCannon"] = 3;
	list_of_consts["missileDropBomb"] = 4;
	list_of_consts["missileBomb"] = 5;
	list_of_consts["missileElectric"] = 6;
	list_of_consts["missileLightning"] = 7;
	list_of_consts["missileMeteor"] = 8;

	list_of_consts["buildingNormal"] = 0;
	list_of_consts["buildingFactory"] = 1;
	list_of_consts["buildingHarvestFactory"] = 2;
	list_of_consts["buildingGate"] = 3;
	list_of_consts["buildingBridgeGate"] = 4;
	list_of_consts["buildingTower"] = 5;
	list_of_consts["buildingWall"] = 6;
	list_of_consts["buildingCopula"] = 7;

	list_of_consts["smallFlyingWaste"] = 0;
	list_of_consts["mediumFlyingWaste"] = 1;
	list_of_consts["bigFlyingWaste"] = 2;

	list_of_consts["groupSword"] = 91;
	list_of_consts["groupDrop"] = 92;
	list_of_consts["groupMag"] = 93;
	list_of_consts["groupSpecial"] = 94;
	list_of_consts["groupAnimal"] = 95;
	list_of_consts["groupMulti"] = 96;
	list_of_consts["groupBuilding"] = 97;

	list_of_consts["positionStartingPoint"] = 0;
	list_of_consts["positionMarkPoint"] = 1;
	list_of_consts["positionProductionPoint"] = 2;

	list_of_consts["eCanBePlayedInSkirmish"] = 0x01;

	list_of_consts["standNone"] = 0x0000;
	list_of_consts["standAccurate"] = 0x0001;
	list_of_consts["standVertical"] = 0x0002;
	list_of_consts["standCoarsly"] = 0x0003;
	list_of_consts["standSwing"] = 0x0004;
	list_of_consts["standWater"] = 0x0005;
	list_of_consts["standMoveDownSmall"] = 0x0010;
	list_of_consts["standMoveDownMedium"] = 0x0020;
	list_of_consts["standMoveDownBig"] = 0x0030;
	list_of_consts["standTurn"] = 0x0040;
	list_of_consts["standTurnToFlat"] = 0x0080;
	list_of_consts["standMoveSmall"] = 0x0100;
	list_of_consts["standMoveMedium"] = 0x0200;
	list_of_consts["standMoveBig"] = 0x0300;
	list_of_consts["standWaterPlant"] = 0x0345;
	list_of_consts["standTree"] = 0x0340;
	list_of_consts["standTreeFall"] = 0x0380;
	list_of_consts["standRock"] = 0x0150;
	list_of_consts["standStone"] = 0x0140;
	list_of_consts["standFish"] = 0x0045;

	list_of_consts["singleHit"] = 0;
	list_of_consts["multiHit"] = 1;

	list_of_consts["expPosZero"] = 0;

	list_of_consts["shieldArmourType"] = 0x01;
	list_of_consts["maxArmourType"] = 0x02;

	list_of_consts["NEUTRAL"] = 0; 
	list_of_consts["POL"] = 1;


	list_of_masks["_bridgePassive_"] = 0x00000001;
	list_of_masks["_pontoonBridgePassive_"] = 0x00000002;
	list_of_masks["_singleBridgePassive_"] = 0x00000003;
	list_of_masks["_singlePontoonBridgePassive_"] = 0x00000004;
	list_of_masks["_bridgeRuinPassive_"] = 0x00000005;
	list_of_masks["_pontoonBridgeRuinPassive_"] = 0x00000006;
	list_of_masks["_artefactPassive_"] = 0x00000007;
	list_of_masks["_tunnelEntrancePassive_"] = 0x00000008;
	list_of_masks["_healthPlacePassive_"] = 0x00000009;
	list_of_masks["_conversionPlacePassive_"] = 0x0000000A;
	list_of_masks["_teleportPassive_"] = 0x0000000B;
	list_of_masks["_birdPassive_"] = 0x0000000C;
	list_of_masks["_waterAnimalPassive_"] = 0x0000000D;
	list_of_masks["_mapOtherPassive_"] = 0x00000000;
	list_of_masks["_mapNothingPassive_"] = 0x00000010;
	list_of_masks["_mapBuildingPassive_"] = 0x00000020;
	list_of_masks["_mapRockPassive_"] = 0x00000030;
	list_of_masks["_mapTreePassive_"] = 0x00000040;
	list_of_masks["_mapWallPassive_"] = 0x00000050;
	list_of_masks["_mapEditorPassive_"] = 0x00000060;
	list_of_masks["equipmentAnimTypeNone"] = 0;
	list_of_masks["equipmentAnimTypeFight"] = 1;
	list_of_masks["equipmentAnimTypeFight2"] = 2;
	list_of_masks["equipmentAnimTypeShoot"] = 3;
	list_of_masks["equipmentAnimTypeMagic1"] = 4;
	list_of_masks["equipmentAnimTypeMagic2"] = 5;
	list_of_masks["equipmentAnimTypeMagic3"] = 6;
	list_of_masks["equipmentAnimTypeMagic4"] = 7;
	list_of_masks["magicTalkNone"] = 0x00000000;
	list_of_masks["magicTalk1"] = 0x00010000;
	list_of_masks["magicTalk2"] = 0x00020000;
	list_of_masks["magicTalk3"] = 0x00030000;
	list_of_masks["magicTalk4"] = 0x00040000;

	list_of_masks["animNone"] = 0x00;
	list_of_masks["animWalk"] = 0x01;
	list_of_masks["animRotor"] = 0x02;
	list_of_masks["animRotation"] = 0x02;
	list_of_masks["moveLand"] = 0x0000;
	list_of_masks["moveAmphibia"] = 0x0100;
	list_of_masks["moveShip"] = 0x0200;
	list_of_masks["moveFlyable"] = 0x0300;
	list_of_masks["notMoveable"] = 0x10000;
}


uint64_t ParCompilatorOverlay::m_number_of_sections = 0;

ParCompilatorOverlay::ParCompilatorOverlay(std::istream& argin, std::ostream& argo, int my_argc, char* my_argv[]) : 
	m_in_stream(argin), m_o(argo), m_main_dir_name(std::string()), m_output_bin_file_name(std::string())
{
	InitializeHashMap();

	if (my_argc == 3)
	{
		m_main_dir_name = *(my_argv + 1);
		m_output_bin_file_name = *(my_argv + 2);
		m_o << "DirectoryName = " << m_main_dir_name << std::endl
		    << "ParametersFileName = " << m_output_bin_file_name << std::endl;
	}
	else
	{
		StandardProgramExecution();
	}


	if (std::filesystem::is_directory(m_main_dir_name) == false)
	{
		m_o << "The specified folder does not exist!" << std::endl;
		exit(EXIT_FAILURE);
	}

	CompileAllTxtFiles();

	m_o << "The " << m_main_dir_name << " directory was compiled successfully..." << std::endl;

}


// order file

void ParCompilatorOverlay::GetOrderListFromFile(uint8_t* pointertofilebuffer, uint64_t filebufferlength)
{
	std::string line = std::string();

	for (uint64_t i = 0; i < filebufferlength; ++i)
	{
		if ((pointertofilebuffer[i] == 0x0D) && (pointertofilebuffer[i + 1] == 0x0A))
		{
			m_order_file_names.push_back(line);

			line = std::string();
			++i;
			continue;
		}

		line += pointertofilebuffer[i];
	}

}


void ParCompilatorOverlay::CompileAllTxtFiles()
{
	InputBinFile orderfile(m_main_dir_name + "\\" + "section_order.txt");

	orderfile.Informations(m_o);
	orderfile.ExitWhenFileDontExist(m_o);

	GetOrderListFromFile(orderfile.m_file_buffer, orderfile.GetFileLength());

	m_number_of_sections = m_order_file_names.size() - 3;
	m_o << m_number_of_sections << " sections were counted." << std::endl;

	for (auto& i : m_order_file_names)
	{
		CompileSingleTxtFile(i);
	}

	Compilator::SaveOutputFileBufferToBin(m_output_bin, m_output_bin_file_name);
	
}


void ParCompilatorOverlay::CompileSingleTxtFile(const std::string& filename)
{
	
	InputBinFile datasubfile(m_main_dir_name + "\\" + filename + ".cpp");

	datasubfile.Informations(m_o);
	datasubfile.ExitWhenFileDontExist(m_o);

	myCompilator = Compilator(datasubfile.m_file_buffer, datasubfile.GetFileLength());
	myCompilator.CompileTxtFileToBin();

}

void ParCompilatorOverlay::StandardProgramExecution()
{
	m_o << "****************" << std::endl
		<< "|PARimV3 BY ATL|" << std::endl
		<< "******2025******" << std::endl;

	m_o << "Enter the name of the input directory:"; m_in_stream >> m_main_dir_name;

	m_output_bin_file_name = m_main_dir_name + ".par";

	m_o << "Output parameters file:" << m_output_bin_file_name << std::endl;

	
}
