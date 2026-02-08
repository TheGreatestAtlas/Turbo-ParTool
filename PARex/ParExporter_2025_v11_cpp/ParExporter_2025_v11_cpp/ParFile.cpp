#include "ParFile.hpp"

#include "ParHeader.hpp"
#include "EndOfPar.hpp"

using namespace std;
namespace fs = filesystem;

ParFile::ParFile(
	std::filesystem::path& input_path, 
	ConfigSwitches& config_switches, 
	bool& error_handler
) :
	m_config_switches(config_switches),
	m_error_handler(error_handler)
{
	this->m_par_file = BinFile(input_path);
	this->m_par_file.Informations();
	this->m_error_handler = !(this->m_par_file.GetIsOpened());
	//this->m_par_file.ExitWhenFileDontExist();
}

ParFile::~ParFile()
{
}

void ParFile::ExportTo(fs::path& output_path)
{
	const char cpp_format[] = ".cpp";
	HashMaps hash_maps;
	CppFile section_order_file;

	fs::create_directory(output_path); // folder roboczy

	string par_header_section_name = "par_header";
	string par_header_file_name = par_header_section_name + cpp_format;
	fs::path par_header_file_path = output_path / par_header_file_name;

	ParHeader par_header;
	par_header.ReadFrom(this->m_par_file);
	par_header.SaveToTextFile(par_header_file_path);

	section_order_file << par_header_section_name << endl;

	uint64_t number_of_sections = par_header.GetNumberOfSections();

	for (uint64_t i = 0; i <= number_of_sections; ++i)
	{
		ParSection single_par_section(this->m_config_switches, hash_maps);
		single_par_section.ReadFrom(this->m_par_file);
		single_par_section.WriteObjNamesListToCppFileStream(this->m_obj_names_list);

		string single_section_name = "section_" + to_string(i) + "_" + single_par_section.GetSectionName();
		section_order_file << single_section_name << endl;

		string single_section_file_name = single_section_name + cpp_format;

		fs::path single_section_file_path = output_path / single_section_file_name;
		single_par_section.SaveToTextFile(single_section_file_path);
	}

	string end_of_par_section_name = "end_of_par";
	string end_of_par_file_name = end_of_par_section_name + cpp_format;
	fs::path end_of_par_file_path = output_path / end_of_par_file_name;

	EndOfPar end_of_par;
	end_of_par.ReadFrom(this->m_par_file);
	end_of_par.SaveTo(end_of_par_file_path);

	section_order_file << end_of_par_section_name << endl;

	string section_order_file_name = "section_order.txt";
	fs::path section_order_file_path = output_path / section_order_file_name;
	section_order_file.SaveToTextFile(section_order_file_path);
}

