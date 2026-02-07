#include "parcppV7.hpp"
#include "posortowaneklasy.hpp"

constexpr int byte_to_bits = 8;

constexpr char editor_names_file_name[] = "PARex_DATA\\EditorNames.txt";

const char text_of_cfg_file[] = "//1bitmasks:\nmoveableFlags = YES;\nplugType = YES;\nslotType = YES;\nstoreableFlags = YES;\nRPGUnitFlags = YES;\nartefactMask = YES;\nrepairerFlags = YES;\nbridgeBordersMask = YES;\nshadowType = YES;\ntargetType = YES;\nlookRoundTypeMask = YES;\npassiveMask = YES;\nbuildBuildingFlags = YES;\npanelPos = YES;";

constexpr uint32_t defined_mask_values[] = { GENERIC, MOVEABLE, SHOPUNIT, RPGUNIT, BUILDER, REPAIRER,
HARVESTER, CANNON, MISSILE,SPECIALEQUIPMENT,SPECIALEQUIPMENTEX,MAGICEQUIPMENT,EQUIPMENTARTEFACT,ARTEFACT,
LOOKROUNDEQUIPMENT,LOOKROUNDEQUIPMENTEFFECT,EQUIPMENT,STOREABLE,BUILDING,PASSIVE,DYNAMIC,ACTIVE,MINE,VISIBLEFAKE,
ANIMATEDPASSIVE,ANIMALPASSIVE, BUILDPASSIVE, GHOSTPASSIVE, TRANSIENTPASSIVE, SPECIALPASSIVE, TRAP, SCRIPTEDACTIVE, 
VERTICALVEHICLE, VERTICALVEHICLESPY, VERTICALVEHICLEBOMBER, EXPLOSION, EXPLOSIONEX, MULTIEXPLOSION, SMOKE, SMOKEFIRE, 
STARTINGPOSITIONMARK, AIPLATOON, FLYINGWASTE };

std::vector<std::string> moveableFlags = {
"animalUnit",
"recyclableUnit",
"towerUnit",
"gateUnit",
"sleepModeUnit",
"camouflageModeUnit",
"enemyAlertUnit",
"ghostFriendUnit",
"noEquipmentArtefactsUnit",
"haveArmourExplosion",
"noAccurateStandInSleep",
"noMagicFreezeUnit",
"noMagicGetHPUnit",
"noMagicBlindAttackUnit",
"loopedMoveAnimUnit",
"noPoissonUnit",
"turnAnimUnit",
"noTurnToFreeGridInSleep",
"noGetArtefactUnit" };

std::vector<std::string> plugTypes = {
"tmpPlug",
"swordPlug",
"helmetPlug",
"shieldPlug",
"armourPlug",
"necklacePlug",
"ringPlug",
"beltPlug",
"unknown",
"axePlug",
"bowPlug",
"spearPlug",
"crossbowPlug",
"specialPlug",
"magicPlug",
"eggPlug",
"udderPlug",
"bannerPlug",
"princeSwordPlug",
"princeHelmetPlug",
"princeShieldPlug",
"princeArmourPlug",
"quiverPlug",
"weaponPriestess_Or_SorcererPlug" };

std::vector<std::string> slotTypes = {
"tmpSlot",
"swordSlot",
"helmetSlot",
"shieldSlot",
"armourSlot",
"necklaceSlot",
"ringSlot",
"beltSlot",
"unknown",
"axeSlot",
"bowSlot",
"spearSlot",
"crossbowSlot",
"specialSlot",
"magicSlot",
"eggSlot",
"udderSlot",
"bannerSlot",
"princeWeaponSlot",
"princeHelmetSlot",
"princeShieldSlot",
"princeArmourSlot",
"quiverSlot",
"weaponPriestess_Or_SorcererSlot" };

std::vector<std::string> slotType8 = {
"spellPlugShield",
"spellPlugCapture",
"spellPlugStorm",
"spellPlugConversion",
"spellPlugFireRain",
"spellPlugSeeing",
"spellPlugTeleportation",
"spellPlugGhost",
"spellPlugWolf",
"spellPlugRemoveStorm" };

std::vector<std::string> storeableFlags = {
"alwaysShadowed",
"notEnemyTarget",
"notSelectableActive",
"neverShadowed",
"notAutoTarget",
"childUnit",
"unknown1",
"unknown2",
"drawSelectionFrame",
"drawSelectionHP",
"drawDamagedSelectionFrame",
"drawDamagedSelectionHP_Or_PassiveSelection",
"drawEnemySelectionFrame",
"drawEnemySelectionHP",
"drawUnknown1",
"drawUnknown2",
"lockedDamageIncrease",
"lockedSpeedUpRegeneration",
"lockedSpeedUpMagicReload",
"lockedHarvestSpeedIncrease",
"lockedBuildSpeedIncrease",
"lockedArmourIncrease" };

std::vector<std::string> rpgPlugType = {
"spellPlugShield",
"spellPlugCapture",
"spellPlugStorm",
"spellPlugConversion",
"spellPlugRPGPriestess",
"spellPlugSeeing",
"spellPlugTeleportation",
"spellPlugGhost",
"spellPlugRPG1",
"spellPlugRPG2",
"spellPlugRPG3",
"spellPlugRPG4",
"spellPlugRPG5",
"spellPlugRPG6",
"spellPlugRPG7",
"spellPlugRPG8",
"spellPlugRPG9",
"spellPlugRPG10",
"spellPlugRPG11",
"spellPlugRPG12",
"spellPlugRPG13",
"spellPlugRPG14",
"spellPlugRPG15",
"spellPlugRPG16",
"spellPlugRPG17" };


std::vector<std::string> RPGUnitFlags = {
"userRPGUnit",
"unknown1",
"unknown2",
"unknown3",
"singleShootAnim",
"holdTrapOnceUnit"
};


std::vector<std::string> artefactMask = {
"artefactRegenerateHP",
"artefactRegenerateMagic",
"artefactAddMaxHP",
"artefactAddDamage",
"artefactAddMaxMagic",
"artefactAddHP",
"artefactAddMagic",
"artefactGiveMoney",
"artefactShowMap",
"artefactGiveRPGMoney",
"unknown1",
"unknown2",
"artefactEquipment",
"artefactRPGUnitOnly",
"artefactNoLocatedTalk",
"artefactSpecialAI",
"artefactNoToolitpData",
"artefactDropFromInventory",
"artefactNoSold",
"artefactNoDrop",
"artefactNoUse",
"artefactNoRPGUnit",
"artefactUniqueTooltipText",
"artefactCurePoison",
"artefactNoBlinkInventory" };

std::vector<std::string> lookRoundTypeMask = {
"lookRoundTypeDamageIncrease",
"lookRoundTypeRadar",
"lookRoundTypeShadow",
"lookRoundTypeArmourIncrease",
"lookRoundTypeSpeedUpHPRegeneration",
"lookRoundTypeSpeedUpMagicRegeneration",
"lookRoundTypeHarvestSpeedIncrease",
"lookRoundTypeBuildSpeedIncrease" };


std::vector<std::string> passiveMask = {
"_wallConnectMask_",
"_wallTargetMask_",
"_depotMask_",
"_cornerMask_",
"_edgeMask_",
"_roadMask_",
"_startSmokeMask_",
"_transientMask_",
"_cantBeHitMask_",
"_initInvisibleMask_",
"_autoLightsMask_",
"_repairableMask_",
"_destroyableMask_",
"_loopedSoundMask_",
"_notVisibleMask_",
"_noResourceOnPassiveMask_",
"_initRandomLoopedAnimMask_",
"_cannonTransientMask_",
"_dayBirdMask_",
"_nightBirdMask_",
"_removeOnBuildingMask_",
"_colouredMask_",
"_destroyedEventMask_" };

