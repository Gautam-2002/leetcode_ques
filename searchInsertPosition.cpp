class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        if(target<arr[0])return 0;
        int l=0;
        int r=arr.size()-1;
        int mid=l+(r-l)/2;
        int near=0;
        while(l<=r){
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]<target){
                near=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
            mid=l+(r-l)/2;
        }
        
        return near+1;
    }
};