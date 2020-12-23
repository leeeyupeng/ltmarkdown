#include"hdu.h"

class Solution {
private:
    int n;
    vector<int> hamilton(vector<vector<int>>& matrix,int& head,int& end){
        vector<int> path(n);
        vector<int> pathreverse(n);
        for(int i = 0; i < n; i ++){
            path[i] = i;
            pathreverse[i] = i;
        }
        path[head] = end;
        pathreverse[end] = head;
        for(int i = 2; i < n; i ++){
            if(matrix[end][i] == 1){
                if(matrix[i][head] == 1){
                    path[end] = i;
                    pathreverse[i] = end;
                    end = i;
                }
                else{
                    int index = pathreverse[end];
                    int indexlast = end;
                    bool flag = false;
                    while(pathreverse[index]!=index){
                        if(matrix[index][i]==1 && matrix[i][indexlast] == 1){
                            pathreverse[i] = pathreverse[path[index]];
                            pathreverse[path[index]] = i;

                            path[i] = path[index];
                            path[index] = i;  
                            flag = true;
                            break;                          
                        }
                        indexlast = index;
                        if(pathreverse[index]==index){break;}
                        index = pathreverse[index];
                    }
                    if(flag==false){
                        path[end] = i;
                        pathreverse[i] = end;
                        end = i;
                    }
                }
            }
            else{
                 int index = pathreverse[end];
                bool flag = false;
                 while(true){
                    if(matrix[index][i]==1){
                        pathreverse[i] = pathreverse[path[index]];
                        pathreverse[path[index]] = i;

                        path[i] = path[index];
                        path[index] = i;  
                        flag = true;
                        break;                          
                    }
                    if(pathreverse[index]==index){break;}
                    index = pathreverse[index];
                }
                 if(flag==false){
                    path[i] = head;
                    pathreverse[head] = i;
                    head = i;
                }
            }
        }
        return path;
    }
public:
    bool router(int n,vector<vector<int>>& matrix,vector<int>& ret){
        this->n = n;
        int head=0,end=1;
        if(matrix[1][0] == 1){
            head = 1,end = 0;
        }

        vector<int> path = hamilton(matrix,head,end);
        int s = 0;
        int nums = 0;
        for(int i = 0; i < n; i ++){
            if(path[i] == i){
                s = i;
                nums++;
            }
        }
        
        if(nums!=1){return false;}
        s = head;
        int i = 0;
        while(path[s]!=s){
            ret[i] = s;
            s = path[s];
            i++;
        }
        ret[i] = s;

        if(matrix[ret[n-1]][ret[0]] == 1){
            return true;
        }
        else{
            return false;
        }
    }
};

// bool check(vector<vector<int>>& matrix,vector<int>& path){
//     int n = path.size();
//     int i = 0;
//     for(int i = 1; i < n; i ++){
//         if(matrix[path[i-1]][path[i]] == 0){
//             return false;
//         }
//     }
//     if(matrix[path[n-1]][path[0]] == 0){
//         return false;
//     }
//     return true; 
// }
// int main(){
//     Solution solution;
//     int n;
//     while(scanf("%d",&n)){
//         if(n==0){break;}
        
//         vector<vector<int>> matrix(n,vector<int>(n,0));
//         int temp;
//         for(int i = 0; i < n; i ++){
//             for(int j = 0; j < n; j ++){
//                 // int r = rand() % 2;
//                 // matrix[i][j] = r;
//                 // matrix[j][i] = r==1?0:1;
//                 scanf("%d",&matrix[i][j]);                
//             }
//         }
//         if(n == 1){ printf("1\n");continue; }
//         vector<int> path(n);
//         bool ret = solution.router(n,matrix,path);

//         if(ret){
//             // if(check(matrix,path) == true){
//             //     printf("true\n");
//             // }
//             // else{
//             //     printf("false\n");   
//             //     for(int i = 0; i < n; i ++){
//             //         for(int j = 0; j < n; j ++){ 
//             //             printf("%d ",matrix[i][j]);              
//             //         }
//             //         printf("\n");
//             //     }
//             //     printf("\n");             
//             // }
//             string out;
//             out+=std::to_string(path[0] + 1);
//             for(int i = 1; i < n; i ++){
//                 out+=" " + std::to_string(path[i] + 1);
//             }
//             out+="\n";
//             printf("%s",out.c_str());
//             // printf("%d",path[0] + 1);
//             // for(int i = 1; i < n; i ++){
//             //     printf(" %d",path[i] + 1);
//             // }
//             // printf("\n");
//         }
//         else{
//             printf("%d\n",-1);
//         }
//     }
//     return 0;
// }