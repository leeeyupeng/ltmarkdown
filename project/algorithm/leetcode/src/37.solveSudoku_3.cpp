
#include"leetcode.h"

#define N 9
class Solution {
private:
    unsigned int row[N];
    unsigned int col[N];
    unsigned int grid[N/3][N/3];
    int getselect(vector<vector<char>>& board){
        int ij = -1;
        int ans = 10;
        int nums = 0;
        unsigned int bit;
        for(int i = 0; i< N;i++)
        {
            for(int j = 0; j < N;j++){
                if(board[i][j] == '.'){
                    bit = row[i]|col[j]|grid[i/3][j/3];
                    bit = ((1<<N)-1)^bit;
                    nums = 0;
                    while(bit!=0x0){
                        if((bit & 0x1) == 0x1){
                            nums ++;
                        }
                        bit>>=1;
                    }
                    if(nums == 0){return -1;}
                    if(ans>nums){
                        ij = (i<<4)+j;
                        ans = nums;
                    }
                }
            }
        }
        return ij;
    }
    // int getselect(vector<vector<char>>& board){
    //     for(int i = 0; i< N;i++)
    //     {
    //         for(int j = 0; j < N;j++){
    //             if(board[i][j] == '.'){
    //                 return (i<<4)+j;
    //             }
    //         }
    //     }
    //     return -1;
    // }
    bool dfs(vector<vector<char>>& board,int count){
        int ij = getselect(board);
        if(ij == -1){
            return count == 0;
        }
        int i = ij>>4;
        int j = ij - (i<<4);
        unsigned int bit = row[i]|col[j]|grid[i/3][j/3];
        bit = ((1<<N)-1)^bit;
        int index = 0;
        while(bit!=0x0){
            if((bit&0x1) == 0x1){
                board[i][j] = index+'1';
                row[i]|=1<<index;
                col[j]|=1<<index;
                grid[i/3][j/3] |= 1<<index;
                if(dfs(board,count -1)){return true;}
                row[i]&=~(1<<index);
                col[j]&=~(1<<index);
                grid[i/3][j/3] &= ~(1<<index);
            }
            index++;
            bit>>=1;
        }
        board[i][j] = '.';
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {        
        memset(row,0,sizeof(unsigned int)*N);
        memset(col,0,sizeof(unsigned int)*N);
        memset(grid,0,sizeof(unsigned int)*N/3*N/3);
        unsigned int bit;
        unsigned int count = 0;
        for(int i = 0; i< N;i++)
        {
            for(int j = 0; j < N;j++){
                if(board[i][j] != '.'){
                    bit = 1<<(board[i][j]-'1');
                    row[i]|=bit;
                    col[j]|=bit;
                    grid[i/3][j/3]|=bit;
                }else{
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