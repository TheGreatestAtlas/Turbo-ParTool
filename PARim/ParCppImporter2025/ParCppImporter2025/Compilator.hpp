#ifndef COMPILATOR_H
#define COMPILATOR_H

#include "HashMaps.hpp"
#include "BinFile.hpp"
#include <bitset>
#include "Globals.hpp"

class Compilator
{
public:
	Compilator(	
				std::filesystem::path& arg_input_path, 
				BinFile& arg_output_file_buffer, 
				HashMaps& arg_hash_maps, 
				uint64_t& arg_number_of_sections,
				bool& arg_error_handler
			  );

private:
	HashMaps& m_hash_maps;
	BinFile& m_output_file_buffer;
	uint64_t& m_number_of_sections;
	bool& m_error_handler;

	bool m_special_function_lock;

	size_t m_number_of_obj_in_section;

	std::bitset<Globals::byte_to_bits> m_binary_value;
	uint32_t m_bits_counter;

	void CompileCppFileToBin(const std::vector <char>& arg_clean_file);

	template <typename T>
	void WriteTabToFile(const std::string& str);

	void WriteBooleanTabToFile(const std::string& str);

	template <typename T>
	void WriteNBitMaskToFile(std::string& str);

	void GetValuesFromString(
		std::string& arg_instruction,
		std::string& arg_value_type,
		Enums::value_types_enum& arg_en_value_type,
		std::string& arg_name,
		std::string& arg_value
	);

	void WriteInstructionToBin(std::string& value_type, Enums::value_types_enum& en_value_type, std::string& value);


	inline uint64_t CountValuesInTab(const std::string& value)
	{
		uint64_t tabsize = std::ranges::count(value, ',');

		if (tabsize != 0) ++tabsize;

		return tabsize;
	}

};



#endif // !COMPILATOR_H
