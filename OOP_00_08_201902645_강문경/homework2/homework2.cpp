#include <iostream>
//201902645 ������
//8���� ���� 2��
class Strategy { //interface
public:
	virtual int doOperation(int num1, int num2) = 0;
};

class OperationAdd : public Strategy { //ConcreteStrategy
public :
	int doOperation(int num1, int num2) {
		return num1 + num2;
	}
};
class OperationSubstract : public Strategy {//ConcreteStrategy
public:
	int doOperation(int num1, int num2) {
		return num1 - num2;
	}
};
class OperationMultiply : public Strategy {//ConcreteStrategy
public:
	int doOperation(int num1, int num2) {
		return num1 * num2;
	}
};
class Context { //Context
private :
	Strategy* strategy;
public :
	Context(Strategy* strategy) {
		if (this->strategy) delete this->strategy; //strategy�� �����ϸ� �� strategy�� �����Ѵ�.
		this->strategy = strategy;//���ο� ConcreteStrategies�� �ٽ� �����Ѵ�.
	}
	int executeStrategy(int num1, int num2) {
		return strategy->doOperation(num1, num2);
	}
};
int main() {//StrategyPatternDemo
	Context* context = new Context(new OperationAdd());
	std::cout << "10 + 5 = " << context->executeStrategy(10, 5) << std::endl;
	context = new Context(new OperationSubstract());
	std::cout << "10 - 5 = " << context->executeStrategy(10, 5) << std::endl;
	context = new Context(new OperationMultiply());
	std::cout << "10 * 5 = " << context->executeStrategy(10, 5) << std::endl;
	return 0;
}