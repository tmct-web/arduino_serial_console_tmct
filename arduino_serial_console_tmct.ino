#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(115200, SERIAL_8N1);
  Serial.println(F("Debug monitor"));
}

void loop() {
  
  const char console_ppt = '>';         // プロンプト文字
  const unsigned char console_len = 15; // 受信バッファの文字数

  char console_buf[console_len];        // 受信バッファ
  char console_byte = 0;                // 受信したデータ
  unsigned char console_bufpos = 0;     // 受信したデータのバイト数

  unsigned char i = 0;
  int slave_addr;
  int device_addr;
  int data;

  Serial.write(console_ppt);

  //-------------------------------------------------------
  //  受信ループ
  //  [LF]が受信されるとループを抜けます
  //------------- https://ss1.xrea.com/tmct.s1009.xrea.com/
  for (i = 0; i < console_len; i++) console_buf[i] = 0;
  while (true) {

    //----- 受信待ち -----
    while (Serial.available() <= 0) {
      //
      //  データが受信されるまで、ここでループします
      //  1バイト以上のデータが受信されるとこのループを抜けます
      //
    }
  
    //----- 受信されたデータを処理 -----
    console_byte = Serial.read();
    if (console_byte == 0x0a) {
      // [LF]が受信された場合
      Serial.write(0x0d); // [CR]
      Serial.write(0x0a); // [LF]
      break;
    }
    else if (console_byte == 0x08) {
      // [BS]が受信された場合
      // 前の文字を消す
      if (console_bufpos > 0) {
        Serial.write(0x08); // [BS]
        Serial.write(' ');  // [SP]
        Serial.write(0x08); // [BS]
        console_buf[console_bufpos] = 0;
        console_bufpos--;
      }
      console_buf[console_bufpos] = 0;
    }
    else if (console_byte < ' ') {
      // その他の制御コードの場合
      // 何もしない
    }
    else {
      // その他の文字と思われる場合
      if (console_bufpos < console_len) {
        console_buf[console_bufpos] = console_byte;
        Serial.write(console_byte);
        console_bufpos++;
      }
    }
    
  }

  //-------------------------------------------------------
  //  コマンド処理
  //  console_buf[]   受信されたバイト列
  //  console_bufpos  受信されたバイト数
  //------------- https://ss1.xrea.com/tmct.s1009.xrea.com/
  // 試しに表示してみます

  // 受信された中身を表示
  //for (i = 0; i < console_bufpos; i++) {
  //  if (console_buf[i] == 0) break; else Serial.write(console_buf[i]);
  //}
  // 受信されたバイト数を表示
  //Serial.write(0x0d);
  //Serial.write(0x0a);
  //Serial.println(console_bufpos, DEC);

  if ((console_buf[0] == 'i') || (console_buf[0] == 'I')) {
    //----- 1バイト目 = 'i' or 'I' の場合 -----
    if ((console_buf[1] == 'r') || (console_buf[1] == 'R')) {
      //----- 2バイト目 = 'r' or 'R' の場合 -----
      // 3~4バイト目を数値に変換
      slave_addr = (int)toCharHexByteString(&console_buf[2]);
      // 5~6バイト目を数値に変換
      device_addr = (int)toCharHexByteString(&console_buf[4]);
      // I2CバスにReadアクセス
      Wire.beginTransmission(slave_addr);
      Wire.write(device_addr);
      Wire.endTransmission();
      Wire.requestFrom(slave_addr, 1);
      if (Wire.available()) i = Wire.read();
      Wire.endTransmission();
      Serial.println(i, HEX);
    }
    else if ((console_buf[1] == 'w') || (console_buf[1] == 'W')) {
      //----- 2バイト目 = 'w' or 'W' の場合 -----
      // 3~4バイト目を数値に変換
      slave_addr = (int)toCharHexByteString(&console_buf[2]);
      // 5~6バイト目を数値に変換
      device_addr = (int)toCharHexByteString(&console_buf[4]);
      // 7~8バイト目を数値に変換
      data = (int)toCharHexByteString(&console_buf[6]);
      // I2CバスにWriteアクセス
      Wire.beginTransmission(slave_addr);
      Wire.write(device_addr);
      Wire.write(data);
      Wire.endTransmission();
      Serial.println(' ');
    }
  }
}
