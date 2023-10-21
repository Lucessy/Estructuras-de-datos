#ifndef MESA_H
#define MESA_H
#include <string>
using namespace std;

class Mesa
{
    public:
        Mesa();
        Mesa(int numMesa,int capacidad,string situacionMesa);
        virtual ~Mesa();
        int getNumMesa();
        int getCapacidad();
        string getSituacionMesa();

    protected:

    private:
        int numMesa;
        int capacidad;
        string situacionMesa;
};

#endif // MESA_H
