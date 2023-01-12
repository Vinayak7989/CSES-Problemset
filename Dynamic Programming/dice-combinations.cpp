#include <bits/stdc++.h>
using namespace std;

/*
THINKING
_ _ _ | after some throws the only thing matters to rest of throws is
1. just the sum of dice outcomes
and not no. of throws and what exaclty came in each throw

STATE & DEFINITION
dp[curSum] = if sum of throws made so far is "curSum", what are no. of ways
to make thissum = "targetSum" 

TRANSITIONS 
In order to complete our way to make sum = 'target'
_ _ _ | (next_throw can  anything 1 to 6)
(curSum) -> (curSum+1) or (curSum + 2) .. (curSum + 6)

ways to reach (curSum + 1) += ways to reach curSum 
same for 2,3,..6

for x from 1 to 6 
ways[curSum + x] += ways[curSum];

This is called push-dp, we are updating answers of states reachable from current state

Alternative Pull Dp
for x : 1 to 6
ways[curSum] += ways[curSum - x] 

*/
const int N = 1e6 + 5;
int cache[N], MOD = 1e9 + 7;

int ways(int sumSoFar, int targetSum) {
    int &ans = cache[sumSoFar]; // taking ans by referrence
    if(ans != -1) return ans;
    
    if(sumSoFar == targetSum) {
        return ans = 1;
    }
    
    ans = 0;
    // current throw can be
    for(int i = 1 ; i <= 6; i++) {
        if(sumSoFar + i <= targetSum)
                ans = (ans + ways(sumSoFar + i, targetSum)) % MOD;
    }
    return ans;
}

int main() {
    int targetSum;
    cin >> targetSum;
    memset(cache, -1, sizeof cache);
    cout << ways(0, targetSum);
}