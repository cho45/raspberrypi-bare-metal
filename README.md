Raspberry Pi Bare Metal Sample
==============================

https://github.com/dwelch67/raspberrypi/tree/master/blinker01
を手元で習作的に再実装したもの。

Mac OS X での環境構築
---------------------

https://launchpad.net/gcc-arm-embedded を入れてパスを通す

ビルドして Raspberry Pi で動かす
--------------------------------

```
rake install dest=/Volume/SD
```

で kernel.img のビルドから kernel.img, bootcode.bin, start.elf の SD カードへのコピーと SD カードのイジェクトが自動で行われる。あとは Raspberry Pi にその SD カードを挿して電源を入れると、LAN ポート近く、電源LED の隣の ACT という LED が点滅する (Raspberry Pi ボード上の LED なので追加の配線やLEDはいらない)
