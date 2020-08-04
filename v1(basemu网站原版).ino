/*Arduino  Music Player */

#include "SD.h"     //读取 SD card 文件
#include "TMRpcm.h"     //读取 音频播放文件
#include "SPI.h"     //读取 SD card的SPI 文件

#define SD_ChipSelectPin 4     //设置CS 引脚 4
TMRpcm music;     //设置音频播放对象 "music"

int song_number=0;
boolean debounce1=true;
boolean debounce2=true;
boolean play_pause;

void setup(){
music.speakerPin = 9; //设置音频输出针脚 9
Serial.begin(9600);     //串口调试
if (!SD.begin(SD_ChipSelectPin)) {
Serial.println("SD fail");
return;
}

pinMode(2, INPUT_PULLUP); //Button 1 切换音频文件
pinMode(3, INPUT_PULLUP); //Button 2 播放或暂停
pinMode(3, INPUT_PULLUP); //Button 2 快进

music.setVolume(5);    //   设置音量0 ~7
music.quality(1);        //  设置 1 或 2x 采样速度，0为正常值
//music.volume(0);        //   1(高)  0(低)控制音量
//music.play("filename",30);     //从30秒开始播放一个文件
}

void loop(){

if (digitalRead(2)==LOW  && debounce1 == true)     //Button 1 按下
{
song_number++;
if (song_number==5)
{song_number=1;}
debounce1=false;
Serial.println("KEY PRESSED");
Serial.print("song_number=");
Serial.println(song_number);

if (song_number ==1)
{music.play("1.wav",10);} //从10秒开始播放第一首歌

if (song_number ==2)
{music.play("2.wav",33);} //从33秒开始播放第二首歌

if (song_number ==3)
{music.play("3.wav");}   //从开始位置播放第三首歌

if (song_number ==4)
{music.play("4.wav",25);}   //从25秒开始播放第四首歌

if (digitalRead(3)==LOW  && debounce2 == true) //Button 2 按下
{
music.pause();  Serial.println("PLAY / PAUSE");
debounce2=false;
}

if (digitalRead(2)==HIGH)   //防止误操作
debounce1=true;

if (digitalRead(3)==HIGH)  //防止误操作
debounce2=true;
}

}