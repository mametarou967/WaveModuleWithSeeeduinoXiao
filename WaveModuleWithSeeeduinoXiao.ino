#include <SoftwareSerial.h>
#include "MP3Player_KT403A.h"

SoftwareSerial mp3(7, 6);

void setup() {
  mp3.begin(9600);          // grove mp3用のシリアル通信を開始
  delay(100);               // 一拍置く
  SelectPlayerDevice(0x02); // mp3モジュールをSDカードから読み取るように設定
  SetVolume(0x1E);          // ボリュームをマックスに指定
}

// the loop function runs over and over again forever
void loop() {
    SpecifyMusicPlay(1);
    delay(10000);
}
