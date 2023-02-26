class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi=INT_MIN;
        for(int i=0;i<accounts.size();i++){
            int currsum=0;
            for(int j=0;j<accounts[i].size();j++){
                currsum+=accounts[i][j];
            }
            maxi=max(maxi,currsum);            
        }
        return maxi;
    }
};