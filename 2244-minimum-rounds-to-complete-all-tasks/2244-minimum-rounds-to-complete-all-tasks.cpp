class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto it:tasks){
            mp[it]++;
        }
        int ans=0;
        for(auto it:mp){
            // cout<<it.second<<endl;
            if(it.second<2){
                return -1;
            }
            else if(it.second==2){
                ans++;
            }
            else if(it.second>=3){
                int ele = it.second;
                int t = ele/3;
                int x = ele-(t*3); 
                if(x==0 && ele>=3){
                    ans+=t;
                }
                else if(x==1 ){
                    ans+=(t+1);
                }
                else if(x==2){
                    ans+=t;
                    ans++;
                }
            }
        }
        return ans;
    }
};