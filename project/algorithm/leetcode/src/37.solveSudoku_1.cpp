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
    inline void removeupdate(int i,int j,unsigned int bit){
        for(int ii = 0; ii < N;ii++){
            record[ii][j] &= (~bit);
        }
        for(int jj = 0; jj < N;jj++){
            record[i][jj] &= (~bit);
        }

        for(int ii = i/3 * 3;ii<i/3 * 3 + 3;ii++){
            for(int jj = j/3 * 3;jj<j/3 * 3+3;jj++){
                record[ii][jj] &= (~bit);
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

    inline unsigned int getzeronums(unsigned int bit){
        unsigned int bit2 = (1<<N)-1;
        bit2 = bit2^bit;
        unsigned int nums = 0;
        while(bit2!=0x0){
            if((bit2 & 0x1) == 0x1){
                nums ++;
            }
            bit2>>=1;
        }
        return nums;
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
    inline int getindexminonenums(vector<vector<char>>& board){
        unsigned int ans = N+1;
        int ij = -1;
        int nums = 0;
        for(int i = 0; i < N; i ++){
            for(int j = 0; j < N;j++){
                if(board[i][j]=='.' ){
                    nums =  getzeronums(record[i][j]);
                    if(nums > 0 && nums < ans){
                        ij = (i << 4) + j;
                        ans = nums;
                    }
                }
            }
        }
        return ij;
    }
    bool dfs(vector<vector<char>>& board,int count){
        int ij = getindexminonenums(board);
        if(ij == -1){
            if(count == 0){
                return true;
            }
            return count == 0;
        }
        unsigned int i = ij>>4;
        unsigned int j = ij - (i<<4);
        unsigned int bit2 = (1<<N)-1;
        bit2 = bit2^record[i][j];
        unsigned int index = 0;
        while(bit2!=0x0){
            if((bit2 & 0x1) == 0x1){
                board[i][j] = index+'1';
                update(i,j,1<<index);
                if(dfs(board,count - 1)){
                    return true;
                }
                removeupdate(i,j,1<<index);
                board[i][j] = '.';
            }
            index ++;
            bit2>>=1;
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {        
        memset(record,0,sizeof(unsigned int)*N*N);
        unsigned int bit;
        unsigned int count = 0;
        for(int i = 0; i< N;i++)
        {
            for(int j = 0; j < N;j++){
                if(board[i][j]!='.'){
                    update(i,j,1<<(board[i][j] - '1'));
                }     
                else{
                    count ++;
                }          
            }
        }

        bool ans = dfs(board,count);
    }
};

// int main(){
//     Solution s;
//     vector<vector<char>> board= {
//         {'.','.','9','7','4','8','.','.','.'},
//         {'7','.','.','.','.','.','.','.','.'},
//         {'.','2','.','1','.','9','.','.','.'},
//         {'.','.','7','.','.','.','2','4','.'},
//         {'.','6','4','.','1','.','5','9','.'},
//         {'.','9','8','.','.','.','3','.','.'},
//         {'.','.','.','8','.','3','.','2','.'},
//         {'.','.','.','.','.','.','.','.','6'},
//         {'.','.','.','2','7','5','9','.','.'}
//     };
//     s.solveSudoku(board);
    
//     return 0;
// }