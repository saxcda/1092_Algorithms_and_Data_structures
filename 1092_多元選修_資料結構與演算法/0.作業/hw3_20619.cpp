#include<iostream>
#include <iomanip>//只用了setw()調整輸出格式 
using namespace std;

struct Student{
	char name[20];
	int score;
};

void Bubble_Sort(Student *, int);

int main(){
	struct Student student[100];
	int student_num, n = 10;
	cout<<"請輸入學生人數:";
	cin>>student_num;
	
	for(int i=0;i<student_num;i++){
		cout<<"請輸入第 "<<i+1<<" 個學生的姓名"<<endl;
		cin>>student[i].name;
		cout<<"請輸入第 "<<i+1<<" 個學生的分數"<<endl;
		cin>>student[i].score;
	}

	Bubble_Sort(&student[0], student_num);
	
	cout<<setw(n)<<"姓名"<<setw(n)<<"分數"<<endl; 
	for(int i=0;i<student_num;i++){
	 	cout<<setw(n)<<student[i].name<<setw(n)<<student[i].score<<endl;
	}
	return 0;
}

void Bubble_Sort(Student *s, int s_num){
    Student tmp;

    for(int i = 0; i < s_num; i++){
        for(int j = 0; j < s_num-i-1; j++){
            if((s+j) -> score < (s+j+1) -> score){
                tmp = *(s+j);
                *(s+j) = *(s+j+1);
                *(s+j+1) = tmp;
            }
        }
    }
}
