#include "Usuario.h"


bool Usuario::iniciar_sesion(string correo,string password){		
	string nombre,correo_,password_,limite,tipo;
	ifstream f(("usuarios.txt"));
	 if(!f.is_open()){
	 	cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        exit(-1);	}
        while(getline(f,nombre,',')){
		getline(f,correo_,',');
        getline(f,password_,',');
        getline(f,limite,',');
        getline(f,tipo,'\n');
        if( (correo_==correo) && (password_==password)){
        	return true;
        }
    								}
    	f.close();
    	return false;


}
