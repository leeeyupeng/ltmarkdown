#include"leetcode.h"

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            int m = (i + j) >>1;
            if (numbers[m] > numbers[j]) i = m + 1;
            else if (numbers[m] < numbers[j]) j = m;
            else {
                if(numbers[(i+m)>>1] == numbers[j] && numbers[(m+j)>>1] == numbers[j]){
                    j--;
                }
                else if(numbers[(i+m)>>1] == numbers[j]){
                    i = m+1;
                }
                else{
                    j = m;
                }
            }
        }
        return numbers[i];
    }
};

// int main(){
//     vector<int> numbers{1,10,10,10,10};
//     Solution solution;
//     auto ret = solution.minArray(numbers);
//     return 0;
// }