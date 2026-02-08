#ifndef MISC_H
#define MISC_H

#include "Globals.hpp"
#include <string>
#include <bitset>
#include <algorithm>

namespace Misc
{
	template<typename Type>
	inline std::string ConvertTrivialTypeToString()
	{
		std::stringstream result{};

		if (std::is_unsigned_v<Type>)
		{
			result << 'u';
		}

		result << "int" << sizeof(Type) * Globals::number_of_bits_in_byte << "_t";

		return result.str();
	}

	template<typename Type>
	inline std::string ConvertTrivialTypeToString(Type)
	{
		return ConvertTrivialTypeToString<Type>();
	}

	inline std::string DecByteToReversedBin(uint8_t number)
	{
		std::string s = std::bitset<Globals::number_of_bits_in_byte>(number).to_string();
		std::reverse(s.begin(), s.end());
		return s;
	}

	static size_t CountOccurrences(const char* buffer, const size_t& size, const std::string& word)
	{
		std::string data(buffer, size);

		size_t count = 0;
		size_t pos = data.find(word, 0);

		while (pos != std::string::npos)
		{
			++count;
			pos = data.find(word, pos + word.length()); // Przesuwamy indeks za znalezione s³owo
		}

		return count;
	}

	inline void ToUpper(std::string& str)
	{
		transform(str.begin(), str.end(), str.begin(),
			[](unsigned char c) { return toupper(c); });
	}
};


#endif // !MISC_H