/*
 * queue
 */
#include <iostream>
#include <queue>
#include <string>

#include <deque>

using namespace std; 



void Tqueue(){

  queue<string> waitingList; 
 
  while(true){
    cout<<"?"; 
    string name; 
    getline(cin,name); 
    if(name=="")break; 
    else if(name=="next"){
      if(waitingList.empty()){
	cout<<" No one is waiting. \n"; 
	break; 
      }
      else {
	cout<<" handle "<< waitingList.front()<<endl; 
	waitingList.pop(); 
      }
    }
    else {
      cout<<" Add "<<endl; 
      waitingList.push(name); 
    }

  }



}


void test_deque(){
  deque<int> mydeque(10); 
  unsigned int i; 
  deque<int>::size_type sz=mydeque.size(); 

  for(i=0; i<sz; i++)mydeque[i]=i; 

  for(i=0; i<sz/2; i++)
    {
      int temp=mydeque[sz-1-i]; 
      mydeque[sz-1-i]= mydeque[i]; 
      mydeque[i]=temp; 
    }
  cout<<"mydeque contains: "; 
  for(i=0; i<sz; i++)
    cout<<" "<<mydeque[i]; 
  cout<<endl; 

}

int main(){

  //
  test_deque(); 

  return 0; 
}
