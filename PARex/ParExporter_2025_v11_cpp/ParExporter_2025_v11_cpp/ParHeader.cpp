#include "ParHeader.hpp"
#include <array>

using namespace std;

ParHeader::ParHeader() :
    m_number_of_sections(0)
{
}

ParHeader::~ParHeader()
{
}

uint64_t ParHeader::GetNumberOfSections() const { return this->m_number_of_sections; }

void ParHeader::ReadFrom(BinFile& bin_file)
{
    this->m_cpp_file << "struct ParHeader" << endl
        << "{" << endl;


    uint32_t time;
    bin_file.ReadValue(time);
    this->m_cpp_file.WriteTime32(1, "time", time);

    string header_string = bin_file.ReadSimpleString();
    uint8_t header_string_len = static_cast<uint8_t>(header_string.length());
    this->m_cpp_file.WriteTrivialValue(1, "header_string_length", header_string_len);

    this->m_cpp_file << "\tchar header_string[header_string_length] = \"" << header_string << "\";" << endl << endl;

    //GUID SEPARATOR - start
    uint32_t parameters_version_start;
    bin_file.ReadValue(parameters_version_start);
    this->m_cpp_file.WriteTrivialValue(1, "parameters_version_start", parameters_version_start);
    //----------------

    //GUID - get and write
    string guid = bin_file.ReadGuid();
    this->m_cpp_file.WriteGuid(1, "header_guid", guid);
    this->m_cpp_file << endl;

    array<uint8_t, sizeof(uint32_t)> format = {};
    bin_file.ReadValue(format);

    for (int i = 0; i < format.size(); ++i)
    {
        this->m_cpp_file.WriteTrivialValue(1, "format_" + to_string(i), format[i], false); 

        if (isalpha(format[i]))
            this->m_cpp_file << " // " << format[i]; 

        this->m_cpp_file << endl;
    }
    //-------------------------------------------------------------------------------------------

    //GUID SEPARATOR - end
    uint32_t parameters_version_end;
    bin_file.ReadValue(parameters_version_end);
    this->m_cpp_file.WriteTrivialValue( 1, "parameters_version_end", parameters_version_end);
    //----------------
    

    //NUMBER OF SECTIONS
    bin_file.ReadValue(this->m_number_of_sections);
    this->m_cpp_file << endl << "\tuint64_t number_of_sections = count();" << endl << "};";
    //----------------
}

