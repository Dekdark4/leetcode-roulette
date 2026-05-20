#pragma once
#include <cstdint>
#include <string>
#include <optional>

namespace Parser
{

	std::optional<uint16_t> try_parse_uint(const std::string& input);

}