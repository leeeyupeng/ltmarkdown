
struct aoivector2{
    int x;
    int y;
    aoivector2(int _x,int _y);
};

class aoinode{
private:
    int _aoinodeid;
};
class aoientity{
private:
    int entityid;
    aoivector2 entitypos;
public:
    aoientity(int _entityid,aoivector2 entitypos);
    void updatepos(){}
};