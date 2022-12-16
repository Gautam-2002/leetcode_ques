class Solution {
public:
    void merge(vector<int> &cnt,vector<pair<int,int>> &v,int s,int e){
        vector<pair<int,int>> temp(e-s+1);
        int m = s+(e-s)/2;
        int i = s;
        int j = m+1;
        int k = 0;
        while(i<=m && j<=e){
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }
            else{
                cnt[v[i].second] += e - j + 1;
                temp[k++] = v[i++];
            }
        }
        while(i <= m){
            temp[k++] = v[i++];
        }
        while(j <= e){
            temp[k++] = v[j++];
        }
        for(int x = s;x <= e;x++){
            v[x] = temp[x-s];
        }
    }
    void mergeSort(vector<int> &cnt,vector<pair<int,int>> &v,int s,int e){
        if(s>=e)return;
        
        int mid = s+(e-s)/2;
        mergeSort(cnt,v,s,mid);
        mergeSort(cnt,v,mid+1,e);
        
        merge(cnt,v,s,e);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i] = make_pair(nums[i],i);
        }
        
        vector<int> count(n,0);
        mergeSort(count,v,0,n-1);
        return count;
    }
};