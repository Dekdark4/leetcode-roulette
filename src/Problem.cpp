#include "Problem.h"
#include <iostream>
#include <fstream>

void Problem::add_problem(std::string problem)
{
	std::ofstream all_problems_txt;
	all_problems_txt.open(PATH, std::ofstream::app);

	if (!all_problems_txt.is_open())
	{
		system("cls");
		std::cerr << "The file has not opened... [press enter]";
		std::cin.get();
		return;
	}
	
	all_problems_txt << "\n" + problem;
}