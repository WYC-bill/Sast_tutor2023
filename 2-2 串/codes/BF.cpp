#include "mystring.h"

int BruteForceMatch(String& T, String& P)
{
	int n = T.StrLength();
	int m = P.StrLength();
	if (n < m || m == 0 || n == 0) return -1;   //��ģʽ�����ȴ���Ŀ�괮������һΪ�մ���ƥ���Ȼʧ��
	int i = 0, j = 0;
	while (j < m && i < n) {          //����������αȶ�
		if (T[i] == P[j]) { i++; j++; }       //��ƥ�䣬ת����һ�ַ���
		else { i -= j - 1; j = 0; }           //ʧ�䣬��T���ˡ�P��λ
		if (j == m) return i - j;             //ƥ��ɹ������ض���λ��
	}
	return -1;                                //ƥ��ʧ��
}