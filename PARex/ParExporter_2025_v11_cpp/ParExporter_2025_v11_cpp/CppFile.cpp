#include "CppFile.hpp"
#include "Console.hpp"
#include <fstream>

using namespace std;

void CppFile::SaveToTextFile(filesystem::path& path)
{
	fstream file;
	file.open(path, ios::out);

	if (!file)
		throw runtime_error("The file cannot be opened for writing.");

	auto str_data(this->m_stream_data.str());
	file.write(&str_data[0], str_data.size());
	file.close();
}

void CppFile::WriteTime32(int quad_count, std::string name, uint32_t& value)
{
	time_t mytime = static_cast<time_t>(value);

	char buffer[64];
	tm time_info;

	this->WriteTrivialValue(quad_count, name, value, false);
	this->m_stream_data << " // ";

	if (localtime_s(&time_info, &mytime) == 0)
	{
		strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &time_info);
		this->m_stream_data << buffer << endl;
	}
	else
	{
		DEBUG_PRINT("Incorrect time value: ", value, Mess::endl);
	}

}