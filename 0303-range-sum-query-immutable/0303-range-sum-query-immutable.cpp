class NumArray {
public:
    vector<int> temp;
    NumArray(vector<int>& nums) {
        // prefix sum
        temp.resize(nums.size()+1);
        temp[0]=0;
        for(int i=0;i<nums.size();i++){
            temp[i+1] = nums[i]+temp[i];
        }
    }
    
    int sumRange(int left, int right) {
        return temp[right+1]-temp[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */