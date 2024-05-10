cmake_minimum_required(VERSION 3.15)

project(counseling LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)


add_library(counseling_lib
            "source/Course.hpp"
            "source/Major.hpp"
            "source/University.hpp"
            "source/parsing.hpp"
            "source/parsing.cpp"
)

target_compile_features(counseling_lib PUBLIC cxx_std_20)
target_include_directories(counseling_lib PUBLIC "source")
target_include_directories(counseling_lib PUBLIC "include")

target_link_libraries(counseling_lib PUBLIC fmt::fmt)

if(MSVC)
  target_compile_options(counseling_lib PUBLIC /W4 /WX)
else()
  target_compile_options(counseling_lib PUBLIC -Wall -Wextra -Wpedantic) #-Werror)
endif()


add_executable(counseling_exe "source/main.cpp")

target_link_libraries(counseling_exe PUBLIC counseling_lib)

# if(BUILD_TESTING)
  add_subdirectory(test)
# endif()



