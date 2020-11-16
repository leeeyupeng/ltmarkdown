#include<iostream>
#include<set>
#include"tree/RedBlackTree.h"
using namespace std;
using namespace tree;
int main(){
    set<int> s;
    RedBlackTree<int> rbtree;
    int counter = 1e6;
    int max = 1e9;
    while(counter>0){
        counter--;

        int cmd = rand() % 9;
        if(cmd<=4){
            int value = rand()%max;
            // if(s.find(value)==s.end()){
            //     s.insert(value);
            // }
            if(!rbtree.find(value)){
                rbtree.insert(value);
            }
        }
        else if(cmd == 5){
            // int value = rand()%max;
            // if(s.find(value)==s.end()){
            //     bool f = rbtree.find(value);
            //     if(f == true){
            //         cout<<"error find"<<endl;
            //     }
            // }
            // else{
            //     bool f = rbtree.find(value);
            //     if(f == false){
            //         cout<<"error find"<<endl;
            //     }
            // }

        }
        else if(cmd == 6){
            //continue;

            // int value = rand()%max;
            // bool bstflag = false;
            // bool sflag= false;
            // if(rbtree.find(value)){
            //     rbtree.remove(value);
            //     bstflag = true;
            // }
            // if(s.find(value)!=s.end()){
            //     s.erase(s.find(value));
            //     sflag = true;
            // }
            // if(bstflag!= sflag){
            //     cout<<"error remove"<<endl;
            // }
            // else{
            //     //cout<<"success remove"<<endl;
            // }

            // // if(!rbtree.isbalance()){
            // //     cout<<"error isbalance"<<endl;
            // // }
        }
        else if(cmd == 7){
            // if(s.size() == 0){continue;}
            // int k = rand()%s.size();
            // int num1 = rbtree.find(k);
            // set<int>::iterator ite = s.begin();
            // for(int i = 0; i < k; i ++){
            //     ite++;
            // }
            // int num2 = *ite;
            // if(num1 != num2){
            //     cout<<"error:k:"<<k+1<<" num1:"<< num1<<" num2:"<<num2<<endl;
            // }
            // else{
            //     //cout<<"success:k:"<<k+1<<" num1:"<< num1<<" num2:"<<num2<<endl;
            // }
        }
        else if(cmd == 8){
            // bool check = rbtree.check();
            // if(check==false){
            //     cout<<"error check"<<endl;
            // }
            // else{
            //     cout<<"success check"<<endl;
            // }
        }
    }
    return 0;
}