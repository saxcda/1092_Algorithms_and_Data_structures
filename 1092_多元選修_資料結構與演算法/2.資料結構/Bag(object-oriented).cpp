#include <iostream>
#include <string>

using namespace std;

//Definition of the class Bag containing integers
class Bag{
public:
	Bag(int bagCapacity = 10);//constructor
	~Bag();                   //destructor
	
	int Size() const;         //return number of elements in bag
	bool IsEmpty()const;      //return true if the bag is empty;false otherwise
	int Element()const;       //return an element that is in the bag
	
	void AllElement()const;    //return all elements that are in the bag
	
	void Push(const int);     //insert an integer into the bag
	void Pop();               //delete an integer from the bag

private:
	int *array;
	int capacity;             //capacity of array
	int top;                  //array position of top element
};
	//Implementation of operations of Bag Bag運算的實作 
	
Bag::Bag(int bagCapacity):capacity(bagCapacity){
	try{
		if(capacity < 1)throw"Capacity must be < 0";
		array = new int[capacity]{};
		top = -1;	
	}
	catch (const char* message) {
        cout << message << endl;
    }
}

Bag::~Bag(){ delete[]array; }

inline int Bag::Size()const{return top + 1;}

inline bool Bag::IsEmpty()const{return Size() == 0;}

inline int Bag::Element()const{
	try{
		if(IsEmpty()) throw "Bag is empty";
		return array[0];
	}
	catch (const char* message) {
        cout << message << endl;
    }
	
}

inline void Bag::AllElement()const{
	try{
		if(IsEmpty()) throw "Bag is empty";
		for(int i = 0;i < top + 1;i++){
			cout << array[i] << "  ";	
		}
		cout << endl;
	}
	catch (const char* message) {
        cout << message << endl;
    }
}

void Bag::Push(const int x){
	if(capacity == top + 1){
		int* temp = new int[capacity*2];
		copy(array,array + capacity,temp);
		delete[] array;
		array = temp;
		capacity = capacity * 2;
	}
	array[++top] = x;
}

void Bag::Pop(){
	try{
		if(IsEmpty()) throw "Bag is empty, cannot delete";
		int deletePos = top/2;
		copy(array + deletePos + 1,array + top + 1,array + deletePos);  //compact array使陣列緊湊 
		top--;
	}
	catch (const char* message) {
		cout << message << endl;
	}
}

int main(){
	Bag hello;
	string enter;
	cin >> enter;
	int x;
	while(enter != "bye"){
		if(enter == "push"){
			cin >> x;
			hello.Push(x);
		}
		else if(enter == "pop") hello.Pop();
		else if(enter == "size") cout << hello.Size() << endl;
		else if(enter == "isempty") cout << hello.IsEmpty() << endl;
		else if(enter == "element") cout << hello.Element() << endl;
		hello.AllElement();
		cin >> enter;	
	}	
	return 0; 
}
