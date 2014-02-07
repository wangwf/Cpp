
//??
double findMedianSortedArrays(int A[], int m, int B[], int n){
  if(m==2 && n==2)
    return max(A[0], B[0]) + min(A[1],B[1])/2;

  double medianA=A[m/2];
  double medianB=B[n/2];

  if (medianA == medianB) return medianA;
  else if(medianA>medianB){
    findMedianSortedArrays(A, m/2, B+n/2, n/2);
  }
  else {
    findMedianSortedArrays(A+m/2, m/2, B,n/2);
  }
}


findMedianSortedArrays(int A[], int m, int B[], int n){

  int *a = new int[n+m];

}


double findKth(int a[], int m, int b[], int n, int k){
  //
  if (m>n) return findKth(b,n, a,m, k);
  if (m==0) return b[k-1];

  if(k==1) return min(a[0], b[0]);

  //divid k into two parts
  int pa=min(k/2, m), pb=k-pa;
  if(a[pa-1]<b[pb-1])
    return findKth(a+pa, m-pa, b, n, k-pa);
  else if (a[pa-1]>b[pb-1])
    return findKth(a, m, b+pb, n-pb, k-pb);
  else 
    return a[pa-1];
}

double findMedianSortedArrays(int A[], int m, int B[], int n){

  int total=m+n;
  if(total&0x1)
    return findKth(A,m,B,n, total/2 +1); 
  else
    return (findKth(A, m, B, n, total/2)
	    + findKth(A,m,B,n,total/2+1))/2;

}
