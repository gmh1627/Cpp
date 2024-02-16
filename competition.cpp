#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
using namespace std;
//<<fixed<<setprecision(1)

/*char compressBits(const char* bitString) {
    char result = 0;
    for (int i = 0; i < 8; ++i) {
        result <<= 1;
        if (bitString[i] == '1') {
            result |= 1;
        }
    }
    return result;
}

int main() {
    const char* bitString = "11001010";
    char compressedChar = compressBits(bitString);
    printf("Compressed char: %d\n", compressedChar);
    return 0;
}*/
#include <stdio.h>

void asciiToBinary(int ascii) {
    for (int i = 7; i >= 0; --i) {
        int bit = (ascii >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main() {
    char character = 'A';
    int asciiValue = (int)character; // 获取字符的ASCII码
    printf("ASCII Value: %d\n", asciiValue);
    printf("Binary Representation: ");
    asciiToBinary(asciiValue); // 将ASCII码转换为二进制
    return 0;
}
