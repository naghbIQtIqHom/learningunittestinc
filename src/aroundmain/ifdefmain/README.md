# main関数を define あるなしで ifdefで main以外の名前にしてユニットテストする

## このディレクトリ

main関数をユニットテストしたいが、
main関数2つ定義できない制約があるからテスト用にmain関数名を変更する。



## 方法
C/C++ではmain関数を2つ以上作成できないが、
main関数をユニットテストしたいがために、
define あるなしで ifdefで main以外の名前にしてユニットテストする。

もしできるなら、main関数はシンプルにして、コードレビューで済むように書いておいて、
ユニットテストは別のオブジェクトに対して行う。
main関数の動作の確認はユニットテストより上位レベルのテストで行う。

次のようにmain関数を別の名前に置換してしまう。
```
#ifndef MAIN_FOR_UNITTEST
#define MAIN main
#else
#define MAIN under_unittest_main
#endif

int MAIN()
{
}
```

ビルドは次のように`-DMAIN_FOR_UNITTEST` を付けて行う。
```
gcc -DMAIN_FOR_UNITTEST -c -o main.o main.c
```

ユニットテストするときは `under_unittest_main` を呼ぶ。

### main()にほとんど書かなければよくない?

次のように main関数内部に実装はほとんどしない。  
main関数のユニットテストは書かないが、コードレビューと上位レベルのテストでその部分の動作確認を行う。

```c++
#include "implement.h"

int main()
{
  int rtn = implement();
  return rtn;
}
```

```c++
int implement()
{
  /* ... */
}
```

## このディレクトリのビルド


* Catch2 をあらかじめビルドしてインストールしておく。
  ``` shell
  git clone https://github.com/catchorg/Catch2.git
  cd Catch2
  cmake -S . -B build
  cmake --build build
  cmake --install build
  ```

* このディレクトリでビルド。ビルドしてテストも走る。
  * make の場合
    ``` shell
    make
    ```
  * CMake の場合
    ``` shell
    cmake -S . -B build
    cmake --build build
    (cd build && ctest -V)
    ```

