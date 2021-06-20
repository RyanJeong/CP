#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'decode' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY codes
 *  2. STRING encoded
 */

enum {
    LEFT,
    RIGHT
};

typedef struct bst {
    char _val;
    bst* _left;
    bst* _right; 
} Bst;

string decode(vector<string> codes, string encoded) {
    Bst* top = (Bst*) malloc(sizeof(Bst));
    Bst* p = NULL;
    top->_val=0;
    top->_left=top->_right=NULL;

    // 1. parse
    for (string str : codes) {
        char val;
        p=top;

        if (!str.compare(0,9,"[newline]")) {
            val='\n';
            str.erase(0,10);
        }
        else {
            val=str[0];            
            str.erase(0,2);
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
    p=top;
    for (char c : encoded) {
        bool path = c-'0';

        if (path==LEFT) {
            p=p->_left;
        }
        else if (path==RIGHT) {
            p=p->_right;
        }
        if (!p->_left && !p->_right) {
            answer.push_back(p->_val);
            p=top;
        }
    }
    
    return answer;
}


int main(void)
{
    /*
    vector<string> codes1 = {
        "a\t010",
        "b\t1",
        "c\t00",
        "d\t011"
    };
    string encoded1="0101001011010011";
    cout << decode(codes1, encoded1);
    vector<string> codes2 = {
        "g\t00",
        "o\t01",
        "p\t1110",
        "h\t1101",
        "e\t101",
        "r\t1111",
        "s\t1100",
        " \t100"
    };
    string encoded2="0001100000110000011110110110111111100";
    cout << decode(codes2, encoded2);
    */
    vector<string> codes = {
        "a\t100100",
        "b\t100101",
        "c\t110001",
        "d\t100000",
        "[newline]\t111111",
        "p\t111110",
        "q\t000001"
    };
    string encoded = 
    "111110000001100100111111100101110001111110";
    cout << decode(codes, encoded);

    return 0;
}