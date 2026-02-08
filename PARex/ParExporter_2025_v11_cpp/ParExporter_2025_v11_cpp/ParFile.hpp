#ifndef PAR_FILE_H
#define PAR_FILE_H

#include "ParSection.hpp"

class ParFile
{
public:
	ParFile(std::filesystem::path& input_path, ConfigSwitches& config_switches, bool& error_handler);
	~ParFile();

	void ExportTo(std::filesystem::path& output_path); // Create a directory with exported content

	inline void SaveObjNamesListTo(std::filesystem::path& output_path) // Only available after export
	{
		this->m_obj_names_list.SaveToTextFile(output_path);
	}

private:
	BinFile m_par_file;

	CppFile m_obj_names_list;

	ConfigSwitches& m_config_switches;
	bool& m_error_handler;
};



#endif // !PAR_FILE_H