#include <iostream>
// 201902645 강문경
// 과제 2
bool funcA() {
    int c;
    std::cin >> c;
    if (c < 10) //Let's assume this is exception
        throw std::out_of_range("Invalid Input!!");//c가 10보다 작다면
    //throw를 통해 catch문으로 std::out_of_range 의 정보를 보낸다. 
    return true;
}
int main() {
    try {
        funcA();
    }
    catch(std::out_of_range& a){//try에서 예외가 발생하면 실행된다.
        //throw의 피연산자는 예외 객체의 형식 매개변수로 전달 된다.
        std::cout << "Exception : " << a.what() << std::endl;
        //a가 가지고 있는 std::out_of_range("Invalid Input!!")을 a.what()을 통해 출력한다.
    }
    return 0;

}
