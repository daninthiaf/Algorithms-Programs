//accept inputs i j x y from input file e.g: 0.5(j) kg of corn(i) for 3.5(y) kg of millet(x)
//do this for whatever amount of inputs for each line (should be 4 values (i j x y))
//put values i j x y (line by line)  through some kind of loop to complete the appropriate conversion
// --subpoint for conversion: do case statement/if statements
//once conversion is done, for each line, compare  if x > 1. if true, output yes and the profit. if false, output no.

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <list> 
#include <limits.h> 
using namespace std; 
 
struct Barter
{
       int i, j;
       float x, y;
};
// Class for an undirected graph 
class Graph 
{ 
    int V;    
    list<int> *adj;   
    bool isCyclicUtil(int v, bool visited[], int parent); 
public: 
    Graph(int V);   
    void addEdge(int v, int w);
    bool isCyclic();   
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 
   
bool Graph::isCyclicUtil(int v, bool visited[], int parent) 
{ 
    visited[v] = true; 
 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    { 
        if (!visited[*i]) 
        { 
           if (isCyclicUtil(*i, visited, v)) 
              return true; 
        } 
  
        else if (*i != parent) 
           return true; 
    } 
    return false; 
} 
  
// Returns true if the graph contains a cycle, else false. 
bool Graph::isCyclic() 
{ 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false;
    for (int u = 0; u < V; u++) 
        if (!visited[u]) // Don't recur for u if it is already visited 
          if (isCyclicUtil(u, visited, -1)) 
             return true; 
  
    return false; 
}  

int main()
{
        
          float i , j , x, y;
          vector <string> numbers;
          string line;

         ifstream myfile("input2.txt");
         //Rename output file like the format given below
         ofstream myfile_out("input2_out.txt");

     //   if(myfile.is_open())
     //   {
     //       while(getline (myfile, line))
     //       {
     //            if(istringstream iss(i >> j >> x >> y))
     //           {
     //               cout << i << " " << j << " " << x  << "  " << y << endl;
     //           }
     //       }
     //       myfile.close();
     //   }
         
         myfile_out.open("input2_out.txt");
        //  if (myfile.is_open())
        
            cout << "Input file has been put into a vector." << endl;
            while(getline(myfile, line))
            {
              string newline;
              newline = line + "\n";
              cout << newline;
              numbers.push_back(newline); 
            }
           //   myfile.close();
              myfile_out.close();
              return 0;

 /*  Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 0); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  
    Graph g2(3); 
    g2.addEdge(0, 1); 
    g2.addEdge(1, 2); 
    g2.isCyclic()? cout << "Graph contains cycle\n": 
                   cout << "Graph doesn't contain cycle\n"; 
  */
 //       return 0;
 }

