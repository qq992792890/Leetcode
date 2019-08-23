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
        long long num1 = 0, i = 0; 
        long long num2 = 0, j = 0;
        ListNode *pos1 = l1;
        ListNode *pos2 = l2;
        long temp = 0;
        while (pos1)
        {
            num1 = num1 * 10 + pos1->val;
            //i++;
            pos1 = pos1->next;
        }
        while (pos2)
        {
            temp = 1;
            for (int k = 0; k < j; k++)
            {
                temp = temp * 10;
            }
            num2 = num2 + pos2->val * temp;
            j++;
            pos2 = pos2->next;
        }
        
        long long result = num1 + num2;
        long long value = 0;
        ListNode *res = NULL;
        ListNode *tmp = NULL;
        
        while (result != 0)
        {
            value = result % 10;
            result = result / 10;
            if (res == NULL)
            {
                // ListNode node1(value);
                res = new ListNode(value);
            }else
            {
                // ListNode node2(value);
                // node2.next = res;
                tmp = new ListNode(value);
                tmp->next = res;
                res = tmp;
            }
            
            
            

        }
        return res;
        
    }
};

