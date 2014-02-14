
//Quick select, Kth element or the first K element

void swap(int a[], int i, int j){
  int tmp=a[i];
  int a[i]=a[j];
  int a[j]=tmp;
}

int selectKth(int *arr, int n, int kth){
  if(!arr || kth>n) return 0;

  int start=0, end = n-1;

  while(start<end){
    int r=start, w=end;
    int mid = r + (w-r)/2;

    while(r<w){
      if(arr[r] >= arr[mid]){ //

      }
    }}}


int partition(int * arr, int n, int start, int end){
  int pivot = arr[r];

  while(start<end){
    while(arr[start] < pivot) start++; //
    while(arr[end] > pivot) end--;

    if(arr[start]==pivot) start++;
    else swap(a, start, end);
  }
  return r;
}

int quick_select(int *arr, int n, int start, int end, int kth){
  if(!arr || kth>n) return 0;

  if(start==end)return arr[p];

  int j=partition(arr, n, start, end);

  int length=j-start+1;
  if(length == kth) return arr[j];
  else if(length<kth)return quick_select(arr, n, j+1, end, kth-length);
  else return quick_select(arr, n, start, j-1, kth);
}
