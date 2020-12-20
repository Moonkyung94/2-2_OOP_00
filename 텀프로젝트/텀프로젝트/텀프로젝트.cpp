/*201902645 ������*/
#include<locale.h>

#include<string>
#include<vector>
#include<iostream>
#include<fstream>




#define maxLine 20//���������� �ִ� �� �� 
#define maxByte 75//�� ���� �ִ� ����Ʈ ��

static std::vector<std::vector<std::wstring>> pageLine;//�� ��, 75����Ʈ�� ������ �ִ� vector
static std::vector<std::wstring> wstr;//��� �ܾ�� ������ �и��Ͽ� �����ϰ� �ִ� vector
static int pageNum = 0;//�� ��ȣ
class fileRead {
public:
	std::vector<std::vector<std::wstring>> read;//������ ������ ����ϴ� vector
	std::vector<std::wstring> read2;//read���� �ȿ� �ִ� ����, 2���� ����
	std::wstring input;//������ ������ ����ϴ� ����
	void fileopen() {//������ ��� �����͸� �д� �Լ�
		std::locale::global(std::locale(".UTF-8"));//UTF-8���·� ����.
		std::wifstream in(L"test.txt");//UTF-8 ���·� ������ �д´�.
		if (!in.is_open()) {//������ ���� ���� �ʴٸ�, ���� ���� ���.
			std::cout << "Can't find the file" << std::endl;
		}
		else {//������ ���������� ���Ͽ� �ִ� ������ �����ϱ�
			int i = 0;
			while (!in.eof()) {//������ ���� �����ϸ� while�� ����
				in >> input; //������ ������ ������ ���ڿ��� �д´� => �� �ܾ�	
				read.push_back(read2);//read ���Ϳ� read2���͸� �߰��ؼ� read[i]�� ���ڿ��� ������ �ֵ��� ������ ���͸� �����
				read.at(i).push_back(input);//read.at(i)�� �Է¹��� ���ڸ� �߰��Ѵ�.
				i = i + 1;//index i�� ������Ų��.
				read.push_back(read2);//index i ����ĭ�� ������ ���͸� �����.
				read.at(i).push_back(L" ");//wstring�� ������ ���� �����Ƿ� ������ read ���Ϳ� �߰��Ͽ� �ش�.
				i = i+1;//index i�� ������Ų��.
			}
		}
		in.close();//���Ͽ� �ִ� �����͸� ��� �о����� ������ �����Ѵ�.
	}
	void save() {//read ���͸� wstr�� pageLine�� �����ϴ� �Լ�
		int i = 0, j = 0;//����Ʈ ũ��, �� ũ��
		unsigned int charnum = 0;//������ ������ �ε���
		unsigned int x = 0;//wstr������ �ε��� ��ġ
		unsigned int p = 0;//�ݺ����� ����ϴ� ����
		for (p = 0; p < read.size(); p++) {//p = �ܾ��� ����
			i = i + read[p][0].size();//�� �ܾ��� ����Ʈ ũ�⸦ ����Ѵ�.
			if (i >= maxByte) {//75����Ʈ�� �ʰ��ϸ� ���� �ٷ� �Ѿ�� �Ѵ�.
				i = 0;//����Ʈ ũ�� �ʱ�ȭ
				pageLine.push_back(std::vector<std::wstring>());//pageLine���͸� ������ ���ͷ� ������ش�.
				for (x; x < p; x++) {// �� �ٿ� �ش��ϴ� �ܾ���� pageLine.at(j)�� �߰����ִ� �ݺ���
					pageLine.at(j).push_back(wstr[x]);
				}
				j = j + 1;//���� �ٷ� �̵�
				x = p;//���� ���� ���� �� ����
				p--;//p�� �߰����� �ʾұ� ������ p--�� ���־ p���� �ٽ� Ž���Ҽ� �ְ� �Ѵ�.
			}
			else{//75����Ʈ ���� ������ wstr�� read[p]���͸� �߰��Ͽ� �ش�.
				wstr.push_back(read[p][charnum]);
			}
		}
		if (p == read.size()) {//������ �ٵ� pageLine�� �߰��Ͽ� �ش�.
			pageLine.push_back(std::vector<std::wstring>());
			for (x; x < read.size(); x++) {
				pageLine.at(j).push_back(wstr[x]);
			}
			
		}
	}
};

