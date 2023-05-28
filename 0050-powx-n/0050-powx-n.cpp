class Solution {
public:
    double myPow(double x, long long n) {
        if(x==1)return 1;
        if(n==0)return 1;
        if(n==1)return x;
        if(n<0){
            n*=-1;
            x=1.0/x;
        }
        double ans = 1;
        while(n){
            if(n&1){
                ans *= x;
                n--;
            }
            else{
                x*=x;
                n/=2;
            }
        }
        return ans;
    }
};