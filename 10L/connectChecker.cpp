#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

void printGraph(map<char, list<char> > &graph)
{
    map<char, list<char> >::iterator graph_it;
    list<char>::iterator it;

    for (graph_it = graph.begin();
         graph_it != graph.end(); graph_it++)
    {
        cout << (*graph_it).first << ": ";
        for (it = (*graph_it).second.begin();
             it != (*graph_it).second.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}

int main() {

    // build the graph
    map<char, list<char> > graph;
    char v1, v2, start, end;

    //Process graph input
    while((cin >> v1) && v1 != '?')
    {
        if (!(cin >> v2))
            break;

        graph[v1].push_back(v2);


        //REPLACE WITH CODE TO STORE EDGE IN GRAPH

    }

    // display stored graph if compiled with -DDEBUG_PRINT
#ifdef DEBUG_PRINT
    printGraph(graph);
#endif

    //Process queries
    bool visited[graph.size()];
    for (int i = 0; i < graph.size(); i++){
      visited[i] = false;
    }
    Queue<char> queue;
    list<char>iterator i;
    list<char> *adj;




    while (cin >> start >> end)
    {
        //REPLACE WITH CODE TO STORE OR PROCESS QUERIES
        queue.push(start);
        while(!queue.empty()){
          char v = queue.front();
          visited[v] = true;
          queue.pop();
          for (int i = adj[v].begin(); i!=graph[v].end(); i++){
            if visited[v] != true;
            queue.push()
          }
        }














        cin >> v1; //grab the next '?'
        if (v1 != '?')
            break;
    }
}
