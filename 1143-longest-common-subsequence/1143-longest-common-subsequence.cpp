class Solution {
public:
    int solve(string &x,string &y,int i,int j,vector<vector<int>> &dp){
        if(i>=x.size() || j>=y.size()){
            return 0;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int a = 0,b=0;
        
        if(x[i]==y[j]){
            a = 1 + solve(x,y,i+1,j+1,dp);
        }
        else{
            a = solve(x,y,i+1,j,dp);
            b = solve(x,y,i,j+1,dp);
        } 
        return dp[i][j] = max(a,b);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return solve(text1,text2,0,0,dp);
    }
};