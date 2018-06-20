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
  lb = -1;
  ub = n;
  /* 上記のように初期値を設定すれば, m = (lb + ub) /2 の値は0,1,...,n-1全て取りうる.
   * したがって, ub は0,1,2,...,n-1,nの値を取りうる
   * 出力の値が 0,1,2,...,n-1,nと0を含むことに注意する.
   * 求める値が存在しない場合は, 毎度 lb = m が適用され, 単調増加的にlb = n-1となり
   * ub = n が出力される.
   */
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
