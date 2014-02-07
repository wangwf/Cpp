//
// top N-selection problem
//
//1. find maximum top 1000 from 1billion element (user-name, user-login-time)
//2. find the median
//
//1. use min-heap of size N (=1000), for each input number k, replace the current min m with max(k,m). Afterward the heap holds the top N inputs.


#include <queue>
#include <vector>
#include <iostream>

// find indices of the k-largest elements in an unsorted length n array
// compile with:
// g++ -std=c++11 maxindices.cc -o maxindices
int topKwithpriority_queue(int k)
{
  std::vector<double> test = {0.2, 1.0, 0.01, 3.0, 0.002, -1.0, -20};
  std::priority_queue<std::pair<double, int>> q; //minheap
  for (int i = 0; i < test.size(); ++i) {
    q.push(std::pair<double, int>(test[i], i));
  }

  //  int k = 5; // number of indices we need
  for (int i = 0; i < k; ++i) {
    int ki = q.top().second;
    std::cout << "index[" << i << "] = " << ki <<"   "<<test[ki]<< std::endl;
    q.pop();
  }
}

#include<vector>
#include<algorithm>
#include<iterator>
#include<ctime>
#include<cstdlib>
// O(n log k)
int RandomNumber(){return rand();}
std::vector<int> find_topk(int arr[], int k, int n)
{
  make_heap(arr, arr + n, std::greater<int>());

  std::vector<int> result(k);

  for(int i=0; i<k; ++i){
    result[i] = arr[0];
    pop_heap(arr, arr + n -i, std::greater<int>());
  }

  return result;
}

std::vector<int> find_topk2(int arr [], int k, int n){
  make_heap(arr, arr + k, std::less<int>());
  for(int i=k; i<n; ++i){
    if(arr[i] < arr[0] ){
      pop_heap(arr, arr + k, std::less<int>());
      arr[k-1] = arr[i];
      push_heap(arr, arr + k, std::less<int>());
    }
  }
  std::vector<int> result(arr, arr+k);

  return result;
}

void  testTopK()
{
   const int n = 220000000;
   const int k = 300;

   srand (time(0));
   int* arr = new int[n];

   std::generate(arr, arr + n, RandomNumber);

   // replace with topk or topk2
   std::vector<int> result = find_topk2(arr, k, n);

   std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, "\n"));

   return;
}


int main(){

  //  topNwithpriority_queue(3);
  testTopK();
  return 0;
}
