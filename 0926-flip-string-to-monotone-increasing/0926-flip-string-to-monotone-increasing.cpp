class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countflip = 0; // 0->1 || 1->0
        int countOne = 0;
        for(auto i:s){
            if(i=='1')countOne+=1;
            else{
                countflip = min(countflip+1,countOne);
            }
        }
        return countflip;
    }
};