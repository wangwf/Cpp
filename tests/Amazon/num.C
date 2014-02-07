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
