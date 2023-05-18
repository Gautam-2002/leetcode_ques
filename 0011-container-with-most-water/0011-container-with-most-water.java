class Solution {
    public int maxArea(int[] height) {
        int ans = 0;
        int i=0,j=height.length-1;
        while(i<j){
            int l = Math.min(height[i],height[j]);
            int b = j-i;
            ans = Math.max(ans,l*b);
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
}
// O(N*N) approach
// class Solution {
//     public int maxArea(int[] height) {
//         int ans = 0;
//         for(int i=0;i<height.length-1;i++){
//             int j=height.length-1;
//             while(i<j){
//                 int l = Math.min(height[i],height[j]);
//                 int b = j-i;
//                 ans = Math.max(ans,l*b);
//                 j--;
//             }
//         }
//         return ans;
//     }
// }