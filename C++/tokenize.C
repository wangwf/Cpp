#include <string>
#include <vector>


vector<string> tokenize(const char* str, char c=' '){
  vector<string> result;
  do{
    while(*str==c)str++; //skip space at begin
    char* p1=str;
    while(*str && str!=c) str++;
    result.push_back( string(p1, str));
  }while( *str != 0);

  return result;
}
