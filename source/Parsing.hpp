#pragma once

#include "Course.hpp"
#include "Major.hpp"
#include "University.hpp"
#include <string>
#include <string_view>

University parse_uni_data(const std::string& file_path, const std::string& name);

vector<vector<string>> parse_requirement(std::string_view req_str);