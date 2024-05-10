#include "Course.hpp"
#include "Major.hpp"
#include "University.hpp"
#include <fmt/format.h>
#include <fmt/ranges.h>

inline auto format_as(const Course& course)
{
    return fmt::format("Course: {} ({} units)", course.name, course.units);
}

inline auto format_as(const Major& major)
{
    auto h = fmt::format("Major: {} (required gpa of {})\n", major.name, major.gpa_req);
    std::string req_str;
    for (const auto& disjunct_req : major.required_courses) {
        req_str += "\t[";
        for (const auto& conjunct_req : disjunct_req) {
            req_str += fmt::format("({}) OR ", fmt::join(conjunct_req, " AND "));
        }
        req_str += "]\n";
    }
    return fmt::format("{}\nRequired courses = \n{}", h, req_str);
}

inline auto format_as(const University& uni)
{
    return fmt::format("University: {}\nInformation on Majors: \n{}", uni.uni_name, fmt::join(uni.major_list, "\n"));
}