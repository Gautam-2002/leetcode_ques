class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.size(),n=b.size(),i;
        if(m>=n){
        a[m-1]+=b[n-1]-'0';
        for(i=1;i<n;i++)
        {
            a[m-1-i]+=b[n-1-i]-'0'+(a[m-i]-'0')/2;
            if((a[m-i]-'0')%2==0)a[m-i]='0';
            else a[m-i]='1';
        }
        while(i<m&&a[m-i]>'1'){
            a[m-i-1]+=1;
            if((a[m-i]-'0')%2==0)a[m-i]='0';
            else a[m-i]='1';
            i++;
            }
            if(a[0]>'1'){
                a[0]-=2;
                a.insert(0,"1");
            }
            return a;
        }
        else
        {
            b[n-1]+=a[m-1]-'0';
        for(i=1;i<m;i++)
        {
            b[n-1-i]+=a[m-1-i]-'0'+(b[n-i]-'0')/2;
            if((b[n-i]-'0')%2==0)b[n-i]='0';
            else b[n-i]='1';
        }
        while(i<n&&b[n-i]>'1'){
            b[n-i-1]+=1;
            if((b[n-i]-'0')%2==0)b[n-i]='0';
            else b[n-i]='1';
            i++;
            }
            if(b[0]>'1'){
                b[0]='0';
                b.insert(0,"1");
            }
            return b;
        }
        return a;
    }
};