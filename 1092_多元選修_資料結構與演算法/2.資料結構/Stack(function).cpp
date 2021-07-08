#include <iostream>
#include <string>

using namespace std;
 
int capacity = 10;
int array[10] = {};
int top = -1;

int Size(){return top + 1;}

bool IsEmpty(){return Size() == 0;}

void AllElement(){
    if(IsEmpty()) cout << "Stack is empty" << endl;
	else{
		for(int i = 0;i < top + 1;i++){
			cout << array[i] << "  ";	
		}
		cout << endl;
	}
}

void Push(int x){
	if(capacity == top + 1) cout << "Stack is full" << endl;
	else	array[++top] = x;
}

void Pop(){
    if(IsEmpty()) cout << "Stack is empty, cannot delete" << endl;
	else	top--;
}

int main(){
	string enter;
	cin >> enter;
	int x;
	while(enter != "bye"){
		if(enter == "push"){
			cin >> x;
			Push(x);
		}
		else if(enter == "pop") Pop();
		else if(enter == "size") cout << Size() << endl;
		else if(enter == "isempty") cout << IsEmpty() << endl;
		AllElement();
		cin >> enter;	
	}	
	return 0; 
}
