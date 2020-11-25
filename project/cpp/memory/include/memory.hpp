#include<iostream>
#include<vector>
#include<unordered_map>
#include<assert.h>
using namespace std;
namespace LT{
    //64MB
    #define MAXBLOCK (1024*1024*64)
    #define MAXBIT 27
    //4个字节
    #define MINBLOCK (4)
    #define MINBIT 3
    #define BITENGHT 25
    struct  memory_unit
    {
        void* ptr;
        memory_unit* next;
        memory_unit():ptr(nullptr),next(nullptr){

        }
    };
    
    class memory_block{
    private:
        void* ptr=nullptr;
        
        memory_unit* units[BITENGHT];
        memory_unit* useunits[BITENGHT];

        vector<memory_unit*> vmu;
        memory_unit* unitcache;
        memory_unit* getunitcache(){
            if(unitcache == nullptr){
                memory_unit* newunit = new memory_unit[1024]();
                vmu.push_back(newunit);
                for(int i = 0; i < 1024; i ++){
                    newunit[i].next = unitcache;
                    unitcache = &(newunit[i]);
                }
            }

            assert(unitcache);

            memory_unit* res=nullptr;

            if(unitcache!=nullptr){
                res = unitcache;
                unitcache=unitcache->next;
            }
            return res;
        }
        inline unsigned int getindex(unsigned int size){
            unsigned int index = 0;
            while(size!=0){
                index++;
                size = size>>1;                
            }
            return index - MINBIT;
        }
        inline unsigned int getsize(unsigned int index){
            unsigned int size = MINBLOCK;
            size = size<<index;
            return size;
        }
        bool _splitunit(unsigned int index){
            if(index>MAXBIT){return false;}
            if(units[index] == nullptr){
                if(_splitunit(index+1)){
                    if(units[index+1]!=nullptr){
                        memory_unit* unit = units[index+1];
                        units[index+1] = units[index+1]->next;
                        memory_unit* unit2 = getunitcache();
                        unit2->ptr = unit->ptr + (getsize(index)>>2);

                        unit->next = units[index];
                        unit2->next = unit;
                        units[index] = unit2;
                    }
                }
            }
            return units[index]!=nullptr;
        }
        void* _get(unsigned int index){
            memory_unit* ptrmu=nullptr;
            if(units[index]==nullptr){
                _splitunit(index);
            }
            if(units[index]!=nullptr){
                ptrmu= units[index];
                units[index] = units[index]->next;

                ptrmu->next = useunits[index];
                useunits[index] = ptrmu;
                return ptrmu->ptr;
            }
            return nullptr;
        }
    public:
        memory_block(){
            unitcache = nullptr;

            ptr = nullptr;
            for(int i = 0; i < BITENGHT; i ++){
                units[i] = nullptr;
                useunits[i] = nullptr;
            }
            unsigned int s = MAXBLOCK * sizeof(char);
            ptr = malloc(s);
            assert(ptr);
            memory_unit* unit = getunitcache();
            unit->ptr = ptr;
            unit->next = units[getindex(MAXBLOCK)];
            units[getindex(MAXBLOCK)] = unit;
        }
        ~memory_block(){
            for(int i = 0; i < BITENGHT; i ++){
                units[i] = nullptr;
                useunits[i] = nullptr;
            }
            for(int i = 0; i < vmu.size();i ++){
                delete[] vmu[i];
                vmu[i] = nullptr;
            }
            vmu.clear();
            free(ptr);
            ptr = nullptr;
        }

        void* get(unsigned int size){
            unsigned int index =getindex(size);
            return _get(index);
        }
    };

    class memory{
    private:
        vector<memory_block*> vmb;
        inline unsigned int getblocksize(unsigned int size){
            if(size <= MINBLOCK){size = MINBLOCK;}
            else if((size&(size-1)) == 0x0){
            }
            else{
                size = size<<1;
                while((size&(size-1))!=0x0){
                    size=size&(size-1);
                }
            }
            return size;
        }
    public:
        memory(){
            vmb.push_back(new memory_block());  
        }
        ~memory(){
            for(int i = 0; i < vmb.size(); i ++){
                delete vmb[i];
            }
            vmb.clear();
        }
        void* malloc(unsigned int size){
            unsigned int blocksize = getblocksize(size);
            //cout<<"size:"<<size<<" blocksize:"<<blocksize<<endl;

            void* res=nullptr;
            for(int i = 0; i < vmb.size(); i ++){
                res = vmb[i]->get(blocksize);
                if(res!=nullptr){return res;}
            }
            vmb.push_back(new memory_block());
            return vmb.back()->get(blocksize);
        }
        void free(void* ){

        }
    };
}