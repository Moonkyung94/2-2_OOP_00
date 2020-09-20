#include<iostream>
class SetValue {
	public:
		int x, y;//지정을 하지 않으면 자동으로 private으로 지정하게 됨
};
int main() {
	SetValue obj;
	obj.x = 33;
	obj.y = 44;
	std::cout << "X = " << obj.x << " , Y = " << obj.y << std::endl;
	system("pause");
	return 0;

}