#include<iostream>
/* 
201902645 강문경
3주차 과제
*/
class SetValue {
private:
	int x, y;//지정을 하지 않으면 자동으로 private으로 지정하게 됨
public : 
	SetValue() { //생성자
		x = 0; y = 0;
	}
	void setX(int a) { //setter
		x = a;
	}
	void setY(int b) { //setter
		y = b;
	}
	int getX() { //getter
		return x;
	}
	int getY() { //getter
		return y;
	}
};
int main() {
	SetValue obj;
	obj.setX(33); // x = 33;
	obj.setY(44); // y = 44;
	std::cout << "X = " << obj.getX() << " , Y = " << obj.getY() << std::endl;
	system("pause");
	return 0;

}