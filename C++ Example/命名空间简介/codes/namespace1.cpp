#include <iostream> 
// ���������ǲ�ʹ��using namespace std
namespace Student {
  int a = 108;
  int b = 100;
  namespace EE{
    double a = 15.05;
    double b = 84.95;
    void involution();
  }
  void EE::involution() {
    std::cout << "touching fish" << std::endl;
  }
  void involution(){
    std::cout << "involution" << std::endl;
  }
}
int main()
{
    std::cout << Student::b << ' ' << Student::EE::b << std::endl;
    //EE::involution();       // ���벻ͨ����Ƕ�׺����һ��һ�����ã�����ǰ��Ĳ��Ѿ�����
    using namespace Student;  // ���������ռ�
    std::cout << EE::a << ' ' << a << std::endl;
    EE::involution();
    involution();
    return 0;
}