
#include <catch2/catch_test_macros.hpp>
#include <cstdint>
#include "../include/basicOpperation.h"
#include "../include/atomType.h"
#include "catch2/generators/catch_generators.hpp"


TEST_CASE("atom_t")
{
    const auto upValue = GENERATE(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
    const auto downValue = GENERATE(0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);

    calculus::atom_t atom = {0};
    atom.setUp(upValue);
    atom.setDown(downValue);

    REQUIRE((uint8_t)atom.getUp() == (uint8_t)upValue);
    REQUIRE((uint8_t)atom.getDown() == (uint8_t)downValue);
}