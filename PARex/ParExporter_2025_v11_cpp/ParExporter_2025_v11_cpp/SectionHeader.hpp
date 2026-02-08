#ifndef SECTION_HEADER_H
#define SECTION_HEADER_H

#include "BinFile.hpp"
#include "CppFile.hpp"

class SectionHeader
{
public:
	SectionHeader(std::unordered_map<uint32_t, std::string>& arg_list_of_race_masks);
	~SectionHeader();

	uint32_t GetNumberOfObjects() const;
	std::string GetSectionName() const;

	void ReadFrom(BinFile& bin_file);

	inline void SaveToTextFile(std::filesystem::path& arg_output_file_path)
	{
		this->m_cpp_file.SaveToTextFile(arg_output_file_path);
	}

	inline void WriteToCppFileStream(CppFile& arg_cpp_file)
	{
		arg_cpp_file << this->m_cpp_file.str();
	}

private:
	CppFile m_cpp_file;
	uint32_t m_number_of_objects;
	std::string m_section_name;
	size_t m_id;

	std::unordered_map<uint32_t, std::string>& m_list_of_race_masks;

	static size_t s_section_id;
};


#endif // !SECTION_HEADER_H