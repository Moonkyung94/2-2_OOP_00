//#include <string>
//#include <iostream>
//
//int main() {
//	std::string s;
//	std::cout << "���ڸ� �Է��ϼ���(100�� �̳�)." << std::endl;
//	std::cin >> s;
//	std::cout << "�Էµ� ���ڴ� " << s << "�Դϴ�." << std::endl;
//
//	system("pause"); // keep terminal open
//	return 0;
//}

/*
* 201902645 ������
* 4���� ���� 1�� : ���� C++�ڵ带 C�ڵ�� �����ϱ�
*/
#include<stdio.h> //ǥ�� ����� �������
int main() {//���� �Լ�
	char s[100];//ũ�Ⱑ 100�� char�� �迭�� ����
	printf("���ڸ� �Է��ϼ���(100�� �̳�).\n");//��¹�
	scanf_s("%s", s,sizeof(s));//�Է��� �޾Ƽ� �迭 ������ ���ڿ� s�� ����
	printf("�Էµ� ���ڴ� %s �Դϴ�.", s);// s�� ����ϴ� ��¹�
	return 0;//����
}