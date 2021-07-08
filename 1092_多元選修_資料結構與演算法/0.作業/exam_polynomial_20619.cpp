#include<iostream>
using namespace std;

/*
struct Data{
	int power;
	int coefficient;
};

std::ostream& operator<< (std::ostream& stream, const Data& dt) {
	std::cout <<"( "<<dt.coefficient<<", "<<dt.power<<" )";
	return stream;
}
*/

class LinkedList;  
                 
class ListNode{
private:
    //Data data;
    int power;
    int coefficient;
    ListNode *next;
public:
    ListNode():coefficient(0),power(0),next(0){};
    ListNode(int a, int b):coefficient(a),power(b),next(0){};

    friend class LinkedList;
    //friend Data;
};

class LinkedList{
private:
    int size;              
    ListNode *first;      
public:
    LinkedList():first(0){};
    void PrintList(bool z);
    void Push_back(int x, int y);
    void Clear();
    LinkedList Addition_or_Subtraction(LinkedList x, LinkedList y, int w, bool z);
    //LinkedList Subtraction(LinkedList x, LinkedList y, bool z);
    LinkedList Multiplication(LinkedList x, LinkedList y, bool z);
    LinkedList Bubble_sort(LinkedList x);
    LinkedList Merge(LinkedList x);
};

void LinkedList::Clear(){
	ListNode *current = first;
	first = 0;
}

void LinkedList::PrintList(bool c){
	bool is_None = true, is_Output = false;
    if (first == 0) {
        cout << "List is empty."<<endl;
        return;
    }

    ListNode *current = first;
    
    while (current != 0){
    	if(!c){ 
	    	if(current->coefficient!=0) is_None = false;
	    	if(current->coefficient > 0 and current!=first and is_Output == true) cout<<"+";
	    	//if(current->coefficient == 0 and current!=first) cout<<"";
		    	if(current->coefficient != 0){
			    	if(current->power == 0){
						is_Output = true;
			    		cout<<current->coefficient;
			    		
					}else if(current->power != 1){
						is_Output = true;
						
						if(current->coefficient == 1)
							cout<<"x^"<<current->power;
						else if(current->coefficient == -1)
							cout<<"-x^"<<current->power;
						else
							cout <<current->coefficient <<"x^"<<current->power;
					}else if (current->power == 1){
						is_Output = true;
						if(current->coefficient == 1)
							cout<<"x";
						else if(current->coefficient == -1)
							cout<<"-x";
						else
							cout <<current->coefficient <<"x";
					}
				}
		}else{
			cout<<"("<<current->coefficient<<", "<<current->power<<")";
		}
        current = current->next;
    }
    
    if(is_None)
    	cout<<"0";
    //cout<<endl;
}

void LinkedList::Push_back(int x, int y){

    ListNode *newNode = new ListNode(x, y);

    if (first == 0) {
        first = newNode;
        return;
    }

    ListNode *current = first;
    while (current->next != 0) {
        current = current->next;
    }
    current->next = newNode;
    size++;
}

LinkedList LinkedList::Addition_or_Subtraction(LinkedList a, LinkedList b, int d, bool c){
	LinkedList tmp_list;
	//a.PrintList();
	//b.PrintList();
	ListNode *current1 = a.first, *current2 = b.first;

	//======================================================================
	
	while(current1!=0){
		//cout <<"("<<current1->coefficient <<", "<<current1->power<<")";
		tmp_list.Push_back(current1->coefficient, current1->power);
		current1 = current1->next;
	}

	while(current2!=0){
		//cout <<"("<<current2->coefficient <<", "<<current2->power<<")";
		if(d == 43)
			tmp_list.Push_back(current2->coefficient, current2->power);
		else if(d == 45)
			tmp_list.Push_back(-(current2->coefficient), current2->power);
		current2 = current2->next;
	}
	
	//======================================================================
	if(c){
		cout<<endl;
		if(d == 43)
			cout<<"Addition"<<endl;
		else if(d == 45)
			cout<<"Subtraction"<<endl;
			
		tmp_list.PrintList(c);
	}
	return tmp_list;
}

/*
LinkedList LinkedList::Subtraction(LinkedList a, LinkedList b, bool c){
	LinkedList tmp_list;
	//a.PrintList();
	//b.PrintList();
	ListNode *current1 = a.first, *current2 = b.first;

	//======================================================================
	
	while(current1!=(0, 0)){
		//cout <<"("<<current1->coefficient <<", "<<current1->power<<")";
		tmp_list.Push_back(current1->coefficient, current1->power);
		current1 = current1->next;
	}

	while(current2!=(0, 0)){
		//cout <<"("<<current2->coefficient <<", "<<current2->power<<")";
		tmp_list.Push_back(-(current2->coefficient), current2->power);
		current2 = current2->next;
	}
	
	//======================================================================
	if(c){
		cout<<endl;
		cout<<"Subtraction"<<endl;
		tmp_list.PrintList();
	}
	
	return tmp_list;
}
*/

