/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p1 = head,*p2 = head;
        int cnt = 0;
        if (head == NULL)
        {
            return NULL;
        }
        
        while (p2->next != NULL)
        {
            if (p2->next->val == p1->val)
            {//重复数在结尾如何处理
                p2 = p2->next;
                cnt += 1;
                
                continue;
            }else
            {
                if (cnt != 0)
                {
                    p1->next = p2->next;
                }
                p1 = p2->next;
                p2 = p1;
                cnt = 0;
            }
            
            
        }
        if (p2->next == NULL && cnt != 0)
        {
            p1->next = NULL;
        }
        
        return head;
        
    }
};

