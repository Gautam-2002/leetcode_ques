class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int r = matrix.length;
        int c = matrix[0].length;
        int s = 0;
        int e = r*c-1;
        int mid ;
        while(s<=e){
            mid = s+(e-s)/2;
            int element = matrix[mid/c][mid%c];
            if(element==target)
                return true;
            else if(element<target)
                s = mid+1;
            else
                e = mid-1;
        }
        return false;
    }
}