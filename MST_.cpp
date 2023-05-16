#include <iostream>
#include <algorithm>
#include <map>


using namespace std;

int* parent;



int minkey(int key[], bool mstSet[], int n)
{
	int min = INT_MAX;
	int	min_index=0;

	for (int v = 0; v < n; v++) {
		if (mstSet[v] == false && key[v] < min ) {
			min = key[v];
			min_index = v;
		}
	}

	return min_index;
}



int* primsMST(int n,int **adj) {
	parent = new int[n];
	int *key = new int[n];
	bool *mstSet = new bool[n];
	for (int i = 0; i < n; i++) {
		key[i] = INT_MAX;
		mstSet[i] = false;
		parent[i] = -1;
	}

	key[0] = 0;
	parent[0] = -1;
	
	for (int i = 0; i < n-1; i++) {
		int u = minkey(key, mstSet, n);

		mstSet[u] = true;

		for (int j = 0; j < n; j++) {
			if (adj[u][j] != 0 && mstSet[j] == false && adj[u][j] < key[j]) {
				parent[j] = u;
				key[j] = adj[u][j];
			}
		}
		
	}
	return parent;
	
}


int main()
{
	int numberofvertices;
	cin >> numberofvertices;

	map<int, string>names;

	int** adj = new int* [numberofvertices];
	for (int i = 0; i < numberofvertices; i++) {
		adj[i] = new int[numberofvertices];
		for (int j = 0; j < numberofvertices; j++) {
			adj[i][j] = 0;
			}
	}
	
	for (int i = 0; i < numberofvertices; i++) {
		int indexofvertices;
		string nameofvertices;
		
		cin >> indexofvertices >> nameofvertices;

		names[indexofvertices-1] = nameofvertices;
		
	}
	
	int numberofedges;
	cin >> numberofedges;
	
	for(int j = 0; j < numberofedges; j++){
		int indexofvertices1;
		int indexofvertices2;
		int weightofedges;
		
		cin >> indexofvertices1 >> indexofvertices2 >> weightofedges;

		adj[indexofvertices1-1][indexofvertices2-1] = weightofedges;
		adj[indexofvertices2-1][indexofvertices1-1] = weightofedges;
		
	}

	 primsMST(numberofvertices,adj);

	
	 for (int i = 1; i < numberofvertices; i++) {
		cout << names[parent[i]] << " " << names[i] << " " << adj[i][parent[i]] << endl;
	 }
	return 0;
}

