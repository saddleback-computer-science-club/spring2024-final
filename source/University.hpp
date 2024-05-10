#pragma once

#include "Major.hpp"
using namespace std;

struct University
{
    // Name of the university
    string uni_name;

    // List of majors offered at the university
    vector<Major> major_list;

    // Constructor to initialize a University object
    University(string name)
        : uni_name(name)
    {}

    /*University Class:

    Constructor: To initialize the University object with default or given values.
    addMajor(Major major): To add a Major object to the major_list.
    getMajor(string majorName): To retrieve a Major object by its name.
   getUniName(): To get the name of the university.
    getUniId(): To get the ID of the university.

    */

    void add_major(const Major& major)
    {
        major_list.push_back(major);
    }

    // For simplified testing
    bool operator==(const University& rhs) const = default;
};
