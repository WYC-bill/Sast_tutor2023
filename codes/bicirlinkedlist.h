#pragma once
#include <cstdio>
#include "node.h"

class bicirlinkedlist
{
public:
	bicirlinkedlist() { head = NULL; }
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

void bicirlinkedlist::destroy()
{
	if (head != NULL) {
		node* start = head, *del; //start��¼����ı�ͷ
		while (head->next != start) { //headָ��
			del = head;
			head = head->next; //��ɾ��del���ǰ�����ȱ�����һ�ڵ��ַ
			delete del;
		}
		delete head;
	}
}

void bicirlinkedlist::insert(int val)
{
	if (head == NULL) {
		head = new node();
		head->data = val;
		head->next = head->prev = head;
	}
	else{
		node* newhead = new node();
		newhead->data = val;
		newhead->next = head;
		newhead->prev = head->prev;
		head->prev = newhead;
		newhead->prev->next = newhead;
		head = newhead; //�ڳ�ʼ����newhead->next��newhead->prev��ſɸ��±�ͷ
	}
}

void bicirlinkedlist::del(int val) {
	if (head == NULL) return;
	else if (head->data == val) {
		node* del = head; //���±�ͷǰ�ȼ�¼��ɾ��ͷ
		if (head->next == head) {
			delete del;
			head = NULL;
		}
		else {
			head = head->next;
			head->prev = del->prev;
			del->prev->next = head;
			delete del;
		}
	}
	else {
		node* prev = head, * del; //prev����Ϊval��Ӧ����ǰ������ɾԪ�ز��Ǳ�ͷ����һ������ǰ����
		while (prev->next != head && prev->next->data != val) {
			prev = prev->next;
		}
		if (prev->next == head) return; //prev���ڱ�β����δ�ҵ�val��������û��val������ɾ��
		del = prev->next; //����prev->nextǰ�ȼ�¼��ɾ���
		prev->next = del->next;
		del->next->prev = prev;
		delete del;
	}
}

int bicirlinkedlist::getval(node* addr)
{
	return addr->data;
}

node* bicirlinkedlist::getprev(node* addr) {
	if (addr != NULL) return addr->prev;
	else return NULL;
}

node* bicirlinkedlist::getnext(node* addr)
{
	if (addr != NULL) return addr->next;
	else return NULL;
}

void bicirlinkedlist::traverse()
{
	if (head == NULL) return;
	printf("%d ", head->data);
	node* cur = head->next;
	while (cur != head) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}