#include "Problem.h"
#include "StringParser.h"
#include <iostream>
#include <fstream>
#include <format>

bool Problem::check_problem_syntax(const std::string& problem)
{
	// 1. Проблема начинается не с '[' или проблема вообще пустая
	if (problem.empty() || problem[0] != '[')
		return false;
	// 2. В проблеме нет '[]'
	size_t close_bracket = problem.find(']');
	if (close_bracket == std::string::npos)
		return false;
	// 3. Между '[' и ']' нет номера
	std::string number_part = problem.substr(1, close_bracket - 1);
	if (number_part.empty())
		return false;

	/*for (char c : number_part)
		if (!std::isdigit(static_cast<unsigned char>(c)))
			return false;*/

	if (!Parser::try_parse_uint(number_part))
		return false;
	// 4. Помимо числа также есть мусор
	if (problem.size() <= close_bracket + 2)
		return false;

	if (problem[close_bracket + 1] != ' ')
		return false;

	if (problem.substr(close_bracket + 2).empty())
		return false;

	return true;
}

bool Problem::check_file(const std::string& PATH)
{
	std::ifstream check(PATH);
	if (check.is_open())
		return check.peek() == std::ifstream::traits_type::eof();
	
	return true;
}

void Problem::Problem::load_tasks()
{
	// 1. Проверить, не пуст ли файл all_tasks.txt
	bool is_empty = check_file(PATH_ALL);
	// 2. Загрузить проблемы в вектор all_tasks
	// 3. Если remaining_problems.txt пуст, то скопировать all_tasks в remaining_tasks
	// 
}

void Problem::Problem::add_problem(const std::string& problem)
{
	bool is_empty{ false };
	{
		std::ifstream check(PATH_ALL);
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
	all_problems_txt.open(PATH_ALL, std::ofstream::app);

	if (!all_problems_txt.is_open())
		throw std::runtime_error(std::format("The file has not opened... [press enter].\n"));

	if (!check_problem_syntax(problem))
		throw std::invalid_argument(std::format("The problem syntax isn't correct... [press enter].\n"));

	if (!is_empty)
		all_problems_txt << "\n";

	all_problems_txt << problem;
}