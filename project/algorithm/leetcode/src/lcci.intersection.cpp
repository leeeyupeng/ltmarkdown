#include"leetcode.h"

class Solution {
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        double x,y;
        if(start1[0] == end1[0] && start2[0] == end2[0]){
            if(start1[0] == start2[0]){
                x = start1[0];
                y = max(min(start1[1],end1[1]),min(start2[1],end2[1]));
            }
            else{
                return {};
            }
        }
        else if(start1[0] == end1[0]){
            x = start1[0];
            y = 1.0f * (end2[1] - start2[1]) * (x - start2[0]) / (end2[0] - start2[0])  + start2[1];
        }
        else if(start2[0] == end2[0]){
            x = start2[0];
            y = 1.0f * (end1[1] - start1[1]) * (x - start1[0]) / (end1[0] - start1[0])  + start1[1];
        }
        else{
            double slop1 = 1.0f * (end1[1]-start1[1]) / (end1[0] - start1[0]);
            double slop2 = 1.0f * (end2[1]-start2[1]) / (end2[0] - start2[0]);
            double slop = 1.0f * ((end1[1]-start1[1]) * (end2[0] - start2[0]) + (end2[1]-start2[1]) * (end1[0] - start1[0])) / ((end1[0] - start1[0]) * (end2[0] - start2[0]));
            if(slop1 == slop2){
                if(start2[0] == start1[0] || (start2[1] - start1[1]) / (start2[0] - start1[0]) == slop1){
                    x = max(min(start1[0],end1[0]),min(start2[0],end2[0]));
                    if(x == start1[0]){y = start1[1];}
                    else if(x == end1[0]){y = end1[1];}      
                    else if(x == start2[0]){y = start2[1];}    
                    else if(x == end2[0]){y = end2[1];}             
                }
                else{
                    return {};
                }
            }
            else{
                x=(end2[1]-start2[1]) * (end1[0] - start1[0]) * start2[0] 
                - (end1[1] - start1[1]) * (end2[0] - start2[0]) * start1[0] 
                - (end1[0] - start1[0])*(end2[0] - start2[0])*start2[1]
                + (end1[0] - start1[0])*(end2[0] - start2[0])*start1[1];
                x*=((end1[0] - start1[0]) * (end2[0] - start2[0]));
                x/=((end1[0] - start1[0])*(end2[0] - start2[0]))*((end2[1]-start2[1]) * (end1[0] - start1[0])-(end1[1]-start1[1]) * (end2[0] - start2[0]));
                if(start1[1] == end1[1]){
                    y = start1[1];
                }
                else if(start2[1] == end2[1]){
                    y = start2[1];
                }
                else{
                    y = 1.0f * (end2[1] - start2[1]) * (x - start2[0]) / (end2[0] - start2[0])  + start2[1];
                }
            }
        }
        double epi = 10e-6;
        if(x>=min(start1[0],end1[0])-epi && x <= max(start1[0],end1[0]) + epi
        &&y>=min(start1[1],end1[1])-epi && y <= max(start1[1],end1[1])+ epi
        &&x>=min(start2[0],end2[0])-epi && x <= max(start2[0],end2[0])+ epi
        &&y>=min(start2[1],end2[1])-epi && y <= max(start2[1],end2[1])+ epi){

        }
        else{
            return {};
        }
        return {x,y};
    }
};

// int main(){
//     vector<int> start1={12,-55};
//     vector<int> end1={59,-60};
//     vector<int> start2={4,-55};
//     vector<int> end2={81,-62};
//     Solution solution;
//     auto ret = solution.intersection(start1,end1,start2,end2);
//     return 0;
// }