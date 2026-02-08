#ifndef ORDER_FILE_H
#define ORDER_FILE_H

#include "TextFile.hpp"

class OrderFile
{
public:
	OrderFile(std::filesystem::path& arg_path, bool& arg_error_handler);
	const std::vector<std::string>& GetOrderFileNames() const noexcept;
	uint64_t GetNumberOfSections() const;

private:
	void GetOrderListFromFile(TextFile& order_file_buff);
	std::vector<std::string> m_order_file_names = {};
	uint64_t m_number_of_sections;

};

#endif // !ORDER_FILE_H