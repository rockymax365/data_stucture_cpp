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

//数值的整数次方
bool g_invalidIput = false;

bool isEqual(double num1, double num2)
{
	return (abs(num1 - num2) < 0.000001) ? true : false;
}

double PowerWithUnsigned(double base, unsigned int exponent)
{
	double res = 1.0;
	for (int i = 0; i < exponent; i++)
	{
		res = res * base;
	}
	return res;
}

double Power(double base, int exponent)
{
	double res = 0.0;
	if ((exponent < 0) && isEqual(base, 0.0))
	{
		g_invalidIput = true;
		return res;
	}
	bool isNegtive = false;
	if (exponent < 0)
	{
		isNegtive = true;
		exponent = -1 * exponent;
	}
	res = PowerWithUnsigned(base, exponent);
	if (isNegtive)
		res = 1.0 / res;

	return res;
}



//打印从1到n最大n位数
void PrintNum(char* ch)
{
	int n = strlen(ch);
	bool startPrint = false;
	for (int i = 0; i < n; i++)
	{
		if (ch[i] != '0')
		{
			startPrint = true;
		}
		if (startPrint)
		{
			cout << ch[i];
		}
	}
	cout << endl;
	return;
}
void PrintNumRecursively(char* ch, int n, int index)
{
	if (index = n - 1)
		PrintNum(ch);
	for (int i = 0; i < 10; i++)
	{
		ch[index + 1] = '0' + i;
		PrintNumRecursively(ch, n, index + 1);
	}

}
void Print1toNOfMaxDigit(int n)
{
	if (n <= 0)
		return;
	char* ch = new char[n + 1];
	ch[n] = '\0';
	for (int i = 0; i < 10; i++)
	{
		ch[0] = i + '0';
		PrintNumRecursively(ch, n, 0);
	}
	delete ch;
	return;
}

//O(1)删除节点
void deleteNode(ListNode** pListHead, ListNode* toBeDeleted)
{
    if(pListHead == NULL || *pListHead == NULL || toBeDeleted == NULL)
        return;
    //待删除节点不是尾部
    if(toBeDeleted->pNext != NULL)
    {
        ListNode* pNext = toBeDeleted->pNext;
        toBeDeleted->val = pNext->val;
        toBeDeleted->pNext = pNext->pNext;
        delete pNext;
        pNext = NULL;
    }
    //只有一个头节点
    else if(*pListHead == toBeDeleted)
    {
        delete toBeDeleted;
        toBeDeleted = NULL;
        *pListHead = NULL;
    }
    else  //尾部节点
    {
        ListNode* pNode = *pListHead;
        while(pNode->pNext != toBeDeleted)
        {
            pNode = pNode->pNext;
        }
        pNode->pNext = NULL;
        delete toBeDeleted;
    }
}

//按奇偶分为两部分
void reOrder(int arr[], int n)
{
    if(arr == NULL || n <=0)
        return;
    int l = 0;
    int r = n-1;
    while(l < r)
    {
        while((l<r) && ((arr[l]&0x01) != 0))
            l++;
        while((l<r) && ((arr[r]&0x01) == 0))
            r--;
        if(l <r)
            swap(arr[l],arr[r]);
    }
}

//二叉树镜像
void binaryTreeMirror(BinaryTreeNode* treeNode)
{
	if (treeNode == NULL)
		return;
	if (treeNode->m_pLeft == NULL && treeNode->m_pRight == NULL)
		return;
	BinaryTreeNode* tempNode = treeNode->m_pLeft;
	treeNode->m_pLeft = treeNode->m_pRight;
	treeNode->m_pRight = tempNode;
	if (treeNode->m_pLeft)
		binaryTreeMirror(treeNode->m_pLeft);
	if (treeNode->m_pRight)
		binaryTreeMirror(treeNode->m_pRight);

}

//寻找链表倒数第k个节点
ListNode* findKthFromTail(ListNode* head, int k)
{
	if (head == NULL || k <= 0)
		return NULL;
	ListNode* pAhead = head;
	ListNode* pBehind = head;
	for (int i = 0; i < (k - 1); i++)
	{
		if (pAhead != NULL)
		{
			pAhead = pAhead->pNext;
		}
		else
		{
			return NULL;
		}
	}
	while (pAhead->pNext != NULL)
	{
		pAhead = pAhead->pNext;
		pBehind = pBehind->pNext;
	}

	return pBehind;
}

//合并排序链表
ListNode* mergeOrderedLinkedList(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;
	ListNode* res = NULL;
	if (pHead1->val < pHead2->val)
	{
		res = pHead1;
		res->pNext = mergeOrderedLinkedList(pHead1->pNext, pHead2);
	}
	else
	{
		res = pHead2;
		res->pNext = mergeOrderedLinkedList(pHead1, pHead2->pNext);
	}
	return res;
}

