#pragma once
#include<iostream>
#include"fivechess.h"
using namespace std;
class fivechessai{
private:
    fivechess chess;
public:
    void init(fivechess _chess){
        chess = _chess;
    }

    fivechess::GameResult dfs(fivechess::GridType side){
        fivechess::GameResult result = fivechess::GameResult::NoneWin;
        fivechess::GameResult temp;
        for(int i = 0; i < chess.getrow();i++){
            for(int j = 0; j < chess.getcol();j++){
                if(chess.get(i,j)==fivechess::GridType::None){
                    chess.set(i,j,side);
                    temp = chess.judge();
                    chess.set(i,j,fivechess::GridType::None);
                    if(side ==fivechess::GridType::Black){
                        if(temp == fivechess::GameResult::BlackWin){
                            result = temp;
                            return result;
                        }
                        else if(temp == fivechess::GameResult::Drawing){
                            result = temp;
                        }
                        else if(result == fivechess::GameResult::NoneWin){                            
                            result = temp;
                        }
                    }
                    else if(side == fivechess::GridType::White){

                    }
                }
            }
        }
        return result;
    }
    pair<int,int> getstep(fivechess::GridType side){
        
    }
};