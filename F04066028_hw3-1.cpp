#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> load_binary_tree(ifstream &);
void print(const vector<int> &);
int search(const int &x, const vector<int> &);

int main(void)
{
    string filename, line;

    cout << "Input filename: ";
    cin >> filename;

    // Read file.
    ifstream inFile(filename, ios::in);
    if (!inFile)
    {
        cerr << "Failed to open " << filename << "\n";
        exit(EXIT_FAILURE); // exit program if failed to read file
    }

    // get number of problem datasets
    getline(inFile, line);
    int n_datasets = line.at(0) - '0';

    for (int i = 0; i < n_datasets; ++i)
    {
        // get input file contents
        string order; // problem type
        getline(inFile, order);
        cout << order << "\n";
        getline(inFile, line);
        int n_nodes = stoi(line); // number of nodes
        cout << n_nodes << "\n";
        vector<int> porder = load_binary_tree(inFile);
        vector<int> inorder = load_binary_tree(inFile);
        print(porder);
        print(inorder);
    }

    return 0;
}

int search(const int &x, const vector<int> &tree)
{
    for (int i = 0; i < tree.size(); ++i)
    {
        if (tree.at(i) == x)
            return i;
    }
    return -1;
}

vector<int> load_binary_tree(ifstream &inFile)
{
    string line;
    vector<int> tree;

    getline(inFile, line);
    stringstream sstream(line);

    // tokenize numbers in line
    while (getline(sstream, line, ' '))
    {
        tree.push_back(stoi(line));
    }

    return tree;
}

void print(const vector<int> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
}