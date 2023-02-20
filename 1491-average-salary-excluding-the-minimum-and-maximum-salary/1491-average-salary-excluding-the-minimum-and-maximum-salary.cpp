class Solution {
public:
    double average(vector<int>& salary) {
        int mini = salary[0];
        int maxi = salary[0];
        double ans = 0;
        for(auto i : salary){
            ans+=i;
            maxi = max(maxi,i);
            mini = min(mini,i);
        }
        ans -= mini;
        ans -= maxi;
        return double(ans/(salary.size()-2));
    }
};