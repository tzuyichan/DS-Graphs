#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void dfs(const int &, const vector<vector<bool>> &, vector<bool> &);
vector<vector<bool>> load_adjacency_matrix(ifstream &, const int &);
void print(const vector<vector<bool>> &);

int main(void)
{
    string filename, line;

    cout << "Input filename: ";
    cin >> filename;

    // read file
    ifstream inFile("./testcases/3-2/" + filename, ios::in);
    if (!inFile)
    {
        cerr << "Failed to open " << filename << "\n";
        exit(EXIT_FAILURE); // exit program if failed to read file
    }

    // get number of problem datasets
    getline(inFile, line);
    int n_datasets = line.at(0) - '0';

    // open output file
    ofstream outFile("output.txt", ios::out);
    if (!outFile)
    {
        cerr << "Failed to write to output\n";
        exit(EXIT_FAILURE); // exit program if failed to write file
    }

    for (int i = 0; i < n_datasets; ++i)
    {
        // get first line
        getline(inFile, line);
        stringstream sstream(line);
        getline(sstream, line, ' ');
        int n_vertices = stoi(line);
        getline(sstream, line, ' ');
        int start = stoi(line);

        // load matrices
        vector<vector<bool>> adjacency = load_adjacency_matrix(inFile, n_vertices);
        vector<bool> visited(n_vertices, false);

        // dfs
        dfs(start, adjacency, visited);
        cout << endl;
    }

    return 0;
}

void dfs(const int &start,
         const vector<vector<bool>> &adjacency,
         vector<bool> &visited)
{
    // mark current node as visited
    cout << start << " ";
    visited.at(start) = true;

    // explore adjacent nodes
    for (int i = 0; i < adjacency.at(0).size(); ++i)
    {
        // find unexplored adjacent node
        if (adjacency.at(start).at(i) == true && !visited.at(i))
        {
            dfs(i, adjacency, visited);
        }
    }
}

vector<vector<bool>> load_adjacency_matrix(ifstream &inFile, const int &n_vertices)
{
    string line;
    vector<vector<bool>> matrix(n_vertices);

    for (int row = 0; row < n_vertices; ++row)
    {
        getline(inFile, line);
        stringstream sstream(line);

        // tokenize numbers in line
        while (getline(sstream, line, ' '))
        {
            matrix.at(row).push_back(stoi(line));
        }
    }

    return matrix;
}

void print(const vector<vector<bool>> &array)
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