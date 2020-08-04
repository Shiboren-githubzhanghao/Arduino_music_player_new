#include<TMRpcm.h>
#include<SD.h>
#include<SPI.h>
#define SD_ChipSelectPin 4
TMRpcm music;
int quactrl = A1;
int volctrl = A1;
int xyskey = 3;
int bfztkey = 2;
boolean debounce1 = 1;
boolean debounce2 = 1;
boolean play_pause;
int song_number = 0;

void setup() {
  // put your setup code here, to run once:
  music.speakerPin = 9;
  Serial.begin(9600); 
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }
  int temp=map(Serial.read(volctrl),temp2=map(Serial.read(quactrl);
  music.setVolume(temp, 0, 1023, 0, 7); 
  music.quality(map(temp2, 0, 1023, 0, 2); 
  void loop() {
    // put your main code here, to run repeatedly:
    if (digitalRead(xyskey) == LOW  && debounce1 == true)
    {
      song_number++;
      if (song_number == 5)
      {
        song_number = 1;
      }
      debounce1 = false;
      Serial.println("KEY PRESSED");
      Serial.print("song_number=");
      Serial.println(song_number);
    }

    if (song_number == 1)
    {
      music.play("1.wav");
    }

    if (song_number == 2)
    {
      music.play("2.wav"); //从33秒开始播放第二首歌
    }

    if (song_number == 3)
    {
      music.play("3.wav"); 
    }

    if (song_number == 4)
    {
      music.play("4.wav");
    }

    if (digitalRead(bfztkey) == LOW  && debounce2 == true)
    {
      music.pause();  Serial.println("PLAY / PAUSE");
      debounce2 = false ;
    }

    if (digitalRead(bfztkey) == HIGH)
      debounce1 = true;

    if (digitalRead(xyskey) == HIGH)
      debounce2 = true;
  }