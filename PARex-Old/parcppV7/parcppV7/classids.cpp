#include "parcppV7.hpp"
#include "posortowaneklasy.hpp"


std::vector<std::string> moveable = {
    "classID",
    "mesh",
    "lowResMesh",
    "lowRes2Mesh",
    "interfaceMesh",
    "shadowType",
    "forceMeshHeight",
    "viewParamsIndex",
    "panelTemplateNum",
    "selectedTemplateNum",
    "listTemplateNum",
    "groupTemplateNum",
    "panelPos",
    "cost",
    "timeOfBuild",
    "$soundPackID",
    "$smokeID",
    "$killExplosionID",
    "$destructedID",
    "hp",
    "hpRegenerationTicks",
    "armour1",
    "armour2",
    "armour3",
    "storeableFlags",
    "standType",
    "mapSign",
    "sightRange",
    "$talkPackID",
    "capturePercent",
    "capturePercentMul",
    "allowCaptureMask",
    "conversionPercentMul",
    "allowConversionMask",
    "maxMagic",
    "magicRegenerationTicks",
    "initMagicPercent",
    "killExperiencePoints",
    "unitDamage1",
    "unitDamage2",
    "unitDamage3",
    "slotType1",
    "slotType2",
    "slotType3",
    "slotType4",
    "slotType5",
    "slotType6",
    "slotType7",
    "slotType8",
    "$subObjectID1",
    "$subObjectID2",
    "$subObjectID3",
    "$subObjectID4",
    "$subObjectID5",
    "$subObjectID6",
    "$subObjectID7",
    "$subObjectID8",
    "$subObjectID9",
    "$subObjectID10",
    "$subObjectID11",
    "$subObjectID12",
    "moveableFlags",
    "$productionBuildingID",
    "formationPriority",
    "unitNameSet",
    "unitsListNumber",
    "soilSpeed",
    "roadSpeed",
    "sandSpeed",
    "bankSpeed",
    "waterSpeed",
    "deepWaterSpeed",
    "airSpeed",
    "camouflageSpeed",
    "runSpeed",
    "objectType",
    "$animParamsID",
    "$engineSmokeID",
    "$dustID",
    "$billowID",
    "$standBillowID",
    "$trackID",
    "$experienceExplosionID",
    "experienceExplosionPos",
    "experienceCustomAnimMask",
    "sleepModeHPRegAdd",
    "sleepModeMagicRegAdd",
    "sleepModeDamageMultiply",
    "exitTrapPercent",
    "exitTrapDamageMaxPercent",
    "scriptParams",
    "$childProtectHitExplosionID",
    "$childConversionExplosionID" };




std::vector < std::string > shopunit = {
    "classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"moveableFlags",
"$productionBuildingID",
"formationPriority",
"unitNameSet",
"unitsListNumber",
"soilSpeed",
"roadSpeed",
"sandSpeed",
"bankSpeed",
"waterSpeed",
"deepWaterSpeed",
"airSpeed",
"camouflageSpeed",
"runSpeed",
"objectType",
"$animParamsID",
"$engineSmokeID",
"$dustID",
"$billowID",
"$standBillowID",
"$trackID",
"$experienceExplosionID",
"experienceExplosionPos",
"experienceCustomAnimMask",
"sleepModeHPRegAdd",
"sleepModeMagicRegAdd",
"sleepModeDamageMultiply",
"exitTrapPercent",
"exitTrapDamageMaxPercent",
"scriptParams",
"$childProtectHitExplosionID",
"$childConversionExplosionID",
"shopType" };

std::vector<std::string> rpgunit = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"moveableFlags",
"$productionBuildingID",
"formationPriority",
"unitNameSet",
"unitsListNumber",
"soilSpeed",
"roadSpeed",
"sandSpeed",
"bankSpeed",
"waterSpeed",
"deepWaterSpeed",
"airSpeed",
"camouflageSpeed",
"runSpeed",
"objectType",
"$animParamsID",
"$engineSmokeID",
"$dustID",
"$billowID",
"$standBillowID",
"$trackID",
"$experienceExplosionID",
"experienceExplosionPos",
"experienceCustomAnimMask",
"sleepModeHPRegAdd",
"sleepModeMagicRegAdd",
"sleepModeDamageMultiply",
"exitTrapPercent",
"exitTrapDamageMaxPercent",
"scriptParams",
"$childProtectHitExplosionID",
"$childConversionExplosionID",
"rpgUnitType",
"RPGUnitFlags",
"rpgViewParamsNum",
"descriptionWave",
"inititializePoints",
"maxInventorySize",
"$experienceParamsID",
"$hpParamsID",
"$damage0ParamsID",
"$damage1ParamsID",
"$damage2ParamsID",
"$magicParamsID",
"$extraCannonDamageParamsID",
"$extraSwordDamageParamsID",
"$avoidSwordHitsParamsID",
"$avoidAnyHitsParamsID",
"$extraRangeParamsID",
"$camouflagingParamsID",
"$holdTrapParamsID",
"$runExtraDamageParamsID",
"$extraCrewDamageParamsID",
"$strongFightParamsID",
"$fastSleepHPRegenerationParamsID",
"$multiTargetDamageParamsID",
"$extraArmour0ParamsID",
"$scriptDiplomacyParamsID",
"$scriptArtefactParamsID",
"$pingMagicMissilesID",
"hireTime",
"hirePrice",
"hireSubObjectsPricePercent",
"$strongFightEffectID",
"$holdTrapID",
"$dropGoldArtefactID" };

