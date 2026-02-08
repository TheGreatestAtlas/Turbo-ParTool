#ifndef OBJECT_H
#define OBJECT_H

#include "BinFile.hpp"
#include "CppFile.hpp"
#include "ConfigSwitches.hpp"
#include "HashMaps.hpp"

class Object
{
public:
	Object(ConfigSwitches& config_switches, HashMaps& hash_maps);
	~Object();

	void ReadFrom(BinFile& bin_file);

	inline void SaveToTextFile(std::filesystem::path& arg_output_file_path)
	{
		this->m_cpp_file.SaveToTextFile(arg_output_file_path);
	}

	inline void WriteToCppFileStream(CppFile& arg_cpp_file)
	{
		arg_cpp_file << this->m_cpp_file.str();
	}

	std::string GetObjectName() const;

private:
	void CheckClassIdAndCorrect(BinFile& bin_file);
	void SelectAndPrintLabelsForClassId(BinFile& bin_file);

	bool CheckIfClassIdIsADefinedMask() const;

	void PrintLabels(BinFile& bin_file, std::vector<std::string>& labels);

	void CheckIfItIsAMaskLabel(BinFile& bin_file, std::string& label);

	void CheckMaskLabelsAndCorrect(std::vector<std::string>& mask_labels);

	ConfigSwitches& m_config_switches;
	HashMaps& m_hash_maps;

	uint32_t m_classid;
	CppFile m_cpp_file;

	std::string m_obj_name;
	std::string m_logic_table_bits;

};


#endif // !OBJECT_H