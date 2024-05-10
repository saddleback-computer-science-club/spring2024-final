#pragma once

#include "Major.hpp"
#include <iostream>
using namespace std;

struct University
{
    // // Unique identifier for the university
    // int uni_id;

    // Name of the university
    string uni_name;

    // List of majors offered at the university
    vector<Major> major_list;

    // API to simply append another element to major_list
    void add_major(Major&& major)
    {
        major_list.emplace_back(std::move(major));
    }
};
