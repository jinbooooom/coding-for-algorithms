void deleteNode(ListNode* pListHead, ListNode* pToBeDeleted)
{
	if (pListHead == nullptr || pToBeDeleted == nullptr)
		return;
	if (pToBeDeleted->next != nullptr)  // 要删除的节点不是尾节点
	{
		ListNode* pNext = pToBeDeleted->next;
		pToBeDeleted->val = pNext->val;
		pToBeDeleted->next = pNext->next;

		delete pNext;
		pNext = nullptr;
	}
	else if(pListHead == pToBeDeleted)	// 链表只有一个节点，删除头节点
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
		pListHead = nullptr;
	}
	else								// 链表中有多个节点，且要删除的节点是尾节点
	{
		ListNode* pNode = pListHead;
		while (pNode->next != pToBeDeleted)
		{
			pNode = pNode->next;
		}
		pNode->next = nullptr;
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}