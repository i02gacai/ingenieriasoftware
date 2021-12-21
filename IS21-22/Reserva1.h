#ifndef RESERVA_H
#define RESERVA_H
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

class Reserva
{

	private:
	int id_reserva;
	string fecha_inicio;
	string fecha_fin;
	string correo;
	int recursos_ram;
	int recursos_cpu;
	int id_maquina;

	public:

	//get y set
	inline int getid_reserva() const{return id_reserva;}
	inline string getfecha_inicio() const{return fecha_inicio;}
	inline string getfecha_fin() const{return fecha_fin;}
	inline string getcorreo() const{return correo;}
	inline int getrecursos_ram() const{return recursos_ram;}
	inline int gerecursos_cpu() const{return recursos_cpu;}
	inline int getid_maquina() const{return id_maquina;}

	inline void setid_reserva(const int id_reserva_) {id_reserva=id_reserva_;}
	inline void setfecha_inicio(const string fecha_inicio_) {fecha_inicio=fecha_inicio_;}
	inline void setfecha_fin(const string fecha_fin_) {fecha_fin=fecha_fin_;}
	inline void setcorreo(const string correo_) {correo=correo_;}
	inline void setrecursos_ram(const int recursos_ram_) {recursos_ram=recursos_ram_;}
	inline void serecursos_cpu(const int recursos_cpu_) {recursos_cpu=recursos_cpu_;}
	inline void setid_maquina(const int id_maquina_) {id_maquina=id_maquina_;}

	//inline int getipo(int tipo);

	//metodos

	void crear_reserva(int id_reserva,string fecha_inicio,string fecha_fin,string correo,int recursos_ram,int recursos_cpu,int id_maquina);
	void modificar_reserva(int id_reserva,string fecha_inicio,string fecha_fin,string correo,int recursos_ram,int recursos_cpu,int id_maquina);
	bool eliminar_reserva(int id_reserva);


};
#endif