#include<iostream>
class SetValue {
	public:
		int x, y;//������ ���� ������ �ڵ����� private���� �����ϰ� ��
};
int main() {
	SetValue obj;
	obj.x = 33;
	obj.y = 44;
	std::cout << "X = " << obj.x << " , Y = " << obj.y << std::endl;
	system("pause");
	return 0;

}