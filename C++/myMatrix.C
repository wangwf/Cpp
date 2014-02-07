/*////////////////////////////////////////////////////////////
 *
 * Re-write the data analysis in C++ structure
 *                       Wenfeng Wang  01/10/2012
 *  
 */////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>
#include <numeric>
//#include "TMatrixD.h"

using namespace std;

//template <typename T>
typedef vector<double> Vec;
typedef vector<Vec> Mat;

// multiply of vector and matrix
Vec operator*(const Mat &a, const Vec &x){
  int i,j;
  int m = a.size();
  int n = x.size();

  Vec prod(m);

  for(i = 0; i < m; i++){
    prod[i] = 0.;
    for(j = 0; j < n; j++)
      prod[i] += a[i][j]*x[j];
  }
  return prod;
}


Vec operator*(const Vec &a, const Vec &b){
  int i,j;
  int m = a.size();
  int n = b.size();
  if(m !=n ){
    assert(m!=n); 
  }
  Vec prod(m);

  for(i = 0; i < m; i++){
      prod[i] = a[i]*b[i];
  }
  return prod;
}




class myAnalysis
{
private:
  Vec sigData;    // experimental data set
  Vec Error_stat;  // statistic error; 
  Vec Error_syst;  // systematic error; 
  Vec Error_stat_syst;  // systematic error; 
  double Corr[13][13];         // correlation Matrix
  
  double Eff_18;  // efficiency from simulated events
  double Eff_19; 
  double Eff_20; 

  double measuredBF_18; 
  double measuredBFerr_18; 

  double measuredBF_19; 
  double measuredBFerr_19; 
  
  double measuredBF_20; 
  double measuredBFerr_20; 

  double BF_corr[3][3]; 

 public:
  myAnalysis( ); 
  myAnalysis(const Vec&, const Vec&, const Vec&, const Mat& ); 

  ~myAnalysis(); 

  void setData(const double *values, const int& length); 
  void setErrorStat(const double *values, const int& length); 
  void setErrorSyst(const double *values, const int& length); 
  void setErrorStatAndSyst(const int& length); 
  void setCorrelationMatrix(const double values[][13], const int& length); 
  void setEfficiency(const double& eff18, const double& eff19,const double& eff20); 
  void addCommonError(); 
   
  void efficiencyCorretion(const double& Eff); 

  void  computeBF(); 
  void  computeBFerr(); 
  void  computeBFcorrel(); 

  //  double getBF(){return measuredBF; }; 
  //  double getBFerr(){return measuredBFerr; }; 
  //  void getBFCorrelation(); 

  void printResults(); 
}; 

//constructor
myAnalysis::myAnalysis( )
{
  cout<<" Get all DatmyAnalysisa, statistic and systematic error?  If yes Produce the results! \n"; 
  cout<<" please Set up input data, systematic and statistic errors! \n"; 
}

myAnalysis::myAnalysis(const Vec& data1, const Vec& errStat, const Vec& errSyst, const Mat&  mat1)
{

  cout<<" Get all Data, statistic and systematic error?  If yes Produce the results! \n"; 
   
  sigData=data1; 
  Error_stat= errStat; 
  Error_syst= errSyst; 
 
}



myAnalysis::~myAnalysis()
{
  cout<<" Congratulation! The Analysis is Done! \n"; 
}

//input the measured data values 
void myAnalysis::setData(const double *values, const int& length)
{
  assert( values && length>1 );
  cout<<"  Input data set \n"; 
  for(int i=0; i<length; i++){
    //    cout<<i<<" "<< values[i]<<endl; 
    sigData.push_back(values[i]); 
  }
}


void myAnalysis::setErrorStat(const double *values, const int& length)
{
      assert(values&& length>1);        
      cout<<"  Input Statistic Errors. \n"; 
      for(int i=0; i<length; i++){
	//	cout<<i<<" "<< values[i]<<endl; 
	Error_stat.push_back(values[i]); 
      }
}

void myAnalysis::setErrorSyst(const double *values, const int& length)
{
  assert(values && length>1);        
  cout<<"  Input Systematic Errors. \n"; 
  for(int i=0; i<length; i++){
    //   cout<<i<<" "<< values[i]<<endl; 
    Error_syst.push_back(values[i]); 
  }
}

void myAnalysis::setErrorStatAndSyst(const int& length)
{
  assert( length);        
  cout<<"  Combine  Statistic and Systematic Errors. \n"; 
  for(int i=0; i<length; i++){
    double Err_t =sqrt( Error_syst[i]*Error_syst[i]+ 
			Error_syst[i]*Error_syst[i]); 
    //   cout<<" "<<Err_t<<endl; 
    Error_stat_syst.push_back( Err_t ); 
  }
}

