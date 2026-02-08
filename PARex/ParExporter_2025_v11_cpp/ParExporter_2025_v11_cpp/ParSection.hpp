#ifndef PAR_SECTION_H
#define PAR_SECTION_H

#include "SectionHeader.hpp"
#include "Object.hpp"

class ParSection
{
public:
	ParSection(ConfigSwitches& config_switches, HashMaps& hash_maps);
	~ParSection();

	std::string GetSectionName() const;

	void ReadFrom(BinFile& bin_file);

	inline void SaveToTextFile(std::filesystem::path& arg_output_file_path)
	{
		this->m_cpp_file.SaveToTextFile(arg_output_file_path);
	}

	inline void WriteObjNamesListToCppFileStream(CppFile& arg_cpp_file)
	{
		arg_cpp_file << this->m_obj_names_list.str();
	}

private:
	CppFile m_cpp_file;

	CppFile m_obj_names_list;

	ConfigSwitches& m_config_switches;
	HashMaps& m_hash_maps;
	std::string m_section_name;
};


#endif // !PAR_SECTION_H