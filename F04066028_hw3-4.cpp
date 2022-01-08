#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

enum edge
{
    COST = 0,
    U = 1,
    V = 2
};

int find_set(const int &, const vector<int> &);
void print(const vector<vector<int>> &);

int main(void)
{
    string filename, line;

    cout << "Input filename: ";
    cin >> filename;

    // read file
    ifstream inFile("./testcases/3-4/" + filename, ios::in);
    if (!inFile)
    {
        cerr << "Failed to open " << filename << "\n";
        exit(EXIT_FAILURE); // exit program if failed to read file
    }

    // open output file
    ofstream outFile("output.txt", ios::out);
    if (!outFile)
    {
        cerr << "Failed to write to output\n";
        exit(EXIT_FAILURE); // exit program if failed to write file
    }

    // get first line
    getline(inFile, line);
    stringstream sstream(line);
    getline(sstream, line, ' ');
    int n_vertices = stoi(line);
    getline(sstream, line, ' ');
    int n_edges = stoi(line);

    // initiate data structures
    vector<vector<int>> graph(n_edges, vector<int>(3));
    vector<vector<int>> mst;
    vector<int> parent(n_vertices);
    for (int i = 0; i < n_vertices; ++i)
    {
        parent.at(i) = i;
    }

    // load edge info
    for (int i = 0; i < n_edges; ++i)
    {
        getline(inFile, line);
        stringstream sstream(line);
        getline(sstream, line, ' ');
        graph[i][U] = stoi(line);
        getline(sstream, line, ' ');
        graph[i][V] = stoi(line);
        getline(sstream, line, ' ');
        graph[i][COST] = stoi(line);
    }

    // sort edge weights in ascending order
    sort(graph.begin(), graph.end());

    // check if adding a new edge would form a cycle
    for (int i = 0; i < n_edges; ++i)
    {
        int u_set_root = find_set(graph[i][U], parent);
        int v_set_root = find_set(graph[i][V], parent);

        // if doesn't form a cycle, add to min span tree
        if (u_set_root != v_set_root)
        {
            mst.push_back(graph[i]);
            parent.at(v_set_root) = parent.at(u_set_root); // join sets
        }
    }

    // sum edge weight cost
    int sum = 0;
    for (int i = 0; i < mst.size(); ++i)
    {
        sum += mst[i][COST];
    }
    outFile << sum;

    return 0;
}

int find_set(const int &vertex, const vector<int> &parent)
{
    // this vertex is the root of the set
    if (parent.at(vertex) == vertex)
        return vertex;
    // find the parent of this vertex's parent
    // until the root of the set is found
    else
        return find_set(parent.at(vertex), parent);
}

void print(const vector<vector<int>> &array)
{
    for (auto row : array)
    {
        for (auto elem : row)
        {
            cout << elem;
        }
        cout << endl;
    }
}