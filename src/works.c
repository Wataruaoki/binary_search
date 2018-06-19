#include <stdio.h>

int n;
int k;
int A[100000];

int sum(int p, int q){
    int m;
    int ans = 0;
    for(m = p;m <= q;m++){
        ans += A[m];
    }
    return ans;
}
/*  A[p]からA[q]までの総和 Σ[k = p~q] A[k] を計算する.
 */


int p(int(m)){
    int i;
    int now = 0;
    for(i = 0; i<k; i++){
        int newnow = now;
        while(newnow < n && sum(now,newnow) <= m){
            newnow += 1;
        }
        now = newnow;
    }
    return (int) now == n;
}
/* 最大値がmを超えないようなa_nのk個の分割法が存在するかを判定する.
 */


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = sum(0,n-1);
  /* 必ずp = 1となるように明らかに正しい, a1+a2+...+anをubの初期値として与える.
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
