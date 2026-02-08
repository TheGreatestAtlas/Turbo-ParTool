#include "OrderFile.hpp"
#include "Globals.hpp"

using namespace std;

const vector<string>& OrderFile::GetOrderFileNames() const noexcept { return this->m_order_file_names; }
uint64_t OrderFile::GetNumberOfSections() const { return this->m_number_of_sections; }

OrderFile::OrderFile(std::filesystem::path& arg_path, bool& arg_error_handler) :
	m_number_of_sections(0)
{
	TextFile order_file(arg_path);
	order_file.Informations();
	arg_error_handler = !(order_file.GetIsOpened());
	//order_file.ExitWhenFileDontExist();

	if (arg_error_handler == Globals::success_code)
	{
		this->GetOrderListFromFile(order_file);

		size_t order_file_names_size = m_order_file_names.size();

		if (order_file_names_size >= 3)
		{
			this->m_number_of_sections = order_file_names_size - 3;
		}

		CONSOLE_OUT.PrintLn(m_number_of_sections, " sections were counted.");
	}
}



void OrderFile::GetOrderListFromFile(TextFile& order_file_buff)
{
	const vector<char>& order_file_vec = order_file_buff.GetFileBuffer();
	const size_t order_file_vec_len = order_file_vec.size();

	size_t line_index = 0;
	size_t line_len = 0;

	for (size_t i = 0; i < order_file_vec_len; ++i)
	{
		if (order_file_vec[i] == '\n' || order_file_vec[i] == '\0')
		{
			const char* line_data = reinterpret_cast<const char*>(&order_file_vec[line_index]);

			string line = string(line_data, line_len);

			if (!line.empty())
			{
				DEBUG_PRINT("line = \"", line, "\"", Mess::endl);
				this->m_order_file_names.push_back(line);
			}

			line_len = 0;
			line_index = i + 1;
		}
		else
		{
			++line_len;
		}

		if (order_file_vec[i] == '\0')
			break;

	}


}