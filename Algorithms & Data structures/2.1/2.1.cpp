#include <fstream>
#include <iostream>
#include <map>

using namespace std;

class Graph
{
    map<char, string> graph;
    map<char, bool> used;
public:
    Graph(string input_file_path);    

    void find_sources();
    bool is_source(char source_node);
    void find_source(char node);
    void print();
    void dfs();
    void bfs();
protected:
    void dfs(char node);
    void bfs(char node);
};

// ----------------------------------------------------------------------------
int main()
{
    Graph g("graph.txt");
    g.print();

    cout << endl << "Sources: ";
    g.find_sources();

    g.dfs();
    cout << endl;

    g.bfs();

    return 0;
}
// ----------------------------------------------------------------------------

Graph:: Graph(string input_file_path)
{
    ifstream input_graph("graph.txt");

    while(!input_graph.eof())
    {
        char node = '\0';
        string link = "";
        input_graph >> node >> link;
        graph[node] += link;
    }
}

void Graph:: find_sources()
{
    for (auto pair : graph)
    {
        if (is_source(pair.first))
            cout << pair.first << " ";
    }
    cout << endl;
}

bool Graph:: is_source(char source_node)
{
    for (auto i : graph)
        used[i.first] = false;
    
    find_source(source_node);
    for (auto i : used)
    {
        if (!i.second)
        {
            used.clear();
            return false;
        }
    }
    
    used.clear();
    return true;
}

void Graph:: find_source(char node)
{
    used[node] = true;
    for (int i = 0; i < graph[node].size(); ++i)
        if (graph[node][0] != '-')
            find_source(graph[node][i]);
}

void Graph:: print()
{
    cout << "  | ";
    for (auto pair : graph)
        cout << pair.first << " ";
    cout << endl;
    
    cout << "----";
    for (auto pair : graph)
        cout << "--";
    cout << endl;

    for (auto pair : graph)
    {
        cout << pair.first << " | ";
        for (auto another_pair : graph)
        {
            if (pair.second.find(another_pair.first) != string::npos)
                cout << 1;
            else
                cout << 0;
            cout << " ";
        }
        cout << endl;
    }
}

void Graph:: dfs()
{
    for (auto pair : graph)
        if (is_source(pair.first))
        {
            dfs(pair.first);
            break;
        }
    used.clear();
}

void Graph:: bfs()
{
    for (auto pair : graph)
        if (is_source(pair.first))
        {
            bfs(pair.first);
            break;
        }
    used.clear();
}

void Graph:: dfs(char node)
{
    if (!used[node])
        cout << node;
    used[node] = true;
    for (int i = 0; i < graph[node].size(); ++i)
        if (graph[node][0] != '-')
            dfs(graph[node][i]);
}

void Graph:: bfs(char node)
{
    if (!used[node])
        cout << node;
    used[node] = true;
    if (graph[node][0] != '-')
        for (int i = 0; i < graph[node].size(); ++i)
            if (!used[graph[node][i]])
            {
                cout << graph[node][i];
                used[graph[node][i]] = true;
            }
    
    if (graph[node][0] != '-')
        for (int i = 0; i < graph[node].size(); ++i)
            bfs(graph[node][i]);
}
