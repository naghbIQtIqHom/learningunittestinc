#include <catch2/catch_test_macros.hpp>

extern "C" int under_unittest_main();

TEST_CASE( "unittest under_unittest_main" ) {
    REQUIRE( under_unittest_main() == 1 );
}
