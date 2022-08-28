#include <SoftwareSerial.h>
#include "MP3Player_KT403A.h"
#include "ATCommands.h"

// grove mp通信用
SoftwareSerial mp3(7, 6);

// host pcとのシリアル通信用
#define WORKING_BUFFER_SIZE 255 // The size of the working buffer (ie: the expected length of the input string)
// declare the commands in an array to be passed during initialization
ATCommands AT; // create an instance of the class

bool at_write_cmd_play(ATCommands *sender)
{
    String str1 = sender->next();
    int playNumber = str1.toInt();
    SpecifyMusicPlay(playNumber);
    return true; // tells ATCommands to print OK
}

bool at_write_cmd_volconf(ATCommands *sender)
{
    String str1 = sender->next();
    int volumeConfig = str1.toInt();
    if(volumeConfig > 0x1E) return false; // 音量の最大値は30
    SetVolume(volumeConfig);
    return true; // tells ATCommands to print OK
}


static at_command_t commands[] = {
    {"+PLAY", NULL, NULL, NULL, at_write_cmd_play},
    {"+VOLCONF", NULL, NULL, NULL, at_write_cmd_volconf},
};

void setup() {
  // grove mp通信用
  mp3.begin(9600);          // grove mp3用のシリアル通信を開始
  delay(100);               // 一拍置く
  SelectPlayerDevice(0x02); // mp3モジュールをSDカードから読み取るように設定
  SetVolume(0x1E);          // ボリュームをマックスに指定

  // host pcとのシリアル通信用
  Serial.begin(115200);
  AT.begin(&Serial, commands, sizeof(commands), WORKING_BUFFER_SIZE);
}

// the loop function runs over and over again forever
void loop() {
  AT.update();
}
