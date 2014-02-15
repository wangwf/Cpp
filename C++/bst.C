
//

//sorted array
int search(int A[], int n, int target){
  if(n<=0) return -1;
  int low=0, high =n-1;
  while(low<=high){
    int mid = low + (high-low)/2;
    if(A[mid] == target) return mid;
    if(A[mid]>target) high = mid-1;
    else low  = mid+1;
  }
  return -1;
}

//sorted array, with duplicated

int searchFirst(int A[], int n, int target){
  if(n<=0) return -1;
  int low=0, high=n-1;
  while(low<high){
    int mid=low + ((high-low)>>1);
    if(target> A[mid])low =mid+1;
    //    else if(target<A[mid]) high=mid-1;
    else high=mid;
  }

  if(A[low] != target) return -1;
  return low;
}

//sorted array, with duplicate, output last one
int searchLast(int A[], int n, int target){
  if(n<=0) return -1;
  int low=0, high =n-1;
  while(low<high){
    int mid= low + (high-low)/2;
    if(target > A[mid]) low = mid+1;
    else if(target<A[mid]) high = mid-1;
    else low=mid;
  }
  if(A[high] != target) return -1;
  return high;
}


//sorted, duplicates, output the largest one <target
int searchLastPosLessThan(int A[], int n, int target){
  if(n<=0) return -1;
  int low=0, high = n-1;
  while(low<high){
    int mid = low + (high - low)/2;
    if(A[mid]>target) high=mid-1;
    else low=mid; //A[mid] <= target
  }
  if(A[high] != target) return -1;
  return high;
}

//sorted, duplicated, count the duplicated

int count(int A[], int n, int target){
  if(n<=0) return -1;
  int low=0, high = n-1;
  int firstPos=searchFirst(A, n, target);
  if(firstPost == -1) return 0;
  int lastPos =searchLast(A, n, target);
  return lastPost - firstPos +1;
}

//rotated array, no duplicated
int searchRotatedArray(int A[], int n){
  if(n==1) return 0;
  int low=0, high=n-1;
  while(low < high-1) // for mid !=low && mid !=high
    {
      int mid = low + (high - low)/2;
      if(A[mid] <A[low]) // mini-point here
        { high=mid;        }
      else
        low=mid;
    }
  return A[low] <A[low+1] ? low : low+1;
}
