#include <iostream>
void print() {                         // ȫ�������ռ�
	using std::cout;                   // using declaration
	cout << "1\n";
}
namespace exap
{
	void print() {                      // exap�����ռ�
		std::cout << "2\n";
	}
	void printnum() {
		print();                        // �Զ������������ռ����������ռ��е�print()����
		::print();                      // ȫ�������ռ��е�print()����
	}
	namespace exbp {
		void print() {                  // exbp�����ռ�
			std::cout << "0\n";
		}
	}
}
int cout() {
	return 108;
}
namespace num {
	int a = 85;
}
int main() {
	exap::printnum();
	using namespace num;              // using directive�������ֲ�������namespace�е�ԭ�г�Ա��ͬʱ�µ��������ڱ�namespace�еĳ�Ա
	//using num::a;                   // using declaration�������ֲ�������namespace�е�ԭ�г�Ա��ͬʱ�ᱨ����Ϊ�����˳�ͻ
	int a = 12;
	//std::cout << num::a;            // �����������(::)�����������Ϻ;ֲ������϶�������������
	using std::cout;                  // using declaration�����������ϲ�����������
	cout << a << std::endl;
	cout << num::a << std::endl;
	/*using namespace std;            // using directive�����������ϻ��������壬����
	cout << a; */
	return 0;
}