/* ��1.cpp����ͬһ��Ŀ�����У�����
0. �����κθĶ������У�
1. 1.cpp���ǰ����static���η���ȥ��2.cpp�еġ�extern�������У�
2. ������showǰ��staticȥ�������У�������ֱ�ӽ�����һ����
3. �ٽ�2.cpp�к�������Ϊshow1�����У�������ֱ�ӽ�����һ����
4. �ٽ�2.cpp�е�ע��ȡ�������С� */
#include<iostream>
using namespace std;
extern int counter;
// void show();
void show() {
    cout << "hello World!" << endl;
    cout << counter << endl;
}
int main() {
    show();
    return 0;
}