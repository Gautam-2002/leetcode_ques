class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum =0;
        for(auto i:nums){
            sum+=i;
        }
        int n = nums.size();
        long long s = (n*(n+1))/2;
        return s-sum;
    }
};