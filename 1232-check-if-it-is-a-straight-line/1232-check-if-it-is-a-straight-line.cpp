class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n=coordinates.size();

        if (n < 3 ) return true;

        vector<int> point1, point2, point3;
        int x1, y1, x2, y2, x3, y3, a;


        for (int i=1; i<n-1; i++) {
            
            point1 = coordinates[i-1]; x1 = point1[0]; y1 = point1[1];
            point2 = coordinates[i]; x2 = point2[0]; y2 = point2[1];
            point3 = coordinates[i+1]; x3 = point3[0]; y3 = point3[1];

            a = x1 * (y2-y3) + x2 * (y3-y1) + x3 * (y1-y2);

           if (a) return false;

        }

        return true;
    }
};