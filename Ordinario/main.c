/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: esauzavaleta
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
struct agenda {
	char nom[15];
	int fecha;
	int hora;
        int duracion;
	char dir[30];
        char tema[40];
} control[100];

int cont = 0;
 
void agregar();
void modificarEvento();
void modificarEventoH();
void eliminar();
void buscar();
void listar();
void listaD();
void listar();


FILE*archivo;

main(){
	int opc;
 
	do{
		
 
		printf("\t\tDigite una opcion\n\n");
		printf("1.Nuevo evento\n");
		printf("2.Modificar evento\n");
                printf("3.Modificar Horario de evento\n");
                printf("4.Eliminar evento\n");
		printf("5.Ver todos los eventos\n");
                printf("6.Ver todos los eventos por dia\n");
                printf("7.Buscar evento por nombre\n");
		printf("8.Salir\n");
 
		scanf("%d", &opc);
 
		switch(opc){
		case 1:
		        agregar();
			
			break;
 
		case 2:
			modificarEvento();
			
			break;
 
		case 3:
			modificarEventoH();
			
			break;
                        
                case 4:
                        eliminar();
			
			break;
                        
                case 5:
		        listar();
			
			break;
                        
                case 6:
			listaD();
			
			break;
                        
                case 7:
			buscar();
			
			break;
		}
	}while(opc!=8);
 
	return 0;
}
 
//Numero 1
void agregar(){
	
     archivo = fopen("agenda.rtf","ad");
	fflush(stdin);
	printf("\nNombre del evento:", (cont+1));
	gets(control[cont].nom);
 
	fflush(stdin);
	printf("\nFecha:");
	scanf("%d", &control[cont].fecha);
 
	fflush(stdin);
	printf("\nHora:");
	scanf("%d", &control[cont].hora);
        fflush(stdin);
	printf("\nDuracion del evento:");
	scanf("%d", &control[cont].duracion);
 
	fflush(stdin);
	printf("\nLugar:");
	gets(control[cont].dir);
 
	fflush(stdin);
	printf("\nTema:");
	gets(control[cont].tema);
 
	cont++;
        
      fclose(archivo);
      
}

//Numero 2
void modificarEvento(){
    
    FILE*fp;
    
    printf("Se modificará un evento");
 	
 	fp = fopen ( "agenda.rtf", "r+" );
        
        
 	char nombre[100] = "Escriba en el evento.";
 	fprintf(fp, nombre);
 	fprintf(fp, "%s", "\nSeguimos escribiendo en el archivo.");
 	
 	fclose ( fp );
        
}

//Numero 3
void modificarEventoH(){
    
    FILE*fp;
    
    printf("Se modificará la hora de un evento");
 	
 	fp = fopen ( "agenda.rtf", "r+" );
        
    printf("Escriba la nueva hora\n");    
 	int hora = scanf("&hora");
 	fprintf(fp, hora);
 	fprintf(fp, "%d", "\nSeguimos escribiendo en el archivo.");
 	
 	fclose ( fp );
        
}

//Numero 4
void eliminar(){
    int nm = 0;
    char nombre[100];
    char registro;
    int hora,min;
    int opcion;
    
    FILE*eliminar;
    
    listar();
    printf("Ingresa el nombre del evento que desee eliminar\n");
    scanf("%c",&registro);
    scanf("%[^\n]",&nombre);
    archivo = fopen("datos.dat","rd");
    
    eliminar = fopen("eliminar.dat","ad");
    while(feof(archivo) == 0){
        fread(&control[nm],sizeof(control[nm]),1,archivo);
        if (strcmp(nombre, control[nm].nom) == 0){
            
            printf("\n\nFecha del evento:");
            printf("%d/%d/%d\n",control[nm].fecha,control[nm].fecha,control[nm].fecha);
            printf("Nombre del evento: %s\nHora del evento:%d:",control[nm].nom, control[nm].hora);
            
            printf("%d\n\n",control[nm].hora);
            printf("¿Quiere eliminar ese evento?\n");
            printf("1. Si\n2. No\n");
            scanf("%d",&opcion);
            if(opcion == 2){
                printf("\nEl evento no ha sido eliminado ha eliminado\n\n");
                fclose(eliminar);
                
            }
                        

            fwrite(&control[nm],sizeof(control[nm]),1,eliminar);
            fclose(eliminar);
            fclose(archivo);
            printf("\nEl evento se ha eliminado correctamente\n\n");
            
        }
        nm++;
    }
    printf("\n\nDigite de manera correcta el nombre del evento\n");
    
    fclose(archivo);
}

