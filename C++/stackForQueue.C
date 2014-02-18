

class myQueue{
  stack<int> inbox;
  stack<int> outbox;
public:
  void enque(int x){inbox.push_back(x);}
  int deque(){
    if(!outbox.empty()){
      while(!inbox.empty()){
	outbox.push_back(inbox.top());
	inbox.pop();
      }
    }
    int tmp=outbox.top(); outbox.pop();
    return tmp;
  }
}

//using only one stack, the second stack use recursive

  class myQueue1{
    stack<int> inbox;
  public:
    void eque(int x){
      if (inbox.empty()) inbox.push_back(x);
      else{
	int elem =inbox.top(); inbox.pop();
	eque(x);
	inbox.push_back(elem);
      }
    }
    int deque(){
      int x =inbox.top();
      inbox.pop();
    }


