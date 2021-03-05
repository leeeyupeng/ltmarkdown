#include<iostream>
#include<string>
#include<queue>
using namespace std;

#include"Lexer.hpp"
int main(int argc,char* argv[]){
    cout<<"hello script"<<endl;
    string inpath = argv[1];
    cout<<argv[1]<<endl;
    ifstream infile;
    infile.open(argv[1],ios::in);
    // string sline;
    // getline(infile,sline);
    // cout<<sline<<endl;
    Lexer lexer(infile);
    queue<Token> q;
    while(lexer.peek(0).tokentype != Token::TokenType::TOKENEOF){
        q.push(lexer.read());
    }
    
    Token front;
    while(!q.empty()){
        front = q.front();
        q.pop();
        cout<< front.tostring() <<endl;
    }
    cout<<"bye script"<<endl;

    return 0;
}