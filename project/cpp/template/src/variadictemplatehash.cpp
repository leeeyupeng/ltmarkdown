#include<iostream>
#include<functional>
using namespace std;

template<typename T>
inline size_t myhash(const T& val){
    return std::hash<T>()(val); 
}
template<typename T>
inline void hash_combine(size_t& seed,const T& val){
    size_t h = std::hash<T>()(val);
    seed ^= (h + 0x9e3779b9 + (seed<<6) + (seed>>2));
}

template<typename T>
inline void hash_val(size_t& seed,const T& val){
    hash_combine(seed,val);
}

template<typename T,typename... Types>
inline void hash_val(size_t& seed,T& head, Types&... tail){
    hash_combine(seed,head);
    hash_val(seed,tail...);
}

template<typename... Types>
inline size_t hash_val(const Types&... args){
    size_t seed = 0;
    hash_val(seed,args...);
    return seed;
}

class Customer1{
public:
    string name;
    int id;
    float fid;

    Customer1(string _name,int _id,float _fid):name(_name),id(_id),fid(_fid){}
};

class Customer2{
public:
    string name;
    int id;
    float fid;
    double did;
    Customer2(string _name,int _id,float _fid,double _did):name(_name),id(_id),fid(_fid),did(_did){}
};
class Hash{
public:
    std::size_t operator()(const Customer1& c)const{
        return hash_val(c.name,c.id,c.fid);
    }
    std::size_t operator()(const Customer2& c)const{
        return hash_val(c.name,c.id,c.fid,c.did);
    }
};

// int main(){
//     float f1 = 1.00010001f;
//     float f2 = 2.00010002f;
//     cout<<&f1<<endl;
//     cout<<&f2<<endl;

//     cout<<std::hash<decltype(f1)>()(f1)<<endl;
//     cout<<std::hash<decltype(f2)>()(f2)<<endl;

//     std::hash<decltype(f1)> h;    
//     cout<<h(f1)<<endl;

//     string name = "hello";
//     cout<<std::hash<decltype(name)>()(name)<<endl;

//     Customer1 c11("hello",10,10.0101f);
//     Customer1 c12("hello",10,10.0101f);

//     Customer2 c21("world",20,20.0202,20.020202);
//     Customer2 c22("world",20,20.0204,20.020202);

//     cout<<Hash()(c11)<<endl;
//     cout<<Hash()(c12)<<endl;
//     cout<<Hash()(c21)<<endl;
//     cout<<Hash()(c22)<<endl;

//     return 0;
// }