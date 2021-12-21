#include <iostream>
#include <string>
#include "Reserva.h"
#include "Usuario.h"
#include "Maquina.h"
#include "AdministradorUsuario.h"
#include "AdministradorMaquina.h"
#include <vector>
#include <fstream>
#include <cstdlib>


using namespace std;

int main()
{
	Usuario us;
	Reserva reser;
	Maquina m;
	string correo_, pass;
	std::cout<<"**Inicio de Sesion**\n";
	

	std::cout<<"Correo: \n";
	cin>>correo_;

	std::cout<<"Contrasena: \n";
	cin>>pass;
	
	int i=0;
	i++;

	if(us.iniciar_sesion(correo_, pass))
	{
		bool salir= false;
		bool salir_Usuarios= false;
		bool salir_Reserva= false;
		bool salir_Maquina= false;
		while(!salir)
		{
			cout<<endl<<endl;
			cout<<"1 Gestion de usuarios\n";
			cout<<"2 Gestion de reservas\n";
			cout<<"3 Gestion de maquinas\n";
			cout<<"4 Salir\n";
			char op;

			cout<<"Mete la opcion\n";
			cin>>op;
			
			switch (op)
			{
				//Menu Gestion De Usuarios
				case '1':
				{
					if(us.getipo()!=1){
						cout<<"Error no es Administrador de Usuarios"<<endl;
						exit(-1);
					}
					AdministradorUsuario gest;	
					while(!salir_Usuarios)
					{
						cout<<endl<<endl;
						cout<<"1 Crear usuario\n";
						cout<<"2 Modificar usuario\n";
						cout<<"3 Eliminar usuario\n";
						cout<<"4 Salir\n";
						char op_u;

						//cout<<"Mete la opcion\n";
						cin>>op_u;
						switch (op_u)
						{
							case '1':
							{	
								gest.crearusuario();
								break;
							}
							case '2':
							{
								gest.modificarusuario();
								break;
							}
							case '3':
							{
								gest.eliminarusuario();
								break;
							}
							
							default:
							{
								cout<<"[ERROR] La opcion selecionada no existe.\n";
								break;
							}
							case '4':
							{
								cout <<"salirrr";
								salir_Usuarios=true;
								break;
							}
						}

					}
					break;
				}
				//Menu Gestion De Reservas
				case '2':
				{
					
					while(!salir_Reserva)
					{
						cout<<"1 Crear Reserva\n";
						cout<<"2 Actualizar Reserva\n";
						cout<<"3 Mostrar listado maquinas y recursos disponibles \n";
						cout<<"4 Ver reservas\n";
						cout<<"5 Salir\n";
						char op_r;

						cout<<"Mete la opcion\n";
						cin>>op_r;
						switch (op_r)
						{
							case '1':
							{
								int id_reserva=1;
								string fecha_inicio;
								string fecha_fin;
								int recursos_ram;
								int recursos_cpu;
								int id_maquina;

								cout<<"Que maquina quieres reservar: ";
								m.mostrar_maquinas();
								cin>>id_maquina;
								cout<<"Introduce la fecha de inicio (dd/mm/yyyy)";
								cin>>fecha_inicio;
								cout<<"Introduce la fecha de final (dd/mm/yyyy)";
								cin>>fecha_fin;
								cout<<"Cuantos nucleos de cpu quieres reservar?";
								cin>>recursos_cpu;
								cout<<"Cuanta ram quieres reservar?";
								cin>>recursos_ram;

								reser.crear_reserva(id_reserva,fecha_inicio, fecha_fin, correo_, recursos_ram, recursos_cpu, id_maquina);
								cout<<"Reserva realizada correctamente";
								break;
							}
							case '2':
							{
								
								break;
							}
							case '3':
							{
								m.mostrar_maquinas();
								break;
							}
							case '4':
							{
								
								break;
							}
							default:
							{
								std::cout<<"[ERROR] La opcion selecionada no existe.\n";
								break;
							}
							case '5':
							{
								//salida
								salir_Reserva=true;
								break;
							}
						}//Fin switch

					}//Fin while
					break;
				}
				//Menu Gestion De maquinas
				case '3':
				{	
					if(us.getipo()!=2){
						cout<<"Error no es Administrador de Maquinas"<<endl;
						exit(-1);
					}
					while(!salir_Maquina)
					{
						cout<<"1 Crear Maquina\n";
						cout<<"2 Modificar Maquina\n";
						cout<<"3 Eliminar Maquina\n";
						cout<<"4 Salir\n";
						char op_m;

						cout<<"Mete la opcion\n";
						cin>>op_m;
						switch (op_m)
						{
							case '1':
							{
								
							}
							case '2':
							{
								
								break;
							}
							case '3':
							{
								
								break;
							}
							
							default:
							{
								std::cout<<"[ERROR] La opcion selecionada no existe.\n";
								break;
							}
							case '4':
							{
								//salida
								salir_Maquina=true;
								break;
							}
						}//Fin switch

					}//Fin while
					break;					
				}
				default:
				{
					std::cout<<"[ERROR] La opcion selecionada no existe.\n";
					break;
				}
				//Salir
				case '4':
				{
					salir=true;
					break;
				}
			}
		}
		
	}
	else
	{
		std::cout<<"[ERROR] La contraseña o el usuario son incorrectos.\n";
	}

	return 0;
}
