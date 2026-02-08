#include "EndOfPar.hpp"
#include <array>

using namespace std;

EndOfPar::EndOfPar()
{
}

EndOfPar::~EndOfPar()
{
}

void EndOfPar::ReadFrom(BinFile& bin_file)
{
    this->m_cpp_file << "struct EndOfPar" << endl
                     << "{" << endl;
    
    uint32_t var_field_0 = 0;
    array<uint32_t, 5> var_fields = {};
    array<string, 2> str_fields = {};

    bin_file.ReadValue(var_field_0);
    str_fields[0] = bin_file.ReadString();

    bin_file.ReadValue(var_fields);
    str_fields[1] = bin_file.ReadString();


    this->m_cpp_file.WriteTrivialValue(1, "var_field", var_field_0);
    this->m_cpp_file.WriteString(1, "str_field", str_fields[0]);

    for(int i = 0 ; i < var_fields.size() ; ++i)
        this->m_cpp_file.WriteTrivialValue(1, "var_field_" + to_string(i), var_fields[i]);

    this->m_cpp_file.WriteString(1, "str_field", str_fields[1]);

    this->m_cpp_file << "};";

}