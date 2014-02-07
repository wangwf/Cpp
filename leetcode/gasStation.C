/*


 */

int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
  int tank=0, sum=0, pos=0;
  int n=gas.size();

  for(int i=0; i<gas.size(); i++){
    tank += gas[i]-cost[i];
    sum +=gas[i] -cost[i];
    if(tank<0){
      tank=0;
      pos=i+1;
    }
  }

  return sum<0? -1: pos%gas.size();
}
