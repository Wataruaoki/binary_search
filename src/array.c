#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
    return (int) m >= k;
}
/* 整数 m がk以上になっているかを判定する.
 */

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = n;
  while(ub - lb > 1){
      int m = (lb + ub) / 2;
      if(p(A[m])){
          ub = m;
      }
      else {
          lb = m;
      }
  }
  printf("%d\n", ub);
  return 0;
}
/* 上記において定義した関数 p を用いて二分探索を行う.
 */
