# arduino_serial_console_tmct
 Arduino serial console

これはArduino用のシリアルコマンドコンソールのサンプルです。

いくつかの補助関数も含まれています。コメントとURLを削除しない限り、自由に複製して利用可能です。(商用・非商用問いません。)

- ASCIIバイト列を比較して結果を返す ... compareByteString
- ASCIIバイト列を小文字→大文字変換しながら複製して返す ... toUpperCopyByteString
- ASCIIバイト列を小文字→大文字変換して返す ... toUpperByteString
- ASCIIバイト列を大文字→小文字変換しながら複製して返す ... toLowerCopyByteString
- ASCIIバイト列を大文字→小文字変換して返す ... toLowerByteString
- 2桁までの16進数ASCIIバイト列を数値変換してunsigned char型の値として返す ... toCharHexByteString
- 4桁までの16進数ASCIIバイト列を数値変換してunsigned short型の値として返す ... toShortHexByteString
- 8桁までの16進数ASCIIバイト列を数値変換してunsigned long型の値として返す ... toLongHexByteString
- バイト列を複製する ... copyByteString

詳細は下記のページをご覧ください。

[tmct](https://ss1.xrea.com/tmct.s1009.xrea.com/doc/ta-ja-7e5g05.html)

-----

This is a sample of serial command console for Arduino.

It also contains some auxiliary functions. You can freely duplicate and use it as long as you do not delete the comment and URL. (It doesn't matter whether it's commercial or non-commercial.)

- Compare ASCII byte strings and return the result ... compareByteString
- Duplicate and return ASCII byte string while converting from lowercase to uppercase ... toUpperCopyByteString
- Return ASCII byte string from lowercase to uppercase ... toUpperByteString
- Duplicate and return ASCII byte string while converting from uppercase to lowercase ... toLowerCopyByteString
- Return ASCII byte string from uppercase to lowercase ... toLowerByteString
- Converts a hexadecimal ASCII byte string up to 2 digits to a numerical value and returns it as an unsigned char type value ... toCharHexByteString
- Converts a hexadecimal ASCII byte string up to 4 digits to a numerical value and returns it as an unsigned short type value ... toShortHexByteString
- Converts a hexadecimal ASCII byte string up to 8 digits to a numerical value and returns it as an unsigned long type value ... toLongHexByteString
- Duplicate byte string ... copyByteString

Please see the following page for details. (* Japanese only.)

[tmct](https://ss1.xrea.com/tmct.s1009.xrea.com/doc/ta-ja-7e5g05.html)
