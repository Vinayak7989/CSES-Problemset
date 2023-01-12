#include <bits/stdc++.h>
using namespace std;
/*
STATE & DEFINITION

dp[curNumber] -> min steps to make curNumber to 0

TRANSITION
we'll subsract one of the digit of curNumber
for each digit of curNumber
(curNumber) -> (curNumber - digit)
dp[curNumber] = minimize with dp[curNumber + digit] + 1
*/
const int N = 1e6 + 5;
int cache[N], n;

int minSteps(int curNumber){
    int &ans = cache[curNumber];
    if(ans != -1) return ans;
    if(curNumber == 0) return ans = 0; // no more steps are required
    
    ans = N;
    for(char dig : to_string(curNumber)) 
        ans = min(ans, minSteps(curNumber - (dig - '0')) + 1);
    return ans;
}

int main() {
    cin >> n;
    memset(cache, -1, sizeof cache);
    cout << minSteps(n);
}