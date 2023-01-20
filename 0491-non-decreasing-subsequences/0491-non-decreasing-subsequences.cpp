class Solution {
public:
    void subseq(int i,vector<int> v,vector<vector<int>> &ans,vector<int>temp,unordered_map<string,int>&mp){
        if(i>=v.size()){
            if(temp.size()>1){
                // cout<<"subseq"<<endl;
                string s="";
                for(int i=0;i<temp.size();i++){
                    if(i!=temp.size()-1 && temp[i]>temp[i+1])return;
                    int x = temp[i];
                    s+=to_string(x);
                    s+="-";
                }
                // cout<<endl<<"subseq"<<endl;
                if(mp.find(s)==mp.end())
                    ans.push_back(temp);
                mp[s]++;
            }
            return;
        }
            // cout<<"temp[0]"<<temp[0]<<endl;
        
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
        // vector<vector<int>> v;
        // vector<int> temp;
        // temp.push_back(nums[0]);
        // for(int i=1;i<nums.size();i++){
        //     if(temp.back()<=nums[i]){
        //         temp.push_back(nums[i]);
        //     }
        //     else{
        //         v.push_back(temp);
        //         temp = {};
        //         temp.push_back(nums[i]);
        //     }
        // }
        // if(temp.size()>1){
        //     v.push_back(temp);
        //     temp={};
        // }
        //     // cout<<"v.len : "<<v.size()<<endl;
        // vector<vector<int>> ans;
        // // int i=0;
        // unordered_map<string,int>mp;
        // for(auto it:v){
        //     // cout<<i++<<endl;
        //     if(it.size()>1){
        //         temp={};
        //         // for(auto i:it){
        //         //     cout<<i<<"*";
        //         // }cout<<endl;
        //         subseq(0,it,ans,temp,mp);
        //     }
        // }
        // sort(ans.begin(),ans.end());
        // return ans;
    }
};