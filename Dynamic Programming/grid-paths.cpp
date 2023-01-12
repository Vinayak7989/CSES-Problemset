#include <bits/stdc++.h>
using namespace std;

/*
STATE & DEFINITION
dp[row][col] -> # ways to reach (n-1, m-1) from (row, col)
TRANSITION
(row, col) -> (row+1, col) or (row, col+1)

*/
const int N = 1e3 + 5, MOD = 1e9 + 7;
string matrix[N];
int n, cache[N][N];

int ways(int row, int col) {
      int &ans = cache[row][col];
      if(ans != -1) return ans;
      if(matrix[row][col] == '*')
            return ans = 0;
      if(row == n-1 && col == n-1) return ans = 1;
      
      ans = 0;
      // go down
      if(row + 1 < n) 
            ans = (ans + ways(row+1, col)) % MOD;
      // go right
      if(col + 1 < n)   
            ans = (ans + ways(row, col+1)) % MOD;
      return ans;
}

int main() {
      cin >> n;
      for(int row = 0; row < n; row++) 
            cin >> matrix[row];
      memset(cache, -1, sizeof cache);  
      cout << ways(0, 0); 
}