std::vector <std::string> builder = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"moveableFlags",
"$productionBuildingID",
"formationPriority",
"unitNameSet",
"unitsListNumber",
"soilSpeed",
"roadSpeed",
"sandSpeed",
"bankSpeed",
"waterSpeed",
"deepWaterSpeed",
"airSpeed",
"camouflageSpeed",
"runSpeed",
"objectType",
"$animParamsID",
"$engineSmokeID",
"$dustID",
"$billowID",
"$standBillowID",
"$trackID",
"$experienceExplosionID",
"experienceExplosionPos",
"experienceCustomAnimMask",
"sleepModeHPRegAdd",
"sleepModeMagicRegAdd",
"sleepModeDamageMultiply",
"exitTrapPercent",
"exitTrapDamageMaxPercent",
"scriptParams",
"$childProtectHitExplosionID",
"$childConversionExplosionID",
"repairerFlags",
"repairHPPerTick",
"ticksPerRepair",
"captureMask",
"convertUnitTime",
"convertAnimalTime",
"convertBuildingTime" };

std::vector<std::string> repairer = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"moveableFlags",
"$productionBuildingID",
"formationPriority",
"unitNameSet",
"unitsListNumber",
"soilSpeed",
"roadSpeed",
"sandSpeed",
"bankSpeed",
"waterSpeed",
"deepWaterSpeed",
"airSpeed",
"camouflageSpeed",
"runSpeed",
"objectType",
"$animParamsID",
"$engineSmokeID",
"$dustID",
"$billowID",
"$standBillowID",
"$trackID",
"$experienceExplosionID",
"experienceExplosionPos",
"experienceCustomAnimMask",
"sleepModeHPRegAdd",
"sleepModeMagicRegAdd",
"sleepModeDamageMultiply",
"exitTrapPercent",
"exitTrapDamageMaxPercent",
"scriptParams",
"$childProtectHitExplosionID",
"$childConversionExplosionID",
"repairerFlags",
"repairHPPerTick",
"ticksPerRepair",
"captureMask",
"convertUnitTime",
"convertAnimalTime",
"convertBuildingTime" };


std::vector<std::string> harvester = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"moveableFlags",
"$productionBuildingID",
"formationPriority",
"unitNameSet",
"unitsListNumber",
"soilSpeed",
"roadSpeed",
"sandSpeed",
"bankSpeed",
"waterSpeed",
"deepWaterSpeed",
"airSpeed",
"camouflageSpeed",
"runSpeed",
"objectType",
"$animParamsID",
"$engineSmokeID",
"$dustID",
"$billowID",
"$standBillowID",
"$trackID",
"$experienceExplosionID",
"experienceExplosionPos",
"experienceCustomAnimMask",
"sleepModeHPRegAdd",
"sleepModeMagicRegAdd",
"sleepModeDamageMultiply",
"exitTrapPercent",
"exitTrapDamageMaxPercent",
"scriptParams",
"$childProtectHitExplosionID",
"$childConversionExplosionID",
"maxHarvestedMoney",
"ticksPerHarvestResource",
"putResourceAngle",
"moneyPerExperiencePoint",
"$ShitFlyingWasteID" };

std::vector<std::string> cannon = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"secondMeshName",
"slotNum",
"plugType",
"equipmentValue",
"$equipmentArtefactID",
"dropButtonNum",
"dropButtonPriority",
"turnToWindSpeed",
"equipmentSetNum",
"addEquipmentSetNum",
"smallIconItem",
"$updateBuildingID",
"minRangeOfFire",
"rangeOfFire",
"shootCloseTowerMinRange",
"shootCloseTowerRange",
"shootCloseTowerBeta",
"shootCloseMinRange",
"shootCloseRange",
"shootCloseBeta",
"shootFarMinRange",
"shootFarRange",
"shootFarBeta",
"alphaMargin",
"shooterSwordAlphaMargin",
"betaMargin",
"cannonAnimType",
"$ammoID",
"$shooterSwordAmmoID",
"ammoType",
"targetType",
"shootDelay",
"shootMagicCost",
"$barrelExplosionID",
"barrelExplosionOnSlot",
"addCannonExtraDamageRandPercent" };

std::vector<std::string> missile = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"type",
"speed",
"timeOfShoot",
"hitType",
"hitRange",
"damage1",
"damage2",
"damage3",
"poissonHP",
"poissonHPTime",
"$poissonEffectID",
"$explosionID",
"notDamageAllies" };

std::vector<std::string> specialequipment = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"secondMeshName",
"slotNum",
"plugType",
"equipmentValue",
"$equipmentArtefactID",
"dropButtonNum",
"dropButtonPriority",
"turnToWindSpeed",
"equipmentSetNum",
"addEquipmentSetNum",
"smallIconItem",
"$updateBuildingID",
"equipmentFlags",
"addHPRegeneration",
"addArmour1",
"addArmour2",
"addArmour3",
"addMagicRegeneration",
"addMaxMagicPercent",
"addMaxMagicVal",
"addMaxHP",
"addExtraDamage0",
"addExtraDamage1",
"addExtraDamage2",
"addExtraDamageRandPercent" };

std::vector<std::string> magicequipment = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"secondMeshName",
"slotNum",
"plugType",
"equipmentValue",
"$equipmentArtefactID",
"dropButtonNum",
"dropButtonPriority",
"turnToWindSpeed",
"equipmentSetNum",
"addEquipmentSetNum",
"smallIconItem",
"$updateBuildingID",
"magicType",
"rpgPointsCost",
"magicAnimType",
"magicCost",
"magicRange",
"magicExecuteRange",
"magicExecuteTime",
"$magicExplosionID",
"magicExplosionPos",
"$targetExplosionID",
"targetExplosionPos",
"$targetEffectID",
"targetEffectExplosionPos",
"$targetEndEffectID",
"$immortalShieldID",
"magicCaptureMask",
"magicCapturePercent",
"stormPower",
"$spyID",
"$magicConversionUnitID",
"magicConversionMask",
"magicConversionPercent",
"fireRainPower",
"$ghostID",
"$wildAnimalID",
"magicRangeMesh",
"getHPValue",
"$magicTrapID",
"aroundDamage0",
"aroundDamage1",
"aroundDamage2",
"$fireWallSmokeID",
"fireWallLength",
"magicMirrorExperiencePercent",
"healingHP",
"timedLifeMagicUnitMaxCount",
"magicUpdateMinExperienceLevel" };

