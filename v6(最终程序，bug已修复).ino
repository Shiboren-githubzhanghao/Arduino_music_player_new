#include <SoftwareSerial.h>
#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>
#define SD_ChipSelectPin 4
TMRpcm music;
SoftwareSerial lyck(7, 8);
int song_number = 1;
boolean debounce1 = true;
boolean debounce2 = true;
boolean play_pause;
int volstate = 0;
int mappedvol = 0;
void setup() {
  lyck.begin(9600);
  Serial.begin(9600);
  music.speakerPin = 9;
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  volstate=analogRead(A5);
  mappedvol=map(volstate,0,1023,0,5);
  music.setVolume(mappedvol);
  music.quality(1);
}
void loop() {
  volstate=analogRead(A5);
  mappedvol=map(volstate,0,1023,0,5);
  music.setVolume(mappedvol);
  Serial.println(mappedvol);
  if (digitalRead(2) == LOW) {
    music.pause();
    Serial.println("PLAY / PAUSE");
    delay(500);
  }
  if (lyck.available()) {
    char lyckvol = lyck.read();
    if (lyckvol == '1')
    {
      music.play("1.wav");
      Serial.print("Song played!");
    }
    if (lyckvol == '2')
    {
      music.play("2.wav");
      Serial.print("Song played!");
    }
    if (lyckvol == '3')
    {
      music.play("3.wav");
      Serial.print("Song played!");
    }
    if (lyckvol == '4')
    {
      music.play("4.wav");
      Serial.print("Song played!");
    }
    if (lyckvol == 'p' || lyckvol == 'P')
    {
      music.pause();
      Serial.println("PLAY / PAUSE");
    }
    if (lyckvol == 'n' || lyckvol == 'N')
    {
      song_number++;
    }
  }
  if (digitalRead(3) == LOW)
  {
    song_number++;
    if (song_number == 5)
    {
      song_number = 1;
    }
    Serial.println("KEY PRESSED");
    Serial.print("song_number=");
    Serial.println(song_number);
    if (song_number == 1)
    {
      music.play("1.wav");
    }
    if (song_number == 2)
    {
      music.play("2.wav");
    }
    if (song_number == 3)
    {
      music.play("3.wav");
    }
    if (song_number == 4)
    {
      music.play("4.wav");
    }
    delay(500);
  }
}
