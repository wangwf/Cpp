// quick sort algorithms in video of Design and algorithm 
//
// to compute the number of comparisons by quicksort, using algorithms from video
#include <iostream>
#include <fstream>

using namespace std;

void swap(int& a, int& b){
  int temp=a;
  a=b;
  b=temp;
}


int nComparison=0; //total number of comparison
int nComparison1=0;

int ChoosePivot(int* A, int start, int stop){

  int Method=2;
  switch (Method)
    {
    case 0: return start;
    case 1: return stop;
    case 2:
      int Median = (int)((start + stop) / 2);
      //      int Median = (stop - start )/2 + start;
      int xmax = max(A[start], max(A[Median],A[stop]));
      int xmin = min(A[start], min(A[Median],A[stop]));
      if( A[start]> xmin && A[start]< xmax)return start;
      if( A[stop] > xmin && A[stop] < xmax)return stop;
      return Median;


    }

}

int partition(int* array, int start, int stop, int pivotIndex)
{


  //       cout<<" "<< start<<" "<<middleIndex<<" "<<stop<<" "<<pivotIndex<<"   "<<array[start]<<" "<<array[stop]<<" "<< array[middleIndex]<<" "<<array[pivotIndex]<<endl; 

    int pivot=array[pivotIndex];
    if(pivotIndex > start) swap( array[start], array[pivotIndex]);

    int i=start+1;
    for(int j=i; j<=stop; j++){
      nComparison1++;
      if(array[j]<pivot){
	swap(array[i], array[j]);
	i++;
      }
    }
    if( start != i)
      {
	swap(array[start], array[i-1]); 
	return i-1; 
      }
    else return start; 
}

void PrintArray(int* array, int n);

void quickSort(int* array, int start, int stop)
{


  if(stop>start){

    //   cout <<" "<<start<<" "<<stop<<" ";  PrintArray(array, 10);
    int splitPoint = ChoosePivot(array, start, stop);
    nComparison += (stop-start);  // total length -1; 
   //     cout<<" com "<<nComparison<<"  "<< (stop-start)<<" "<<start<<" "<<stop <<endl; 

     splitPoint = partition(array, start, stop, splitPoint ); 
    if(splitPoint>start) quickSort(array, start, splitPoint-1); 
    if(stop>splitPoint)  quickSort(array, splitPoint+1, stop); 
  } 



}



int main(){
 
  int ARRAY_SIZE= 10000; 
  int array[ARRAY_SIZE]; 

  //  srand(time(NULL));   for(int i=0; i<ARRAY_SIZE; i++) array[i]=rand()%ARRAY_SIZE+1; 
  ifstream fin("QuickSort.txt"); 
  
  for(int i=0; i<ARRAY_SIZE; i++){  fin>>array[i]; }
  cout<<" end of reading "<<array[0]<<" "<<array[ARRAY_SIZE -1]<<endl; 

  fin.close(); 

  cout<<endl<<"The list you input is : "<<endl;
  //  PrintArray(array, ARRAY_SIZE);

  quickSort(array,0,ARRAY_SIZE - 1);              //sort array from first to last element
 
  cout<<endl<<"The list has been sorted, now it is : "<<endl;
     PrintArray(array, ARRAY_SIZE);

  cout<<" total Comparison "<<nComparison<<" "<<nComparison<<endl; 


  return 0; 

}



void PrintArray(int* array, int n)
{
    int i;
      
    for( i = 0; i < n; i++) {
      cout<<array[i]<<'\t';
      if(i%10==0)cout<<endl; 
    }
    cout<<endl; 
}
