#include"leetcode.h"

class Solution {
private:
    inline int find(vector<int> &us,vector<int> &usstack,int index){
        if(us[index] == index){return us[index];}
        int pp;
        int top = -1;
        while(us[index]!=index){
            usstack[++top] = index;
            index = us[index];
        }
        pp = us[usstack[top]];
        while(top != -1){
            us[usstack[top--]] = pp;
        }
        return pp;
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> usalice(n+1,0);
        vector<int> usbob(n+1,0);
        vector<int> usstack(n+1);
        for(int i = 0; i <= n; i ++){usalice[i] = i;usbob[i] = i;}
        int counterremove = 0;
        int counteralice = 0;
        int counterbob = 0;
        int aalice,balice,abob,bbob;
        for(int i = 0;i<m; i ++){
            if(edges[i][0] == 3){
                aalice = find(usalice,usstack,edges[i][1]);
                balice = find(usalice,usstack,edges[i][2]);
                abob = find(usbob,usstack,edges[i][1]);
                bbob = find(usbob,usstack,edges[i][2]);

                if(aalice!=balice || abob != bbob){
                    if(aalice!=balice){
                        usalice[balice] = aalice;
                        counteralice++;
                    }
                    if(abob!=bbob){
                        usbob[bbob] = abob;
                        counterbob++;
                    }
                }
                else{
                    counterremove ++;
                }
            }
        }

        for(int i = 0;i<m; i ++){
            if(edges[i][0] == 1){
                aalice = find(usalice,usstack,edges[i][1]);
                balice = find(usalice,usstack,edges[i][2]);
                if(aalice!=balice){
                    usalice[balice] = aalice;
                    counteralice++;
                }
                else{
                    counterremove ++;
                }
            }
            else if(edges[i][0] == 2){
                abob = find(usbob,usstack,edges[i][1]);
                bbob = find(usbob,usstack,edges[i][2]);
                if(abob!=bbob){
                    usbob[bbob] = abob;
                    counterbob++;
                }
                else{
                    counterremove ++;
                }
            }
        }

        if(counteralice != n -1 || counterbob != n-1){
            return -1;
        }

        return counterremove;
    }
};