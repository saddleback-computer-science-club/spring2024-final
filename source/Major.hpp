#pragma once

#include <string>
#include <vector>
using std::vector, std::string;

struct Major
{
    // Name of the major
    string major_name;

    // GPA requirement for the major
    float gpa_req;

    // Map of required courses for the major
    vector<vector<vector<string>>> required_courses;

    // API to simply append another element to major_list
    void add_required_courses(vector<vector<string>>&& req)
    {
        required_courses.emplace_back(std::move(req));
    }
};