LinkedList LinkedList::Multiplication(LinkedList a, LinkedList b, bool c){
	LinkedList tmp_list, test_list1, test_list2, test_list3, test_list4;
	//a.PrintList();
	//b.PrintList();
	test_list1 = a.Bubble_sort(a);
	test_list2 = test_list1.Merge(test_list1);
	test_list3 = b.Bubble_sort(b);
	test_list4 = test_list3.Merge(test_list3);
	/*
	cout<<"=================="<<endl;
	cout<<endl;
	a.PrintList();
	cout<<endl;
	b.PrintList();
	cout<<endl;
	cout<<"=================="<<endl;
	*/
	ListNode *current1 = test_list2.first, *current2 = test_list4.first;
	while(current1 != 0){
		current2 = test_list4.first;
		while(current2 != 0){
			/*if(current1->power == 0)
				current1->power = 1;
			if(current2->power == 0)
				current2->power = 1;*/
			tmp_list.Push_back((current1->coefficient)*(current2->coefficient), (current1->power)+(current2->power));
			current2 = current2->next;
			//cout<<"t";
		}
		current1 = current1->next;
	}
	//======================================================================
	/*
	cout<<endl;
	while(current1!=(0, 0)){
		cout <<"("<<current1->coefficient <<", "<<current1->power<<")";
		current1 = current1->next;
	}
	cout<<endl;
	while(current2!=(0, 0)){
		cout <<"("<<current2->coefficient <<", "<<current2->power<<")";
		current2 = current2->next;
	}
	*/
	
	//======================================================================
	if(c){
		cout<<endl;
		cout<<"Multiplication"<<endl;
		tmp_list.PrintList(c);
		
	}
	
	return tmp_list;
}

LinkedList LinkedList::Bubble_sort(LinkedList a){
    int n = a.size +1;
  
	while(n--){
	    ListNode *prev = 0;
	    ListNode *current = a.first;
	    
	    while(current->next!=0){
	        if(current->power <current->next->power){
	            if(prev==0){
	                //first node
	                ListNode *tmp = current->next ;
	                current->next = tmp->next ;
	                tmp->next = current ;
	            	prev=tmp ;
	                a.first = prev ;
	            }else{
	                ListNode *tmp = current->next ;
	                prev->next = tmp ;
	                current->next = tmp->next ;
	                tmp->next = current ;
	                prev = tmp ;
	            }
	        }/*else if(current->power == current->next->power){
	        	current->coefficient = current->coefficient + current->next->coefficient;
	        	current->next = current->next->next;
			}else if(current->next->coefficient == 0){
				current->next = current->next->next;
			}*/else{
	        	prev = current ; 
	            current=current->next ;
	        }
		}
	}
	//a.PrintList();
    return a ;
}

LinkedList LinkedList::Merge(LinkedList a){
	ListNode *current = a.first;
	while(current!=0){
		
		if(current->next!=0 and current->next->power == current->power){
			current->coefficient = current->coefficient + current->next->coefficient;
			current->next = current->next->next;
			a.size--;
		}
		
		if(current->next!=0 and current->next->coefficient == 0){
			if(current->next->next!=0){
				current->next = current->next->next;
				a.size--;
			}else{//=0
				current->next = 0;
				a.size--;
			}
		}
		
		if(current->next!=0 and current->next->power == current->power){
			current->coefficient = current->coefficient + current->next->coefficient;
			current->next = current->next->next;
			a.size--;
		}
		//a.PrintList();
		//cout<<endl;
		current = current->next;
	}
	//cout<<current->coefficient<<" "<<current->power;
	//cout<<a.first->coefficient<<" "<<a.first->power;
	return a;
}

// example
//1 100 -5 50 3 0 0 + 2 98 10 50 -7 20 0  =>  x^100+2x^98+5x^50-7x^20+3
//1 100 -5 50 3 0 0 * 2 98 10 50 -7 20 0  =>  2x^198+10x^150-10x^148-7x^120-50x^100+6x^98+35x^70+30x^50-21x^20
//1 100 -5 50 3 0 0 - 2 98 10 50 -7 20 0  =>  x^100-2x^98-15x^50+7x^20+3

// -
//1 5 1 4 1 3 1 2 1 1 0 + -1 5 -1 4 -1 3 -1 2 -1 1 0  =>  0

// *
//1 100 -5 50 3 0 0 - 2 98 10 50 -7 20 0  =>  x^100-2x^98-15x^50+7x^20+3
//-3 0 5 0 0 * 1 1 -1 1 1 2 0  =>  2x^2
//-4 2 6 3 4 2 5 0 0 * 5 0 6 3 0  =>  36x^6+60x^3+25
//7 7 3 19 -6 1 6 0 0 * 6 0 6 1 0  =>  18x^20+18x^19+42x^8+42x^7-36x^2+36
//9 2 6 1 0 * 9 2 -6 1 0  =>  81x^4-36x^2
//9 2 16 4 0 * 16 4 9 2 0  =>  256x^8+288x^6+81x^4
//-2 0 3 5 -2 5 0 * -2 0 0  =>  -2x^5+4
//-2 0 3 5 -3 1 2 0 0 * -2 1 0  =>  -6x^6+6x^2
//1 0 2 0 3 0 0 * 1 0 2 0 0  =>  18
//1 0 -1 0 0 * 1 0 -1 0 0  =>  0
//1 5 1 4 1 3 1 2 1 1 0 * 1 5 1 4 1 3 1 2 1 1 0  =>  x^10+2x^9+3x^8+3x^7+x^7+3x^6+2x^6+3x^5+x^5+3x^4+2x^3+x^2

