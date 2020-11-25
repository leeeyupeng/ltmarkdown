#pragma once
template<typename T>
class static_constructable{
private:
    struct  helper
    {
        helper(){
            T::static_constructor();
        }
    };
protected:
    static_constructable(){
        static helper placeholder;
    }   
};