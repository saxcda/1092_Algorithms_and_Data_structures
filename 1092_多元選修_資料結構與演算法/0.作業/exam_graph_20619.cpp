#include<iostream>
using namespace std;

class Graph{
private:
    int numV;
    int gLine[20][20];
    bool visited[];

public:	
	Graph(int);
	void addEdge(int, int);
    void Print_adjacency_matrix();
	bool is_Connected();
	int get_max_degree();
	int get_min_degree();
	bool is_Eulerian();
	bool is_Isolated();
	int DFS(int);
	void show_connected(int);
	int* get_sum_degree();
	bool compare_two_graph(int, int, Graph, Graph);
};

Graph::Graph(int N){
	numV = N;
	visited[numV];
	for(int i = 0; i<numV; i++){
		visited[i] = false;
        for(int j = 0; j<numV; j++){
            gLine[i][j] = 0;
        }
    }
}

void Graph::addEdge(int i, int j){
    if((i < 0) or (i >= numV)){
        cout<<"頂點"<<i<<"不存在!";
    }
    
    if((j < 0) or (j >= numV)){
        cout<<"頂點"<<j<<"不存在!";
    }
    
    if(i >= 0 and i < numV and j >= 0 and j < numV){
        gLine[i][j] = 1;
        gLine[j][i] = 1;
    }
}

void Graph::Print_adjacency_matrix(){
    for(int i = 0; i<numV; i++){
		cout<<endl;
        for(int j = 0; j<numV; j++){
            cout<<gLine[i][j]<<" ";
        }
    }
    cout<<endl;
}
 
int* Graph::get_sum_degree(){
	int* sumDegree = new int[numV];
    int degree, maxDeg = 0;

    for(int i = 0; i<numV; i++){
    	degree=0;
    	for(int j=0; j<numV; j++){
	        if(gLine[i][j] ==1)
	            degree++;
        }
        sumDegree[i]=degree;
    }
    return sumDegree;
}
 
int Graph::get_max_degree(){
	int maxDeg = 0;
    int* sumDegree = Graph::get_sum_degree();
    
    for(int i = 0; i<numV; i++){
    	if(sumDegree[i] > maxDeg)
    		maxDeg = sumDegree[i];
    }
 	return maxDeg;
}

int Graph::get_min_degree(){
    int minDeg = numV+1;
    int* sumDegree = Graph::get_sum_degree();

    for(int i = 0; i<numV; i++){
    	if(sumDegree[i] < minDeg)
    		minDeg = sumDegree[i];
    }
 	return minDeg;
}

bool Graph::is_Isolated(){
	int* sumDegree = Graph::get_sum_degree();
	
	for(int i = 0; i<numV; i++){
      if(sumDegree[i] == 0)
    	return true;
    }
 	return false;
}


Graph generateGraph(Graph amGraph, int vNum){
    for(int i = 0; i<vNum; i++){
		cout<<"請依序輸入與頂點 "<<i<<"相連的點,並使用空格隔開, 結束請輸入-9, (例如:1 3 4 -9) : "<<endl;
		int j;
		while(cin>>j){
			if (j >= 0 and j < vNum and j != -9){
				amGraph.addEdge(i, j);
			}else if(j == -9){
				break;
			}
		}
	}
	amGraph.Print_adjacency_matrix();
	return amGraph;
}

int Graph::DFS(int point){
    visited[point] = true;
    for(int v = 0 ; v<numV ; v++){
        if(gLine[point][v]){
            if(!visited[v]){
                DFS(v);
            }
        }
	}
	
}


bool Graph::is_Connected(){
	int i;
    for(i = 0; i<numV; i++){
    	visited[i] = false;
		for(int j=0;j<numV;j++){
        	gLine[i][j] = false;
        	if(gLine[i][j]!=0)
        		break;
        }
        DFS(i);
    }

    for(i = 0; i<numV; i++){
       if(visited[i] == false){
		   for(int j = 0; j<numV; j++){
		   		if(gLine[i][j] > 0)
		   			return false;
		   	}
		}
	}
    return true;
}

