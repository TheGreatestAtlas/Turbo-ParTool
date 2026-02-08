#ifndef PAR_HEADER_H
#define PAR_HEADER_H

#include "BinFile.hpp"
#include "CppFile.hpp"

class ParHeader
{
public:
	ParHeader();
	~ParHeader();

	uint64_t GetNumberOfSections() const;

	void ReadFrom(BinFile& bin_file);

	inline void SaveToTextFile(std::filesystem::path& arg_output_file_path)
	{
		this->m_cpp_file.SaveToTextFile(arg_output_file_path);
	}

private:
	CppFile m_cpp_file;
	uint64_t m_number_of_sections;

};


#endif // !PAR_HEADER_H