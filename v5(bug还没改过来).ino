#include <SoftwareSerial.h>
#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>
#define SD_ChipSelectPin 4
TMRpcm music;
SoftwareSerial lyck(7, 8);
int song_number = 0;
int volctrl = A5;
boolean debounce1 = true;
boolean debounce2 = true;
boolean play_pause;
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
  int temp = analogRead(volctrl);
  music.setVolume(map(temp, 0, 1023, 0, 7));
  music.quality(1);
}

void loop() {
  //
  if (lyck.available()) {
    intSD fail lyckvol = lyck.read();
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
  }
  if (digitalRead(2) == LOW  && debounce1 == true)
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

    if (digitalRead(3) == LOW && debounce2 = true;)
    {
      music.pause();
      Serial.println("PLAY / PAUSE");
      debounce2 = false;
    }

    if (digitalRead(2) == HIGH)
    { debounce1 = true;
      delay(500);
    }
    if (digitalRead(3) == HIGH)
    { delay(500);
      if (digitalRead(3) == HIGH)
        debounce2 = true;
    }
  }

}