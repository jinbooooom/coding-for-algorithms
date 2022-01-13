/*
题目：
在列表中删除一个节点，要求时间复杂度 O(1)

提示：
    由于不知道该节点的前驱，那就只能把后缀赋给该节点，然后将该节点的 next 指向下个节点的下一个节点。
    如 a->b->c->i->j->k->z->None，要删除 i，由于不知道 i 的前驱，那就把 j 的值赋给 i，然后让 i.next 指向 k，就相当于删除 i 了。
    特殊情况：
        1，若该节点就是尾节点，那就只能通过 head 指针顺序找到该尾节点的前驱，然后让该前驱的指针域指向 None
        2，若链表中只有一个节点，要删除该节点，把链表的头节点设置为 None
*/
void deleteNode(ListNode *pListHead, ListNode *pToBeDeleted)
{
	if (pListHead == nullptr || pToBeDeleted == nullptr)
		return;
	if (pToBeDeleted->next != nullptr) // 要删除的节点不是尾节点
	{
		ListNode *pNext = pToBeDeleted->next;
		pToBeDeleted->val = pNext->val;
		pToBeDeleted->next = pNext->next;

		delete pNext;
		pNext = nullptr;
	}
	else if (pListHead == pToBeDeleted) // 链表只有一个节点，删除头节点
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		pListHead = nullptr;
	}
	else // 链表中有多个节点，且要删除的节点是尾节点
	{
		ListNode *pNode = pListHead;
		while (pNode->next != pToBeDeleted)
		{
			pNode = pNode->next;
		}
		pNode->next = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}