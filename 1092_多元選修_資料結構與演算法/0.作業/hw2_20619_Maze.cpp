#include <iostream>
#include <iomanip>//只有用到setw()排版 
using namespace std;
 
struct Items{
	int x, y, dir;	
};
struct offsets{
 	int a, b;
};
enum directions{N, NE, E, SE, S, SW, W, NW};
offsets move[8];
int m = 12,p = 12;

template<class T>
class Stack{
public:
	Stack(int bagCapacity = 1000);//constructor
	~Stack();                   //destructor
	
	friend void Path(int ,int );
	template<class U>
	friend ostream &operator<<(ostream &, Stack<U> &);
	
	int Size();         
	bool IsEmpty();      
	T& Top();	
	void Push(T&);     
	void Pop();               
private:
	T *array;
	int capacity;             
	int top;
}; 

template<class T>
Stack<T>::Stack(int bagCapacity):capacity(bagCapacity){
	try{
		if(capacity < 1)throw"Capacity must be < 0";
		array = new T[capacity]{};
		top = -1;	
	}
	catch (const char* message) {
        cout << message << endl;
    }
}

template<class T>
Stack<T>::~Stack(){ delete[]array; }

template<class T>
inline int Stack<T>::Size(){return top + 1;}

template<class T>
inline bool Stack<T>::IsEmpty(){return Size() == 0;}

template<class T>
inline T& Stack<T>::Top(){
	try{
		if(IsEmpty()) throw "Stack is empty";
		return array[top];
	}
	catch (const char* message) {
        cout << message << endl;
    }
} 

template<class T>
void Stack<T>::Push(T& x){
	if(capacity == top + 1){
		T* temp = new T[capacity*2];
		copy(array,array + capacity,temp);
		delete[] array;
		array = temp;
		capacity = capacity * 2;
	}
	array[++top] = x;
}

template<class T>
void Stack<T>::Pop(){
	try{
		if(IsEmpty()) throw "Stack is empty, cannot delete";
		array[top--].~T();
	}
	catch (const char* message) {
		cout << message << endl;
	}
}

template<class T>
ostream &operator<<(ostream &os, Stack<T> &s){
	for(int i = 0 ; i <= s.top ; i++){
		os << i << ":" << s.array[i] << endl;
	};
	return os;
}
ostream &operator<<(ostream &os, Items& item){
	return os << item.x << "," << item.y << "," << item.dir;
}
 
int maze[1001][1001] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
{1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1},
{1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
{1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
{1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1},
{1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1},
{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};



int mark[1001][1001] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};


void Path(int m, int p){
	int i, j, d, g, h, x, y, dir = 0, nextx, nexty, count = 0;
	Items temp;
	bool found;
		
	Stack<Items> stack(m*p), stack2(m*p);
	temp.x = 1;
	temp.y = 1;
	temp.dir = 0;
	mark[1][1] = 1;
	stack.Push(temp);
	
	
	
	while(!stack.IsEmpty()){
		temp = stack.Top();
		stack.Pop();
		x = temp.x;  
		y = temp.y;   
		dir = temp.dir;
		
		while(dir < 8 && !found){
			nextx = x + move[dir].a;
			nexty = y + move[dir].b;
			 
			if(nextx == m && nexty == p){
				found = 1;
				temp.dir = dir;
				stack.Push(temp);
				
				temp.x = nextx;
				temp.y = nexty;
				temp.dir = -1;
				stack.Push(temp);
				break;
			}else if(!maze[nextx][nexty] && !mark[nextx][nexty]){
				mark[nextx][nexty] = 1;
				temp.x = x;
				temp.y = y;
				temp.dir = dir++;
				stack.Push(temp);
				x = nextx;
				y = nexty;
				dir = 0;
			}else{
				dir++;
			}
		}
		
		if(found){
			cout<<"Have path !"<<endl;
			while(!stack.IsEmpty()){
				temp = stack.Top();
				stack2.Push(temp);
				stack.Pop();
			}
			while(!stack2.IsEmpty()){
				temp = stack2.Top();
				cout<<setw(4)<<count<<":("<<setw(3)<<temp.x<<","<<setw(3)<<temp.y<<")"<<setw(2)<<temp.dir<<endl;
				stack2.Pop();
				count++;
			}
			cout<<"Arrived !";
			break;
		}
	}

	if(not found)
		cout << "No path in maze." << endl;	
}

int main(){
	int mwidth = 1, mlong = 1;
	bool use_org = 1;
	move[0].a = -1;
	move[0].b = 0;
	move[1].a = -1;
	move[1].b = 1;
	move[2].a = 0;
	move[2].b = 1;
	move[3].a = 1;
	move[3].b = 1;
	move[4].a = 1;
	move[4].b = 0;
	move[5].a = 1;
	move[5].b = -1;
	move[6].a = 0;
	move[6].b = -1;
	move[7].a = -1;
	move[7].b = -1;
	
	cout<<"請選擇使用原題預設迷宮或是自定義迷宮, 使用原題請輸入1, 自定義請輸入0 : ";
	cin>>use_org;
	
	
	if(!use_org){
		while(mwidth == 1 and mlong == 1){ 
			cout<<"請輸入迷宮寬 : ";
			cin>>mwidth; 
			cout<<"請輸入迷宮長 : ";
			cin>>mlong;
			if(mwidth == 1 and mlong == 1)
				cout<<"輸入的長寬皆為 1，請重新輸入"<<endl; 
		}
		
		for(int i = 1; i<= mwidth; i++){//使用者初始化 
				for(int j = 1; j<= mlong; j++){
					cout<<"請設置第 "<<i<<" , "<<j<<" 格障礙物 (若有障礙物請輸入 1，無則輸入 0)";
					cin>>maze[i][j];
					if(i == 1 and j == 1 and maze[1][1] == 1){
						cout<<"輸入錯誤，入口不可設置障礙物"<<endl<<"入口預設無障礙物"<<endl;
						maze[1][1] = 0; 
					}else if(i == mwidth and j == mlong and maze[mwidth][mlong] == 1){
						cout<<"輸入錯誤，出口不可設置障礙物"<<endl<<"出口預設無障礙物"<<endl;
						maze[mwidth][mlong] = 0; 
					}
				}
			} 
			cout<<endl;
			
			for(int i = 0; i<= mwidth+1; i++){//設置圍牆 
				for(int j = 0; j<= mlong+1; j++){
					if(i == 0 or j == 0 or i == mwidth+1 or j == mlong+1){
						mark[i][j] = 1;
						maze[i][j] = 1;
					}
				}
			}
	}else{
		mwidth = 12;
		mlong = 12;
	}
	
	Path(mwidth,mlong);
	
	return 0;	
}

