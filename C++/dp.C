

//dynamic programming
//
// f[i][j] = max( f[i-1][j],  f[i-1][j- c[i]] + w[i]

#include <stdio.h>

int dy1(void){
  int i=0, j=0, n=0, v=0;
  int f[100][100]={0}, c[100]={0}, w[100]={0};

  scanf("%d%d", &v, &n);

  for(i=0; i<=n; i++) scanf("%d%d", &c[i], &w[i]);

  for(i=1; i<=n; i++){
    for(j=0; j<=v; j++){
      if(j>c[i] && (f[i-1][j] < (f[i-1][j-c[i]] + w[i])))
        f[i][j]= f[i-1][j-c[i]] + w[i];
    }}
  printf("%d", f[n][v]);
  getch();
  return 0;
}

