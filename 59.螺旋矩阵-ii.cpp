/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //Java solution change to C++ solution
         int l = 0, r = n - 1, t = 0, b = n - 1;
        // int[][] mat = new int[n][n];
        vector<vector<int>> mat(n, vector<int>(n));
        //
        int num = 1, tar = n * n;
        while(num <= tar){
            for(int i = l; i <= r; i++) mat[t][i] = num++; // left to right.
            t++;//change top boundary 
            for(int i = t; i <= b; i++) mat[i][r] = num++; // top to bottom.
            r--;//change right boundary
            for(int i = r; i >= l; i--) mat[b][i] = num++; // right to left.
            b--;//change bottom boundary
            for(int i = b; i >= t; i--) mat[i][l] = num++; // bottom to top.
            l++;//change left boundary
        }
        return mat;

// 作者：jyd
// 链接：https://leetcode-cn.com/problems/spiral-matrix-ii/solution/spiral-matrix-ii-mo-ni-fa-she-ding-bian-jie-qing-x/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
        
    }
};
// @lc code=end

