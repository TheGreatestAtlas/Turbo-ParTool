#ifndef HASH_MAPS_H
#define HASH_MAPS_H

#include <unordered_map>
#include <string>

class HashMaps
{
public:
	HashMaps();
	std::unordered_map<uint32_t, std::string> m_list_of_passive_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_magic_anim_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_magic_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_explosion_flags_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_trap_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_missile_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_object_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_building_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_waste_size_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_group_template_num_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_position_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_race_flags_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_stand_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_hit_type_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_experience_explosion_pos_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_equipment_flags_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_race_masks = {};
	
	void InitializeHashMaps();
};

#endif // !HASH_MAPS_H