//passy 2D array need  ** 
//declaration of 'values' as multidimensional array must have bounds for all dimensions except the first
void myAnalysis::setCorrelationMatrix(const double values[][13], const int& length)
{
  assert(values && length);     
  cout<<"  Input correlation matrix. \n"; 
  for(int i=0; i<length; i++){
    for(int j=0; j<length; j++){
      //      cout<<" "<< values[i][j]<<endl; 
      Corr[i][j]=values[i][j]; 
    }
  }
}


void myAnalysis::setEfficiency(const double& eff18, const double& eff19, const double& eff20){

  cout<<"  Set up the selection efficiency (from simulation Events! \n"; 
  Eff_18= eff18; 
  Eff_19= eff19; 
  Eff_20= eff20; 


}

void myAnalysis::computeBF()
{
  
  cout<<"  Start to compute Branching Fractions. \n"; 
  Vec dataYield(sigData.size()); 
  partial_sum(sigData.begin(), sigData.end(), dataYield.begin()); 

  if(Eff_18<=0.0 || Eff_19<=0.0 || Eff_20<=0.0 ) cout<<" Error! Input Efficiency Wrong! \n"; 

  //  cout<<" Eff "<< Eff_18 <<" "<< Eff_19 <<" "<< Eff_20<<endl; 

  measuredBF_18= dataYield[3]/Eff_18; // from 3 bins
  measuredBF_19= dataYield[4]/Eff_19; // from 4 bins
  measuredBF_20= dataYield[5]/Eff_20; // from 5 bins
}

void myAnalysis::computeBFerr()
{  
  cout<<"  Start to compute uncertainties of Branching Fractions. \n "; 

  double sigma_gt18=0.0,sigma_gt19=0.0, sigma_gt20=0.0; 
  for(int i=3; i<13; i++){
    for(int j=3; j<13; j++){
      //      cout<<" "<<i<<j<<endl; 
      double err_i = Error_stat_syst[i]; 
      double err_j = Error_stat_syst[j]; 
      double rho_ij= Corr[i][j]; 
      //      cout<<" I j "<<i<<" "<<j<<" "<< err_i<<" "<<err_j<<" "<<rho_ij<<endl; 

      sigma_gt18             += rho_ij*err_i*err_j/Eff_18/Eff_18; 
      if(i>3&&j>3)sigma_gt19 += rho_ij*err_i*err_j/Eff_19/Eff_19; 
      if(i>4&&j>4)sigma_gt20 += rho_ij*err_i*err_j/Eff_20/Eff_20; 	   
    }
  }
  //  cout<<" Start to compute uncertainties of Branching Fractions. \n "; 

  sigma_gt18 =sqrt(sigma_gt18 ); 
  sigma_gt19 =sqrt(sigma_gt19 ); 
  sigma_gt20 =sqrt(sigma_gt20 ); 
  
  measuredBFerr_18 =  sigma_gt18; 
  measuredBFerr_19 =  sigma_gt19; 
  measuredBFerr_20 =  sigma_gt20; 

  cout<<" Start to compute uncertainties of Branching Fractions. \n"; 
}

void myAnalysis::computeBFcorrel()
{
 cout<<" Start to compute the correlation matrix of Branching Fractions. \n"; 

  double sigma_gt18 =measuredBFerr_18 ; 
  double sigma_gt19 =measuredBFerr_19 ; 
  double sigma_gt20 =measuredBFerr_20 ; 

  double   sigma_18    = Error_stat_syst[3]/Eff_19; 
  double   sigma_19    = Error_stat_syst[3]/Eff_20;
  double   sigma_18_19 = sqrt(sigma_18 * sigma_18 + sigma_19* sigma_19 + 2 *Corr[3][4]* sigma_18 * sigma_19); 

  //  cout<<" "<<  sigma_gt18 <<" "<<  sigma_gt19<<" "<< sigma_gt20<<endl; 

  double C01= Eff_19/Eff_18; //correction from efficiency differnt
  double C02 =Eff_20/Eff_18; 
  double C12 =Eff_20/Eff_19; 

  double rho01 = (sigma_gt18*sigma_gt18  + sigma_gt19 * sigma_gt19*C01*C01 - sigma_18*sigma_18)/sigma_gt19/sigma_gt18/C01/2.0; 
  double rho02 = (sigma_gt18*sigma_gt18  + sigma_gt20 * sigma_gt20*C02*C02 - sigma_18_19*sigma_18_19)/sigma_gt20/sigma_gt18/C02/2.0; 
  double rho12 = (sigma_gt19*sigma_gt19  + sigma_gt20 * sigma_gt20*C12*C12 - sigma_19*sigma_19)/sigma_gt20/sigma_gt19/C12/2.0; 


  //  cout<< " rho "<<rho01<<" "<<rho02<<" "<<rho12<<endl; 

  BF_corr[0][1]= rho01; 
  BF_corr[0][2]= rho02;
  BF_corr[1][2]= rho12; 

  BF_corr[1][0]= BF_corr[0][1]; 
  BF_corr[2][0]= BF_corr[0][2]; 
  BF_corr[2][1]= BF_corr[1][2]; 
  
  BF_corr[0][0]= 1.00;  
  BF_corr[1][1]= 1.00;  
  BF_corr[2][2]= 1.00;  
 

}

