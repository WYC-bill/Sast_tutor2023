#include <iostream>
using namespace std;
class Student {
 public:
  Student(): stuID(ID++){}
  int getID1() const  { return stuID; } // �Ǿ�̬��Ա�����ɵ��þ�̬���Ǿ�̬��Ա����
  //int getID1() const  { return ID; }
  static int getID2();
private:
  static int ID;       // �˴����������Ƕ���
  int stuID;
};
int Student::ID{ 0 };  // ��̬��Ա��������������ͺ����ⶨ�壨��ʱ���������ֵ���Զ�����ֵ����C++17�����˵���������Ȥ�����в����й����ϣ�
int Student::getID2(){ // ��̬��Ա����ֻ�ܵ��þ�̬��Ա����
    return ID++; 
}
/*int Student::getID2(){ 
    return stuID++; 
}*/
int main()
{
    Student Wang;
    Student Li;
    Student Xu;
    cout << Wang.getID1() << '\n';
    cout << Wang.getID2() << '\n';
    cout << Li.getID1() << '\n';
    cout << Li.getID2() << '\n';
    cout << Xu.getID1() << '\n';
    cout << Xu.getID2() << '\n';
    //cout << Student::getID1() << '\n';
    cout << Student::getID2() << '\n'; // ����ͨ�� ���� ֱ�ӷ��� ���� ��̬ ��Ա����
    //cout << Student::stuID << '\n';
    //cout << Student::ID << '\n'; // ����ͨ�� ���� ֱ�ӷ��� ���� ��̬ ��Ա����
    return 0;
}