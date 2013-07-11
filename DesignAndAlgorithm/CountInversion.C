// counting the inversion of array

#include <iostream>
#include <fstream>
#include <time.h>

using namespace std; 


//two loop solution
unsigned long int getInvCount(int* array, const int& n){

  unsigned long int inv_count=0; 

  //   for(int i=0; i<n; i++) cout<<array[i]<<" ";  cout<<endl; 

  for( int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      if(array[i]>array[j]) inv_count++; 
      //      cout<<"       "<<i<<j<<" "<<array[i]<<" "<<array[j]<<" "<< inv_count<<endl; 
    }
    //    cout<<" "<<i<<" "<<inv_count<<endl; 
  }
  return inv_count; 
}

void swap(int& a, int& b){
  int temp=a; 
  a=b; 
  b=temp; 
}

//??? some problem in the countInversion method 
//

unsigned long int countSplitInversion(int* array, const int& iStart, const int& iSplit, const int& iEnd){

   unsigned long int numInvers=0; 

   int iLeft=iStart, iRight=iSplit+1,  length=iEnd - iStart +1; 
   if(length==1) return 0; 

   int *temp=new int[length];
   //   cout<<" temp "<<length;  for(int i=0; i<length; i++) cout<<"  "<<temp[i]; cout<<endl; 
   int l_finish=0, r_finish=0; 
   //    cout<<" Split "<< iStart<<" "<<iSplit<<" "<<iEnd<<endl; 

   for(int i=0; i< length; i++){
     //       cout<<"------- "<<array[iLeft]<<" "<<array[iRight]<<"     "<< iLeft<<" "<<iRight<<endl;  
       if( (array[iLeft]<=array[iRight] && !l_finish) || (r_finish && !l_finish))
      {
	temp[i]= array[iLeft];
	if(iLeft==iSplit)l_finish=1; 
	else iLeft++;
      }
       else if( (array[iLeft]>array[iRight] && !r_finish) || (l_finish && !r_finish))
      {
	if(!l_finish)
		  numInvers += iSplit-iLeft+1 ; // If left side large, then all left side is larger
	//numInvers++; 
	temp[i]=array[iRight];	  
	if(iRight==iEnd)r_finish=1;  
	else iRight++; 

      }

       //        cout<<" numIn "<<numInvers<<endl; 
  }
  
   for(int i=0; i<length; i++){ array[iStart+i] = temp[i];   }
   //    for(int i=0; i<5; i++) cout<<array[i]<<" ";  cout<<endl; 

  delete[] temp; 
  return numInvers; 

}
/*
int countSplitInversion(int* array, const int& iStart, const int& iSplit, const int& iEnd){

  int numInvers=0; 

  int iLeft=iStart, iRight=iSplit+1,  length=iEnd - iStart +1; 


  for(int i=0; i< length; i++){

    if(array[iLeft]<=array[iRight]){
      if(iLeft<iSplit)iLeft++; 
    }
    else{
      swap(array[iLeft], array[iRight]); 
      numInvers += iEnd-iRight+1 ; 
      if(iRight<iEnd)iRight++;
    }
  }
  for(int i=0; i<5; i++) cout<<array[i]<<" ";  cout<<endl; 

  return numInvers; 
}

*/

unsigned long int countInversion(int* array, const int& iStart, const int& iEnd){

  int length = iEnd - iStart +1; 
  if(length<=0){    std::cout<<" Input wrong"; return -1;   }
  if(length==1) return 0; 

  //    cout<<" length "<<iStart<<" "<<iEnd<<endl; 
  int imiddle = iStart+ length/2-1; 
  unsigned long int n1 = countInversion( array, iStart, imiddle); 
  unsigned long int n2 = countInversion( array, imiddle+1, iEnd); 
  unsigned long int n3 = countSplitInversion( array,iStart,imiddle, iEnd); 

  //      cout<<" counting "<< iStart<<" "<< iEnd<<"   "<<n1<<" "<<n2<<" "<<n3<<endl; 
    return (n1+n2+n3); 

}





int main(){

  
  std::fstream fin("IntegerArray.txt"); 
  int array_size=  100000;  
  int* array = new int[array_size]; 

  cout<<"reading array..."<<endl; 
  for(int i=0; i<array_size; i++){
    int temp;
    fin>>temp; 
    array[i]=temp; 
  }
  fin.close(); 
  cout<<" end of reading array. "<<endl; 

  cout<<" temp "<<array[0]<<" "<<array[array_size-1]<<endl; 


  time_t time3=time(NULL); 
  cout<<" answer( O(n^2) ) = "<<getInvCount(array, array_size)<<endl; 
  time_t time4=time(NULL);  cout<<"  time "<<difftime(time4,time3)<<endl; 
 
  cout<<" recursive "<<endl;
  time_t time1=time(NULL); 
  unsigned long int numInver=countInversion(array,0,array_size-1); 
  time_t time2=time(NULL); 
  cout<<" answer = "<<numInver<< "    "<< difftime(time2,time1)<<endl; 

  
  cout<<endl<<endl;

  int arr[]={20,6,4,5,1}; 
  cout<<" another test "<<getInvCount(arr,5)<<endl; 
  cout<<"              "<<countInversion(arr,0, 4)<<endl; 

  return 0; 
}
