#pragma once
#include <string>
#include <vector>
#include <optional>

static const std::string PATH = "saves/all_problems.txt";

namespace Problem
{
	class Problem
	{
	public:
		void load_tasks();
		void save_remaining();
		void add_problem(const std::string& problem);
		std::optional<std::string> get_problem();

	private:
		std::vector<std::string> all_tasks{};
		std::vector<std::string> remaining_tasks{};
		const std::string PATH_ALL = "saves/all_problems.txt";
		const std::string PATH_SAVE = "saves/remaining_problems.txt";
	};

	bool check_problem_syntax(const std::string& problem);

	void add_problem(const std::string& problem);

	void get_problem();

	void remove_problem();

}