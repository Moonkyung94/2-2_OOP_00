/*201902645 강문경*/
#include<locale.h>

#include<string>
#include<vector>
#include<iostream>
#include<fstream>




#define maxLine 20//한페이지의 최대 줄 수 
#define maxByte 75//한 줄의 최대 바이트 수

static std::vector<std::vector<std::wstring>> pageLine;//한 줄, 75바이트를 가지고 있는 vector
static std::vector<std::wstring> wstr;//모든 단어와 공백을 분리하여 저장하고 있는 vector
static int pageNum = 0;//줄 번호
class fileRead {
public:
	std::vector<std::vector<std::wstring>> read;//파일을 읽을때 사용하는 vector
	std::vector<std::wstring> read2;//read벡터 안에 있는 벡터, 2차원 벡터
	std::wstring input;//파일을 읽을때 사용하는 변수
	void fileopen() {//파일을 열어서 데이터를 읽는 함수
		std::locale::global(std::locale(".UTF-8"));//UTF-8형태로 설정.
		std::wifstream in(L"test.txt");//UTF-8 형태로 파일을 읽는다.
		if (!in.is_open()) {//파일이 열려 있지 않다면, 오류 문구 출력.
			std::cout << "Can't find the file" << std::endl;
		}
		else {//파일이 열려있으면 파일에 있는 데이터 저장하기
			int i = 0;
			while (!in.eof()) {//파일의 끝에 도달하면 while문 종료
				in >> input; //공백을 만나기 전까지 문자열을 읽는다 => 한 단어	
				read.push_back(read2);//read 벡터에 read2벡터를 추가해서 read[i]에 문자열을 담을수 있도록 이차원 벡터를 만든다
				read.at(i).push_back(input);//read.at(i)에 입력받은 문자를 추가한다.
				i = i + 1;//index i를 증가시킨다.
				read.push_back(read2);//index i 다음칸에 이차원 벡터를 만든다.
				read.at(i).push_back(L" ");//wstring이 공백을 읽지 않으므로 공백을 read 벡터에 추가하여 준다.
				i = i+1;//index i를 증가시킨다.
			}
		}
		in.close();//파일에 있는 데이터를 모두 읽었으면 파일을 종료한다.
	}
	void save() {//read 벡터를 wstr과 pageLine에 저장하는 함수
		int i = 0, j = 0;//바이트 크기, 줄 크기
		unsigned int charnum = 0;//이차원 벡터의 인덱스
		unsigned int x = 0;//wstr벡터의 인덱스 위치
		unsigned int p = 0;//반복문에 사용하는 변수
		for (p = 0; p < read.size(); p++) {//p = 단어의 개수
			i = i + read[p][0].size();//한 단어의 바이트 크기를 계산한다.
			if (i >= maxByte) {//75바이트를 초과하면 다음 줄로 넘어가야 한다.
				i = 0;//바이트 크기 초기화
				pageLine.push_back(std::vector<std::wstring>());//pageLine벡터를 이차원 백터로 만들어준다.
				for (x; x < p; x++) {// 한 줄에 해당하는 단어들을 pageLine.at(j)에 추가해주는 반복문
					pageLine.at(j).push_back(wstr[x]);
				}
				j = j + 1;//다음 줄로 이동
				x = p;//다음 줄의 시작 값 저장
				p--;//p는 추가되지 않았기 때문에 p--를 해주어서 p부터 다시 탐색할수 있게 한다.
			}
			else{//75바이트 보다 작으면 wstr에 read[p]벡터를 추가하여 준다.
				wstr.push_back(read[p][charnum]);
			}
		}
		if (p == read.size()) {//마지막 줄도 pageLine에 추가하여 준다.
			pageLine.push_back(std::vector<std::wstring>());
			for (x; x < read.size(); x++) {
				pageLine.at(j).push_back(wstr[x]);
			}
			
		}
	}
};

