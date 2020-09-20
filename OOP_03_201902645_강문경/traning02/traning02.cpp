#include<iostream>
#define MAXSTACKSIZE 1000//스텍의 최대 크기
class Stack {
	int top;//접근 지정자가 없기 때문에 private 으로 선언
public :
	int a[MAXSTACKSIZE];//스택
	Stack() {//생성자
		top = -1;//스택의 꼭대기 값 초기화
	}
	bool push(int x);
	int pop();
	
};
bool Stack::push(int x) {
	if (top >= MAXSTACKSIZE-1) {
		std::cout << "오류 : 스택이 넘쳤습니다." << std::endl;
		return false;
	}
	else {
		//코드 구현 : 스택에 데이터 넣기
		//top = top + 1;
		a[++top] = x;
		std::cout << x << "이 스택에 들어갔습니다." << std::endl;
		return true;
	}
}
int Stack::pop() {
	if (top < 0) {
		std::cout << "오류 : 스택이 비었습니다." << std::endl;
		return 0;
	}
	else {
		int x = a[top--];
		//a[top] = NULL;
		//top = top - 1;

		//코드 구현 : 스택에서 데이터 빼기
		return x;
	}
}
int main() {
	class Stack s;
	s.push(7);
	s.push(88);
	s.push(999);

	std::cout << s.pop() << "을 스텍에서 꺼냈습니다." << std::endl;
	std::cout << s.pop() << "을 스텍에서 꺼냈습니다." << std::endl;
	std::cout << s.pop() << "을 스텍에서 꺼냈습니다." << std::endl;
	std::cout << s.pop() << "을 스텍에서 꺼냈습니다." << std::endl;

	system("pause");
	return 0;
}