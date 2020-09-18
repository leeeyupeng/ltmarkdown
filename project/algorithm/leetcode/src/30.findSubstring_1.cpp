#include"leetcode.h"

#define CHARNUMS 26
#define CHARINDEX(c) (c - 'a')
class Solution {
private:
    struct TrieNode{
        bool success;
        int wordindex;
        TrieNode* child[CHARNUMS];
        TrieNode():success(false),wordindex(0){
            memset(child,0,sizeof(TrieNode*) * CHARNUMS);
        }
    };
    TrieNode* root;
    int n;
    int wordsnums;
    int wordslength;
    vector<int> flag;
    inline void addword(string &word,int wordindex){
        TrieNode *node = root;
        int n = word.length();
        for(int i = 0; i < n; i ++){
            if(node->child[CHARINDEX(word[i])] == NULL){
                node->child[CHARINDEX(word[i])] = new TrieNode();
            }
            node = node->child[CHARINDEX(word[i])];
        }
        if(node->success){flag[node->wordindex]++;}
        else{
            node->success = true;
            node->wordindex = wordindex;
            flag[node->wordindex]=1;
        }
    }
    bool dfs(string& s,TrieNode *node,int i,int count){
        if(count == 0){return true;}
        while(i<n&&node->child[CHARINDEX(s[i])]!=NULL){
            node = node->child[CHARINDEX(s[i])];         
            i++;

            if(node->success){
                if(flag[node->wordindex] > 0){
                    flag[node->wordindex] --;
                    if(dfs(s,root,i,count - 1)){return true;}
                    flag[node->wordindex] ++;
                }
            }
        }
        return false;
    }
    bool issuccess(string &s,int i){
        return dfs(s,root,i,wordsnums);
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        root = new TrieNode();
        wordsnums = words.size();
        flag = vector<int>(wordsnums);
        wordslength = 0;
        for(int i = 0; i < wordsnums; i ++){flag[i] = 0;wordslength+=words[i].length();}
        for(int i = 0; i < wordsnums;i ++){
            addword(words[i],i);
        }
        vector<int> initflag = flag;
        n = s.length();
        vector<int> ans;
        for(int i = 0;i <= n-wordslength;i++){
            flag= initflag;
            if(issuccess(s,i)){ans.push_back(i);}
        }
        return ans;
    }
};

// int main(){
//     Solution solution;
//     string s = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel";
//     vector<string> words={
// "dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"
//     };
//     vector<int> ans = solution.findSubstring(s,words);
//     return 0;
// }