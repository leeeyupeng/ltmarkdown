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
        person *lastdescendant;
        person(string _name):name(_name),isdead(false),parent(NULL),next(NULL),lastdescendant(this){}
    };

    person* king;
    unordered_map<string,person *> map;
public:
    ThroneInheritance(string kingName) {
        king = new person(kingName);
        map[king->name] = king;
    }
    
    void birth(string parentName, string childName) {
        person *p=new person(childName);
        person *parent = map[parentName];

        person *front = parent->lastdescendant;
        p->next = front->next;
        front->next = p;

        person *pparent=parent;
        do{
            pparent->lastdescendant = p;
            if(pparent->parent!=NULL && pparent->parent->child.back() == pparent){
                pparent = pparent->parent;
            }else{break;}
        }
        while(pparent!=NULL);

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