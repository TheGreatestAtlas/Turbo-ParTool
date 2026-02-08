#include "ParSection.hpp"

using namespace std;

ParSection::ParSection(ConfigSwitches& config_switches, HashMaps& hash_maps) :
    m_config_switches(config_switches),
    m_hash_maps(hash_maps),
    m_section_name(string())
{
}

ParSection::~ParSection()
{
}

void ParSection::ReadFrom(BinFile& bin_file)
{
    SectionHeader section_header(m_hash_maps.m_list_of_race_masks);
    section_header.ReadFrom(bin_file);
    section_header.WriteToCppFileStream(this->m_cpp_file);

    this->m_section_name = section_header.GetSectionName();

    uint32_t number_of_objects = section_header.GetNumberOfObjects();

    for (uint32_t i = 0; i < number_of_objects; ++i)
    {
        Object single_object(this->m_config_switches, this->m_hash_maps);
        single_object.ReadFrom(bin_file);
        single_object.WriteToCppFileStream(this->m_cpp_file);
        
        this->m_obj_names_list << single_object.GetObjectName() << endl;
    }

}


string ParSection::GetSectionName() const 
{
    return this->m_section_name;
}