class Print {//print Ŭ����
public:
	void printPage(int n) {//���ڷ� �Է¹��� n���� 20���� ����ϴ� �Լ�
		int p = 1;//�ٹ�ȣ ����� ���� ����
		pageNum = n;//pageNum �ʱ�ȭ
		std::vector<std::wstring> print;//print ����
		for (int i = pageNum; i < pageNum+20; i++) {//pageNum���� 20�� �ݺ��ϴ� �ݺ���
			if (i >= (int)pageLine.size()) {//i�� ������ �ٹ�ȣ���� ũ�ٸ� for���� �������´�.
				break;
			}
			print = pageLine.at(i);//print�� i��° pageLine����
			std::cout.width(2);//���� �ڸ������� ���
			std::cout <<p++<< " | ";//�� ��ȣ ���
			for (unsigned int j = 0; j < print.size(); j++) {//�� ���� ����ϴ� �ݺ���
				std::wstring str = print.at(j);
				std::wcout << str;
			}
			std::cout << std::endl;//\n
		}
		printdefault();//printdefault�Լ� ȣ��
	}
	void printdash() {// '-'�� ������ִ� �Լ�
		for (int i = 0; i < maxByte + 5; i++) {
			std::cout << "-";
		}
		std::cout << std::endl;
	}
	void printdefault() {//�Է� ������ ������ִ� �Լ�
		printdash();
		std::wcout << L"n : ����������, p : ����������, i : ����, d : ����, c : ����, s : ã��, t : ���� �� ����" << std::endl;
		printdash();
	}
	void consoleMessage() {//ó�� ����Ҷ� �ʱ� ���� ������ִ� �Լ�
		std::wcout << L"(�ܼ� �޼���)" << std::endl;
		printdash();
	}
	void sortChar() {//���� ���� �Լ�
		int i = 0, j = 0;//����Ʈũ��, ��ũ��
		unsigned int charnum = 0;
		unsigned int x = 0;
		unsigned int p = 0;
		pageLine.clear();//pageLine �ʱ�ȭ
		std::vector<std::wstring> s;
		for (p = 0; p < wstr.size(); p++) {//�ܾ� ������ŭ �ݺ��ϴ� �ݺ���
			i = i + wstr[p].size();//i�� ����Ʈ ũ�� ��� ���� ����
			if (i >= maxByte) {//���� ���� �ʰ�
				i = 0;//����Ʈ ũ�� 0���� �ʱ�ȭ
				pageLine.push_back(std::vector<std::wstring>());//pageLine�� ������ �迭 ����
				for (x; x < p; x++) {//�� �ٿ� �ش��ϴ� �ܾ �����ϴ� �ݺ���
					pageLine.at(j).push_back(wstr[x]);
				}
				j = j + 1;//pageLine�� �ε��� �� 1 ���� ��Ų��. �� �ٲ�
				x = p;//������ ������ �ܾ� ��ġ�� x�� ����
				p--;//p�� �߰����� �ʾұ� ������ p--�� ���־ p���� �ٽ� Ž���Ҽ� �ְ� �Ѵ�.
			}
		}
		if (p == wstr.size()) {//������ �� �߰��ϱ�
			pageLine.push_back(std::vector<std::wstring>());//������ �迭 ����
			for (x; x < wstr.size(); x++) {//������ �ٿ� �ش��ϴ� �ܾ� ����
				pageLine.at(j).push_back(wstr[x]);
			}

		}
		printPage(pageNum);//printPage ȣ��
	}
};
class textEditor {//�߻� Ŭ����, ���丮 ����
public:
	Print print;
	static textEditor* editorFactory(std::wstring c);//textEditorFactory
	virtual void action() = 0;//�߻� �żҵ�
};


