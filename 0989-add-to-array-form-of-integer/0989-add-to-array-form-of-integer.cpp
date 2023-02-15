class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(),num.end());
        int i = 0;
        int s = 0;
        int c = 0;
        while((k>0||c>0) && i<num.size()){
            s = num[i]+(k%10)+c;
            k/=10;
            int x = s/10;
            s=s%10;
            num[i++]=s;
            c = x;
        }
        if(k>0 && i==num.size()){
            int z = c+(k%10);
            k/=10;
            num.push_back(z%10);
            c=z/10;
            while(k>0){
                z = (k%10)+c;
                num.push_back(z%10);
                c=z/10;
                k/=10;
            }
            if(c!=0)num.push_back(c);
        }
        else if(c!=0 && i==num.size())num.push_back(c);
        else if(c!=0){
            int x = num[i]+c;
            while(x>9 && i<num.size()){
                x = num[i]+c;
                num[i]=x%10;
                c=x/10;
                i++;
            }
            if(c!=0 && i==num.size())num.push_back(c);
        }
        reverse(num.begin(),num.end());
        return num;
    }
};