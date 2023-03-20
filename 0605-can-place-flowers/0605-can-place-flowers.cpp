class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size() < n)return false;
        if(flowerbed.size()==1)
            return (n==1&&flowerbed[0]==0)||(n==0)?true:false;
        int cnt = 0;
        int i = 0;
        if(flowerbed[0]==0 && flowerbed[1]==0){
            cnt++;
            i = 2;
        }
        else{
            i = 1;
        }
        for(;i<flowerbed.size();i++){
            // cout<<i<<"*"<<cnt<<endl;
            if(i==flowerbed.size()-1){
                if(flowerbed[i]==0&&flowerbed[i-1]==0)cnt++;
                break;
            }
            else if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                cnt++;
                i++;
            }
            // cout<<i<<"^"<<cnt<<endl;
        }
        if(cnt>=n)return true;
        return false;
    }
};