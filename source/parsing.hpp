#include "Course.hpp"
#include "Major.hpp"
#include "University.hpp"

#include <string_view>
#include <vector>

std::vector<std::string_view> split(std::string_view str, char sep, char delim = '\n');

University csv_to_uni(const std::string& uni_name, std::istream& csv_source);

Major line_spec_to_major(std::string_view line_source);

DisjunctiveReqs parse_req(std::string_view statement_source);
