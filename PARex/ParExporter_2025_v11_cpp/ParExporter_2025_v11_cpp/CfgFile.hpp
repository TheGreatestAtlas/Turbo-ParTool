#ifndef CFG_FILE_H
#define CFG_FILE_H

#include "ConfigSwitches.hpp"
#include <unordered_map>
#include "CfgFileUtils.hpp"
#include "TextFile.hpp"

class CfgFile
{
public:
	CfgFile(std::filesystem::path& input_path);
	~CfgFile();

	ConfigSwitches GetConfigSwitches() const;

private:
	void GetInfoFromCfg(const std::vector<char>& arg_clean_file);
	void GetValuesFromString(std::string& arg_instruction, std::string& arg_ins_value_type, std::string& arg_ins_value);
	void InitializeSwitches(std::string& value_type, std::string& value);
	
	void PrintSwitchInfo(std::string& value_type, bool& value);

	void InitializeHashMap();

	ConfigSwitches m_config_switches = {};

	std::unordered_map<std::string, bool> m_config_values_hash_map = {};
	std::unordered_map<std::string, CfgFileUtils::en_cfg_value_types> m_config_en_value_types_hash_map = {};
};

#endif // !CFG_FILE_H