std::vector<std::string> repairerFlags = {
"repairerCanRepairUnits",
"repairerCanRepairAnimals",
"repairerCanRepairBuildings",
"repairerCanRepairConstructions",
"repairerCanConvertUnits",
"repairerCanConvertAnimals",
"repairerCanConvertBuildings",
"repairerCanCaptureBuildings",
"repairerNotTurnToTarget"
};

std::vector<std::string> bridgeBordersMask = {
    "lockedBridgeBorderN",
"lockedBridgeBorderE",
"lockedBridgeBorderS",
"lockedBridgeBorderW"

};

std::vector<std::string> shadowType = {
"_shadowSimple",
"_shadowStatic",
"_shadowAnimated",
"_shadowVertical",
"unknown1",
"unknown2",
"unknown3",
"unknown4",
"_moveWind",
"_noReflect",
"unknown5",
"_hasNotBigEnoughBox",
"_noSubObjectShadow",
"_symmetricShadow",
"unknown6",
"unknown7",
"_shadowOldStatic",
"_shadowOldRound",
"_shadowOldEllipse1",
"_shadowOldEllipse2",
"_shadowOldEllipse3",
"_shadowOldTree",
"_hasOldSoftwareRendering" };

std::vector<std::string> targetType = {
"targetTypeGround",
"targetTypeAir",
"targetNoUnitOnTower",
"turnExplosionToTarget" };

std::vector<std::string> panelPos = {
"tab1"  };

std::vector<std::string> buildBuildingFlags = {
"unknown1",
"unknown2",
"unknown3",
"unknown4",
"buildAllowLZ0",
"buildAllowLZ1",
"buildTabBuildings",
"buildTabConstructions",
"buildAutoTurnToRoad",
"buildingLockSold",
"unknown5",
"unknown6",
"buildingNoChangeAltitude",
"buildingNoChangeTerrain",
"buildingNoRoadNeighbour",
"towerNoChangePlayer",
"gateNoChangePlayer",
"gateNoUnitRequired",
"cantBeCaptured",
"haveLoopedDoorsSound",
"gateLockEdge1",
"gateLockEdge2",
"researchUpdateButton",
"initVisibleFlags",
"noDarkVisibleFake" };



constexpr size_t numberofvaluetypes = 14;
const char* valuetypes[] = {
"moveableFlags",
"plugType",
"slotType",
"storeableFlags",
"RPGUnitFlags",
"artefactMask",
"repairerFlags",
"bridgeBordersMask",
"shadowType",
"targetType",
"lookRoundTypeMask",
"passiveMask",
"buildBuildingFlags",
"panelPos"
};

static std::string DecByteToReversedBin(uint8_t liczba)
{
    uint8_t rest;

    std::string reversedbin = std::string();

    do
    {
        rest = liczba % 2;
        liczba /= 2;
        reversedbin += std::to_string(rest);

    } while (liczba != 0);

    const int32_t rest_of_zeros = byte_to_bits - static_cast<int32_t>(reversedbin.length());

    for (int i = 0; i < rest_of_zeros; ++i)
        reversedbin += '0';
    

    return reversedbin;
}

//------------------------
// Input File Buffer Class
//------------------------

InputBinFile::InputBinFile(char* argfilename) : m_file_name(argfilename), m_is_opened(false), 
m_is_open_now(false), m_file_length(0),
m_file_buffer(nullptr)
{
	DEBUG_PRINT("Nazwa pliku:");
	DEBUG_PRINT(m_file_name);
	DEBUG_PRINT("\n");

	OpenFile();

	if (m_is_open_now == true)
	{
		MeasureFile();
		PutFileToBuffer();
		m_input_file.close();
		m_is_open_now = m_input_file.is_open();

	}
}

void InputBinFile::OpenFile()
{
	m_input_file.open(m_file_name, std::ios::in | std::ios::binary);

	m_is_opened = m_input_file.is_open();
	m_is_open_now = m_is_opened;

}

void InputBinFile::MeasureFile()
{
	m_input_file.seekg(0, std::ios_base::end); // Przeskakuje na koniec pliku.
	m_file_length = m_input_file.tellg(); // Pobieram koncowa pozycje.
	m_input_file.seekg(0, std::ios_base::beg); // Wracam na poczatek pliku.
}


void InputBinFile::PutFileToBuffer()
{
	m_file_buffer = new uint8_t[m_file_length];
	m_input_file.read(reinterpret_cast<char*>(m_file_buffer), m_file_length);

}

bool InputBinFile::GetIsOpened() const { return m_is_opened; }
bool InputBinFile::GetIsOpenNow() const { return m_is_open_now; }
uint64_t InputBinFile::GetFileLength() const { return m_file_length; }

InputBinFile::~InputBinFile()
{
	if (m_is_open_now == false && m_is_opened == true)
		delete[] m_file_buffer;
	
}

void InputBinFile::Informations(std::ostream& o) const
{
	o << std::endl
		<< "-------------------------------------" << std::endl
		<< "Opening the file:" << m_file_name << std::endl
		<< "Was the file successfully opened?: " << m_is_opened << std::endl
		<< "Is the file currently open?: " << m_is_open_now << std::endl
		<< "-------------------------------------" << std::endl
		<< std::endl;
}


void InputBinFile::ExitWhenFileDontExist(std::ostream& o) const
{
	if (m_is_opened == false && m_is_open_now == false)
	{
		o << "The specified file does not exist!" << std::endl;
		exit(EXIT_FAILURE);
	}
}



//------------------
// BINARY UTILS
//------------------

BinaryUtils::BinaryUtils(uint8_t* argfilebuffer, uint64_t argfilelength) :
	m_file_buffer(argfilebuffer), m_current_offset(0), m_file_length(argfilelength)
{
}


void BinaryUtils::Write1BITMASK(std::string& name, int quadcount, const uint8_t& value ,std::stringstream& output)
{
    WriteQuad('\t', output, quadcount);
    output << "1bitmask " << name << " = " << value << ";" << std::endl;
}

void BinaryUtils::WriteAll1BITMASKS(std::vector<std::string>& mask_labels, int quadcount, 
    std::string main_label, std::stringstream& output, int size)
{
    std::string binary_value;

    output << std::endl;
    WriteQuad('\t', output, quadcount);
    output << "// " << main_label << std::endl;

    for (int j = 0; j < size; ++j)
    {
        binary_value = DecByteToReversedBin(GetVALUE<uint8_t>());

        for (int i = 0; i < binary_value.length(); ++i)
        {
            Write1BITMASK(mask_labels[j * binary_value.length() + i], quadcount, binary_value[i], output);
        }
    }

    output << std::endl;

}

template<typename T>
void BinaryUtils::WriteNBitMask(uint8_t nbits, std::string name, std::string main_label, 
    std::unordered_map<uint32_t, std::string>& list_of_masks, 
    int quadcount, std::stringstream& output)
{
    std::set<std::string> masks_strings = {};

    T value;

    const int tetrad = 4;
    
    const int digits = (sizeof(T) * byte_to_bits) / tetrad;

    T hex_value_4bits[digits] = {};
    T and_mask = static_cast<T>(0x0000000F);

    output << std::endl;
    WriteQuad('\t', output, quadcount);
    output << "// " << main_label << std::endl;
    WriteQuad('\t', output, quadcount);
    output << static_cast<uint32_t>(nbits) << "bitmask " << name << " = (";

    value = GetVALUE<T>();

    for (int i = 0; i < digits; ++i)
    {    
        hex_value_4bits[i] = value & and_mask;
        and_mask = and_mask << tetrad;

        masks_strings.insert( list_of_masks[hex_value_4bits[i]] );
    }

    int j = 0;
    for (std::string mask : masks_strings)
    {
        output << mask;

        if (j < masks_strings.size() - 1) output << " | ";

        ++j;
    }

    output << ");" << std::endl << std::endl;

}


