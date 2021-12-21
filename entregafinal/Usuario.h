#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

class Usuario
{

	private:

	string nombre;
	string correo;
	string password;
	int limite;
	int tipo;

	public:

	//get y set

	inline string getnombre() const{return nombre;}
	inline string getcorreo() const{return correo;}
	inline string getpassword() const{return password;}
	inline int getlimite() const{return limite;}
	inline int getipo() const{return tipo;}

	inline void setnombre(const string nombre_){nombre=nombre_;}
	inline void setcorreo(const string correo_){correo=correo_;}
	inline void setpassword(const string password_){password=password_;}
	inline void setlimite(const int limite_){limite=limite_;}
	inline void settipo(const int tipo_){tipo=tipo_;}

	//inline int getipo(int tipo);

	//metodos

	bool iniciar_sesion(string Correo, string password);
	bool comprobar_limites(int limite, string correo);


};
#endif