class nextPage : public textEditor{//���� �������� ����ϴ� Ŭ����
public:
	void action() override {
		pageNum = pageNum + 20;//20�ٿ� 1�������̹Ƿ� +20�� ���Ͽ� ������������ �̵��ϴ� ȿ���� �����
		unsigned int i = pageNum;
				if (i > pageLine.size() - 1) {//����ó��
					print.printdefault();
					std::cout << "This is the last page!" << std::endl;
					pageNum = pageLine.size()-20;//������ �������� ���������Ƿ� pageNum���� ������ �������� ù°�� ������ �����Ѵ�.
					print.printdash();
					return;
				}
				else {//����
					if (pageNum + 20 > (int)(pageLine.size() - 1)) {//������ �������� 20�ٷ� ������ֱ� ���ؼ� pageNum���� �����Ѵ�.
						pageNum = pageLine.size() - 20;
					}
					print.printPage(pageNum);//printPageȣ��
				}
	}
};
class prevPage :public textEditor {//���� �������� ����ϴ� Ŭ����
public:
	void action() {
		pageNum = pageNum - 20;//-20�� ���Ͽ� ������������ �̵��ϴ� ȿ���� �����
				if (pageNum < 0) {//����ó��, �̹� ���� �� ������
					print.printdefault();
					std::cout << "This is the first page!" << std::endl;
					print.printdash();
					pageNum = 0;//pageNum�� �ʱ�ȭ
					return;
				}
				else {//����
					if (pageNum - 20 < 0) {//ù��° �������� 20�ٷ� ������ֱ� ����
					pageNum = 0;
		}
					print.printPage(pageNum);//printPageȣ��
				}
	}
};
class wordDelete :public textEditor {//�ܾ �����ϴ� Ŭ����
private :
	int line, num;
public :
	wordDelete(int a, int b) {
		line = a;
		num = b;
	}
	void action() {
		//�ܾ� ����
		int i = 0;
		int j = 0;
		int size = 0;
		int page = 0;
		for (page = 0; page < pageNum+ (line); page++) {//�ش� �ܾ��� wstr[i]��ġ�� ã�� ���ؼ� size���� ����Ѵ�.
			size = size + pageLine[page].size();
		}
		for (i = 0; i < num; i++) {//�ش� �ٿ����� ��ġ�� �ľ��ϱ� ���� �ݺ���
			if (pageLine[pageNum + line][i] == (L" ")) {//������ �ܾ �ƴϹǷ� num���� ���������ش�.
				num = num + 1;
			}
		}
		size = size + num-1;//size���� ���Ѵ�.
		std::copy(wstr.begin() + size+2, wstr.end(), wstr.begin() + size);//�ܾ�� ������ �ε��� 2���� �����ϰ� �ֱ⶧����
		//size+2 ���� �������� size��ġ�� �������� �����Ѵ�. �׷��� ���ϴ� �ܾ ������ �ȴ�.
		wstr.pop_back();//�� ���� ���� �����Ѵ�.
		wstr.pop_back();//�� ���� ���� �����Ѵ�.
		print.sortChar();//������ �Ǹ� �ܾ��� ��ġ���� �޶����Ƿ� sortChar()ȣ���Ͽ� �ܾ �ٽ� �����Ѵ�.
	}
};
class wordInsert :public textEditor {//�ܾ �߰��ϴ� Ŭ����
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
				for (page = 0; page < pageNum+(line); page++) {//�ش� �ܾ��� wstr[i]��ġ�� ã�� ���ؼ� size���� ����Ѵ�.
					size = size + pageLine[page].size();
				}
				for (i= 0; i < num; i++) {//�ش� �ٿ����� ��ġ�� �ľ��ϱ� ���� �ݺ���
					if (pageLine[pageNum + line][i] == (L" ")) {//������ �ܾ �ƴϹǷ� num���� ���������ش�.
								num = num + 1;
							}
						}
				size = size + num;//size���� ���Ѵ�.
				std::vector<std::wstring>::iterator it = wstr.begin();
				it = wstr.insert(it+size,L" ");//������ �켱 �����ϰ�
				wstr.insert(it + 1, word);//�� �ڿ� �ش� �ܾ �����Ѵ�.
				print.sortChar();//������ �Ǹ� �ܾ��� ��ġ���� �޶����Ƿ� sortChar()ȣ���Ͽ� �ܾ �ٽ� �����Ѵ�.
		
	}
};
class wordChange :public textEditor {//�ܾ �ٲٴ� Ŭ����
private:
	std::wstring findword, changeword;
public:
	wordChange(std::wstring a, std::wstring b) {
		findword = a;
		changeword = b;
	}
	void action() {
		//�ܾ�ã�� �ܾ� �ٲٱ�
		unsigned int i = 0;
		int count = 0;
		while (i < wstr.size()) {//wstr�� ũ�⸸ŭ �ݺ��ϴ� �ݺ���, ��� �ܾ Ž���Ѵ�.
			if (!wstr[i].compare(findword)) {//���� �ܾ ã����
				wstr[i].erase();//�ܾ �켱 �����Ѵ�.
				std::vector<std::wstring>::iterator it = wstr.begin();
				it = wstr.insert(it + i, changeword);//�� ��ġ�� �ٲ� �ܾ �����Ѵ�.
				count = count + 1;//���� �ܾ ã�Ҵ��� Ȯ���ϱ� ���� ����
			}
			i = i + 1;
		}
		if (count == 0) {//���� �ܾ ������ ���
			print.printdefault();
			std::wcout << L"�ܾ ã�� ���Ͽ����ϴ�." << std::endl;
			print.printdash();
		}
		else {
			print.sortChar();//sortChar()ȣ��
		}
		
	}
};
class wordSearch :public textEditor {//�ܾ ã�� Ŭ����
private :
	std::wstring findword;
public:
	wordSearch(std::wstring	a) {
		findword = a;
	}
	void action() {
		//�ܾ� ã�� �� �ܾ �����ϴ� ���� ù° �ٷ� �ؼ� ���
		int count = 0;
		int i = 0;
		unsigned int size = 0;
		for (i = pageNum; i < pageNum + 20; i++) {//�� Ž��
			for (unsigned int j = 0; j < pageLine[i].size();j++) {//�ٿ� �ִ� �ܾ� Ž��
				if (!pageLine[i][j].compare(findword)) {//ã����
					return print.printPage(i);//�ش� �������� ���� ���ٷ� �ؼ� ����
				}
			}
		}//ã�����ϸ�
		print.printdefault();
		std::wcout << L"�ܾ ã�� ���Ͽ����ϴ�." << std::endl;
		print.printdash();
		
	}
};
class saveAndTerminate :public textEditor {
	//������ ����
public:
	void action() {
		std::locale::global(std::locale(".UTF-8"));//UTF-8���·� ����
		std::wofstream out(L"testSave.txt");//UTF-8���·� �� ������ ����. 

		if (!out.is_open()) {//������ ������ �ʾҴٸ� ���� ���� ���
			std::cout << "Can't find the file" << std::endl;
		}
		else {//����� ���ȴٸ�
			for (unsigned int i = 0; i < pageLine.size(); i++) {//���Ͽ� pageLine�� ����Ǿ��ִ� �ܾ���� �����Ѵ�.
				for (unsigned int j = 0; j < pageLine[i].size(); j++) {
					out << pageLine[i][j];
				}
				out << std::endl;
			}
			std::wcout << L"���� �� ���������� ����Ǿ����ϴ�." << std::endl;
		}
		out.close();//������ �����Ѵ�.
	}
};
class error :public textEditor {//������ ���� �κп� ������ ����ϱ� ���� Ŭ����
private :
	int errnum;
public:
	error(int n) {
		errnum = n;
	}
	void action() {
		print.printdefault();
		if (errnum == 0) {
			std::wcout << L"�Է��� �ùٸ��� �ʽ��ϴ�. �ٽ� �Է��ϼ���." << std::endl;
		}
		else if (errnum == 1) {
			std::wcout << L"ù��° ���� �Է� ���� : ���ڰ� �Էµ��� �ʾҽ��ϴ�. 1~20������ ���ڸ� �Է��ϼ���." << std::endl;
		}
		else if (errnum == 2) {
			std::wcout << L"ù��° ���� �Է� ���� : �� ��ȣ�� ������ ������ϴ�. 1~20 ������ ���ڸ� �Է��ϼ���." << std::endl;
		}
		else if (errnum == 3) {
			std::wcout << L"�ι�° ���� �Է� ���� : ���ڰ� �Էµ��� �ʾҽ��ϴ�. ���ڸ� �Է��ϼ���." << std::endl;
		}
		else if (errnum == 4) {

		}
		else if (errnum == 5) {
			std::wcout << L"����° ���� �Է� ���� : �� �ٿ� 75����Ʈ �̻� ����� �Ұ����մϴ�. �ٽ� �Է��ϼ���." << std::endl;
		}
		else if (errnum == 6) {
			std::wcout << L"ù��° ���� �Է� ���� : �� �ٿ� 75����Ʈ �̻� ����� �Ұ����մϴ�. �ٽ� �Է��ϼ���." << std::endl;
		}
		else if (errnum == 7) {
			std::wcout << L"�ι�° ���� �Է� ���� : �� �ٿ� 75����Ʈ �̻� ����� �Ұ����մϴ�. �ٽ� �Է��ϼ���." << std::endl;
		}
		print.printdash();
	}
};
textEditor* textEditor::editorFactory(std::wstring c) {//textEditorFactory �żҵ�
	wchar_t a = c.at(0);//cin�� ���� �Է¹��� ���ڿ��� ù��° ���ڿ��� ���� � ��ü�� �������� �����Ѵ�.
	if (a == 'n') {//���� ������ ���
		if (c.length() > 1) {
			return new error(0);
		}
		return new nextPage;
	}
	else if (a == 'p') {//���� ������ ���
		if (c.length() > 1) {
			return new error(0);
		}
		return new prevPage;
	}
	else if (a == 'i') {//����
		int i = 0;
		int line = 0;
		int num = 0;
		std::wstring word;
		int wordcount = 0;
		if (c.length() < 3) {
			return new error(0);
		}
		if (c.at(1) != '(' || c.at(2) == ' ') {//�ι�° ���ڰ� '('�� �ƴϰų� ����° ���ڰ� �����̸� error
			return new error(0);
		}
		for (i = 2; c.at(i) != ','; i++) {//��ǥ�� ���ڸ� ����
			if (48 <= c.at(i) && c.at(i) <= 57) {
				line = line * 10 + ((int)(c.at(i)) - 48);
			}
			else {//��ǥ ���� ���ڰ� �ƴ� �ٸ� ���ڰ� ������ error
				return new error(1);
			}
		}
		if (line > 20 || line <= 0) {//line�� 20���� ũ�ų� 0���� ������ ���������� ã���� �����Ƿ� error
			return new error(2);
		}
	
		for (unsigned int j = 0; j < pageLine[pageNum + line - 1].size(); j++) {//�ش� line�� �ܾ���� ����ϴ� �ݺ���
			if (pageLine[pageNum + line - 1][j] != L" ") {
				wordcount = wordcount + 1;
			}
		}
		for (++i; c.at(i) != ','; i++) {//�ι�° ���� �б�
			if (48 <= c.at(i) && c.at(i) <= 57) {
				num = num * 10 + (int)(c.at(i) - 48);
			}
			else {//��ǥ ���� ���ڰ� �ƴ� �ٸ� ���ڰ� ������ error
				return new error(3);
			}
		}

		if (num > wordcount) {//�Էµ� ������ ���� �ش����� �ܾ��� ������ ������ error
			//����
			std::wcout << L"�ι�° ���� �Է� ���� : �ܾ� ������ ������ ������ϴ�. 0~" << wordcount << L" ������ ���ڸ� �Է��ϼ���." << std::endl;
			return new error(4);
		}
		for (++i; c.at(i) != ')'; i++) {//����° ����
			word = word + c.at(i);
				if (word.size() > 75) {//������ �ִ����Ʈ ���� ũ�ٸ� error
					return new error(5);
				}
		}
		return new wordInsert(line - 1, num, word);//���������� ��� ���ڰ� �� �ԷµǾ����� wordInsert��ü ����
	}
	else if (a == 'd') {//����
		int i = 0;
		int line = 0;
		int num = 0;
		int wordcount = 0;
		if (c.length() < 3) {
			return new error(0);
		}
		if (c.at(1) != '(' || c.at(2) == ' ' ) {//�ι�° ���ڰ� '('�� �ƴϰų� ����° ���ڰ� �����̸� error
			return new error(0);
		}
		for (i = 2; c.at(i) != ','; i++) {//��ǥ�� ���ڸ� ����
			if (48 <= c.at(i) && c.at(i) <= 57) {
				line = line * 10 + ((int)(c.at(i)) - 48);
			}
			else {//��ǥ���� ���ڰ� �ƴ� �ٸ� ���ڰ� ���� error
				return new error(1);
			}
		}
		if (line > 20 || line <= 0) {//line�� 20���� ũ�ų� 0���� ������ ���������� ã���� �����Ƿ� error
		return new error(2);
	}
		for (unsigned int j = 0; j < pageLine[pageNum + line - 1].size(); j++) {//�ش� line�� �ܾ���� ����ϴ� �ݺ���
			if (pageLine[pageNum + line - 1][j] != L" ") {
				wordcount = wordcount + 1;
			}
		}
		for (++i; c.at(i) != ')'; i++) {//�ι�° ���� �б�
			if (48 <= c.at(i) && c.at(i) <= 57) {
				num = num * 10 + (int)(c.at(i) - 48);
			}
			else {//')'���� ���ڰ� �ƴ� �ٸ� ���ڰ� ���� error
				return new error(3);
			}
		}
		if (num > wordcount) {//�Էµ� ������ ���� �ش����� �ܾ��� ������ ������ error
			//����
			std::wcout << L"�ι�° ���� �Է� ���� : �ܾ� ������ ������ ������ϴ�. 0~" << wordcount << L" ������ ���ڸ� �Է��ϼ���." << std::endl;
			return new error(4);
		}
		return new wordDelete(line - 1, num);//���������� ��� ���ڰ� �� �ԷµǾ����� wordDelete��ü ����
	}
	else if (a == 'c') {//�ܾ� ��ü
		int i = 2;
		std::wstring targetword;
		std::wstring changeword;
		if (c.length() < 3) {
			return new error(0);
		}
		if (c.at(1) != '(' || c.at(2) == ' ') {//�ι�° ���ڰ� '('�� �ƴϰų� ����° ���ڰ� �����̸� error
			return new error(0);
		}
		for (i; c.at(i) != ','; i++) {//ù��° ���� �б�
				targetword = targetword + c.at(i);
			if (targetword.size() > 75) {//������ �ִ����Ʈ ���� ũ�ٸ� error
				
				return new error(6);
			}
		}
		for (++i; c.at(i) != ')'; i++) {//�ι�° ���� �б�
			
				changeword = changeword + c.at(i);
			
			if (targetword.size() > 75) {//������ �ִ����Ʈ ���� ũ�ٸ� error
				
				return new error(7);
			}
		}
		return new wordChange(targetword, changeword);//���������� �ԷµǾ��ٸ� wordChange��ü ����
	}
	else if (a == 's') {//Ž��
		int i = 2;
		std::wstring targetword;
		if (c.length() < 3) {
			return new error(0);
		}
		if (c.at(1) != '(' || c.at(2) == ' ') {//�ι�° ���ڰ� '('�� �ƴϰų� ����° ���ڰ� �����̸� error
			return new error(0);
		}
		for (i; c.at(i) != ')'; i++) {//ù��° ���� �б�
				targetword = targetword + c.at(i);
				if (targetword.size() > 75) {//������ �ִ����Ʈ ���� ũ�ٸ� error
					return new error(6);
				}
		}
		return new wordSearch(targetword);//���������� �ԷµǾ��ٸ� wordSearch��ü ����
	}
	else{//���� �� ����
		return new saveAndTerminate;//��ü ����
	}
}
class userInput{//Ŭ���̾�Ʈ�� �Է°��� �д� Ŭ����
	Print print;
public:
	void input() {
		std::wcout << L"�Է� : ";
		std::wstring a;
		std::getline(std::wcin, a);//������ ������ �� ������ �д´�.
		std::cout << std::endl;
		
		while (true) {
			if ((a.at(0) == 'n')|| (a.at(0) == 'p') || (a.at(0) == 'i') || (a.at(0) == 'd') || (a.at(0) == 'c') || (a.at(0) == 's')) {
				//'t'�� ������ ��ɿ� �ش��ϴ� ���ڰ� ������
				
				textEditor::editorFactory(a)->action();//���ڿ� �ش��ϴ� ��ü�� �����ϰ� action()�Լ��� ȣ���Ѵ�.
				std::wcout << L"�Է� : ";//'t'�� �ԷµǱ� �������� ��� �ݺ��ؾ� �ϹǷ�
				std::getline(std::wcin, a);
				std::cout << std::endl;
				print.printdash();
			}
			else if (a.at(0) == 't') {//���� ����
				textEditor::editorFactory(a)->action();//'t'�� �ԷµǸ� ���Ͽ� �����ϰ� texteditor����
				break;//while���� �������´�.
			}
			else {
				//������ �Է��϶��� ���������� ����ϰ� �ٽ� �Է��ϵ��� �Ѵ�.
				print.printdefault();
				std::wcout << L"���������� ���� �Է��Դϴ�. �ٽ� �Է��ϼ���" << std::endl;
				print.printdash();
				std::wcout << L"�Է� : ";
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

	fileRead fileread; //fileRead��ü�� �����ϰ�, ������ �а� �� ���� �����Ѵ�.
	fileread.fileopen();
	fileread.save();
	Print printPage;//ù��° �������� ����Ѵ�.
	printPage.printPage(0);
	printPage.consoleMessage();
	
	userInput userinput;//userInput��ü�� �����ϰ� text editor�� �����Ѵ�.
	userinput.input();
	return 0;
}