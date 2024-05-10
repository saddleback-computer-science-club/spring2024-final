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
    auto s = fmt::format("Major: {} (required gpa of {})", major.name, major.gpa_req);
    return fmt::format("{}\nRequired courses = \n{}", s, fmt::join(major.required_courses, ", "));
}

inline auto format_as(const University& uni)
{
    auto s = fmt::format("University: {}", uni.uni_name);
    return fmt::format("{}\nInformation on Majors: \n{}", s, fmt::join(uni.major_list, "\n"));
}