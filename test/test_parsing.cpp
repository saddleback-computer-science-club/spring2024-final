#include "Course.hpp"
#include "University.hpp"
#include "parsing.hpp"
#include <catch2/catch_test_macros.hpp>
#include <sstream>
#include <string_view>
#include <vector>

TEST_CASE("Basic string split cases", "[split]")
{
    using vs = std::vector<std::string_view>;
    REQUIRE(split("123,test,$Er4", ',') == vs{"123", "test", "$Er4"});

    REQUIRE(split("ABC&DEF&GHI", '&') == vs{"ABC", "DEF", "GHI"});

    REQUIRE(split("ABC&DEF\n&GHI", '&') == vs{"ABC", "DEF"});

    REQUIRE(split("CS1A&CS1B|MATH 30A&PSYC 101", '&', '|') == vs{"CS1A", "CS1B"});

    auto expected = vs{"Computer Science", "3.00", "CS1A&CS1B&CS1C|CS1D", "MATH3A", "", "", ""};
    REQUIRE(split("Computer Science,3.00,CS1A&CS1B&CS1C|CS1D,MATH3A,,,", ',') == expected);
}

TEST_CASE("Requirement statement parsing", "[parse_req]")
{
    using DR = DisjunctiveReqs;
    using CC = ConjunctiveCourses;

    REQUIRE(parse_req("A&B&C") == DR{CC{Course("A"), Course("B"), Course("C")}});

    REQUIRE(parse_req("A|B|C") == DR{CC{Course("A")}, CC{Course("B")}, CC{Course("C")}});

    auto expected = DR{CC{Course("A"), Course("B")}, CC{Course("C"), Course("D")}, CC{Course("E"), Course("F")}};
    REQUIRE(parse_req("A&B|C&D|E&F") == expected);
}

TEST_CASE("Major specification csv parsing", "[line_spec_to_major]")
{
    using DR = DisjunctiveReqs;
    using CC = ConjunctiveCourses;

    auto parsed_spec = line_spec_to_major("Computer Science,3.00,CS1A&CS1B&CS1C|CS1D,MATH3A,,,");
    auto expected = Major("Computer Science", 3.00);
    expected.add_requirement(DR{CC{Course("CS1A"), Course("CS1B"), Course("CS1C")}, CC{Course("CS1D")}});
    expected.add_requirement(DR{CC{Course("MATH3A")}});

    REQUIRE(parsed_spec == expected);
}

TEST_CASE("University csv parsing", "[csv_to_uni]")
{
    using DR = DisjunctiveReqs;
    using CC = ConjunctiveCourses;

    std::istringstream input_data(
        R"(major,gpa_req,req_1,req_2,req_3,req_4,req_5
Computer Science,3.00,CS1A&CS1B&CS1C|CS1D,MATH3A,,,)");

    auto expected = University("UCI");
    auto expected_major = Major("Computer Science", 3.00);
    expected_major.add_requirement(DR{CC{Course("CS1A"), Course("CS1B"), Course("CS1C")}, CC{Course("CS1D")}});
    expected_major.add_requirement(DR{CC{Course("MATH3A")}});
    expected.add_major(expected_major);

    REQUIRE(csv_to_uni("UCI", input_data) == expected);
}