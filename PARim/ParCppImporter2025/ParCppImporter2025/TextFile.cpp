#include "TextFile.hpp"

using namespace std;

void TextFile::DeleteComments()
{
	bool its_comment = false;

	const size_t file_len = this->m_file_buffer.size();
	for (size_t i = 0; i < file_len; ++i)
	{
		if (this->m_file_buffer[i] == '\0')
		{
			this->m_file_buffer.resize(i + 1);
			break;
		}

		if ((this->m_file_buffer[i] == '/') && (this->m_file_buffer[i + 1] == '/'))
		{
			its_comment = !its_comment;
		}

		if ( this->m_file_buffer[i] == '\n' && its_comment == true)
		{
			its_comment = !its_comment;
		}

		if (its_comment == true)
		{
			this->m_file_buffer[i] = ' ';
			continue;
		}
	}

}

void TextFile::DeleteContrCharAndPutToCleanFileVector()
{
	size_t new_size = 0;
	bool its_string = false;

	const size_t file_len = this->m_file_buffer.size();
	this->m_clean_file.resize(file_len);
	for (size_t i = 0; i < file_len; ++i)
	{
		if (this->m_file_buffer[i] == '\"')
		{
			its_string = !its_string;
		}

		if ((this->m_file_buffer[i] <= 32) && (its_string == false))
		{
			continue;
		}

		this->m_clean_file[new_size] = this->m_file_buffer[i];
		++new_size;
	}

	this->m_clean_file.resize(new_size + 1);
}

const vector<char>& TextFile::GetCleanFileBuffer() const noexcept { return this->m_clean_file; }