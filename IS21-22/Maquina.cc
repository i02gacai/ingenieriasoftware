#include "Maquina.h"

void Maquina::mostrar_maquinas()
{
    ifstream f4(("maquinas.txt"));
	 if(!f4.is_open()){
	 	cout<<"ERROR AL ABRIR EL ARCHIVO MAQUINAS.TXT"<<endl;
        exit(-1);	}
        
        while(getline(f4,id_maquina_,',')){
			getline(f4,cpu,',');
	        getline(f4,ram,',');
	        getline(f4,recursos_disp_ram,',');
	        getline(f4,recursos_disp_cpu,',');
	        getline(f4,cluster,'\n');
	    	cout<<"Id_Maquina:"<<id_maquina_<<","<<"Cpu:"<<cpu<<","<<"Ram:"<<ram<<","<<"Recursos disponibles ram:"<<recursos_disp_ram<<","<<"Recursos disponibles cpu:"<<recursos_disp_cpu<<","<<"Cluster:"<<cluster<<endl;
	    }
	    f4.close();
}
