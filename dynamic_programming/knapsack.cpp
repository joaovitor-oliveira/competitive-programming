#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1234;

int n;
int arr[MAXN], value[MAXN], weight[MAXN], memo[MAXN][MAXN];
/*
// recursive
int knapsack(int i, int j) {
  if(i == n)
    return 0;
  if(memo[i][j] != -1)
    return memo[i][j];
    
  int op1 = knapsack(i + 1, j);
  int op2 = 0;
  
  if(weight[i] <= j)
    op2 = knapsack(i + 1, j - weight[i]) + value[i];
    
  return memo[i][j] = max(op1, op2);
}
*/

int main() {
  /*  iterative + space optimized
      pd[2][MAXN]
      int c = max weight
  */
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= c; j++) {
      if(weight[i - 1] <= j)
        pd[i & 1][j] = max(pd[~i & 1][j], pd[~i & 1][j - weight[i - 1]] + value[i - 1]);
      else
        pd[i & 1][j] = pd[~i & 1][j];
    }
  }
  
  printf("%d\n", pd[n & 1][c]);
  
  return 0;
}
