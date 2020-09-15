#include"leetcode.h"

#define N 9
class Solution {
private:
    unsigned int record[N][N];
    void update(int i,int j,unsigned int bit){
        for(int ii = 0; ii < N;ii++){
            record[ii][j] |= bit;
        }
        for(int jj = 0; jj < N;jj++){
            record[i][jj] |= bit;
        }

        for(int ii = i/3 * 3;ii<i/3 * 3 + 3;ii++){
            for(int jj = j/3 * 3;jj<j/3 * 3+3;j++){
                record[ii][jj] |= bit;
            }
        }
    }
    bool onlyzero(unsigned int bit){
        unsigned int b = (1<<10)-1;
        b = b^bit;
        return b&(b-1);
    }
    unsigned int getonlyzero(unsigned int bit){

    }
public:
    void solveSudoku(vector<vector<char>>& board) {        
        memset(record,0,sizeof(unsigned int)*N*N);
        unsigned int bit;
        for(int i = 0; i< N;i++)
        {
            for(int j = 0; j < N;j++){
                if(board[i][j]!='.'){
                    update(i,j,1<<(board[i][j] - '1'));
                }               
            }
        }

        for(int i = 0;i < N;i++){
            for(int j = 0; j < N;j++){
                
            }
        }
    }
};