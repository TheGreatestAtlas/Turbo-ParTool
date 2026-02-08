#ifndef MISC_H
#define MISC_H

#include <string>

namespace Misc
{
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

};


#endif // !MISC_H