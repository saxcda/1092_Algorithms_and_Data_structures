#include <iostream>

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
 
int maze[14][14] = {
/* 
你要自己宣告迷宮 
*/ 
};
int mark[14][14] = {};

void Path(int m, int p){
	int i, j, d, g, h;
	Items temp;
	
	//path starts at (1,1) and direction E(i.e. east) 
	mark[1][1] = 1;
	
	Stack<Items> stack(m*p);
	
	temp.x = 1;
	temp.y = 1;
	temp.dir = E;
	stack.Push(temp);
	
	while(!stack.IsEmpty()){
		/*
		這裡你要自己完成 
		*/ 
	}
	cout << "No path in maze." << endl;	
}

int main(){
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
	
	Path(m,p);
	
	return 0;	
}




