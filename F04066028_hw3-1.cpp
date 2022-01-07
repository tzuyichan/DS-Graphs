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
void print_preorder(const vector<int> &, const vector<int> &, ofstream &);
void print_postorder(const vector<int> &, const vector<int> &, ofstream &);

int main(void)
{
    string filename, line;

    cout << "Input filename: ";
    cin >> filename;

    // read file
    ifstream inFile("./testcases/3-1/" + filename, ios::in);
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
        // get input file contents
        string order; // problem type
        getline(inFile, order);
        getline(inFile, line);
        int n_nodes = stoi(line); // number of nodes
        vector<int> porder = load_binary_tree(inFile);
        vector<int> inorder = load_binary_tree(inFile);

        // print order conversion
        if (order == "preorder-inorder")
        {
            print_postorder(porder, inorder, outFile);
            outFile << endl;
        }
        if (order == "postorder-inorder")
        {
            print_preorder(porder, inorder, outFile);
            outFile << endl;
        }
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

void print_preorder(const vector<int> &post, const vector<int> &in, ofstream &outFile)
{
    int root_idx = search(post.back(), in);
    int rsubtree_len = post.size() - root_idx - 1;

    outFile << post.back() << " ";

    if (root_idx != 0)
    {
        vector<int> sub_post(post.begin(), post.end() - rsubtree_len - 1);
        vector<int> sub_in(in.begin(), in.begin() + root_idx);
        print_preorder(sub_post, sub_in, outFile);
    }

    if (root_idx != in.size() - 1)
    {
        vector<int> sub_post(post.end() - rsubtree_len - 1, post.end() - 1);
        vector<int> sub_in(in.begin() + root_idx + 1, in.end());
        print_preorder(sub_post, sub_in, outFile);
    }
}

void print_postorder(const vector<int> &pre, const vector<int> &in, ofstream &outFile)
{
    int root_idx = search(pre.at(0), in);

    if (root_idx != 0)
    {
        vector<int> sub_pre(pre.begin() + 1, pre.end());
        vector<int> sub_in(in.begin(), in.begin() + root_idx);
        print_postorder(sub_pre, sub_in, outFile);
    }

    if (root_idx != in.size() - 1)
    {
        vector<int> sub_pre(pre.begin() + root_idx + 1, pre.end());
        vector<int> sub_in(in.begin() + root_idx + 1, in.end());
        print_postorder(sub_pre, sub_in, outFile);
    }

    outFile << pre.at(0) << " ";
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