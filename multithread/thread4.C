#include <iostream>
#include <pthread.h>

using namespace std;

void *function1(void* arg1){
  cout<<" Hello ";
  sleep(2);
}

void *function2(void* arg2)
{
  cout<<" World!"<<endl;
}

int main(){

  pthread_t t1,t2;

  pthread_create(&t1,NULL, function1, NULL);
  pthread_create(&t2,NULL, function2, NULL);

  pthread_exit(NULL);

}
