#include"leetcode.h"
class Solution {
private:
    vector<int> vans;
    unordered_map<int,vector<int>> us;
    int n,m,k;
    int getmaxindex(vector<int>& nums,int i,int j){
        int index = i;
        for(int kk = i+1;kk <= j; kk ++){
            if(nums[kk]>nums[index]){
                index = kk;
            }
        }
        return index;
    }

    void dfs(vector<int>& nums1, vector<int>& nums2,vector<int>& ans,int i, int j,int index,int flag){
        if (flag == 0){
            if(index>0&&vans[index-1]!=-1&&vans[index-1] < ans[index-1]){
                flag = 1;
            }
            else if(index>0&&vans[index-1]!=-1&&vans[index-1] > ans[index-1]){
                flag=-1;
            }
        }

        if(index == k ){
            if(flag!=-1){
                vans = ans;
            }
            return;
        }

        if(us.find(i*1000*1000 + j * 1000 +index)!=us.end()){          
            vector<int> temp = us[i*1000*1000 + j * 1000 +index];
            for(int kk = index;kk < k; kk++){
                ans[kk] = temp[kk];
            }
            if(flag!=-1){
                vans = ans;
            }
            return;
        }

        

        if(index == 5){
            cout<<index<<endl;
        }
        if(index == 9){
            cout<<index<<endl;
        }

        if(i == 8 && j == 5){
            cout<<i<<j<<endl;
        }
        
        int maxi=getmaxindex(nums1,i,n- max(1,k-index-(m-j)));
        int maxj=getmaxindex(nums2,j,m- max(1,k-index-(n-i)));
        if(maxi == n){
            ans[index] = nums2[maxj];
            dfs(nums1,nums2,ans,i,maxj + 1,index+1,flag);
        }
        else if(maxj == m){
            ans[index] = nums1[maxi];
            dfs(nums1,nums2,ans,maxi + 1,j,index+1,flag);
        }
        else if(nums1[maxi]>nums2[maxj]){
            ans[index] = nums1[maxi];
            dfs(nums1,nums2,ans,maxi + 1,j,index+1,flag);
        }
        else if(nums1[maxi]<nums2[maxj]){
            ans[index] = nums2[maxj];
            dfs(nums1,nums2,ans,i,maxj + 1,index+1,flag);
        }
        else{
            ans[index] = nums1[maxi];
            vector<int> temp = ans;
            dfs(nums1,nums2,ans,maxi + 1,j,index+1,flag);
            dfs(nums1,nums2,temp,i,maxj + 1,index+1,flag==1?0:flag);
            for(int kk = index+1;kk<k;kk++){
                if(temp[kk] < ans[kk]){
                    break;
                }else if(temp[kk]>ans[kk]){
                    ans = temp;
                    break;
                }
            }
        }
        if(i == 8 && j == 5){
            cout<<i<<j<<endl;
        }
        
        us.insert({i*1000*1000 + j * 1000 +index,ans});
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k);
        vans= vector<int>(k);
        for(int i = 0; i < k; i ++){ans[i] = -1;vans[i]=-1;}
        this->n = nums1.size();
        this->m = nums2.size();
        this->k = k;

        dfs(nums1,nums2,ans,0,0,0,0);

        return vans;
    }
};

// int main(){
//     vector<int> nums1={
// 2,1,7,8,0,1,7,3,5,8,9,0,0,7,0,2,2,7,3,5,5
//   };
//     vector<int> nums2={
// 2,6,2,0,1,0,5,4,5,5,3,3,3,4  };
//     int k=35;

//     Solution solution;
//     vector<int> ans = solution.maxNumber(nums1,nums2,k);

//     return 0;
// }