std::vector<std::string> equipmentartefact = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"passiveMask",
"$wallCopulaID",
"bridgeHeight",
"bridgeBordersMask",
"$passiveChimneySmokeID",
"$passiveNightSmokeID",
"daySoundTimeSec",
"daySoundDelaySec",
"nightSoundTimeSec",
"nightSoundDelaySec",
"passiveSpeed",
"passiveRange",
"$passiveAnimParamsID",
"artefactMask",
"artefactInventorySize",
"artefactRPGCost",
"artefactRPGCostCategory",
"minExperienceLevel",
"minMagic",
"minDamage0",
"minDamage1",
"minDamage2",
"useButtonNum",
"useButtonPriority",
"$useExplosionID",
"artefactParam",
"respawnTime",
"addDamage1",
"addDamage2",
"addDamage3",
"$equipmentID" };

std::vector<std::string> artefact = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"passiveMask",
"$wallCopulaID",
"bridgeHeight",
"bridgeBordersMask",
"$passiveChimneySmokeID",
"$passiveNightSmokeID",
"daySoundTimeSec",
"daySoundDelaySec",
"nightSoundTimeSec",
"nightSoundDelaySec",
"passiveSpeed",
"passiveRange",
"$passiveAnimParamsID",
"artefactMask",
"artefactInventorySize",
"artefactRPGCost",
"artefactRPGCostCategory",
"minExperienceLevel",
"minMagic",
"minDamage0",
"minDamage1",
"minDamage2",
"useButtonNum",
"useButtonPriority",
"$useExplosionID",
"artefactParam",
"respawnTime",
"addDamage1",
"addDamage2",
"addDamage3" };

std::vector<std::string> lookroundequipment = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"secondMeshName",
"slotNum",
"plugType",
"equipmentValue",
"$equipmentArtefactID",
"dropButtonNum",
"dropButtonPriority",
"turnToWindSpeed",
"equipmentSetNum",
"addEquipmentSetNum",
"smallIconItem",
"$updateBuildingID",
"lookRoundTypeMask",
"lookRoundRange",
"turnSpeed",
"damageIncreasePercent",
"speedUpHPRegenerationAdd",
"speedUpMagicRegerationAdd",
"harvestSpeedIncrease",
"buildSpeedIncrease",
"armour0Increase",
"armour1Increase",
"armour2Increase",
"$lookRoundEffectID",
"showEffectForAllPlayers" };

std::vector<std::string> lookroundequipmenteffect = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"secondMeshName",
"slotNum",
"plugType",
"equipmentValue",
"$equipmentArtefactID",
"dropButtonNum",
"dropButtonPriority",
"turnToWindSpeed",
"equipmentSetNum",
"addEquipmentSetNum",
"smallIconItem",
"$updateBuildingID" };

std::vector<std::string> equipment = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"secondMeshName",
"slotNum",
"plugType",
"equipmentValue",
"$equipmentArtefactID",
"dropButtonNum",
"dropButtonPriority",
"turnToWindSpeed",
"equipmentSetNum",
"addEquipmentSetNum",
"smallIconItem",
"$updateBuildingID" };

std::vector<std::string> building = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"buildingType",
"buildingTypeEx",
"buildBuildingFlags",
"$requiredBuilding",
"$copulaID",
"productionNumber",
"maxUnitsInBuilding",
"buildingConnectFlags",
"$chimneySmokeID",
"$nightSmokeID",
"$buildExplosionID",
"$connectWallID",
"$bridgeGateID",
"extraTowerArmour1",
"extraTowerArmour2",
"extraTowerArmour3",
"assemblyPointMesh",
"harvestLoopsCnt",
"harvestStartBeg",
"harvestStartEnd",
"harvestLoopBeg",
"harvestLoopEnd",
"harvestEndBeg",
"harvestEndEnd" };

std::vector<std::string> passive = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"passiveMask",
"$buildCopulaID",
"bridgeHeight",
"bridgeBordersMask",
"$passiveChimneySmokeID",
"$passiveNightSmokeID",
"daySoundTimeSec",
"daySoundDelaySec",
"nightSoundTimeSec",
"nightSoundDelaySec",
"passiveSpeed",
"passiveRange",
"$passiveAnimParamsID" };

std::vector<std::string> specialpassive = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"passiveMask",
"$wallCopulaID",
"bridgeHeight",
"bridgeBordersMask",
"$passiveChimneySmokeID",
"$passiveNightSmokeID",
"daySoundTimeSec",
"daySoundDelaySec",
"nightSoundTimeSec",
"nightSoundDelaySec",
"passiveSpeed",
"passiveRange",
"$passiveAnimParamsID",
"entranceTunnelNumber",
"$entranceExplosionID",
"entranceExplosionPos",
"hpRegenerationAdd",
"magicRegenerationAdd",
"$conversionUnitID",
"conversionMask",
"conversionTime",
"conversionRequiredHPPercent" };

std::vector<std::string> trap = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"passiveMask",
"$wallCopulaID",
"bridgeHeight",
"bridgeBordersMask",
"$passiveChimneySmokeID",
"$passiveNightSmokeID",
"daySoundTimeSec",
"daySoundDelaySec",
"nightSoundTimeSec",
"nightSoundDelaySec",
"passiveSpeed",
"passiveRange",
"$passiveAnimParamsID",
"trapType",
"trapInventorySize",
"trapRPGCost",
"trapRPGCostCategory",
"holdTime",
"trapDamage0",
"trapDamage1",
"trapDamage2",
"trapDamageRange",
"trapPoissonHP",
"trapPoissonHPTime",
"$trapPoissonEffectID",
"beginTrapAnimBeg",
"beginTrapAnimEnd",
"endTrapAnimBeg",
"endTrapAnimEnd",
"$trapExplosionID",
"trapExistTime",
"holdExtraDamagePercent" };

std::vector<std::string> verticalvehiclespy = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"vehicleSpeed",
"verticalVehicleAnimationType",
"flightLevel" };

std::vector<std::string> verticalvehiclebomber = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"vehicleSpeed",
"verticalVehicleAnimationType",
"bombsCnt",
"createDistanceFromTarget" };

