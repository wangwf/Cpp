

//implement isSubString
char *strStr(char *str, char* target){
  if(!*target) return str;

  char* p1 = (char*)str;
  char* p2 = (char*)target;
  char* p1Adv = (char*) str;
  while(*++p2)p1Adv;

  while(p1Adv){
    char* p1Begin=p1;
    p2 = (char*)target;
    while(*p1 && *p2 && *p1 ==*p2){
      p1++; p2++;
    }
    if(!*p2)return p1Begin;
    p1=p1Begin +1;
    p1Adv++;
  }
  return NULL;
}

bool isRotation(string s1, string s2)
{
  if(s1.size() != s2.size()) return false;
  if(s1.size() ==0) return true;
  
  return strStr(s1+s1, s2);

}
