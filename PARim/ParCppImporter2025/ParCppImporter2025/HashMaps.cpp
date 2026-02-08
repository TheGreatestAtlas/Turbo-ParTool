#include "HashMaps.hpp"
#include "CompilatorValueTypes.hpp"

using namespace std;

HashMaps::HashMaps()
{
    InitializeHashMapOfConsts();
	InitializeHashMapOfMasks();
	InitializeHashMapOfValueTypesEnums();
	InitializeHashMapOfBooleanValues();
}

void HashMaps::InitializeHashMapOfConsts()
{
	m_list_of_consts["NULL"] = 0;
	m_list_of_consts["magicImmortalShield"] = 1;
	m_list_of_consts["magicFreeze"] = 2;
	m_list_of_consts["magicCapturing"] = 3;
	m_list_of_consts["magicStorm"] = 4;
	m_list_of_consts["magicSeeing"] = 5;
	m_list_of_consts["magicConversion"] = 6;
	m_list_of_consts["magicFireRain"] = 7;
	m_list_of_consts["magicRemoveStormFireRain"] = 8;
	m_list_of_consts["magicTeleportation"] = 9;
	m_list_of_consts["magicGhost"] = 10;
	m_list_of_consts["magicWildAnimal"] = 11;
	m_list_of_consts["magicTrap"] = 12;
	m_list_of_consts["magicGetHP"] = 13;
	m_list_of_consts["magicSingleFreeze"] = 14;
	m_list_of_consts["magicBlindAttack"] = 15;
	m_list_of_consts["magicTimedCapturing"] = 16;
	m_list_of_consts["magicOurWildAnimal"] = 17;
	m_list_of_consts["magicOurHoldWildAnimal"] = 18;
	m_list_of_consts["magicOurMagicMirror"] = 19;
	m_list_of_consts["magicRandConversion"] = 20;
	m_list_of_consts["magicAroundDamage"] = 21;
	m_list_of_consts["magicSelfHealing"] = 22;
	m_list_of_consts["magicFireWall"] = 23;
	m_list_of_consts["noEarthquake"] = 0x00;
	m_list_of_consts["smallEarthquake"] = 0x01;
	m_list_of_consts["mediumEarthquake"] = 0x02;
	m_list_of_consts["bigEarthquake"] = 0x03;
	m_list_of_consts["typeHoldTrap"] = 1;
	m_list_of_consts["typeDamageTrap"] = 2;
	m_list_of_consts["typeHoldTrapOnce"] = 3;
	m_list_of_consts["missileSword"] = 1;
	m_list_of_consts["missileInvisible"] = 2;
	m_list_of_consts["missileCannon"] = 3;
	m_list_of_consts["missileDropBomb"] = 4;
	m_list_of_consts["missileBomb"] = 5;
	m_list_of_consts["missileElectric"] = 6;
	m_list_of_consts["missileLightning"] = 7;
	m_list_of_consts["missileMeteor"] = 8;

	m_list_of_consts["buildingNormal"] = 0;
	m_list_of_consts["buildingFactory"] = 1;
	m_list_of_consts["buildingHarvestFactory"] = 2;
	m_list_of_consts["buildingGate"] = 3;
	m_list_of_consts["buildingBridgeGate"] = 4;
	m_list_of_consts["buildingTower"] = 5;
	m_list_of_consts["buildingWall"] = 6;
	m_list_of_consts["buildingCopula"] = 7;

	m_list_of_consts["smallFlyingWaste"] = 0;
	m_list_of_consts["mediumFlyingWaste"] = 1;
	m_list_of_consts["bigFlyingWaste"] = 2;

	m_list_of_consts["groupSword"] = 91;
	m_list_of_consts["groupDrop"] = 92;
	m_list_of_consts["groupMag"] = 93;
	m_list_of_consts["groupSpecial"] = 94;
	m_list_of_consts["groupAnimal"] = 95;
	m_list_of_consts["groupMulti"] = 96;
	m_list_of_consts["groupBuilding"] = 97;

	m_list_of_consts["positionStartingPoint"] = 0;
	m_list_of_consts["positionMarkPoint"] = 1;
	m_list_of_consts["positionProductionPoint"] = 2;

	m_list_of_consts["eCanBePlayedInSkirmish"] = 0x01;

	m_list_of_consts["standNone"] = 0x0000;
	m_list_of_consts["standAccurate"] = 0x0001;
	m_list_of_consts["standVertical"] = 0x0002;
	m_list_of_consts["standCoarsly"] = 0x0003;
	m_list_of_consts["standSwing"] = 0x0004;
	m_list_of_consts["standWater"] = 0x0005;
	m_list_of_consts["standMoveDownSmall"] = 0x0010;
	m_list_of_consts["standMoveDownMedium"] = 0x0020;
	m_list_of_consts["standMoveDownBig"] = 0x0030;
	m_list_of_consts["standTurn"] = 0x0040;
	m_list_of_consts["standTurnToFlat"] = 0x0080;
	m_list_of_consts["standMoveSmall"] = 0x0100;
	m_list_of_consts["standMoveMedium"] = 0x0200;
	m_list_of_consts["standMoveBig"] = 0x0300;
	m_list_of_consts["standWaterPlant"] = 0x0345;
	m_list_of_consts["standTree"] = 0x0340;
	m_list_of_consts["standTreeFall"] = 0x0380;
	m_list_of_consts["standRock"] = 0x0150;
	m_list_of_consts["standStone"] = 0x0140;
	m_list_of_consts["standFish"] = 0x0045;

	m_list_of_consts["singleHit"] = 0;
	m_list_of_consts["multiHit"] = 1;

	m_list_of_consts["expPosZero"] = 0;

	m_list_of_consts["shieldArmourType"] = 0x01;
	m_list_of_consts["maxArmourType"] = 0x02;

	m_list_of_consts["NEUTRAL"] = 0;
	m_list_of_consts["POL"] = 1;

}

