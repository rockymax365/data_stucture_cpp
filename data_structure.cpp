#include<iostream>
#include<cassert>
using namespace std;


//二分查找
int binarySearch(int arr[], int n, int val)
{
	assert(arr != NULL && n > 0);
	int index = -1;
	int l = 0, r = n - 1;
	while (l <= r)
	{
		int mid = l +(r - l) / 2;   //防溢出
		if (arr[mid] > val)
			r = mid - 1;
		else if (arr[mid] < val)
			l = mid + 1;
		else
		{
			index = mid;
			break;
		}
	}
	
	return index;
}

//反转链表
struct ListNode {
	int val;
	ListNode *pNext;
	ListNode(int value, ListNode* next = NULL)
	{
		val = value;
		pNext = next;
	}
};

ListNode* reverseLinkedList(ListNode* head)
{
	if (head == NULL)
		return head;
	ListNode* preNode = NULL;
	ListNode* curNode = head;
	ListNode* reverseHead = NULL;
	while (curNode != NULL)
	{
		ListNode* nextNode = curNode->pNext;
		if (nextNode == NULL)
			reverseHead = curNode;

		curNode->pNext = preNode;
		preNode = curNode;
		curNode = nextNode;
	}

	return reverseHead;
}



int main(void)
{
	int arr_ordered[10] = { 0,1,2,3,8,9,11,12,23,56 };
	int arr[10] = { 9,4,5,7,6,2,3,1,8,0 };

	int val = 12;
	int index = -1;

	index = binarySearch(arr_ordered, 10, val);


	return 0;
}