#include "mystring.h"

void Next(String& P, int n[])
{
	int m = P.StrLength();
	n[0] = 0;                             //λ��0������ƥ�䴮����Ϊ0
	int i = 1, j = 0;
	while (i < m) {                       //��ʱ��ƥ��j+1���ַ���
		if (P[i] == P[j]) {
			n[i] = j + 1;
			i++; j++;
		}
		else if (j > 0) j = n[j - 1];     //�ƶ����ò���ƥ�䴮����
		else { n[i++] = 0; }              //j�ڴ�ͷʱ����ƥ�䴮����Ϊ0
	}
}

void Next_Pro(String& P, int n[])
{
	int m = P.StrLength();
	n[0] = 0;                             //λ��0������ƥ�䴮����Ϊ0
	int i = 1, j = 0;
	while (i < m) {                       //��ʱ��ƥ��j+1���ַ���
		if (P[i] == P[j]) {
			if (P[i] == P[n[i - 1]]) n[i] = n[i - 1];
			else n[i] = j + 1;
			i++; j++;
		}
		else if (j > 0) j = n[j - 1];     //�ƶ����ò���ƥ�䴮����
		else { n[i++] = 0; }              //j�ڴ�ͷʱ����ƥ�䴮����Ϊ0
	}
}

int KMP_Match(String& T, String& P)
{
	int n = T.StrLength(), m = P.StrLength();
	int* next = new int[m];
	Next_Pro(P, next);
	int i = 0, j = 0;
	int cnt = 0;
	while (i < n) {
		cnt++;
		if (T[i] == P[j]) {
			if (j == m - 1) {
				return i - j;
			}
			else { i++; j++; }
		}
		else {
			if (j > 0) j = next[j - 1];
			else i++;
		}
	}
	return -1;
}