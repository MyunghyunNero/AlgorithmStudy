#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
int n;
int dp[31];

int main(){
    cin>>n;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]+=dp[i-1];
        dp[i]+=dp[i-2] * 2;
    }
    if(n % 2) {
        cout<< (dp[n]+dp[n/2])/2;
    }else{
        cout<<(dp[n]+dp[n/2]+2*dp[n/2-1])/2;
    }
}