bool Graph::is_Eulerian(){
    if(is_Connected() == false)
        return false;
      
    int odd = 0;
    int* sum_degree = get_sum_degree();
    
    for(int i = 0; i<numV; i++){
    	if(sum_degree[i]%2 !=0){
        	odd++;
    	}
    }
    if(odd > 2 or odd == 1)
        return false;
    
    return true;
}

void Graph::show_connected(int i){
	cout<<i;
	for(int j = 0; j<numV; j++){
		if (gLine[i][j])
			cout << " -> " << j;
	}
}

bool Graph::compare_two_graph(int org_size, int sub_size, Graph org_graph, Graph sub_graph){	 
	bool ret;
	int gap = org_size-sub_size; 
	
	for(int i = 0; i<sub_size; i++){
		for(int j = 0; j<sub_size; j++){
			if(org_graph.gLine[i+gap][j+gap] == sub_graph.gLine[i][j])
				ret = true;
			else
				ret = false;
		}
	}
	return ret;
}

void Print_options(){
	cout<<endl<<endl;
	cout<<"|========================|"<<endl;
    cout<<"| 1.查詢 maximum degree. |"<<endl;
	cout<<"| 2.查詢 minimum degree. |"<<endl;
	cout<<"| 3.查詢子圖             |"<<endl;
	cout<<"| 4.是否為 connected     |"<<endl;
	cout<<"| 5.是否有 Euler trail.  |"<<endl;
	cout<<"| 0.結束                 |"<<endl;
	cout<<"|========================|"<<endl;
}

/*

1 3 4 -9
0 2 -9
1 3 4 -9
0 2 4 -9
0 2 3 -9

1 2 -9
0 3 -9
0 1 -9

3 4 -9
2 3 -9
1 4 -9
0 1 4 -9
0 2 3 -9
*/

int main(){
	int num, choice,exit_p = 1, max_degree, min_degree, subPoint=-1;
	bool connected = false, ret;
	
	cout<<"請輸入圖的點數 : ";
	cin>>num;
 	 
    Graph adjacency_matrix_graph(num);
    adjacency_matrix_graph = generateGraph(adjacency_matrix_graph, num);
    
    Print_options();
    cin>>choice;
    
	do{
        if(choice == 1){
            max_degree = adjacency_matrix_graph.get_max_degree();
            cout<<"Maximum degree = "<<max_degree;
            
    	}else if(choice == 2){
			min_degree = adjacency_matrix_graph.get_min_degree();
			cout<<"Minimum degree = "<< min_degree;
			
    	}else if(choice == 3){
			cout<<"請輸入圖形的點數 : ";
			cin>>subPoint;
			Graph subGraph(subPoint);
			subGraph = generateGraph(subGraph, subPoint);
		   
			if(subPoint > 0 and subPoint <= num){
				ret = subGraph.compare_two_graph(num, subPoint, adjacency_matrix_graph, subGraph);
				if(ret)
					cout<<"yes";
				else
					cout<<"no";	  		  
		    }else{
		    	 cout<<"no";	  		    	
		    }
		    
        }else if(choice == 4){
			connected = adjacency_matrix_graph.is_Isolated();
			if(!connected)
				cout<<"yes, it\'s connected.";
			else
				cout<<"no, it\' not connected.";
				
        }else if(choice ==5){
			bool ret = adjacency_matrix_graph.is_Eulerian();
			if(!ret)
				cout<<"no euler trail.";
			else{
				cout<<"have euler trail.";
				/*
				for(int i = 1;i<=num;i++){
					int V = AMgraph.DFS(0);
					cout<<V;
				}
				*/
				
			}
        }else if(choice ==0){ 
			exit_p = 0; 
        }
        Print_options();
    	cin>>choice;
    	
    }while(exit_p);
    
    return 0;
}


