#include"leetcode.h"

#define N 9
class Solution {
private:
    unsigned int record[N][N];
    unsigned int rr[N][N];
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
    pair<int,unsigned int> getindexminonenums(){
        memset(rr,0,sizeof(unsigned int)*N*N);
        for(int i = 0; i< N;i++)
        {
            for(int j = 0; j < N;j++){
                if(record[i][j] != 0){
                    unsigned int bit = record[i][j];
                    for(int ii = 0; ii < N;ii++){
                        rr[ii][j] |= bit;
                    }
                    for(int jj = 0; jj < N;jj++){
                        rr[i][jj] |= bit;
                    }

                    for(int ii = i/3 * 3;ii<i/3 * 3 + 3;ii++){
                        for(int jj = j/3 * 3;jj<j/3 * 3+3;jj++){
                            rr[ii][jj] |= bit;
                        }
                    }
                }
            }
        }

        unsigned int ans = N+1;
        int ij = -1;
        unsigned int bit = 0;
        int nums = 0;
        for(int i = 0; i < N; i ++){
            for(int j = 0; j < N;j++){
                if(record[i][j]==0x0 ){
                    nums =  getzeronums(rr[i][j]);
                    if(nums == 0){return {-1,0};}
                    if(nums < ans){
                        ij = (i << 4) + j;
                        ans = nums;
                        bit = rr[i][j];
                    }
                }
            }
        }
        return {ij,bit};
    }
    bool dfs(vector<vector<char>>& board,int count){
        pair<int,unsigned int> minone = getindexminonenums();
        int ij = minone.first;
        if(ij== -1){
            if(count == 0){
                return true;
            }
            return count == 0;
        }
        unsigned int i = ij>>4;
        unsigned int j = ij - (i<<4);
        unsigned int bit2 = (1<<N)-1;
        bit2 = bit2^minone.second;
        unsigned int index = 0;
        while(bit2!=0x0){
            if((bit2 & 0x1) == 0x1){
                board[i][j] = index+'1';
                record[i][j] = 1<<index;
                if(dfs(board,count - 1)){
                    return true;
                }
            }
            index ++;
            bit2>>=1;
        }
        record[i][j] = 0x0;
        board[i][j] = '.';
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
                    record[i][j] = 1<<(board[i][j] - '1');
                }     
                else{
                    record[i][j] = 0x0;
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