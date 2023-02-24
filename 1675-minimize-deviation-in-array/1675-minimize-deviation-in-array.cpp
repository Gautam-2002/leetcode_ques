class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n= nums.size();
        priority_queue<int> pq;
        int mn=INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i]&1){
                pq.push(nums[i]*2);
                mn= min(mn, nums[i]*2);
            }
            else{
                mn=min(mn, nums[i]);
                pq.push(nums[i]);
            }
        }

        int ans= INT_MAX;

        while( !pq.empty() ){
            int top= pq.top();
            pq.pop();
            ans = min(ans, (top-mn));
            if(top&1){
                break;
            }
            mn= min(mn, top/2);
            pq.push(top/2);
        }

        return ans;
        
    }
};