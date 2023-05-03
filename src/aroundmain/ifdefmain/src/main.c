#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// MAINというマクロ名が今一つ。あと引数これどうすれば可変にできる?
#ifndef MAIN_FOR_UNITTEST
#define MAIN main
#else
#define MAIN under_unittest_main
#endif


int MAIN()
{
    time_t t;
    srand((unsigned) time(&t));
    int r = rand() % 256;
    printf("num=%d\n", r);
    return r;
}
