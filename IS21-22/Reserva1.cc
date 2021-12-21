#include "Reserva1.h"
void Reserva::crear_reserva(int id_reserva,string fecha_inicio,string fecha_fin,string correo,int recursos_ram,int recursos_cpu,int id_maquina){

//comprueba que no haya otra reserva igual o con el mismo id
string id_reserva_,fecha_inicio_,fecha_fin_,correo_,recursos_ram_,recursos_cpu_,id_maquina_;
ifstream f(("reservas.txt"));
	 if(!f.is_open()){
	 	cout<<"ERROR AL ABRIR EL ARCHIVO RESERVAS.TXT"<<endl;
        exit(-1);	}
        
        while(getline(f,id_reserva_,',')){
			getline(f,fecha_inicio_,',');
	        getline(f,fecha_fin_,',');
	        getline(f,correo_,',');
	        getline(f,recursos_ram_,',');
	        getline(f,recursos_cpu_,',');
	        getline(f,id_maquina_,'\n');
	        	if(stoi(id_reserva_)==id_reserva){
	        		cout<<"ERROR HAY UNA RESERVA IGUAL O CON EL MISMO ID"<<endl;
	        		exit(EXIT_FAILURE);					}
	        	
	        	if((fecha_inicio_==fecha_inicio) && (fecha_fin_==fecha_fin) && (stoi(recursos_ram_)==recursos_ram) && (stoi(recursos_cpu_)==recursos_cpu) && (stoi(id_maquina_)==id_maquina) ){	
	        		cout<<"ERROR HAY UNA RESERVA IGUAL O CON EL MISMO ID"<<endl;
	        		exit(EXIT_FAILURE);						} }
	    f.close();

//fin de la comprobacion

//comprueba que la fecha de fin no sea anterior que la fecha de inicio

string dia_inicio,dia_fin,mes_inicio,mes_fin,ano_inicio,ano_fin;

dia_inicio=fecha_inicio.substr(0,2);
mes_inicio=fecha_inicio.substr(3,2);
ano_inicio=fecha_inicio.substr(6,4);
dia_fin=fecha_inicio.substr(0,2);
mes_fin=fecha_inicio.substr(3,2);
ano_fin=fecha_inicio.substr(6,4);

int a=stoi(ano_inicio),b=stoi(ano_fin);
if(a<=b){
	
	a=stoi(mes_inicio);
	b=stoi(mes_fin);
	
	if(a<=b){
	
	a=stoi(dia_inicio);
	b=stoi(dia_fin);

	if(a>b){
		cout<<"ERROR LA FECHA DE FIN ES ANTERIOR A LA DE INICIO"<<endl;
	exit(EXIT_FAILURE); }
				}
	else{
	cout<<"ERROR LA FECHA DE FIN ES ANTERIOR A LA DE INICIO"<<endl;
	exit(EXIT_FAILURE);
		}
}
else{
	cout<<"ERROR LA FECHA DE FIN ES ANTERIOR A LA DE INICIO";
	exit(EXIT_FAILURE);
} //Fin de la comprobacion

//Comprueba los limites del usuario
int limites;
string nombre,correo__,password_,limite,tipo;
ifstream f1(("usuarios.txt")); //busco el usuario y veo cual es su limite
	 if(!f1.is_open()){
	 	cout<<"ERROR AL ABRIR EL ARCHIVO USUARIO.TXT"<<endl;
        exit(-1);	}
        
        while(getline(f1,nombre,',')){
			getline(f1,correo__,',');
	        getline(f1,password_,',');
	        getline(f1,limite,',');
	        getline(f1,tipo,'\n');
	        	if(correo__==correo){
	        		limites=stoi(limite);
	        							}	
	        								}
	        f1.close();

//leo el archivo reservas para contar cuantas reservas tiene hechas ese usuario

int nreservas=0;
ifstream f2(("reservas.txt"));
	 if(!f2.is_open()){
	 	cout<<"ERROR AL ABRIR EL ARCHIVO RESERVAS.TXT"<<endl;
        exit(-1);	}
        
        while(getline(f2,id_reserva_,',')){
			getline(f2,fecha_inicio_,',');
	        getline(f2,fecha_fin_,',');
	        getline(f2,correo_,',');
	        getline(f2,recursos_ram_,',');
	        getline(f2,recursos_cpu_,',');
	        getline(f2,id_maquina_,'\n');
	        	if(correo_==correo){
	        		nreservas++;
	        							}	
	        								}
	    f2.close();

//compruebo que nreservas sea menor que limites para ver si el usuario supera sus limites

if(nreservas>limites){
	cout<<"Ha superado el límite de reservas"<<endl;
	exit(EXIT_FAILURE);
}

//fin de la comprobacion de los limites del usuario

//Compruebo si supera los recursos de las maquinas

int recursos_ram_disponibles,recursos_cpu_disponibles;
string id_maquina__,cpu,ram,recursos_disp_ram,recursos_disp_cpu,cluster;
ifstream f3(("maquinas.txt")); //Leo el archivo recursos para ver los recursos disponibles de la máquina y ademas compruebo si existe la maquina
	 if(!f3.is_open()){
	 	cout<<"ERROR AL ABRIR EL ARCHIVO MAQUINAS.TXT"<<endl;
        exit(-1);	}
        
        while(getline(f3,id_maquina__,',')){
			getline(f3,cpu,',');
	        getline(f3,ram,',');
	        getline(f3,recursos_disp_ram,',');
	        getline(f3,recursos_disp_cpu,',');
	        getline(f3,cluster,'\n');
	        	if(stoi(id_maquina__)==id_maquina){
	        		recursos_ram_disponibles=stoi(recursos_disp_ram);
	        		recursos_cpu_disponibles=stoi(recursos_disp_cpu);
	        							}
	        	else{
	        		cout<<"La maquina en la que quiere realizar la reserva no existe"<<endl;
	        		exit(-1);}	
	        								}
	    f3.close();

//Compruebo que los recursos que se quieren reservar no superen a los que se quiere reservar y sino recomendar otra maquina en la que se pueda realizar la reserva
if(recursos_ram_disponibles<recursos_ram || recursos_cpu_disponibles<recursos_cpu){
	cout<<"Se superan los recursos de la maquina"<<endl;

	ifstream f4(("maquinas.txt")); //Leo el archivo maquina para ver en que maquina si se puede realizar la reserva 
	 if(!f4.is_open()){
	 	cout<<"ERROR AL ABRIR EL ARCHIVO MAQUINAS.TXT"<<endl;
        exit(-1);	}
        
        while(getline(f4,id_maquina_,',')){
			getline(f4,cpu,',');
	        getline(f4,ram,',');
	        getline(f4,recursos_disp_ram,',');
	        getline(f4,recursos_disp_cpu,',');
	        getline(f4,cluster,'\n');
	        	if( (stoi(recursos_disp_ram)>recursos_ram) && (stoi(recursos_disp_cpu)>recursos_cpu) ){
	        		cout<<"En la maquina con id: "<<id_maquina_<<" se puede realizar la reserva";
	        		exit(EXIT_FAILURE);
	        							}
	        	else{ cout<<"No hay ninguna maquina en la que se pueda realizar la reserva "<<endl;}	
	        								}
	    f.close();


}   

//Actualizo los recursos disponibles de la maquina
int recursos_ram_act,recursos_cpu_act;
ifstream f5(("maquinas.txt"));
ofstream ft(("maquinastemp.txt")); //Leo el archivo maquina y a la vez voy escribiendo en un archivo temporal 
	 if(!f5.is_open() || !ft.is_open()){
	 	cout<<"ERROR AL ABRIR EL ARCHIVO MAQUINAS.TXT O MAQUINASTEMP.TXT"<<endl;
        exit(-1);	}
        
        while(getline(f5,id_maquina_,',')){
			getline(f5,cpu,',');
	        getline(f5,ram,',');
	        getline(f5,recursos_disp_ram,',');
	        getline(f5,recursos_disp_cpu,',');
	        getline(f5,cluster,'\n');
	        	if(stoi(id_maquina_)==id_maquina){
	        		recursos_ram_act=stoi(recursos_disp_ram)-recursos_ram;
	        		recursos_cpu_act=stoi(recursos_disp_cpu)-recursos_cpu;
	        		ft<<id_maquina<<","<<cpu<<","<<ram<<","<<recursos_ram_act<<","<<recursos_cpu_act<<","<<cluster<< endl;
	        							}
	        	else{ ft<<id_maquina_<<","<<cpu_<<","<<ram_<<","<<recursos_disp_ram<<","<<recursos_disp_cpu<<","<<cluster<< endl; }	
	        								}
	    f5.close();
	    ft.close();
	    remove("maquinas.txt");
	    rename("maquinastemp.txt","maquinas.txt");

//Por ultimo anado la reserva al fichero de reservas 

fstream file;
    file.open("reservas.txt", std::ios_base::app | std::ios_base::in);
    if (file.is_open()){
    file<<id_reserva<<","<<fecha_inicio<<","<<fecha_fin<<","<<correo<<","<<recursos_ram<<","<<recursos_cpu<<","<<id_maquina<<endl;
}
	else{
		std::cout<<"ERROR"<<endl; 
		exit(EXIT_FAILURE);}
 	file.close();
 	
 	cout<<"Reserva realizada con exito"<<endl;
 } 