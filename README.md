# WaveModuleWithSeeeduinoXiao

## ハードウェア接続

|SeeeduinoXiao|Grove Mp3 v2.0|
|:---:|:---:|
|RX|TX|
|TX|RX|
|3V3|VCC|
|GND|GND|

![](images/Seeeduino-XIAO-pinout.jpg)

## Arduino IDE

### 書き込み設定

* ボード:Seeeduino Xiao

### ライブラリ

* SoftwareSerial
* MP3Player_KT403A.h
    * 公式ではないため[github](https://github.com/lemairec/rasika/blob/master/lib/MP3Player_KT403A/MP3Player_KT403A.h)からダウンロードし、ローカルに保存のこと