class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v;
        int x = n;
        while(x>0){
            v.push_back(x%10);
            x/=10;
        }
        reverse(v.begin(),v.end());
        int a = v[0];
        next_permutation(v.begin(),v.end());
        if(a>v[0])return -1;
        long long ans = 0;
        for(auto i:v){
            if((ans*10)+i > INT_MAX)return -1;
            ans*=10;
            ans+=i;
        }
        if(ans==n)return -1;
        return (int)ans;
    }
};