void BinaryUtils::WriteSTRING(std::string name, int quadcount, std::stringstream& output)
{
	WriteQuad('\t', output, quadcount);
	output << "string " << name << " = \"" << GetString() << "\";" << std::endl;
}

template<typename T>
void BinaryUtils::WriteINT(uint32_t mode, std::string name, int quadcount, std::stringstream& output, int count, char signed_or_unsigned)
{
	for (int i = 0; i < count; ++i)
	{
		WriteQuad('\t', output, quadcount);
		output << ((signed_or_unsigned == 'u') ? ("u") : ("")) << "int" << mode << "_t " << name 
            << ((count == 1) ? ("") : (std::to_string(i))) << " = ";

		if (mode == byte_to_bits)
		{
            output << ((signed_or_unsigned == 'u') ? (static_cast<uint32_t>(GetVALUE<T>())) : (static_cast<int32_t>(GetVALUE<T>())));
		}
		else
		{
			output << GetVALUE<T>();
		}

		output << ";" << std::endl;
	}
}


template<typename T>
void BinaryUtils::WriteUNIQUEKEYwithCONST(uint32_t mode, std::string name, std::unordered_map<T, std::string>& list_of_masks,
    int quadcount, std::stringstream& output, int count)
{
    T value;

    for (int i = 0; i < count; ++i)
    {
        value = GetVALUE<T>();

        if (list_of_masks[value] == "")
        {
            m_current_offset -= sizeof(T);
            WriteINT<T>(mode, name, quadcount, output, count, 'u');
            continue;
        }

        WriteQuad('\t', output, quadcount);
        output << mode << "bituniquekey " << name << ((count == 1) ? ("") : (std::to_string(i))) << " = "
         << list_of_masks[value]
         << ";" << std::endl;
    }
}

void BinaryUtils::WriteGUID(std::string name, int quadcount, std::stringstream& output)
{
	WriteQuad('\t', output, quadcount);
	output << "GUID " << name << " = " << GetGUID() << ";" << std::endl;
}

void BinaryUtils::WriteTIME32(std::string name, int quadcount, std::stringstream& output)
{
	std::uint32_t timevalue = GetVALUE<uint32_t>();

	time_t mytime = static_cast<time_t>(timevalue);

	char buffer[64];
	std::tm timeinfo;

	WriteQuad('\t', output, quadcount);

	output << "uint32_t " << name << " = " << timevalue << "; // ";

	if (localtime_s(&timeinfo, &mytime) == 0)
	{
		std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeinfo);
		output << buffer << std::endl;
	}
	else
	{
		output << "Incorrect time value: " << timevalue << std::endl;
	}

}

std::string BinaryUtils::GetString(void)
{
	std::string takedstring = std::string();
	uint32_t lenghtofstring = GetVALUE<uint32_t>();

	for (uint32_t i = 0; i < lenghtofstring; ++i)
	{
		if (m_file_buffer[m_current_offset] == 0) { break; }

		takedstring += m_file_buffer[m_current_offset];
		++m_current_offset;

	}

	return takedstring;
}

template<typename T>
T BinaryUtils::GetVALUE(void)
{
	T value = reinterpret_cast<T&>(m_file_buffer[m_current_offset]);
	m_current_offset += sizeof(T);
	return value;
}

std::string BinaryUtils::GetGUID(void)
{
	constexpr const int static number_of_uint16_fields = 2;

	std::string myGUID = std::string();

	myGUID += "{" + std::format("{:08X}", GetVALUE<uint32_t>());

	for (int i = 0; i < number_of_uint16_fields; ++i)
		myGUID += "-" + std::format("{:04X}", GetVALUE<uint16_t>());

	myGUID += "-" + std::format("{:04X}", _byteswap_ushort(GetVALUE<uint16_t>())) + "-";
	myGUID += std::format("{:08X}", _byteswap_ulong(GetVALUE<uint32_t>()));
	myGUID += std::format("{:04X}", _byteswap_ushort(GetVALUE<uint16_t>())) + "}";

	return myGUID;
}

std::string BinaryUtils::GetLOGICTABLE(void)
{
	std::string mask = std::string();
	uint32_t lenghtofmask = GetVALUE<uint32_t>();

	for (uint32_t i = 0; i < lenghtofmask; ++i)
	{
		if (m_file_buffer[m_current_offset] == 0)
			mask += '0';

		if (m_file_buffer[m_current_offset] == 1)
			mask += '1';

        if(i != lenghtofmask - 1)
            mask += ',';

		++m_current_offset;
	}

	return mask;
}


