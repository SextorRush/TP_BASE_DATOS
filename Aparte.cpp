#include <iostream>
#include <algorithm>

using namespace std;
   

struct dato{
    int clave;
    string valor;
    dato * dir;
};

struct DatoIndice{
    int clave;
    dato *dir;
};

dato TablaDatos[30];
DatoIndice TablaIndices[5];
dato a;

//Devuelve espacios libres en la tabla de datos
int EspacioLibre(int a){
    int contador_bloke=0;
    
    for (int i=a;i<4;i++){
        if(TablaDatos[i].clave==0)contador_bloke++;
    }
    return contador_bloke;}
//Devuelve espacios ocupados en la tabla de datos
int EspacioOcupado(int a){
    int contador_bloke=0;
    
    for (int i=a;i<4;i++){
        if(TablaDatos[i].clave!=0)contador_bloke++;
    }
    cout<<contador_bloke;
    return contador_bloke;}

//envia al overflow
void enviar_al_overflow(){
for(int i=20;i<30;i++){
    if(TablaDatos[i].clave==0){
        TablaDatos[i].clave=a.clave;
        TablaDatos[i].valor=a.valor;
        TablaDatos[i].dir=nullptr;
    } else {
        cout<<"Overflow lleno";
    }
}
}
//verifica bloques libres, devuelve la posición del primer bloque libre
int BlokeLibre(){
int aux = 0;
for(int i=0;i<4;i++){
    if(TablaIndices[i].clave==0){
        aux=i;

        return aux;
    }
}
return aux;
}
//ordena el bloque de la tabla de datos

void ordenar(int a) {

    for (int i=a; i < 3; i++) {  // Solo los primeros 4 elementos (índices 0 a 3)
        int minAux = i;  
         for (int j = i + 1; j < 4; j++) {  
             if (TablaDatos[j].clave < TablaDatos[minAux].clave) {  
                 minAux = j;  
              }
          }
         // Intercambiamos las estructuras completas
          swap(TablaDatos[i], TablaDatos[minAux]);  
      }
 }

//busca el maximo del bloque de la tabla de datos
bool buscar_max(int b){
bool flag=false;
for(int i=b;i<4;i++){
    if(TablaDatos[i].clave>a.clave){
        flag=true;
        return flag;
    }
}
return flag;
}

void insertar(dato a){
    
    int aux;//Almacena el valor de EspacioOcupado
    int aux2;//Almacena el valor de EspacioLibre
    int Pos_bloque;//Almacena el valor de BlokeLibre
    //inserta si la tabla de indices esta vacia
    if(TablaIndices[0].clave==0){
        TablaDatos[0].clave=a.clave;
        TablaDatos[0].valor=a.valor;
        TablaDatos[0].dir=nullptr;
        TablaIndices[0].clave=a.clave;
        TablaIndices[0].dir=&TablaDatos[0];}
    //si la tabla de indices no esta vacia,primer bloque
    else if(((TablaIndices[0].clave < a.clave))||
        ((TablaIndices[0].clave > a.clave) && (TablaIndices[1].clave <a.clave))){
            aux=EspacioOcupado(0)+1;
            aux2=EspacioLibre(0);
            Pos_bloque=BlokeLibre();
        //si hay 3 lugares disponibles
            if (aux2==3){
            TablaDatos[aux].clave=a.clave;
            TablaDatos[aux].valor=a.valor;
            TablaDatos[aux].dir=nullptr;
            ordenar(0);
            TablaIndices[0].clave=a.clave;
            TablaIndices[0].dir=&TablaDatos[0];
           }
        //si hay 2 lugares disponibles, subocupado
           else if (aux2<3){
                //si no hay va al overflow
             if(aux2==0){
                   enviar_al_overflow();
                   TablaDatos[3].dir=&TablaDatos[20];
             } 
             //verifica e inserta insercion media
             else if(buscar_max(0)==true){
                  TablaDatos[aux+1].clave=a.clave;
                  TablaDatos[aux+1].valor=a.valor;
                    TablaDatos[aux+1].dir=nullptr;
                    ordenar(0);
                 TablaIndices[0].clave=a.clave;
                 TablaIndices[0].dir=&TablaDatos[0];
              }
             //si no es insersion media
                    else if(buscar_max(0)==false){
                   if( EspacioOcupado(0)>=2){
                    TablaDatos[Pos_bloque*4].clave=a.clave;
                    TablaDatos[Pos_bloque*4].valor=a.valor;
                    TablaDatos[Pos_bloque*4].dir=nullptr;
                    TablaIndices[Pos_bloque].clave=a.clave;
                    TablaIndices[Pos_bloque].dir=&TablaDatos[0];}
                    }
        }
    }
}
    
    
void inicializarTablaDatos() {
    for (int i = 0; i < 30; i++) {
        TablaDatos[i].clave = 0;
        TablaDatos[i].valor = "";  // Se deja en blanco
        TablaDatos[i].dir = nullptr;
    }
}

// Inicializa la tabla de índices
void inicializarTablaIndices() {
    for (int i = 0; i < 5; i++) {
        TablaIndices[i].clave = 0;
        TablaIndices[i].dir = nullptr;
    }
}
void Menu() {
    cout << "\n###### MENU ######" << endl;
    cout << "1. Ingresar clave" << endl;
    cout << "2. Consultar clave" << endl;
	cout<<"3. Mostrar menu"<<endl;
    cout << "4. Salir" << endl;
    cout << "Elige una opcion: "<<endl;
}

void Mostrar_Tabla_Indice(){
    cout<<"\n***********TABLA INDICE**********";
    cout<<"\nValor\n"<<endl;

    for(int i=0;i<5;i++){
        if(TablaIndices[i].clave!=0){
        cout<<TablaIndices[i].clave<<endl;
        }
    }
    cout<<"**********"<<endl<<endl;
}
void Mostrar_Tabla_Datos(){
    cout<<"\n***********TABLA Datos**********";
    cout<<"\nCLAVE"<<"                     VALOR"<<endl;
    
    for(int i=0;i<20;i++){
        if(TablaDatos[i].clave!=0){
        cout<<TablaDatos[i].clave<<"         "<<TablaDatos[i].valor<<endl;
        }
    }
    cout<<"\n**********\n"<<"*****OVERFLOW****"<<endl;
    cout<<"CLAVE"<<"                     VALOR";
    for(int b=20;b<30;b++){
        if(TablaDatos[b].clave!=0){
        cout<<TablaDatos[b].clave<<"       "<<TablaDatos[b].valor<<endl;
        }
    }
    cout<<"\n*****"<<endl<<endl;
}

int main(void){

    int _clave;
    string _valor;
    inicializarTablaDatos();
    inicializarTablaIndices();

   int opcion;
    Menu();
do{
    cin >> opcion;
    switch (opcion) {
        case 1: {
        cout << "Ingrese clave: ";
        cin >> _clave;
        cout << "Ingrese valor: ";
        cin.ignore();
        getline(cin, _valor);
        
        dato Datos_Usuario;
        Datos_Usuario.clave=_clave;
        Datos_Usuario.valor=_valor;
        Datos_Usuario.dir=nullptr;
        insertar(Datos_Usuario);
        Mostrar_Tabla_Indice();
        Mostrar_Tabla_Datos();
        break;}
        
        case 2:
            cout<<"hola;";break;
        case 3:Menu();break;
        case 4:
            cout << "Saliendo del programa" << endl;break;
        default:
            cout << "Opción inválida" << endl;
    }
} while (opcion != 4);
    return 0;
}