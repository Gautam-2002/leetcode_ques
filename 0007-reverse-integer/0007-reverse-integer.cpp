class Solution {
public:
    int reverse(int x) {
        int n = abs(x);
        long long ans = 0;
        while(n>0){
            if(ans*10 > INT_MAX)return 0;
            ans = (ans*10)+(n%10);
            n/=10;
        }
        int a = int(ans);
        return x>0? a : (-1 * a);
    }
};