std::vector<std::string> explosion = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"explosionTicks",
"explosionFlags",
"explosionSoundDelay" };

std::vector<std::string> multiexplosion = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"useDownBuilding",
"downBuildingStart",
"downBuildingTime",
"$subObject1",
"time1",
"angle1",
"dist4X1",
"$subObject2",
"time2",
"angle2",
"dist4X2",
"$subObject3",
"time3",
"angle3",
"dist4X3",
"$subObject4",
"time4",
"angle4",
"dist4X4",
"$subObject5",
"time5",
"angle5",
"dist4X5",
"$subObject6",
"time6",
"angle6",
"dist4X6",
"$subObject7",
"time7",
"angle7",
"dist4X7",
"$subObject8",
"time8",
"angle8",
"dist4X8" };

std::vector<std::string> smoke = {
"classID",
"mesh",
"lowResmesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"mainSmokeTicks",
"mesh1",
"mesh2",
"mesh3",
"smokeTime1",
"smokeTime2",
"smokeTime3",
"smokeFrequency",
"startingTime",
"smokingTime",
"endingTime",
"smokeUpSpeed",
"newSmokeDistance" };

std::vector<std::string> smokefire = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"standType",
"mapSign",
"mainSmokeTicks",
"mesh1",
"mesh2",
"mesh3",
"smokeTime1",
"smokeTime2",
"smokeTime3",
"smokeFrequency",
"startingTime",
"smokingTime",
"endingTime",
"smokeUpSpeed",
"newSmokeDistance",
"smokeDamage1",
"smokeDamage2",
"smokeDamage3",
"smokeDamageTicks",
"smokeTime" };

std::vector<std::string> startingpositionmark = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"positionType" };

std::vector<std::string> aiplatoon = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12" };

std::vector<std::string> flyingwaste = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"wasteSize",
"$subWasteID1",
"subWaste1Alpha",
"$subWasteID2",
"subWaste2Alpha",
"$subWasteID3",
"subWaste3Alpha",
"$subWasteID4",
"subWaste4Alpha",
"flightTime",
"wasteSpeed",
"wasteDistanceX4",
"wasteBeta" };

std::vector<std::string> talkpacks = {
"talkPack1",
"talkPack2",
"talkPack3",
"talkPack4",
"talkPack5",
"talkPack6",
"talkPack7",
"talkPack8",
"talkPack9",
"talkPack10",
"talkPack11",
"talkPack12",
"talkPack13",
"talkPack14",
"talkPack15",
"talkPack16",
"talkPack17",
"talkPack18",
"talkPack19",
"talkPack20",
"talkPack21",
"talkPack22",
"talkPack23",
"talkPack24",
"talkPack25",
"talkPack26",
"talkPack27",
"talkPack28",
"talkPack29",
"talkPack30" };

std::vector<std::string> animparams = {
"speedFactAccelerate",
"speedFactorMove",
"speedFactorBreak",
"speedFactorTurn45",
"speedFactorTurn90",
"speedFactorTurn135",
"speedFactorTurn180",
"trajcFactor1",
"trajcFactor2",
"trajcFactor3",
"trajcFactor4",
"trajcFactor5",
"trajcFactor6",
"trajcFactor7",
"trajcFactor8",
"trajcFactor9",
"trajcFactor10",
"trajcFactor11",
"trajcFactor12",
"stay1Beg",
"stay1End",
"stay2Beg",
"stay2End",
"stay3Beg",
"stay3End",
"stay4Beg",
"stay4End",
"stayCamouflagedBeg",
"stayCamouflagedEnd",
"accelerateBeg",
"accelerateEnd",
"moveBeg",
"moveEnd",
"breakBeg",
"breakEnd",
"runBeg",
"runEnd",
"turnR45Beg",
"turnR45End",
"turnR90Beg",
"turnR90End",
"turnR135Beg",
"turnR135End",
"turnR180Beg",
"turnR180End",
"turnL45Beg",
"turnL45End",
"turnL90Beg",
"turnL90End",
"turnL135Beg",
"turnL135End",
"accelerateCamouflagedBeg",
"accelerateCamouflagedEnd",
"moveCamouflagedBeg",
"moveCamouflagedEnd",
"breakCamouflagedBeg",
"breakCamouflagedEnd",
"turnCamouflagedR45Beg",
"turnCamouflagedR45End",
"turnCamouflagedR90Beg",
"turnCamouflagedR90End",
"turnCamouflagedR135Beg",
"turnCamouflagedR135End",
"turnCamouflagedR180Beg",
"turnCamouflagedR180End",
"turnCamouflagedL45Beg",
"turnCamouflagedL45End",
"turnCamouflagedL90Beg",
"turnCamouflagedL90End",
"turnCamouflagedL135Beg",
"turnCamouflagedL135End",
"moveClimbBeg",
"moveClimbEnd",
"moveFlyingStartBeg",
"moveFlyingStartEnd",
"moveFlyingBeg",
"moveFlyingEnd",
"moveFlyingStopBeg",
"moveFlyingStopEnd",
"landToFlyBeg",
"landToFlyEnd",
"flyToLandBeg",
"flyToLandEnd",
"animStartCamouflageBeg",
"animStartCamouflageEnd",
"animEndCamouflageBeg",
"animEndCamouflageEnd",
"animStartSleepBeg",
"animStartSleepEnd",
"animSleepBeg",
"animSleepEnd",
"animEndSleepBeg",
"animEndSleepEnd",
"animEnemyAlertBeg",
"animEnemyAlertEnd",
"animStartWorkBeg",
"animStartWorkEnd",
"animWork1Beg",
"animWork1End",
"animWork2Beg",
"animWork2End",
"animEndWorkBeg",
"animEndWorkEnd",
"animShitBeg",
"animShitEnd",
"animStartFightBeg",
"animStartFightEnd",
"animFightHit1Beg",
"animFightHit1End",
"animFightHit2Beg",
"animFightHit2End",
"animFightHit3Beg",
"animFightHit3End",
"animFightHit4Beg",
"animFightHit4End",
"animEndFightBeg",
"animEndFightEnd",
"animStartFight2Beg",
"animStartFight2End",
"animFight2Hit1Beg",
"animFight2Hit1End",
"animFight2Hit2Beg",
"animFight2Hit2End",
"animFight2Hit3Beg",
"animFight2Hit3End",
"animFight2Hit4Beg",
"animFight2Hit4End",
"animEndFight2Beg",
"animEndFight2End",
"animStartRunFightBeg",
"animStartRunFightEnd",
"animRunFightHitBeg",
"animRunFightHitEnd",
"animEndRunFightBeg",
"animEndRunFightEnd",
"animStartShootBeg",
"animStartShootEnd",
"animShootFar1Beg",
"animShootFar1End",
"animShootFar2Beg",
"animShootFar2End",
"animShootClose1Beg",
"animShootClose1End",
"animShootClose2Beg",
"animShootClose2End",
"animShootCloseTowerBeg",
"animShootCloseTowerEnd",
"animEndShootBeg",
"animEndShootEnd",
"animMagic1Beg",
"animMagic1End",
"animMagic2Beg",
"animMagic2End",
"animMagic3Beg",
"animMagic3End",
"animMagic4Beg",
"animMagic4End",
"animDead1Beg",
"animDead1End",
"animDead2Beg",
"animDead2End",
"animDead3Beg",
"animDead3End",
"animDead4Beg",
"animDead4End",
"animDeadSleepBeg",
"animDeadSleepEnd",
"animCustom1Beg",
"animCustom1End",
"animCustom2Beg",
"animCustom2End",
"animCustom3Beg",
"animCustom3End",
"animCustom4Beg",
"animCustom4End",
"animPutHoldTrapBeg",
"animPutHoldTrapEnd",
"animGetHoldTrapBeg",
"animGetHoldTrapEnd",
"animWork1Fire",
"animWork2Fire",
"shitFire",
"animFightHit1Fire",
"animFightHit2Fire",
"animFightHit3Fire",
"animFightHit4Fire",
"animFight2Hit1Fire",
"animFight2Hit2Fire",
"animFight2Hit3Fire",
"animFight2Hit4Fire",
"animRunFightHitFire",
"animShootFar1Fire",
"animShootFar2Fire",
"animShootClose1Fire",
"animShootClose2Fire",
"animShootCloseTowerFire",
"animMagic1Fire",
"animMagic2Fire",
"animMagic3Fire",
"animMagic4Fire",
"animDead1Frame",
"animDead2Frame",
"animDead3Frame",
"animDead4Frame",
"animDeadSleepFrame",
"animPutHoldTrapFrame",
"animGetHoldTrapFrame" };

