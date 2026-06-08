#pragma once
#include <string>

static const std::string PATH = "saves/all_problems.txt";

namespace Problem
{

	bool check_problem_syntax(const std::string& problem);

	void add_problem(const std::string& problem);

	void get_problem();

	void remove_problem();

}