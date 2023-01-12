#include <bits/stdc++.h>
using namespace std;

/*
1) THINKING
we have to take some coins to make sum = 'target' by possibly retaking one coin
c1, c2, c3, _ _ _  after taking some coins 

2) STATE & DEFINITION

what is the important thing that matters to complete the way of making sum = 'target'
1) sum of coins taken 
2) the index or the coins upto which we have decided how many times we need to take them
Observe : 
2nd state is of no importance bcoz
(a) if we take 1 coins (one type) 2 coins (second type)
then total ways = 3! / (1! * 2!) since we have to count ordered ways
(b) it's not NECESSARy we can drop it..
So just 1st state is sufficient

dp[sumSoFar] = min Coins required to make sum = 'target' is current sum is this or INF if it's not possible

3) TRANSITIONS
the next coin can be anything a[0], a[1],..a[n-1]
(sumSoFar) -> (sumSoFar + a[0]) or ...(sumSoFar + a[1]) 

// push way
for all coins
minCoins[sumSoFar + coinValue] = minimize with (minCoins[sumSoFar] + 1)
// pull way
for lastCoinsValue from a[0]..a[n-1]
minCoins[sumSoFar] = min(minCoins[sumSoFar], minCoins[sumSoFar - lastCoinValue] + 1)
*/

const int mxN = 1e6 + 5;
int cache[mxN], n, coins[105], target;

int minCoins(int sumMadeSoFar) {
    int &ans = cache[sumMadeSoFar];
    if(ans != -1) return ans;
    if(sumMadeSoFar == target) {
        return ans = 0;
    }
    ans = mxN; // max required coins can be 1e6 = 1 + 1 + 1 ...
    for(int nextCoin = 0; nextCoin < n; nextCoin++) {
        if(sumMadeSoFar + coins[nextCoin] <= target)
            ans = min(ans, minCoins(sumMadeSoFar + coins[nextCoin]) + 1);
    }
    return ans;
}

int main() {
    cin >> n >> target;
    for(int i = 0; i < n; i++) 
        cin >> coins[i];
    memset(cache, -1, sizeof cache);
    int answer = minCoins(0);
    if(answer == mxN) answer = -1;
    cout << answer;
}