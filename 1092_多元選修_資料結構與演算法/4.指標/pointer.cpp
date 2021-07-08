#include<iostream>

using namespace std;

//傳值的函式 
void swap1(int x, int y){
	int s;
	s = x;
	x = y;
	y = s;
}

//傳址的函式 
void swap2(int *x,int *y){
	int s;
	s = *x;
	*x = *y;
	*y = s;
}

//傳址的函數2 
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
	
	//*ptr 表它指向的變數的值 
	cout << *ptr << endl;
	//ptr 表 ptr 這個變數的值，而它的值是一個記憶體位址 
	cout << ptr << endl;
	//&ptr 表 ptr 這個變數自己所在的記憶體位址 
	cout << &ptr << endl;
	ptr = &b;
	//*ptr 表它指向的變數的值 
	cout << *ptr << endl;
	//ptr 表 ptr 這個變數的值，而它的值是一個記憶體位址 
	cout << ptr << endl;
	//&ptr 表 ptr 這個變數自己所在的記憶體位址 
	cout << &ptr << endl;
	
	//指標可以改變所指的變數 
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
