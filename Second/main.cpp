#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <windows.h>
using namespace std;

// ȫ�ֱ���
int student_Total_Num = 0;   // ��¼ѧ��������

/*
** sco[i][0] �洢�γ̺�
** sco[i][1] �洢�γ̳ɼ�
** sco[7][0] �洢ƽ���ɼ�
** sco[7][1] �洢�ɼ�����
*/
class stu_cou {
public:
    int stu_Num;
    int sco[7][2];
};
stu_cou sc[101];  // ѧ��-�γ̹�ϵ�Ķ�ά�������洢ѧ�����Գɼ�

class student {
public:
    // ���캯��
    student(int nu = 0):Number(nu){}

    // ��������
    ~student(){}

    // ��ʼ��
    void set_Info();

    // ����ĳһ�ſογ̺ţ� ���ظÿγ̵ĳɼ�
    float get_Score(int course_Num) {
        int i = 0;
        for(i = 0; i < 6; i++) {
            if(score[i][0] == course_Num)
                return score[i][1];
        }
        printf("The score of %d is: %d\n", course_Num, score[i][1]);
        return -1;
    }

    // ͳ�Ƹ��˸��ſγ�ƽ���ɼ�
    float average_Score() {
        unsigned int sum = 0; // �ܳɼ�
        for(int i = 0; i < 6; i++)
            sum += score[i][1];
        float aver_score = sum / 6;
        printf("The average score is: %.2f\n", aver_score); // ������λС��
        return aver_score;
    }

private:
    int  Number;       // ѧ��
	string Name;       // ѧ����
	char Sex;          // F / M
	int  Grade;        // �꼶
	int  Clas;        // �༶
    string Birth;      // ����
	string Dorm;       // dormitory
	string Address;    // �����ַ
	int score[6][2];   // ��һά���ǿγ̺ţ��ڶ�ά���ǳɼ��� ��Ϊ -1 ���ʱûѡ�ÿ�
};

// sc[7][0] �洢ƽ���ɼ�
void student::set_Info() {
    cout << "����ѧ��" << endl; cin >> Number;
	cout << "��������" << endl; cin >> Name;
	cout << "�����Ա�" << endl; cin >> Sex;
	cout << "�����꼶" << endl; cin >> Grade;
	cout << "����༶" << endl; cin >> Clas;
	cout << "��������" << endl; cin >> Birth;
	cout << "��������" << endl; cin >> Dorm;
	cout << "���뼮��" << endl; cin >> Address;

	// ����ɼ�
	for(int i = 0; i < 6; i++) {
        cout << "����� " << i+1 << " �ſγ̵Ŀγ̺ţ�" << endl;
        cin >> score[i][0];
        sc[student_Total_Num - 1].sco[i][0] = score[i][0];
        cout << "����ÿγ̵ĳɼ���" << endl;
        cin >> score[i][1];
        sc[student_Total_Num - 1].sco[i][1] = score[i][0];
	}
}

class course {
public:
    // ���캯��
    course(int nu = 0): Number(nu){}

    // ��������
    ~course() {}
    // ͳ�ƿγ�ƽ���ɼ�
    void average_Score();

    // ͳ����ƿγ̲������ѧ��
    void show_Poor_Student();
private:
    int  Number;       // �γ̺�
	char Name[20];     // �γ���
	char tescher_Name[20]; // �ڿ���ʦ����
};

void course::average_Score() {
    int cn;
    float ave_Cou = 0;
    cout << "����Ҫ�鿴��ƽ���ɼ��Ŀγ̺ţ�" << endl;
    cin >> cn;
    for(int i = 0; i < student_Total_Num; i++) {
        for(int j = 0; j < 6; j++) {
            if(sc[i].sco[j][0] == cn) {
                ave_Cou += sc[i].sco[j][1];
            }
        }
    }
    ave_Cou /= 6;
    cout << "�ÿγ�ƽ���ɼ�Ϊ��" << ave_Cou << endl;
}

void course::show_Poor_Student() {
    int cn;
    cout << "����Ҫ�鿴�Ĳ�����ѧ���Ŀγ̺ţ�" << endl;
    cin >> cn;
    for(int i = 0; i < student_Total_Num; i++) {
        for(int j = 0; j < 6; j++) {
            if(sc[i].sco[j][0] == cn && sc[i].sco[j][1] < 60) {
                cout << "ѧ��Ϊ: " << sc[i].stu_Num << " ��ѧ�����ſγ̲�����" << endl;
            }
        }
    }
}

