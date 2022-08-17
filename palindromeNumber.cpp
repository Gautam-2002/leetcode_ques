class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0 && x%10==0))return false;
        int y=x;
        int t=0;
        while(y>t){
            int r=y%10;
            t=(t*10)+r;
            y/=10;
        }
        return (y==t || y==t/10);
    }
};