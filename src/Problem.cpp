#include "Problem.h"
#include "StringParser.h"
#include <iostream>
#include <fstream>
#include <format>
#include <random>
#include <ctime>

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
	// 1. Если файл со всеми задачами есть и не пуст — загружаем в вектор
	std::ifstream all_file(PATH_ALL);
	if (all_file.is_open())
	{
		std::string line{};
		while (std::getline(all_file, line))
		{
			all_tasks.push_back(line);
		}
	}
	// 2. Есть ли файл с сохранением???
	if (check_file(PATH_SAVE))	// нет или пуст
	{
		remaining_tasks = all_tasks;
	}
	else	// в нём что-то есть
	{
		std::ifstream save_file(PATH_SAVE);
		if (save_file.is_open())
		{
			std::string line{};
			while (std::getline(save_file, line));
			{
				remaining_tasks.push_back(line);
			}
		}
	}
}

void Problem::Problem::save_remaining()
{
	std::ofstream save_file(PATH_SAVE);
	if (!save_file.is_open())
	{
		throw std::runtime_error(std::format("Не удалось открыть файл '{}' для записи. [Нажми enter].\n", PATH_SAVE));
	}

	for (size_t i{}; i < remaining_tasks.size(); ++i)
	{
		save_file << remaining_tasks[i];
		if (i != remaining_tasks.size() - 1)
		{
			save_file << "\n";
		}
	}
}

void Problem::Problem::add_problem(const std::string& problem)
{
	// 1. Проверяем, пуст ли файл (или не существует)
	bool is_empty{ check_file(PATH_ALL) };

	std::ofstream all_problems_txt(PATH_ALL, std::ios::app);
	if (!all_problems_txt.is_open())
		throw std::runtime_error(std::format("The file has not opened... [press enter].\n"));

	if (!check_problem_syntax(problem))
		throw std::invalid_argument(std::format("The problem syntax isn't correct... [press enter].\n"));

	if (!is_empty)
		all_problems_txt << "\n";

	all_problems_txt << problem;

	all_tasks.push_back(problem);
	remaining_tasks.push_back(problem);
}

std::optional<std::string> Problem::Problem::get_problem()
{
	if (remaining_tasks.empty())
		return std::nullopt;

	static std::mt19937_64 rng(std::time(nullptr));
	std::shuffle(remaining_tasks.begin(), remaining_tasks.end(), rng);

	std::string problem{ remaining_tasks.back() };
	remaining_tasks.pop_back();

	save_remaining();

	return problem;
}
