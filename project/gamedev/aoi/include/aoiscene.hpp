#define MAXENTYTY 1000000
#include<iostream>
#include<vector>
#include<unordered_map>

#include"aoientity.hpp"
using namespace std;
struct aoidoublenode{
    int entityid;
    aoidoublenode* xpre;
    aoidoublenode* xnext;
    aoidoublenode* ypre;
    aoidoublenode* ynext;
    aoidoublenode(int _entityid):entityid(_entityid),xpre(nullptr),xnext(nullptr),ypre(nullptr),ynext(nullptr){}
};

class aoiscene{
private:
    vector<aoientity> entitys;
    unordered_map<int,aoientity*> umentitys;

    vector<aoidoublenode> nodes;
    unordered_map<int,aoidoublenode*> umnodes;
    int n;

    void enter(int entityid1,int nodeid1,int entityid2,int nodeid2);
    void leave(int entityid1,int nodeid1,int entityid2,int nodeid2);
public:
    aoiscene();
    ~aoiscene();
    void add(int entityid,int x,int y);
    void remove(int entityid);
    void move(int entityid,int x,int y);

    // void register();
    // void unregister();
};