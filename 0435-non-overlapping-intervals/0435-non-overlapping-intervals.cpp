bool cmpWithSecondElement(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
// refer to solution section this is greedy approch
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmpWithSecondElement);
        int ans = 0,k=INT_MIN;
        
        for(int i=0;i<intervals.size();i++){
            int x = intervals[i][0];
            int y = intervals[i][1];
            if(x >= k){
                // case 1
                k = y;
            }
            else{
                // case 2
                ans++;
            }
        }
        
        return ans;        
    }
};