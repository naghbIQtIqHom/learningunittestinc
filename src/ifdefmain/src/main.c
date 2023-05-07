// MAINというマクロ名が今一つ。あと引数これどうすれば可変にできる?
#ifndef MAIN_FOR_UNITTEST
#define MAIN main
#else
#define MAIN under_unittest_main
#endif

int MAIN()
{
    return 1;
}
