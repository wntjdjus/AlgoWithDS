/*
 * Author: Yoonjin Park
 * Date : 2019 3 22
 * Description: Dijkstra Algorithm not using Priority Queue
 * 5 Nodes
 * Starting Node is Node 5
 * Connection :
 * 5 -> 4 (2)
 * 5 -> 2 (4)
 * 2 -> 1 (3)
 * 4 -> 2 (1)
 * 4 -> 3 (1)
 * 1 -> 4 (3)
 * 1 -> 3 (6)
 * 3 -> 4 (2)
 *
 * Warning: middle node should start with the starting node index!
 * */

#include <iostream>

using namespace std;

//struct Node{
//	int val;
//	Node* next;
//	Node* prev;
//}Node;
//
//class LinkedList{
//	Node* head;
//	Node* tail;
//	int cnt;
//
//	Node* pushback(Node){
//
//	}
//
//}

void printPath(int p, int* path);

int main(){

	int dist[] = {-999, 999,999,999,999,0};
	int path[] = {-999,-1, -1, -1, -1, -1};
	int w[6][6] = {{0,0,0,0,0,0},
		     {0,0,0,6,3,0},
	     	     {0,3,0,0,0,0},
	             {0,0,0,0,2,0},
	             {0,0,1,1,0,0},
	             {0,0,4,0,2,0}};	     


	//update dist with infinity
	
	//check all nodes
	cout<<"  5 4 3 2 1"<<endl;
	for(int i=5;i>=1;--i){
		cout<<"\n"<<i<<" ";
		for(int j=1;j<=5;++j){
			if(w[i][j]!=0 && dist[j]>dist[i]+w[i][j]){
				dist[j]=dist[i]+w[i][j];
				path[j]=i;
			}
			cout<< dist[j]<<" ";
		}
	}

	// path until Node d and the distance
	for(int d=1;d<=5;++d){
		cout << "Path from Node 5 to Node "<< d <<": ";
		printPath(d, path);
		cout<< "\nShortest Distance from Node 5 to Node "<< d <<": " << dist[d] <<endl;
	}

	return 0;
}

void printPath(int p, int* path){
	if(p==5){
		cout << p <<" ";
		return;
	}
	printPath(path[p], path);
	cout << p << " ";
}