void myAnalysis::printResults()
{

  cout<<"\n"; 
  cout<<" --------Meausred Branching Fraction (yields), with errors. \n"; 
  printf("  BF(>1.8GeV) =  %8.2f +- %8.2f \n",measuredBF_18, measuredBFerr_18);
  printf("  BF(>1.9GeV) =  %8.2f +- %8.2f \n",measuredBF_19, measuredBFerr_19);
  printf("  BF(>2.0GeV) =  %8.2f +- %8.2f \n",measuredBF_20, measuredBFerr_20);
  cout<<" -----------------------------------------------. \n \n"; 

  cout<<" The correlation matrix of BF \n"; 
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      printf("  %6.2f ",BF_corr[i][j]); 
    }
    printf("\n \n"); 
  }
  
}




int main(){


  //correlation matrix 
  double corr[13][13]={
  1.00, 0.75, 0.71, 0.65, 0.58, 0.46, 0.32, 0.16, 0.07, 0.03, 0.01, 0.01, 0.00,
  0.75, 1.00, 0.74, 0.68, 0.61, 0.48, 0.33, 0.17, 0.07, 0.03, 0.02, 0.01, 0.00,
  0.71, 0.74, 1.00, 0.67, 0.60, 0.47, 0.33, 0.17, 0.08, 0.03, 0.02, 0.01, 0.00,
  0.65, 0.68, 0.67, 1.00, 0.58, 0.46, 0.32, 0.17, 0.08, 0.04, 0.02, 0.01, 0.00,
  0.58, 0.61, 0.60, 0.58, 1.00, 0.44, 0.31, 0.16, 0.08, 0.03, 0.02, 0.01, 0.00,
  0.46, 0.48, 0.47, 0.46, 0.44, 1.00, 0.28, 0.15, 0.07, 0.03, 0.02, 0.01, 0.00,
  0.32, 0.33, 0.33, 0.32, 0.31, 0.28, 1.00, 0.14, 0.07, 0.03, 0.02, 0.01, 0.00,
  0.16, 0.17, 0.17, 0.17, 0.16, 0.15, 0.14, 1.00, 0.05, 0.03, 0.02, 0.01, 0.00,
  0.07, 0.07, 0.08, 0.08, 0.08, 0.07, 0.07, 0.05, 1.00, 0.02, 0.01, 0.01, 0.00,
  0.03, 0.03, 0.03, 0.04, 0.03, 0.03, 0.03, 0.03, 0.02, 1.00, 0.01, 0.00, 0.00,
  0.01, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.02, 0.01, 0.01, 1.00, 0.00, 0.00,
  0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.01, 0.00, 0.00, 1.00, 0.00,
  0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 0.00, 1.00};


       double nSigData[20]={
	 318.4,     706.4,     149.6,     425.8,     466.4, 
	 547.9,     722.0,    1105.3,    1023.5,    1023.9, 
	 659.4,     434.7,      34.7,      90.6,      70.6, 
	 -43.5,     -96.1,      -0.1,     -69.2,      37.9}; 
 
       double nSigDataStat[20]={
	 156.4,  161.9,   153.2,  137.8, 121.2,
	 105.6,   97.6,    91.2,   90.3,  84.0,
	 78.7,    61.7,    65.6,   57.2,  59.5, 
	 59.5,    63.3,    52.5,   57.0,  43.3}; 
      

       double nSigDataSyst[20]={
         274.7,  315.7, 252.0, 195.0, 139.1,
          91.3,   55.9,  32.6,  20.3,  19.3,
           9.4,    6.5,   3.4,  0.001,    0.001, 
	 0.001,    0.001,   0.001,   0.001,    0.001};


       double Eff_18  =0.02573, Eff_19 =0.02603, Eff_20=0.02641; 
       double Eff_err =0.031; 
       double Xterm_18=0.029, Xterm_19=0.024, Xterm_20=0.019; 
       double NBB_err =0.011; 
       // 

       myAnalysis bsg; 
       const int nBins=13; 
       const int nbins=13; 

       //Input all measured Values
       bsg.setData(nSigData,nBins); 

       bsg.setErrorStat(nSigDataStat,nBins); 

       bsg.setErrorSyst(nSigDataSyst,nBins); 

       bsg.setErrorStatAndSyst(nBins); 

       bsg.setEfficiency( Eff_18, Eff_19, Eff_20); 

       bsg.setCorrelationMatrix(corr,nbins); 

       //compute efficiency
       bsg.computeBF(); 

       bsg.computeBFerr(); 

       bsg.computeBFcorrel(); 

       bsg.printResults(); 
       //





       return 0; 
}
