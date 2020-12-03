#include"leetcode.h"
class Solution {
private:
    int n,m,k;
    void getnums(vector<int>& nums,int k,vector<int>& ans){
        int top = -1;
        int size = nums.size();
        for(int i = 0; i < size; i ++){
            while(top>=0 && (size-i) + top + 1 > k && ans[top]<nums[i]){
                top--;
            }
            if(top<k-1){
                ans[++top] = nums[i];
            }
        }
    }
    void merge(vector<int>& nums1,int n1, vector<int>& nums2,int n2,vector<int>& ans){
        int n12 = n1+n2;
        int i=0,j=0;
        int ij=0;
        int ii,jj;
        while(ij<n12){
            if(j==n2||nums1[i]>nums2[j]){
                ans[ij]=nums1[i];
                i++;
                ij++;
            }
            else if(i==n1||nums1[i]<nums2[j]){
                ans[ij]=nums2[j];
                j++;
                ij++;
            }
            else{
                ii = i+1;
                jj = j+1;
                while(ii<n1&&jj<n2&&nums1[ii] == nums2[jj]){
                    ii++;
                    jj++;
                }
                if(jj==n2||nums1[ii]>nums2[jj]){
                        ans[ij]=nums1[i];
                        i++;
                        ij++;
                }
                else{
                    ans[ij]=nums2[j];
                    j++;
                    ij++;
                }
            }
        }
    }
    bool compare(vector<int>& nums1, vector<int>& nums2,int n){
        for(int i = 0; i < n; i ++){
            if(nums1[i]>nums2[i]){
                return true;
            }
            else if(nums1[i]<nums2[i]){
                return false;
            }
        }
        return true;
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        this->n = nums1.size();
        this->m = nums2.size();
        this->k = k;

        vector<int> ans(k);
        vector<int> stack1(k);
        vector<int> stack2(k);
        vector<int> merge12(k);
        for(int i = 0; i < k; i ++){ans[i]=-1;}
        for(int i = max(0,k-m);i <= min(n,k);i ++){
            getnums(nums1,i,stack1);
            getnums(nums2,k-i,stack2);
            merge(stack1,i,stack2,k-i,merge12);
            if(compare(merge12,ans,k)){
                ans = merge12;
            }
        }
        return ans;
    }
};

// int main(){
//     vector<int> nums1={
// 8,8
//   };
//     vector<int> nums2={
// 8,8,2, 1, 2, 5, 8, 3
//  };
//     int k=5;

//     Solution solution;
//     vector<int> ans = solution.maxNumber(nums1,nums2,k);

//     return 0;
// }