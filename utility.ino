
//---------------------------------------------------------
//  ASCIIバイト列を比較して結果を返す
//---------------------------------------------------------
//[Arguments]
//  *str1 : 比較されるcharバイト列へのポインタ
//  *str2 : 比較するcharバイト列へのポインタ
//[Returns]
//  unsigned char : 0 = 最後まで一致した
//                  1 = バイト列は異なる
//--------------- https://ss1.xrea.com/tmct.s1009.xrea.com/
unsigned char compareByteString(char *str1, char *str2) {
  unsigned char flag = 0;
  while (*str1 != 0) {
    if (*str1 != *str2) {
      flag = 1;
      break;
    }
    str1++;
    str2++;
  }
  if ((*str1 != 0) || (*str2 != 0)) flag = 1;
  return (flag);
}


//---------------------------------------------------------
//  ASCIIバイト列を小文字→大文字変換しながら複製して返す
//---------------------------------------------------------
//[Arguments]
//  *src : 変換もとのバイト列へのポインタ
//  *dst : 変換後の結果を格納するバイト列へのポインタ
//[Returns]
//  なし
//[Note]
//  *dstには *srcを格納できるだけの領域が必要です
//--------------- https://ss1.xrea.com/tmct.s1009.xrea.com/
void toUpperCopyByteString(char *src, char *dst) {
  while (*src != 0) {
    if ((*src >= 'a') && (*src <= 'z')) *dst = (*src - 0x20); else *dst = *src;
    src++;
    dst++;
  }
}


//---------------------------------------------------------
//  ASCIIバイト列を小文字→大文字変換して返す
//---------------------------------------------------------
//[Arguments]
//  *str : 変換対象のバイト列へのポインタ
//[Returns]
//  なし
//--------------- https://ss1.xrea.com/tmct.s1009.xrea.com/
void toUpperByteString(char *str) {
  while (*str != 0) {
    if ((*str >= 'a') && (*str <= 'z')) *str -= 0x20;
    str++;
  }
}


//---------------------------------------------------------
//  ASCIIバイト列を大文字→小文字変換しながら複製して返す
//---------------------------------------------------------
//[Arguments]
//  *src : 変換もとのバイト列へのポインタ
//  *dst : 変換後の結果を格納するバイト列へのポインタ
//[Returns]
//  なし
//[Note]
//  *dstには *srcを格納できるだけの領域が必要です
//--------------- https://ss1.xrea.com/tmct.s1009.xrea.com/
void toLowerCopyByteString(char *src, char *dst) {
  while (*src != 0) {
    if ((*src >= 'A') && (*src <= 'Z')) *dst = (*src + 0x20); else *dst = *src;
    src++;
    dst++;
  }
}


//---------------------------------------------------------
//  ASCIIバイト列を大文字→小文字変換して返す
//---------------------------------------------------------
//[Arguments]
//  *str : 変換対象のバイト列へのポインタ
//[Returns]
//  なし
//--------------- https://ss1.xrea.com/tmct.s1009.xrea.com/
void toLowerByteString(char *str) {
  while (*str != 0) {
    if ((*str >= 'A') && (*str <= 'Z')) *str += 0x20;
    str++;
  }
}


//---------------------------------------------------------
//  2桁までの16進数ASCIIバイト列を数値変換してunsigned char型の値として返す
//---------------------------------------------------------
//[Arguments]
//  *str : 変換対象のバイト列へのポインタ
//[Returns]
//  unsigned char : 変換後の値
//[Note]
//  変換対象のASCIIバイト列に16進数に変換できない文字が含まれる場合は
//  異常な値が返ります
//--------------- https://ss1.xrea.com/tmct.s1009.xrea.com/
unsigned char toCharHexByteString(char *str) {
  unsigned char r = 0;
  if(*str > 0x39) r = *str - 0x07; else r = *str;
  str++;
  if (*str != 0) {
    r <<= 4;
    if(*str > 0x39) r |= (*str - 0x07) & 0x0f; else r |= (*str & 0x0f);
  }
  return (r);
}


//---------------------------------------------------------
//  4桁までの16進数ASCIIバイト列を数値変換してunsigned short型の値として返す
//---------------------------------------------------------
//[Arguments]
//  *str : 変換対象のバイト列へのポインタ
//[Returns]
//  unsigned short : 変換後の値
//[Note]
//  変換対象のASCIIバイト列に16進数に変換できない文字が含まれる場合は
//  異常な値が返ります
//--------------- https://ss1.xrea.com/tmct.s1009.xrea.com/
unsigned short toShortHexByteString(char *str) {
  unsigned short r = 0;
  unsigned char i;
  if(*str > 0x39) r = *str - 0x07; else r = *str;
  for (i = 0; i < 3; i++)
  {
    str++;
    if (*str != 0) {
      r <<= 4;
      if(*str > 0x39) r |= (*str - 0x07) & 0x0f; else r |= (*str & 0x0f);
    }
    else break;
  }
  return (r);
}


//---------------------------------------------------------
//  8桁までの16進数ASCIIバイト列を数値変換してunsigned long型の値として返す
//---------------------------------------------------------
//[Arguments]
//  *str : 変換対象のバイト列へのポインタ
//[Returns]
//  unsigned long : 変換後の値
//[Note]
//  変換対象のASCIIバイト列に16進数に変換できない文字が含まれる場合は
//  異常な値が返ります
//--------------- https://ss1.xrea.com/tmct.s1009.xrea.com/
unsigned long toLongHexByteString(char *str) {
  unsigned long r = 0;
  unsigned char i;
  if(*str > 0x39) r = *str - 0x07; else r = *str;
  for (i = 0; i < 7; i++)
  {
    str++;
    if (*str != 0) {
      r <<= 4;
      if(*str > 0x39) r |= (*str - 0x07) & 0x0f; else r |= (*str & 0x0f);
    }
    else break;
  }
  return (r);
}


//---------------------------------------------------------
//  バイト列を複製する
//---------------------------------------------------------
//[Arguments]
//  *src  : 複製もとのバイト列へのポインタ
//  *dst  : 複製後の結果を格納するバイト列へのポインタ
//  st    : *srcの複製開始位置
//  length: 複製するバイト数
//  dstcol: *dstへの複製開始位置
//[Returns]
//  なし
//--------------- https://ss1.xrea.com/tmct.s1009.xrea.com/
void copyByteString(unsigned char *src, unsigned char *dst,  unsigned char st, unsigned char length, unsigned char dstcol) {
  unsigned char i;
  dst += dstcol;
  src += st;
  for(i = 0; i < length; i++) {
    *dst = *src;
    dst++;
    src++;
  }
}
