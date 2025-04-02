#include <iostream>


using namespace std;

struct dato{
    int clave;
    string valor;
    dato * dir;
}

struct DatoIndice{
    int clave;
    dato *dir;
}

void insertar(dato a){
    //inserta si la tabla de indices esta vacia
    if(TablaIndices[0].clave==0){
        TablaDatos[0].clave=a.clave;
        TablaDatos[0].valor=a.valor;
        TablaDatos[0].dir=nullptr;
        TablaIndices[0].claver=a.clave;
        TablaIndices[0].dir=&TablaDatos[0];}
    //si la tabla de indices no esta vacia,primer bloque
    else if(((TablaIndices[0].clave < a.clave))||
        ((TablaIndices[0].clave > a.clave) && (TablaIndices[1].clave <a.clave))){
        //si hay 3 lugares disponibles
            if (EspacioLibre(0)==3){
            TablaDatos[EspacioOcupado(0)+1].clave=a.clave;
            TablaDatos[EspacioOcupado(0)+1].valor=a.valor;
            TablaDatos[EspacioOcupado(0)+1].dir=nullptr;
            ordenar(0);
            TablaIndices[0].claver=a.clave;
            TablaIndices[0].dir=&TablaDatos[0];
           }
        //si hay 2 lugares disponibles, subocupado
           else if (EspacioLibre(0)<3){
            //si no hay va al overflow
            if(EspacioLibre(0)==0){
                enviar_al_overflow();
                TablaDatos[3].dir=&TablaDatos[20];
            } 
            //verifica e inserta insercion media
            else if(buscar_max(0)==true);{
                TablaDatos[EspacioOcupado(0)+1].clave=a.clave;
                TablaDatos[EspacioOcupado(0)+1].valor=a.valor;
                TablaDatos[EspacioOcupado(0)+1].dir=nullptr;
                ordenar(0);
                TablaIndices[0].claver=a.clave;
                TablaIndices[0].dir=&TablaDatos[0];
            }
            //si no es insersion media
            else if(buscar_max(0)==false){
               if( EspacioOcupado(0)>=2){
                TablaDatos[BlokeLibre()*4].clave=a.clave;
                TablaDatos[BlokeLibre()*4].valor=a.valor;
                TablaDatos[BlokeLibre()*4].dir=nullptr;
                TablaIndices[BlokeLibre()].claver=a.clave;
                TablaIndices[BlokeLibre()].dir=&TablaDatos[0];
               }
               }
            }
           }
        }
    
//ordena el bloque de la tabla de datos
    void ordenar(int pos){
        sort(TablaDatos[pos],TablaDatos[pos]+4);
        }            
//busca el maximo del bloque de la tabla de datos
bool buscar_max(int i){
    bool flag=false;
    for(i;i<4;i++){
        if(TablaDatos[i].clave>a.dato){
            flag=true;
            return flag;
        }
    }
    return flag;
}
//Devuelve espacios libres en la tabla de datos
    int EspacioLibre(int a){
        int contador_bloke=0;
        int i=a;
        for (i;i<4;i++){
            if(TablaDatos[i].clave==0)contador_bloke++;
        }
        return contador_bloke;}
//Devuelve espacios ocupados en la tabla de datos
    int EspacioOcupado(int a){
        int contador_bloke=0;
        int i=a;
        for (i;i<4;i++){
            if(TablaDatos[i].clave!=0)contador_bloke++;
        }
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


        int main(void){
    dato TablaDatos[30];
    DatoIndice TablaIndices[5];
}