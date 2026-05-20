#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>

enum class MenuOptions
{
	exit,
	get_problem,
	add_problem
};

int main()
{
	std::cout << "========= MAIN MENU =========" << std::endl;
	std::cout << std::setw(14) << std::left << "Get problem:" << std::setw(5) << std::right << "[1]" << std::endl;
	std::cout << std::setw(14) << std::left << "Add problem:" << std::setw(5) << std::right << "[2]" << std::endl;
	std::cout << std::setw(14) << std::left << "Exit program:" << std::setw(5) << std::right << "[0]" << std::endl << std::endl;
	std::cout << "Enter your option:  ";

	std::string option_str{};
	std::getline(std::cin, option_str);
	uint16_t option{};

	std::cin.get();
	return 0;
}