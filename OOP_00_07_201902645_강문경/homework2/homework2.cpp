#include <iostream>
// 201902645 ������
// ���� 2
bool funcA() {
    int c;
    std::cin >> c;
    if (c < 10) //Let's assume this is exception
        throw std::out_of_range("Invalid Input!!");//c�� 10���� �۴ٸ�
    //throw�� ���� catch������ std::out_of_range �� ������ ������. 
    return true;
}
int main() {
    try {
        funcA();
    }
    catch(std::out_of_range& a){//try���� ���ܰ� �߻��ϸ� ����ȴ�.
        //throw�� �ǿ����ڴ� ���� ��ü�� ���� �Ű������� ���� �ȴ�.
        std::cout << "Exception : " << a.what() << std::endl;
        //a�� ������ �ִ� std::out_of_range("Invalid Input!!")�� a.what()�� ���� ����Ѵ�.
    }
    return 0;

}
