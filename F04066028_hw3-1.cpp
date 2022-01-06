#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> load_binary_tree(ifstream &, const int &);
void print(const vector<int> &);

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
        string order;
        getline(inFile, order);
        getline(inFile, line);
        int n_nodes = line.at(0) - '0';
        vector<int> porder = load_binary_tree(inFile, n_nodes);
        vector<int> inorder = load_binary_tree(inFile, n_nodes);
        print(porder);
        print(inorder);
    }

    return 0;
}

vector<int> load_binary_tree(ifstream &inFile, const int &n_nodes)
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