//从上到下打印二叉树
void printBinaryTreeFromTopToDown(BinaryTreeNode* pTreeRoot)
{
	if (pTreeRoot == NULL)
		return;

	queue<BinaryTreeNode*> q;
	q.push(pTreeRoot);
	while (!q.empty())
	{
		BinaryTreeNode* pNode = q.front();
		cout << pNode->val << endl;
		q.pop();
		if (pNode->m_pLeft != NULL)
			q.push(pNode->m_pLeft);
		if (pNode->m_pRight != NULL)
			q.push(pNode->m_pLeft);
	}
	return;
}

//找出占数组一半的值

int partition(int arr[], int l, int r)
{
	if (l > r)
		return -1;
	swap(arr[l],arr[l+(rand()%(r-l+1))]);
	int v = arr[l];
	int j = l;
	for (int i = l+1; i <= r; i++)
	{
		if (arr[i] < v)
		{
			swap(arr[i], arr[j + 1]);
			j++;
		}
	}
	swap(arr[l], arr[j]);

	return j;
}



int findMidVal(int arr[], int n)
{
	assert(arr != NULL && n >= 0);
	int res = 0;
	int l = 0, r = n - 1;
	int p = partition(arr, l, r);
	int mid = n / 2;
	while (p != mid)
	{
		if (p > mid)
			r = p;
		else
			l = p;
		p = partition(arr, l, r);
	}

	return arr[p];

}


//数组前n个数
void findKSmallVal(int arr[], int n, int k)
{
	if (arr == NULL || n <= 0 || k <= 0 || n < k)
		return;
	priority_queue<int> q; //大顶堆
	for (int i = 0; i < k; i++)
	{
		q.push(arr[i]);
	}
	for (int i = k; i < n; i++)
	{
		if (q.top() > arr[i])
		{
			q.pop();
			q.push(arr[i]);
		}
	}
}

//寻找连续子数组最大和
int findTheGreatestOfSubArray(int arr[], int n)
{
	assert(arr != NULL && n > 0);
	int* arrMaxOfNth = new int[n];
	arrMaxOfNth[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arrMaxOfNth[i - 1] < 0)
		{
			arrMaxOfNth[i] = arr[i];
		}
		else
		{
			arrMaxOfNth[i] = arrMaxOfNth[i - 1] + arr[i];
		}
	}

	int max = arrMaxOfNth[0];
	for (int i = 1; i < n; i++)
	{
		if (arrMaxOfNth[i] > max)
			max = arrMaxOfNth[i];
	}
	return max;
}

//1到n中整数1出现的次数
int numOf1(unsigned int n)
{
	int res = 0;
	while (n != 0)
	{
		if (n % 10 == 1)
			res++;
		n = n / 10;
	}
	return n;
}
int numOf1From1ToN(unsigned int n)
{
	int res = 0;
	for (int i = 0; i <= n; i++)
	{
		res += numOf1(n);
	}
	return res;
}

//寻找两个链表的公共节点
int lengthOfLinkedList(ListNode* pHead)
{
    int res = 0;
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        res++;
        pNode = pNode->pNext;
    }
    return res;
}

ListNode* findCommonNode(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == NULL || pHead2 == NULL)
        return NULL;
    int length1 = lengthOfLinkedList(pHead1);
    int length2 = lengthOfLinkedList(pHead2);
    ListNode* pHeadLong = pHead1;
    ListNode* pHeadShort = pHead2;
    if(length1 < length2)
    {
        pHeadLong = pHead2;
        pHeadShort = pHead1;
    }
    int longthDiff = int(abs(pHead1 - pHead2));
    for(int i=0; i<longthDiff; i++)
    {
        pHeadLong = pHeadLong->pNext;
    }
    while(pHeadLong != NULL && pHeadShort != NULL && pHeadLong != pHeadShort)
    {
        pHeadLong = pHeadLong->pNext;
        pHeadShort = pHeadShort->pNext;
    }
    
    return pHeadLong;
    
}

//寻找第一个只出现一次的字符
char findTheFirstSingleChar(char* pString)
{
    if(pString == NULL)
        return '\0';
    int hashTable[256] = {0};
    char* pHashKey = pString;
    while(*pHashKey != '\0')
    {
        hashTable[*pHashKey]++;
        pHashKey++;
    }
    pHashKey = pString;
    while(*pHashKey != '\0')
    {
        if(hashTable[*pHashKey] == 1)
            return *pHashKey;
        pHashKey++;
    }
    return '\0';
}

//统计数组逆序对

int res = 0;

