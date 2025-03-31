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


int main(void){
    dato TablaDatos[30];
    DatoIndice TablaIndices[5];
void insertar (dato a){
if(TablaIndices[0].clave==0){
TablaDatos[0].clave=a.clave;
TablaDatos[0].valor=a.valor;
TablaDatos[0].dir=nullptr;

TablaIndices[0].claver=a.clave;
TablaIndices[0].dir=&TablaDatos[0];
}else if (((TablaIndices[0].clave > a.clave) && (a.clave < TablaIndices[1].clave))||(TablaIndices[0].clave > a.clave) && (TablaIndices[1].clave == 0)){
    

    int pos(){
        return BlokeLibre() *4;
    }

    //Cantidad de elementos del bloque
int EsacioLibre(int a=pos())
    int contador_bloke=0;
    int i=a;
    for (i;i<4;i++){
        if(TablaDatos[i].clave==0)contador_bloke ++;
    }


//verificar blokes libres
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

    
    if(contador_bloke>2 && BlokeLibre==0){
        for(int i=0;i<4;i++){

            if(TablaDatos[i].clave==0){
            TablaDatos[i].clave=a.clave;
            TablaDatos[i].valor=a.valor;
            TablaDatos[i].dir=nullptr;
            break;
        } else if(i>4){
            for(int i=20;i<30;i++){

                if(TablaDatos[i].clave==0){
                TablaDatos[i].clave=a.clave;
                TablaDatos[i].valor=a.valor;
                TablaDatos[i].dir=nullptr;
                break;
            } 
        }

    }

 }}
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

void ordenar(int pos){
    sort(TablaDatos[pos],TablaDatos[pos]+4);
}

}}

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
}