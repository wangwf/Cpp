#include <iostream>
 
using namespace std; 
 
void print2( char** mat, const int& width, const int& height, int r1, int r2, int l1, int l2); 

void print1(char** mat, const int& width, const int& height, int r1, int r2, int l1, int l2 )
{
  if(width<1 || height<1) return; 
 
 
  //print top row
  for(int i=r1; i<=r2; i++) cout<< mat[i][l1]<<" "; 
   
  //print right col
  for(int j=l1+1; j<=l2; j++) cout<<mat[r2][j]<<" "; 
   
  //
  if(r1<r2 &&l1<l2)
    print2(mat, width, height, r1, r2-1, l1+1, l2); 
}
 
void print2( char** mat, const int& width, const int& height, int r1, int r2, int l1, int l2){
  if(width<1 && height<1) return; 
    
  //print bottom row
  for(int i=r2; i>=r1; i--) cout<< mat[i][l2]<<" "; 
    
  //print left col
  for(int j=l2; j>=l1; j--) cout<< mat[r1][j]<<" "; 
    
  //
  if(r1<r2&&l1<l2)
    print1(mat, width, height, r1+1, r2, l1, l2-1); 
}


int main(){
    
//print spiral ordering
//print1(mat, width, height, 0, width-1, 0, height-1); 
    
 return 0; 
}

