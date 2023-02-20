class Solution {
public:
    int countOdds(int low, int high) {
        // BRUTE FORCE :
        // int ans = 0 ;
        // for(int i=low;i<=high;i++){
        //     if(i&1)ans++;
        // }
        // return ans;
        // OPTIMIZED
        if(!(low & 1))
            low++;
        return low>high ? 0 : ((high-low)/2)+1;
    }
};