#include <iostream>
using namespace std;

class LinkedList;    
                 
class ListNode{
private:
    double data;
    ListNode *next;
public:
    ListNode():data(0),next(0){};
    ListNode(int a):data(a),next(0){};

    friend class LinkedList;
};

class LinkedList{
private:
    int size;              
    ListNode *first;      
public:
    LinkedList():first(0){};
    void PrintList();
    void Push_back(int x);
    void Clear();
    void Radix_Sort();
};

void LinkedList::Clear(){
	ListNode *current = first;
	first = 0;
}

void LinkedList::PrintList(){

    if (first == 0) {
        cout << "List is empty."<<endl;
        return;
    }

    ListNode *current = first;
    while (current != 0) {
        cout << float(current->data)/10 << " ";
        current = current->next;
    }
}


void LinkedList::Push_back(int x){

    ListNode *newNode = new ListNode(x);

    if (first == 0) {
        first = newNode;
        return;
    }

    ListNode *current = first;
    while (current->next != 0) {
        current = current->next;
    }
    current->next = newNode;
}


void LinkedList::Radix_Sort(){
	LinkedList list_0, list_1, list_2, list_3, list_4, list_5, list_6, list_7, list_8, list_9, tmp_list;
	LinkedList main_body[10];
	int tmp_data, digit, i = 1;
	
	ListNode *current = first;
	while (current != 0) {
			tmp_data = current->data;
	        tmp_list.Push_back(tmp_data);
	        current = current->next;
	    }
	
	for(i = 1;i <= 3; i++){//三位數 
		ListNode *current = tmp_list.first;
		while (current != 0) {
			tmp_data = current->data;
	        //cout << tmp_data << " ";
	        current = current->next;
	    }
	    //cout<<endl;
	    
	    current = tmp_list.first;
	    while (current != 0){
			tmp_data = current->data;

			for(int j = 2;j<=i;j++){
	        	tmp_data /= 10;
			}
			digit = tmp_data % 10;
			main_body[digit].Push_back(current->data);
	        current = current->next;
	    }
	    /*
	    cout<<">================<"<<endl;
	    cout<<">    第"<<i<<"次"<<"排序   <"<<endl; 
	    for(int j = 0;j<=9;j++){
	    	main_body[j].PrintList();
		}
		cout<<">================<"<<endl;
		*/
		
		//============= 
		tmp_list.first = 0;
		
		for(int k = 0; k<=9 ; k++){
			
	    	if(main_body[k].first != 0){
	    		
				ListNode *current2 = main_body[k].first;
				
				while (current2 != 0) {
					tmp_data = current2->data;
					tmp_list.Push_back(current2 -> data);
			        current2 = current2->next;
			    }
			main_body[k].first = 0; 
			}
		} 
		//tmp_list.PrintList();
		//=============
	}
	
	current = tmp_list.first;
	
	//cout<<endl<<"排序後 : ";
    tmp_list.PrintList();//結果 
} 
LinkedList tmp_list;
ListNode tmp_node;

int main() {
	//1 10 27.1 9.3 3.3 98.4 5.5 30.6 20 17.9 85.9 0.9
	int mode = 1;
	int data_num;
	double tmp;
	
	cout<<"請選擇輸入模式(預設1) 模式1(原題，輸入1), 模式2(加分題，輸入2): ";
	cin>>mode;
	
	if(mode == 1 or !mode == 2){
		cout<<"請輸入欲排序的總數 : ";
		cin>>data_num;
		for(int i = 1; i<=data_num; i++){
			cin>>tmp;
			tmp_list.Push_back(tmp*10);
		}
		//
		tmp_list.Radix_Sort();
	}else{
		data_num = 1;
		
		while(data_num != 0){
			cout<<"請輸入欲排序的總數(若不排列請輸入 0 ) : ";
			cin>>data_num;
			
			if(data_num == 0){
				cout<<"程式已終止";
				break;
			}
			else{
				for(int i = 1; i<=data_num; i++){
					cin>>tmp;
					tmp_list.Push_back(tmp*10);
				}
			}
			//
			tmp_list.Radix_Sort();
			tmp_list.Clear();
		}
		
	}
	
    return 0;
}
