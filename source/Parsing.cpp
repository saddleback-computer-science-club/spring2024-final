#include "Parsing.hpp"
#include <csv2/csv2.hpp>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string_view>
#include <vector>

University parse_uni_data(const std::string& file_path, const std::string& name)
{
    University result{name};
    csv2::Reader csv_reader;

    if (!csv_reader.mmap(file_path)) {
        throw std::invalid_argument("Unable to read from file path passed to `parse_uni_data`!");
    }

    for (auto row : csv_reader) {
        auto cell_iter = row.begin();

        Major major;

        // First two values in row are: major_name and gpa. Deal with them accordingly
        auto cell = *cell_iter;

        major.major_name = cell.read_view(); // Read the value for major name
        cell = *(++cell_iter);               // Advance the iterator

        auto gpa_str = cell.read_view();

        for (++cell_iter; cell_iter != row.end(); ++cell_iter) {
            cell = *cell_iter;

            auto req_str = cell.read_view();
            auto req = parse_requirement(req_str);
            major.add_required_courses(std::move(req));
        }

        result.add_major(std::move(major));
    }

    return result;
}

vector<vector<std::string>> parse_requirement(std::string_view req_str) {}