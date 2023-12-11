class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ans = 0;
        // int x = ;
        for(int i:batteryPercentages ){
            if(i-ans>0){
                ans++;
            }
        }
        return ans;
    }
};