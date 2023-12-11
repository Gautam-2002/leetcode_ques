class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0, x = 0, y = 0;
        
        unordered_map<int,vector<int>> idx;
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            
            int a = nums[i];

            idx[a].push_back(i);

            if(mp.find(a)==mp.end() || mp[a]+1 <= k){
                mp[a]++;
                // cout<<a<<" "<<mp[a]<<endl;
            }
            else{
                int j;
                for(j=0;j < idx[a].size();j++){
                    if(idx[a][j]!=-1)
                        break;
                }
                y = max(y,idx[a][j] + 1);
                idx[a][j] = -1;
            }
            
            x = i - y + 1;
            // cout<<y<<"*"<<x<<endl;
            ans = max(ans,x);
        }
        return ans;
    }
};