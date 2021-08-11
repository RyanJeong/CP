#include <string>
#include <vector>

using namespace std;

/*
     0 1 2
    +-----
  0 |1 2 3 
  1 |4 5 6
  2 |7 8 9
  3 |* 0 #
*/
string solution(vector<int> numbers, string hand) 
{
    bool is_right_handed = (hand=="right") ? true : false;
    int l_r = 3; // left row
    int l_c = 0; // left col
    int r_r = 3; // right row
    int r_c = 2; // right col

    string answer = "";
    for (auto i : numbers) {
        switch (i) {
        case 1: case 4: case 7:
            l_r=(i==1) ? 0 : ((i==4) ? 1 : 2);
            l_c=0;
            answer+='L';
            break;
        case 3: case 6: case 9:
            r_r=(i==3) ? 0 : ((i==6) ? 1 : 2);
            r_c=2;
            answer+='R';
            break;
        case 2: case 5: case 8: case 0: {
            int row = (i==2) ? 0 : ((i==5) ? 1 : ((i==8) ? 2 : 3));
            int col = 1;
            int l_dist = abs((row-l_r))+abs((col-l_c));
            int r_dist = abs((row-r_r))+abs((col-r_c));
            if (l_dist>r_dist) {
                r_r=row;
                r_c=col;
                answer+='R';
            } 
            else if (l_dist<r_dist) {
                l_r=row;
                l_c=col;
                answer+='L';
            } 
            else {
                r_r=(is_right_handed) ? row : r_r;
                r_c=(is_right_handed) ? col : r_c;
                l_r=(is_right_handed) ? l_r : row;
                l_c=(is_right_handed) ? l_c : col;
                answer+=(is_right_handed) ? 'R' : 'L';
            }
            break;
        }
        default:
            break;
        }
    }

    return answer;
}