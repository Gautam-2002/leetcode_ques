class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int maxi = nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(i > 0 && nums[i]==nums[i-1])
                continue;
            int j=i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(sum - target) < abs(maxi-target)){
                    maxi = sum;
                }
                if(sum == target)break;
                if(sum < target)
                    j++;
                if(sum > target)
                    k--;
            }
        }
        return maxi;
    }
};