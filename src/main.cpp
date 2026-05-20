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
		// ===========================================================
		


		// ======= ПРЕОБРАЗОВАНИЕ В enum И ВЫПОЛНЕНИЕ ДЕЙСТВИЯ =======
		MenuOptions choice;

		switch (choice)
		{

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