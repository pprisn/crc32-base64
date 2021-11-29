#include <string>

std::string rawData( std::string txt );
typedef unsigned int int32;
std::string crc32IEEE( std::string txt );
int32 reflect(int32 data, int bits);
int32 crc32(char* msg, int len);
