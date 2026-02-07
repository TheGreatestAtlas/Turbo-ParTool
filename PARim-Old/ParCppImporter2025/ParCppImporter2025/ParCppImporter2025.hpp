#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <filesystem>
#include <unordered_map>

#ifdef _DEBUG
#define DEBUG_PRINT(x) //printf_s("%s",x)
#else
#define DEBUG_PRINT(x)
#endif

//---------------------
// InputBinFile CLASS
//---------------------

class InputBinFile
{
public:
	//Pola:
	uint8_t* m_file_buffer;

	InputBinFile(std::string argfilename);
	~InputBinFile();

	void Informations(std::ostream& o) const;
	void ExitWhenFileDontExist(std::ostream& o) const;

	//Gettery:
	bool GetIsOpened() const;
	bool GetIsOpenNow() const;
	uint64_t GetFileLength() const;

private:

	//Pola:
	std::fstream m_input_file;
	std::string m_file_name;
	uint64_t m_file_length;
	bool m_is_opened;
	bool m_is_open_now;

	//Metody:
	void OpenAndReadFile();

};

//------------
// Compilator
//------------

class Compilator
{
public:
	// metody:

	Compilator(uint8_t* argfilebuffer = nullptr, int64_t argfilelength = 0);

	void CompileTxtFileToBin();


	static void SaveOutputFileBufferToBin(std::fstream& outputfile, std::string& output_file_name);
	static std::vector<char> output_file_buffer;

private:
	//Pola:
	bool m_its_string;
	bool m_its_comment;
	uint8_t* m_file_buffer;
	uint64_t m_file_length;

	size_t m_number_of_obj_in_section;
	std::string m_instruction;
	std::string m_value_type;
	std::string m_name;
	std::string m_value;

	std::string m_binary_value;
	uint32_t m_bits_counter;

	std::vector <uint8_t> m_clean_file = {};

	//Metody:
	template<typename T>
	void WriteRaw(std::vector<char>& buf, const T& val);

	void DeleteComments();
	void DeleteContrCharAndPutToVector();

	void WriteGUID(std::string& slowo);
	void WriteString(std::string& str);

	template <typename T>
	void WriteValueToFile(std::string& value, uint8_t mode);
	
	template <typename T>
	void WriteTabToFile(std::string& str, uint8_t mode);

	template <typename T>
	void WriteNBitMaskToFile(std::string& str);

	void GetValuesFromString();
	void WriteInstructionToBin(std::string& valuetype, std::string& name, std::string& value);

	uint64_t CountValuesInTab(std::string& value);

};


class ParCompilatorOverlay
{
public:
	//Pola:
	static uint64_t m_number_of_sections;

	//Metody:
	ParCompilatorOverlay(std::istream& argin, std::ostream& argo, int my_argc, char* my_argv[]);

private:
	//Pola:
	Compilator myCompilator;

	std::istream& m_in_stream;
	std::ostream& m_o;

	std::string m_main_dir_name;

	std::string m_output_bin_file_name;
	std::fstream m_output_bin;

	std::vector<std::string> m_order_file_names = {};

	//metody:

	void StandardProgramExecution();

	void CompileAllTxtFiles();
	//{
	void CompileSingleTxtFile(const std::string& filename);
	//}

	void GetOrderListFromFile(uint8_t* pointertofilebuffer, uint64_t filebufferlength);
	
	void InitializeHashMap();

};