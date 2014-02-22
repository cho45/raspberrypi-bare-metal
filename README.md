Raspberry Pi Bare Metal Sample
==============================

https://github.com/dwelch67/raspberrypi/tree/master/blinker01
を手元で習作的に再実装したもの。

Mac OS X での環境構築
=====================

arm-none-eabi でクロスコンパイルできる環境をつくるのが面倒

 * https://github.com/jsnyder/arm-eabi-toolchain

このスクリプトを使えば make 一発で ~/arm-cs-tools/ にコンパイラが入る。
ただし結構時間はかかる。

あとは PATH を通せば一応使えそうな環境はできるが、fpu まわりで必要なものが足りない。
よくわかってないので、今のところ、gcc のビルドしなおしではなく、ビルドオプションの変更で対応している。

具体的には、リンク時ハードウェア FPU 命令がないというエラーがでるので、 -mfloat-abi=softfp -mfpu=vfp をつけてビルドしている




