#include <bits/stdc++.h>
using namespace std;
/*
THINKING
unlike previous problem here order doesn't matter 2 + 3 and 3 + 2 are same
so if the multiset of coins values is different then it's counted as distinct way
so if we sort the coin Values in any way then overcounting can be eliminated

since all the coins values are distinct so if we take each coin one after another 

c1 , c2 , c3 , c4 
for c1 -> we'll either take 0,1,2,... coins of it 
for c2 -> we'll either take 0,1,2,... coins of it
ans so on for each coin we have many choices

if we have made choices about coins c1, c2, c3... what matter to the choices of remaining coins
1.) the sum of coin values
2.) the index of coin we are at, or the no. of coins for which choice has been made

STATE & DEFINITION
dp[index][sum of Coins choosen] -> # of ways to make sum = 'target' if currently we have made choices for first index coins and sum = 'sum'

TRANSITIONS
we have made decision for 0,1,..index-1 coins
now it's the time to make decision for "index" coin
so we'll either leave it, of take it 1 times, 2, 3... times
(index, curSum) -> (index+1, curSum), or (index+1, curSum - a[index]) or (index+1, curSum = 2*a[index]) 
we can also iterate on no. of time we'll take "index"th coin but no. of transitions can be reduced

(idx, sum)          (idx+1, sum)
(idx, sum + a[i])   (idx+1, sum+a[i])
                    (idx+1, sum + 2*a[i])

we'll add ways to (idx+1, sum + 2*a[i]) -> in two transitions (idx, sum + a[i]) and (idx, sum)

this can be done in one transition just make two transition from (idx, sum)
(idx, sum) => (idx, sum + a[i]) // don't increase idx. bcoz possibly take this coins again
(idx,sum) => (idx+1, sum)// stop taking this coins 

in this way to (idx+1, 2*a[i]) all the ways will be added in just two transition by (idx, a[i]) and (idx, 2*a[i]) only  

we know Time Complexity 
No. of states * (transition time for each state)    
*/
const int N = 1e6 + 5, MOD = 1e9 + 7;
int cache[105][N]; // 381 MB memory allowed 512 MB
int n, coins[105], target;

// Due to tight time bounds .. recusive implementation is getting TLE
int ways(int index, int curSum) {
    int &ans = cache[index][curSum];
    if(ans != -1) return ans;
    if(index == n) {
        if(curSum == target) return ans = 1;
        else return ans = 0;
    }
    ans = 0;
    // take this once more
    if(curSum + coins[index] <= target)
        ans = (ans + ways(index, curSum + coins[index])) % MOD;
    // stop taking this coins
    ans = (ans + ways(index+1, curSum)) % MOD;
    return ans;
}

int main() {
    cin >> n >> target;
    for(int i = 0; i < n; i++)  
        cin >> coins[i];
    memset(cache, -1, sizeof cache);
    cout << ways(0, 0);    
}