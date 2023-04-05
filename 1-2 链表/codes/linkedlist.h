#pragma once
#include <cstdio>
#include "node.h"

class linkedlist
{
public:
	linkedlist() { head = NULL; }
	void destroy();
	void insert(int val);
	void del(int val);
	int getval(node* addr);
	node* getprev(node* addr);
	node* getnext(node* addr);
	void traverse();
private:
	node* head;
};

void linkedlist::destroy()
{
	while (head != NULL) {
		node* del = head;
		head = head->next; //��ɾ��del���ǰ�����ȱ�����һ�ڵ��ַ
		delete del;
	}
}

void linkedlist::insert(int val)
{
	node* newhead = new node();
	newhead->data = val;
	newhead->next = head;
	head = newhead; //�ڳ�ʼ����newhead->next��ſɸ��±�ͷ
}

void linkedlist::del(int val) {
	if (head == NULL) return;
	else if(head->data == val) {
		node* del = head; //���±�ͷǰ�ȼ�¼��ɾ��ͷ
		head = head->next;
		delete del;
	}
	else {
		node* prev = head, *del; //prev����Ϊval��Ӧ����ǰ������ɾԪ�ز��Ǳ�ͷ����һ������ǰ����
		while (prev->next != NULL && prev->next->data != val) {
			prev = prev->next;
		}
		if (prev->next == NULL) return; //prev���ڱ�β����δ�ҵ�val��������û��val������ɾ��
		del = prev->next; //����prev->nextǰ�ȼ�¼��ɾ���
		prev->next = prev->next->next;
		delete del;
	}
}

int linkedlist::getval(node* addr)
{
	return addr->data;
}

node* linkedlist::getprev(node* addr) {
	if (head == NULL || addr == NULL) return NULL;
	node* prev = head; //prev���ռ�¼addr��ǰ����ַ
	while (prev->next != addr && prev->next != NULL) prev = prev->next;
	if (prev->next == NULL) return NULL; //prev��Ϊ��ף�������Ϊǰ����˵��addr���ڱ���
	return prev;
}

node* linkedlist::getnext(node* addr)
{
	if (addr != NULL) return addr->next;
	else return NULL;
}

void linkedlist::traverse()
{
	if (head == NULL) return;
	node* cur = head;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}