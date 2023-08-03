class Solution {
public:
    long long expo_pow(long long x,long long y){
        // cout<<x<<" "<<y<<endl;
        if(x<=0)return 1;
        long long ans = 1;
        while(x){
            if(x&1){
                ans = ((ans) * y) % 1000000007;
                x--;
            }
            else{
                x/=2;
                y = (y*y)%(1000000007);
            }
        }
        // cout<<ans<<endl;
        return ans%1000000007;        
    }
    int countGoodNumbers(long long n) {
        long long ans = 1;
        int e = 5;
        int o = 4;
        long long x = n/2;
        if(n&1){
            ans = ((expo_pow(x+1,e)%1000000007) * (expo_pow(x,o)%1000000007)) % 1000000007;
        }
        else{
            ans = ((expo_pow(x,e)%1000000007) * (expo_pow(x,o)%1000000007)) % 1000000007;
        }
        return ans%1000000007;
    }
};