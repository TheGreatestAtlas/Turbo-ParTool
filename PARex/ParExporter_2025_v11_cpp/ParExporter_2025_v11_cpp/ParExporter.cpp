#include "ParExporter.hpp"

using namespace std;
namespace fs = filesystem;

ParExporter::ParExporter()
{
}

ParExporter::~ParExporter()
{
}

void ParExporter::Run(int my_argc, char* my_argv[])
{
	const unsigned int correct_number_of_args = 2;
    fs::path input_par_file_path;
    bool error_handler = Globals::success_code;
    const char par_ex_cfg_file_name[] = "PARex.cfg";
    const char par_ex_data_dir_name[] = "PARex_DATA";
    const char editor_names_txt_file_name[] = "EditorNames.txt";

    if (my_argc == correct_number_of_args)
    {
        input_par_file_path = my_argv[1];
        
        CONSOLE_OUT.PrintLn("Input file = ", input_par_file_path);
    }
    else
    {
        ShowIntroScreen();
        CONSOLE_OUT.PrintLn("Enter the path to the input .par file, including the extension:");
        CONSOLE_IN.Scan(input_par_file_path);
    }

    if (!fs::exists(input_par_file_path))
    {
        CONSOLE_OUT.PrintLn("Error: The specified ", input_par_file_path, " file does not exist.");
        exit(EXIT_FAILURE);
    }

    if (input_par_file_path.extension().string() != ".par" )
    {
        CONSOLE_OUT.PrintLn("The specified file is not a .par file. The program terminates with an error.");
        exit(EXIT_FAILURE);
    }

    filesystem::path par_ex_cfg_file_path = fs::current_path() / par_ex_cfg_file_name;
    CfgFile par_ex_cfg_file(par_ex_cfg_file_path);
    ConfigSwitches config_switches = par_ex_cfg_file.GetConfigSwitches();

    filesystem::path export_path = input_par_file_path.parent_path() / input_par_file_path.stem();

    ParFile my_ks_par(input_par_file_path, config_switches, error_handler);
    if (error_handler == Globals::error_code)
    {
        CONSOLE_OUT.PrintLn("Error: Failed to open ", input_par_file_path, " file.");
        exit(EXIT_FAILURE);
    }
    my_ks_par.ExportTo(export_path);


    filesystem::path par_ex_data_directory_path = fs::current_path() / par_ex_data_dir_name;
    filesystem::create_directory(par_ex_data_directory_path);
    filesystem::path editor_names_file_path = par_ex_data_directory_path / editor_names_txt_file_name;

    my_ks_par.SaveObjNamesListTo(editor_names_file_path);

    
    CONSOLE_OUT.PrintLn("Decompilation of file ", input_par_file_path, " completed successfully!");

}

void ParExporter::ShowIntroScreen()
{
    CONSOLE_OUT.Print("****************", Mess::endl, 
                      "|PARex BY ATLAS|", Mess::endl, 
                      "******2025******", Mess::endl);
}