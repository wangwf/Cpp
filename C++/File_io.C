//adding 3.3% correlated error matrix
#include <fstream>
#include <iostream>
#include <string>
#include <Scanner>
using namespace std; 


void OpenFile(const string& fileName){   
   
    string lstrin; 
    ifstream file11; 
    file11.open(fileName.c_str());
    if(file11.fail()){
	cout<<" Input file failed. Please try again!"<<endl; 
        file11.clear(); 
	}


     string lineString; 
     for(int i=0; i<11; i++){getline(file11,lineString); /* cout<<lineString<<endl; */};  //
  

     cout<<" check Scanner "<<endl; 
     Scanner scanner; 
     int count=0; 
     scanner.setInput(lineString); 
     while (scanner.hasMoreToken()){
       scanner.NextToken(); 
       count++
     }
     cout<<" number of Tokens "<<count<<endl; 

    int nLine=13; 
//    Matrix* Etrue_coll=new TMatrix(nLine,nLine); 
    float Etrue_coll[nLine][nLine]; 
    float f; 
    string s1, s2,s3,s4; 

   for(int i=0; i<nLine; i++){
     if(i==0){file11>>s1>>s2; cout<<"Beging "<<s1<<" "<<s2<<" ";}
     else{file11>>s1>>s2>>s3; cout<<"Beging "<<s1<<" "<<s2<<" "<<s3;  }

     for (int j=0; j<nLine; j++){
       if(j<i){file11>>s1; }
       else if (j>=i){
 	 file11>>s1>>f; Etrue_coll[i][j]=f;
	 cout<<" "<<s1<<" "<<Etrue_coll[i][j];
        }
      }

      file11>>s1>>s2>>s3; 
      cout<<" "<<s1<<" "<<s2<<"  "<<s3<<endl; 
 
  }
  file11.close(); 
//  Etrue_coll->Print(); 

}

int main(){

 string fileName11="../Bsg/BAD/note2347/tables/EGammaCMSTrue-correlation.tex"; 
 
 OpenFile(fileName11); 

return 0; 

}

