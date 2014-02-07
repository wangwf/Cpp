/*
 * section sorting, example in Progamming Abstraction, lecture 14-15
 */

#include <iostream>
#include <vector>
using namespace std; 

/*
template <typename Type>
void swap(Type& a, Type& b){
  Type tmp=a; 
  a=b; 
  b=tmp; 
}
*/

vector<int> generatRand(const int& n, const int& n1, const int& nn)
{
  srand( time(NULL)); 
  vector<int> *nV=new vector<int>; 
  int nx=nn-n1; 
  cout<<" Generating vector: "<<n<<endl; 
  for(int i=0; i<n; i++){
       int nrand=rand()%nx + n1; 
       nV->push_back(nrand); 
       //       nV[i]=nrand; 
  }

  //  for(int i=0; i<nV.size(); i++)cout<<" "<<nV[i]; cout<<endl; 


  return *nV; 

}


void PrintVector(vector<int>& v){

  cout<<"Print Vector "<<endl; 
  for(int i=0; i<v.size(); i++)cout<<" "<<v[i]; cout<<endl; 
}

void selectionSort(vector<int>& v){

  if(v.size()==0)return; 

  for (int i=0; i<v.size(); i++){
    int minIndex=i; 
    for (int j=i+1; j<v.size(); j++)
      if(v[j]<v[minIndex]) minIndex=j; 
    
    //    cout<<" "<<i<<" "<<minIndex<<endl; 

    swap(v[i],v[minIndex]); 
  }

  //  for(int i=0; i<v.size(); i++)cout<<" "<<v[i]; cout<<endl;   
}

void InsertionSort(vector<int>& v){

  if(v.size()==0)return; 
  for(int i=1; i<v.size(); i++){
    int cur= v[i]; 
    //    cout<<" i=  "<<i<<" "<<cur<<" "<<i-1<<endl; 

    int j=i-1; 
    for( j=i-1; j>=0&&v[j]>cur; j--){
      v[j+1]=v[j];  
    }
    //    cout<<"j+1 "<<j+1<<" "<<cur<<endl; 
    v[j+1]=cur; 

    //    for(int i=0; i<v.size(); i++)cout<<" "<<v[i]; cout<<endl;   
  }

}

//
// divide and conquer method
// rescursively 
int partition1(vector<int>&array, int start, int stop){
  int lh=start+1, rh=stop; 

  int pivot =array[start];
  while(true){
    while(lh<rh && array[lh]< pivot)lh++; 
    while(lh<rh && array[rh]>=pivot)rh--; 
    if(lh==rh)break; 
    swap(array[lh],array[rh]); 
  }
  if(array[lh]>=pivot)return start; 
  swap(array[lh],array[start]); 
}

void quickSort1(vector<int>& arr, int start, int stop){

  if(stop>start){
    int splitPoint = partition1(arr, start, stop); 
    quickSort1(arr, start, splitPoint-1); 
    quickSort1(arr, splitPoint+1, stop); 
    
  }

}

//another implementation of quicksort algorithm
int Partition(vector<int> &arr, int pivot, int  start,  int stop){

  int lh = start, rh=stop; 
  //  if(stop=start+1)return start; 

  while(lh<rh){
    while(lh<rh&&arr[rh]> pivot)rh--; 
    swap(arr[lh],arr[rh]); 
    while(lh<rh&&arr[lh]<=pivot)lh++;  
    swap(arr[lh],arr[rh]); 
    //    if(lh>=rh) break; 
    //   cout<<" lr "<<lh<<" "<<rh<<endl; PrintVector(arr); 
  }
  // //   if(arr[lh]>=pivot) return start; 
  //..  swap(arr[start],arr[lh]); 
  
  return lh; 
}

void quickSort( vector<int> &arr,  int start,  int stop){

  int pivot =arr[start]; 
  int splitPoint; 
  //  cout<<" "<<start<<" "<<stop<<endl; 
  if(stop>start){
    splitPoint= Partition(arr,pivot, start, stop); 
        arr[splitPoint]=pivot; 

    //    cout<<"splitPoint "<<splitPoint<<" "<<start<<" "<<stop<<endl; 
   quickSort(arr, start,splitPoint-1); 
   quickSort(arr, splitPoint+1, stop); 
   }
 
}
/*
vector<int> mergeSort(vector<int>&arr, int start, int stop){

 
  if(stop=start) return arr; 

  vector<int> B, C; 
  int splitPoint =start + (stop-start)/2; 
  B=mergeSort(arr, start, splitPoint); 
  C=mergeSort(arr, splitPoint+1,stop); 
  D=merge(B,C); 
    
  return; 
}
*/
int main(){

  //  int v1[]={7,4,5,2,1};   vector<int> Vv(v1,v1+sizeof(v1)/sizeof(int)); 

  vector<int> vv1=generatRand(10,0,10);
  PrintVector(vv1); 
  //  for(int i=0; i<vv1.size(); i++)cout<<" "<<vv1[i]; cout<<endl; 

  cout<<"size of vector "<<vv1.size()<<endl; 

  cout<<"\n Selection Sort: "; 
  vector<int> vv_s(vv1); selectionSort(vv_s);PrintVector(vv_s);  
  cout<<"\n Insertion Sort: "; 
  vector<int> vv_i(vv1); InsertionSort(vv_i);  PrintVector(vv_i); 
  cout<<"\n QuickSort:      "; 
  vector<int> vv_q(vv1);  quickSort(vv_q, 0, vv_q.size()-1); PrintVector(vv_q); 

  cout<<"\n QuickSort1:      "; 
  vector<int> vv_q1(vv1);  quickSort(vv_q1, 0, vv_q1.size()-1); PrintVector(vv_q1); 

  //  for(int i=0; i<Vv.size(); i++)cout<<" "<<Vv[i]; 
  cout<<endl; 

  return 0; 
  

}
