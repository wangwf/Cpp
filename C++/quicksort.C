

void quickSort(int arr[], int n, int left, int right){
  int i=left, j=right;

  int m = i + (j-i)/2;
  int pivot = arr[m];

  while(i<=j){
    while(arr[i] < arr[pivot]) i++;
    while(arr[j] > arr[pivot]) j--;

    if(arr[i] == arr[pivot]) i++;
    else{
      int t=arr[i];
      arr[i]=arr[j];
      arr[j]=t;
      i++;
      j--;
    }
  }

  if(left<j) quickSort(arr, n, left, j);

  if(i<right) quickSort(arr, n, j, right);
}
