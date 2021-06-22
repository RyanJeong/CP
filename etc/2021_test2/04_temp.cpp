#include <bits/stdc++.h>

using namespace std;

enum {
    LEFT,
    RIGHT
};

typedef struct bst {
    char _val;
    bst* _left;
    bst* _right; 
} Bst;

void print(Bst *p)
{
    if (p) {
        cout << p->_left << ' ' << p << ' ' << p->_right << '\n';
        print(p->_left);
        print(p->_right);
    }
}

string decode(vector<string> codes, string encoded) {
    Bst* top = (Bst*) malloc(sizeof(Bst));
    Bst* p = NULL;
    top->_val=0;
    top->_left=top->_right=NULL;

    // 1. parse
    for (string str : codes) {
        char val;
        p=top;

        if (isalnum(str[0])) {
            val=str[0];            
            str.erase(0,2);
        }
        else {
            val='\n';
            str.erase(0,10);
        }
        for (char c : str) {
            bool path = c-'0';

            if (path==LEFT) {
                if (!p->_left) {
                    p->_left=(Bst*) calloc(1, sizeof(Bst));
                }
                p=p->_left;
            }
            else if (path==RIGHT) {
                if (!p->_right) {
                    p->_right=(Bst*) calloc(1, sizeof(Bst));
                }
                p=p->_right;
            }
        }
        p->_val=val;
    }

    // 2. decode
    string answer;
    print(top);
    
    return answer;
}

int main(void)
{
    vector<string> codes = {
        "a\t100100",
        "b\t100101",
        "c\t110001",
        "d\t100000",
        "[newline]\t111111",
        "p\t111110",
        "q\t000001"
    };
    string encoded = "111110000001100100111111100101110001111110";
    cout << decode(codes, encoded);

    return 0;
}