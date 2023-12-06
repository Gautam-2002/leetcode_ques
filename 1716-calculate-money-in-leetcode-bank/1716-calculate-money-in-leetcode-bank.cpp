class Solution {
public:
    int totalMoney(int n) {
        int x = 1, t = 1;
        int amount = 0;
        int day = 1;
        while(n>0){
            amount += x;
            if(day == 7){
                day = 0;
                x = t;
                t++;
            }
            x+=1;
            day++;
            n--;
        }
        return amount;
    }
};