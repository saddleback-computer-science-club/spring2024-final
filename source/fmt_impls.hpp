#include "Course.hpp"
#include "Major.hpp"
#include "University.hpp"
#include <fmt/format.h>
#include <fmt/ranges.h>

inline auto format_as(const Course& course)
{
    return course.name;
    // return fmt::format("Course: {} ({} units)", course.name, course.units);
}

inline auto format_as(const Major& major)
{
    auto h = fmt::format("Major: {} (required gpa of {:.2f})\n", major.name, major.gpa_req);
    std::string req_str;
    for (const auto& disjunct_req : major.required_courses) {
        std::vector<std::string> conj_req_parts;
        for (const auto& conjunct_req : disjunct_req) {
            conj_req_parts.push_back(fmt::format("[{}]", fmt::join(conjunct_req, " AND ")));
        }
        req_str += fmt::format("\t{}\n", fmt::join(conj_req_parts, " OR "));
    }
    return fmt::format("{}\nRequired courses = \n{}", h, req_str);
}

inline auto format_as(const University& uni)
{
    return fmt::format("University: {}\nInformation on Majors: \n{}", uni.uni_name, fmt::join(uni.major_list, "\n"));
}