class Print {//print 클래스
public:
	void printPage(int n) {//인자로 입력받은 n부터 20줄을 출력하는 함수
		int p = 1;//줄번호 출력을 위한 변수
		pageNum = n;//pageNum 초기화
		std::vector<std::wstring> print;//print 벡터
		for (int i = pageNum; i < pageNum+20; i++) {//pageNum부터 20줄 반복하는 반복문
			if (i >= (int)pageLine.size()) {//i가 마지막 줄번호보다 크다면 for문을 빠져나온다.
				break;
			}
			print = pageLine.at(i);//print에 i번째 pageLine저장
			std::cout.width(2);//십의 자리수까지 출력
			std::cout <<p++<< " | ";//줄 번호 출력
			for (unsigned int j = 0; j < print.size(); j++) {//한 줄을 출력하는 반복문
				std::wstring str = print.at(j);
				std::wcout << str;
			}
			std::cout << std::endl;//\n
		}
		printdefault();//printdefault함수 호출
	}
	void printdash() {// '-'를 출력해주는 함수
		for (int i = 0; i < maxByte + 5; i++) {
			std::cout << "-";
		}
		std::cout << std::endl;
	}
	void printdefault() {//입력 정보를 출력해주는 함수
		printdash();
		std::wcout << L"n : 다음페이지, p : 이전페이지, i : 삽입, d : 삭제, c : 변경, s : 찾기, t : 저장 후 종료" << std::endl;
		printdash();
	}
	void consoleMessage() {//처음 출력할때 초기 값을 출력해주는 함수
		std::wcout << L"(콘솔 메세지)" << std::endl;
		printdash();
	}
	void sortChar() {//내용 갱신 함수
		int i = 0, j = 0;//바이트크기, 줄크기
		unsigned int charnum = 0;
		unsigned int x = 0;
		unsigned int p = 0;
		pageLine.clear();//pageLine 초기화
		std::vector<std::wstring> s;
		for (p = 0; p < wstr.size(); p++) {//단어 개수만큼 반복하는 반복문
			i = i + wstr[p].size();//i에 바이트 크기 계산 값을 저장
			if (i >= maxByte) {//한줄 길이 초과
				i = 0;//바이트 크기 0으로 초기화
				pageLine.push_back(std::vector<std::wstring>());//pageLine에 이차원 배열 생성
				for (x; x < p; x++) {//한 줄에 해당하는 단어를 저장하는 반복문
					pageLine.at(j).push_back(wstr[x]);
				}
				j = j + 1;//pageLine의 인덱스 값 1 증가 시킨다. 줄 바꿈
				x = p;//다음의 저장할 단어 위치를 x에 저장
				p--;//p는 추가되지 않았기 때문에 p--를 해주어서 p부터 다시 탐색할수 있게 한다.
			}
		}
		if (p == wstr.size()) {//마지막 줄 추가하기
			pageLine.push_back(std::vector<std::wstring>());//이차원 배열 생성
			for (x; x < wstr.size(); x++) {//마지막 줄에 해당하는 단어 저장
				pageLine.at(j).push_back(wstr[x]);
			}

		}
		printPage(pageNum);//printPage 호출
	}
};
class textEditor {//추상 클래스, 팩토리 패턴
public:
	Print print;
	static textEditor* editorFactory(std::wstring c);//textEditorFactory
	virtual void action() = 0;//추상 매소드
};


