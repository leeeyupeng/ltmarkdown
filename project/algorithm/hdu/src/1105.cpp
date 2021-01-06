#include"hdu.h"

class Solution{
private:
    int move[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int r,c;
    vector<vector<char>> grids;
    unordered_set<unsigned int> us;
    unordered_set<unsigned int> usw;
    inline unsigned int get(char wolves[3][2],char sheep[2]){
        unsigned int key = 0;
        key += wolves[0][0];
        key*=10;
        key += wolves[0][1];
        key*=10;
        key += wolves[1][0];
        key*=10;
        key += wolves[1][1];
        key*=10;
        key += wolves[2][0];
        key*=10;
        key += wolves[2][1];
        key*=10;
        key += sheep[0];
        key*=10;
        key += sheep[1];
        return key;
    }
    inline bool isout(char pos[2]){
        if(pos[0]<0||pos[0]>=r || pos[1]<0||pos[1]>=c){return true;}
        return false;
    }    
    inline bool isobstacle(char pos[2]){
        if(grids[pos[0]][pos[1]]=='X'){return true;}
        return false;
    }
    inline bool islegal(char pos[2]){
        if(pos[0]<0||pos[0]>=r || pos[1]<0||pos[1]>=c){return false;}
        if(grids[pos[0]][pos[1]]=='X'){return false;}
        return true;
    }
    inline bool iscover(char wolves[3][2],char sheep[2],char pos[2])
    {
        int nums = 0;
        for(int i = 0; i < 3; i++){
            if(wolves[i][0] == pos[0] && wolves[i][1] == pos[1]){nums++;}
        }
        if(sheep[0] == pos[0] && sheep[1] == pos[1]){nums++;}
        return nums != 1;
    }
    int dfs(char wolves[3][2],char sheep[2],char roundwolve){
        int ret;
        if(roundwolve==1){
            unsigned int key = get(wolves,sheep);
            if(usw.find(key) != usw.end()){
                return 0;
            }            
            usw.insert(key);
            ret = 1;
            bool ismove = false;
            for(int i = 0; i < 3; i ++){
                for(int j = 0; j < 4; j ++){
                    wolves[i][0] += move[j][0];
                    wolves[i][1] += move[j][1];
                    if(islegal(wolves[i]) && !iscover(wolves,sheep,wolves[i])){
                        ret = dfs(wolves,sheep,0);
                        ismove = true;
                        if(ret==-1){break;}
                        
                    }
                    wolves[i][0] -= move[j][0];
                    wolves[i][1] -= move[j][1];
                }
                if(ret==-1){break;}
            }
            if(ismove==false){
                ret = dfs(wolves,sheep,!roundwolve);
            }
            return ret;
        }
        else{
            // int key = get(wolves,sheep);
            // if(us.find(key) != us.end()){
            //     return 0;
            // }            
            // us.insert(key);
            ret = -1;
            for(int j = 0; j < 4; j ++){
                sheep[0] += move[j][0];
                sheep[1] += move[j][1];
                if(isout(sheep)){return 1;}
                if(!isobstacle(sheep) && !iscover(wolves,sheep,sheep)){
                    ret = dfs(wolves,sheep,1);
                    if(ret==1){break;}
                }
                sheep[0] -= move[j][0];
                sheep[1] -= move[j][1];
            }
            
            return ret;
        }
    }
public:
    bool Solve(int r,int c,vector<vector<char>>& grids,char wolves[3][2],char sheep[2]){
        this->r = r;
        this->c = c;
        this->grids = grids;
        us.clear();
        usw.clear();
        return dfs(wolves,sheep,1);
    }
};

// int main(){
//     int r,c;
//     Solution solution;
//     while(scanf("%d%d",&r,&c)!=EOF){
//         vector<vector<char>> grids(r,vector<char>(c,'.'));
//         char wolves[3][2];
//         char sheep[2];
//         int wolvenums = 0;
//         char cc;
//         scanf("%c",&cc);
//         for(int i = 0; i < r; i ++){
//             for(int j = 0; j < c; j ++){
//                 scanf("%c",&grids[i][j]);
//                 if(grids[i][j] == 'S'){
//                     sheep[0] = i;
//                     sheep[1] = j;
//                     grids[i][j]='.';
//                 }
//                 else if(grids[i][j] == 'W'){
//                     wolves[wolvenums][0] = i;
//                     wolves[wolvenums][1] = j;
//                     wolvenums++;
//                     grids[i][j]='.';
//                 }
//             }
//             scanf("%c",&cc);
//         }
//         int ret = solution.Solve(r,c,grids,wolves,sheep);
//         printf(ret!=-1?"Lucky Mmxl is safe:)\n":"Poor Mmxl is in danger:(\n");
//     }
//     return 0;
// }