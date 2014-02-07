#include <vector> 
#include <iostream> 
#include <numeric>   
using namespace std; 
template <class T>
void print(T& c){
   for( typename T::iterator i = c.begin(); i != c.end(); i++ ){
      std::cout << *i << endl;
   }
}

int main() { 

  vector<double> vec1(4, 2.0);  // Length 4, all values == 2.0 
  vector<double> vec2(4, 4.0);  // Length 4, all values == 4.0 

  double init = 0.0; 
  double summation = accumulate (vec1.begin(), vec1.end(), init); 

  cout << "Sum of elements in vec1: " << summation<<" "<<init << endl; 

  double ip = inner_product(vec1.begin(), vec1.end(), vec2.begin(), init); 
  cout << "Inner product of vec1 and vec2: " << ip <<" "<<init<< endl; 

  int size = 6; 
  int seed_value = 2; 
  vector<int> vec3(size, seed_value); 
  vector<int> result(size); 
  partial_sum(vec3.begin(), vec3.end(), result.begin()); 

  cout<<" partial_sum "<<endl; 
  print(result); 

  int sz = 10; 
  int value = 2; 
  vector<int> vec4(sz); 

  vector<int>::iterator it; 
  for (it = vec4.begin(); it != vec4.end(); it++) 
  { 
    (*it) = value; 
    value += 1; 
  } 
  vector<int> result2(vec4.size()); 
  adjacent_difference(vec4.begin(), vec4.end(), result2.begin()); 
  cout << "The adjacent difference of the vector vec4\n"; 

  print(result2); 

  return 0; 
}
