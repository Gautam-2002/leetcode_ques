class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        int i = 0;
        int j = 0;
        int n = nums.size();
        vector<int>ans;
        if(k==1){
            return nums;
        }
        if(k==n){
            int m = INT_MIN;
            for(auto i:nums){
                m = max(i,m);
            }
            ans.push_back(m);
            return ans;
        }
        while(j<k){
            while(dq.size() > 0 && dq.back() < nums[j]){
                    dq.pop_back();
            }
            dq.push_back(nums[j]);
            j++;
            // cout<<dq.front();
        }
        while(j<=n){
            // cout<<dq.front();
            ans.push_back(dq.front());
            if(nums[i]==dq.front()){
                dq.pop_front();
            }
            i++;
            if(j<n){
                while(dq.size() > 0 && dq.back() < nums[j]){
                    dq.pop_back();
                }
                dq.push_back(nums[j]);
            }
            j++;
        }
        return ans;
    }
};