#pragma once
#define BOARDROW 20
#define BOARDCOL 20
#define Five 5

class fivechess
{
public:
    enum GridType:char{
        None='o',
        Black='B',
        White='W',
    };
    //游戏继续，黑方赢得比赛，白方赢得比赛 平局
    enum GameResult:char{        
        Going='G',
        NoneWin='N',
        BlackWin='B',
        WhiteWin='W',        
        Drawing='D',
    };
private:
    GridType board[BOARDROW][BOARDCOL];
public:
    int getrow(){return BOARDROW;}
    int getcol(){return BOARDCOL;}
    GridType get(int i,int j){
        return board[i][j];
    }
    void set(int i,int j,GridType gridType){
        board[i][j] = gridType;
    }
    void going(int i,int j,GridType gridType){
        set(i,j,gridType);
    }
    void init(){
        for(int i = 0; i < BOARDROW; i ++){
            for(int j = 0; j < BOARDCOL;j ++){
                board[i][j] = GridType::None;
            }
        }
    }
    
    GameResult judge(){
        GameResult result = judgerow();
        if(result!=GameResult::NoneWin){return result;}
        result = judgecol();
        if(result!=GameResult::NoneWin){return result;}
        result = judgedown();
        if(result!=GameResult::NoneWin){return result;}
        result = judgeup();
        if(result!=GameResult::NoneWin){return result;}
        int nonenums = getnonenums();
        if(nonenums == 0){return GameResult::Drawing;}
        return GameResult::Going;
    }
private:
    GameResult judgerow(){
        int dp[BOARDROW][BOARDCOL];
        for(int i = 0; i < BOARDROW;i++){
            dp[i][0] = board[i][0]==GridType::None?0:1;
            for(int j = 1; j < BOARDCOL;j++){
                if(board[i][j]!=GridType::None){
                    if(board[i][j] == board[i][j-1]){
                        dp[i][j] = dp[i][j-1] + 1;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        int blacknums = 0;
        int whitenums = 0;
        for(int i = 0; i < BOARDROW;i++){
            for(int j = 0; j < BOARDCOL;j++){
                if(board[i][j] == GridType::Black){
                    blacknums = max(blacknums,dp[i][j]);
                }
                else if(board[i][j] == GridType::White){
                    whitenums = max(whitenums,dp[i][j]);
                }
            }
        }
        if(blacknums >= Five){return GameResult::BlackWin;}
        else if(whitenums >= Five){return GameResult::WhiteWin;}
        return GameResult::NoneWin;
    }

    GameResult judgecol(){
        int dp[BOARDROW][BOARDCOL];        
        for(int j = 0; j < BOARDCOL;j++){
            dp[0][j] = board[0][j]==GridType::None?0:1;
            for(int i = 1; i < BOARDROW;i++){
                if(board[i][j]!=GridType::None){
                    if(board[i][j] == board[i][j-1]){
                        dp[i][j] = dp[i][j-1] + 1;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        int blacknums = 0;
        int whitenums = 0;
        for(int j = 0; j < BOARDCOL;j++){
            for(int i = 0; i < BOARDROW;i++){            
                if(board[i][j] == GridType::Black){
                    blacknums = max(blacknums,dp[i][j]);
                }
                else if(board[i][j] == GridType::White){
                    whitenums = max(whitenums,dp[i][j]);
                }
            }
        }
        if(blacknums >= Five){return GameResult::BlackWin;}
        else if(whitenums >= Five){return GameResult::WhiteWin;}
        return GameResult::NoneWin;
    }

    GameResult judgedown(){
        int dp[BOARDROW][BOARDCOL];
        for(int i = 0; i < BOARDROW;i++){        
            for(int j = 0; j < BOARDCOL;j++){
                if(board[i][j]!=GridType::None){
                    if(i>0&&j>0&&board[i][j] == board[i-1][j-1]){
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        int blacknums = 0;
        int whitenums = 0;
        for(int i = 0; i < BOARDROW;i++){ 
            for(int j = 0; j < BOARDCOL;j++){                       
                if(board[i][j] == GridType::Black){
                    blacknums = max(blacknums,dp[i][j]);
                }
                else if(board[i][j] == GridType::White){
                    whitenums = max(whitenums,dp[i][j]);
                }
            }
        }
        if(blacknums >= Five){return GameResult::BlackWin;}
        else if(whitenums >= Five){return GameResult::WhiteWin;}
        return GameResult::NoneWin;
    }

    GameResult judgeup(){
        int dp[BOARDROW][BOARDCOL];
        for(int i = BOARDROW - 1; i >= 0;i--){        
            for(int j = 0; j < BOARDCOL;j++){
                if(board[i][j]!=GridType::None){
                    if(i+1<BOARDROW&&j>0&&board[i][j] == board[i+1][j-1]){
                        dp[i][j] = dp[i+1][j-1] + 1;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        int blacknums = 0;
        int whitenums = 0;
        for(int i = 0; i < BOARDROW;i++){ 
            for(int j = 0; j < BOARDCOL;j++){                       
                if(board[i][j] == GridType::Black){
                    blacknums = max(blacknums,dp[i][j]);
                }
                else if(board[i][j] == GridType::White){
                    whitenums = max(whitenums,dp[i][j]);
                }
            }
        }
        if(blacknums >= Five){return GameResult::BlackWin;}
        else if(whitenums >= Five){return GameResult::WhiteWin;}
        return GameResult::NoneWin;
    }

    int getnonenums(){
        int nonenums = 0;
        for(int i = 0; i < BOARDROW;i++){
            for(int j = 0; j < BOARDCOL;j++){
                if(board[i][j] == GridType::None){nonenums++;}
            }
        }
        return nonenums;
    }
};
