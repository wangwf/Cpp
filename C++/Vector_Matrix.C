

#include <iostream>
#include <vector>
using namespace std;

typedef vector<double> Vec;
typedef vector<Vec> Mat;

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

int main(){
  int i,j,m,n;

  cout << "Enter the number of rows in the matrix \n";
  cin >> m;
  cout << "Enter the number of columns in the matrix \n";
  cin >> n;

  // Allocate space for the vectors
  Vec row(n);
  Mat a;

  cout << "Enter the matrix\n";
  for(i = 0; i < m; i++){
    for(j = 0; j < n; j++)cin >> row[j];
    a.push_back(row);
  }

  cout << "Enter the vector\n";
  Vec x(n);
  for(j = 0; j < n; j++)
    cin >> x[j];

  Vec b = a*x;

  cout << "\nA*x = \n";
  for(i = 0; i < m; i++)
    cout << b[i] << "\n";
}
