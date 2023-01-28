//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long fun(long long n,long long dp[]){
        if(n<=1)return 1;
        if(dp[n]!=0)return dp[n]%1000000007;
        dp[n] = (fun(n-1,dp)%1000000007)+(fun(n-2,dp)%1000000007);
        long long ans = dp[n]%1000000007;
        return ans%1000000007;
    }
    long long numberOfWays(long long N) {
        //code here
        long long dp[N+1] = {0};
        long long ans = fun(N,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.numberOfWays(N) << endl;
    }
    return 0;
}
// } Driver Code Ends