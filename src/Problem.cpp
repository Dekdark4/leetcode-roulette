#include "Problem.h"
#include <iostream>
#include <fstream>

void Problem::add_problem(std::string problem)
{
	bool is_empty{ false };
	{
		std::ifstream check(PATH);
		if (check.is_open())
		{
			is_empty = (check.peek() == std::ifstream::traits_type::eof());
		}
		else
		{
			is_empty = true;
		}
	}

	std::ofstream all_problems_txt;
	all_problems_txt.open(PATH, std::ofstream::app);

	if (!all_problems_txt.is_open())
	{
		system("cls");
		std::cerr << "The file has not opened... [press enter]";
		std::cin.get();
		return;
	}

	if (!is_empty)
		all_problems_txt << "\n";

	all_problems_txt << problem;
}