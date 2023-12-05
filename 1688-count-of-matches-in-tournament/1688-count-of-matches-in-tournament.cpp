class Solution {
public:
    int numberOfMatches(int n) {
        if(n == 1)return 0;
        if(n == 2)return 1;
        
        if(n & 1)
            return (n/2) + numberOfMatches(n/2+1);
        else
            return (n/2) + numberOfMatches(n/2);
    }
};
// from solutions : 
// class Solution {
// public:
//     int numberOfMatches(int n) {
//         return n - 1;
//     }
// };