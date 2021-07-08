#include <iostream>
#include <string>

using namespace std;
 
int capacity = 10;
int array[10] = {};
int top = -1;

int Size(){return top + 1;}

bool IsEmpty(){return Size() == 0;}

int Element(){
	if(IsEmpty()) cout << "Bag is empty" << endl;
	else return array[0];
}

void AllElement(){
    if(IsEmpty()) cout << "Bag is empty" << endl;
	else{
		for(int i = 0;i < top + 1;i++){
			cout << array[i] << "  ";	
		}
		cout << endl;
	}
}

void Push(int x){
	if(capacity == top + 1) cout << "Bag is full" << endl;
	else	array[++top] = x;
}

void Pop(){
    if(IsEmpty()) cout << "Bag is empty, cannot delete" << endl;
	else{
		int deletePos = top/2;
		copy(array + deletePos + 1,array + top + 1,array + deletePos);  //compact array¨Ï°}¦Cºò´ê 
		top--;
	}
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
		else if(enter == "element") cout << Element() << endl;
		AllElement();
		cin >> enter;	
	}	
	return 0; 
}
