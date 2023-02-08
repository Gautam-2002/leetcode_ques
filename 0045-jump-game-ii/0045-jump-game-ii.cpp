class Solution {
public:
    int jump(vector<int>& nums) {
        // The starting range of the first jump is [0, 0]
        int answer = 0, n = int(nums.size());

        int curEnd = 0, curFar = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest reachable index of this jump.
            curFar = max(curFar, i + nums[i]);

            // If we finish the starting range of this jump,
            // Move on to the starting range of the next jump.
            if (i == curEnd) {
                answer++;
                curEnd = curFar;
            }
        }
        
        return answer;
    }
};
// class Solution {
// public:
//     void solve(vector<int>& arr,int &ans,int idx,int j){
//         if(idx >= arr.size()-1){
//             ans = min(ans,j);
//             return;
//         }
//         if(idx+arr[idx]>=arr.size()-1){
//             ans = min(ans,j+1);
//             return;
//         }
//         for(int i = arr[i]; i >= 0; i){
//             solve(arr,ans,idx+i,j+1);
//         }
//     }
//     int jump(vector<int>& nums) {
//         int ans = INT_MAX;
//         solve(nums,ans,0,0);
//         return ans;
//     }
// };