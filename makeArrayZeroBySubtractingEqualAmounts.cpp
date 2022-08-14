class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        
        for(int i=0;i<n;i++){
            int flag=0;
            for(int k=0;k<n;k++){
                if(nums[k]==0)
                    flag++;
            }
            if(flag==n){
                return ans;
            }
            int mini = INT_MAX;
            for(int x:nums){
                if(x!=0)
                mini=min(mini,x);
            }
            for(int j=0;j<n;j++){
                if(nums[j]<=mini)
                    nums[j]=0;
                else
                    nums[j]-=mini;
            }
            ans++;
        }
        return ans;
    }
};