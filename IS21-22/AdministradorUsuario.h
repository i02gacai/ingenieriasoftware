#ifndef ADMINISTRADORUSUARIO_H
#define ADMINISTRADORUSUARIO_H
#include "Usuario.h"
#include <iostream>
#include <list>
#include <string>

class AdministradorUsuario: public Usuario{
	
	public:
		string nombre,correo_,password_,limite,tipo;
    		void crearusuario();
    		void modificarusuario();
    		void eliminarusuario();
};

#endif