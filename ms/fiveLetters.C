//
// Giving 5 'A' 4'B' 3 'C', total 12 letters,
//     how many 5-letters words can be formed?
//
// Starting from the simplest case: 5 'A', 5 'B' and 5 'C', total 15 letters
//    => pow(3,5)=243
//  5B ('BBBBB')  is missing,  => -1
//  5C ('CCCCC')  is missing,  => -1
//  A4C ('ACCCC' ...)           => -5
//  B4C ('BCCCC'....)           => -5
// 
// Answer is  243 -12 =231 unique 5-letters words from 
//
//  Below give one code testing the above answer using set<string>
//
//  Wenfeng.Wang@yahoo.com   05/20/2012
/////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std; 

void swap(string& s, string& t){
  string tt=s; 
  s=t; 
  t=tt; 
}

void checkPerm1(string s){

 
  vector<string> v1; // total permutation
  set<string> set1;  // distinguish permuation

  if(s.size()<=0) return; 
  //  string s="aaaaabbbbccc"; // 5A+4B+3C
  //  cout<<"s "<<s.size()<<endl; 

   for(int i0=0; i0<s.size(); i0++) {
    string s0=s; 
    string t; 
    t.append(s0,i0,1);  s0.erase(i0,1); 

    //    cout<<"0 "<<s<<"  "<<t<<endl; 
     for(int i1=0;i1<s0.size(); i1++) {
       string s1=s0; 
       t.append(s1,i1,1);  s1.erase(i1,1); 

       //       cout<<"1 "<<s<<endl; 
       for(int i2=0;i2<s1.size(); i2++) {
	 string s2=s1; 
	 t.append(s2,i2,1);  s2.erase(i2,1); 

	 //         cout<<"2 "<<s<<endl; 
	 for(int i3=0;i3<s2.size(); i3++) {
	   string s3=s2; 
	   t.append(s3,i3,1);  s3.erase(i3,1); 

	   //	   cout<<"3 "<<s3<<endl; 
	   for(int i4=0;i4<s3.size(); i4++) {
	     string s4=s3; 
	     t.append(s4,i4,1);  s4.erase(i4,1); 

	    set1.insert(t); 
	    v1.push_back(t); 
	    //	    cout<<" t "<<t<<" "<<s.size()<<endl; 
	    t.erase(4,1);
	  }
           t.erase(3,1); 
	 }
	 t.erase(2,1);
       }
       t.erase(1,1); 
     }
     t.erase(0,1);
  }


   cout<<"Total 5-letter words : "<<v1.size()<<endl; 
   cout<<"Unique 5-letter words: "<<set1.size()<<endl; 

}

//using next_permutation and substr
void  checkPerm2(string s){

  vector<string> v1; 
  set<string> set1; 

  sort(s.begin(), s.end()); 
  do{
    //    cout<<s<<endl; 
    string str=s.substr(0,5); 
    v1.push_back(str); 
    set1.insert(str); 
  }while(next_permutation(s.begin(),s.end())); 
	 
  cout<<"Total 5-letter words : "<<v1.size()<<endl; 
  cout<<"Unique 5-letter words: "<<set1.size()<<endl; 	 
}

int main(){

  string s1="aaaaa"; 
  string s2="bbbb"; 
  string s3="ccc"; 
  string s=s1+s2+s3; 

  checkPerm1(s); 

  checkPerm2(s); 
   return 0; 
}
