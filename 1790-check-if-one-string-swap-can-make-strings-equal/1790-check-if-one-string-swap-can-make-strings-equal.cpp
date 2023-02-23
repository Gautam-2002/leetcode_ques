class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int x = 0;
        pair<char,int> a = make_pair('^',-1);
        pair<char,int> b = make_pair('^',-1);
        for(int i = 0 ;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                x++;
                if(x>2)return false;
                if(a.second==-1 && b.second==-1){
                    a=make_pair(s1[i],i);
                    b=make_pair(s2[i],i);
                }
                else{
                    if(s1[i]==b.first && s2[i]==a.first){
                        x=2;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(x==0||x==2)
            return true;
        return false;
    }
};