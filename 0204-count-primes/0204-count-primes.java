class Solution {
    public int countPrimes(int n) {
        if( n==0 || n==1)return 0;
        boolean []arr = new boolean[n+1];
        arr[0]=true;
        arr[1]=true;
        for(int i =2;i*i<=n;i++){
            if(arr[i]==false){
                for(int mul = 2;i*mul<=n;mul++){
                    arr[i*mul]=true;
                }
            }
        }
        int ans = 0;
        for(int i =0;i<n;i++){
            if(arr[i]==false)
                ans++;
        }
        return ans;
    }
}