#include "ParCompilatorApp.hpp"

using namespace std;
namespace fs = filesystem;

ParCompilatorApp::ParCompilatorApp() :
	m_input_dir_path(fs::path())
{
}

void ParCompilatorApp::Run(int my_argc, char* my_argv[])
{
	const int correct_number_of_args = 2;

	if (my_argc == correct_number_of_args)
	{
		this->m_input_dir_path = my_argv[1];

		CONSOLE_OUT.PrintLn("DirectoryName = ", this->m_input_dir_path);
	}
	else
	{
		StandardProgramExecution();
	}

	if (fs::is_directory(this->m_input_dir_path) == false)
	{
		CONSOLE_OUT.PrintLn("The specified folder does not exist!");
		exit(EXIT_FAILURE);
	}

	bool error_handler = Globals::success_code;

	ParCompilator ks_par_compilator(this->m_input_dir_path, error_handler);

	const char par_format[] = ".par";

	if (error_handler == Globals::success_code)
	{
		string ks_par_file_name = this->m_input_dir_path.stem().string() + par_format;
		fs::path output_file_path = this->m_input_dir_path.parent_path() / ks_par_file_name;
		ks_par_compilator.SaveCompiledFileTo(output_file_path);

		CONSOLE_OUT.PrintLn("The ", this->m_input_dir_path, " directory was compiled successfully...");
	}
	else
	{
		CONSOLE_OUT.PrintLn("An error occurred during compilation ", this->m_input_dir_path, ". The compiler has been terminated.");
		exit(EXIT_FAILURE);
	}

}

void ParCompilatorApp::StandardProgramExecution()
{
	CONSOLE_OUT.Print("**************", Mess::endl,
					  "|PARim BY ATL|", Mess::endl,
					  "*****2025*****", Mess::endl,
		              "Enter the name of the input directory:");
	
	CONSOLE_IN.Scan(this->m_input_dir_path);
}



