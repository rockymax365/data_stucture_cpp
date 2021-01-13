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
//字符串转整型
bool g_Isvalid = true;

long long str2IntCore(const char* str, bool minus)
{
    long long num = 0;
    
    int minusFlag = minus ? -1 : 1;
    while(*str != '\0')
    {
        if((*str - '0') >= 0 && (*str - '0') <= 9 )
        {
            num = num*10 + minusFlag*(*str - '0');
            if((!minus && num > (signed int)(0x7FFFFFFF)) || (minus && num < (signed int)(0x80000000)))
            {
                num = 0;
                break;
            }
        }
        else
        {
            num = 0;
            break;
        }
        
        str ++;
    }
    
    
    if(*str == '\0')
    {
        g_Isvalid = true;
    }
    
    return num;
}

int str2int(const char* str)
{
    assert(str != NULL);
    long long num = 0;
    bool minus = false;
    if(str[0] == '+')
    {
        str++;
    }
    else if(str[0] == '-')
    {
        minus = true;
        str++;
    }
    
    if(str[0] != '\0')
    {
        num = str2IntCore(str, minus);
    }
    
    
    return (int)num;
}

//判断链表是否有环

struct ListNode{
    int val;
    ListNode* pNext;
};


bool isLoop(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head;
    while(slow != NULL && fast != NULL && fast->pNext != NULL)
    {
        slow = slow->pNext;
        fast = fast->pNext->pNext;
        if(slow == fast)
            return true;
    }
    return false;
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

//冒泡排序
void bubbleSort(int arr[], int n)
{
    if(arr == NULL || n <= 0)
        return;
    for(int i = 0; i < n-1; i ++)
        for(int j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    return;
}
//选择排序
void selectSort(int arr[], int n)
{
    if(arr == NULL || n <= 0)
        return;
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for(int j=i; j<n; j++)
        {
            if(arr[min] > arr[j])
                min = j;
        }
        swap(arr[i],arr[min]);
    }
    return;
}

//插入排序
void insertSort(int arr[], int n)
{
    if(arr == NULL || n <= 0)
        return;
    for(int i=0; i<n; i++)
    {
        int j = i;
        for(; j>0; j--)
        {
            if(arr[j] < arr[j-1])
            {
                swap(arr[j], arr[j-1]);
            }
            else
            {
                break;
            }
        }
    }
    return;
}
//插入排序（另一个版本）
void insertSort1(int arr[], int n)
{
    if(arr == NULL || n <= 0)
        return;
    for(int i=1; i<n; i++)
    {
        int temp = arr[i];
        int j;
        for(j=i; j>0 && arr[j-1]>temp; j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = temp;
    }
    
    return;
}

//归并排序
void _merge(int arr[], int l, int mid, int r)
{
    int* aux = new int[r-l+1];
    for(int i=l; i<=r; i++)
    {
        aux[i-l] = arr[i];
    }
    int i = l;
    int j = mid +1;
    
    for(int k = l; k<=r; k++)
    {
        if(i > mid)
        {
            arr[k] = aux[j-l];
            j++;
        }
        else if(j > r)
        {
            arr[k] = aux[i-l];
            i++;
        }
        else if(aux[i-l] > aux[j-l])
        {
            arr[k] = aux[j-l];
            j++;
        }
        else if(aux[i-l] <= aux[j-l])
        {
            arr[k] = aux[i-l];
            i++;
        }
    }
    
    
    delete [] aux;
    return;
}

void _mergeSort(int arr[], int l, int r)
{
    if(l >= r)
        return;
    int mid = l + (r-l)/2;
    _mergeSort(arr, l, mid);
    _mergeSort(arr, mid+1,r);
    if(arr[mid] > arr[mid+1])
        _merge(arr, l, mid, r);
    
    return;
    
}

void mergeSort(int arr[], int n)
{
    if(arr == NULL || n <=0)
        return;
    _mergeSort(arr, 0, n-1);
}

//快速排序

int _partition(int arr[], int l, int r)
{
    swap(arr[l], arr[rand()%(r-l+1) + l]);
    int v = arr[l];
    int j = l;
    for(int i=l+1; i<=r; i++)
    {
        if(arr[i] <= v)
        {
            swap(arr[j+1], arr[i]);
            j++;
        }
    }
    swap(arr[l], arr[j]);
    
    
    return j;
}

void _quickSort(int arr[], int l, int r)
{
    if(l >= r)
        return;
    int p = _partition(arr, l, r);
    _quickSort(arr, l, p);
    _quickSort(arr, p+1, r);
    
    return;
    
}

void quickSort(int arr[], int n)
{
    if(arr == NULL || n <= 0)
        return;
    srand((unsigned int)time(NULL));
    _quickSort(arr, 0, n-1);
    
}

//是否是其子树
struct BinaryTreeNode {
	int val;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

bool doseTree1HasTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	if (pRoot2 == NULL)
		return true;
	if (pRoot1 == NULL)
		return false;
	if (pRoot1->val != pRoot2->val)
		return false;

	return doseTree1HasTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && doseTree1HasTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}

bool hasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
	bool res = false;
	if (pRoot1 != NULL && pRoot2 != NULL)
	{
		if (pRoot1->val == pRoot2->val)
		{
			res = doseTree1HasTree2(pRoot1, pRoot2);
		}
		if (!res)
		{
			res = hasSubtree(pRoot1->m_pLeft, pRoot2);
		}
		if (!res)
		{
			res = hasSubtree(pRoot1->m_pRight, pRoot2);
		}
	}
	return res;
}
//树深度

int treeDepth(BinaryTreeNode* root)
{
	if (root == NULL)
		return 0;
	int nLeft = treeDepth(root->m_pLeft);
	int nRight = treeDepth(root->m_pRight);

	return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}


//链表尾部添加节点
void addToTail(ListNode** pHead, int val)
{
	ListNode* newNode = new ListNode(val);
	if (*pHead == NULL)
	{
		*pHead = newNode;
	}
	else
	{
		ListNode* tempNode = *pHead;
		while (tempNode->pNext != NULL)
		{
			tempNode = tempNode->pNext;
		}
		tempNode->pNext = newNode;
	}
}

//移除节点
void removeNode(ListNode** pHead, int val)
{
	if (pHead == NULL || *pHead == NULL)
		return;
	ListNode* pToBeDeleted = NULL;
	if ((*pHead)->val == val)
	{
		pToBeDeleted = *pHead;
		*pHead = ((*pHead)->pNext);
	}
	else
	{
		ListNode* pNode = *pHead;
		while (pNode->pNext != NULL && pNode->pNext->val != val)
		{
			pNode = pNode->pNext;
		}
		if (pNode->pNext != NULL && pNode->pNext->val == val)
		{
			pToBeDeleted = pNode->pNext;
			pNode->pNext = pNode->pNext->pNext;
		}
		if (!pToBeDeleted)
		{
			delete pToBeDeleted;
			pToBeDeleted = NULL;
		}
	}
}


//反向打印链表
#include <stack>

void printLinkedlistReversely(ListNode* head)
{
    if(head == NULL)
        return;
    stack<ListNode*> st;
    ListNode* tempNode = head;
    while(tempNode != NULL)
    {
        st.push(tempNode);
        tempNode = tempNode->pNext;
    }
    
    while(!st.empty())
    {
        ListNode* node;
        node = st.top();
        cout << node->val << endl;
        st.pop();
    }
    
}

//斐波那契数列
long long printFibN(int n)
{
    if(n < 0 )
        return -1;
    long long result[2] = {1,1};
    if(n < 2)
    {
        return result[n];
    }
    long long fibMinusOne = 1;
    long long fibMinusTwo = 1;
    long long fibN = 0;
    for(int i = 2; i <= n; i++)
    {
        fibN =fibMinusOne+fibMinusTwo;
        fibMinusTwo = fibMinusOne;
        fibMinusOne = fibN;
    }
    return fibN;
}

//找出旋转数组最小值
int MinInOrder(int* arr, int l, int r)
{
    int min = arr[l];
    for(int i=l+1; i<=r; ++i)
    {
        if(min > arr[i])
            min = arr[i];
    }
    return min;
}

int Min(int arr[], int n)
{
    assert(arr == NULL || n <=0);
    
    int l = 0,r = n-1;
    int mid = 0;
    while(arr[l] >= arr[r])
    {
        if(r-l == 1)
        {
            mid = r;
            break;
        }
        mid = (r+l)/2;
        if(arr[l] == arr[mid] && arr[mid] == arr[r])
            return MinInOrder(arr, l, r);
        if(arr[l] >= arr[mid])
            r = mid;
        else if(arr[r] <= arr[mid])
            l = mid;
    }
    return arr[mid];
}

//判断二进制整数中为1的个数
int NumOf1(int n)
{
    int res = 0;
    unsigned int temp = 1;
    if(n & temp)
    {
        ++res;
        temp = temp << 1;
    }
    return res;
}



