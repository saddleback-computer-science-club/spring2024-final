#pragma once

#include <string>
#include <vector>

struct Course
{
    std::string name;
    float units;

    Course(std::string name)
        : Course(name, 0.0f)
    {}

    // Constructor to initialize a Course object
    Course(std::string name, float unit)
        : name(name)
        , units(unit)
    {}

    /*
           Constructor: To initialize the Course object with default or given values.
           getCourseName(): To get the name of the course.
           getCourseId(): To get the ID of the course.
           getCourseUnit(): To get the number of units the course is worth.

    */

    // For simplified testing
    bool operator==(const Course& rhs) const = default;
};

// Course requirement spec of the form:
//   courseA AND courseB AND ...
using ConjunctiveCourses = std::vector<Course>;

// Requirement spec of a list of conjunctive courses the form:
//   conjA OR conjB OR ...
using DisjunctiveReqs = std::vector<ConjunctiveCourses>;