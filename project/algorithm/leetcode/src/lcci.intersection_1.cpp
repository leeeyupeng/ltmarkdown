#include"leetcode.h"

#define EPI (10e6)
class Solution {
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        vector<long long> llstart1={start1[0],start1[1]};
        llstart1[0] *= EPI;
        llstart1[1] *= EPI;
        vector<long long> llend1={end1[0],end1[1]};
        llend1[0] *= EPI;
        llend1[1] *= EPI;
        vector<long long> llstart2={start2[0],start2[1]};
        llstart2[0] *= EPI;
        llstart2[1] *= EPI;
        vector<long long> llend2={end2[0],end2[1]};
        llend2[0] *= EPI;
        llend2[1] *= EPI;

        double x,y;
        if(llstart1[0] == llend1[0] && llstart2[0] == llend2[0]){
            if(llstart1[0] == llstart2[0]){
                x = llstart1[0];
                y = max(min(llstart1[1],llend1[1]),min(llstart2[1],llend2[1]));
            }
            else{
                return {};
            }
        }
        else if(llstart1[0] == llend1[0]){
            x = llstart1[0];
            y = 1.0f * (llend2[1] - llstart2[1]) * (x - llstart2[0]) / (llend2[0] - llstart2[0])  + llstart2[1];
        }
        else if(llstart2[0] == llend2[0]){
            x = llstart2[0];
            y = 1.0f * (llend1[1] - llstart1[1]) * (x - llstart1[0]) / (llend1[0] - llstart1[0])  + llstart1[1];
        }
        else{
            double slop1 = 1.0f * (llend1[1]-llstart1[1]) / (llend1[0] - llstart1[0]);
            double slop2 = 1.0f * (llend2[1]-llstart2[1]) / (llend2[0] - llstart2[0]);
            bool isslop = (llend1[1]-llstart1[1]) * (llend2[0] - llstart2[0]) == (llend2[1]-llstart2[1]) * (llend1[0] - llstart1[0]);
            if(isslop){
                if(llstart2[0] == llstart1[0] || (llstart2[1] - llstart1[1]) / (llstart2[0] - llstart1[0]) == slop1){
                    x = max(min(llstart1[0],llend1[0]),min(llstart2[0],llend2[0]));
                    if(x == llstart1[0]){y = llstart1[1];}
                    else if(x == llend1[0]){y = llend1[1];}      
                    else if(x == llstart2[0]){y = llstart2[1];}    
                    else if(x == llend2[0]){y = llend2[1];}             
                }
                else{
                    return {};
                }
            }
            else{
                x=(llend2[1]-llstart2[1]) * (llend1[0] - llstart1[0]) * llstart2[0] 
                - (llend1[1] - llstart1[1]) * (llend2[0] - llstart2[0]) * llstart1[0] 
                - (llend1[0] - llstart1[0])*(llend2[0] - llstart2[0])*llstart2[1]
                + (llend1[0] - llstart1[0])*(llend2[0] - llstart2[0])*llstart1[1];
                x*=((llend1[0] - llstart1[0]) * (llend2[0] - llstart2[0]));
                x/=((llend1[0] - llstart1[0])*(llend2[0] - llstart2[0]))*((llend2[1]-llstart2[1]) * (llend1[0] - llstart1[0])-(llend1[1]-llstart1[1]) * (llend2[0] - llstart2[0]));

                if(llstart1[1] == llend1[1]){
                    y = llstart1[1];
                }
                else if(llstart2[1] == llend2[1]){
                    y = llstart2[1];
                }
                else{
                    y = (llend2[1] - llstart2[1]) * (x - llstart2[0]) / (llend2[0] - llstart2[0])  + llstart2[1];
                }
            }
        }
        if((long long)x>=min(llstart1[0],llend1[0]) && (long long)x <= max(llstart1[0],llend1[0])
        &&(long long)y>=min(llstart1[1],llend1[1]) && (long long)y <= max(llstart1[1],llend1[1])
        &&(long long)x>=min(llstart2[0],llend2[0]) && (long long)x <= max(llstart2[0],llend2[0])
        &&(long long)y>=min(llstart2[1],llend2[1]) && (long long)y <= max(llstart2[1],llend2[1])){

        }
        else{
            return {};
        }
        return {1.0f * x/EPI,1.0f*y/EPI};
    }
};

// int main(){
//     vector<int> start1={50,76};
//     vector<int> end1={23,33};
//     vector<int> start2={58,87};
//     vector<int> end2={21,30};
//     Solution solution;
//     auto ret = solution.intersection(start1,end1,start2,end2);
//     return 0;
// }