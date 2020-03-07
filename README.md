# topological_sort
 An implementation of the topological sort using C++
 
 ```
 Description:	
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
 ```
