cmake_minimum_required(VERSION 3.27)
project(calculus)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0 # or a later release
)
FetchContent_MakeAvailable(Catch2)

set(CMAKE_CXX_STANDARD 23)



add_executable(calculus main.cpp
        src/basicOpperation.cpp
        include/basicOpperation.h
        src/atomType.cpp
        include/atomType.h)

add_executable(tests tests/TEST.cpp
        src/atomType.cpp
        include/atomType.h)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests)

