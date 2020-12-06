#include <iostream>
#include <string>
class Animal {
public :
	std::string name;
};

class Dog : public Animal {
protected:
	int dogspeed;
	std::string dogsize;
public:
	Dog() {};
	virtual int speed() = 0;
	virtual std::string size() = 0;
};
class Bird : public Animal {
protected:
	std::string koreanBird;
	std::string whereLived;
public :
	Bird() {};
	virtual std::string isKoreanBird() = 0;
	virtual std::string where() = 0;
};

class Pomeranian : public Dog {
public:
	Pomeranian(std::string name) {
		this->name = name;
	}
	int speed() {
		dogspeed = 16;
		return this->dogspeed;
	}
	std::string size(){
		dogsize = "����";
		return this->dogsize;
	}
};
class ShihTzu : public Dog{
public:
	ShihTzu(std::string name) {
		this->name = name;
	}

	int speed() {
		dogspeed = 10;
		return dogspeed;
	}
	std::string size() {
		dogsize= "����";
		return dogsize;
	}
};

class BorderCollie : public Dog {
public:

	BorderCollie(std::string name) {
		this->name = name;
	}
	int speed() {
		dogspeed = 48;
		return this->dogspeed;
	}
	std::string size() {
		dogsize = "����";
		return this->dogsize;
	}
};

class BaldEagle : public Bird {
public:
	BaldEagle(){
		this->name = "��Ӹ� ������";
	}
	std::string isKoreanBird() {
		koreanBird = "NO";
		return this->koreanBird;
	}
	std::string where() {
		whereLived = "America";
		return this->whereLived;
	}
};
class Sparrow : public Bird {
public:
	Sparrow() {
		this->name = "����";
	}
	std::string isKoreanBird() {
		koreanBird = "YES";
		return koreanBird;
	}
	std::string where() {
		whereLived = "Korea";
		return whereLived;
	}
};
class Pigeon : public Bird {
public:
	Pigeon() {
		this->name = "��ѱ�";
	}

	std::string isKoreanBird() {
		koreanBird = "YES";
		return koreanBird;
	}
	std::string where() {
		whereLived = "Korea";
		return whereLived;
	}
};
int main() {
	Pomeranian pomeranian("���޶�Ͼ�");
	std::cout << "[Dog] Name: " << pomeranian.name << ", speed: " << pomeranian.speed() << ", size: " << pomeranian.size() << std::endl;
	ShihTzu shihTzu("����");
	std::cout << "[Dog] Name: " << shihTzu.name << ", speed: " << shihTzu.speed() << ", size: " << shihTzu.size() << std::endl;
	BorderCollie borderCollie("���� �ݸ�");
	std::cout << "[Dog] Name: " << borderCollie.name << ", speed: " << borderCollie.speed() << ", size: " << borderCollie.size() << std::endl;
	BaldEagle baldeagle;
	std::cout << "[Bird] Name: " << baldeagle.name << ", ��°� : " << baldeagle.where() << ", �ѱ��� �����ϴ°� ? : " << baldeagle.isKoreanBird() << std::endl;
	Sparrow sparrow;
	std::cout << "[Bird] Name: " << sparrow.name << ", ��°� : " << sparrow.where() << ", �ѱ��� �����ϴ°� ? : " << sparrow.isKoreanBird() << std::endl;
	Pigeon pigeon;
	std::cout << "[Bird] Name: " << pigeon.name << ", ��°� : " << pigeon.where() << ", �ѱ��� �����ϴ°� ? : " << pigeon.isKoreanBird() << std::endl;
	return 0;
}