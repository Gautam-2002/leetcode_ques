// not(~) = make 0 to 1 and 1 to 0
// and (&) = both bits should be 1 for result to be 1
// or(|) = either of bit should be 1 for result to be 1
// Xor(^) = any one bit should be 1 and other should be 0 for result to be 1
// left shift (<<) = it append 0 at end of the number and shift all bits to left side [multiply by 2]
// eg: a= 1 = 001(in binary) ; a<<1 = 010 = 2(in decimal)
// right shift (>>) = it append 0 at the left side and move all bits to right;[divide by 2]
// eg: b = 5 = 00101; b>>1 = 00101>>1 = 00010 = 2;
// To obtain the least significant bit of P, we can use bitwise AND operator P & 1
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(a != 0 | b!= 0 | c != 0){
            if((c & 1) == 1){
                if((a & 1)==0 && (b & 1)==0){
                    ans++;
                }
            }
            else{
                ans += (a & 1) + (b & 1);
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ans;
    }
};