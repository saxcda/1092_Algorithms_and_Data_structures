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
	cout<<"�п�J�ǥͤH��:";
	cin>>student_num;
	
	for(int i=0;i<student_num;i++){
		cout<<"�п�J�� "<<i+1<<" �Ӿǥͪ��m�W"<<endl;
		cin>>student[i].name;
		cout<<"�п�J�� "<<i+1<<" �Ӿǥͪ�����"<<endl;
		cin>>student[i].score;
	}

	sort(student, student+student_num, cmp);
	cout<<setw(n)<<"�m�W"<<setw(n)<<"����"<<endl; 
	for(int i=0;i<student_num;i++){
	 	cout<<setw(n)<<student[i].name<<setw(n)<<student[i].score<<endl;
	}
	return 0;
}
