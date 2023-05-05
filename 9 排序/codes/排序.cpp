#include<iostream>
using namespace std;

//��������
template<class T>
inline void exch(T* e1, T* e2)
{
	T tmp;
	tmp = *e1;
	*e1 = *e2;
	*e2 = tmp;
}

//�Ƚ�-������������֤��Ԫ���С��������
template<class T>
bool compExch(T* e1, T* e2)
{
	if (*e1 > *e2) {
		exch(e1, e2); return true;
	}
	else return false;
}

//ð������
template<class T>
void bubble_sort(T* a, int left, int right)//�Ե�left+1����right+1��Ԫ�ؽ�������
{
	int i, j;
	for (i = left; i < right; i++)//n-1��ð�ݣ���i��ð��
	{
		for (j = right; j > i; j--)//��i��ð��Ҫ����n-i�αȽϺͽ�������
		{
			compExch(a + j - 1, a + j);
		}
	}
}

//�����Ľ���ð������
template<class T>
void bubble_sort_improved(T* a, int left, int right)//�Ե�left+1����right+1��Ԫ�ؽ�������
{
	int i, j;
	for (i = left; i < right; i++)//n-1��ð�ݣ���i��ð��
	{
		int flag = false;
		for (j = right; j > i; j--)//��i��ð��Ҫ����n-i�αȽϺͽ�������
		{
			if (compExch(a + j - 1, a + j))//������������򣬽���־��Ϊtrue
			{
				flag = true;
			}
		}
		if (flag == false)return;//�����һ��ð��û�����򣬷���
	}
}

template<class T>
void insert_sort(T* a, int left, int right)
{
	int i, j;
	T tTag;
	for (i = right; i > left; i--)//һ��ð�ݣ�����С��Ԫ�ط�����ǰ�棬���⸺��
	{
		if (a[i - 1] > a[i])exch(a + i - 1, a + i);
	}
	for (i = left + 2; i <= right; i++)//��ʾ���ν��в��������Ԫ���±�
	{
		j = i;//��¼λ��
		tTag = a[i];//��¼Ԫ�ش�С
		while (tTag < a[j - 1])//������㣬�˴����ǲ���λ�ã�����ǰѰ��С�ڻ����tTag��λ��
		{
			a[j] = a[j - 1];//Ųλ��
			j--;
		}
		a[j] = tTag;//����
	}
}

template<class T>
void insert_bisort(T* a, int l, int r)
{
	int i, j, right, left, middle;
	T e;
	for (i = l + 1; i <= r; i++)
	{
		e = a[i];//��ǰ�����Ԫ��
		left = l; right = i - 1;//�۰���ҷ�Χ
		while (left <= right)//�۰����
		{
			middle = (left + right) / 2;//�м�λ��
			if (e < a[middle])right = middle - 1;
			else left = middle + 1;
		}//ȷ������λ��
		for (j = i - 1; j >= left; j--)a[j + 1] = a[j];//�ɿ�����ƶ����ճ�����λ��
		a[left] = e;//����
	}
}

//template<class T>
//void shell_insert_sort(T* a, int left, int right,int gap)
//{
//	int i, j;
//	T tTag;
//	for (i = right; i > left; i--)//һ��ð�ݣ�����С��Ԫ�ط�����ǰ�棬���⸺��
//	{
//		if (a[i - 1] > a[i])exch(a + i - 1, a + i);
//	}
//	for (i = left + 2; i <= right; i++)//��ʾ���ν��в��������Ԫ���±�
//	{
//		j = i;//��¼λ��
//		tTag = a[i];//��¼Ԫ�ش�С
//		while (tTag < a[j - 1])//������㣬�˴����ǲ���λ�ã�����ǰѰ��С�ڻ����tTag��λ��
//		{
//			a[j] = a[j - 1];//Ųλ��
//			j--;
//		}
//		a[j] = tTag;//����
//	}
//}

template<class T>
void shell_sort(T* a, int left, int right)
{
	int shellh[3] = { 1, 2, 5 };
	for (int i = 2; i >= 0; i--)//ѡ�񱾴������gap
	{
		int gap = shellh[i];
			for (int j = left; j < left+gap; j++)//��Ϊgap���飬���ڽ���ֱ�Ӳ�������
			{
				for (int k = j + gap; k <= right; k += gap)//ֱ�Ӳ�������
				{
					T temp = a[k];
					int s = k - gap;
					while (s >= left && temp < a[s])//s>=left���⸺��
					{
						a[s + gap] = a[s];
						s -= gap;
					}
					a[s + gap] = temp;
				}
			}
	}
}

