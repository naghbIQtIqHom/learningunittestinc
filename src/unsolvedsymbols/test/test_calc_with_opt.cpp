#include <catch2/catch_test_macros.hpp>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
#include "../src/calc.h"
#ifdef __cplusplus
}
#endif /* __cplusplus */


TEST_CASE( "add() retruns 5 gevine 2 and 3" ) {
    REQUIRE( add(2, 3) == 5 );
}

/*
-Wl,--unresolved-symbols=ignore-in-object-files を使って未解決シンボルを解決を手抜くのはいいが、
呼ばれてはダメ。
del()内部で nothing()を呼んでいる。
TEST_CASE( "del() retruns -1 gevine 2 and 3" ) {
    REQUIRE( del(2, 3) == -1 );
}
*/