void HashMaps::InitializeHashMapOfMasks()
{

	m_list_of_masks["_bridgePassive_"] = 0x00000001;
	m_list_of_masks["_pontoonBridgePassive_"] = 0x00000002;
	m_list_of_masks["_singleBridgePassive_"] = 0x00000003;
	m_list_of_masks["_singlePontoonBridgePassive_"] = 0x00000004;
	m_list_of_masks["_bridgeRuinPassive_"] = 0x00000005;
	m_list_of_masks["_pontoonBridgeRuinPassive_"] = 0x00000006;
	m_list_of_masks["_artefactPassive_"] = 0x00000007;
	m_list_of_masks["_tunnelEntrancePassive_"] = 0x00000008;
	m_list_of_masks["_healthPlacePassive_"] = 0x00000009;
	m_list_of_masks["_conversionPlacePassive_"] = 0x0000000A;
	m_list_of_masks["_teleportPassive_"] = 0x0000000B;
	m_list_of_masks["_birdPassive_"] = 0x0000000C;
	m_list_of_masks["_waterAnimalPassive_"] = 0x0000000D;
	m_list_of_masks["_mapOtherPassive_"] = 0x00000000;
	m_list_of_masks["_mapNothingPassive_"] = 0x00000010;
	m_list_of_masks["_mapBuildingPassive_"] = 0x00000020;
	m_list_of_masks["_mapRockPassive_"] = 0x00000030;
	m_list_of_masks["_mapTreePassive_"] = 0x00000040;
	m_list_of_masks["_mapWallPassive_"] = 0x00000050;
	m_list_of_masks["_mapEditorPassive_"] = 0x00000060;
	m_list_of_masks["equipmentAnimTypeNone"] = 0;
	m_list_of_masks["equipmentAnimTypeFight"] = 1;
	m_list_of_masks["equipmentAnimTypeFight2"] = 2;
	m_list_of_masks["equipmentAnimTypeShoot"] = 3;
	m_list_of_masks["equipmentAnimTypeMagic1"] = 4;
	m_list_of_masks["equipmentAnimTypeMagic2"] = 5;
	m_list_of_masks["equipmentAnimTypeMagic3"] = 6;
	m_list_of_masks["equipmentAnimTypeMagic4"] = 7;
	m_list_of_masks["magicTalkNone"] = 0x00000000;
	m_list_of_masks["magicTalk1"] = 0x00010000;
	m_list_of_masks["magicTalk2"] = 0x00020000;
	m_list_of_masks["magicTalk3"] = 0x00030000;
	m_list_of_masks["magicTalk4"] = 0x00040000;

	m_list_of_masks["animNone"] = 0x00;
	m_list_of_masks["animWalk"] = 0x01;
	m_list_of_masks["animRotor"] = 0x02;
	m_list_of_masks["animRotation"] = 0x02;
	m_list_of_masks["moveLand"] = 0x0000;
	m_list_of_masks["moveAmphibia"] = 0x0100;
	m_list_of_masks["moveShip"] = 0x0200;
	m_list_of_masks["moveFlyable"] = 0x0300;
	m_list_of_masks["notMoveable"] = 0x10000;
}

void HashMaps::InitializeHashMapOfValueTypesEnums()
{
	constexpr size_t number_of_value_types = 28;
	const char* value_types[] =
	{
		CVT::c_char_type_str,
		CVT::c_char_arr_type_str,

		CVT::c_uint8_t_type_str,
		CVT::c_uint8_t_arr_type_str,

		CVT::c_uint16_t_type_str,
		CVT::c_uint16_t_arr_type_str,

		CVT::c_uint32_t_type_str,
		CVT::c_uint32_t_arr_type_str,

		CVT::c_uint64_t_type_str,
		CVT::c_uint64_t_arr_type_str,

		CVT::c_guid_type_str,
		CVT::c_string_type_str,
		CVT::c_struct_type_str,

		CVT::c_int8_t_type_str,
		CVT::c_int8_t_arr_type_str,

		CVT::c_int16_t_type_str,
		CVT::c_int16_t_arr_type_str,

		CVT::c_int32_t_type_str,
		CVT::c_int32_t_arr_type_str,

		CVT::c_int64_t_type_str,
		CVT::c_int64_t_arr_type_str,

		CVT::c_bool_type_str,
		CVT::c_bool_arr_type_str,

		CVT::c_1bitmask_type_str,

		CVT::c_32bitmask_type_str,

		CVT::c_8bitmask_type_str,

		CVT::c_32bituniquekey_type_str,

		""
	};


	for (size_t i = 0; i < number_of_value_types; ++i)
		this->m_hash_map_of_value_types_enums[string(value_types[i])] = static_cast<Enums::value_types_enum>(i);
}

void HashMaps::InitializeHashMapOfBooleanValues()
{
	this->m_hash_map_of_boolean_values[ CVT::c_bool_false_value ] = false;
	this->m_hash_map_of_boolean_values[ CVT::c_bool_true_value  ] = true;
	this->m_hash_map_of_boolean_values[ CVT::c_bool_zero_value  ] = false;
	this->m_hash_map_of_boolean_values[ CVT::c_bool_one_value   ] = true;
}