std::vector<std::string> soundpack = {
"normalWavePack1",
"normalWavePack2",
"normalWavePack3",
"normalWavePack4",
"loopedWavePack1",
"loopedWavePack2",
"loopedWavePack3",
"loopedWavePack4" };

std::vector<std::string> passiveanimparams = {
"anim1Beg",
"anim1End",
"anim2Beg",
"anim2End",
"anim3Beg",
"anim3End",
"anim4Beg",
"anim4End",
"anim5Beg",
"anim5End" };

std::vector<std::string> talkpackdelays = {
"talkPackDelay1",
"talkPack1MapSign",
"talkPack1MapSignTime",
"talkPackDelay2",
"talkPack2MapSign",
"talkPack2MapSignTime",
"talkPackDelay3",
"talkPack3MapSign",
"talkPack3MapSignTime",
"talkPackDelay4",
"talkPack4MapSign",
"talkPack4MapSignTime",
"talkPackDelay5",
"talkPack5MapSign",
"talkPack5MapSignTime",
"talkPackDelay6",
"talkPack6MapSign",
"talkPack6MapSignTime",
"talkPackDelay7",
"talkPack7MapSign",
"talkPack7MapSignTime",
"talkPackDelay8",
"talkPack8MapSign",
"talkPack8MapSignTime",
"talkPackDelay9",
"talkPack9MapSign",
"talkPack9MapSignTime",
"talkPackDelay10",
"talkPack10MapSign",
"talkPack10MapSignTime",
"talkPackDelay11",
"talkPack11MapSign",
"talkPack11MapSignTime",
"talkPackDelay12",
"talkPack12MapSign",
"talkPack12MapSignTime",
"talkPackDelay13",
"talkPack13MapSign",
"talkPack13MapSignTime",
"talkPackDelay14",
"talkPack14MapSign",
"talkPack14MapSignTime",
"talkPackDelay15",
"talkPack15MapSign",
"talkPack15MapSignTime",
"talkPackDelay16",
"talkPack16MapSign",
"talkPack16MapSignTime",
"talkPackDelay17",
"talkPack17MapSign",
"talkPack17MapSignTime",
"talkPackDelay18",
"talkPack18MapSign",
"talkPack18MapSignTime",
"talkPackDelay19",
"talkPack19MapSign",
"talkPack19MapSignTime",
"talkPackDelay20",
"talkPack20MapSign",
"talkPack20MapSignTime",
"talkPackDelay21",
"talkPack21MapSign",
"talkPack21MapSignTime",
"talkPackDelay22",
"talkPack22MapSign",
"talkPack22MapSignTime",
"talkPackDelay23",
"talkPack23MapSign",
"talkPack23MapSignTime",
"talkPackDelay24",
"talkPack24MapSign",
"talkPack24MapSignTime",
"talkPackDelay25",
"talkPack25MapSign",
"talkPack25MapSignTime",
"talkPackDelay26",
"talkPack26MapSign",
"talkPack26MapSignTime",
"talkPackDelay27",
"talkPack27MapSign",
"talkPack27MapSignTime",
"talkPackDelay28",
"talkPack28MapSign",
"talkPack28MapSignTime",
"talkPackDelay29",
"talkPack29MapSign",
"talkPack29MapSignTime",
"talkPackDelay30",
"talkPack30MapSign",
"talkPack30MapSignTime" };

