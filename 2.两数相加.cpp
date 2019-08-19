/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool overflow = false;
        int value = 0;
        ListNode *res = NULL, *tail = NULL;
        ListNode *pos1 = l1, *pos2 = l2;
        while (pos1 || pos2 || overflow)
        {   //sum = overflow + val1 + val2
            value = 0;
            value += overflow ? 1 : 0;
            if(pos1) value += pos1->val;
            if(pos2) value += pos2->val;

            overflow = value / 10;
            if (overflow) value -= 10;

            if (res)//other node
            {
                tail->next = new ListNode(value);
                tail = tail->next;
            }else//the first node
            {
                res = new ListNode(value);
                tail = res;
            }

            pos1 = pos1 != NULL ? pos1->next : NULL;
            pos2 = pos2 != NULL ? pos2->next : NULL; 
 
        }
        
        return res;
        
    }
};

