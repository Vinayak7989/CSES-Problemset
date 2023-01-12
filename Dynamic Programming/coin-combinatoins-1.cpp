#include <bits/stdc++.h>
using namespace std;

/*
THINKING
how would any way look like ?
c1 + c2 + c3 ... = 'target' we will take some coins which sums to target
if we have made one way half way through what information of already made choices (coins) 
will affect to complete the rest of the way

1.) sum of coins 
2.) NOT what exact coins and not the coin we are at [index].. because 2 + 2 + 1, 1 + 2 + 2 are differenct so order matters.. 

STATE & DEFINITION
dp[sumTaken] : # of ways to make sum = 'target' is current sum of coins = 'sumTaken'

TRANSITIONS
to complete the way we will take some coin next
for each nextCoin in coins array
noOfWaysToMake[curSum + nxtCoin] += noOfToMake[curSum]
*/
const int N = 1e6 + 5, MOD = 1e9 + 7;
int cache[N], n, coins[105], target;

int ways(int curSum) {
      int &ans = cache[curSum];
      if(ans != -1) return ans;
      if(curSum == target) {
            // ways to make sum = 'targetSum' if current sum is 'targetSum' obviously 1 way to take no coins
            return ans = 1;
      }
      ans = 0;
      for(int nextCoin = 0; nextCoin < n; nextCoin++) {
            if(curSum + coins[nextCoin] <= target)
                  ans = (ans + ways(curSum + coins[nextCoin])) % MOD;
      }
      return ans;
}

int main() {
      cin >> n >> target;
      for(int i = 0; i < n; i++) 
            cin >> coins[i];
      memset(cache, -1, sizeof cache);
      cout << ways(0);
}