template<class T>
void select_sort(T* a, int left, int right)
{
	int i, j, min;
	for (i = left; i < right; i++)//�ӵ�һ������n-1��λ��
	{
		min = i;
		for (j = i + 1; j <= right; j++)
			//ѡ���λ�ü�֮������λ������Сֵ���±�
			if (a[j] < a[min])min = j;
		exch(a + i, a + min);//��iλ�ý���
	}
}

//��������
// ����ȡ��
template<class T>
void MiddleOfThree(T* a, int left, int right)
{
	int middle = (left + right) / 2;
	if (a[middle] > a[right])exch(a + middle, a + right);
	if (a[left] > a[right])exch(a + left, a + right);
	if (a[left] > a[middle])exch(a + left, a + middle);
	exch(a + middle, a + right);
}

//���ֲ���
template<class T>
int partition(T* a, int left, int right)//���� ���ػ���λ��
{
	int i = left - 1, j = right;
	MiddleOfThree(a, left, right);
	T e = a[right];
	while (1)
	{
		while (a[++i] <= e)if (i == right)break;
		while (e <= a[--j])if (j == left)break;
		if (i >= j)break;
		exch(a + i, a + j);
	}
	exch(a + i, a + right);
	return i;
}
//�ݹ�ʵ��
template<class T>
void quick_sort(T* a, int left, int right)
{
	if (right <= left)return;
	int i = partition(a, left, right);
	quick_sort(a, left, i - 1);
	quick_sort(a, i + 1, right);
}

template<class T>
void merge(T* a, int p1, int p2, int p3)//����������
{
	long i, j, k;
	T* c = new T[p3 - p1 + 1];
	for (i = 0, j = 0, k = 0; k < p3 - p1+1; k++)
	{
		if (i == p2 - p1) { c[k] = a[p2+j]; j++; continue; }
		if (j == p3-p2+1) { c[k] = a[p1+i]; i++; continue; }
		if (a[p1 + i] <= a[p2 + j]) { c[k] = a[p1 + i]; i++; }
		else { c[k] = a[p2 + j]; j++; }
	}
	for (i = 0; i < p3-p1+1; i++)
	{
		a[p1+i] = c[i];
	}
	delete[] c;
}

template<class T>
void merge_sort(T* a, int left, int right)
{
	int i, m;
	for (m = 1; m < right - left; m = m + m)//ÿ��ѭ��m����
	{
		for (i = left; i <= right - m; i += m + m)
		{
			merge(a, i, i + m, min(i + m + m - 1, right));
		}
	}
}

//����ṹ��λ
struct Node {
	int val;
	Node* next;
};

//node -- �����ͷ
Node* MergeSort(Node* node) {
	//���ж��������Ƿ����1��С��1ʱ��������
	if (node != NULL && node->next != NULL) {
		//���ÿ���ָ�룬�ҵ�������м�ڵ�
		Node* fast = node->next;
		Node* slow = node;
		while (fast != NULL && fast->next != NULL) {
			fast = fast->next->next;
			slow = slow->next;
		}

		//������ֳ������ֽ��зָ�
		Node* p1 = MergeSort(slow->next);
		slow->next = NULL;                 
		Node* p2 = MergeSort(node);
		//�������������й鲢
		Node* p0 = (Node*)malloc(sizeof(Node));
		Node* p = p0;
		while (p1 != NULL && p2 != NULL) {
			if (p1->val < p2->val) { p->next = p1; p1 = p1->next; }
			else { p->next = p2; p2 = p2->next; }
			p = p->next;
		}
		if (p1 != NULL) p->next = p1;
		if (p2 != NULL) p->next = p2;
		p = p0->next;free(p0);
		return p;
	}
	return node;
}

template<class T>
void merge_sort2(T* a, int left, int right)
{
	if (right <= left)return;//�����еĳ���С�ڵ���1
	int m = (left + right) / 2;//ȡ�м�λ��
	merge_sort2(a, left, m);//���ҷֱ�ݹ�����
	merge_sort2(a, m + 1, right);
	merge(a, left, m+1, right);
}

int main()
{
	int a[13] = { 1,4,63,5,73,3,74,24,54,11,35,8,12 };
	//bubble_sort_improved<int>(a, 0, 12);
	//insert_sort<int>(a, 0, 12);
	//insert_bisort<int>(a, 0, 12);
	//shell_sort<int>(a, 0, 12);
	//select_sort(a, 0, 12);
	//quick_sort(a, 0, 12);
	//merge_sort(a, 0, 12);
	merge_sort2(a, 0, 12);
	for (int i = 0; i < 13; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}