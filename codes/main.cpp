#include <cstdio>
#include "node.h"
#include "linkedlist.h"
#include "bicirlinkedlist.h"

int main()
{
	printf("���������֣�\n");
	linkedlist ll;
	printf("�����ձ�\n");
	ll.traverse();
	printf("�ӿձ�ɾ��1\n");
	ll.traverse();
	printf("���ٿձ�\n");
	ll.destroy();
	printf("����1\n");
	ll.insert(1);
	ll.traverse();
	printf("ɾ��1\n");
	ll.del(1);
	ll.traverse();
	printf("�ӿձ�ɾ��2\n");
	ll.del(2);
	ll.traverse();
	printf("����1\n");
	ll.insert(1);
	ll.traverse();
	printf("����2\n");
	ll.insert(2);
	ll.traverse();
	printf("ɾ��2\n");
	ll.del(2);
	ll.traverse();
	printf("����2\n");
	ll.insert(2);
	ll.traverse();
	printf("����3\n");
	ll.insert(3);
	ll.traverse();
	printf("ɾ��4\n");
	ll.del(4);
	ll.traverse();
	printf("ɾ��1\n");
	ll.del(1);
	ll.traverse();
	printf("���ٱ�\n");
	ll.destroy();
	printf("\n˫�������֣�\n");

	bicirlinkedlist bcll;
	printf("�����ձ�\n");
	bcll.traverse();
	printf("�ӿձ�ɾ��1\n");
	bcll.traverse();
	printf("���ٿձ�\n");
	bcll.destroy();
	printf("����1\n");
	bcll.insert(1);
	bcll.traverse();
	printf("ɾ��1\n");
	bcll.del(1);
	bcll.traverse();
	printf("�ӿձ�ɾ��2\n");
	bcll.del(2);
	bcll.traverse();
	printf("����1\n");
	bcll.insert(1);
	bcll.traverse();
	printf("����2\n");
	bcll.insert(2);
	bcll.traverse();
	printf("ɾ��2\n");
	bcll.del(2);
	bcll.traverse();
	printf("����2\n");
	bcll.insert(2);
	bcll.traverse();
	printf("����3\n");
	bcll.insert(3);
	bcll.traverse();
	printf("ɾ��4\n");
	bcll.del(4);
	bcll.traverse();
	printf("ɾ��1\n");
	bcll.del(1);
	bcll.traverse();
	printf("���ٱ�\n");
	bcll.destroy();
	return 0;
}