# 未解決のシンボルの解決の仕方

## このディレクトリ

ユニットテスト対象に関心のない未解決のシンボルを適当に解決してユニットテストするためのやり方。


## 方法
### 全部リンクする

がんばって必要なもの全てリンクする。

### 必要な未定義シンボルを自分でダミー実装する。

* 全部リンクするの大変なので、使用しないが解決が必要なシンボルをダミー実装する。
* テストダブルとして必要なものはそのように実装する。

### コンパイルオプションを使う

* gccならば `-Wl,--unresolved-symbols=ignore-in-object-files` を付ける。

