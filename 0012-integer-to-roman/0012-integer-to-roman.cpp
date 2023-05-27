class Solution {
public:
    string intToRoman(int num) {
        vector<string> rom = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        vector<int> roi = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        string ans = "";
        while(num>0){
            for(int i=roi.size()-1;i>=0;i--){
                if(num>=roi[i]){
                    num-=roi[i];
                    ans+=rom[i];
                    break;
                }
            }
        }
        return ans;
    }
};