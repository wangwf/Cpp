//
//check point in cross
//  Q:  there is n points in boundary, to check any point in cross or not?
//  choose any convenient coordinate.
//    =>  length of cross is 3(n-1); 
//    =>  short side  is (n-1)
///* if n=1, 2, see below for illustration
//
//      *       * *             
//     ***    * * * *
//      *     * * * *
//              * *
// Wenfeng.Wang@yahoo.com    05/20/2012
/////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <math.h>

using namespace std; 

// choose the center of cross as (0,0), 
// then change int to double, (0.5,0.5) should allowed
bool inCross(double x, double y, int n){
  if(n<=0)return false; 
  double shortSide = n-1; 
  double longSide  = 3*(n-1); 

  if(n==1){ shortSide=0; longSide=2; }

  shortSide /=2.0; 
  longSide /=2.0; 

  if(fabs(x)<= shortSide && fabs(y)<= longSide) return true; 
  if(fabs(y)<= shortSide && fabs(x)<= longSide) return true; 
  return false; 
}

// Choose (0,0) at lelt-bottom, all inCross points with (x,y)>=0, <=3*(n-1)
 bool inCross2(int x, int y, int n)
{
  if (n<=0) return false; 
  int shortSide=n-1;
  int longSide=3*(n-1); 
  if(n==1) {shortSide=0; longSide=2;}

  //remove all points out of the large box
  if(x> longSide || y > longSide) return false; 

  //remove four small corner box
  if(x<shortSide && y<shortSide) return false; 
  if(x<shortSide && y> 2*shortSide) return false; 
  if(x>2*shortSide && y< shortSide) return false; 
  if(x>2*shortSide && y> 2*shortSide) return false; 

  return true; 

}

int main(){

  //test case- n=1; 
  cout<<"test case ( 1, 1) in n=1: "<<inCross( 1, 1, 1)<<endl; 
  cout<<"test case (-1, 1) in n=1: "<<inCross(-1, 1, 1)<<endl; 
  cout<<"test case ( 1,-1) in n=1: "<<inCross( 1,-1, 1)<<endl; 
  cout<<"test case ( 1, 0) in n=1: "<<inCross( 1, 0, 1)<<endl; 
  cout<<"test case ( 1,-2) in n=1: "<<inCross( 1,-2, 1)<<endl; 

  //test case n=2
  cout<<"test case ( 0.5,-1) in n=2: "<<inCross( 0.5,-1, 2)<<endl; 
  cout<<"test case ( 0.5, 1) in n=2: "<<inCross( 0.5, 1, 2)<<endl; 
  cout<<"test case (-0.5, 1) in n=2: "<<inCross(-0.5, 1, 2)<<endl; 
  cout<<"test case (-0.5,-1) in n=2: "<<inCross(-0.5,-1, 2)<<endl; 


  return 0; 

}
