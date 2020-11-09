// #include<iostream>
// #include"tree/BinarySearchTree.h"
// #include<set>
// using namespace std;
// using namespace tree;

// int main(){

//     BinarySearchTree<int> bst;
//     set<int> s;

//     int counter = 1e6;
//     int max = 1e5;
//     while(counter>0){
//         counter--;

//         int cmd = rand() % 8;
//         if(cmd<=5){
//             int value = rand()%max;
//             if(s.find(value)==s.end()){
//                 bst.insert(value);
//                 s.insert(value);
//             }
//         }
//         else if(cmd == 6){
//             //continue;
//             int value = rand()%max;
//             bool bstflag = false;
//             bool sflag= false;
//             if(bst.find(value)){
//                 bst.remove(value);
//                 bstflag = true;
//             }
//             if(s.find(value)!=s.end()){
//                 s.erase(s.find(value));
//                 sflag = true;
//             }
//             if(bstflag!= sflag){cout<<"error remove"<<endl;}
//         }
//         else if(cmd == 7){
//             if(s.size() == 0){continue;}
//             int k = rand()%s.size();
//             int num1 = bst.get(k);
//             set<int>::iterator ite = s.begin();
//             for(int i = 0; i < k; i ++){
//                 ite++;
//             }
//             int num2 = *ite;
//             if(num1 != num2){
//                 cout<<"error:k:"<<k+1<<" num1:"<< num1<<" num2:"<<num2<<endl;
//             }
//             else{
//                 //cout<<"success:k:"<<k+1<<" num1:"<< num1<<" num2:"<<num2<<endl;
//             }
//         }
//     }
//     return 0;
// }