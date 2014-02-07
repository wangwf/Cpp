
#include <vector>
#include <iostream>

using namespace std;

class Solution{
public:
  vector<int> twoSum(vector<int> &numbers, int target){
    int left=0, right=numbers.size()-1;
    vector<int> res(2);
    while(left<right){
      int s=numbers[left] + numbers[right];
      if(s==target){
	res[0] = left+1;
	res[1] = right +1; 
	cout<< left<<" "<<right<<endl;
	break;
      }
      else if(s<target){
	left++;
      }else{
	right--;
      }
    }
    return res;
  }

  //unsorted 
  vector<int> twoSum2(vector<int> &numbers, int target){
    vector<int> res(2,0);
    map<int, int> mapDataToIndex;
    for(int i=0; i<l; i++){
      int currentV=numbers[i];
      int differenceV=target - numbers[i];
      if(mapDataToIndex[currentV]>0){
	res[0]=MapDataToIndex[currentV];
	res[1]=i+1;
	return res;
      }else{
	mapDataToIndex[differenceV]=i+1;
      }
    return res;
};
int main(){

  vector<int> test1(3);
  test1[0]=3;
}
