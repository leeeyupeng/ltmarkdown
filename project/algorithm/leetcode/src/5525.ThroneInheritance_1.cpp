#include"leetcode.h"

class ThroneInheritance {
private:
    struct person
    {
        string name;     
        bool isdead;
        person *parent;
        vector<person*> child;
        person *next;
        person(string _name):name(_name),isdead(false),parent(NULL),next(NULL){}
    };

    person* king;
    unordered_map<string,person *> map;

    person* getlastdescendant(person *p){
        person * lastdescendant = p;
        while(!lastdescendant->child.empty()){
            lastdescendant = lastdescendant->child.back();
        }
        return lastdescendant;
    }
public:
    ThroneInheritance(string kingName) {
        king = new person(kingName);
        map[king->name] = king;
    }
    
    void birth(string parentName, string childName) {
        person *p=new person(childName);
        person *parent = map[parentName];

        person *front = getlastdescendant(parent);
        p->next = front->next;
        front->next = p;

        parent->child.push_back(p);
        p->parent = parent;
        map[childName] = p;
    }
    
    void death(string name) {
        map[name]->isdead = true;
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> curoder;
        person *node = king;
        do{
            if(node->isdead==false){curoder.push_back(node->name);}
            node = node->next;
        }while(node!=NULL);
        return curoder;
    }
};

// int main(){
//     ThroneInheritance* obj = new ThroneInheritance("kingName");
//     obj->birth("kingName","childName1");
//     obj->death("childName1");
//     vector<string> param_3 = obj->getInheritanceOrder();
// }