class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int l = 0,r = n-1;
        int ans = 0;
        int maxleft = 0,maxright = 0;
        while(l<r){
            if(height[l] <= height[r]){
                if(height[l] > maxleft)maxleft = height[l];
                else ans += maxleft-height[l];
                
                l++;
            }
            else{ // means (height[l] > height[r])
                if(height[r] > maxright)maxright = height[r];
                else ans += maxright-height[r];
                
                r--;
            }
        }
        return ans;
    }
}

// o(2n) space sol:
// class Solution {
// public:
//     int trap(vector<int>& height)
//     {
//         if(height.empty())
//             return 0;
//         int ans = 0;
//         int size = height.size();
//         vector<int> left_max(size), right_max(size);
//         left_max[0] = height[0];
//         for (int i = 1; i < size; i++) {
//             left_max[i] = max(height[i], left_max[i - 1]);
//         }
//         right_max[size - 1] = height[size - 1];
//         for (int i = size - 2; i >= 0; i--) {
//             right_max[i] = max(height[i], right_max[i + 1]);
//         }
//         for (int i = 1; i < size - 1; i++) {
//             ans += min(left_max[i], right_max[i]) - height[i];
//         }
//         return ans;
//     }
// };