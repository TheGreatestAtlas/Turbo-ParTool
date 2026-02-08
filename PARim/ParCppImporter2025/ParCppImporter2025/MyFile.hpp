#ifndef MY_FILE_H
#define MY_FILE_H

#include <filesystem>
#include <vector>
#include <fstream>
#include "Console.hpp"

//-------------
// MyFile CLASS
//-------------

template<class Type>
class MyFile
{
public:
	MyFile(std::filesystem::path arg_input_file_path, std::ios_base::openmode arg_mode) :
		m_file_path(arg_input_file_path),
		m_is_opened(false),
		m_is_open_now(false)
	{
		DEBUG_PRINT("Path to file:", this->m_file_path, Mess::endl);
		LoadFrom(this->m_file_path, arg_mode);
	}

	MyFile() :
		m_file_path(std::filesystem::path()),
		m_is_opened(false),
		m_is_open_now(false)
	{
		DEBUG_PRINT("A new file has been initialized...", Mess::endl);
	}

	~MyFile() { this->m_file_buffer.clear();  }

	virtual void LoadFrom(std::filesystem::path& arg_file_path, const std::ios_base::openmode& arg_mode)
	{
		std::fstream input_file;
		input_file.open(arg_file_path, std::ios::in | arg_mode | std::ios::ate);

		if (input_file)
		{
			this->m_is_opened = this->m_is_open_now = true;

			size_t file_length = input_file.tellg();
			DEBUG_PRINT(arg_file_path, "::FILE_LEN = ", file_length, Mess::endl);

			input_file.seekg(0);

			this->m_file_buffer.resize(file_length);

			if (this->m_file_buffer.empty() == false && file_length > 0)
			{
				input_file.read(reinterpret_cast<char*>(&this->m_file_buffer[0]), file_length);
			}

			input_file.close();
			m_is_open_now = false;
		}

	}

	virtual void SaveTo(std::filesystem::path& output_file_path, const std::ios_base::openmode& arg_mode)
	{
		std::fstream output_file;
		output_file.open(output_file_path, std::ios::out | arg_mode);

		if (this->m_file_buffer.empty() == false && this->m_file_buffer.size() > 0)
		{
			output_file.write(reinterpret_cast<char*>(&this->m_file_buffer[0]), this->m_file_buffer.size());
		}
		else
		{
			DEBUG_PRINT
			(
				Mess::endl, 
				Mess::endl, 
				"void MyFile::SaveTo(fs::path & output_file_path, const ios_base::openmode & arg_mode):", Mess::endl, 
				"Error while saving data - vector is empty!", Mess::endl, Mess::endl
			);
		}

		output_file.close();
	}

	void Informations() const
	{
		if (m_is_opened == false)
		{
			CONSOLE_OUT.Print(Mess::endl,
				"WARNING: The specified file could not be opened.", Mess::endl,
				"-------------------------------------", Mess::endl,
				"Opening the file:", this->m_file_path, Mess::endl,
				"Was the file successfully opened?: ", this->m_is_opened, Mess::endl,
				"Is the file currently open?: ", this->m_is_open_now, Mess::endl,
				"-------------------------------------", Mess::endl,
				Mess::endl);
		}

	}

	void ExitWhenFileDontExist() const
	{
		if (this->m_is_opened == false && this->m_is_open_now == false)
		{
			CONSOLE_OUT.PrintLn("The specified file does not exist!");
			exit(EXIT_FAILURE);
		}
	}


	//Gettery:
	bool GetIsOpened() const { return m_is_opened; }
	bool GetIsOpenNow() const { return m_is_open_now; }
	size_t GetFileLength() const { return this->m_file_buffer.size(); }
	const std::vector<Type>& GetFileBuffer() const noexcept { return this->m_file_buffer; }
	constexpr bool Empty() const noexcept { return this->m_file_buffer.empty(); }

protected:
	//Pola:
	std::vector<Type> m_file_buffer;

	std::filesystem::path m_file_path;
	bool m_is_opened;
	bool m_is_open_now;

};

#endif // !MY_FILE_H
