class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxAr=INT_MIN;
        int i=0,j=n-1;
        while(i<j){
            int w=j-i;
            int h=min(height[i],height[j]);
            int currAr=h*w;
            maxAr=max(maxAr,currAr);
            if(height[i]<height[j])i++;
            else j--;
        }
        return maxAr;
    }
};