// #include<iostream>
// #include<set>
// #include"tree/AVLTree3.h"
// using namespace std;
// using namespace tree;
// int main(){
//     set<int> s;
//     AVLTree<int> avltree;
//     int counter = 1e6;
//     int max = 1e5;
//     while(counter>0){
//         counter--;

//         int cmd = rand() % 9;
//         if(cmd<=5){
//             int value = rand()%max;
//             if(s.find(value)==s.end()){
//                 avltree.insert(value);
//                 s.insert(value);
//             }
//         }
//         else if(cmd == 6){
//             //continue;

//             int value = rand()%max;
//             bool bstflag = false;
//             bool sflag= false;
//             if(avltree.find(value)){
//                 avltree.remove(value);
//                 bstflag = true;
//             }
//             if(s.find(value)!=s.end()){
//                 s.erase(s.find(value));
//                 sflag = true;
//             }
//             if(bstflag!= sflag){
//                 cout<<"error remove"<<endl;
//             }
//             else{
//                 //cout<<"success remove"<<endl;
//             }

//             // if(!avltree.isbalance()){
//             //     cout<<"error isbalance"<<endl;
//             // }
//         }
//         else if(cmd == 7){
//             // if(s.size() == 0){continue;}
//             // int k = rand()%s.size();
//             // int num1 = avltree.find(k);
//             // set<int>::iterator ite = s.begin();
//             // for(int i = 0; i < k; i ++){
//             //     ite++;
//             // }
//             // int num2 = *ite;
//             // if(num1 != num2){
//             //     cout<<"error:k:"<<k+1<<" num1:"<< num1<<" num2:"<<num2<<endl;
//             // }
//             // else{
//             //     //cout<<"success:k:"<<k+1<<" num1:"<< num1<<" num2:"<<num2<<endl;
//             // }
//         }
//         else if(cmd == 8){
//             // if(avltree.isbalance()){
//             //     //cout<<"success isbalance"<<endl;
//             // }
//             // else{
//             //     cout<<"error isbalance"<<endl;
//             // }
//         }
//     }
//     return 0;
// }