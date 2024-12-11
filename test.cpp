#include <iostream>
#include <vector>

using namespace std;

struct pos { int row; int col; };
 

vector<vector<int>> rotateMatrix(const vector<vector<int>>& before) {
    int N = before.size();
    vector<vector<int>> after(N, vector<int>(N));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            after[j][N - i - 1] = before[i][j];
        }
    }

    return after;
}


int main() {

    int maxRow, maxColumn;
    cin >> maxRow >> maxColumn;


    vector<vector<pos>> mino = {
        {    // I = 
            {0,0} , {1,0} , {2,0} , {3,0}   
        },
        {    // J = 
            {2,0}, {0,1}, {1,1} , {2,1}
        },
        {    // L = 
            {0,0}, {1,0} , {2,0} , {2,1}
        },
        {    // Z = 
            {0,0}, {0,1} , {1,0} , {1,2}
        },
        {    // S = 
            {1,0}, {1,1} , {0,1} , {0,2}
        },
        {    // T = 
            {1,1}, {0,1} , {1,0} , {1,2}
        },
        {    // O = 
            {0,0}, {0,1} , {1,0} , {1,1}
        }



    };
    vector<vector<int>> transform = {
        // I mino
        {0,0}
    }
    
}