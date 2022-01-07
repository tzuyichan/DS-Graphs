#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(const int &, const vector<vector<bool>> &, vector<bool> &, ofstream &);
vector<vector<bool>> load_adjacency_matrix(ifstream &, const int &);
void print(const vector<vector<bool>> &);

int main(void)
{
    string filename, line;

    cout << "Input filename: ";
    cin >> filename;

    // read file
    ifstream inFile("./testcases/3-3/" + filename, ios::in);
    if (!inFile)
    {
        cerr << "Failed to open " << filename << "\n";
        exit(EXIT_FAILURE); // exit program if failed to read file
    }

    // get number of problem datasets
    getline(inFile, line);
    int n_datasets = stoi(line);

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

        // bfs
        bfs(start, adjacency, visited, outFile);
        outFile << endl;
    }

    return 0;
}

void bfs(const int &start,
         const vector<vector<bool>> &adjacency,
         vector<bool> &visited,
         ofstream &outFile)
{
    queue<int> q;

    // mark starting node as visited
    q.push(start);
    visited.at(start) = true;

    while (!q.empty())
    {
        // add current node to traversed list
        int current = q.front();
        outFile << current << " ";
        q.pop();

        // explore adjacent nodes
        for (int i = 0; i < adjacency.at(0).size(); ++i)
        {
            // find unexplored adjacent node
            if (adjacency.at(current).at(i) == true && !visited.at(i))
            {
                // push into to-be-traversed queue
                q.push(i);
                visited.at(i) = true;
            }
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