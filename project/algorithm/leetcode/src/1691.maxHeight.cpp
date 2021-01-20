#include"leetcode.h"

#define MAX 100
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<vector<int>>* dpdown0 = new vector<vector<int>>(MAX+1,vector<int>(MAX+2,0));
        vector<vector<int>>* dpup0=new vector<vector<int>>(MAX+1,vector<int>(MAX+2,0));
        vector<vector<int>>* dpdown = new vector<vector<int>>(MAX+1,vector<int>(MAX+2,0));
        vector<vector<int>>* dpup=new vector<vector<int>>(MAX+1,vector<int>(MAX+2,0));
        int w,l,h;
        for(int k = 0; k < n; k ++){
            for(int i = 1; i <= MAX; i ++){
                for(int j = 1; j <= MAX;j ++){
                    (*dpdown)[i][j] = max((*dpdown)[i-1][j],(*dpdown)[i][j-1]);
                    w = 0;l = 1;h = 2;
                    if(cuboids[k][w]<=i&&cuboids[k][l]<=j){
                        (*dpdown)[i][j] = max((*dpdown)[i][j],(*dpdown0)[cuboids[k][w]][cuboids[k][l]] + cuboids[k][h] + (*dpup0)[cuboids[k][w]][cuboids[k][l]]);
                    }
                    w = 1;l = 0;h = 2;
                    if(cuboids[k][w]<=i&&cuboids[k][l]<=j){
                        (*dpdown)[i][j] = max((*dpdown)[i][j],(*dpdown0)[cuboids[k][w]][cuboids[k][l]] + cuboids[k][h] + (*dpup0)[cuboids[k][w]][cuboids[k][l]]);
                    }
                    w = 0;l = 2;h = 1;
                    if(cuboids[k][w]<=i&&cuboids[k][l]<=j){
                        (*dpdown)[i][j] = max((*dpdown)[i][j],(*dpdown0)[cuboids[k][w]][cuboids[k][l]] + cuboids[k][h] + (*dpup0)[cuboids[k][w]][cuboids[k][l]]);
                    }
                    w = 2;l = 0;h = 1;
                    if(cuboids[k][w]<=i&&cuboids[k][l]<=j){
                        (*dpdown)[i][j] = max((*dpdown)[i][j],(*dpdown0)[cuboids[k][w]][cuboids[k][l]] + cuboids[k][h] + (*dpup0)[cuboids[k][w]][cuboids[k][l]]);
                    }
                    w = 1;l = 2;h = 0;
                    if(cuboids[k][w]<=i&&cuboids[k][l]<=j){
                        (*dpdown)[i][j] = max((*dpdown)[i][j],(*dpdown0)[cuboids[k][w]][cuboids[k][l]] + cuboids[k][h] + (*dpup0)[cuboids[k][w]][cuboids[k][l]]);
                    }
                    w = 2;l = 1;h = 0;
                    if(cuboids[k][w]<=i&&cuboids[k][l]<=j){
                        (*dpdown)[i][j] = max((*dpdown)[i][j],(*dpdown0)[cuboids[k][w]][cuboids[k][l]] + cuboids[k][h] + (*dpup0)[cuboids[k][w]][cuboids[k][l]]);
                    }
                }
            }

            for(int i = MAX; i > 0; i --){
                for(int j = MAX;j > 0; j --){
                    (*dpup)[i][j] = max((*dpup)[i+1][j],(*dpup)[i][j+1]);
                    w = 0;l = 1;h = 2;
                    if(cuboids[k][w]>=i&&cuboids[k][l]>=j){
                        (*dpup)[i][j] = max((*dpup)[i][j],(*dpup0)[cuboids[k][w]][cuboids[k][l]] + cuboids[k][h] + (*dpup0)[cuboids[k][w]][cuboids[k][l]]);
                    }
                }
            }
            
            swap(dpdown0,dpdown);
            swap(dpup0,dpup);
        }
    }
};