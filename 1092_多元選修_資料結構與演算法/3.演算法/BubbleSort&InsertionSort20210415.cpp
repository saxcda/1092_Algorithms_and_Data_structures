#include<iostream>

using namespace std;

int main(){
	int n = 7,k,temp;
	int a[8] = {};
	int b[8] = {};
	for(int p = 1;p <= n;p++){
		cin >> a[p];
		b[p] = a[p];		
	}
	
	//bubble sort
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n-i;j++){
			if(a[j] > a[j+1]){
				k = a[j];	
				a[j] = a[j+1];
				a[j+1] = k; 
			}
		}
	}
	cout << "bubble sort:" << endl;
	for(int m = 1;m <= n;m++){
		cout << a[m] << " ";		
	}
	cout << endl;
	//insertion sort
	for(int ii = 2;ii <= n;ii++){
		temp = b[ii];
		b[0] = temp;
		while(temp < b[ii-1]){
			b[ii] = b[ii-1];
			ii--;
		}
		//這行投影片沒打到 
		b[ii] = temp;
	}
	cout << "insertion sort:" << endl;
	for(int jj = 1;jj <= n;jj++){
		cout << b[jj] << " ";		
	}
	return 0;	
}
