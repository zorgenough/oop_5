#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

class Tree {

    struct Node {
        char data;
        int k;
        Node* left;
        Node* right;
    };
    Node* root;


    void InitTree(Node *&root);

    void InitTree(Node *&root, char elem);

public:

    Tree();

    Tree(char c);

    ~Tree();

    void Clear(Node *&root);

    bool Searching(Node *root); //

    bool IsEmpty();//

    void InsertUnit(Node *&root, char elem);

    void DeleteNode(Node *&pNode);

    void PrintTree(Node *&root, int level);

    void PrintTree(int level); //

    void Print(Node *&root, int level);

    void Print(int level);

    void InsertUnit(char elem); //

    void DeleteElement(Node *&root, char elem); //

    void DeleteRepeats(); //

    void print_postfix(Node *root, int level); //

    char Finder(Node *&pNode, int &k);

    void DeleteRepeats(Node *&root);

    void print_postfix(int level);

    void DeleteElement(char elem);
};