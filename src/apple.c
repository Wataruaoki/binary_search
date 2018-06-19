#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
    int sum = 0;
    int j;
    for(j = 0; j < n; j++){
        if(A[j] % m == 0){
            sum += A[j] / m ;
        }
        else{
            sum += (A[j] / m )+1;
        }
    }
    return (int) k >= sum;

}
/* 最大で m 個のリンゴが入るバックにおいて, k個のバックで足りるかの真偽を判定する.
 * 各A[j]に対して, 必要なバックの数を足していき, kとの大小を比べて真偽を出力する.
 */


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  ub = 0;
  int j;
  for(j = 0; j < n; j ++){
      if(A[j] > ub){
          ub = A[j];
      }
  }
  /* 必ずpが正しくなるものとして, A[j]の最大値をubに初期値として与える.
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
    printf("%d\n",ub);
  return 0;
}
/* 上記で定義した関数pを用いて二分探索する.
*/
