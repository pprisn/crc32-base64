// src/crc32.cpp
#include <iostream>
#include <string>
#include "crc32.h"
#include "base64.h"

typedef unsigned int int32;

// key is the crc-32 ieee 802.3 standard polynomial
const int32 poly = 0x04C11DB7;

int32 reflect(int32 data, int bits) {
    int32 ret = 0;
    for(int i = bits-1; i>=0; i--) {
        if(data & 1) ret |= (1 << i);
        data >>= 1;
    }
    return ret;
}

int32 crc32(char* msg, int len) {
    int32 crc = 0xffffffff;
    int i, j;
    for(i = 0; i < len; i++) {
        crc ^= ((char)reflect(msg[i], 8) << 24);
        for(j = 8; j; j--) {
            crc = (crc << 1) ^ ((crc & 0x80000000) ? poly : 0x0);
        }
    }
    return reflect(crc, 32) ^ 0xffffffff;
}

/*
// encodedData - кодированные в base64 данные
*/
std::string crc32IEEE( std::string encodedData ) {
    int32 crc;
    const unsigned long polynom = 0x04C11DB7; //0x0;//0xEDB88320;//
    std::string decoded = base64_decode(encodedData);
    const char *msg = decoded.c_str();
    int32 l = decoded.size();
    crc = crc32((char*)msg, l);
  return std::to_string(crc);
}
