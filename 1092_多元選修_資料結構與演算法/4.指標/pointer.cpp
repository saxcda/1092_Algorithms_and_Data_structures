#include<iostream>

using namespace std;

//�ǭȪ��禡 
void swap1(int x, int y){
	int s;
	s = x;
	x = y;
	y = s;
}

//�ǧ}���禡 
void swap2(int *x,int *y){
	int s;
	s = *x;
	*x = *y;
	*y = s;
}

//�ǧ}�����2 
void swap3(int &x,int &y){
	int s;
	s = x;
	x = y;
	y = s;
}

int main(){
	int a = 5, b = 3;
	int *ptr;
	ptr = &a;
	
	//*ptr �����V���ܼƪ��� 
	cout << *ptr << endl;
	//ptr �� ptr �o���ܼƪ��ȡA�ӥ����ȬO�@�ӰO�����} 
	cout << ptr << endl;
	//&ptr �� ptr �o���ܼƦۤv�Ҧb���O�����} 
	cout << &ptr << endl;
	ptr = &b;
	//*ptr �����V���ܼƪ��� 
	cout << *ptr << endl;
	//ptr �� ptr �o���ܼƪ��ȡA�ӥ����ȬO�@�ӰO�����} 
	cout << ptr << endl;
	//&ptr �� ptr �o���ܼƦۤv�Ҧb���O�����} 
	cout << &ptr << endl;
	
	//���Хi�H���ܩҫ����ܼ� 
	*ptr = 10; 
	cout << b << endl;
	
	swap1(a,b);
	cout << "After swap1:" << a << " " << b << endl;
	swap2(&a,&b);
	cout << "After swap2:" << a << " " << b << endl;
	swap3(a,b);
	cout << "After swap3:" << a << " " << b << endl;
		
	
	return 0;
}
