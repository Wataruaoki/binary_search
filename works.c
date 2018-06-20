#include <stdio.h>

int n;
int k;
int A[100000];

int p(int(m)){
    int i;
    int now = 0;
    int eversum = 0;
    int times = 0;
    while(now < n && times < k){
      if(eversum + A[now] <= m){
        eversum += A[now];
        now += 1;
      }
      /* evermax と A[now] の和が m を超えない場合は
       * evermax に A[now] を加えて 1ステップ進める
       */
      else{
        eversum = 0;
        times += 1;
      }
      /* 超えてしまう場合は, evermax を 0 に 再度初期化して, 回数timesを1つ増やす
       */
    }
    return now == n;
}
/* 最大値がmを超えないようなa_nのk個の分割法が存在するかを判定する. 
 */


int main(){
  int i, j,lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 0;
  /* ub, lb の初期化
   */
  for(j = 0;j<n;j++){
      ub += A[j];
  }
  /* 必ずp = 1となるように,明らかに正しい a1+a2+...+an をubの初期値として与える.
   */
  while(ub - lb > 1){
      int m = (ub + lb) / 2;
      if(p(m)){
          ub = m;
      }
      else{
          lb = m;
      }
  }
  printf("%d\n", ub);
  return 0;
}
/* 上記で定義した関数 p を用いて, 二分探索を行う. 解xにおいて, p(x-1) = 0, p(x) = 1に注意
 */
