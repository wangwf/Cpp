// implement a que using stack class


#include <iostream>
#include <stack>

using namespace std; 

template <class myType> 
class myque{

  stack<myType> myStack; 
 
public: 
  //  myque(); 
  //  ~myque(); 

  void enqueue(myType&); 
  myType dequeue(); 
  int isEmpty(){return myStack.empty();}; 


  // better solution using two stacks ?
  // doesnot work well with proceduce: push, pop, push, pop
  myType dequeue2(); // better solution using two stacks 
  stack<myType> myStack2; 

  // method 3: recursive method in enqueue3
  void enqueue3(myType& ); 
  myType dequeue3(){ myType temp=myStack.top(); myStack.pop(); return temp; }; 

}; 


// template function outside the class body, put the template types after the class name.

// push into queue
template <typename myType>
void myque<myType>::enqueue(myType& x){  myStack.push(x); }

//pop out
template <typename myType>
myType myque<myType>::dequeue(){
  stack<myType> tmpStack;  //temporary stack
  myType tmp_num; 

  // move elements into a temporary stack (not the last one)
  while(!myStack.empty()){
    tmp_num= myStack.top(); //
    myStack.pop(); 
    if(!myStack.empty())tmpStack.push(tmp_num);
  }
  
  //move back
  while(!tmpStack.empty()){
    myType tmp1= tmpStack.top(); 
    myStack.push(tmp1); 
    tmpStack.pop(); 
  }

  return tmp_num; 
}

template <typename myType>
myType myque<myType>::dequeue2(){

  if(myStack2.empty()){
    while (!myStack.empty()){ 
      myStack2.push(myStack.top()); myStack.pop(); 
    }
  }

  myType temp= myStack2.top();  myStack2.pop(); 
  return temp; 

}

template <typename myType>
void myque<myType>::enqueue3(myType& x){

  if(myStack.empty()){
    myStack.push(x); 
  }
  else {
    myType temp= myStack.top(); myStack.pop(); 
    enqueue3(x); 
    myStack.push(temp);
  }
}


//test the above code (FIFO); 
int main(){

  myque<int> testque; 

  cout<<"test whether it is FIFO"<<endl; 
  cout<<"Input of myque "<<endl; 
  for(int i=0; i<10; i++){
    testque.enqueue(i); 
    cout<<i<<" "; 
  }
  cout<<endl; 

  cout<<" output of que "<<endl; 
  while(!testque.isEmpty()){ cout<<testque.dequeue()<<" "; }
  cout<<endl; 


  cout<<endl<<endl; 
 cout<<"test Second dequeue method (using two stack)"<<endl; 
  cout<<"Input of myque "<<endl; 
  for(int i=0; i<10; i++){
    testque.enqueue(i); 
    cout<<i<<" "; 
  }
  cout<<endl; 

  cout<<" output of que "<<endl; 
  while(!testque.isEmpty()){ cout<<testque.dequeue()<<" "; }
  cout<<endl; 

  cout<<endl; 
  cout<<"test Third  method (recurived enqueue3)"<<endl; 
  cout<<"Input of myque "<<endl; 
  for(int i=0; i<10; i++){
    testque.enqueue3(i); 
    cout<<i<<" "; 
  }
  cout<<endl; 

  cout<<" output of que "<<endl; 
  while(!testque.isEmpty()){ cout<<testque.dequeue3()<<" "; }
  cout<<endl; 


}
