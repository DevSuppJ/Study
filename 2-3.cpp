#include <iostream>
using namespace std;
#define StudentScale 10 // 프로그램에서 저장할 학생수
#define NameLen 30 // 이름 문자열의 길이
#define StuNumLen 20 // 학번 문자열의 길이



/* 2 - 3 program 작성 및 실행
1. 학번과 영문 이름을 키보드로 입력 받아 화면에 출력하라.
2. 1번 스텝을 반복(while문)하면서, 매번 입력을 계속할지를 묻고 yes 면 다음 학생, no 면 프로그램을 종료하라. */


// 학생 정보를 담을 형식 지정
class student {
private:
	char* name;
	char* stuNum;
public:
	student(); // 디폴트 생성자 (배열 선언을 위함)
	//student(const student& stuIns); // 임시 복사 생성자
	~student() { delete name; delete stuNum; } // 소멸자
	void PutStudentInfo(char* putName, char* putStuNum) { name = putName; stuNum = putStuNum; } // 설정자 (입력)
	void ShowStudentInfo() { cout << "이름 : " << name << endl << "학번 : " << stuNum << endl; } // 접근자 (출력)
};

// 디폴트 생성자
student::student() {
	char* name = new char[NameLen];
	char* stuNum = new char[StuNumLen];
	student::name = NULL;
	student::stuNum = NULL;
}

/*
// 복사 생성자 (깊은 복사)
student::student(const student& stuIns) {
	char* name = new char[NameLen];
	char* stuNum = new char[StuNumLen];
	strcpy(name, stuIns.name);
	strcpy(stuNum, stuIns.stuNum);
} */

// 이름 입력함수
char* GetName() {
	char* getName = new char[NameLen];
	cout << "학생의 이릅을 입력하세요 : ";
	cin >> getName;
	return getName;
}

// 학번 입력함수
char* GetStuNum() {
	char* getStuNum = new char[StuNumLen];
	cout << "학생의 학번을 입력하세요 : ";
	cin >> getStuNum;
	return getStuNum;
}


int main() {
	student* studentArr = new student[StudentScale]; // 학생들의 정보를 담을 배열
	char* breakLoop = new char[5]; // 루프를 빠져나오기위한 문자열
	int arrNum = 0; // 몇번 째 학생인지 저장할 정수

	// breakLoop가 no가 아니고 배열의 숫자가 저장 가능한 학생 수를 초과하지 않은경우 반복
	while (arrNum < StudentScale) {
		studentArr[arrNum].PutStudentInfo(GetName(), GetStuNum());
		arrNum++;

		cout << "계속하시겠습니까? yes or no 입력 : ";
		cin >> breakLoop;

		// 사용자가 no를 입력할경우 루프 종료
		if (strcmp(breakLoop, "no") == 0) break;
	}

	// 루프가 끝난경우 결과 보여주기
	for (int i = 0; i < arrNum; i++) studentArr[i].ShowStudentInfo();

	// 할당된 동적 메모리 비우기
	delete[]studentArr;
	delete breakLoop;

	return 0;
}