//#include <string>
//#include <iostream>
//
//int main() {
//	std::string s;
//	std::cout << "문자를 입력하세요(100자 이내)." << std::endl;
//	std::cin >> s;
//	std::cout << "입력된 문자는 " << s << "입니다." << std::endl;
//
//	system("pause"); // keep terminal open
//	return 0;
//}

/*
* 201902645 강문경
* 4주차 과제 1번 : 위의 C++코드를 C코드로 변경하기
*/
#include<stdio.h> //표준 입출력 헤더파일
int main() {//메인 함수
	char s[100];//크기가 100인 char형 배열을 선언
	printf("문자를 입력하세요(100자 이내).\n");//출력문
	scanf_s("%s", s,sizeof(s));//입력을 받아서 배열 형태의 문자열 s에 저장
	printf("입력된 문자는 %s 입니다.", s);// s를 출력하는 출력문
	return 0;//종료
}