#define _CRT_SECURE_NO_WARNNING
#include <iostream>
//201902645 강문경
//과제 1번
class My_cat {
	char* name;
	int weight;

public:
	My_cat();
	My_cat(const char* name);
	My_cat(const My_cat& cat);
	~My_cat();
	
	My_cat& eat(int food);//eat 함수 선언

	void show_status() const;
};

My_cat::My_cat() :name(NULL), weight(10) { }

My_cat::My_cat(const char* cat_name) : weight(10) {
	name = new char[strlen(cat_name) + 1];
	strcpy_s(name, strlen(cat_name)+1,cat_name);
}

My_cat::My_cat(const My_cat& cat) : weight(10) { //Copy constructor
	std::cout << "Copy constructor invocation ! " << std::endl;
	name = new char[strlen(cat.name) + 1];
	strcpy_s(name,strlen(cat.name)+1, cat.name);
}

My_cat::~My_cat() {		//Destructor
	if (name) delete[] name;
}

//eat 함수를 구현하세요.
My_cat& My_cat::eat(int food) {
	weight = weight + food;//객체의 원래 weight에 인자로 들어온 food를 더해준다.
	return *this;//return type이 객체 자기자신의 레퍼런스이므로 *this를 리턴해준다.
}
void My_cat::show_status() const {
	std::cout << " Weight : " << weight << std::endl;
}
int main() {
	My_cat cat1("Nabi");	//Cat 1 생성
	cat1.show_status();

	cat1.eat(4);
	cat1.show_status();

	cat1.eat(4);
	cat1.show_status();

	cat1.eat(4).eat(5).eat(6);
	cat1.show_status();

	getchar();
	return 0;
}
