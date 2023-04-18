class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        st.push(-1);
        int n = nums2.size();
        vector<int> ans(n);
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]=-1;
        }
        int i=0,j=0;
        j=n-1;
        while(j>=0){
            while(st.top() < nums2[j] && st.top() != -1){
                st.pop();
            }
            ans[j]=st.top();
            st.push(nums2[j]);
            if(mp.find(nums2[j]) != mp.end())
                mp[nums2[j]]=ans[j];
            j--;
        }
        vector<int> res;
        for(int k=0;k<nums1.size();k++){
            res.push_back(mp[nums1[k]]);
        }
        return res;
    }
};