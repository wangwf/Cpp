#include <vector>
#include <iostream>

using namespace std;

  void setZeroes(vector<vector<int> > & matrix) {
        int nrows= matrix.size();
        if(nrows==0)return;
        int ncols= matrix[0].size();
        if(ncols==0) return;

        bool fc0=false;
        bool fr0=false;
        //        cout<<"ncol "<<ncols<<" "<<nrows<<endl;

        for(int i=0; i<ncols; i++) if(matrix[0][i]==0)fr0=true;
        for(int j=0; j<nrows; j++) if(matrix[j][0]==0)fc0=true;
        //        cout<<" "<<fr0<<" "<<fc0<<endl;

        for(int j=1; j<nrows; j++){
            for(int i=1; i<ncols; i++){
                if(matrix[j][i]==0){
                    matrix[j][0]=0;
                    matrix[0][i]=0;
                }
            }
        }

        for(int i=1; i<ncols; i++){
            if(matrix[0][i]==0){
                for(int j=0; j<nrows; j++)matrix[j][i]=0;
            }
        }

        for(int j=1; j<nrows; j++){
            if(matrix[j][0]==0){
                for(int i=0; i<ncols; i++){
                    matrix[j][i]=0;
                }
            }
        }


        if(fc0) for(int j=0; j<nrows; j++)matrix[j][0]=0;
        if(fr0) for(int i=0; i<ncols; i++)matrix[0][i]=0;
        return;
    }

int main(){

  vector< vector<int> > mat(1,vector<int>(2));
  mat[0][0]=1;
  mat[0][1]=0;

    setZeroes(mat);

  for(int i=0; i<mat.size(); i++){
    for(int j=0; j<mat[0].size(); j++)
      cout<< mat[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
