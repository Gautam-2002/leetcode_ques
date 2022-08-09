class Solution { // not optimized (O((n+m)*log(n+m))) used inbuilt func.
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m,j=0;i<m+n;i++){
            nums1[i]=nums2[j];
            j++;
        }
        sort(nums1.begin(),nums1.end());
        return;
    }
};
// BETTER APPROACH USING TWO-POINTER 
// class Solution { // solution from discussion form
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i = m-1;
//         int j =n-1;
//         int tar = n+m-1;
        
//         while (j >=0){
//             if (i>=0 && nums1[i] > nums2[j]){
//                 nums1[tar] = nums1[i];
//                 tar -=1;
//                 i -=1;
//             }
//             else{
//                 nums1[tar] = nums2[j];
//                 tar -=1;
//                 j -=1;
//             }
//         }
//     }
// };
