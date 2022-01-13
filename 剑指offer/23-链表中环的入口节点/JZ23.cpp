/**
 * 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出 null。
*/

class Solution
{
public:
    /**
    *      
    提示：
    假设有环，且知道环中节点的个数设为 n，那么设置两个指针 p1, p2 分别指向头节点，现在使 p2 先移动 n 步，p1 不动，
    再使 p1, p2 同时移动，那么当 p1, p2 相遇时，p1 指针指向的节点就是入口节点。

    如何求环中节点个数 n?
    设置两个指针，一快一慢，最开始都指向头节点。快指针 pFast 每次移动 2 步，慢指针 pSlow 每次移动 1 步，
    若 pFast 能到达尾节点，则说明无环；
    若 pFast 能相遇，说明有环，当相遇时，慢指针 pSlow 保持位置不变，
    快指针改为每次移动 1 步，直到再次与慢指针相遇，移动了多少步，环中就含有多少个节点。设节点数为 k，
    此时，再让两个指针 p1, p2 从 head 节点开始移动，p2 先移动 k 次，
    然后 p1, p2 同时移动，它们相遇的位置即是环的入口。
    */
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        if (pHead == nullptr)
            return nullptr;
        ListNode *pFast = pHead;
        ListNode *pSlow = pHead;

        while (pFast)
        {
            if (pFast->next && pFast->next->next)
            {
                pFast = pFast->next->next;
                pSlow = pSlow->next;
                if (pFast == pSlow)
                    break;
            }
            else // 此时链表无环
                return nullptr;
        }

        pFast = pFast->next;
        int NodeOfLoop = 1;
        while (pFast != pSlow)
        {
            pFast = pFast->next;
            ++NodeOfLoop;
        }
        if (NodeOfLoop == 1) // 环中只有一个结点，pSlow 就是环的入口结点
            return pSlow;

        ListNode *p1 = pHead;
        ListNode *p2 = pHead;
        while (NodeOfLoop)
        {
            p2 = p2->next;
            NodeOfLoop--;
        }
        while (p1 != p2)
        {
            p2 = p2->next;
            p1 = p1->next;
        }
        return p1;
    }
};