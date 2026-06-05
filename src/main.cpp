#include <iostream>
#include <iomanip>
#include <string>
#include <cstdint>
#include "StringParser.h"
#include "Problem.h"

enum class MenuOptions
{
	exit,
	get_problem,
	add_problem,
	_LAST_
};

int main()
{



	while (true)
	{
		// ===================== ОТРИСОВКА МЕНЮ ======================
		std::cout << "========= MAIN MENU =========" << std::endl;
		std::cout << std::setw(14) << std::left << "Get problem:" << std::setw(5) << std::right << "[1]" << std::endl;
		std::cout << std::setw(14) << std::left << "Add problem:" << std::setw(5) << std::right << "[2]" << std::endl;
		std::cout << std::setw(14) << std::left << "Exit program:" << std::setw(5) << std::right << "[0]" << std::endl << std::endl;
		std::cout << "Enter your option:  ";
		// ===========================================================



		// ===================== ПОЛУЧЕНИЕ ВВОДА =====================
		std::string option_str{};
		std::getline(std::cin, option_str);
		// ===========================================================
		


		// ====================== ПАРСИНГ ВВОДА ======================
		auto opt = Parser::try_parse_uint(option_str);
		if (!opt || opt.value() < 0 || opt.value() >= static_cast<uint16_t>(MenuOptions::_LAST_))
		{
			system("cls");
			std::cout << "Error... [press enter]" << std::endl;
			std::cin.get();
			system("cls");
			continue;
		}
		uint16_t option = opt.value();
		// ===========================================================
		


		// ======= ПРЕОБРАЗОВАНИЕ В enum И ВЫПОЛНЕНИЕ ДЕЙСТВИЯ =======
		MenuOptions choice = static_cast<MenuOptions>(option);

		switch (choice)
		{
		case MenuOptions::exit:
		{
			system("cls");
			std::cout << "Exiting the program... [press enter]";
			std::cin.get();
			return 0;
		}
		case MenuOptions::get_problem:
		{

		}
		case MenuOptions::add_problem:
		{
			//Problem::add_problem();
		}
		default:
		{
			system("cls");
			std::cout << "Something wrong... [press enter]";
			std::cin.get();
			system("cls");
			continue;
		}
		}
		// ===========================================================
		


		// ========================== ПАУЗА ==========================
		std::cin.get();
		system("cls");
		// ===========================================================
	}



	std::cin.get();
	return 0;
}