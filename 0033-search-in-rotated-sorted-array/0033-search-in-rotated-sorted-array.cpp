class Solution {
public:
    int getPivot(vector<int>& nums){
        int l=0;int r=nums.size()-1;
        int mid = l+(r-l)/2;
        while(l<r){
            if(nums[mid]>=nums[0]){
                l = mid+1;
            }
            else{
                r= mid;
            }
            mid = l+(r-l)/2;
        }
        return l;
    }
    int binarySearch(vector<int>& nums, int l, int r,int target ){
        int mid = l + (r-l)/2;
        while(l<=r){
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
            mid = l + (r-l)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = getPivot(nums);
        if(target >= nums[pivot] && target <= nums[nums.size()-1]){
            return binarySearch(nums,pivot,nums.size()-1,target);
        }
        else{
            return binarySearch(nums,0,pivot-1,target);
        }
    }
};