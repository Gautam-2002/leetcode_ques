class Solution {
public:
    static bool cmp(int a,int b){
        bitset<32> x(a);
        bitset<32> y(b);
        int p = x.count();
        int q = y.count();
        if(p==q)
            return a<b;
        return p<q;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};


// //Approach-1 (Simply counting 1 bits using bit manipulation) (8 ms)
// class Solution {
// public:
//     vector<int> sortByBits(vector<int>& arr) {
//         auto lambda = [](int &x, int &y) {
//             int x_1 = 0;
//             int y_1 = 0;
            
//             int temp_x = x;
//             int temp_y = y;
            
//             while(temp_x) {
//                 temp_x = temp_x & (temp_x-1);
//                 x_1++;
//             }
            
//             while(temp_y) {
//                 temp_y = temp_y & (temp_y-1);
//                 y_1++;
//             }
            
//             if(x_1 == y_1)
//                 return x < y;
            
//             return x_1<y_1;
//         };
        
//         sort(begin(arr), end(arr), lambda);
//         return arr;
//     }
// };
// //Approach-2 (Using C++ bitset) (4 ms)
// class Solution {
// public:
//     vector<int> sortByBits(vector<int>& arr) {
//         auto lambda = [](int &x, int &y) {
//             bitset<32> b_x(x);
//             bitset<32> b_y(y);
            
//             int x_1 = b_x.count();
//             int y_1 = b_y.count();
            
//             if(x_1 == y_1)
//                 return x < y;
            
//             return x_1<y_1;
//         };
        
//         sort(begin(arr), end(arr), lambda);
//         return arr;
//     }
// };


// //Approach-3 (Using __builtin_popcount -  built in function of GCC) (0 ms)
// //Note that it's not in C++. It's just a built in function of GCC
// class Solution {
// public:
//     vector<int> sortByBits(vector<int>& arr) {
//         auto lambda = [](int &x, int &y) {
//             int x_1 = __builtin_popcount(x);
//             int y_1 = __builtin_popcount(y);
                
//             if(x_1 == y_1)
//                 return x < y;
            
//             return x_1<y_1;
//         };
        
//         sort(begin(arr), end(arr), lambda);
//         return arr;
//     }
// };
