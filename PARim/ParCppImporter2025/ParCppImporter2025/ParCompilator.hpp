#ifndef PAR_COMPILATOR_H
#define PAR_COMPILATOR_H

#include "Compilator.hpp"
#include "OrderFile.hpp"

class ParCompilator
{
public:
	ParCompilator(std::filesystem::path& arg_input_path, bool& arg_error_handler);

	inline void SaveCompiledFileTo(std::filesystem::path& arg_output_file_path)
	{
		this->m_output_file.SaveTo(arg_output_file_path);
	}

private:
	BinFile m_output_file;
};

#endif // !PAR_COMPILATOR_H