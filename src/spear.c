#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
    int sum = 0;
    int j;
    for(j = 0;j<n;j++){
        sum += (A[j] / m);
    }
    return k > sum;
}
/* 長さm の槍が k本 作れないかどうかの真偽を判定する.
 * 各木から長さm のできる数の総和をとり, kとの大小を比べる.
 */

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  ub = 0; /* ubの初期化 */
  int j;
  for(j = 0; j < n; j ++){
      if(A[j] > ub){
          ub = A[j];
      }
  }
  ub += 1;
  /* x = max{A[j]_(j =0,1,2,...,n-1)+1}とすると x > A[j] (j = 0,1,2,...,n-1)
   * したがって, sum = 0  すなわち p(x)= 1 が任意の自然数 k に対して成り立つので
   * 初期値を ub = x とする.
   */
  lb = 0;
  while(ub - lb > 1){
      int m = (lb + ub) /2;
      if(p(m)){
          ub = m;
      }
      else{
          lb = m;
      }
  }
printf("%d\n",lb);
return 0;
}
/* 上記で定義した関数 p を用いて, 二分探索を行う. なお, 求める解xはp(x) = 0であることに注意.(p(x+1)=1)
 * したがって, lbの値を出力する.
 */
