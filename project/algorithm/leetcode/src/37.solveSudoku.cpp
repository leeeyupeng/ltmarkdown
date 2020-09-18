#include"leetcode.h"

#define N 9
class Solution {
private:
    unsigned int record[N][N];
    inline void update(int i,int j,unsigned int bit){
        for(int ii = 0; ii < N;ii++){
            record[ii][j] |= bit;
        }
        for(int jj = 0; jj < N;jj++){
            record[i][jj] |= bit;
        }

        for(int ii = i/3 * 3;ii<i/3 * 3 + 3;ii++){
            for(int jj = j/3 * 3;jj<j/3 * 3+3;jj++){
                record[ii][jj] |= bit;
            }
        }
    }
    inline bool isonlyzero(unsigned int bit){
        unsigned int bit2 = (1<<N)-1;
        bit2 = bit2^bit;
        if(bit2 == 0x0){
            return false;
        }
        return (bit2 & (bit2 - 1)) == 0x0;
    }
    inline unsigned int getonlyzero(unsigned int bit){
        unsigned int bit2 = (1<<N)-1;
        bit2 = bit2^bit;
        unsigned int index = 0;
        while((bit2 & 0x1) != 0x1){
            index ++;
            bit2>>=1;
        }
        return index;
    }

    inline void updatequeue(vector<vector<char>>& board,queue<unsigned int>& q,int i,int j){
        for(int ii = 0; ii < N;ii++){
            if(board[ii][j]=='.' && isonlyzero(record[ii][j])){q.push((ii<<4) + j);}
        }
        for(int jj = 0; jj < N;jj++){
            if(board[i][jj]=='.' && isonlyzero(record[i][jj])){q.push((i<<4) + jj);}
        }

        for(int ii = i/3 * 3;ii<i/3 * 3 + 3;ii++){
            for(int jj = j/3 * 3;jj<j/3 * 3+3;jj++){
                if(board[ii][jj]=='.' && isonlyzero(record[ii][jj])){q.push((ii<<4) + jj);}
            }
        }
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

        queue<unsigned int> q;
        for(int i = 0;i < N;i++){
            for(int j = 0; j < N;j++){
                if(board[i][j]=='.' && isonlyzero(record[i][j])){
                    q.push((i<<4) + j);
                }
            }
        }

        int i,j;
        unsigned int index;
        while(!q.empty()){
            i = q.front() >> 4;
            j = q.front() - (i<<4);
            q.pop();
            if(board[i][j] !='.'){continue;}
            index = getonlyzero(record[i][j]);
            board[i][j] = index+'1';
            update(i,j,1<<index);
            updatequeue(board,q,i,j);
        }
    }
};

// int main(){
//     Solution s;
//     vector<vector<char>> board= {
//         {'5','3','.','.','7','.','.','.','.'},
//         {'6','.','.','1','9','5','.','.','.'},
//         {'.','9','8','.','.','.','.','6','.'},
//         {'8','.','.','.','6','.','.','.','3'},
//         {'4','.','.','8','.','3','.','.','1'},
//         {'7','.','.','.','2','.','.','.','6'},
//         {'.','6','.','.','.','.','2','8','.'},
//         {'.','.','.','4','1','9','.','.','5'},
//         {'.','.','.','.','8','.','.','7','9'}
//     };
//     s.solveSudoku(board);
    
//     return 0;
// }