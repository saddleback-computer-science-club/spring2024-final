#include "fmt_impls.hpp"
#include "parsing.hpp"
#include <fmt/core.h>
#include <fstream>
#include <string>

int main()
{
    using fmt::println;

    println("Hello from counseling app!");

    const std::string FILE_NAME = "./data/uci.csv";
    const std::string UNI_NAME = "UCI";

    std::ifstream sample_uni_csv(FILE_NAME);

    println("Loading university data for {} from {}", UNI_NAME, FILE_NAME);
    println("Parsing data...");

    auto parsed_uni_data = csv_to_uni(UNI_NAME, sample_uni_csv);

    println("Parsed Info:\n{}", parsed_uni_data);

    // Parse student transcript data

    // Prompt user for major of choice

    // Check completed courses against required

    // Output remaining required courses, or whether all of them
    // have been completed
}
