/*
https ://leetcode-cn.com/problems/palindrome-linked-list
请判断一个链表是否为回文链表。
示例 1:
输入: 1->2
	输出 : false

	示例 2 :
	输入 : 1->2->2->1
	输出 : true
*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        /*
	提示：
	方法一：快慢指针+链表翻转
	先用快慢指针找到中心节点（过程中反转慢指针前的节点），
	然后从中间分开成两个链表，然后开始逐个比对看是否相等。
	*/
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode *pre = nullptr;
        ListNode *pNode = nullptr;
        ListNode *pSlow = head;
        ListNode *pFast = head;

        while (pFast && pFast->next)
        {
            pNode = pSlow;
            pFast = pFast->next->next;
            pSlow = pSlow->next;
            pNode->next = pre;  // 翻转前半部分
            pre = pNode;        // 保留前面的节点
        }

        ListNode *p1 = nullptr, *p2 = nullptr;
        if (pFast) // 链表长度为奇数
        {
            p1 = pNode;
            p2 = pSlow->next;
        }
        else
        {
            p1 = pNode;
            p2 = pSlow;
        }

        while (p1 && p2)
        {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }

    bool isPalindrome2(ListNode *head)
    {
        /*
	方法二：快慢指针+栈
	先用快慢指针找中点，边找边入栈；
	再依次比对中心结点后的数据和出栈的数据是否相等
	*/
    }
};