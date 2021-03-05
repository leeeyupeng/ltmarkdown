#include"leetcode.h"

#define EPI (10e-6)
class Solution {
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        double x,y;

        if(start1[0] > end1[0]){swap(start1,end1);}
        else if(start1[0] == end1[0] && start1[1] > end1[1]){swap(start1,end1);}
        if(start2[0] > end2[0]){swap(start2,end2);}
        else if(start2[0] == end2[0] && start2[1] > end2[1]){swap(start2,end2);}
        vector<double> left = {1.0f*start1[0],1.0f*start1[1]};
        vector<double> right = {1.0f*end1[0],1.0f*end1[1]};

        if((end2[1] - start2[1]) * (start1[0] - start2[0]) > (start1[1] - start2[1]) * (end2[0] - start2[0])
        && (end2[1] - start2[1]) * (end1[0] - start2[0]) > (end1[1] - start2[1]) * (end2[0] - start2[0])){return {};}
        else if((end2[1] - start2[1]) * (start1[0] - start2[0]) < (start1[1] - start2[1]) * (end2[0] - start2[0])
        && (end2[1] - start2[1]) * (end1[0] - start2[0]) < (end1[1] - start2[1]) * (end2[0] - start2[0])){return {};}
        else if((end2[1] - start2[1]) * (start1[0] - start2[0]) == (start1[1] - start2[1]) * (end2[0] - start2[0])
        && (end2[1] - start2[1]) * (end1[0] - start2[0]) == (end1[1] - start2[1]) * (end2[0] - start2[0])){
            x = max(min(start1[0],end1[0]),min(start2[0],end2[0]));
            if(x == start1[0]){y = start1[1];}
            else if(x == end1[0]){y = end1[1];}      
            else if(x == start2[0]){y = start2[1];}    
            else if(x == end2[0]){y = end2[1];}      
        }
        else {
            vector<double>  point={0.0f,0.0f};
            while(left[0]<=right[0]-EPI*0.5f ||  (start1[1] < end1[1] && left[1]<=right[1]-EPI*0.5f) || (start1[1] > end1[1] && left[1]>=right[1]+EPI*0.5f) ){
                point = {(left[0] + right[0])*0.5f,(left[1] + right[1]) * 0.5f};
                if((end2[1] - start2[1])==0){
                    if(point[1] >= end2[1]){
                        if(left[1]<=right[1]){
                            right = point;
                        }
                        else{
                            left = point;
                        }
                    }
                    else{
                        if(left[1]>=right[1]){
                            right = point;
                        }
                        else{
                            left = point;
                        }
                    }
                }
                else if((end2[0] - start2[0]) == 0){
                    if(point[0] >= end2[0]){
                        if(left[0]<=right[0]){
                            right = point;
                        }
                        else{
                            left = point;
                        }
                    }
                    else{
                        if(left[0]>=right[0]){
                            right = point;
                        }
                        else{
                            left = point;
                        }
                    }
                }
                else if(start1[0] == end1[0]){
                    if((end2[1] - start2[1]) * (point[0] - start2[0]) >= (point[1] - start2[1]) * (end2[0] - start2[0])){
                        left = point;
                    }
                    else{
                        right = point;
                    }
                }
                else if((end2[0] - start2[0])>0 && (end2[1] - start2[1]) > 0){
                    if((end2[1] - start2[1]) * (point[0] - start2[0]) >= (point[1] - start2[1]) * (end2[0] - start2[0])){
                        right = point;
                    }
                    else{
                        left = point;
                    }
                }
                else if((end2[0] - start2[0])>0 && (end2[1] - start2[1]) < 0){
                    if((end2[1] - start2[1]) * (point[0] - start2[0]) <= (point[1] - start2[1]) * (end2[0] - start2[0])){
                        right = point;
                    }
                    else{
                        left = point;
                    }
                }
            }

            x = left[0];
            y = left[1];
        }
        if(x>=min(start1[0],end1[0])-EPI && x <= max(start1[0],end1[0]) + EPI
        &&y>=min(start1[1],end1[1])-EPI && y <= max(start1[1],end1[1])+ EPI
        &&x>=min(start2[0],end2[0])-EPI && x <= max(start2[0],end2[0])+ EPI
        &&y>=min(start2[1],end2[1])-EPI && y <= max(start2[1],end2[1])+ EPI){

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