/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
采用一种遍历方式访问所有元素 两数的访问结果一致就说明相同
或者遍历访问元素时判断两数对应节点数是否相等，碰到不等的就跳出 可同时保存访问结果
遍历访问树较实现也较容易理解
循环访问比较难，现在还不太懂190915
将树转换为线性表或向量组 然后依次判断即可
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p || !q) return p == q; 
        vector<TreeNode *> stack_p;
        stack_p.push_back(p);
        vector<TreeNode *> stack_q;
        stack_q.push_back(q);
        TreeNode *pnode, *qnode;
        while (!stack_p.empty() || !stack_q.empty())
        {
            pnode = stack_p.back();
            stack_p.pop_back();
            qnode = stack_q.back();
            stack_q.pop_back();
            if (pnode == NULL && qnode == NULL)
            {
                continue;
            }
            if (pnode == NULL || qnode == NULL)
            {
                return false;
            }
            if (pnode->val != qnode->val)//中序遍历 中左右的结构
            {
                return false;
            }else
            {//先入栈右节点则先访问左节点
                stack_p.push_back(pnode->right);
                stack_p.push_back(pnode->left);
                stack_q.push_back(qnode->right);
                stack_q.push_back(qnode->left);
            }

        }
        
        //全部遍历结束则两树相同
        return true;
    }
};