//--------------------------------
// ParDecompilerOverlay CLASS
//--------------------------------
void ParDecompilerOverlay::InitializeHashMaps()
{
    m_list_of_passive_masks[0x00000001] = "_bridgePassive_";
    m_list_of_passive_masks[0x00000002] = "_pontoonBridgePassive_";
    m_list_of_passive_masks[0x00000003] = "_singleBridgePassive_";
    m_list_of_passive_masks[0x00000004] = "_singlePontoonBridgePassive_";
    m_list_of_passive_masks[0x00000005] = "_bridgeRuinPassive_";
    m_list_of_passive_masks[0x00000006] = "_pontoonBridgeRuinPassive_";
    m_list_of_passive_masks[0x00000007] = "_artefactPassive_";
    m_list_of_passive_masks[0x00000008] = "_tunnelEntrancePassive_";
    m_list_of_passive_masks[0x00000009] = "_healthPlacePassive_";
    m_list_of_passive_masks[0x0000000A] = "_conversionPlacePassive_";
    m_list_of_passive_masks[0x0000000B] = "_teleportPassive_";
    m_list_of_passive_masks[0x0000000C] = "_birdPassive_";
    m_list_of_passive_masks[0x0000000D] = "_waterAnimalPassive_";
    m_list_of_passive_masks[0x00000000] = "_mapOtherPassive_";
    m_list_of_passive_masks[0x00000010] = "_mapNothingPassive_";
    m_list_of_passive_masks[0x00000020] = "_mapBuildingPassive_";
    m_list_of_passive_masks[0x00000030] = "_mapRockPassive_";
    m_list_of_passive_masks[0x00000040] = "_mapTreePassive_";
    m_list_of_passive_masks[0x00000050] = "_mapWallPassive_";
    m_list_of_passive_masks[0x00000060] = "_mapEditorPassive_";

    m_list_of_magicAnimType_masks[0] = "equipmentAnimTypeNone";
    m_list_of_magicAnimType_masks[1] = "equipmentAnimTypeFight";
    m_list_of_magicAnimType_masks[2] = "equipmentAnimTypeFight2";
    m_list_of_magicAnimType_masks[3] = "equipmentAnimTypeShoot";
    m_list_of_magicAnimType_masks[4] = "equipmentAnimTypeMagic1";
    m_list_of_magicAnimType_masks[5] = "equipmentAnimTypeMagic2";
    m_list_of_magicAnimType_masks[6] = "equipmentAnimTypeMagic3";
    m_list_of_magicAnimType_masks[7] = "equipmentAnimTypeMagic4";
    m_list_of_magicAnimType_masks[0x00000000] = "magicTalkNone";
    m_list_of_magicAnimType_masks[0x00010000] = "magicTalk1";
    m_list_of_magicAnimType_masks[0x00020000] = "magicTalk2";
    m_list_of_magicAnimType_masks[0x00030000] = "magicTalk3";
    m_list_of_magicAnimType_masks[0x00040000] = "magicTalk4";


    m_list_of_magicType_masks[0] = "NULL";
    m_list_of_magicType_masks[1] = "magicImmortalShield";
    m_list_of_magicType_masks[2] = "magicFreeze";
    m_list_of_magicType_masks[3] = "magicCapturing";
    m_list_of_magicType_masks[4] = "magicStorm";
    m_list_of_magicType_masks[5] = "magicSeeing";
    m_list_of_magicType_masks[6] = "magicConversion";
    m_list_of_magicType_masks[7] = "magicFireRain";
    m_list_of_magicType_masks[8] = "magicRemoveStormFireRain";
    m_list_of_magicType_masks[9] = "magicTeleportation";
    m_list_of_magicType_masks[10] = "magicGhost";
    m_list_of_magicType_masks[11] = "magicWildAnimal";
    m_list_of_magicType_masks[12] = "magicTrap";
    m_list_of_magicType_masks[13] = "magicGetHP";
    m_list_of_magicType_masks[14] = "magicSingleFreeze";
    m_list_of_magicType_masks[15] = "magicBlindAttack";
    m_list_of_magicType_masks[16] = "magicTimedCapturing";
    m_list_of_magicType_masks[17] = "magicOurWildAnimal";
    m_list_of_magicType_masks[18] = "magicOurHoldWildAnimal";
    m_list_of_magicType_masks[19] = "magicOurMagicMirror";
    m_list_of_magicType_masks[20] = "magicRandConversion";
    m_list_of_magicType_masks[21] = "magicAroundDamage";
    m_list_of_magicType_masks[22] = "magicSelfHealing";
    m_list_of_magicType_masks[23] = "magicFireWall";


    m_list_of_trapType_masks[0] = "NULL";
    m_list_of_trapType_masks[1] = "typeHoldTrap";
    m_list_of_trapType_masks[2] = "typeDamageTrap";
    m_list_of_trapType_masks[3] = "typeHoldTrapOnce";

    m_list_of_explosionFlags_masks[0x00] = "noEarthquake";
    m_list_of_explosionFlags_masks[0x01] = "smallEarthquake";
    m_list_of_explosionFlags_masks[0x02] = "mediumEarthquake";
    m_list_of_explosionFlags_masks[0x03] = "bigEarthquake";

    m_list_of_missileType_masks[0] = "NULL";
    m_list_of_missileType_masks[1] = "missileSword";
    m_list_of_missileType_masks[2] = "missileInvisible";
    m_list_of_missileType_masks[3] = "missileCannon";
    m_list_of_missileType_masks[4] = "missileDropBomb";
    m_list_of_missileType_masks[5] = "missileBomb";
    m_list_of_missileType_masks[6] = "missileElectric";
    m_list_of_missileType_masks[7] = "missileLightning";
    m_list_of_missileType_masks[8] = "missileMeteor";

    m_list_of_objectType_masks[0x00] = "animNone";
    m_list_of_objectType_masks[0x01] = "animWalk";
    m_list_of_objectType_masks[0x02] = "animRotor";
    m_list_of_objectType_masks[0x02] = "animRotation";
    m_list_of_objectType_masks[0x0000] = "moveLand";
    m_list_of_objectType_masks[0x0100] = "moveAmphibia";
    m_list_of_objectType_masks[0x0200] = "moveShip";
    m_list_of_objectType_masks[0x0300] = "moveFlyable";
    m_list_of_objectType_masks[0x10000] = "notMoveable";

    m_list_of_buildingType_masks[0] = "buildingNormal";
    m_list_of_buildingType_masks[1] = "buildingFactory";
    m_list_of_buildingType_masks[2] = "buildingHarvestFactory";
    m_list_of_buildingType_masks[3] = "buildingGate";
    m_list_of_buildingType_masks[4] = "buildingBridgeGate";
    m_list_of_buildingType_masks[5] = "buildingTower";
    m_list_of_buildingType_masks[6] = "buildingWall";
    m_list_of_buildingType_masks[7] = "buildingCopula";

    m_list_of_wasteSize_masks[0] = "smallFlyingWaste";
    m_list_of_wasteSize_masks[1] = "mediumFlyingWaste";
    m_list_of_wasteSize_masks[2] = "bigFlyingWaste";
        	
    m_list_of_groupTemplateNum_masks[91] = "groupSword";
    m_list_of_groupTemplateNum_masks[92] = "groupDrop";
    m_list_of_groupTemplateNum_masks[93] = "groupMag";
    m_list_of_groupTemplateNum_masks[94] = "groupSpecial";
    m_list_of_groupTemplateNum_masks[95] = "groupAnimal";
    m_list_of_groupTemplateNum_masks[96] = "groupMulti";
    m_list_of_groupTemplateNum_masks[97] = "groupBuilding";


    m_list_of_positionType_masks[0] = "positionStartingPoint";
    m_list_of_positionType_masks[1] = "positionMarkPoint";
    m_list_of_positionType_masks[2] = "positionProductionPoint";

    m_list_of_raceFlags_masks[0x01] = "eCanBePlayedInSkirmish";

    m_list_of_standType_masks[0x0000] = "standNone";
    m_list_of_standType_masks[0x0001] = "standAccurate";
    m_list_of_standType_masks[0x0002] = "standVertical";
    m_list_of_standType_masks[0x0003] = "standCoarsly";
    m_list_of_standType_masks[0x0004] = "standSwing";
    m_list_of_standType_masks[0x0005] = "standWater";
    m_list_of_standType_masks[0x0010] = "standMoveDownSmall";
    m_list_of_standType_masks[0x0020] = "standMoveDownMedium";
    m_list_of_standType_masks[0x0030] = "standMoveDownBig";
    m_list_of_standType_masks[0x0040] = "standTurn";
    m_list_of_standType_masks[0x0080] = "standTurnToFlat";
    m_list_of_standType_masks[0x0100] = "standMoveSmall";
    m_list_of_standType_masks[0x0200] = "standMoveMedium";
    m_list_of_standType_masks[0x0300] = "standMoveBig";
    m_list_of_standType_masks[0x0345] = "standWaterPlant";
    m_list_of_standType_masks[0x0340] = "standTree";
    m_list_of_standType_masks[0x0380] = "standTreeFall";
    m_list_of_standType_masks[0x0150] = "standRock";
    m_list_of_standType_masks[0x0140] = "standStone";
    m_list_of_standType_masks[0x0045] = "standFish";


    m_list_of_hitType_masks[0] = "singleHit";
    m_list_of_hitType_masks[1] = "multiHit";

    m_list_of_experienceExplosionPos_masks[0] = "expPosZero";

    m_list_of_equipmentFlags_masks[0x01] = "shieldArmourType";
    m_list_of_equipmentFlags_masks[0x02] = "maxArmourType";
    
    m_list_of_race_masks[0] = "NEUTRAL";
    m_list_of_race_masks[1] = "POL";

}


