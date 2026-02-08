#ifndef TEXT_FILE_H
#define TEXT_FILE_H

#include "MyFile.hpp"
#include "Misc.hpp"

class TextFile : public MyFile<char>
{
public:
	TextFile(std::filesystem::path arg_input_file_path) : 
		MyFile(arg_input_file_path, std::ios::in)
	{}

	TextFile() : 
		MyFile()
	{}

	void DeleteComments();
	void DeleteContrCharAndPutToCleanFileVector();
	const std::vector<char>& GetCleanFileBuffer() const noexcept;

	inline size_t CountOccurrencesOfText(const std::string& word)
	{
		return Misc::CountOccurrences(reinterpret_cast<const char*>(this->m_file_buffer.data()), this->m_file_buffer.size(), word);
	}

	inline void LoadFrom(std::filesystem::path& arg_input_file_path)
	{
		MyFile::LoadFrom(arg_input_file_path, std::ios::in);
	}

	inline void SaveTo(std::filesystem::path& arg_output_file_path)
	{
		MyFile::SaveTo(arg_output_file_path, std::ios::out);
	}

private:
	std::vector <char> m_clean_file = {};

};


#endif // !TEXT_FILE_H