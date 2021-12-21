#include "AdministradorUsuario.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

void AdministradorUsuario::crearusuario()
{
	string nombre1,correo1,password1,limite1,tipo1;
	cout<<"Introduce el nombre del nuevo usuario"<<endl;
	cin>>nombre1;
	cout<<"Introduce el correo del nuevo usuario"<<endl;
	cin>>correo1;
	cout<<"Introduce la password del nuevo usuario"<<endl;
	cin>>password1;
	cout<<"Introduce el limite del nuevo usuario"<<endl;
	cin>>limite1;
	cout<<"Introduce el tipo del nuevo usuario"<<endl;
	cin>>tipo1;
	
	string nombre_,correo_,password_,limite_,tipo_;
	ifstream f(("usuarios.txt"));
	 if(!f.is_open()){
	 	cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        exit(-1);	}
        while(getline(f,nombre_,',')){
		getline(f,correo_,',');
        getline(f,password_,',');
        getline(f,limite_,',');
        getline(f,tipo_,'\n');
        if( (correo_==correo1)){
        	cout<<"ERROR YA EXISTE ESE USUARIO EN EL SISTEMA"<<endl;
        	exit(-1);
        }							}
    	f.close();
	fstream file;
    file.open("usuarios.txt", std::ios_base::app | std::ios_base::in);
    if (file.is_open()){
    file<<nombre1<<","<<correo1<<","<<password1<<","<<limite1<<","<<tipo1<<endl;
}
	else{
		std::cout<<"ERROR"<<endl; 
		exit(EXIT_FAILURE);}
 	file.close();
 	
 	cout<<"Usuario creado con exito"<<endl;
 } 
void AdministradorUsuario::eliminarusuario(){
	string nombre_,correo_,password_,limite_,tipo_,correo1;
	int existe=0;
	cout<<"Introduce el correo del usuario que quiere eliminar"<<endl;
	cin>>correo1;
	ifstream f(("usuarios.txt"));
	 if(!f.is_open()){
	 	cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        exit(-1);	}
        while(getline(f,nombre_,',')){
		getline(f,correo_,',');
        getline(f,password_,',');
        getline(f,limite_,',');
        getline(f,tipo_,'\n');
        if( (correo_==correo1)){
        	existe=1;
        }							}
    	f.close();
    	if(existe==0){
    		cout<<"El usuario que quiere eliminar no existe"<<endl;
             exit(-1);
    	}
    
    ifstream f1(("usuarios.txt"));
    ofstream ft(("usuariostemp.txt"));
	 if(!f1.is_open()){
	 	cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        exit(-1);	}
        while(getline(f1,nombre_,',')){
		getline(f1,correo_,',');
        getline(f1,password_,',');
        getline(f1,limite_,',');
        getline(f1,tipo_,'\n');
        if( (correo_==correo1)){
        }	
        else{
        	ft<<nombre_<<","<<correo_<<","<<password_<<","<<limite_<<","<<tipo_<<endl;
        }						}
       	f1.close();
	    ft.close();
	    remove("usuarios.txt");
	    rename("usuariostemp.txt","usuarios.txt");
	    cout<<"Usuario eliminado con exito"<<endl;
    }
	
void AdministradorUsuario::modificarusuario(){
	string nombre_,correo_,password_,limite_,tipo_,correo1;
	Usuario u;
	int existe=0;
	cout<<"Introduce el correo del usuario que quiere modificar"<<endl;
	cin>>correo1;
	ifstream f(("usuarios.txt"));
	 if(!f.is_open()){
	 	cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        exit(-1);	}
        while(getline(f,nombre_,',')){
		getline(f,correo_,',');
        getline(f,password_,',');
        getline(f,limite_,',');
        getline(f,tipo_,'\n');
        if( (correo_==correo1)){
        	existe=1;
        	u.setnombre(nombre_);
        	u.setcorreo(correo_);
        	u.setcorreo(password_);
        	u.setlimite(stoi(limite_));
        	u.settipo(stoi(tipo_));
        }							}
    	f.close();
    	if(existe==0){
    		cout<<"El usuario que quiere modificar no existe"<<endl;
            exit(-1);
    	}
    	int opcion;
    	cout<<"¿Que campo quiere modificar? 1.Nombre  2.Correo 3.Password 4.Limite 5.Tipo"<<endl;
    	cin>>opcion;
    	switch(opcion){
    		case 1:
    		cout<<"Introduzca el nuevo nombre"<<endl;
    		cin>>nombre_;
    		u.setnombre(nombre_);
    		break;
    		case 2:
    		cout<<"Introduzca el nuevo correo"<<endl;
    		cin>>correo_;
    		u.setnombre(correo_);
    		break;
    		case 3:
    		cout<<"Introduzca el nuevo password"<<endl;
    		cin>>password_;
    		u.setnombre(password_);
    		break;
    		case 4:
    		cout<<"Introduzca el nuevo limite"<<endl;
    		cin>>limite_;
    		u.setlimite(stoi(limite_));
    		break;
    		case 5:
    		cout<<"Introduzca el nuevo tipo"<<endl;
    		cin>>tipo_;
    		u.settipo(stoi(tipo_));
    		break;
    		default: cout<<"Error ha introducido una opcion que no existe. Recuerde que debe ser un numero"<<endl;
    	}
    ifstream f1(("usuarios.txt"));
    ofstream ft(("usuariostemp.txt"));
	 if(!f1.is_open()){
	 	cout<<"ERROR AL ABRIR EL ARCHIVO"<<endl;
        exit(-1);	}
        while(getline(f1,nombre_,',')){
		getline(f1,correo_,',');
        getline(f1,password_,',');
        getline(f1,limite_,',');
        getline(f1,tipo_,'\n');
        if( (correo_==correo1)){
        	ft<<u.getnombre()<<","<<u.getcorreo()<<","<<u.getpassword()<<","<<u.getlimite()<<","<<u.getipo()<<endl;
        }	
        else{
        	ft<<nombre_<<","<<correo_<<","<<password_<<","<<limite_<<","<<tipo_<<endl;
        }						}

       	f1.close();
	    ft.close();
	    remove("usuarios.txt");
	    rename("usuariostemp.txt","usuarios.txt");
	    cout<<"Usuario actualizado con exito"<<endl;
    }

