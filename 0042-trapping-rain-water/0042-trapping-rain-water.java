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