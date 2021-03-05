#include<iostream>
#include <memory>
using namespace std;
// class ICar{
// public:
//     virtual void DriveCar()=0;
// };

class ICar{
public:
    virtual ~ICar(){
        cout<<"~ICar()"<<endl;
    }
    virtual void DriveCar(){}
};

class Car:public ICar{
public:
    Car(){
        cout<<"Car()"<<endl;
    }
    ~Car()override{
        cout<<"~Car()"<<endl;
    }
    void DriveCar()override{
        cout<<"Car DriveCar()"<<endl;
    }
};
class ProxyCar:public ICar{
private:
    std::unique_ptr<ICar> real_car = std::make_unique<Car>();
    int driverage;
public:
    ProxyCar(int _driverage):driverage(_driverage){
        cout<<"ProxyCar()"<<endl;
    }
    ~ProxyCar()override{
        cout<<"~ProxyCar()"<<endl;
    }
    void DriveCar()override{
        cout<<"ProxyCar DriveCar"<<endl;
        if(driverage>16){
            real_car->DriveCar();
        }
        else{
            cout<<"driverage<=16"<<endl;
        }
    }
};

// int main(){
//     std::unique_ptr<ICar> car2(std::make_unique<ProxyCar>(16));
//     std::unique_ptr<ICar> car = std::make_unique<ProxyCar>(16);
//     car->DriveCar();

//     car = std::make_unique<ProxyCar>(25);
//     car->DriveCar();

//     return 0;
// }