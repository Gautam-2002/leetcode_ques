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
// Intution each match eliminated 1 team to to eliminate n-1 teams it will take n-1 matches (as 1 team will we winner at the end)
// class Solution {
// public:
//     int numberOfMatches(int n) {
//         return n - 1;
//     }
// };