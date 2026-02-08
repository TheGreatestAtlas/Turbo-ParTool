#include "ParCompilator.hpp"

using namespace std;
namespace fs = filesystem;

ParCompilator::ParCompilator(fs::path& arg_input_path, bool& arg_error_handler)
{
	if (fs::exists(arg_input_path))
	{
		if (fs::is_directory(arg_input_path) == false)
		{
			CONSOLE_OUT.PrintLn("The specified folder does not exist!");
			arg_error_handler = Globals::error_code;
		}
	}

	if (arg_error_handler == Globals::success_code)
	{
		const char cpp_format[] = ".cpp";
		const char section_file_name[] = "section_order.txt";

		HashMaps par_file_hash_maps;
		fs::path order_file_path = arg_input_path / section_file_name;

		bool order_file_error_handler = Globals::success_code;
		OrderFile order_file(order_file_path, order_file_error_handler);
		
		if (order_file_error_handler == Globals::success_code)
		{
			const vector<string>& order_file_names = order_file.GetOrderFileNames();
			uint64_t number_of_sections = order_file.GetNumberOfSections();

			for (const auto& file_name : order_file_names)
			{
				string data_sub_file_name = file_name + cpp_format;
				fs::path data_sub_file_path = arg_input_path / data_sub_file_name;

				Compilator compiled_data_sub(
					data_sub_file_path,
					this->m_output_file,
					par_file_hash_maps,
					number_of_sections,
					arg_error_handler
				);
			}
		}
		else
		{
			arg_error_handler = Globals::error_code;
		}
	}

}

