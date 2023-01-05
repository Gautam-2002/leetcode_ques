class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(auto it:nums){
            if(mp.find(it-1)!=mp.end()){
                mp[it]=false;
            }
            else{
                mp[it]=true;
            }
            if(mp.find(it+1)!=mp.end()){
                mp[it+1]=false;
            }
        }
        int ans=0;
        for(auto i:mp){
            int curr=0;
            if(i.second==true){
                int x = i.first;
                while(mp.find(x)!=mp.end()){
                    curr++;
                    x++;
                }
                ans=max(ans,curr);
            }
                        
        }
        return ans;
    }
};