void ParDecompilerOverlay::GetCfgFile()
{
    const char cfgfilename[] = "PARex.cfg";

    if (!std::filesystem::exists(cfgfilename))
    {
        std::fstream cfg_file_new;
        m_o << "PARex.cfg file does not exist so I created a new one...." << std::endl;
        cfg_file_new.open(cfgfilename, std::ios::out); // dodatkowy plik z orderem
        cfg_file_new << text_of_cfg_file << std::endl;
        cfg_file_new.close();
    }

    InputBinFile cfgfile(const_cast<char*>(cfgfilename));
    cfgfile.Informations(m_o);
    cfgfile.ExitWhenFileDontExist(m_o);


    if (cfgfile.m_file_buffer != nullptr && cfgfile.GetFileLength() != 0)
    {
        for (uint64_t i = 0; i < cfgfile.GetFileLength() - 1; ++i)
        {
            if ((cfgfile.m_file_buffer[i] == '/') && (cfgfile.m_file_buffer[i + 1] == '/'))
            {
                m_its_comment = !(m_its_comment);
            }

            if ((cfgfile.m_file_buffer[i] == 0x0D) && (cfgfile.m_file_buffer[i + 1] == 0x0A) && (m_its_comment == true))
            {
                m_its_comment = !(m_its_comment);
            }

            if (m_its_comment == true)
            {
                cfgfile.m_file_buffer[i] = ' ';
                continue;
            }
        }


        for (uint64_t i = 0; i < cfgfile.GetFileLength() - 1; ++i)
        {
            if (cfgfile.m_file_buffer[i] == '\"')
            {
                m_its_string = !m_its_string;
            }

            if ((cfgfile.m_file_buffer[i] <= 32) && (m_its_string == false))
            {
                continue;
            }

            m_cfg_clean_file.push_back(cfgfile.m_file_buffer[i]);
        }
    }
}

void ParDecompilerOverlay::GetInfoFromCfg()
{
    m_o << "PARex.cfg:" << std::endl
        << "##########" << std::endl
        << "1bitmasks:" << std::endl;

    for (uint64_t i = 0; i < m_cfg_clean_file.size(); ++i)
    {
        m_instruction += m_cfg_clean_file[i];

        if (m_cfg_clean_file[i] == ';')
        {
            DEBUG_PRINT("----\n");
            DEBUG_PRINT(m_instruction.c_str());
            DEBUG_PRINT("\n");

            GetValuesFromString();
            InitializeSwitches(m_value_type, m_value);

            DEBUG_PRINT(m_value_type.c_str()); DEBUG_PRINT("\n");
            DEBUG_PRINT(m_value.c_str()); DEBUG_PRINT("\n");
            DEBUG_PRINT("----\n");

            m_instruction = std::string();
            m_value_type = std::string();
            m_value = std::string();
        }
    }

    m_o << "-----------------" << std::endl;
}

void ParDecompilerOverlay::GetValuesFromString()
{
    while (1)
    {
        bool nopswitch = true;

        //Sprawdzenie czy jest prawidlowy typ
        for (uint32_t i = 0; i < numberofvaluetypes; ++i)
        {
            if (m_instruction.substr(0, std::string(valuetypes[i]).length()) == valuetypes[i])
            {
                m_value_type = valuetypes[i];
                nopswitch = false;
                break;
            }
        }

        // Jesli typ byl nieprawidlowy czyli nopswitch == true to wychodze
        if (nopswitch == true)
        {
            m_value_type = "nop";
            m_value = std::string();
            return;
        }

        //Wyodrebnienie wartosci od instrukcji
        uint64_t valueindex = m_instruction.find("=") + 1;
        m_value = m_instruction.substr(valueindex, m_instruction.length() - valueindex - 1);

        
        if (m_value == "YES" || m_value == "yes" || m_value == "Yes" || 
            m_value == "TRUE" || m_value == "true" || m_value == "True")
        {
            m_value = "1";
            return;
        }
            
        if (m_value == "NO" || m_value == "no" || m_value == "No" ||
            m_value == "FALSE" || m_value == "false" || m_value == "False" )
        {
            m_value = "0";
            return;
        }
            

        break;
    }

}

void ParDecompilerOverlay::InitializeSwitches(std::string& valuetype, std::string& value)
{
    // moveableFlags
    if(valuetype == valuetypes[0])
    {
        moveableFlags_switch = std::stoul(value,nullptr,10);
        
        m_o << valuetype << " = " << moveableFlags_switch << std::endl;

        return;
    }

    // plugType
    if (valuetype == valuetypes[1])
    {
        plugType_switch = std::stoul(value, nullptr, 10);

        m_o << valuetype << " = " << plugType_switch << std::endl;

        return;
    }

    // slotType
    if (valuetype == valuetypes[2])
    {
        slotType_switch = std::stoul(value, nullptr, 10);

        m_o << valuetype << " = " << slotType_switch << std::endl;

        return;
    }

    // storeableFlags
    if (valuetype == valuetypes[3])
    {
        storeableFlags_switch = std::stoul(value, nullptr, 10);

        m_o << valuetype << " = " << storeableFlags_switch << std::endl;

        return;
    }

    // RPGUnitFlags
    if (valuetype == valuetypes[4])
    {
        RPGUnitFlags_switch = std::stoul(value, nullptr, 10);

        m_o << valuetype << " = " << RPGUnitFlags_switch << std::endl;

        return;
    }

    // artefactMask
    if (valuetype == valuetypes[5])
    {
        artefactMask_switch = std::stoul(value, nullptr, 10);

        m_o << valuetype << " = " << artefactMask_switch << std::endl;

        return;
    }

    // repairerFlags
    if (valuetype == valuetypes[6])
    {
        repairerFlags_switch = std::stoul(value, nullptr, 10);

        m_o << valuetype << " = " << repairerFlags_switch << std::endl;

        return;
    }

    // bridgeBordersMask
    if (valuetype == valuetypes[7])
    {
        bridgeBordersMask_switch = std::stoul(value, nullptr, 10);

        m_o << valuetype << " = " << bridgeBordersMask_switch << std::endl;

        return;
    }

    // shadowType
    if (valuetype == valuetypes[8])
    {
        shadowType_switch = std::stoul(value, nullptr, 10);

        m_o << valuetype << " = " << shadowType_switch << std::endl;

        return;
    }

    // targetType
    if (valuetype == valuetypes[9])
    {
        targetType_switch = std::stoul(value, nullptr, 10);

        m_o << valuetype << " = " << targetType_switch << std::endl;

        return;
    }

    // lookRoundTypeMask
    if (valuetype == valuetypes[10])
    {
        lookRoundTypeMask_switch = std::stoul(value, nullptr, 10);

        m_o << valuetype << " = " << lookRoundTypeMask_switch << std::endl;

        return;
    }

    // passiveMask
    if (valuetype == valuetypes[11])
    {
        passiveMask_switch = std::stoul(value, nullptr, 10);

        m_o << valuetype << " = " << passiveMask_switch << std::endl;

        return;
    }

    // buildBuildingFlags
    if (valuetype == valuetypes[12])
    {
        buildBuildingFlags_switch = std::stoul(value, nullptr, 10);

        m_o << valuetype << " = " << buildBuildingFlags_switch << std::endl;

        return;
    }

    // panelPos
    if (valuetype == valuetypes[13])
    {
        panelPos_switch = std::stoul(value, nullptr, 10);

        m_o << valuetype << " = " << panelPos_switch << std::endl;

        return;
    }

}


