#include <iostream>
//201902645 강문경
// 8주차 과제 1번
class GlobalClass {
private:
	int m_value;
	static GlobalClass* s_instance;

	GlobalClass(int v = 0) {
		m_value = v;
	}
public:
	int get_value() {
		return m_value;
	}
	void set_value(int v) {
		m_value = v;
	}
	static GlobalClass* instance() {
		// 내용을 완성하시오
		if (!s_instance) { //s_instance 가 없으면
			s_instance = new GlobalClass;//s_instance 이름의 객체를 생성하여 준다.
		}
		return s_instance;//s_instance를 리턴한다.
	}
};

// Allocating and initializing GlobalClass's
// static data member.  The pointer is being
// allocated - not the object itself.
GlobalClass* GlobalClass::s_instance = 0;

void foo(void) {
	GlobalClass::instance()->set_value(1);
	std::cout << "foo: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}

void bar(void) {
	GlobalClass::instance()->set_value(2);
	std::cout << "bar: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}

int main() {
	std::cout << "main: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
	foo();
	bar();
}