void Add();
void Search();
void Delete();
void Sort();
void Average();
void Poor_student();
void Menu();      // �˵�

void Add() {
	cout << "������Ҫ�������Ϣ" << endl;
	student tmp;
	tmp.set_Info();
    sc[student_Total_Num].sco[7][0] = tmp.average_Score();
    student_Total_Num++;
	cout << "���ӳɹ�" << endl;
	cout << "student_Total_Num = " << student_Total_Num << endl;
	Menu();
}

void Search() {
    cout << "������Ҫ���ҵ�ѧ��ѧ��: ";
	int Search_Number;
	cin >> Search_Number;
	cout << "Search_Number is " << Search_Number << endl;
	for(int i = 0; i < student_Total_Num; i++) {
        if(sc[i].stu_Num == Search_Number) {
            cout << "��ѧ���ɼ����£�\n";
            for(int j  = 0; j < 6; j++) {
                cout << "�γ̺ţ�" << sc[i].sco[j][0] << " �ĳɼ�Ϊ��" << sc[i].sco[j][1] << endl;
            }
            Menu();
            return;
        }
	}
	cout << "Ҫ���ҵ�ѧ��ѧ�Ų�����" << endl;
	Menu();
}

bool Exist(int exi_Num) {
    bool res = false;
	for(int i = 0; i < student_Total_Num; i++) {
        if(sc[i].stu_Num == exi_Num)
            return true;
	}
	return res;
}
void Delete() {
	cout << "������Ҫɾ����ѧ��ѧ��" << endl;
	int delete_Num;
	cin >> delete_Num;
	bool flag = Exist(delete_Num);
	if(flag) {
        student_Total_Num--;
        cout << "student_Total_Num = " << student_Total_Num << endl;
        cout << "Delete successfully" << endl;
        Menu();
	}
	cout << "Ҫɾ����ѧ��ѧ�Ų�����" << endl;
	Menu();
}


bool cmp(const stu_cou &a, const stu_cou &b) {
    return a.stu_Num < b.stu_Num;
}
void Sort() {
    sort(sc, sc + student_Total_Num, cmp);
    for(int i = 0; i < student_Total_Num; i++) {
        cout << "ѧ��Ϊ��" << sc[i].stu_Num << " ��ѧ���ɼ����£�" << endl;
        for(int j  = 0; j < 6; j++) {
            cout << "�γ̺ţ�" << sc[i].sco[j][0] << " �ĳɼ�Ϊ��" << sc[i].sco[j][1] << endl;
        }
    }
}

void Average() {
    int ave_Num;
    cout << "����Ҫ����ƽ���ɼ���ѧ��ѧ�ţ�" << endl;
    cin >> ave_Num;
    for(int i = 0; i < student_Total_Num; i++) {
        if(sc[i].stu_Num == ave_Num) {
            cout << "ƽ���ɼ�Ϊ��" << sc[i].sco[7][0] << endl;
            return;
        }
	}
	cout << "������������" << endl;
}

void Poor_student() {
    int poor_Cou;
    cout << "����Ҫ�鿴�Ĳ�����ѧ���Ŀγ̺ţ�" << endl;
    cin >> poor_Cou;
}

Menu_error() {     // ������
    cout << "Input operation error" << endl;
    Menu();
}
void Menu() {
	int Button_num;  // ��������ѡ�����
	cout << "��ǰ�Ѿ���¼��ѧ������Ϊ��" << student_Total_Num << endl;
	cout << "��������ѡ����" << endl;
	cout << "1: ����\n" << "2: ��Ѱ" << endl;
	cout << "3: ɾ��\n" << "4: ����" << endl;
    cout << "5: �鿴ƽ���ɼ�" << endl;
    cout << "6: �鿴������ѧ��" << endl;
	cout << "7: ���ز˵�" << endl;
	cin >> Button_num;
	switch(Button_num) {
        case 1:  Add();
        case 2:  Search();
        case 3:  Delete();
        case 4:  Sort();
        case 5:  Average();
        case 6:  Poor_student();
        case 7:  Menu();
        default: Menu_error();
	}
}

int main() {
    Menu();
    return 0;
}
