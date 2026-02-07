#include <fstream>
#include <string>
#include <ctime>
#include <filesystem>
#include <unordered_map>
#include <set>

#ifdef _DEBUG
#define DEBUG_PRINT(x) printf_s("%s",x)
#else
#define DEBUG_PRINT(x)
#endif

const char par_header_file_name[] = "par_header";
const char end_of_par_file_name[] = "end_of_par"; 
const char section_order_file_name[] = "section_order";

constexpr void WriteQuad(char symbol, std::stringstream& output, int count)
{
	for (int i = 0; i < count; ++i)
		output << symbol;

}

//---------------------
// InputBinFile CLASS
//---------------------

class InputBinFile
{
public:
	//pola:
	uint8_t* m_file_buffer;

	//metody:
	void Informations(std::ostream& o) const;
	void ExitWhenFileDontExist(std::ostream& o) const;

	InputBinFile(char* argfilename);
	~InputBinFile();

	//Gettery:
	bool GetIsOpened() const;
	bool GetIsOpenNow() const;
	uint64_t GetFileLength() const;

private:

	//pola:
	std::fstream m_input_file;
	char* m_file_name;
	uint64_t m_file_length;
	bool m_is_opened;
	bool m_is_open_now;

	//metody:
	void OpenFile();
	void MeasureFile();
	void PutFileToBuffer();


};


//---------------------
// MapBinaryUtils CLASS
//---------------------

class BinaryUtils
{

public:
	//Pola:
	uint64_t m_current_offset;

	//Metody:
	BinaryUtils(uint8_t* argfilebuffer = nullptr, uint64_t argfilelength = 0);

	std::string GetString(void);

	template<typename T>
	T GetVALUE(void);

	std::string GetGUID(void);

	void WriteTIME32(std::string name, int quadcount, std::stringstream& output);

	void WriteSTRING(std::string name, int quadcount, std::stringstream& output);

	void Write1BITMASK(std::string& name, int quadcount, const uint8_t& value, std::stringstream& output);

	void WriteAll1BITMASKS(std::vector<std::string>& mask_labels, int quadcount, std::string main_label,
		std::stringstream& output, int size = sizeof(uint32_t));

	template<typename T>
	void WriteNBitMask(uint8_t nbits, std::string name, std::string main_label, std::unordered_map<uint32_t, std::string>& list_of_masks,
		int quadcount, std::stringstream& output);

	template<typename T>
	void WriteUNIQUEKEYwithCONST(uint32_t mode, std::string name, std::unordered_map<T, std::string>& list_of_masks,
		int quadcount, std::stringstream& output, int count = 1);

	template<typename T>
	void WriteINT(uint32_t mode, std::string name, int quadcount, std::stringstream& output, int count = 1, char signed_or_unsigned = 'u');


	void WriteGUID(std::string name, int quadcount, std::stringstream& output);

	std::string GetLOGICTABLE(void);

private:
	//Pola:
	uint64_t m_file_length;
	uint8_t* m_file_buffer;

};

//--------------------------------
// ParDecompilerOverlay CLASS
//--------------------------------

class ParDecompilerOverlay
{
public:
	ParDecompilerOverlay(std::istream& argin, std::ostream& argo, int my_argc, char* my_argv[]);

private:
	//Pola:
	//cfg:
	bool m_its_comment;
	bool m_its_string;
	std::vector <uint8_t> m_cfg_clean_file = {};

	std::string m_instruction;
	std::string m_value_type;
	std::string m_value;

	bool moveableFlags_switch;
	bool plugType_switch;
	bool slotType_switch;
	bool storeableFlags_switch;
	bool RPGUnitFlags_switch;
	bool artefactMask_switch;
	bool repairerFlags_switch;
	bool bridgeBordersMask_switch;
	bool shadowType_switch;
	bool targetType_switch;
	bool lookRoundTypeMask_switch;
	bool passiveMask_switch;
	bool buildBuildingFlags_switch;
	bool panelPos_switch;

	//-----------------------------------------

	std::stringstream m_data;
	std::stringstream m_editor_names_stream;

	std::istream& m_in_stream;
	std::ostream& m_o;

	std::fstream m_section_order_file; //orderfile
	std::string m_section_order_file_path;

	std::fstream m_end_of_par_file; //endfile
	std::string m_end_of_par_file_path;

	std::fstream m_par_header_file; //par_header_file
	std::string m_par_header_file_path;

	std::fstream m_single_section_file; //plik sekcji
	std::string m_single_section_file_name; //nazwa pliku sekcji
	
	std::fstream m_editor_names_file; //plik z nazwami do edytora

	std::string m_export_directory_name;

	std::string m_input_par_file_name; //nazwa par

	BinaryUtils myInputParUtil;

	uint64_t m_number_of_sections; // zmienna od ilosci sekcji w par
	uint32_t m_number_of_objects;

	uint32_t m_classid;

	std::unordered_map<uint32_t, std::string> m_list_of_passive_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_magicAnimType_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_magicType_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_explosionFlags_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_trapType_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_missileType_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_objectType_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_buildingType_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_wasteSize_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_groupTemplateNum_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_positionType_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_raceFlags_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_standType_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_hitType_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_experienceExplosionPos_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_equipmentFlags_masks = {};
	std::unordered_map<uint32_t, std::string> m_list_of_race_masks = {};

	//--- stringi na dane -----
	std::string m_help_str; //string na typowy string
	std::string m_bits;           //string przeznaczony na maske struktury obiektu
	
	std::string m_section_name;

	uint32_t m_single_value;


	//Metody:

	void WriteEndFile();
	void WriteRaceDataFile();
	void WriteSingleObject();
	void WriteSectionHeader(uint32_t& section_index);
	void WriteSingleSectionFile(uint32_t &h);
	void WriteAllParSections();

	void SelectLabelsForClassId();
	void PrintLabels(std::vector<std::string>& labels);
	void CheckClassIdAndCorrect();

	void CheckIfItIsAMaskLabel(std::string& label);

	void CheckMaskLabelsAndCorrect(std::vector<std::string>& masklabels);

	bool CheckIfClassIdIsADefinedMask() const;

	void DecompilePar();

	void ShowIntroScreen();
	void StandardProgramLaunch();

	void InitializeHashMaps();


	void GetCfgFile();
	void GetInfoFromCfg();
	void GetValuesFromString();
	void InitializeSwitches(std::string& valuetype, std::string& value);

};
