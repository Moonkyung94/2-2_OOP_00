#include <iostream>

class MyData {
	int number;
	std::string strNumber;
public:
	MyData(int data, std::string str) : number(data), strNumber(str) {}
	//Operator conversion
	operator int() { return number; }
	operator std::string() { return strNumber; }

	//Unary operator
	int operator++(int) { //postfix operation (indicated by dummy 'int')
	  //작성1
		MyData temp(*this);//임시객체를 만들고,임시객체의 생성자에는 원래의 값들을 초기값으로 설정.
		number++;//현재 객체의 number값을 1 더해준다.
		return temp;//현재 객체를 리턴하는 것이 아니라 임시객체를 리턴해서 1이 증가되지 않은 number를 리턴한다.
	}
	int operator++() { //prefix operation
	  //작성2
		return ++number;//number를 1 증가시킨 후 그 number를 리턴한다.
	}

	friend std::ostream& operator<<(std::ostream&, MyData&);
};

// non-member operator<< function
std::ostream& operator<<(std::ostream& os, MyData& md) {
	return os << "This number is: " << md.strNumber << "\n";
}

int main() {
	MyData mydata(1, "one");

	std::string strNum = mydata;
	int intNum = mydata;

	std::cout << strNum << std::endl; // one
	std::cout << intNum << std::endl; // 1
	std::cout << mydata++ << std::endl; // 1
	std::cout << ++mydata << std::endl; // 3
	std::cout << mydata;

}