std::vector<std::string> playertalkpack = {
"talkPack1",
"talkPack2",
"talkPack3",
"talkPack4",
"talkPack5",
"talkPack6",
"talkPack7",
"talkPack8",
"talkPack9",
"talkPack10",
"talkPack11",
"talkPack12",
"talkPack13",
"talkPack14" };

std::vector<std::string> playertalkpackdelays = {
"talkPackDelay1",
"talkPackMapSign1",
"talkPackMapSignTime1",
"talkPackDelay2",
"talkPackMapSign2",
"talkPackMapSignTime2",
"talkPackDelay3",
"talkPackMapSign3",
"talkPackMapSignTime3",
"talkPackDelay4",
"talkPackMapSign4",
"talkPackMapSignTime4",
"talkPackDelay5",
"talkPackMapSign5",
"talkPackMapSignTime5",
"talkPackDelay6",
"talkPackMapSign6",
"talkPackMapSignTime6",
"talkPackDelay7",
"talkPackMapSign7",
"talkPackMapSignTime7",
"talkPackDelay8",
"talkPackMapSign8",
"talkPackMapSignTime8",
"talkPackDelay9",
"talkPackMapSign9",
"talkPackMapSignTime9",
"talkPackDelay10",
"talkPackMapSign10",
"talkPackMapSignTime10",
"talkPackDelay11",
"talkPackMapSign11",
"talkPackMapSignTime11",
"talkPackDelay12",
"talkPackMapSign12",
"talkPackMapSignTime12",
"talkPackDelay13",
"talkPackMapSign13",
"talkPackMapSignTime13",
"talkPackDelay14",
"talkPackMapSign14",
"talkPackMapSignTime14" };

std::vector<std::string> musicpack = {
"mainMusic",
"statisticVictoryMusic",
"statisticDefeatMusic",
"dayMusic1",
"dayMusic2",
"dayMusic3",
"dayMusic4",
"dayMusic5",
"dayMusic6",
"dayMusic7",
"dayMusic8",
"nightMusic1",
"nightMusic2",
"nightMusic3",
"nightMusic4",
"nightMusic5",
"nightMusic6",
"nightMusic7",
"nightMusic8",
"warMusic1",
"warMusic2",
"warMusic3",
"warMusic4",
"warMusic5",
"warMusic6",
"warMusic7",
"warMusic8" };

std::vector<std::string> experienceparams = {
"levelPoints",
"harvesterLevelPoints",
"convertLevelPoints",
"speedAdd",
"maxHPAdd",
"maxMagicAdd",
"damageAdd",
"shootDelayAdd",
"sightRangeAdd",
"shootRangeAdd",
"maxHarvesterMoneyAdd",
"convertPercentAdd" };

std::vector<std::string> meshbuttonviewparams = {
"posX",
"posY",
"posZ",
"posAlpha",
"posBeta" };

std::vector<std::string> selectionmeshes = {
"road",
"roadOnBridge",
"roadBad",
"roadBadOnBridge",
"bridgeBeg",
"bridgeBegOnBridge",
"buildEntrance",
"buildEntranceOnBridge",
"commandMove",
"commandMoveOnBridge",
"commandMoveHoldPos",
"commandMoveHoldPosOnBridge",
"commandEnter",
"commandEnterOnBridge",
"commandAttack",
"commandAttackOnBridge",
"commandAttack1x1",
"commandAttack3x3",
"commandAttack4x1",
"commandOther",
"commandOtherOnBridge",
"commandOther1x1",
"commandOther3x3",
"commandOther4x1" };

std::vector<std::string> specialupdateslinks = {
"$specialUpdateLink",
};

std::vector<std::string> racedata = {
"raceIdentifier",
"raceFlags",
"buildFlags",
"$wallID",
"$narrowBridgeID",
"$wideBridgeID",
"$singleBridgeID",
"$roadID",
"roadCost",
"$platoonID",
"wallTemplateNum",
"wallPanelPos",
"narrowBridgeTemplateNum",
"narrowBridgePanelPos",
"wideBridgeTemplateNum",
"wideBridgeTemplatePos",
"singleBridgeTemplateNum",
"singleBridgePanelPos",
"roadTemplateNum",
"roadPanelPos",
"$unitTalkPackDelaysID",
"$buildingTalkPackDelaysID",
"$playerTalkPackID",
"$playerTalkPackDelaysID",
"$musicPackID",
"interfaceFlags",
"defBannerName",
"defStatsBannerName",
"defaultInterface",
"$selectionMeshes" };

std::vector<std::string> rpgparams = {
"pointsCost",
"value1",
"value2",
"value3" };

std::vector<std::string> rpgexperience = {
"experiencePoints",
"addRPGPoints",
"addHireCost",
"addHPLevel",
"addDamageLevel" };

std::vector<std::string> verticalvehicle = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12",
"vehicleSpeed",
"verticalVehicleAnimationType" };

std::vector<std::string> scriptedactive = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12" };

std::vector<std::string> active = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"hpRegenerationTicks",
"armour1",
"armour2",
"armour3",
"storeableFlags",
"standType",
"mapSign",
"sightRange",
"$talkPackID",
"capturePercent",
"capturePercentMul",
"allowCaptureMask",
"conversionPercentMul",
"allowConversionMask",
"maxMagic",
"magicRegenerationTicks",
"initMagicPercent",
"killExperiencePoints",
"unitDamage1",
"unitDamage2",
"unitDamage3",
"slotType1",
"slotType2",
"slotType3",
"slotType4",
"slotType5",
"slotType6",
"slotType7",
"slotType8",
"$subObjectID1",
"$subObjectID2",
"$subObjectID3",
"$subObjectID4",
"$subObjectID5",
"$subObjectID6",
"$subObjectID7",
"$subObjectID8",
"$subObjectID9",
"$subObjectID10",
"$subObjectID11",
"$subObjectID12" };

