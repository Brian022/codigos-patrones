#include <iostream>
#include <vector>
using namespace std;

class Vehiculo {
public:
    virtual void printVehiculo() = 0;
    static Vehiculo* Crear(int tipo);
};
class dosR : public Vehiculo {
public:
    void printVehiculo() {
        cout << "Vehiculo de dos ruedas" << endl;
    }
};
class tresR : public Vehiculo {
public:
    void printVehiculo() {
        cout << "Vehiculo de tres ruedas" << endl;
    }
};

Vehiculo* Vehiculo::Crear(int tipo) {
    if (tipo == 2)
        return new dosR();
    else if (tipo == 3)
        return new tresR();
    else return NULL;
}

class Cliente {
public:
    Vehiculo* getV(){return pVehiculo;}

private:
    Vehiculo *pVehiculo;
};

int main()
{
    int tipo;
    vector<Vehiculo*> Autos;
    Cliente *pCliente = new Cliente();
    while(true)
    {
        cin>>tipo;
        if (tipo== 0)
            break;
        Autos.push_back(Vehiculo::Crear(tipo));
    }
    for (int i = 0; i < Autos.size(); i++)
        Autos[i]->printVehiculo();
    for (int i = 0; i < Autos.size(); i++)
    {
        delete Autos[i];
        cout<<"borrado" <<i<<"\n";
    }
    return 0;
}
