#include"leetcode.h"

#define CHARNUMS 26
#define CHARINDEX(c) (c - 'a')
class Solution {
private:
    struct TrieNode{
        bool success;
        TrieNode* child[CHARNUMS];
        TrieNode():success(false){
            memset(child,0,sizeof(TrieNode*) * CHARNUMS);
        }
    };
    TrieNode* root;
    int n;
    int wordsnums;
    int wordslength;
    vector<bool> flag;
    inline TrieNode* updatenode(string& words,TrieNode* node){
        int n = words.length();
        for(int i = 0; i < n; i ++){
            if(node->child[CHARINDEX(words[i])] == NULL){
                node->child[CHARINDEX(words[i])] = new TrieNode();
            }
            node = node->child[CHARINDEX(words[i])];
        }
        return node;
    }
    void dfs(vector<string>& words,TrieNode* node,int count){
        if(count == 0){node->success = true;}
        for(int i = 0; i < wordsnums;i++){
            if(flag[i] == false){
                flag[i]=true;
                dfs(words,updatenode(words[i],node),count-1);
                flag[i]=false;
            }
        }
    }
    bool issuccess(string &s,int i){
        TrieNode* node = root;
        while(i<n&&node->child[CHARINDEX(s[i])]!=NULL){
            node = node->child[CHARINDEX(s[i])];            
            i++;
        }
        return node->success;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        root = new TrieNode();
        wordsnums = words.size();
        flag = vector<bool>(wordsnums);
        wordslength = 0;
        for(int i = 0; i < wordsnums; i ++){flag[i] = false;wordslength+=words[i].length();}
        dfs(words,root,wordsnums);

        n = s.length();
        vector<int> ans;
        for(int i = 0;i <= n-wordslength;i++){
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