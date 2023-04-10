class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        for(auto i:nums1){
            mp[i]++;
        }
        vector<int>ans;
        for(auto i:nums2){
            if(mp.find(i)!=mp.end() && mp[i]!=-1){
                ans.push_back(i);
                mp[i]=-1;
            }
        }
        return ans;
    }
};