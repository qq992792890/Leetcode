/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        if (l1 == NULL && l2 == NULL)
            return NULL;
        ListNode *pos2 = NULL;
        ListNode *pos1 = NULL;
        ListNode *temp = NULL;
        if (l2->val >= l1->val)
        { //whose head node small as mother
            pos2 = l2;
            pos1 = l1;
        }
        else
        {
            pos2 = l1;
            pos1 = l2;
        }
        ListNode *res = pos1;
        //insert node of big link to small link one by one
        while (pos2 != NULL)
        {
            while (pos1 != NULL)
            {
                if (pos1->next == NULL)//if all the node after pos2 will follow pos1->next
                {
                    pos1->next = pos2;
                    pos2 = NULL;
                    break;
                }
                if (pos2->val >= pos1->val && pos2->val <= pos1->next->val)
                {
                    temp = pos2;
                    pos2 = pos2->next;

                    temp->next = pos1->next;
                    pos1->next = temp;

                    pos1 = pos1->next;

                    if (pos2 == NULL)
                    {
                        break;
                    }
                }
                else
                {
                    pos1 = pos1->next;
                    
                    
                }
            }
        }
        return res;
    }
};

