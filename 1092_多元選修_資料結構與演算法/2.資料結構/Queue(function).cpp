#include <iostream>
#include <string>

using namespace std;
 
int capacity = 10;
int array[10] = {};
int front = 0,rear = 0;

bool IsEmpty(){return front == rear;}

int Front(){
	if(IsEmpty()) cout << "Queue is empty.No front element" << endl;
	else return array[(front + 1)%capacity];
}

int Rear(){
	if(IsEmpty()) cout << "Queue is empty.No rear element" << endl;
	else return array[rear];
}

void AllElement(){
    if(IsEmpty()) cout << "Queue is empty" << endl;
	else{
		if((front + 1)%capacity <= rear){
			for(int i = (front + 1)%capacity;i < rear + 1;i++){
					cout << array[i] << "  ";	
			}
		}
		else{
			for(int i = (front + 1)%capacity;i < capacity ;i++){
				cout << array[i] << "  ";	
			}
			for(int j = 0;j <= rear;j++){
				cout << array[j] << "  ";
			}
		}
		cout << endl;
	}
}

void Push(int x){
	rear = (rear + 1)%capacity;
	array[rear] = x;	
}

void Pop(){
    if(IsEmpty()) cout << "Queue is empty, cannot delete" << endl;
	else	front = (front + 1)%capacity;
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
		else if(enter == "front") cout << Front() << endl;
		else if(enter == "rear") cout << Rear() << endl;
		else if(enter == "isempty") cout << IsEmpty() << endl;
		AllElement();
		cin >> enter;	
	}	
	return 0; 
}
