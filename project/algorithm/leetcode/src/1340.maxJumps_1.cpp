#include"leetcode.h"
class Solution {
    struct Edge{
        int t;
        int next;
        Edge(int _t):t(_t){}
    };
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> vertice(n,-1);
        vector<Edge> edges;
        vector<int> degrees(n,0);
        for(int i = 0; i < n; i ++){
            for(int j = -1; j >= -d; j --){
                if(i + j >= 0 && arr[i+j] < arr[i]){
                    edges.push_back({i});
                    degrees[i] ++;
                    edges.back().next = vertice[i+j];
                    vertice[i+j] = edges.size()-1;
                }
                else{
                    break;
                }
            }

            for(int j = 1; j <= d; j ++){
                if(i + j < n && arr[i+j] < arr[i]){
                    edges.push_back({i});
                    degrees[i] ++;
                    edges.back().next = vertice[i+j];
                    vertice[i+j] = edges.size()-1;
                }
                else{
                    break;
                }
            }
        }

        vector<int> ans(n,1);
        vector<int> *degrees0 = new vector<int>();
        for(int i = 0; i < n; i ++){
            if(degrees[i] == 0){
                degrees0->push_back(i);
            }
        }

        vector<int> *degrees1= new vector<int>();

        while(true){
            int d0n = degrees0->size();
            if(d0n==0){
                break;
            }
            degrees1->clear();
            int tempid;
            int edgeid;
            for(int i = 0; i < d0n; i ++){
                tempid = (*degrees0)[i];
                edgeid = vertice[tempid];
                while(edgeid!=-1){
                    ans[edges[edgeid].t] = max(ans[edges[edgeid].t],ans[tempid] + 1);
                    degrees[edges[edgeid].t]--;
                    if(degrees[edges[edgeid].t]== 0){
                        degrees1->push_back(edges[edgeid].t);
                    }
                    edgeid = edges[edgeid].next;
                }
            }
            swap(degrees0,degrees1);
            degrees1->clear();
        }

        int ret = 1;
        for(int i = 0;i < n; i ++){
            ret = max(ret,ans[i]);
        }
        return ret;
    }
};

// int main()
// {
//     vector<int> arr={
// 6,4,14,6,8,13,9,7,10,6,12
// };

//     Solution solution;
//     int ret = solution.maxJumps(arr,25);
//     return 0;
// }