std::vector<std::string> generic = {
"classID",
"mesh",
"lowResMesh",
"lowRes2Mesh",
"interfaceMesh",
"shadowType",
"forceMeshHeight",
"viewParamsIndex",
"panelTemplateNum",
"selectedTemplateNum",
"listTemplateNum",
"groupTemplateNum",
"panelPos",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID" };

std::vector<std::string> mine = {
"classID",
"mesh",
"shadowType",
"viewParamsIndex",
"cost",
"timeOfBuild",
"$soundPackID",
"$smokeID",
"$killExplosionID",
"$destructedID",
"hp",
"regenerationHP",
"armour",
"calorificCapacity",
"disableResist",
"storeableFlags",
"standType",
"mineSize",
"mineTypeOfDamage",
"mineDamage" };



void ParDecompilerOverlay::SelectLabelsForClassId()
{
    uint32_t help_mask = 0x00FFFFFF;

    uint32_t help_classid = m_classid & help_mask;

    if (help_classid == help_mask)
    {
        switch (m_classid)
        {
        case 0x01FFFFFF:
            PrintLabels(talkpacks);
            break;

        case 0x02FFFFFF:
            PrintLabels(animparams);
            break;

        case 0x03FFFFFF:
            PrintLabels(soundpack);
            break;

        case 0x04FFFFFF:
            PrintLabels(passiveanimparams);
            break;

        case 0x05FFFFFF:
            PrintLabels(talkpackdelays);
            break;

        case 0x06FFFFFF:
            PrintLabels(playertalkpack);
            break;

        case 0x07FFFFFF:
            PrintLabels(playertalkpackdelays);
            break;

        case 0x08FFFFFF:
            PrintLabels(musicpack);
            break;

        case 0x09FFFFFF:
            PrintLabels(experienceparams);
            break;

        case 0x0AFFFFFF:
            PrintLabels(meshbuttonviewparams);
            break;

        case 0x0BFFFFFF:
            PrintLabels(selectionmeshes);
            break;

        case 0x0CFFFFFF:
            PrintLabels(specialupdateslinks);
            break;

        case 0x0DFFFFFF:
            PrintLabels(racedata);
            break;

        case 0x0EFFFFFF:
            PrintLabels(rpgparams);
            break;

        case 0x0FFFFFFF:
            PrintLabels(rpgexperience);
            break;

        default:
            for (int i = 0; i < m_bits.length(); i++)
            {
                switch (m_bits[i])
                {
                case '0': myInputParUtil.WriteINT<uint32_t>(32, "var_field", 1, m_data); break;
                case '1': myInputParUtil.WriteSTRING("str_field", 1, m_data); break;
                default: break;
                }
            }
            break;

        }

        return;
    }

    if ((m_classid == ANIMATEDPASSIVE) || (m_classid == ANIMALPASSIVE) || (m_classid == BUILDPASSIVE) || (m_classid == GHOSTPASSIVE) ||
        (m_classid == TRANSIENTPASSIVE) || (m_classid == PASSIVE))
    {
        PrintLabels(passive);
        return;
    }

    if ((m_classid == SPECIALEQUIPMENT) || (m_classid == SPECIALEQUIPMENTEX))
    {
        PrintLabels(specialequipment);
        return;
    }

    
    if ((m_classid == STOREABLE) || (m_classid == DYNAMIC) || (m_classid == GENERIC) || (m_classid == VISIBLEFAKE))
    {
        PrintLabels(generic);
        return;
    }

    if ((m_classid == EXPLOSION) || (m_classid == EXPLOSIONEX))
    {
        PrintLabels(explosion);
        return;
    }


    switch (m_classid)
    {
    
    case MOVEABLE:
        PrintLabels(moveable);
        break;

    case SHOPUNIT:
        PrintLabels(shopunit);
        break;

    case RPGUNIT:
        PrintLabels(rpgunit);
        break;

    case BUILDER:
        PrintLabels(builder);
        break;

    case REPAIRER:
        PrintLabels(repairer);
        break;

    case HARVESTER:
        PrintLabels(harvester);
        break;

    case CANNON:
        PrintLabels(cannon);
        break;

    case MISSILE:
        PrintLabels(missile);
        break;

    
    case MAGICEQUIPMENT:
        PrintLabels(magicequipment);
        break;

    case EQUIPMENTARTEFACT:
        PrintLabels(equipmentartefact);
        break;

    case ARTEFACT:
        PrintLabels(artefact);
        break;

    case LOOKROUNDEQUIPMENT:
        PrintLabels(lookroundequipment);
        break;

    case LOOKROUNDEQUIPMENTEFFECT:
        PrintLabels(lookroundequipmenteffect);
        break;

    case EQUIPMENT:
        PrintLabels(equipment);
        break;


    case BUILDING:
        PrintLabels(building);
        break;

    //active
    case ACTIVE:
        PrintLabels(active);
    break;

    //mine
    case MINE:
        PrintLabels(mine);
    break;

    case SPECIALPASSIVE:
        PrintLabels(specialpassive);
        break;

    case TRAP:
        PrintLabels(trap);
        break;

    case SCRIPTEDACTIVE:
        PrintLabels(scriptedactive);
        break;

    case VERTICALVEHICLE:
        PrintLabels(verticalvehicle);
        break;

    case VERTICALVEHICLESPY:
        PrintLabels(verticalvehiclespy);
        break;

    case VERTICALVEHICLEBOMBER:
        PrintLabels(verticalvehiclebomber);
        break;


    case MULTIEXPLOSION:
        PrintLabels(multiexplosion);
    break;

    case SMOKE:
        PrintLabels(smoke);
    break;

    case SMOKEFIRE:
        PrintLabels(smokefire);
    break;

    case STARTINGPOSITIONMARK:
        PrintLabels(startingpositionmark);
    break;

    case AIPLATOON:
        PrintLabels(aiplatoon);
    break;

    case FLYINGWASTE:
        PrintLabels(flyingwaste);
    break;

    default:

        for (int i = 0; i < m_bits.length(); i++)
        {
            switch (m_bits[i])
            {
            case '0': myInputParUtil.WriteINT<uint32_t>(32, "var_field", 1, m_data); break;
            case '1': myInputParUtil.WriteSTRING("str_field", 1, m_data); break;
            default: break;
            }
        }

    break;

    }
    

}




/*
help_mask = 0x0000000F;

const int tetrad = 4;

if ((_classid & help_mask) == (GENERIC & help_mask))
{
    help_mask <<= tetrad;

    if ((_classid & help_mask) == (EQUIPMENT & help_mask))
    {
        help_mask <<= tetrad;

        if ((_classid & help_mask) == (SPECIALEQUIPMENT & help_mask))
        {
            help_mask <<= (2 * tetrad);

            if (_classid == SPECIALEQUIPMENTEX)
            {
                PrintLabels(specialequipment);
                return;
            }

            PrintLabels(specialequipment);
            return;
        }

        if (_classid == CANNON)
        {
            PrintLabels(cannon);
            return;
        }

        if (_classid == LOOKROUNDEQUIPMENT)
        {
            PrintLabels(lookroundequipment);
            return;
        }

        if (_classid == MAGICEQUIPMENT)
        {
            PrintLabels(magicequipment);
            return;
        }

        if (_classid == LOOKROUNDEQUIPMENTEFFECT)
        {
            PrintLabels(lookroundequipmenteffect);
            return;
        }


        PrintLabels(equipment);
        return;
    }

    if ((_classid & help_mask) == (STOREABLE & help_mask))
    {
        help_mask <<= tetrad;

        if ((_classid & help_mask) == (DYNAMIC & help_mask))
        {
            help_mask <<= (2 * tetrad);

            if ((_classid & help_mask) == (EXPLOSION & help_mask))
            {
                if (_classid == EXPLOSIONEX)
                {
                    PrintLabels(explosion);
                    return;
                }

                PrintLabels(explosion);
                return;
            }

            if ((_classid & help_mask) == (SMOKE & help_mask))
            {
                if (_classid == SMOKEFIRE)
                {
                    PrintLabels(smokefire);
                    return;
                }

                PrintLabels(smoke);
                return;
            }

            if (_classid == FLYINGWASTE)
            {
                PrintLabels(flyingwaste);
                return;
            }

            if (_classid == MISSILE)
            {
                PrintLabels(missile);
                return;
            }


            PrintLabels(generic);
            return;
        }

        if ((_classid & help_mask) == (ACTIVE & help_mask))
        {
            help_mask <<= 2 * tetrad;

            if ((_classid & help_mask) == (VERTICALVEHICLE & help_mask))
            {
                if ((_classid == VERTICALVEHICLEBOMBER))
                {
                    PrintLabels(verticalvehiclebomber);
                    return;
                }

                if ((_classid == VERTICALVEHICLESPY))
                {
                    PrintLabels(verticalvehiclespy);
                    return;
                }


                PrintLabels(verticalvehicle);
                return;
            }

            if ((_classid & help_mask) == (MOVEABLE & help_mask))
            {
                help_mask <<= tetrad;

                if ((_classid & help_mask) == (REPAIRER & help_mask))
                {
                    if ((_classid == BUILDER))
                    {
                        PrintLabels(builder);
                        return;
                    }

                    PrintLabels(repairer);
                    return;
                }

                if ((_classid == HARVESTER))
                {
                    PrintLabels(harvester);
                    return;
                }

                if ((_classid == RPGUNIT))
                {
                    PrintLabels(rpgunit);
                    return;
                }

                if ((_classid == SHOPUNIT))
                {
                    PrintLabels(shopunit);
                    return;
                }

                PrintLabels(moveable);
                return;
            }

            if ((_classid == STARTINGPOSITIONMARK))
            {
                PrintLabels(startingpositionmark);
                return;
            }

            if ((_classid == BUILDING))
            {
                PrintLabels(building);
                return;
            }

            if ((_classid == AIPLATOON))
            {
                PrintLabels(aiplatoon);
                return;
            }


            if ((_classid & help_mask) == (SCRIPTEDACTIVE & help_mask))
            {
                PrintLabels(scriptedactive);
                return;
            }


            PrintLabels(active);
            return;
        }


        if ((_classid & help_mask) == (PASSIVE & help_mask))
        {
            help_mask <<= tetrad;

            if ((_classid & help_mask) == (ANIMATEDPASSIVE & help_mask))
            {
                help_mask <<= tetrad;

                if ((_classid & help_mask) == (TRANSIENTPASSIVE & help_mask))
                {
                    if (_classid == ARTEFACT)
                    {
                        PrintLabels(artefact);
                        return;
                    }

                    if (_classid == TRAP)
                    {
                        PrintLabels(trap);
                        return;
                    }

                    if (_classid == EQUIPMENTARTEFACT)
                    {
                        PrintLabels(equipmentartefact);
                        return;
                    }


                    PrintLabels(passive);
                    return;
                }

                if (_classid == SPECIALPASSIVE)
                {
                    PrintLabels(specialpassive);
                    return;
                }

                if (_classid == GHOSTPASSIVE)
                {
                    PrintLabels(passive);
                    return;
                }

                if (_classid == ANIMALPASSIVE)
                {
                    PrintLabels(passive);
                    return;
                }

                PrintLabels(passive);
                return;
            }


            if (_classid == BUILDPASSIVE)
            {
                PrintLabels(passive);
                return;
            }


            PrintLabels(passive);
            return;
        }


        if (_classid == MINE )
        {
            PrintLabels(mine);
            return;
        }

        if ((_classid == VISIBLEFAKE))
        {
            PrintLabels(generic);
            return;
        }

        PrintLabels(generic);
        return;
    }


    PrintLabels(generic);
    return;
}


for (int i = 0; i < _bits.length(); i++)
{
    switch (_bits[i])
    {
    case '0': myInputParUtil.WriteUINT<uint32_t>(32, "var_field", 1, _data); break;
    case '1': myInputParUtil.WriteSTRING("str_field", 1, _data); break;
    default: break;
    }
}

*/