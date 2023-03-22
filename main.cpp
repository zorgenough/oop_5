#include "Tree.h"
#include <windows.h>

string DelSameStr(string str) {
    unsigned int start_time =  clock();
    string res = "";
    char prev = str[0];
    res += str[0];
    for (int i = 0; i < str.size(); i++)
        if (str[i] != prev) {
            prev = str[i];
            res += str[i];
        }
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << "Время строки = " << search_time << endl;
}


int main() {
    SetConsoleOutputCP(CP_UTF8);
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    Tree Tree;
    string str = "QWEQWEASDCZXFDZ"; //gsgsdfsadfsd // ABCDEFGABC // MCVMCXDSA //QWEQWEASDCZXFDZ
    for (int i = 0; i < str.size(); ++i){
        Tree.InsertUnit(str[i]);
    }

    Tree.PrintTree(0);
    unsigned int start_time =  clock();
    Tree.DeleteRepeats();
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    cout << endl << "=================================" << endl;
    cout << "Готовое дерево" << endl;
    Tree.PrintTree(0);

    cout << "Время удаления в дереве = " << search_time << endl;
    DelSameStr(str);

    system("pause");
}