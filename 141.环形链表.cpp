/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *follow = NULL;
        while (head)
        {
            follow = head->next;
            head->next = prev;
            prev = head;
            head = follow;
        }
        return prev;
    }

    //本方案是实在没想到除了遍历查找重复出现的节点 之外的其他办法
    //参考的Leetcode的高票答案
    //实际上还有一种办法，双指针法，一个移动快一个移动慢。
    //快指针每次移动2节点，慢指针每次移动一节点，没有环的话
    //快指针更块到达尾部，有环则快指针会追上慢指针！！
    bool hasCycle(ListNode *head) {
        ListNode *rev = reverseList(head);
        if (head && head->next && rev == head)
        {
            return true;
        }
        return false;
    }
};