ParDecompilerOverlay::ParDecompilerOverlay(std::istream& argin, std::ostream& argo, int my_argc, char* my_argv[]) : 
	m_in_stream(argin), m_o(argo), m_number_of_sections(0), m_help_str(std::string()), m_bits(std::string()),
    m_single_value(0), m_single_section_file_name(std::string()), m_section_order_file_path(std::string()),
    m_end_of_par_file_path(std::string()), m_par_header_file_path(std::string()), m_number_of_objects(0),
    m_section_name(std::string()), m_classid(0xFFFFFFFF), m_its_comment(false), m_its_string(false),

    m_instruction(std::string()), m_value_type(std::string()), m_value(std::string()),

    moveableFlags_switch(true),plugType_switch (true), slotType_switch(true), storeableFlags_switch(true),
    RPGUnitFlags_switch(true), artefactMask_switch(true), repairerFlags_switch(true),bridgeBordersMask_switch(true),
    shadowType_switch(true), targetType_switch(true), lookRoundTypeMask_switch(true), passiveMask_switch(true),
    buildBuildingFlags_switch(true), panelPos_switch(true)
{
    std::filesystem::create_directory("PARex_DATA"); // folder roboczy
    //argc argv
    
    if (my_argc == 3)
    {
       m_input_par_file_name = *(my_argv + 1);
       m_export_directory_name = *(my_argv + 2);
       m_o << "Input file = " << m_input_par_file_name << std::endl;
       m_o << "Output directory = " << m_export_directory_name << std::endl;
    }
    else
    {
        ShowIntroScreen(); //intro screen
        StandardProgramLaunch();
    }
    
    GetCfgFile();
    GetInfoFromCfg();

    InitializeHashMaps();

    //wazne stringi od nazw plikow wewnatrz exportu
    //------------------------------------------
    m_par_header_file_path = m_export_directory_name + "\\" + par_header_file_name + ".cpp"; //sklejenie nazwy folderu out z plikiem head data
    m_end_of_par_file_path = m_export_directory_name + "\\" + end_of_par_file_name + ".cpp"; //sklejenie nazwy folderu out z plikiem end
    m_section_order_file_path = m_export_directory_name + "\\" + section_order_file_name + ".txt"; //sklejenie nazwy folderu out z plikiem porzadku order
    //-------------------------------------

    std::filesystem::create_directory(m_export_directory_name); //stworzenie folderu do exportu
    
    m_o << "ATTENTION - wait a minute...." << std::endl; //jakis chujowy kom
    //----------------------------
    InputBinFile inputpar(const_cast<char*>(m_input_par_file_name.c_str())); // plik input .par
    inputpar.Informations(m_o);
    inputpar.ExitWhenFileDontExist(m_o);

    myInputParUtil = BinaryUtils(inputpar.m_file_buffer, inputpar.GetFileLength());
    DecompilePar();

    m_o << "DONE! - I finished the job!" << std::endl;

}
void ParDecompilerOverlay::DecompilePar()
{
    m_editor_names_file.open(editor_names_file_name, std::ios::out); // dodatkowy plik z nazwami do edytora

    WriteRaceDataFile();
    WriteAllParSections();
    // --- End file -----
    WriteEndFile();
    // -------------------

    auto strData(m_editor_names_stream.str());
    m_editor_names_file.write(&strData[0], strData.size());

    m_editor_names_file.close();
}


void ParDecompilerOverlay::StandardProgramLaunch()
{
   m_o << "Enter the name of the input .par file along with the extension:" << std::endl;
   m_in_stream >> m_input_par_file_name; //pobranie nazwy pliku input od uzytkownika

   m_export_directory_name = m_input_par_file_name.substr(0, m_input_par_file_name.length() - 4);
   m_o << "Output directory:" << m_export_directory_name << std::endl;
   
   //m_o << "Specify the name of the output folder to which I should save the export:" << std::endl;
   //m_in_stream >> m_export_directory_name; //pobranie nazwy folderu out od uzytkownika
    
}

void ParDecompilerOverlay::WriteRaceDataFile()
{
    //********stworzenie pliku race data i pisanie w nim ***********
    std::stringstream _par_header_stream;
    m_par_header_file.open(m_par_header_file_path, std::ios::out);

    //-----race data
    _par_header_stream << "struct ParHeader" << std::endl
        << "{" << std::endl;

    //-----------time----------------
    myInputParUtil.WriteTIME32("time", 1, _par_header_stream);
    //-------------------------------

    //translategameparams
    uint8_t headerstringlength = myInputParUtil.GetVALUE<uint8_t>();

    _par_header_stream << "\tuint8_t header_string_length = " << static_cast<uint32_t>(headerstringlength) << ";" << std::endl
        << "\tchar header_string[header_string_length] = \"";

    for (uint8_t i = 0; i < headerstringlength; ++i) { _par_header_stream << myInputParUtil.GetVALUE<uint8_t>(); }

    _par_header_stream << "\";" << std::endl << std::endl;
    //----------------

    //GUID SEPARATOR - start
    myInputParUtil.WriteINT<uint32_t>(32, "parameters_version_start", 1, _par_header_stream);
    //----------------

    //GUID - get and write
    myInputParUtil.WriteGUID("header_guid", 1, _par_header_stream);
    _par_header_stream << std::endl;
    myInputParUtil.WriteINT<uint8_t>(8, "format_", 1, _par_header_stream, 4);
    //----------------

    //GUID SEPARATOR - END
    myInputParUtil.WriteINT<uint32_t>(32, "parameters_version_end", 1, _par_header_stream);
    _par_header_stream << std::endl;
    //----------------

    //NUMBER OF SECTIONS
    m_number_of_sections = myInputParUtil.GetVALUE<uint64_t>();
    _par_header_stream << "\tuint64_t number_of_sections = count();"<< std::endl;
    //par_header_file << "\tuint64_t number_of_sections = " << number_of_sections << ";" << std::endl;
    //----------------

    _par_header_stream << "};";
    //----------------
    //end of race data

    auto strData(_par_header_stream.str());
    m_par_header_file.write(&strData[0], strData.size());


    m_par_header_file.close();
    //zamkniecie pliku race data
    //***************************
}


void ParDecompilerOverlay::WriteSectionHeader(uint32_t& section_index)
{
    //****header sekcji************
    m_data << "struct Section_" << section_index << "_" << m_section_name << "_Header" << std::endl
                << "{" << std::endl;

    //--flags
    myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "race", m_list_of_race_masks, 1, m_data);
    myInputParUtil.WriteINT<uint32_t>(32, "flag_", 1, m_data, 1);

    //--number of obj
    m_number_of_objects = myInputParUtil.GetVALUE<uint32_t>();
    m_data << "\tuint32_t number_of_objects = count();" << std::endl;

    m_data << "};" << std::endl << std::endl;

    //*********************
}

void ParDecompilerOverlay::WriteSingleSectionFile(uint32_t& h)
{
    m_data = std::stringstream();

    m_single_section_file.open(m_single_section_file_name, std::ios::out);
    WriteSectionHeader(h);

    for (uint32_t j = 0; j < m_number_of_objects; j++)
    {
        //-----obiekt i jego definicja     
        m_help_str = myInputParUtil.GetString();
        WriteSingleObject();
    }

    auto strData(m_data.str());
    m_single_section_file.write(&strData[0], strData.size());

    m_single_section_file.close();
}



void ParDecompilerOverlay::CheckMaskLabelsAndCorrect(std::vector<std::string>& masklabels)
{
    const size_t number_of_bits_in_int = 32;

    if (masklabels.size() < number_of_bits_in_int)
    {
        size_t delta = number_of_bits_in_int - masklabels.size();
        for (int j = 0; j < delta; ++j)
        {
            masklabels.push_back("ExtraFlag" + std::to_string(j));
        }
    }

}

void ParDecompilerOverlay::PrintLabels(std::vector<std::string>& labels)
{
    int i = 0;

    size_t delta = (m_bits.length() + 1) / 2;
    if (delta > labels.size())
    {
        delta -= labels.size();

        for (int j = 0; j < delta; ++j)
            labels.push_back("ExtraField" + std::to_string(j));
    }

    bool is_special = false;

    for (std::string label : labels)
    {
        
        if (label[0] == '$')
        {
            is_special = true;
        }
        else
        {
            is_special = false;
        }

        switch (m_bits[i])
        {
            case '0':
                CheckIfItIsAMaskLabel(label);
                
            break;

            case '1':

                if (is_special == true)
                {
                    myInputParUtil.WriteSTRING(label, 1, m_data);
                    myInputParUtil.WriteINT<uint32_t>(32, label, 1, m_data);
                }
                else
                {
                    myInputParUtil.WriteSTRING(label, 1, m_data);
                }
            break;

            default: break;
        }
        

        if (is_special == true)
        {
            i += 2;
        }

        i += 2;

        if (i > m_bits.length() - 1) break;

    }

}

