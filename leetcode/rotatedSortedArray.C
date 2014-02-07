
#include <iostream>
/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

using namespace std;

// find minimum point
int findSortedRotation(int A[],int n){
  if(n<1) return n;
  int l=0, r=n-1;

  while(A[l]>A[r]){
    int m= l + (r-l)/2;
    if(A[m]>A[r]) l=m+1;
    else r=m;
  }
  return l;
}

//no duplicate
int search(int A[], int n, int target){
  int l=0, r=n-1;
  while(l<=r){
    int m=l + (r-1)/2;
    if(A[m]==target) return m;
    if(A[l]<=A[m]){
      if(target>=A[l]&&A<A[m])
        r=m-1;
      else
        l=m +1;
    }else{
      if(target>A[m] && target<=A[r]) l=m+1;
      else r=m-1;
    }
  }
  return -1;
}


//if duplicated [2,2,2,3,3
   bool searchHelper(int A[], int l, int r, int target){
        if(l>r) return false;
        int m=l+(r-l)/2;
        if(A[m]==target)return true;

        //the right part is sorted
        if(A[m]<A[r]){
            if(target<A[m]|| target>A[r])
                return searchHelper(A, l, m-1, target);
            return searchHelper(A, m+1, r, target);
        }
        //the left part is sorted
        if(A[m]>A[r]){
            if(target>A[m] || target<A[l])
                return searchHelper(A, m+1, r, target);
            return searchHelper(A, l, m-1, target);
        }
        //don't know which part
        bool ret=searchHelper(A, l, m-1,target);
        if(ret)return true;
        else
            return searchHelper(A, m+1, r, target);
    }
    bool search(int A[], int n, int target) {
        if(n<=0) return false;
        return searchHelper(A, 0, n-1, target);
    }
