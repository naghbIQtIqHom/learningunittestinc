#include <catch2/catch_test_macros.hpp>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include "../src/calc.h"


/*
 * テストに関係ないシンボルを宣言しておく。
 * C言語なので extern "C"の中で宣言しておく。
 */
void nothing(){} // dummy

#ifdef __cplusplus
}
#endif /* __cplusplus */


TEST_CASE( "add() retruns 5 gevine 2 and 3" ) {
    REQUIRE( add(2, 3) == 5 );
}

TEST_CASE( "del() retruns -1 gevine 2 and 3" ) {
    REQUIRE( del(2, 3) == -1 );
}
