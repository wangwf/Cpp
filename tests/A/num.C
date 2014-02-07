//
// integer list


//  [8,9,9] +1 => 900


int listAdd(list<int> l1, int a)
{
  //change list to integer

  int num=0; 
  for(int i=0; i<l1.size(); i++)
    {
      num = num*10 + li.at(i); 
    }

  return num+a; 
}

//leetcode plusOne solution

//Given a number represented as array of digits, plus one to the number
vector<int> plusOne(vector<int> &digits){
  int i;
  for(i=digits.size()-1; i>=0; i--){
    if(digits[i] !=9){
      ++digits[i];
      return digits;
    }else digits[0]=0;
  }
  if(i<0) digits.insert(digits.begin(), 1);
  return digits;
}
