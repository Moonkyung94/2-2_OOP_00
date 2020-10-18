#include <fstream>
#include <iostream>
#include <string>
//201902645 강문경
//과제 1번
class AnyString {
	std::string anyString;

public:
	AnyString(const std::string& anyString) : anyString(anyString) {}
	std::string getAnyString() {
		return "Stored String :: " + anyString;
	}
	//operator overloading
	friend std::ofstream& operator<<(std::ofstream& out, AnyString& a);//private을 접근하기 위해 friend 키워드 추가
};
	//operator overloading
	std::ofstream& operator<<(std::ofstream& out, AnyString& a) {//non-member function
		out << a.getAnyString();//out에 a.getAnyString()을 넣는다.
		return out;//out을 반환
	}


int main() {
	std::ofstream out("testOveroding.txt");
	AnyString a("Hello, this is operator overloading test!!!");

	out << a << std::endl;//operator<<(std::ofstream out, AnyString a)
	return 0;
}