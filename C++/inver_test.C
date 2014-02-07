/*
 * test recursion example : exponential function
 */
#include <iostream>

using namespace std; 

int merge(const int* a, const int* b, int *c){

  int i=1; 
  int j=1; 
  for (int k=1; k<n; k++){
    if( a[i]<b[j]){
      c[k]=a[i]; i++; 
    }
    else {
      c[k]=b[i]; j++; 
    }


  }


}



double baseFunction(const double& base,  int *n){
  //  int n1 =*n; 
  if((*n)==0) return 1; 
  else{
    (*n)--; 
    return base*baseFunction(base, n); 
  }
}

// when non-constant int&, expect change in code
double baseFunction(const double& base,  int& n){

  if(n==0) return 1; 
  else{
    n--; 
    return base*baseFunction(base, n); 
  }
}

double baseFunction(const double& base,  const int& n){

  if(n==0) return 1; 
  else{
    return base*baseFunction(base, n-1); 
  }
}


bool isPalindromes(const string& s){

  if(s.length()<=1)return true; 
  bool test= (s[0]==s[s.length()-1]); 
  test = test&& isPalindromes(s.substr(1,(s.length()-2))); 
  return test; 

}

#include <string>
#include <vector>

//binary search
int BSearch(const vector<string>& s, const int& start, const int& stop, const string& key){

  const int NotFound=-1;
  if(start>stop)return NotFound; 

  int mid=(start+stop)/2; 

  if(key==s[mid]) return mid; 
  else if(key<s[mid])
    return BSearch(s, start, mid-1, key); 
  else if(key>s[mid])
    return BSearch(s, mid+1, stop, key); 


}

// C(n,K)
int Cnk(const int& n, const int& k){

   if(n<k || n<0 || k<0) return -1; 
   //   if(k==0) return 1; 
   //   return n*Cnk(n-1, k-1); // P_(n,k)

   if(k==0 || n==k)return 1; 
   return Cnk(n-1, k) + Cnk(n-1,k-1); 
}




int main(){

  double x=3.;
  int n1=4; 

  //  cin>>x>>n1; 
  cout<<" exponent "<<baseFunction(x, &n1)<<endl; 

  n1=4; 
  cout<<n1<<endl; 
  cout<<" exponent "<<baseFunction(x, n1)<<endl; 
  cout<<n1<<endl; 

  //  string s1="was it a car or a car i saw"; 
  string s1="aawwaa"; 
  cout<<" isPalindromes "<<isPalindromes(s1)<<endl; 

  int n=60, k=2; 
  

  cout<<" "<<Cnk(n,k)<<" "<<Cnk(k,k)<<" "<<Cnk(n,k)/Cnk(k,k) <<endl; 
  return 0; 
}
