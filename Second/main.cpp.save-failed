#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <windows.h>
using namespace std;

// 全局变量
int student_Total_Num = 0;   // 记录学生总人数

/*
** sco[i][0] 存储课程号
** sco[i][1] 存储课程成绩
** sco[7][0] 存储平均成绩
** sco[7][1] 存储成绩排名
*/
class stu_cou {
public:
    int stu_Num;
    int sco[7][2];
};
stu_cou sc[101];  // 学生-课程关系的二维数组来存储学生考试成绩

class student {
public:
    // 构造函数
    student(int nu = 0):Number(nu){}

    // 析构函数
    ~student(){}

    // 初始化
    void set_Info();

    // 输入某一门课课程号， 返回该课程的成绩
    float get_Score(int course_Num) {
        int i = 0;
        for(i = 0; i < 6; i++) {
            if(score[i][0] == course_Num)
                return score[i][1];
        }
        printf("The score of %d is: %d\n", course_Num, score[i][1]);
        return -1;
    }

    // 统计个人各门课程平均成绩
    float average_Score() {
        unsigned int sum = 0; // 总成绩
        for(int i = 0; i < 6; i++)
            sum += score[i][1];
        float aver_score = sum / 6;
        printf("The average score is: %.2f\n", aver_score); // 保留两位小数
        return aver_score;
    }

private:
    int  Number;       // 学号
	string Name;       // 学生名
	char Sex;          // F / M
	int  Grade;        // 年级
	int  Clas;        // 班级
    string Birth;      // 生日
	string Dorm;       // dormitory
	string Address;    // 宿舍地址
	int score[6][2];   // 第一维度是课程号，第二维度是成绩， 若为 -1 则表时没选该课
};

// sc[7][0] 存储平均成绩
void student::set_Info() {
    cout << "输入学号" << endl; cin >> Number;
	cout << "输入姓名" << endl; cin >> Name;
	cout << "输入性别" << endl; cin >> Sex;
	cout << "输入年级" << endl; cin >> Grade;
	cout << "输入班级" << endl; cin >> Clas;
	cout << "输入生日" << endl; cin >> Birth;
	cout << "输入宿舍" << endl; cin >> Dorm;
	cout << "输入籍贯" << endl; cin >> Address;

	// 输入成绩
	for(int i = 0; i < 6; i++) {
        cout << "输入第 " << i+1 << " 门课程的课程号：" << endl;
        cin >> score[i][0];
        sc[student_Total_Num - 1].sco[i][0] = score[i][0];
        cout << "输入该课程的成绩：" << endl;
        cin >> score[i][1];
        sc[student_Total_Num - 1].sco[i][1] = score[i][0];
	}
}

class course {
public:
    // 构造函数
    course(int nu = 0): Number(nu){}

    // 析构函数
    ~course() {}
    // 统计课程平均成绩
    void average_Score();

    // 统输出计课程不及格的学生
    void show_Poor_Student();
private:
    int  Number;       // 课程号
	char Name[20];     // 课程名
	char tescher_Name[20]; // 授课老师名字
};

void course::average_Score() {
    int cn;
    float ave_Cou = 0;
    cout << "输入要查看的平均成绩的课程号：" << endl;
    cin >> cn;
    for(int i = 0; i < student_Total_Num; i++) {
        for(int j = 0; j < 6; j++) {
            if(sc[i].sco[j][0] == cn) {
                ave_Cou += sc[i].sco[j][1];
            }
        }
    }
    ave_Cou /= 6;
    cout << "该课程平均成绩为：" << ave_Cou << endl;
}

void course::show_Poor_Student() {
    int cn;
    cout << "输入要查看的不及格学生的课程号：" << endl;
    cin >> cn;
    for(int i = 0; i < student_Total_Num; i++) {
        for(int j = 0; j < 6; j++) {
            if(sc[i].sco[j][0] == cn && sc[i].sco[j][1] < 60) {
                cout << "学号为: " << sc[i].stu_Num << " 的学生该门课程不及格" << endl;
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
void Menu();      // 菜单

void Add() {
	cout << "请输入要插入的信息" << endl;
	student tmp;
	tmp.set_Info();
    sc[student_Total_Num].sco[7][0] = tmp.average_Score();
    student_Total_Num++;
	cout << "增加成功" << endl;
	cout << "student_Total_Num = " << student_Total_Num << endl;
	Menu();
}

void Search() {
    cout << "请输入要查找的学生学号: ";
	int Search_Number;
	cin >> Search_Number;
	cout << "Search_Number is " << Search_Number << endl;
	for(int i = 0; i < student_Total_Num; i++) {
        if(sc[i].stu_Num == Search_Number) {
            cout << "该学生成绩如下：\n";
            for(int j  = 0; j < 6; j++) {
                cout << "课程号：" << sc[i].sco[j][0] << " 的成绩为：" << sc[i].sco[j][1] << endl;
            }
            Menu();
            return;
        }
	}
	cout << "要查找的学生学号不存在" << endl;
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
	cout << "请输入要删除的学生学号" << endl;
	int delete_Num;
	cin >> delete_Num;
	bool flag = Exist(delete_Num);
	if(flag) {
        student_Total_Num--;
        cout << "student_Total_Num = " << student_Total_Num << endl;
        cout << "Delete successfully" << endl;
        Menu();
	}
	cout << "要删除的学生学号不存在" << endl;
	Menu();
}


bool cmp(const stu_cou &a, const stu_cou &b) {
    return a.stu_Num < b.stu_Num;
}
void Sort() {
    sort(sc, sc + student_Total_Num, cmp);
    for(int i = 0; i < student_Total_Num; i++) {
        cout << "学号为：" << sc[i].stu_Num << " 的学生成绩如下：" << endl;
        for(int j  = 0; j < 6; j++) {
            cout << "课程号：" << sc[i].sco[j][0] << " 的成绩为：" << sc[i].sco[j][1] << endl;
        }
    }
}

void Average() {
    int ave_Num;
    cout << "输入要查找平均成绩的学生学号：" << endl;
    cin >> ave_Num;
    for(int i = 0; i < student_Total_Num; i++) {
        if(sc[i].stu_Num == ave_Num) {
            cout << "平均成绩为：" << sc[i].sco[7][0] << endl;
            return;
        }
	}
	cout << "该生并不存在" << endl;
}

void Poor_student() {
    int poor_Cou;
    cout << "输入要查看的不及格学生的课程号：" << endl;
    cin >> poor_Cou;
}

Menu_error() {     // 错误处理
    cout << "Input operation error" << endl;
    Menu();
}
void Menu() {
	int Button_num;  // 输入数字选择操作
	cout << "当前已经记录的学生人数为：" << student_Total_Num << endl;
	cout << "输入数字选择功能" << endl;
	cout << "1: 增加\n" << "2: 搜寻" << endl;
	cout << "3: 删除\n" << "4: 排序" << endl;
    cout << "5: 查看平均成绩" << endl;
    cout << "6: 查看不及格学生" << endl;
	cout << "7: 返回菜单" << endl;
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
