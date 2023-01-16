class Solution {
public:
    void merge(vector<vector<int>> &mergeIntervals,vector<vector<int>> &intervals){
        if(intervals.size()==0)
            return ;
        
        if(intervals.size()==1){
            mergeIntervals=intervals;
            return ;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> tempInterval=intervals[0];
        for(auto it : intervals){
            if(it[0]<=tempInterval[1]){
                tempInterval[1]=max(it[1],tempInterval[1]);
            }
            else{
                mergeIntervals.push_back(tempInterval);
                tempInterval=it;
            }
        }mergeIntervals.push_back(tempInterval);
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
//         vector<vector<int>> ans;
//         if(intervals.size()==0){
//             ans.push_back(newInterval);
//             return ans;
//         }
//         int f=-1;
//         for(int i=0;i<intervals.size();i++){
//             if(intervals[i][1]>=newInterval[0]){
//                 if(f==1){
//                     ans.push_back(intervals[i]);
//                     continue;
//                 }
//                 vector<int> temp = {min(newInterval[0],intervals[i][0]),max(intervals[i][1],newInterval[1])};
//                 ans.push_back(temp);
//                 f=1;
//             }
//             else{
//                 ans.push_back(intervals[i]);
//             }
//         }
//         if(f==-1){
//             ans.push_back(newInterval);
//             return ans;
//         }
        intervals.push_back(newInterval);
        vector<vector<int>> res;
        merge(res,intervals);
        
        return res;
    }
};