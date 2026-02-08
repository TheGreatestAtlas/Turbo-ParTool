#ifndef PAR_EXPORTER_H
#define PAR_EXPORTER_H

#include "ParFile.hpp"
#include "CfgFile.hpp"

class ParExporter
{
public:
	ParExporter();
	~ParExporter();
	void Run(int my_argc, char* my_argv[]);

private:
	void ShowIntroScreen();

};


#endif // !PAR_EXPORTER_H