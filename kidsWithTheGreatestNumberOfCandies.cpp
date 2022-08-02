class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans(candies.size());
        int maxi=INT_MIN;
        for(int i=0;i<candies.size();i++){
            maxi=max(candies[i],maxi);
        }
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maxi)ans[i]=true;
            else ans[i]=false;
        }
        return ans;
    }
};