bool ParDecompilerOverlay::CheckIfClassIdIsADefinedMask() const
{
    for (int i = 0; i < _countof(defined_mask_values); ++i)
        if (m_classid == defined_mask_values[i])
            return true;
    

    return false;
}

void ParDecompilerOverlay::CheckClassIdAndCorrect()
{
    m_classid = 0xFFFFFFFF;

    if (m_bits.length() > 0)
    {
        if (m_bits[0] == '0')
        {
            m_classid = myInputParUtil.GetVALUE<uint32_t>();
            myInputParUtil.m_current_offset -= sizeof(uint32_t);
        }
    }

    if (CheckIfClassIdIsADefinedMask() == true)
    {
        return;
    }


    if (m_help_str.substr(0, 5) == "TALK_")
    {
        m_classid = 0x01FFFFFF;
        return;
    }

    if( (m_help_str.substr(0, 11) == "ANIMPARAMS_") ||
        (m_help_str.substr(0, 11) == "del_parAMS_") ||
        (m_help_str.substr(0, 15) == "OLD_ANIMPARAMS_") )
    {
        m_classid = 0x02FFFFFF;
        return;
    }



    if (m_help_str.substr(0, 4) == "SND_")
    {
        m_classid = 0x03FFFFFF;
        return;
    }
    

    if (m_help_str.substr(0, 19) == "PASSIVE_ANIMPARAMS_")
    {
        m_classid = 0x04FFFFFF;
        return;
    }

    if ((m_help_str.substr(0, 18) == "UNITTALKPACKDELAYS") ||
        (m_help_str.substr(0, 22) == "BUILDINGTALKPACKDELAYS"))
    {
        m_classid = 0x05FFFFFF;
        return;
    }
        

    if (m_help_str.substr(0, 14) == "PLAYERTALK_POL")
    {
        m_classid = 0x06FFFFFF;
        return;
    }

    if (m_help_str.substr(0, 20) == "PLAYERTALKPACKDELAYS")
    {
        m_classid = 0x07FFFFFF;
        return;
    }

    if (m_help_str.substr(0, 11) == "MUSIC_PACK_")
    { 
        m_classid = 0x08FFFFFF;
        return;
    }

    if (m_help_str.substr(0, 11) == "EXPERIENCE_")
    { 
        m_classid = 0x09FFFFFF;
        return;
    }

    if ((m_help_str.substr(0, 15) == "RPG_VIEWPARAMS_") ||
        (m_help_str.substr(0, 11) == "VIEWPARAMS_"))
    { 
        m_classid = 0x0AFFFFFF;
        return;
    }

    if (m_help_str.substr(0, 16) == "SELECTION_MESHES")
    { 
        m_classid = 0x0BFFFFFF;
        return;
    }

    if ((m_help_str.substr(0, 2) == "__") &&
        (m_help_str.substr(m_help_str.length() - 2, 2) == "__"))
    {
        m_classid = 0x0CFFFFFF;
    
        return;
    }


    if (m_help_str.substr(0, 5) == "RACE_")
    { 
        m_classid = 0x0DFFFFFF;
        return;
    }

    if( (m_help_str.substr(0, 4) == "RPG_") && ((m_bits.length() + 1)/2 <= 4))
    { 
        m_classid = 0x0EFFFFFF;
        return;
    }
    
    if( (m_help_str.substr(0, 14) == "RPG_EXPERIENCE") && (m_classid == SPECIALEQUIPMENT) )
    {
        m_classid = SPECIALEQUIPMENT;
        return;
    }

    if( (m_help_str.substr(0, 14) == "RPG_EXPERIENCE") ||
        (m_help_str.substr(0, 20) == "RPG_ENEMY_EXPERIENCE") )
    { 
        m_classid = 0x0FFFFFFF;
        return;
    }
}

void ParDecompilerOverlay::WriteSingleObject()
{
    
    m_editor_names_stream << m_help_str << std::endl;


    m_data << "struct " << m_help_str << std::endl
                << "{" << std::endl;

    m_data << "\tstring obj_name = \"" << m_help_str << "\";" << std::endl; //name


    m_single_value = myInputParUtil.GetVALUE<uint32_t>();

    m_data << "\tuint32_t research_switch = " << m_single_value << ";" << std::endl; //RES

    if (m_single_value == 1)
        myInputParUtil.WriteSTRING("research", 1, m_data);


    m_bits = myInputParUtil.GetLOGICTABLE();

    m_data << "\tbool classID_array[] = {" << m_bits << "};" << std::endl;
    
    CheckClassIdAndCorrect();

    SelectLabelsForClassId();

    m_data << "};" << std::endl << std::endl;

}

void ParDecompilerOverlay::WriteAllParSections()
{
    std::stringstream _section_order_stream;
    m_section_order_file.open(m_section_order_file_path, std::ios::out); // dodatkowy plik z orderem

    _section_order_stream << par_header_file_name << std::endl;

    for (uint32_t h = 0; h <= m_number_of_sections; h++)
    {
        myInputParUtil.m_current_offset += 3 * sizeof(uint32_t);
        m_section_name = myInputParUtil.GetString();
        myInputParUtil.m_current_offset -= m_section_name.length();
        myInputParUtil.m_current_offset -= 4 * sizeof(uint32_t);

        m_single_section_file_name = m_export_directory_name + "\\" + "section_" + std::to_string(h) + "_" + m_section_name + ".cpp";
        _section_order_stream << "section_" << h << "_" << m_section_name << std::endl;
        // ---------------------------------
        WriteSingleSectionFile(h);
    }

    _section_order_stream << end_of_par_file_name << std::endl;

    auto strData(_section_order_stream.str());
    m_section_order_file.write(&strData[0], strData.size());

    m_section_order_file.close();

}

void ParDecompilerOverlay::WriteEndFile()
{
    std::stringstream _end_of_par_stream;
    m_end_of_par_file.open(m_end_of_par_file_path, std::ios::out);

    _end_of_par_stream << "struct EndOfPar" << std::endl
        << "{" << std::endl;
    myInputParUtil.WriteINT<uint32_t>(32, "var_field", 1, _end_of_par_stream);
    myInputParUtil.WriteSTRING("str_field", 1, _end_of_par_stream);
    myInputParUtil.WriteINT<uint32_t>(32, "var_field_", 1, _end_of_par_stream, 5);
    myInputParUtil.WriteSTRING("str_field", 1, _end_of_par_stream);
    _end_of_par_stream << "};";

    auto strData(_end_of_par_stream.str());
    m_end_of_par_file.write(&strData[0], strData.size());

    m_end_of_par_file.close();
}


void ParDecompilerOverlay::ShowIntroScreen()
{
   m_o << "******************" << std::endl
       << "|PARexV3 BY ATLAS|" << std::endl
       << "*******2025*******" << std::endl;
}



