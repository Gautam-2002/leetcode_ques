class Solution {
public:
    int solve(int n,int i){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
        return (solve(n,i+1)+solve(n,i+2));
    }
    int climbStairs(int n) {
        
        // int ans = solve(n,0);
        // return ans;
        int a=1,b=1;
        while(--n){
            a = ((b+=a) - a);
        }
        return b;
    }
};