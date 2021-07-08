#include<iostream>
#include <iomanip>
#include<algorithm>
using namespace std;
struct Student{
	char name[20];
	int score;
};

bool cmp(Student a, Student b){
	return a.score > b.score;
}
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

	sort(student, student+student_num, cmp);
	cout<<setw(n)<<"姓名"<<setw(n)<<"分數"<<endl; 
	for(int i=0;i<student_num;i++){
	 	cout<<setw(n)<<student[i].name<<setw(n)<<student[i].score<<endl;
	}
	return 0;
}
