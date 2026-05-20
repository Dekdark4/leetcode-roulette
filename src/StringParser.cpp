#include "StringParser.h"
#include <sstream>
#include <limits>

std::optional<uint16_t> Parser::try_parse_uint(const std::string& input)
{
	// Пустая ли строка
	if (input.empty())
		return std::nullopt;

	// Содержит ли строка число
	std::istringstream iss(input);
	long long temp{};
	if (!(iss >> temp))
		return std::nullopt;
	
	// Нету ли мусора
	if (!(iss >> std::ws).eof())
		return std::nullopt;

	// Находится ли число в нужном диапазоне
	if (temp < std::numeric_limits<uint16_t>::min() || temp > std::numeric_limits<uint16_t>::max())
		return std::nullopt;

	// Единственно верный исход
	return static_cast<uint16_t>(temp);
}