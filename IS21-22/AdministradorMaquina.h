#ifndef ADMINISTRADORMAQUINA_H
#define ADMINISTRADORMAQUINA_H

#include "Usuario.h"

class AdministradorMaquina: public Usuario
{
	
	public:
    		void crearmaquina(const int id_maquina,const int cpu,const int ram,const int cluster);
    		void modificarmaquina(const int id_maquina,int cpu,int ram,int cluster);
    		void eliminarmaquina(const int id_maquina);
}

#endif