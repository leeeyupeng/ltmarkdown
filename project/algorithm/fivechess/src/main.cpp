#include<iostream>
#include<unordered_map>
using namespace std;
#include"fivechess.h"
enum ecommand:char{
    init,
    going,
    judge,
    print,

    quit,
};
int main(){
    fivechess chess;
    chess.init();
    unordered_map<string,ecommand> commandhash;
    commandhash["init"] = ecommand::init;
    commandhash["going"] = ecommand::going;
    commandhash["judge"] = ecommand::judge;
    commandhash["print"] = ecommand::print;
    
    commandhash["quit"] = ecommand::quit;
    unordered_map<string,fivechess::GridType> sidehash;
    sidehash["Black"] = fivechess::GridType::Black;
    sidehash["White"] = fivechess::GridType::White;

    string command;
    string side;
    int x,y;
    fivechess::GameResult gameResult;
    char tab = ' ';
    while(true){
        cin>>command;
        if(commandhash.find(command) == commandhash.end()){
            cout<<"command error"<<endl;
            continue;
        }
        if(commandhash[command] == ecommand::quit){break;}
        switch (commandhash[command])
        {
        case ecommand::init:
            chess.init();
            break;
        case ecommand::going:
            cin>>side;
            if(sidehash.find(side) == sidehash.end()){
                cout<<"side error";
            }
            cin>>x>>y;
            x--,y--;
            if(x>chess.getrow() || y > chess.getcol()){
                cout<<"x,y error";
            }
            chess.going(x,y,sidehash[side]);
            break;
        case ecommand::judge:
            gameResult= chess.judge();
            cout<<"GameResult:"<<(char)gameResult<<endl;
            break;
        case ecommand::print:            
            cout<<'0'<<tab;
            for(int j = 0; j < chess.getcol(); j ++){
                cout<<j%10;
                cout<<tab;
            }
            cout<<endl;
            for(int i = 0; i < chess.getrow(); i ++){
                cout<<i%10<<tab;
                for(int j = 0; j < chess.getcol(); j ++){
                    cout<<(char)chess.get(i,j);
                    cout<<tab;
                }
                cout<<endl;
            }
            break;
        default:
            break;
        }


    }
    return 0;
}
