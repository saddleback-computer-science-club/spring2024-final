#pragma once

#include "Course.hpp"
#include <string>
#include <vector>
using namespace std;

struct Major
{
    // Name of the major
    string name;

    // GPA requirement for the major
    float gpa_req;

    // Required courses for the major
    vector<DisjunctiveReqs> required_courses;

    // Constructor to initialize a Major object
    Major(string name, float gpa)
        : name(name)
        , gpa_req(gpa)
    {}

    /*        Major Class:

            Constructor: To initialize the Major object with default or given values.
            addRequiredCourse(string courseCategory, vector<string> courses): To add required courses to the
       required_courses map. getGPAReq(): To get the GPA requirement for the major. getRequiredCourses(): To get the map
       of required courses. …other getters and setters as needed.



    */

    void add_requirement(DisjunctiveReqs&& req)
    {
        required_courses.push_back(std::move(req));
    }

    // For simplified testing
    bool operator==(const Major& rhs) const = default;
};