//Numero 5
void listar(){
	int aux, i, j;
	char auxc[50];
 
	
        archivo = fopen("agenda.rtf","rd");
	for(i = 0; i < cont - 1;  i++){
		for(j = 0; j < cont - 1 - i; j++){
			if(strcmp(control[j].nom,control[j+1].nom)>0){
 
				strcpy(auxc,control[j].nom);
				strcpy(control[j].nom,control[j+1].nom);
				strcpy(control[j+1].nom,auxc);
 
				aux = control[j].fecha;
				control[j].fecha = control[j+1].fecha;
				control[j+1].fecha = aux;
 
				aux = control[j].hora;
				control[j].hora = control[j+1].hora;
				control[j+1].hora = aux;
                                
                                aux = control[j].duracion;
				control[j].duracion = control[j+1].duracion;
				control[j+1].duracion = aux;
 
				strcpy(auxc,control[j].dir);
				strcpy(control[j].dir,control[j+1].dir);
				strcpy(control[j+1].dir,auxc);
 
				strcpy(auxc,control[j].tema);
				strcpy(control[j].tema,control[j+1].tema);
				strcpy(control[j+1].tema,auxc);
 
			}
		}
	}
 
	printf("\nAgenda.\n");
 
	for(i=0;i<cont;i++){
		printf("\n%d.Nombre del evento: %s\n",(i+1), control[i].nom);
		printf("Fecha: %d\n", control[i].fecha);
		printf("Hora: %d\n", control[i].hora);
                printf("Duracion del evento: %d\n", control[i].duracion);
		printf("Lugar: %s\n", control[i].dir);
		printf("Tema: %s\n", control[i].tema);
	}
        
 fclose(archivo);
 
} 

//Numero 6
void listaD(){
    int fecha;
    int d = 0;
    int i = 0;

    printf("Digite la fecha del evento\n");
    printf("Dia: ");
    scanf("%d", &fecha);

    
    archivo = fopen("agenda.rtf","rd");
    
    printf("\n");
    while(feof(archivo) == 0){
        fread(&control[d],sizeof(control[d]),1,archivo);
        d++;
    }
    
    while(i<d){
        
        if (fecha == control[i].fecha){
            printf("%d \n",control[i].fecha,control[i]);
            printf("%d \n",control[i].hora, control[i].nom);
        }
        i++;
    }
    
    fclose(archivo);
    
    printf("\n");
    
}

//Numero 7
void buscar(){
	char busca[15];
	int i;
 
	archivo = fopen("agenda.rtf","rd");
 
	fflush(stdin);
	printf("\nBuscar evento \nIngrese el nombre del evento:");
	gets(busca);
 
	for(i = 0; i < cont; i++){
		if(strcmp(busca,control[i].nom) == 0){
			printf("\nNombre del evento: %s\n", control[i].nom);
			printf("Fecha: %d\n", control[i].fecha);
			printf("Hora: %d\n", control[i].hora);
                        printf("Duracion del evento: %d\n", control[i].duracion);
			printf("Lugar: %s\n", control[i].dir);
			printf("Tema: %s\n", control[i].tema);
		}
	}
        
 fclose(archivo);
 
}