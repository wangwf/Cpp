/*
 *
 */

#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>

using namespace std; 


//template <typename Type>
class myDataBase
{
  private:
  vector<double> myData; 

  public:
  myDataBase(const vector<double>&); 
  ~myDataBase();  // lated try virtual constructor/

  void dataGenerator(const double mean, const double sigma,const int length); 
  void dataGenerator(const int max, const int length); 
  double getSum(); 
  double getMean(); 
  double getRMS(); 

  void  printData(); 

}; 

//Constructor
myDataBase::myDataBase(const vector<double>& inputData){

  if(inputData.size()<=0){cout<<" Warning Data size\n"; }
  myData= inputData; 
}
 
//Destructor
myDataBase::~myDataBase(){
  cout<<"*** Destructor of myDataBase \n"; 
}

//generator random values 
void myDataBase::dataGenerator(const int max,  const int length)
{

 srand ( time(NULL) );
  vector<double> *newVec =new vector<double>; 
  for(int i=0; i<length; i++){newVec->push_back(rand()%max +1.0);   }
  myData=*newVec; 
  
}
void myDataBase::dataGenerator(const double mean, const double sigma, const int length)
{
  vector<double> *newVec =new vector<double>; 
// for(int i=0; i<length; i++){(*newVec).push_back (rand()%max);   }
  myData =*newVec; 
}


double myDataBase::getSum(){
  //   double sum=0.0; 
  // for(int i=0; i<myData.size(); i++) sum +=myData.at(i); 
  // return sum; 

  //  Can  accumlate from <numberical>
      double init = 0.0; 
      return accumulate(myData.begin(), myData.end(), init); 
}

double myDataBase::getMean(){
  return getSum()/myData.size();  
}

double myDataBase::getRMS(){
  //vector inner product
  double init=0.0; 
  double meanSq = inner_product(myData.begin(), myData.end(), myData.begin(), init);
  meanSq /= myData.size(); 
  double mean = getMean(); 
  //  cout<<" meansq "<<meanSq<<" "<<mean<<endl; 
  return sqrt(meanSq- mean*mean);  
}

//template <class type>
void myDataBase::printData(){
  for( vector<double>::iterator i=myData.begin(); i!=myData.end(); i++)
    cout<<*i<<endl; 

  cout<<" Sum "<<getSum()<<endl; 
  cout<<" mean "<<getMean()<<endl; 
  cout<<" RMS  "<<getRMS()<<endl; 
}

class myDataClass : public myDataBase
{ 
public:
  myDataClass(); 
  ~myDataClass();  // lated try virtual constructor/

  double gaussian(double x, const double mean, const double sigma, const double norm);
  double getChiSq(); 
}; 

double myDataClass::gaussian(double x, const double mean, const double sigma, const double norm){
  double pi=3.1415; 
  return norm/sqrt(2*pi*sigma)*exp( -0.5*(x-mean)*(x-mean)/sigma/sigma); 
}

double myDataClass::getChiSq(){

  double mean =getMean(); 
  double sigma=getRMS();
  double norm =getSum(); 

  //  for(int i=0; i<nBins; i++){
  //    chisq += (xx[i] - gaussian())**2/err[i]; 
  //  }  
}

int main(){
  
  //  vector<double> *vect1=new vector<double>(4,2.0); 
  vector<double> vect1(4,2.0); 

  myDataBase D1(vect1); 

  D1.printData(); 

  cout<<" random number generator \n"; 
  D1.dataGenerator(100,5); 
  D1.printData(); 

  return 0; 
}

