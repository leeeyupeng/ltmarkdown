#include"leetcode.h"

class Solution {
private:
    double cosangle;
    bool check(vector<vector<int>>& points,int i,int j){             
        long long cross = (long long)points[i][0] * (long long)points[j][1] - (long long)points[i][1] * (long long)points[j][0];
        if(cross < 0){return false;}
        if((long long)points[i][1] * (long long)points[j][0] == (long long)points[i][0]*(long long)points[j][1]){return true;} 
        long long dot = ((long long)points[i][0] * (long long)points[j][0] + (long long)points[i][1] * (long long)points[j][1]);
        double v = 1.0f * dot
        /  (sqrt((long long)points[i][0] * (long long)points[i][0] + (long long)points[i][1] * (long long)points[i][1]) 
        * sqrt((long long)points[j][0] * (long long)points[j][0] + (long long)points[j][1] * (long long)points[j][1])) ;
        return v-cosangle>= -numeric_limits<double>::epsilon();
    }
    bool check2(vector<vector<int>>& points,int i,int j){        
        long long cross = (long long)points[i][0] * (long long)points[j][1] - (long long)points[i][1] * (long long)points[j][0];
        if(cross < 0){return false;}
        long long dot = ((long long)points[i][0] * (long long)points[j][0] + (long long)points[i][1] * (long long)points[j][1]);
        double v = 1.0f * dot
        /  (sqrt((long long)points[i][0] * (long long)points[i][0] + (long long)points[i][1] * (long long)points[i][1]) 
        * sqrt((long long)points[j][0] * (long long)points[j][0] + (long long)points[j][1] * (long long)points[j][1])) - cosangle;
        return v> numeric_limits<double>::epsilon();
    }
    bool check3(vector<vector<int>>& points,int i,int j){             
        long long cross = (long long)points[i][0] * (long long)points[j][1] - (long long)points[i][1] * (long long)points[j][0];
        if(cross < 0){return false;}
        if((long long)points[i][1] * (long long)points[j][0] == (long long)points[i][0]*(long long)points[j][1]){return true;} 
        return false;
    }
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int n = points.size();
        vector<vector<int>> ppoints;
        int k = 0;
        for(int i = 0; i < n; i ++){
            points[i][0]-=location[0];
            points[i][1] -= location[1];

            if(points[i][0] == 0 && points[i][1] == 0){
                k++;
            }
            else{
                ppoints.push_back(points[i]);
            }
        }

        sort(ppoints.begin(),ppoints.end(),[](vector<int> &a,vector<int> &b){
            if(a[1] >= 0 && b[1] >=0){
                if((long long)a[1]*(long long)b[0] == (long long)a[0] * (long long)b[1]){return a[1]<b[1];}
                return (long long)a[1] * (long long)b[0] < (long long)a[0] * (long long)b[1];
            }
            else if(a[1] <=0 && b[1]<=0){
                if((long long)a[1]*(long long)b[0] == (long long)a[0] * (long long)b[1]){return a[1]>b[1];}
                return (long long)a[1] * (long long)b[0] < (long long)a[0] * (long long)b[1];
            }
            else{
                return a[1]>b[1];
            }
        });

        int ans = 0;
        int i = 0,j = 0;      
        i = 0;
        j = 0;
        int originnums = k;
        
        int nn = ppoints.size();
        if(nn<=1){return nn+originnums;}
        if(angle == 0){
            while(i < nn && j < (nn<<1)){
                j++;
                while(i<nn&&i<=j&&!check3(ppoints,i,j%nn)){i++;}
                
                ans = max(ans,j-i+1 + originnums);
                if(ans == n){break;}
            }
        }else if(angle == 360){
            return n;
        }
        else if(angle <= 180){
            cosangle = cos(M_PI * angle / 180.0f);
            while(i < nn && j < (nn<<1)){
                j++;
                while(i<nn&&i<=j&&!check(ppoints,i,j%nn)){i++;}
                
                ans = max(ans,j-i+1 + originnums);
                if(ans == n){break;}
            }
        }else{
            cosangle = cos(M_PI * (360-angle) / 180.0f);
            ans = 0;
            while(i < nn&& j < (nn<<1)){
                j++;
                while(i+1<nn&&i+1<=j&&!check(ppoints,i+1,j%nn)){i++;}             
                ans = max(ans,n-(j-i-1) + originnums);
                if(ans == n){break;}
            } 
        }
        return ans;
    }
};

// int main(){
//     Solution solution;
//     vector<vector<int>> points={
// {956,232},{438,752},{595,297},{508,143},{111,594},{645,824},{758,434},{447,423},{825,356},{807,377}
//     };
//     int angle= 38;
//     vector<int> location={
// 74,581
//     };
//     int ans = solution.visiblePoints(points,angle,location);
//     return 0;
// }