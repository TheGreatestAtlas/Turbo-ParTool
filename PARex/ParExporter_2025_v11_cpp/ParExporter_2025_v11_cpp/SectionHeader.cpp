#include "SectionHeader.hpp"

using namespace std;

size_t SectionHeader::s_section_id = 0;

SectionHeader::SectionHeader(unordered_map<uint32_t, string>& arg_list_of_race_masks) :
	m_number_of_objects(0),
    m_section_name(string()),
    m_id(SectionHeader::s_section_id),
    m_list_of_race_masks(arg_list_of_race_masks)
{
    ++s_section_id;
}


SectionHeader::~SectionHeader()
{
}

uint32_t SectionHeader::GetNumberOfObjects() const { return this->m_number_of_objects; }
string SectionHeader::GetSectionName() const { return this->m_section_name; }

void SectionHeader::ReadFrom(BinFile& bin_file)
{
    uint32_t race_unique_key = 0;
    uint32_t flag = 0;

    bin_file.ReadValue(race_unique_key);
    bin_file.ReadValue(flag);
    bin_file.ReadValue(this->m_number_of_objects);
    
    this->m_section_name = bin_file.ReadString();
    
    const int64_t binary_string_length = this->m_section_name.length() + sizeof(uint32_t);
    bin_file.MoveOverBy(-binary_string_length);


    this->m_cpp_file << "struct Section_" << this->m_id << "_" << this->m_section_name << "_Header" << endl
                     << "{" << endl;


    this->m_cpp_file.WriteUniqueKeyWithConst<uint32_t>(1, "race", race_unique_key, this->m_list_of_race_masks);
    this->m_cpp_file.WriteTrivialValue(1, "flag_", flag);
    this->m_cpp_file << "\tuint32_t number_of_objects = count();" << endl << "};" << endl << endl;

}


