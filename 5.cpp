#include <stdio.h>
#include <stack>

struct ListNode{
	int	m_nKey;
	ListNode* m_pNext;
};

void PrintListReversingly_Iteratively(ListNode* pHead){
	std::stack<ListNode*> nodes;
	ListNode* pNode = pHead;
	while(pNode != NULL){
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	
	while(!nodes.empty()){
		pNode = nodes.top();
		printf("%d ",pNode->m_nKey);
		nodes.pop();
	}
	printf("\n");
}

void PrintListReveringly_Recursively(ListNode* pNode){
	if(pNode != NULL){
		if(pNode->m_pNext != NULL){
			PrintListReveringly_Recursively(pNode->m_pNext);
		}
		printf("%d ",pNode->m_nKey);
	}
}

void ConnectList(ListNode* pCurrent,ListNode* pNext){
	pCurrent->m_pNext = pNext;
}

ListNode* CreateListNode(int value){
	ListNode* pNode = new ListNode();
	pNode->m_nKey = value;
	pNode->m_pNext = NULL;
	return pNode;
}

ListNode* InitLinkList(){
	ListNode* node1 = CreateListNode(1);
	ListNode* node2 = CreateListNode(2);
	ListNode* node3 = CreateListNode(3);
	ListNode* node4 = CreateListNode(4);
	ListNode* node5 = CreateListNode(5);
	
	ConnectList(node1,node2);
	ConnectList(node2,node3);
	ConnectList(node3,node4);
	ConnectList(node4,node5);
	return node1;
} 

int main(){
	ListNode* pHead = InitLinkList();
	PrintListReversingly_Iteratively(pHead);
	PrintListReveringly_Recursively(pHead);
	return 0;
}