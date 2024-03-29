class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)return false;
        if(n==1)return true;
        while(n>0){
            if(n==2)return true;
            if(n&1)return false;
            n/=2;
        }
        return true;
    }
};