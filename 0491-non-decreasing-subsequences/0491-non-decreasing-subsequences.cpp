class Solution {
public:
    void subseq(int i,vector<int> v,vector<vector<int>> &ans,vector<int>temp,unordered_map<string,int>&mp){
        if(i>=v.size()){
            if(temp.size()>1){
                string s="";
                for(int i=0;i<temp.size();i++){
                    if(i!=temp.size()-1 && temp[i]>temp[i+1])return;
                    int x = temp[i];
                    s+=to_string(x);
                    s+="-";
                }
                if(mp.find(s)==mp.end())
                    ans.push_back(temp);
                mp[s]++;
            }
            return;
        }        
        subseq(i+1,v,ans,temp,mp);
        temp.push_back(v[i]);
        subseq(i+1,v,ans,temp,mp);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        unordered_map<string,int>mp;
        subseq(0,nums,ans,temp,mp);
        return ans;
    }
};