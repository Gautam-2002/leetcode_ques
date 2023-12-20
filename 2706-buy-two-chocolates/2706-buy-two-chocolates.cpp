class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int a=INT_MAX,b=INT_MAX,c=INT_MAX;
        for(auto i:prices){
            if(a>i){
                // c = min(c,a);
                b = a;
                a = i;
            }
            else if(b>i){
                // b = min(c,i);
                b = i;
            }
            // cout<<a<<" "<<b<<" "<<c<<endl;
        }
        // b = min(b,c);
        int x = (money-a-b);
        if(x >=0 ) return x;
        else return money;
    }
};