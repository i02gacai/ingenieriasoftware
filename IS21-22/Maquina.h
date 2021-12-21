
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

class Maquina
{
    private:
    //parametros
    int id_maquina=0;
    int cpu;
    int ram;
    int recuersos_disp_ram;
    int recuersos_disp_cpu;
    int cluster;

    public:
    //get
    inline int getid_maquina(){return id_maquina;}
    inline int getcpu(){return cpu;}
    inline int getram(){return ram;}
    inline int getrecuersos_disp_ram(){return recuersos_disp_ram;}
    inline int getrecuersos_disp_cpu(){return recuersos_disp_cpu;}
    inline int getcluster(){return cluster;}
    
    
    //set
    /*
    void setmaquina(int id_maquina_);
    int setcpu(int cpu_);
    int setram( int ram_);
    int setrecuersos_disp_ram(int recuersos_disp_ram_);
    int setrecuersos_disp_cpu(int recuersos_disp_cpu_);
    int setcluster(int cluster_);
    */
    //constructor vacio
    Maquina()
    { 
    }

    //Constructor con parametros
    Maquina( int cpu_, int ram_, int cluster_)
    {
        id_maquina++;
        cpu=cpu_;
        ram=ram_;
        cluster=cluster_;
    }
    
    inline void setid_maquina(int id_maquina_)
    {
        id_maquina=id_maquina_;
    }
    inline void setcpu(int cpu_)
    {
        cpu=cpu_;
    }
    inline void setram( int ram_)
    {
        ram=ram_;
    }
    inline void setrecuersos_disp_ram(int recuersos_disp_ram_)
    {
        recuersos_disp_ram=recuersos_disp_ram_;
    }
    inline void setrecuersos_disp_cpu(int recuersos_disp_cpu_)
    {
        recuersos_disp_cpu=recuersos_disp_cpu_;
    }
    inline void setcluster(int cluster_)
    {
        cluster=cluster_;
    }

    //metodos
    void mostrar_maquinas();

};