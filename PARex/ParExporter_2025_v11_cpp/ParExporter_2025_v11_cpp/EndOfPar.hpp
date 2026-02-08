#ifndef END_OF_PAR_H
#define END_OF_PAR_H

#include "BinFile.hpp"
#include "CppFile.hpp"

class EndOfPar
{
public:
	EndOfPar();
	~EndOfPar();

	void ReadFrom(BinFile& bin_file);

	inline void SaveTo(std::filesystem::path& arg_output_file_path)
	{
		this->m_cpp_file.SaveToTextFile(arg_output_file_path);
	}

private:
	CppFile m_cpp_file;

};


#endif // !END_OF_PAR_H