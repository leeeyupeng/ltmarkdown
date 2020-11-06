#include"leetcode.h"

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        map<int,int> rmap;
        
        for(int i = 0; i < n; i ++){
            rmap[rectangles[i][0]] = 0;
            rmap[rectangles[i][1]] = 0;
            rmap[rectangles[i][2]] = 0;
            rmap[rectangles[i][3]] = 0;
        }
        int counter = 0;
        for(map<int,int>::iterator ite = rmap.begin();ite!=rmap.end(); ite++){
            ite->second = counter++;
        }
        map<int,int>::iterator ite=rmap.end();
        ite--;
        int minx = ite->first,miny = ite->first,maxx=rmap.begin()->first,maxy=rmap.begin()->first;
        for(int i = 0; i < n; i ++){
            minx = min(minx,rectangles[i][0]);
            miny = min(miny,rectangles[i][1]);
            maxx = max(maxx,rectangles[i][2]);
            maxy = max(maxy,rectangles[i][3]);
        }

        int nx = rmap[maxx] - rmap[minx];
        int ny = rmap[maxy] - rmap[miny];
        vector<vector<bool>> rect(nx,vector<bool>(ny));
        for(int i = 0; i < nx; i ++){
            for(int j = 0; j < ny;j ++){
                rect[i][j] = false;
            }
        }
        int iminx,imaxx,jminy,jmaxy;
        int area = 0;
        for(int i = 0; i < n; i ++){
            iminx = rmap[rectangles[i][0]];
            jminy = rmap[rectangles[i][1]];
            imaxx = rmap[rectangles[i][2]];
            jmaxy = rmap[rectangles[i][3]];
            area += (imaxx - iminx) * (jmaxy - jminy);
            for(int ix = iminx;ix<imaxx;ix++){
                for(int jy = jminy;jy < jmaxy; jy++){
                    rect[ix-rmap[minx]][jy - rmap[miny]] = true;
                }
            }
        }
        //有重叠，所有小矩形面积之和是否等于区域的面积
        if(area != nx * ny){return false;}

        //区域内是否有空白，有空白则不是完美矩形
        for(int i = 0; i < nx; i ++){
            for(int j = 0; j < ny;j ++){
                if(rect[i][j] == false){return false;}
            }
        }
        return true;
    }
};

// int main(){
//     Solution solution;
//     vector<vector<int>> rectangles={
//         {0,990,1,991},
//         {0,991,1,992},
//         {0,992,1,993}
//     };
//     bool ans = solution.isRectangleCover(rectangles);
//     return 0;
// }