// - +
//剩下常數 2 0 0 - 1 0 0  =>  1
//剩下0 1 5 1 4 1 3 1 2 1 1 0 + -1 5 -1 4 -1 3 -1 2 -1 1 0  =>  0
//多項式+-0  2 3 0 - 1 0 -1 0 0  =>  2x^3
//0+-多項式  1 0 -1 0 0 - 2 3 0  =>  -2x^3
//0+-0 1 0 2 2 0 + -1 0 -2 2 0  =>  0
//完全沒有消除 1 1 2 2 3 3 4 4 0 + 5 5 6 6 7 7 8 8 0  =>  8x^8+7x^7+6x^6+5x^5+4x^4+3x^3+2x^2+x
//完全消除 1 1 2 2  0 + -1 1 -2 2 0   =>  0
// 1 2 3 3 0 + -1 2 3 3 0  =>  6x^3

//new test data
//6 2 4 1 0 * 3 1 -2 0 0  =>  18x^3-8x
//6 2 -6 2 0 + 3 1 -2 0 0  =>  3x-2
//6 2 -6 2 0 - 3 1 -2 0 0  =>  -3x+2
//6 2 -6 2 0 * 3 1 -2 0 0  =>  0
//6 2 4 1 0 + 3 1 -2 0 0  =>  6x^2+7x-2

//6 2 4 1 0 - 3 1 -2 0 0  =>  6x^2+x+2
//-6 2 -4 1 0 - 3 1 -2 0 0  =>  -6x^2-7x+2
//6 2 4 1 0 * 3 1 -3 1 0  =>  0
//6 2 4 1 0 + 3 1 -3 1 0  =>  6x^2+4x
//6 2 4 1 0 - 3 1 -3 1 0  =>  6x^2+4x

//6 2 4 1 -5 2 3 1 0 * 3 0 0  =>  3x^2+21x
//6 2 -5 2 3 1 -1 2 0 - 57 6 3 1 -56 6 -1 6 0  =>  0
//6 2 3 1 0 - 2 1 -1 0 0  =>  6x^2+x+1
//1 2 -1 0 0 - -5 2 1 1 0  =>  6x^2-x-1
//6 2 -5 2 1 0 -1 2 0 * 1 2 -1 2 -1 0 0  =>  -1

//-6 2 -3 2 2 0 9 2 0 * 3 0 -6 2 3 2 3 2 0  =>  6
//6 2 3 1 -2 1 -2 0 0 * 1 0 5 1 -2 1 0  =>  18x^3+9x^2-5x-2

//1 1 -2 0 0 * 1 0 3 1 0  =>  3x^2-5x-2

//* 
//有可消除項 -3 0 5 0 0 * 1 1 -1 1 1 2 0  =>  2x^2
//多項式*0 -3 1 5 0 0 * 1 1 -1 1 0   =>  0

int main(){
	LinkedList list_1, list_2, empty_list, list, test_list1, test_list2, test_list3, test_list4, test_list5;
	int coef = 1, pow = 0, sign;
	bool is_Test = false;
	char c;
	
	/*
	test_list1.Push_back(1, 2);
	test_list1.Push_back(9, 2);
	test_list1.Push_back(5, 2);
	test_list1.PrintList();
	*/
	
	//===========================================
	//cin
	cin>>coef;
	while(coef != 0){//first
		cin>>pow;
		list_1.Push_back(coef, pow);
		if(is_Test)
			cout<<"{push 1}";
		cin>>coef;
	}
	
	
	cin>>c;//+-*
	sign = int(c);
	//cout<<sign;
	
	cin>>coef;
	while(coef != 0){//second
		cin>>pow;
		list_2.Push_back(coef, pow);
		if(is_Test)
			cout<<"{push 2}";
		cin>>coef;
	}
	//===========================================

	if(sign == 43 or sign == 45)
		list = empty_list.Addition_or_Subtraction(list_1, list_2, sign, is_Test);
	//else if(sign == 45)
	//	list = empty_list.Subtraction(list_1, list_2, is_Test);
	else if(sign == 42)
		list = empty_list.Multiplication(list_1, list_2, is_Test);
	
	
	if(is_Test){
		cout<<endl<<endl;
		cout<<"////////////////////"<<endl;
		cout<<"Before sort : ";
		list.PrintList(is_Test);
		test_list2 = list.Bubble_sort(list);
		test_list3 = test_list2.Merge(test_list2);
		cout<<endl<<endl;
		cout<<"After sort and Merge : ";
		test_list3.PrintList(is_Test);
		cout<<endl;
		cout<<"///////////////////"<<endl;
	}else{
		test_list4 = list.Bubble_sort(list);
		test_list5 = test_list4.Merge(test_list4);
		test_list5.PrintList(is_Test);
	}
	
} 
