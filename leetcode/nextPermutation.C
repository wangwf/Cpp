
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename It>
bool next_permutation(It begin, It end)
{
  if (begin == end) return false;

  It i=begin;
  ++i;
  if (i == end) return false;

  i = end;
  --i;

  while (true){
    It j = i;
    --i;

    if (*i < *j)
      {
	It k = end;
	while (!(*i < *--k));
	iter_swap(i, k);
	reverse(j, end);
	return true;
      }

    if (i == begin){
      reverse(begin, end);
      return false;
    }
  }
}

//O(1) swap
private void swap(int[] num, int a, int b){
  int temp = num[a];
  num[a]=num[b];
  num[b]=temp;
}

// O(n) -- reverse the array
private void reverse(int[] num, int l, int r){
  while (l<r){
    swqp(num, l++, r--);
  }
}

// O(n)
public void nextPermutation(int[] num){
  //find descending part from right to left
  int cur = num.length-1;
  while (cur >0 && num[cur-1]>= num[cur]) --cur;
  reverse(num, cur, num.length -1);
  if( cur>0){
    //insert cur-1 to the right spot
    int next = cur;
    cur -=1;
    while (num[next] <= num[cur]) ++next;
    swap(num, next, cur);
  }
}
