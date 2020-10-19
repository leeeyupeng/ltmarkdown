#include"leetcode.h"

class ThroneInheritance {
private:
    struct person
    {
        string name;        
        bool isdead;
        person *parent;
        vector<person*> child;
        person(string _name):name(_name),isdead(false),parent(NULL){}
    };

    person* king;
    unordered_map<string,person*> map;
    

    // Successor(x, curOrder):
    // 如果 x 没有孩子或者所有 x 的孩子都在 curOrder 中：
    //     如果 x 是国王，那么返回 null
    //     否则，返回 Successor(x 的父亲, curOrder)
    // 否则，返回 x 不在 curOrder 中最年长的孩子
    person* Successor(string x,vector<string>& curoder,unordered_set<string>& set){
        person *p = map[x];
        int childnums = p->child.size();
        for(int i = 0; i < childnums;i++){
            if(set.find(p->child[i]->name)==set.end()){
                set.insert(p->child[i]->name);
                return p->child[i];
            }
        }
        if(p == king){return NULL;}
        else {return Successor(p->parent->name,curoder,set);}
    }
public:
    ThroneInheritance(string kingName) {
        king = new person(kingName);
        map[king->name] = king;
    }
    
    void birth(string parentName, string childName) {
        person *p=new person(childName);
        person *parent = map[parentName];
        parent->child.push_back(p);
        p->parent = parent;
        map[childName] = p;
    }
    
    void death(string name) {
        map[name]->isdead = true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> curoder;
        unordered_set<string> set;
        if(king->isdead==false){curoder.push_back(king->name);}
        set.insert(king->name);
        person *node = king;

        while(node!=NULL){
            node =  Successor(node->name,curoder,set);
            if(node!=NULL && node->isdead==false){
                curoder.push_back(node->name);
            }
        }
        return curoder;
    }
};

// int main(){
//     ThroneInheritance* obj = new ThroneInheritance("kingName");
//     obj->birth("kingName","childName1");
//     obj->death("childName1");
//     vector<string> param_3 = obj->getInheritanceOrder();
// }