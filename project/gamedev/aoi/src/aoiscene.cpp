#include"aoiscene.hpp"
aoiscene::aoiscene(){
    entitys = vector<aoientity>(MAXENTYTY);
    nodes = vector<aoidoublenode>(MAXENTYTY);
    n = 0;
}
aoiscene::~aoiscene(){
    entitys.clear();
    umentitys.clear();
    nodes.clear();    
    umnodes.clear();
    n = 0;
}
void aoiscene::add(int entityid,aoivector2 pos){
    entitys[n] = {entityid,pos};
}