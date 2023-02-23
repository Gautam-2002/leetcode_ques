class Solution {
public:
    int arraySign(vector<int>& nums) {
        int pl = 0,ng = 0;
        for(auto i:nums){
            if(i==0)
                return 0;
            else if(i<0){
                ng++;
            }
            else{
                pl++;
            }
        }
        if(ng&1)return -1;
        else return 1;
    }
};