#include <iostream>
#include <string>
#include "Maquina.cc"
#include "Reserva1.cc"
#include "Usuario.cc"
#include "Maquina.cc"
//#include "CrearUsuario.cc"
//#include "Listado.h"
#include <vector>
#include <fstream>
#include <cstdlib>


using namespace std;

int main()
{
	//Array maquina
	Maquina m;
	
	Maquina *arr = new Maquina[m.getid_maquina()];
	Usuario usu;
	Reserva reser;
	//Listado list;
	
	m.cargar_maquinas(arr);
	string correo, pass;
	std::cout<<"**Inicio de Sesion**\n";
	

	std::cout<<"Correo: \n";
	cin>>correo;

	std::cout<<"Contrasena: \n";
	cin>>pass;
	
	int i=0;
	i++;

	if(usu.iniciar_sesion(correo, pass))
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
					
					while(!salir_Usuarios)
					{
						cout<<endl<<endl;
						cout<<"1 Crear usuario\n";
						cout<<"2 Modificar usuario\n";
						cout<<"3 Eliminar usuario\n";
						cout<<"4 Perfil\n";
						cout<<"5 Salir\n";
						char op_u;

						//cout<<"Mete la opcion\n";
						cin>>op_u;
						switch (op_u)
						{
							case '1':
							{
								
								break;
							}
							case '2':
							{
								
								break;
							}
							case '3':
							{
								
								break;
							}
							case '4':
							{
								
								break;
							}
							default:
							{
								cout<<"[ERROR] La opcion selecionada no existe.\n";
								break;
							}
							case '5':
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
						cout<<"2 Modificar Reserva\n";
						cout<<"3 Eliminar Reserva\n";
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
								m.mostrar_maquinas(arr);
								cin>>id_maquina;
								cout<<"Introduce la fecha de inicio (dd/mm/yyyy)";
								cin>>fecha_inicio;
								cout<<"Introduce la fecha de final (dd/mm/yyyy)";
								cin>>fecha_fin;
								cout<<"Cuantos nucleos de cpu quieres reservar?";
								cin>>recursos_cpu;
								cout<<"Cuanta ram quieres reservar?";
								cin>>recursos_ram;

								//reser.crear_reserva(id_reserva,fecha_inicio, fecha_fin, correo, recursos_ram, recursos_cpu, id_maquina);
								cout<<"Reserva realizada correctamente";
								break;
							}
							case '2':
							{
								
								break;
							}
							case '3':
							{
								
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
					while(!salir_Maquina)
					{
						cout<<"1 Crear Maquina\n";
						cout<<"2 Modificar Maquina\n";
						cout<<"3 Eliminar Maquina\n";
						cout<<"4 Ver Maquina\n";
						cout<<"5 Salir\n";
						char op_m;

						cout<<"Mete la opcion\n";
						cin>>op_m;
						switch (op_m)
						{
							case '1':
							{
								int cpu, ram, cluster, recursos_disp_cpu, recursos_disp_ram;

								std::cout<<"Cpu: ";
								cin>>cpu;

								std::cout<<"Ram: ";
								cin>>ram;

								std::cout<<"Cluster: ";
								cin>>cluster;

								std::cout<<"Cpu disponible: ";
								cin>>recursos_disp_cpu;

								std::cout<<"Ram disponible: ";
								cin>>recursos_disp_ram;
								//crear maquina
								m.subir_maquinas(m.getid_maquina(), cpu, ram, recursos_disp_cpu, recursos_disp_ram, cluster);
								m.cargar_maquinas(arr);
								break;
							}
							case '2':
							{
								
								break;
							}
							case '3':
							{
								
								break;
							}
							case '4':
							{
								//list.IntroducirUsuario();
								m.mostrar_maquinas(arr);
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
/*
void escribe_maquinas(Maquina::Maquina *arr)
{
	
}

void carga_maquinas(Maquina *arr)
{
	ofstream m;
	m.open("maquina.txt");
	
	if(!m)
	{
		cout<<"Error al abrir el archivo";
		exit(0);
	}
	else
	{
		for(int i=0;i>sizeof arr;i++)
		{
			getline(m, arr[i].getid_maquina());
			m >> arr[i].getid_maquina() >> endl;
			m >> arr[i].getcpu() >> endl;
			m >> arr[i].getram() >> endl;
			m >> arr[i].getrecuersos_disp_cpu() >> endl;
			m >> arr[i].getrecuersos_disp_ram() >> endl;
			m >> arr[i].getcluster() >> endl;
		}
	}
	m.close();
}*/