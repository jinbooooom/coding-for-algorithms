### [1-两数之和](https://leetcode-cn.com/problems/two-sum/)(哈希)
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

**示例:**

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

**思路：**

使用hashmap。

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        map<int, int> index;
        vector<int> id(2);
        for (int i = 0; i < size; ++i)
        {
            index[nums[i]] = i;
        }
        for (int i = 0; i < size; ++i)
        {
            if (index.count(target - nums[i]) && index[target - nums[i]] != i)
            {
                id[0] = i;
                id[1] = index[target - nums[i]];
                return id;
            }
        }
        return id;
    }
};
```

### [2-两数相加](https://leetcode-cn.com/problems/add-two-numbers)(链表)

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

**示例：**

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

```C++
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
        int carry = 0;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *head = new ListNode(0);
        ListNode *p = head;
        int s, x, y = 0;
        while (p1 || p2)
        {
            if (p1 && p2)
                s = p1->val + p2->val + carry;
            else if (p1 && !p2)
                s = p1->val + carry;
            else if (!p1 && p2)
                s = p2->val + carry;
            x = s % 10;
            carry = s / 10;
            p->next = new ListNode(x);
            p = p->next;
            if (p1)
                p1 = p1->next;
            if (p2)
                p2 = p2->next;
        }
        if (carry)
            p->next = new ListNode(carry);
        return head->next;
    }
};
```



###  从排序数组中删除重复项 

给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组**并在使用 O(1) 额外空间的条件下完成。