//algorithms for Closest Pair

#include <iostream>
#include <math.h>
using namespace std; 

struct points{
  double x; 
  double y; 
  //  double r; 
}; 

double dist(const points& p1, const points& p2){

  //  if(!p1  && !p2){
    double dist12= (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
    if (dist12>=0.0)dist12 = sqrt(dist12);  
    else {
      cout<<" Something wrong here "<<endl; 

      cout<<" dist "<<dist12<<" ("<<p1.x<<" "<<p1.y<<")  ("<<p2.x<<" "<<p2.y<<") "<<endl; 
    }
    //      cout<<" dist "<<dist12<<" ("<<p1.x<<" "<<p1.y<<")  ("<<p2.x<<" "<<p2.y<<") "<<endl; 


    return dist12; 
    //  }

}

double min3( const double& a, const double& b, const double& c){

  return min(min(a,b),c); 

}

#define INF 99999999.

// two loop
double TwoLoopsMethod(const points* p1, const int n){

  double temp,  shortest =INF; 
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
     
      temp= dist( p1[i], p1[j] ); 
      if(temp<shortest) shortest=temp; 
		 
    } 
  }

  return shortest; 
}


double closestSplitPair(const points* p1, const int& istart, const int& imiddle, const int& n, double& shortest){
  //  double shortest = INF; 

  if(n<2)return shortest; 

  double temp; 
  for(int i=istart; i<imiddle; i++){
    for(int j=imiddle; j<istart+n; j++){
      temp=dist(p1[i], p1[j]); 
      if(temp<shortest) shortest = temp; 
    }}

  return shortest; 

}



double closestPair(const points* p1, const int& istart, const int& n){

  int imiddle = istart + n/2 ;
  int iend    = istart + n -1;  
  //  cout<<" "<<istart<<" "<< imiddle<<" "<<iend<<"  "<<n<<endl; 

  if(n<=1) return INF; 

  if(n==2) return dist(p1[istart], p1[istart+1]); 


  double s1= closestPair(p1,istart, n/2); 

  double s2= closestPair(p1,imiddle, n-n/2); 

  //  cout<<" s12 "<<s1<<" "<<s2<<endl; 
  double delta = min(s1, s2); // mini distance from previous two recursive calls
  double s3= closestSplitPair(p1, istart, imiddle, n, delta); 

  //    cout<<" "<<istart<<" "<< imiddle<<" "<<iend<<" "<<n<<"    "<<s1<<" "<<s2<<" "<<s3<<" "<<min3(s1,s2,s3)<<endl; 
  return min3(s1, s2, s3); 
}




int main(){


    /* initialize random seed: */
        srand ( time(NULL) );

  int itest=1000, good=0, bad=0; 

  for(int it=0; it<itest; it++){
    int num=100; 
    points* pnew=new points[num];
    
    for(int i=1; i<num; i++){  // generate points (0,100)
      pnew[i].x = rand() % 1000; 
      pnew[i].y = rand() % 1000; 
      //      pnew[i].r = sqrt( pnew[i].x * pnew[i].x + pnew[i].y * pnew[i].y ); 
    }
    
    double dist1 = TwoLoopsMethod(pnew, num); 
    cout<<" shorest distance(1) "<<dist1<<endl; 
    
    double dist2 = closestPair(pnew,0, num); 
    cout<<" shortest distance(2) "<<dist2<<endl; 
    
    if( fabs(dist1-dist2)>0.1){ cout<<" wrong "<<endl; bad++; }
    else {cout<<" good "<<endl; good++; }

    delete[] pnew; 
  }

  cout<<" total test "<<itest<<" : good="<<good<<"  bad="<<bad<<endl; 

  return 0; 

}
