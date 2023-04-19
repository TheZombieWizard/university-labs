#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Graph
{
    vector<char> nodes;
    vector<string> links;
public:
    Graph(string input_file_path);    

    void find_sources();
    bool is_source(char source_node);
    void print();
};

// ----------------------------------------------------------------------------
int main()
{
    Graph g("graph.txt");
    g.print();
    cout << endl << "Sources: ";
    g.find_sources();
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
        nodes.push_back(node);
        links.push_back(link);
    }
}

void Graph:: find_sources()
{
    for (int node_i = 0; node_i < nodes.size(); ++node_i)
    {
        if (is_source(nodes[node_i]))
            cout << nodes[node_i] << " ";
    }
    cout << endl;
}

bool Graph:: is_source(char source_node)
{
    for (int node = 0; node < nodes.size(); ++node)
        if (nodes[node] == source_node)
            for (int link = 0; link < links.size(); ++link)
                if ((links[node].find(nodes[link]) == string::npos) && (nodes[link] != source_node))
                    return false;
    
    return true;
}

void Graph:: print()
{
    cout << "  | ";
    for (int i = 0; i < nodes.size(); ++i)
        cout << nodes[i] << " ";
    cout << endl;
    
    cout << "----";
    for (int i = 0; i < nodes.size(); ++i)
        cout << "--";
    cout << endl;

    for (int row = 0; row < nodes.size(); ++row)
    {
        cout << nodes[row] << " | ";
        for (int column = 0; column < links.size(); ++column)
        {
            if (links[row].find(nodes[column]) != string::npos)
                cout << 1;
            else
                cout << 0;
            cout << " ";
        }
        cout << endl;
    }
}
