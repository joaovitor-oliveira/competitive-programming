#include <bits/stdc++.h>

using namespace std;

int kadane(vector<int> v) {
  int ans = 0, _max = 0;
  
  int sz = v.size();
  for(int i = 0; i < sz; i++) {
    _max = max(0, _max + v[i]);
    ans = max(ans, _max);
  }
  
  return ans;
}

int main() {
  
  
  return 0;
}
