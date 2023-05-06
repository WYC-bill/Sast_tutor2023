#include<iostream>
using namespace std;
const int DEFAULT_SIZE = 100;
class String
{
private:
	char a[DEFAULT_SIZE];
public:
	//����һ���մ�
	String() { a[0] = '\0'; }

	//���ƹ���
	String(const char* S);
	String(String& S);

	//����
	~String() {};

	//��ʾ
	void ShowString()const;

	//����
	void StrCopy(String& S);
	//void friend StrCopy(String& T, String& S);

	//���
	void ClearString();
	//void friend ClearString(String& S);

	//�п�
	bool StrEmpty()const;
	//bool friend StrEmpty(String& S);

	//�Ƚ�
	int StrCompare(String& S)const;
	//int friend StrCompare(String& T, String& S);

	//��
	int StrLength()const;
	//int friend StrLength(String& S);

	//����
	void Concat(String& S);                       //����S���ӱ�����
	void Concat(String& S1, String& S2);          //��S1��S2���Ӻ���´���������
	//void friend Concat(String& T, String& S1, String& S2);         

	//��ת
	void Reverse();
	//void friend Reverse(String& S);

	//��ȡ�ִ�
	void SubString(String& Sub, int pos, int len);
	//void friend SubString(String& Sub, String& S, int pos, int len);

	//�ִ�����
	int Index(String& P, int pos)const;
	//int friend Index(String& T, String& P, int pos);

	//����
	void StrInsert(int pos, String& T);
	//void StrInsert(String& S, int pos, String& T);

	//ɾ���ִ�
	void StrDelete(int pos, int len);
	//void StrDelete(String& S, int pos, int len);

	//�ؼ����滻
	void Replace(String& T, String& V);
	void friend Replace(String& S, String& T, String& V);

	//ģʽ��ƥ��
	//BF
	int friend BruteForceMatch(String& T, String& P);
	//KMP
	int friend KMP_Match(String& T, String& P);
	void friend Next(String& T, int n[]);
	void friend Next_Pro(String& T, int n[]);
	//BM
	int friend BM_Match(String& T, String& P);
	void friend Build_BC(String& P, int bc[]);
	void friend Build_GS(String& P, int bc[]);
	int friend Horspool(String& T, String& P);

	//�����±������
	char& operator[](int n);
};
