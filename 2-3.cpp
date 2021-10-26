#include <iostream>
using namespace std;
#define StudentScale 10 // ���α׷����� ������ �л���
#define NameLen 30 // �̸� ���ڿ��� ����
#define StuNumLen 20 // �й� ���ڿ��� ����



/* 2 - 3 program �ۼ� �� ����
1. �й��� ���� �̸��� Ű����� �Է� �޾� ȭ�鿡 ����϶�.
2. 1�� ������ �ݺ�(while��)�ϸ鼭, �Ź� �Է��� ��������� ���� yes �� ���� �л�, no �� ���α׷��� �����϶�. */


// �л� ������ ���� ���� ����
class student {
private:
	char* name;
	char* stuNum;
public:
	student(); // ����Ʈ ������ (�迭 ������ ����)
	//student(const student& stuIns); // �ӽ� ���� ������
	~student() { delete name; delete stuNum; } // �Ҹ���
	void PutStudentInfo(char* putName, char* putStuNum) { name = putName; stuNum = putStuNum; } // ������ (�Է�)
	void ShowStudentInfo() { cout << "�̸� : " << name << endl << "�й� : " << stuNum << endl; } // ������ (���)
};

// ����Ʈ ������
student::student() {
	char* name = new char[NameLen];
	char* stuNum = new char[StuNumLen];
	student::name = NULL;
	student::stuNum = NULL;
}

/*
// ���� ������ (���� ����)
student::student(const student& stuIns) {
	char* name = new char[NameLen];
	char* stuNum = new char[StuNumLen];
	strcpy(name, stuIns.name);
	strcpy(stuNum, stuIns.stuNum);
} */

// �̸� �Է��Լ�
char* GetName() {
	char* getName = new char[NameLen];
	cout << "�л��� �̸��� �Է��ϼ��� : ";
	cin >> getName;
	return getName;
}

// �й� �Է��Լ�
char* GetStuNum() {
	char* getStuNum = new char[StuNumLen];
	cout << "�л��� �й��� �Է��ϼ��� : ";
	cin >> getStuNum;
	return getStuNum;
}


int main() {
	student* studentArr = new student[StudentScale]; // �л����� ������ ���� �迭
	char* breakLoop = new char[5]; // ������ �������������� ���ڿ�
	int arrNum = 0; // ��� ° �л����� ������ ����

	// breakLoop�� no�� �ƴϰ� �迭�� ���ڰ� ���� ������ �л� ���� �ʰ����� ������� �ݺ�
	while (arrNum < StudentScale) {
		studentArr[arrNum].PutStudentInfo(GetName(), GetStuNum());
		arrNum++;

		cout << "����Ͻðڽ��ϱ�? yes or no �Է� : ";
		cin >> breakLoop;

		// ����ڰ� no�� �Է��Ұ�� ���� ����
		if (strcmp(breakLoop, "no") == 0) break;
	}

	// ������ ������� ��� �����ֱ�
	for (int i = 0; i < arrNum; i++) studentArr[i].ShowStudentInfo();

	// �Ҵ�� ���� �޸� ����
	delete[]studentArr;
	delete breakLoop;

	return 0;
}