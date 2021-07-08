#include <iostream>
#include <string>

using namespace std;

//Definition of template class Bag 
template<class T>
class Bag{
public:
	Bag(int bagCapacity = 10);//constructor
	~Bag();                   //destructor
	
	int Size() const;         //return number of elements in bag
	bool IsEmpty()const;      //return true if the bag is empty;false otherwise
	T& Element()const;       //return an element that is in the bag
	
	void AllElement()const;    //return all elements that are in the bag
	
	void Push(const T&);     //insert an integer into the bag
	void Pop();               //delete an integer from the bag

private:
	T *array;
	int capacity;             //capacity of array
	int top;                  //array position of top element
};
	//Implementation of operations of Bag Bag運算的實作 

template<class T>
Bag<T>::Bag(int bagCapacity):capacity(bagCapacity){
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
Bag<T>::~Bag(){ delete[]array; }

template<class T>
inline int Bag<T>::Size()const{return top + 1;}

template<class T>
inline bool Bag<T>::IsEmpty()const{return Size() == 0;}

template<class T>
inline T& Bag<T>::Element()const{
	try{
		if(IsEmpty()) throw "Bag is empty";
		return array[0];
	}
	catch (const char* message) {
        cout << message << endl;
    }
	
}

template<class T>
inline void Bag<T>::AllElement()const{
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

template<class T>
void Bag<T>::Push(const T& x){
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
void Bag<T>::Pop(){
	try{
		if(IsEmpty()) throw "Bag is empty, cannot delete";
		int deletePos = top/2;
		copy(array + deletePos + 1,array + top + 1,array + deletePos);  //compact array使陣列緊湊 
		array[top--].~T();
	}
	catch (const char* message) {
		cout << message << endl;
	}
}

int main(){
	Bag<int> hello;
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
