/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

//最简单暴力的方法，直接递归比对所有节点
//方法一
    // bool checktree(TreeNode *p, TreeNode *q) {
    //     if (!p && !q) return true;
    //     if (!p || !q) return false;
    //     return p->val == q->val && checktree(p->left, q->right) && checktree(p->right, q->left);//镜像需要达成的条件
    // }
    // bool isSymmetric(TreeNode* root) {
    //     return checktree(root, root);
    }
//方法一


//方法二 迭代递归一般都对应迭代
 bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left); 
            q.push(v->right);

            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
//方法一 迭代递归一般都对应迭代

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/symmetric-tree/solution/dui-cheng-er-cha-shu-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


};
// @lc code=end

