#include <fstream>
#include <iostream>
#include <string>
//201902645 ������
//���� 1��
class AnyString {
	std::string anyString;

public:
	AnyString(const std::string& anyString) : anyString(anyString) {}
	std::string getAnyString() {
		return "Stored String :: " + anyString;
	}
	//operator overloading
	friend std::ofstream& operator<<(std::ofstream& out, AnyString& a);//private�� �����ϱ� ���� friend Ű���� �߰�
};
	//operator overloading
	std::ofstream& operator<<(std::ofstream& out, AnyString& a) {//non-member function
		out << a.getAnyString();//out�� a.getAnyString()�� �ִ´�.
		return out;//out�� ��ȯ
	}


int main() {
	std::ofstream out("testOveroding.txt");
	AnyString a("Hello, this is operator overloading test!!!");

	out << a << std::endl;//operator<<(std::ofstream out, AnyString a)
	return 0;
}