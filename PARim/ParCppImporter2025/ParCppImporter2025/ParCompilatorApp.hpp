#ifndef PAR_COMPILATOR_APP_H
#define PAR_COMPILATOR_APP_H

#include "ParCompilator.hpp"

class ParCompilatorApp
{
public:
	ParCompilatorApp();
	void Run(int my_argc, char* my_argv[]);

private:
	//Pola:
	std::filesystem::path m_input_dir_path;

	//metody:
	void StandardProgramExecution();
};

#endif // !PAR_COMPILATOR_APP_H