//Creator: Haque, Mahfuzul
//Last Modified: 3/27/2018

/*Description:	
	This program is intended to take in a sequence of integer inputs from the user and sort them topologically. When launching the program,
the user will be presented with a blank console. On the first line, the user is to enter the total number of vertices
from 1 <= N <= 100. Each proceeding line will represent a vertice from 1 - N. After the user enters the total number of vertices, each proceeding input 
should be a list of integer vertices that will represent an edge between the vertice represented by the line number and the list of vertices inputted 
by the user. The line should end with 0 to denote that the vertice represented by the line number will not have any more adjacent vertices.

If that doesn't sound confusing enough, here is an example of a valid input:

5             (total number of vertices)
0             (vertice 1 is adjacent to nothing)
4 5 1 0		  (vertice 2 is adjacent to vertice 4, 5, and 1)
1 0           (vertice 3 is adjacent to vertice 1)
5 3 0         (vertice 4 is adjacent to 5 and 3)
3 0           (vertice 5 is adjacent to 3)

The input above will yield the following output. Note that the program will sort topologically AND should it come across multiple ties between
vertices (multiple vertices with indegree 0), the program will output the vertices lexicographically:

2 4 5 3 1

*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class TopologicalSort
{
	int numVertices;
	vector<int>* list;
	//Post: update indegree of vertex x and all adjacent vertices of vertex x
	void updateKey(int x, vector<int>& inDegree) {

		for (vector<int>::iterator i = list[x].begin(); i != list[x].end(); i++) {
			inDegree[*i]--;
		}
		inDegree[x] = -1;											//a vertice marked by -1 means it has already been visited
	}

public:
	//Pre: 1 <= numVertices <= 100
	//Post: class will initialize an adjacency list of size numVertices
	TopologicalSort(int numVertices) {
		this->numVertices = numVertices;
		list = new vector<int>[numVertices];
	}

	//Post: function will append adjacent vertice to appropriate vertex in the adjacency list
	void addEdge(int vertice, int value) {
		list[vertice].push_back(value);
	}

	//Pre: No 2 vertices in adjacency list point to each other (no infinite loop)
	//Post: function will sort adjacency list topologically and lexicographically in the event of a tie
	void sort() {

		//initialize an inDegree list with all 0's.
		//declare toUpdate to hold a list of germs to be updated using updateKey
		//declare sortedList to hold topologically sorted list

		vector<int> inDegree(numVertices, 0), toUpdate, sortedList;
		queue<int> priorityQueue;

		for (int i = 0; i < numVertices; i++)                                   //initialize indegree of all vertices in adjacency list
		{
			for (vector<int>::iterator x = list[i].begin(); x != list[i].end(); x++) {		//use iterator to access adjacent vertices
				inDegree[*x]++;
			}
		}


		for (int i = 0; i < numVertices; i++) {								   //push any vertice with indegree 0 into a queue
			if (inDegree[i] == 0) {
				priorityQueue.push(i);
				toUpdate.push_back(i);
				//updateKey(i, inDegree);
			}
		}
		for (int i = 0; i < toUpdate.size(); i++) {							  //update indegree of all adjacent vertices of each vertex currently in queue
			updateKey(toUpdate[i], inDegree);
		}


		while (!priorityQueue.empty())
		{
			toUpdate.clear();
			int front;
			while (!priorityQueue.empty()) {								//push all vertices inside priority queue to the sortedList vector
				front = priorityQueue.front();								//since its indegree is 0
				priorityQueue.pop();
				sortedList.push_back(front);
			}

			for (int i = 0; i < numVertices; i++) {							//loop from beginning of indegree vector everytime to ensure that
				if (inDegree[i] == 0) {										//the sortedList is ordered topologically AND LEXICOGRAPHICALLY
					priorityQueue.push(i);									//and push back to priorityQueue
					toUpdate.push_back(i);
					//updateKey(i, inDegree);
				}
			}
			for (int i = 0; i < priorityQueue.size(); i++) {			   //update all vertices in toUpdate vector because there are certain cases
				updateKey(toUpdate[i], inDegree);						   //where all indegrees have to be updated after all vertices in indegree
			}															   //vector have been read first.

		}

		for (int i = 0; i < sortedList.size(); i++) {					   //output sorted list. add 1 to each element to account for index starting at 0
			cout << sortedList[i] + 1 << " ";
		}
	}
};

//post: program will take in a series of integer inputs from user and output them in topological order
int main()
{

	int numSequences, value;
	cin >> numSequences;
	TopologicalSort graph(numSequences);
	for (int i = 0; i < numSequences; i++) {					//read inputs
		while (true) {
			cin >> value;
			if (value == 0) break;
			graph.addEdge(i, value - 1);
		}
	}

	graph.sort();
	return 0;
}