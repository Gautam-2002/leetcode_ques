class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        vector<char> v;
        for(int i=0;i<chars.size();i++){
            char ch = chars[i];
            s+= ch;
            v.push_back(ch);
            int x = 1;i++;
            while(i<chars.size() && chars[i]==ch){
                x++;i++;
            }
            if(i!=chars.size())
                i--;
            if(x!=1){
                string y = to_string(x);
                s+=y;
                for(auto q:y)
                    v.push_back(q);
            }
        }
        chars = v;
        return s.size();
    }
};