void ParDecompilerOverlay::CheckIfItIsAMaskLabel(std::string& label)
{
    if (label == "mapSign")
    {
        myInputParUtil.WriteINT<int32_t>(32, label, 1, m_data, 1, 'd');
        return;
    }

    if ( (label == "moveableFlags") && (moveableFlags_switch == true))
    {
        CheckMaskLabelsAndCorrect(moveableFlags);
        myInputParUtil.WriteAll1BITMASKS(moveableFlags, 1, label, m_data);
        return;
    }

    if ((label == "buildBuildingFlags") && (buildBuildingFlags_switch == true))
    {
        CheckMaskLabelsAndCorrect(buildBuildingFlags);
        myInputParUtil.WriteAll1BITMASKS(buildBuildingFlags, 1, label, m_data);
        return;
    }

    if ((label == "plugType") && (plugType_switch == true) && (m_classid == MAGICEQUIPMENT) && (m_help_str.substr(0,4) == "RPG_"))
    {
        CheckMaskLabelsAndCorrect(rpgPlugType);
        myInputParUtil.WriteAll1BITMASKS(rpgPlugType, 1, label, m_data);
        return;
    }

    if ((label == "plugType") && (plugType_switch == true) && (m_classid == MAGICEQUIPMENT))
    {
        CheckMaskLabelsAndCorrect(slotType8);
        myInputParUtil.WriteAll1BITMASKS(slotType8, 1, label, m_data);
        return;
    }


    if( (label == "plugType") && (plugType_switch == true))
    {
        CheckMaskLabelsAndCorrect(plugTypes);
        myInputParUtil.WriteAll1BITMASKS(plugTypes, 1, label, m_data);
        return;
    }


    if ((label.substr(0, 9) == "slotType8") && (slotType_switch == true))
    {
        CheckMaskLabelsAndCorrect(slotType8);
        myInputParUtil.WriteAll1BITMASKS(slotType8, 1, label, m_data);
        return;
    }


    if( (label.substr(0, 8) == "slotType") && (slotType_switch == true))
    {
        CheckMaskLabelsAndCorrect(slotTypes);
        myInputParUtil.WriteAll1BITMASKS(slotTypes, 1, label, m_data);
        return;
    }

    if( (label == "storeableFlags") && (storeableFlags_switch == true))
    {
        CheckMaskLabelsAndCorrect(storeableFlags);
        myInputParUtil.WriteAll1BITMASKS(storeableFlags, 1, label, m_data);
        return;
    }

    if( (label == "RPGUnitFlags") && (RPGUnitFlags_switch == true))
    {
        CheckMaskLabelsAndCorrect(RPGUnitFlags);
        myInputParUtil.WriteAll1BITMASKS(RPGUnitFlags, 1, label, m_data);
        return;
    }

    if( (label == "artefactMask") && (artefactMask_switch == true))
    {
        CheckMaskLabelsAndCorrect(artefactMask);
        myInputParUtil.WriteAll1BITMASKS(artefactMask, 1, label, m_data);
        return;
    }

    if( (label == "repairerFlags") && (repairerFlags_switch == true))
    {
        CheckMaskLabelsAndCorrect(repairerFlags);
        myInputParUtil.WriteAll1BITMASKS(repairerFlags, 1, "first two bytes of " + label, m_data, sizeof(uint16_t));

        myInputParUtil.WriteINT<uint16_t>(16, label, 1, m_data);
        m_data << std::endl;

        return;
    }

    if( (label == "bridgeBordersMask") && (bridgeBordersMask_switch == true))
    {
        CheckMaskLabelsAndCorrect(bridgeBordersMask);
        myInputParUtil.WriteAll1BITMASKS(bridgeBordersMask, 1, label, m_data, sizeof(uint8_t));
        myInputParUtil.WriteINT<uint8_t>(8, label, 1, m_data, sizeof(uint32_t) - 1);
        m_data << std::endl;

        return;
    }

    if( (label == "shadowType") && (shadowType_switch == true))
    {
        CheckMaskLabelsAndCorrect(shadowType);
        myInputParUtil.WriteAll1BITMASKS(shadowType, 1, label, m_data, sizeof(uint32_t) - 1);
        myInputParUtil.WriteINT<uint8_t>(8, label, 1, m_data, 1, 'u');
        m_data << std::endl;

        return;
    }

    if( (label == "targetType") && (targetType_switch == true))
    {
        CheckMaskLabelsAndCorrect(targetType);
        myInputParUtil.WriteAll1BITMASKS(targetType, 1, label, m_data, sizeof(uint8_t));
        myInputParUtil.WriteINT<uint8_t>(8, label, 1, m_data, sizeof(uint32_t) - 1, 'u');
        m_data << std::endl;

        return;
    }


    if( (label == "lookRoundTypeMask") && (lookRoundTypeMask_switch == true))
    {
        CheckMaskLabelsAndCorrect(lookRoundTypeMask);
        myInputParUtil.WriteAll1BITMASKS(lookRoundTypeMask, 1, label, m_data);
        return;
    }


    if( (label == "passiveMask") && (passiveMask_switch == true))
    {
        myInputParUtil.WriteNBitMask<uint8_t>(8, "passiveMask", "first byte of " + label, m_list_of_passive_masks, 1, m_data);
        CheckMaskLabelsAndCorrect(passiveMask);
        myInputParUtil.WriteAll1BITMASKS(passiveMask, 1, "rest bytes of " + label, m_data, sizeof(uint32_t) - 1);
        return;
    }

    if((label == "panelPos") && (panelPos_switch == true))
    {
        m_data << std::endl;
        myInputParUtil.WriteINT<uint16_t>(16, label, 1, m_data, 1, 'u');

        CheckMaskLabelsAndCorrect(panelPos);
        myInputParUtil.WriteAll1BITMASKS(panelPos, 1, "third byte of " + label, m_data, sizeof(uint8_t));

        myInputParUtil.WriteINT<uint8_t>(8, label, 1, m_data, 1, 'u');
        m_data << std::endl;

        return;
    }

    if (label == "magicAnimType")
    {

        myInputParUtil.WriteNBitMask<uint32_t>(32, "magicAnimType", label, m_list_of_magicAnimType_masks, 1, m_data);
        return;
    }

    if (label == "objectType")
    {
        myInputParUtil.WriteNBitMask<uint32_t>(32, "objectType", label, m_list_of_objectType_masks, 1, m_data);
        return;
    }

    if (label == "magicType")
    {
        myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "magicType", m_list_of_magicType_masks, 1, m_data);
        return;
    }

    if (label == "buildingType")
    {
        myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "buildingType", m_list_of_buildingType_masks, 1, m_data);
        return;
    }

    if (label == "trapType")
    {
        myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "trapType", m_list_of_trapType_masks, 1, m_data);
        return;
    }

    if (label == "wasteSize")
    {
        myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "wasteSize", m_list_of_wasteSize_masks, 1, m_data);
        return;
    }

    if (label == "groupTemplateNum")
    {
        myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "groupTemplateNum", m_list_of_groupTemplateNum_masks, 1, m_data);
        return;
    }

    if (label == "positionType")
    {
        myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "positionType", m_list_of_positionType_masks, 1, m_data);
        return;
    }

    if (label == "explosionFlags")
    {
        myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "explosionFlags", m_list_of_explosionFlags_masks, 1, m_data);
        return;
    }

    if (label == "raceFlags")
    {
        myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "raceFlags", m_list_of_raceFlags_masks, 1, m_data);
        return;
    }

    if (label == "standType")
    {
        myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "standType", m_list_of_standType_masks, 1, m_data);
        return;
    }

    if (label == "experienceExplosionPos")
    {
        myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "experienceExplosionPos", m_list_of_experienceExplosionPos_masks, 1, m_data);
        return;
    }

    if (label == "equipmentFlags")
    {
        myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "equipmentFlags", m_list_of_equipmentFlags_masks, 1, m_data);
        return;
    }

    if (label == "hitType")
    {
        myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "hitType", m_list_of_hitType_masks, 1, m_data);
        return;
    }

    if( (label == "type") && (m_classid == MISSILE))
    {
        myInputParUtil.WriteUNIQUEKEYwithCONST<uint32_t>(32, "type", m_list_of_missileType_masks, 1, m_data);
        return;
    }

    myInputParUtil.WriteINT<uint32_t>(32, label, 1, m_data);


}
