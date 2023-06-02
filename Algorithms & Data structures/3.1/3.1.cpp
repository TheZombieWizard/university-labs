#include <iostream>
#include <string>
#include <list>

using namespace std;


class Database 
{
private:
    static const int SIZE = 1000;
    list<pair<string, string>> database[SIZE];
    
    int hash_function(string key) 
    {
        int hash = 0;
        for (char c : key)
            hash = (hash * 42 + c) % SIZE;
        return hash;
    }
public:
    void add(string key, string value) 
    {
        int index = hash_function(key);
        database[index].push_back(make_pair(key, value));
    }

    void find(string key) 
    {
        int index = hash_function(key);
        
        for (auto p : database[index])
            if (p.first == key) 
                cout << p.first << " : " << p.second << endl;
    }

    void remove(string key) 
    {
        int index = hash_function(key);
        
        for (auto it = database[index].begin(); it != database[index].end(); ++it) 
        {
            if (it->first == key) 
            {
                database[index].erase(it);
                return;
            }
        }

        cout << "Element not found." << endl;
    }
    
    void print()
    {
        for (auto iter : database)
            if (iter.size())
                for (auto name : iter)
                    cout << name.first << " " << name.second << endl;
    }
};

int main() 
{
    Database database_test;
    
    database_test.add("Bob", "+375213213");
    database_test.add("That guy with mexican hat", "+242142144");
    database_test.add("Don Kihot", "-412874821");
    database_test.add("Jack", "=489218948");
    database_test.add("Klim", "+521514892");
    database_test.add("Klim", "+312389482");
    
    database_test.print();

    cout << endl;
    database_test.find("Klim");
    database_test.remove("Klim");
    cout << endl;
    database_test.find("Klim");
    return 0;
}