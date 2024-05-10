This is going to be the simple version of the counselling project for CS Club 
Spring 2024 - Saddleback College

## Setup Instructions

Using vscode:

1) Install the CMake Tools (Microsoft verified)
2) Open the folder in vscode -> CMake Sidebar -> Project Status -> Configure
   - Choose "default"
3) To build, `F5`

Without:

1) Ensure `cmake` is installed by opening a terminal and running `cmake -v`
2) Navigate to the project folder and run the following command to setup the project

```console
cmake --preset default
```

3) To compile and run the project, run the following two commands in sequence

```console
cmake --build build
./build/counseling_exe
```

If you'd like to execute the units tests, run the following two commands in sequence

```console
cd build/test
ctest
```
