#include "fmt_impls.hpp"
#include "parsing.hpp"
#include <fmt/core.h>
#include <fstream>

int main()
{
    using fmt::println;

    println("Hello from counseling app!");

    constexpr auto FILE_NAME = "./data/sample.csv";
    constexpr auto UNI_NAME = "UCI";

    std::ifstream sample_uni_csv(FILE_NAME);

    println("Loading university data for {} from {}", UNI_NAME, FILE_NAME);
    println("Parsing data...");

    auto parsed_uni_data = csv_to_uni(UNI_NAME, sample_uni_csv);

    println("Parsed Info:\n{}", parsed_uni_data);
}
