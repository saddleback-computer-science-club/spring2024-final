#include "parsing.hpp"
#include "Course.hpp"
#include "Major.hpp"
#include "University.hpp"
#include <iostream>
#include <limits>
#include <span>
#include <string_view>

std::vector<std::string_view> split(std::string_view str, char sep, char delim)
{
    std::vector<std::string_view> result;
    std::size_t last_pos = 0;

    for (std::size_t i = 0; i < str.size(); ++i) {
        // Split the string upon: separator, delimeter, or e
        // last recorded pos up to sep. For example, if sep=','
        // "hello,world" will become "hello" upon encountering ','
        if (str[i] == sep || str[i] == delim) {
            auto token = str.substr(last_pos, i - last_pos);
            result.push_back(token);
            last_pos = i + 1;
        }

        if (str[i] == delim) {
            return result;
        }
    }

    result.push_back(str.substr(last_pos));

    return result;
}

University csv_to_uni(const std::string& uni_name, std::istream& csv_source)
{
    University result(uni_name);

    // Top line is just headers, so let's skip it
    csv_source.ignore(std::numeric_limits<int>::max(), '\n');

    std::string line;
    while (std::getline(csv_source, line)) {
        Major major = line_spec_to_major(line);
        result.add_major(major);
    }

    return result;
}

Major line_spec_to_major(std::string_view line_source)
{
    auto csv_fields = split(line_source, ',');

    auto major_name = std::string{csv_fields[0]};
    float major_gpa = std::stof(std::string{csv_fields[1]});

    Major result{major_name, major_gpa};

    std::span req_fields(csv_fields);

    for (auto requirement_spec : req_fields.subspan(2)) {
        if (requirement_spec.empty()) {
            break;
        }

        DisjunctiveReqs reqs = parse_req(requirement_spec);

        result.add_requirement(reqs);
    }

    return result;
}

DisjunctiveReqs parse_req(std::string_view statement_source)
{
    DisjunctiveReqs result;

    // Conjunctions have higher precedence ('&' gets eval-ed before '|')

    // Split by disjunction delimeter to obtain list of conjunctions!
    auto disjunctive_req = split(statement_source, '|');
    for (auto conjunctive_reqs : disjunctive_req) {
        ConjunctiveCourses conj;

        for (auto course_name : split(conjunctive_reqs, '&')) {
            auto course = Course(std::string{course_name});

            conj.push_back(course);
        }

        result.push_back(conj);
    }

    return result;
}