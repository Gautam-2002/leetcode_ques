class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newEvent) {
        int N = intervals.size();
        vector<vector<int>> ans;
        int i = 0;
        while(i < N && newEvent[0] > intervals[i][1])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while(i < N && newEvent[1] >= intervals[i][0]){
            newEvent[0] = min(intervals[i][0],newEvent[0]);
            newEvent[1] = max(intervals[i][1],newEvent[1]);
            i++;
        }
        ans.push_back(newEvent);
        while(i<N){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};