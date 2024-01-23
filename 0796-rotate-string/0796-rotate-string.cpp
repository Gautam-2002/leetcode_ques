class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(),m = goal.size();
        if(n!=m)return false;
        int i=0,j=0;
        while(i<n && j<n){
            while(j<n && s[i]!=goal[j]){
                j++;
                // cout<<j<<"@";
            }
            if(j==n)return false;
            // cout<<i<<"*"<<j<<"*"<<endl;
            int y = j;
            while(j<n){
                if(s[i]!=goal[j]){
                    i = 0;
                    j = y+1;
                    // y=-1;
                    break;
                }
                i++;j++;
            }
            
        }
        int k = n-i;//cout<<i<<"*"<<j<<"*"<<k<<endl;
        for(int l=0;l<k;l++){
            if(goal[l]!=s[i++])return false;
        }
        return true;
    }
};
//aeme eame