class nextPage : public textEditor{//다음 페이지를 출력하는 클래스
public:
	void action() override {
		pageNum = pageNum + 20;//20줄에 1페이지이므로 +20을 통하여 다음페이지로 이동하는 효과가 생긴다
		unsigned int i = pageNum;
				if (i > pageLine.size() - 1) {//예외처리
					print.printdefault();
					std::cout << "This is the last page!" << std::endl;
					pageNum = pageLine.size()-20;//마지막 페이지에 도달했으므로 pageNum값을 마지막 페이지의 첫째줄 값으로 저장한다.
					print.printdash();
					return;
				}
				else {//정상
					if (pageNum + 20 > (int)(pageLine.size() - 1)) {//마지막 페이지를 20줄로 출력해주기 위해서 pageNum값을 변경한다.
						pageNum = pageLine.size() - 20;
					}
					print.printPage(pageNum);//printPage호출
				}
	}
};
class prevPage :public textEditor {//이전 페이지를 출력하는 클래스
public:
	void action() {
		pageNum = pageNum - 20;//-20을 통하여 이전페이지로 이동하는 효과가 생긴다
				if (pageNum < 0) {//예외처리, 이미 제일 앞 페이지
					print.printdefault();
					std::cout << "This is the first page!" << std::endl;
					print.printdash();
					pageNum = 0;//pageNum값 초기화
					return;
				}
				else {//정상
					if (pageNum - 20 < 0) {//첫번째 페이지를 20줄로 출력해주기 위함
					pageNum = 0;
		}
					print.printPage(pageNum);//printPage호출
				}
	}
};
class wordDelete :public textEditor {//단어를 삭제하는 클래스
private :
	int line, num;
public :
	wordDelete(int a, int b) {
		line = a;
		num = b;
	}
	void action() {
		//단어 삭제
		int i = 0;
		int j = 0;
		int size = 0;
		int page = 0;
		for (page = 0; page < pageNum+ (line); page++) {//해당 단어의 wstr[i]위치를 찾기 위해서 size값을 계산한다.
			size = size + pageLine[page].size();
		}
		for (i = 0; i < num; i++) {//해당 줄에서의 위치를 파악하기 위한 반복문
			if (pageLine[pageNum + line][i] == (L" ")) {//공백은 단어가 아니므로 num값을 증가시켜준다.
				num = num + 1;
			}
		}
		size = size + num-1;//size값을 구한다.
		std::copy(wstr.begin() + size+2, wstr.end(), wstr.begin() + size);//단어와 공백이 인덱스 2개를 차지하고 있기때문에
		//size+2 부터 끝까지를 size위치를 시작으로 복사한다. 그러면 원하는 단어만 삭제가 된다.
		wstr.pop_back();//맨 뒤의 값을 삭제한다.
		wstr.pop_back();//맨 뒤의 값을 삭제한다.
		print.sortChar();//삭제가 되면 단어의 위치들이 달라지므로 sortChar()호출하여 단어를 다시 정렬한다.
	}
};
class wordInsert :public textEditor {//단어를 추가하는 클래스
private:
	int line, num;
	std::wstring word;
public:
	wordInsert(int a, int b, std::wstring c) {
		line = a;
		num = b;
		word = c;
	}
	void action() {
		int i = 0;
				int j = 0;
				int size = 0;
				int page = 0;
				for (page = 0; page < pageNum+(line); page++) {//해당 단어의 wstr[i]위치를 찾기 위해서 size값을 계산한다.
					size = size + pageLine[page].size();
				}
				for (i= 0; i < num; i++) {//해당 줄에서의 위치를 파악하기 위한 반복문
					if (pageLine[pageNum + line][i] == (L" ")) {//공백은 단어가 아니므로 num값을 증가시켜준다.
								num = num + 1;
							}
						}
				size = size + num;//size값을 구한다.
				std::vector<std::wstring>::iterator it = wstr.begin();
				it = wstr.insert(it+size,L" ");//공백을 우선 삽입하고
				wstr.insert(it + 1, word);//그 뒤에 해당 단어를 삽입한다.
				print.sortChar();//삽입이 되면 단어의 위치들이 달라지므로 sortChar()호출하여 단어를 다시 정렬한다.
		
	}
};
class wordChange :public textEditor {//단어를 바꾸는 클래스
private:
	std::wstring findword, changeword;
public:
	wordChange(std::wstring a, std::wstring b) {
		findword = a;
		changeword = b;
	}
	void action() {
		//단어찾고 단어 바꾸기
		unsigned int i = 0;
		int count = 0;
		while (i < wstr.size()) {//wstr의 크기만큼 반복하는 반복문, 모든 단어를 탐색한다.
			if (!wstr[i].compare(findword)) {//같은 단어를 찾으면
				wstr[i].erase();//단어를 우선 삭제한다.
				std::vector<std::wstring>::iterator it = wstr.begin();
				it = wstr.insert(it + i, changeword);//그 위치에 바꿀 단어를 삽입한다.
				count = count + 1;//같은 단어를 찾았는지 확인하기 위한 변수
			}
			i = i + 1;
		}
		if (count == 0) {//같은 단어가 없으면 출력
			print.printdefault();
			std::wcout << L"단어를 찾지 못하였습니다." << std::endl;
			print.printdash();
		}
		else {
			print.sortChar();//sortChar()호출
		}
		
	}
};
class wordSearch :public textEditor {//단어를 찾는 클래스
private :
	std::wstring findword;
public:
	wordSearch(std::wstring	a) {
		findword = a;
	}
	void action() {
		//단어 찾고 그 단어를 포함하는 줄을 첫째 줄로 해서 출력
		int count = 0;
		int i = 0;
		unsigned int size = 0;
		for (i = pageNum; i < pageNum + 20; i++) {//줄 탐색
			for (unsigned int j = 0; j < pageLine[i].size();j++) {//줄에 있는 단어 탐새
				if (!pageLine[i][j].compare(findword)) {//찾으면
					return print.printPage(i);//해당 페이지를 제일 윗줄로 해서 리턴
				}
			}
		}//찾지못하면
		print.printdefault();
		std::wcout << L"단어를 찾지 못하였습니다." << std::endl;
		print.printdash();
		
	}
};
class saveAndTerminate :public textEditor {
	//저장후 종료
public:
	void action() {
		std::locale::global(std::locale(".UTF-8"));//UTF-8형태로 설정
		std::wofstream out(L"testSave.txt");//UTF-8형태로 쓸 파일을 연다. 

		if (!out.is_open()) {//파일이 열리지 않았다면 에러 문구 출력
			std::cout << "Can't find the file" << std::endl;
		}
		else {//제대로 열렸다면
			for (unsigned int i = 0; i < pageLine.size(); i++) {//파일에 pageLine에 저장되어있는 단어들을 저장한다.
				for (unsigned int j = 0; j < pageLine[i].size(); j++) {
					out << pageLine[i][j];
				}
				out << std::endl;
			}
			std::wcout << L"저장 후 정상적으로 종료되었습니다." << std::endl;
		}
		out.close();//파일을 종료한다.
	}
};
class error :public textEditor {//에러가 나는 부분에 문구를 출력하기 위한 클래스
private :
	int errnum;
public:
	error(int n) {
		errnum = n;
	}
	void action() {
		print.printdefault();
		if (errnum == 0) {
			std::wcout << L"입력이 올바르지 않습니다. 다시 입력하세요." << std::endl;
		}
		else if (errnum == 1) {
			std::wcout << L"첫번째 인자 입력 오류 : 숫자가 입력되지 않았습니다. 1~20사이의 숫자를 입력하세요." << std::endl;
		}
		else if (errnum == 2) {
			std::wcout << L"첫번째 인자 입력 오류 : 줄 번호의 범위를 벗어났습니다. 1~20 사이의 숫자를 입력하세요." << std::endl;
		}
		else if (errnum == 3) {
			std::wcout << L"두번째 인자 입력 오류 : 숫자가 입력되지 않았습니다. 숫자를 입력하세요." << std::endl;
		}
		else if (errnum == 4) {

		}
		else if (errnum == 5) {
			std::wcout << L"세번째 인자 입력 오류 : 한 줄에 75바이트 이상 출력이 불가능합니다. 다시 입력하세요." << std::endl;
		}
		else if (errnum == 6) {
			std::wcout << L"첫번째 인자 입력 오류 : 한 줄에 75바이트 이상 출력이 불가능합니다. 다시 입력하세요." << std::endl;
		}
		else if (errnum == 7) {
			std::wcout << L"두번째 인자 입력 오류 : 한 줄에 75바이트 이상 출력이 불가능합니다. 다시 입력하세요." << std::endl;
		}
		print.printdash();
	}
};
textEditor* textEditor::editorFactory(std::wstring c) {//textEditorFactory 매소드
	wchar_t a = c.at(0);//cin을 통해 입력받은 문자열중 첫번째 문자열을 보고 어떤 객체를 생성할지 결정한다.
	if (a == 'n') {//다음 페이지 출력
		if (c.length() > 1) {
			return new error(0);
		}
		return new nextPage;
	}
	else if (a == 'p') {//이전 페이지 출력
		if (c.length() > 1) {
			return new error(0);
		}
		return new prevPage;
	}
	else if (a == 'i') {//삽입
		int i = 0;
		int line = 0;
		int num = 0;
		std::wstring word;
		int wordcount = 0;
		if (c.length() < 3) {
			return new error(0);
		}
		if (c.at(1) != '(' || c.at(2) == ' ') {//두번째 문자가 '('이 아니거나 세번째 문자가 공백이면 error
			return new error(0);
		}
		for (i = 2; c.at(i) != ','; i++) {//쉼표로 인자를 구분
			if (48 <= c.at(i) && c.at(i) <= 57) {
				line = line * 10 + ((int)(c.at(i)) - 48);
			}
			else {//쉼표 전에 숫자가 아닌 다른 문자가 있으면 error
				return new error(1);
			}
		}
		if (line > 20 || line <= 0) {//line이 20보다 크거나 0보다 작으면 페이지에서 찾을수 없으므로 error
			return new error(2);
		}
	
		for (unsigned int j = 0; j < pageLine[pageNum + line - 1].size(); j++) {//해당 line의 단어수를 계산하는 반복문
			if (pageLine[pageNum + line - 1][j] != L" ") {
				wordcount = wordcount + 1;
			}
		}
		for (++i; c.at(i) != ','; i++) {//두번째 인자 읽기
			if (48 <= c.at(i) && c.at(i) <= 57) {
				num = num * 10 + (int)(c.at(i) - 48);
			}
			else {//쉼표 전에 숫자가 아닌 다른 문자가 있으면 error
				return new error(3);
			}
		}

		if (num > wordcount) {//입력된 인자의 값이 해당줄의 단어의 수보다 많으면 error
			//에러
			std::wcout << L"두번째 인자 입력 오류 : 단어 개수의 범위를 벗어났습니다. 0~" << wordcount << L" 사이의 숫자를 입력하세요." << std::endl;
			return new error(4);
		}
		for (++i; c.at(i) != ')'; i++) {//세번째 인자
			word = word + c.at(i);
				if (word.size() > 75) {//한줄의 최대바이트 보다 크다면 error
					return new error(5);
				}
		}
		return new wordInsert(line - 1, num, word);//정상적으로 모든 인자가 잘 입력되었으면 wordInsert객체 생성
	}
	else if (a == 'd') {//삭제
		int i = 0;
		int line = 0;
		int num = 0;
		int wordcount = 0;
		if (c.length() < 3) {
			return new error(0);
		}
		if (c.at(1) != '(' || c.at(2) == ' ' ) {//두번째 문자가 '('이 아니거나 세번째 문자가 공백이면 error
			return new error(0);
		}
		for (i = 2; c.at(i) != ','; i++) {//쉼표로 인자를 구분
			if (48 <= c.at(i) && c.at(i) <= 57) {
				line = line * 10 + ((int)(c.at(i)) - 48);
			}
			else {//쉼표전에 숫자가 아닌 다른 문자가 오면 error
				return new error(1);
			}
		}
		if (line > 20 || line <= 0) {//line이 20보다 크거나 0보다 작으면 페이지에서 찾을수 없으므로 error
		return new error(2);
	}
		for (unsigned int j = 0; j < pageLine[pageNum + line - 1].size(); j++) {//해당 line의 단어수를 계산하는 반복문
			if (pageLine[pageNum + line - 1][j] != L" ") {
				wordcount = wordcount + 1;
			}
		}
		for (++i; c.at(i) != ')'; i++) {//두번째 인자 읽기
			if (48 <= c.at(i) && c.at(i) <= 57) {
				num = num * 10 + (int)(c.at(i) - 48);
			}
			else {//')'전에 숫자가 아닌 다른 문자가 오면 error
				return new error(3);
			}
		}
		if (num > wordcount) {//입력된 인자의 값이 해당줄의 단어의 수보다 많으면 error
			//에러
			std::wcout << L"두번째 인자 입력 오류 : 단어 개수의 범위를 벗어났습니다. 0~" << wordcount << L" 사이의 숫자를 입력하세요." << std::endl;
			return new error(4);
		}
		return new wordDelete(line - 1, num);//정상적으로 모든 인자가 잘 입력되었으면 wordDelete객체 생성
	}
	else if (a == 'c') {//단어 교체
		int i = 2;
		std::wstring targetword;
		std::wstring changeword;
		if (c.length() < 3) {
			return new error(0);
		}
		if (c.at(1) != '(' || c.at(2) == ' ') {//두번째 문자가 '('이 아니거나 세번째 문자가 공백이면 error
			return new error(0);
		}
		for (i; c.at(i) != ','; i++) {//첫번째 인자 읽기
				targetword = targetword + c.at(i);
			if (targetword.size() > 75) {//한줄의 최대바이트 보다 크다면 error
				
				return new error(6);
			}
		}
		for (++i; c.at(i) != ')'; i++) {//두번째 인자 읽기
			
				changeword = changeword + c.at(i);
			
			if (targetword.size() > 75) {//한줄의 최대바이트 보다 크다면 error
				
				return new error(7);
			}
		}
		return new wordChange(targetword, changeword);//정상적으로 입력되었다면 wordChange객체 생성
	}
	else if (a == 's') {//탐색
		int i = 2;
		std::wstring targetword;
		if (c.length() < 3) {
			return new error(0);
		}
		if (c.at(1) != '(' || c.at(2) == ' ') {//두번째 문자가 '('이 아니거나 세번째 문자가 공백이면 error
			return new error(0);
		}
		for (i; c.at(i) != ')'; i++) {//첫번째 인자 읽기
				targetword = targetword + c.at(i);
				if (targetword.size() > 75) {//한줄의 최대바이트 보다 크다면 error
					return new error(6);
				}
		}
		return new wordSearch(targetword);//정상적으로 입력되었다면 wordSearch객체 생성
	}
	else{//저장 후 종료
		return new saveAndTerminate;//객체 생성
	}
}
class userInput{//클라이언트의 입력값을 읽는 클래스
	Print print;
public:
	void input() {
		std::wcout << L"입력 : ";
		std::wstring a;
		std::getline(std::wcin, a);//공백을 포함한 한 문장을 읽는다.
		std::cout << std::endl;
		
		while (true) {
			if ((a.at(0) == 'n')|| (a.at(0) == 'p') || (a.at(0) == 'i') || (a.at(0) == 'd') || (a.at(0) == 'c') || (a.at(0) == 's')) {
				//'t'를 제외한 기능에 해당하는 문자가 들어오면
				
				textEditor::editorFactory(a)->action();//문자에 해당하는 객체를 생성하고 action()함수를 호출한다.
				std::wcout << L"입력 : ";//'t'가 입력되기 전까지는 계속 반복해야 하므로
				std::getline(std::wcin, a);
				std::cout << std::endl;
				print.printdash();
			}
			else if (a.at(0) == 't') {//정상 종료
				textEditor::editorFactory(a)->action();//'t'가 입력되면 파일에 저장하고 texteditor종료
				break;//while문을 빠져나온다.
			}
			else {
				//비정상 입력일때는 오류문구를 출력하고 다시 입력하도록 한다.
				print.printdefault();
				std::wcout << L"비정상적인 유저 입력입니다. 다시 입력하세요" << std::endl;
				print.printdash();
				std::wcout << L"입력 : ";
				std::getline(std::wcin, a);
				std::cout << std::endl;
				print.printdash();
			}
		}
	}
};
int main() {
#ifdef _DEBUG
	setlocale(LC_ALL, ("korean"));
#endif // _DEBUG
	//_tsetlocale(LC_ALL, _T("korean"));
	//TRACE("");

	fileRead fileread; //fileRead객체를 생성하고, 파일을 읽고 그 값을 저장한다.
	fileread.fileopen();
	fileread.save();
	Print printPage;//첫번째 페이지를 출력한다.
	printPage.printPage(0);
	printPage.consoleMessage();
	
	userInput userinput;//userInput객체를 생성하고 text editor를 실행한다.
	userinput.input();
	return 0;
}