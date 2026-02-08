#ifndef HASH_MAPS_H
#define HASH_MAPS_H

#include <unordered_map>
#include <string>
#include "Enums.hpp"

class HashMaps
{
public:
	HashMaps();
	std::unordered_map<std::string, uint32_t> m_list_of_consts = {};
	std::unordered_map<std::string, uint32_t> m_list_of_masks = {};
	std::unordered_map<std::string, Enums::value_types_enum> m_hash_map_of_value_types_enums = {};
	std::unordered_map<std::string, bool> m_hash_map_of_boolean_values = {};

	void InitializeHashMapOfConsts();
	void InitializeHashMapOfMasks();
	void InitializeHashMapOfValueTypesEnums();
	void InitializeHashMapOfBooleanValues();

};


#endif // !HASH_MAPS_H