class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        double curr = 0;
        for(int i=0;i<nums.size();i++){
            if(i<k){
                curr+=nums[i];
            }
            else{
                double x = double(curr/k);
                ans = max(ans,x);
                curr-=nums[i-k];
                curr+=nums[i];                
            }
        }
        double x = double(curr/k);
        ans = max(ans,x);
        return ans;
    }
};