void merge(int arr[], int l, int mid, int r)
{
    int* aux = new int[r-l+1];
    for(int i=l; i<=r; i++)
    {
        aux[i-l] = arr[i];
    }
    int i = mid, j = r;
    for(int k=r; k>=l; k--)
    {
        if(i<l)
        {
            arr[k] = aux[j-l];
            j--;
        }
        else if(j < (mid+1))
        {
            arr[k] = aux[i-l];
            i--;
        }
        else if(aux[i-l] > aux[j-l])
        {
            arr[k] = aux[i-l];
            res += (j-mid);
            i--;
        }
        else if(aux[i-l] <= aux[j-l])
        {
            arr[k] = aux[j-l];
            j--;
        }
    }
    
    delete [] aux;
}
void mergeSort(int arr[], int l, int r)
{
    if(l >= r)
        return;
    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    if(arr[mid] > arr[mid+1])
        merge(arr, l, mid, r);
}

void reversePair(int arr[], int n)
{
    assert(arr != NULL && n > 0);
    
    mergeSort(arr, 0, n-1);
    
}

//字符串全排列
void permutation(char* ch, char* pBegin)
{
    if(*pBegin == '\0')
    {
        return;
    }
    for(char* pCh = pBegin; *pCh != '\0'; pCh++)
    {
        char temp = *pCh;
        *pCh = *pBegin;
        *pBegin = temp;
        permutation(ch,pBegin+1);
        temp = *pCh;
        *pCh = *pBegin;
        *pBegin = temp;
    }
    
}
void permutation(char* ch)
{
    if(ch == NULL)
        return;
    permutation(ch,ch);
    
}

//判断数组是否为二叉搜索树后序遍历
bool VerifySequeceOfBST(int arr[], int n)
{
	if (arr == NULL || n <= 0)
		return false;
	int root = arr[n - 1];
	int i = 0;
	for (; i < n - 1; i++)
	{
		if (arr[i] > root)
			break;
	}
	int j = i;
	for(; j<n-1;j++)
	{
		if (arr[j] < root)
			return false;
	}
	bool left = true;
	if (i > 0)
	{
		left = VerifySequeceOfBST(arr, i);
	}
	bool right = true;
	if (j < n - 1)
	{
		right = VerifySequeceOfBST(arr + i, n - 1 - i);
	}
	return left && right;
}


//寻找数组中重复超过一半的数
int FindMoreThanHalf(int arr[], int n)
{
	assert(arr == NULL || n <= 0);
	int num = arr[0];
	int times = 1;
	for (int i = 1; i < n; i++)
	{
		if (times == 0)
		{
			num = arr[i];
			times++;
		}
		else if (arr[i] == num)
		{
			times++;
		}
		else
		{
			times--;
		}
	}
	return num;

}


//数字在排序数组中出现的次数
int FindStartIndex(int arr[], int k, int l, int r)
{
    if(l > r)
        return -1;
    
    int mid = l + (r-1)/2;
    if(arr[mid] == k)
    {
        if((mid >0 && arr[mid-1] != k) || mid == 0 )
        {
            return mid;
        }
        else
        {
            r = mid-1;
        }
    }
    else if(arr[mid] > k)
    {
        r = mid -1;
    }
    else
    {
        l = mid +1;
    }
    
    return FindStartIndex(arr, k, l, r);
}

int FindEndIndex(int arr[], int k, int l, int r)
{
    if(l > r)
        return -1;
    int mid = l + (r-l)/2;
    if(arr[mid] == k)
    {
        if((mid < r && arr[mid +1] != k) || mid == r)
        {
            return mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    else if(arr[mid] < k)
    {
        l = mid + 1;
    }
    else
    {
        r = mid - 1;
    }
    
    return FindEndIndex(arr, k, l, r);
}


int CalcNumberOfK(int arr[], int n, int k)
{
    int res = -1;
    if(arr != NULL && n > 0)
    {
        int start = FindEndIndex(arr, k, 0, n-1);
        int end = FindEndIndex(arr, k, 0, n-1);
        if(start != -1 && end != -1)
            res = end -start +1;
    }
    return res;
}

//计算树的深度

struct BinaryTreeNode{
    int val;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

int TreeDepth(BinaryTreeNode* pRoot)
{
    if(pRoot == NULL)
        return 0;
    int left = TreeDepth(pRoot->m_pLeft);
    int right = TreeDepth(pRoot->m_pRight);
    
    return (left > right) ? (left+1) : (right +1);
}

//是否是平衡二叉树
bool IsBalance(BinaryTreeNode* pRoot)
{
    if(pRoot == NULL)
        return true;
    int left = TreeDepth(pRoot);
    int right = TreeDepth(pRoot);
    if(abs(left-right) >1)
        return false;
    return IsBalance(pRoot->m_pLeft) && IsBalance(pRoot->m_pRight);
}

bool IsBalanced(BinaryTreeNode* pRoot, int* pDepth)
{
    if(pRoot == NULL)
    {
        *pDepth = 0;
        return true;
    }
    int left, right;
    if(IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right))
    {
        if(abs(left-right) >1)
        {
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
}



