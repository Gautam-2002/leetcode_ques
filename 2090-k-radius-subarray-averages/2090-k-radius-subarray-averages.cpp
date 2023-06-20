class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0)
            return nums;
        int n = nums.size();
        if(n < 1+2*k)
            return vector<int> (n,-1);
        
        vector<int> v;
        long long sum = 0;
        for(int i = 0;i<(2*k+1);i++){
            if(i<k)
                v.push_back(-1);
            sum+=nums[i];
        }
        int i=0,j=2*k+1;;
        while(j<n){
            v.push_back(int(sum/(2*k+1)));
            sum-=nums[i++];
            sum+=nums[j++];
        }
        v.push_back(sum/(2*k+1));
        for(int x = 0;x<k;x++){
            v.push_back(-1);
        }
        return v;
    }
};