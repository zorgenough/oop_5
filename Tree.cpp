#include "Tree.h"
#include <Windows.h>

void Tree::InitTree(Node*& root)
{
    root = nullptr;
}

void Tree::InitTree(Node*& root, char elem) {
    root = new Node;
    root->data = elem;
    root->k = 1;
    root->left = nullptr;
    root->right = nullptr;
}

Tree::Tree()
{
    InitTree(root);
}

Tree::Tree(char c) {
    InitTree(root, c);
}

bool Tree::IsEmpty() {
    return root == nullptr;
}

void Tree::Clear(Node*& root)
{
    if (root) {
        Clear(root->left);
        Clear(root->right);
        root->left = nullptr;
        root->right = nullptr;
        root = nullptr;
        delete root;
    }
}

Tree::~Tree() {
    Clear(root);
}

bool Tree::Searching(Node* root)
{
    if (!root)
        return false;
    else
    {
        if (root->k > 1)
            return true;
        else if (root->k <= 1)
            return Searching(root->right) || Searching(root->left);
    }
}

void Tree::InsertUnit(Node*& root, char elem) {
    if (!root)
        InitTree(root, elem);
    else {
        if (root->data == elem)
            root->k++;
        else {
            if (elem < root->data)
                InsertUnit(root->left, elem);
            else InsertUnit(root->right, elem);
        }
    }
}

void Tree::InsertUnit(char elem) {
    InsertUnit(root, elem);
}

void Tree::PrintTree(Node*& root, int level)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (root) {
        PrintTree(root->right, level + 1);
        for (int i = 0; i < level; i++) {
            cout << "   ";
        }
        if (root->k > 1) {
            SetConsoleTextAttribute(console, FOREGROUND_RED);
            cout << root->data << endl;
        }
        else {
            SetConsoleTextAttribute(console, FOREGROUND_GREEN);
            cout << root->data << endl;
        }
        PrintTree(root->left, level + 1);
    }
}

void Tree::Print(Node*& root, int level) {
    if (root) {
        Print(root->right, level + 1);
        for (int i = 0; i < level; i++) { ////////////
            cout << "    ";
        }
        cout << root->k << endl;
        Print(root->left, level + 1);
    }
}

void Tree::Print(int level) {
    Print(root, level);
}

void Tree::PrintTree(int level) {
    PrintTree(root, level);
}

void Tree::DeleteElement(Node*& root, char elem)
{
    if (elem == root->data)
        DeleteNode(root);
    else if (elem < root->data)
        DeleteElement(root->left, elem);
    else DeleteElement(root->right, elem);
}

void Tree::DeleteRepeats()
{
    while (Searching(root)) {
        DeleteRepeats(root);
    }
}

void Tree::DeleteElement(char elem) {
    DeleteElement(root, elem);
}

void Tree::print_postfix(Node* root, int level)
{
    if (root) {
        print_postfix(root->left, level + 1);
        for (int i = 0; i < level; ++i)
            cout << "   ";
        cout << root->data << endl;
        print_postfix(root->right, level + 1);
    }
}


void Tree::print_postfix(int level)
{
    print_postfix(root, level);
}

char Tree::Finder(Node*& pNode, int& k) {
    if (!pNode->left) {
        char value = pNode->data;
        k = pNode->k;
        Node* dNode = pNode;
        pNode = pNode->right;
        delete dNode;
        dNode = nullptr;
        return value;
    }
    Finder(pNode->left, k);
}

void Tree::DeleteRepeats(Node*& root)
{
    if (root)
    {
        if (root->k > 1)
            DeleteElement(root, root->data);
        DeleteRepeats(root->left);
        DeleteRepeats(root->right);
    }
}

void Tree::DeleteNode(Node*& pNode) {
    if (!pNode->left && !pNode->right)
    {
        //pNode = nullptr;
    }
    else {
        Node* dNode;
        if (!pNode->left || !pNode->right) {
            dNode = pNode;
            if (!pNode->left) {
                pNode = pNode->right;
                delete dNode;
                dNode = nullptr;
            }
            else {
                pNode = pNode->left;
                delete dNode;
                dNode = nullptr;
            }
        }
        else {
            pNode->data = Finder(pNode->right, pNode->k);
        }
    }
}