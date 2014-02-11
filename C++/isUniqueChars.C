//
//
//Find whether a tring contains unique items, the string contains only lower case letters
 
bool isUniqueChars(char* str){
  //assume lower cases
  int checker=0;
  while(*str !='\0'){
    int val = *str - 'a';
    if (checker & (1<<val)) return false; //when some 1 collide with checker
    checker |= 1<<val; // checker will become series of 1's
    str++;
  }
  return true;
}

//Find wether the integer array contains unique numbers. 
//The integer value in array can be negative and also can be 32-bit size
bool isUniqueDigits(int *arr, int size){
  int checks=0;
  for(int i=0; i<size; i++){
    if(check & (1<<arr[i])) return false;
    checker |= 1<< arr[i];
  }
  return true;
}

//remove duplicate
void removeUnique(char *& str){
  int checker =0;
  char* istr = str;
  char* ehead=NUL;
  while(*str != '\0'){
    int val = *str;
    while(*str != '\0' && (check & 1<<val)){
      if(ehead == NULL) ehead = str;
      *str = '\0';
      str++;
      val = *str;
    }
    if(*str == '\0') break;
    check |= 1<<val;
    if(ehead != NULL){
      *ehead = *str;
      *str = '\0';
      ehead++;
    }
    str++;
  }
  str = istr;
}

}

int man(){
  char* mstr = "Hello Wenfeng ";
  bool test = isUniqueChars(mstr);
  return 0;
}
