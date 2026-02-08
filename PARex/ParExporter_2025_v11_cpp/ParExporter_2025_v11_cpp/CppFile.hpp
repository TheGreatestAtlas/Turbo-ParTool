#ifndef CPP_FILE_H
#define CPP_FILE_H

#include <filesystem>
#include <sstream>
#include "Misc.hpp"
#include <unordered_map>
#include <set>

class CppFile
{
public:

	CppFile() = default;

	template<typename T>
	CppFile& operator<<(const T& value)
	{
		this->m_stream_data << value;
		return *this;
	}

	CppFile& operator<<(std::ostream& (*manip)(std::ostream&))
	{
		manip(this->m_stream_data);
		return *this;
	}

	std::string str() const { return this->m_stream_data.str(); }

	inline void WriteSymbol(char symbol, int count)
	{
		for (int i = 0; i < count; ++i)
			this->m_stream_data << symbol;
	}

	template<typename Type>
	inline void WriteTrivialValue(int quad_cound, std::string name, Type& value, bool make_new_line = true)
	{
		WriteSymbol('\t', quad_cound);

		this->m_stream_data << Misc::ConvertTrivialTypeToString(value) << " " << name << " = ";

		if (sizeof(Type) * Globals::number_of_bits_in_byte == Globals::number_of_bits_in_byte)
		{
			this->m_stream_data << static_cast<uint32_t>(value) << ";";
		}
		else
		{
			this->m_stream_data << value << ";";
		}

		if (make_new_line)
			this->m_stream_data << std::endl;
	}

	template<typename Type, int Size>
	inline void WriteTrivialArray(int quad_count, std::string name, std::array<Type, Size> array, bool make_new_line = true)
	{
		size_t i = 0;
		for (Type& value : array)
		{
			this->WriteTrivialValue(quad_count, name + std::to_string(i), value, make_new_line);
			++i;
		}
	}

	inline void WriteString(int quadcount, std::string name, std::string& value, bool make_new_line = true)
	{
		WriteSymbol('\t', quadcount);
		this->m_stream_data << "string " << name << " = \"" << value << "\";";
		
		if (make_new_line)
			this->m_stream_data << std::endl;
	}

	inline void WriteGuid(int quad_count, std::string name, std::string& guid, bool make_new_line = true)
	{
		WriteSymbol('\t', quad_count);
		this->m_stream_data << "GUID " << name << " = " << guid << ";";
		
		if (make_new_line)
			this->m_stream_data << std::endl;
	}


	template<typename Type>
	void WriteUniqueKeyWithConst(
		int quad_count,
		std::string name, 
		Type& value,
		std::unordered_map<Type, std::string>& list_of_masks,
		bool make_new_line = true
		)
	{
		
		if (list_of_masks[value] == "")
		{
			this->WriteTrivialValue(quad_count, name, value, make_new_line);
			return;
		}

		WriteSymbol('\t', quad_count);
		this->m_stream_data
			<< sizeof(value) * Globals::number_of_bits_in_byte
			<< "bituniquekey "
			<< name
			<< " = "
			<< list_of_masks[value]
			<< ";";
			
		if (make_new_line)
			this->m_stream_data << std::endl;
		
	}


	template<typename T>
	void WriteNBitMask(
		int quadcount, 
		std::string name, 
		T& value, 
		std::string main_label,
		std::unordered_map<uint32_t, std::string>& list_of_masks
		)
	{
		std::set<std::string> masks_strings = {};

		const int digits = (sizeof(T) * Globals::number_of_bits_in_byte) / Globals::tetrad;

		T hex_value_4bits[digits] = {};
		T and_mask = static_cast<T>(0x0000000F);

		this->m_stream_data << std::endl;
		WriteSymbol('\t', quadcount);
		this->m_stream_data << "// " << main_label << std::endl;
		WriteSymbol('\t', quadcount);
		this->m_stream_data << sizeof(value) * Globals::number_of_bits_in_byte << "bitmask " << name << " = (";

		for (int i = 0; i < digits; ++i)
		{
			hex_value_4bits[i] = value & and_mask;
			and_mask = and_mask << Globals::tetrad;

			masks_strings.insert(list_of_masks[hex_value_4bits[i]]);
		}

		int j = 0;
		for (const std::string& mask : masks_strings)
		{
			this->m_stream_data << mask;

			if (j < masks_strings.size() - 1) this->m_stream_data << " | ";

			++j;
		}

		this->m_stream_data << ");" << std::endl << std::endl;

	}


	inline void Write1BitMask(int quad_count, std::string& name, const uint8_t& value)
	{
		WriteSymbol('\t', quad_count);
		this->m_stream_data << "1bitmask " << name << " = " << value << ";" << std::endl;
	}

	template<int Size>
	void WriteAll1BitMasks(
		int quad_count,
		std::vector<std::string>& mask_labels, 
		std::array<uint8_t,Size>& array,
		std::string main_label
	)
	{
		std::string binary_value;

		this->m_stream_data << std::endl;
		WriteSymbol('\t', quad_count);
		this->m_stream_data << "// " << main_label << std::endl;

		for (int j = 0; j < array.size(); ++j)
		{
			binary_value = Misc::DecByteToReversedBin(array[j]);

			for (int i = 0; i < binary_value.length(); ++i)
			{
				this->Write1BitMask(quad_count, mask_labels[j * binary_value.length() + i], binary_value[i]);
			}
		}

		this->m_stream_data << std::endl;

	}

	void WriteTime32(int quad_count, std::string name, uint32_t& value);

	void SaveToTextFile(std::filesystem::path& path);

private:
	std::stringstream m_stream_data;


};


#endif // !CPP_FILE_H