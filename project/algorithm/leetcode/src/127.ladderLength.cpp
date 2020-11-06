#include"leetcode.h"

class Solution {
private:
    int wordlength;
    int n;
    int distance(string &word1,string &word2){
        int dist = 0;
        for(int i = 0; i < wordlength; i ++){
            if(word1[i]!=word2[i]){dist++;}
        }
        return dist;
    }

    int findshortestpath(vector<vector<bool>> &matrix,int s,int e){
        vector<bool> visit(n+1);
        for(int i = 0; i < n+1; i ++){
            visit[i] = false;
        }
        queue<int> q;
        q.push(s);
        visit[s] = true;
        int index;
        int counter;
        int dist = 1;
        while(!q.empty()){
            counter = q.size();
            dist++;
            while(counter>0){
                counter--;
                index = q.front();
                q.pop();
                for(int i = 0; i < n+1; i++){
                    if(matrix[index][i]&&visit[i]==false){
                        q.push(i);
                        visit[i] = true;
                        if(i == e){return dist;}
                    }
                }
            }
        }

        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordlength = beginWord.length();
        n = wordList.size();
        vector<vector<bool>> matrix(n+1,vector<bool>(n+1));
        for(int i = 0; i < n+1; i ++){
            for(int j = 0; j < n+1; j ++){
                matrix[i][j] = false;
            }
        }

        for(int i = 1; i <= n; i ++){
            for(int j = i+1; j <= n; j ++){
                if(distance(wordList[i-1],wordList[j-1]) == 1){
                    matrix[i][j] = true;
                    matrix[j][i] = true;
                }
            }
        }

        for(int j = 1; j <= n; j ++){
            if(distance(beginWord, wordList[j-1]) == 1){
                matrix[0][j] = true;
                matrix[j][0] = true;
            }
        }

        int endwordindex = 0;
        for(int j = 1; j <= n; j ++){
            if(distance(endWord,wordList[j-1]) == 0){
                endwordindex = j;
            }
        }
        if(endwordindex == 0){return 0;}
        int dist = distance(beginWord,endWord);
        if(dist == 0){return 1;}
        else if(dist == 1){return 2;}


        dist = findshortestpath(matrix,0,endwordindex);
        return dist;
    }
};