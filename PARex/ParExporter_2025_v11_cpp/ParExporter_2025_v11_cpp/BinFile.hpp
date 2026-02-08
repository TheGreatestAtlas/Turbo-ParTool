#ifndef BIN_FILE_H
#define BIN_FILE_H

#include "MyFile.hpp"

//---------------------
// BinFile CLASS
//---------------------

class BinFile : public MyFile<uint8_t>
{
public:
	BinFile(std::filesystem::path arg_input_file_path) :
		MyFile(arg_input_file_path, std::ios::binary),
		m_current_offset(0)
	{}

	BinFile() :
		MyFile(),
		m_current_offset(0)
	{}

	inline void WriteBuffer(std::vector<uint8_t>& arg_buff)
	{
		m_file_buffer.insert(m_file_buffer.end(), arg_buff.begin(), arg_buff.end());
	}

	inline void WriteBuffer(BinFile& arg_file)
	{
		m_file_buffer.insert(m_file_buffer.end(), arg_file.GetFileBuffer().begin(), arg_file.GetFileBuffer().end());
	}

	inline void WriteBuffer(const uint8_t* arg_buff, size_t& buff_len)
	{
		m_file_buffer.insert(m_file_buffer.end(), arg_buff, arg_buff + buff_len);
	}

	template<typename T>
	inline void WriteValue(const T& val)
	{
        static_assert(std::is_trivially_copyable_v<T>,
			"WriteValue can only be used with trivially copyable types");

		auto ptr = reinterpret_cast<const uint8_t*>(&val);
		this->m_file_buffer.insert(this->m_file_buffer.end(), ptr, ptr + sizeof(T));
	}

	template<typename T>
	inline void ReadValue(T& value)
	{
		value = reinterpret_cast<T&>(this->m_file_buffer[m_current_offset]);
		m_current_offset += sizeof(T);
	}

	std::string ReadLogicTable();
	std::string ReadSimpleString();
	std::string ReadString();

	inline void WriteString(std::string& str)
	{
		m_file_buffer.insert(m_file_buffer.end(), str.begin(), str.end());
	}

	void WriteGuid(std::string& guid);
	std::string ReadGuid();

	inline void LoadFrom(std::filesystem::path& arg_input_file_path)
	{
		MyFile::LoadFrom(arg_input_file_path, std::ios_base::binary);
	}

	inline void SaveTo(std::filesystem::path& arg_output_file_path)
	{
		MyFile::SaveTo(arg_output_file_path, std::ios_base::binary);
	}

	inline void MoveOverBy(int64_t count)
	{
		this->m_current_offset += count;
	}

private:
	size_t m_current_offset;
	
};

#endif // !BIN_FILE_H
