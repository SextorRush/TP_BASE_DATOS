#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>


using namespace std;
struct Datos{
	int clave;
	int *dir;
	string valor;
};

class Tabla_Datos{	

private:
	int clave;
	string valor;
	int *dir;
	
public:
	Tabla_Datos(Datos _datos){
		this->clave=_datos.clave;
		this->valor=_datos.valor;
		this->dir=_datos.dir;
	}
	int get_clave(){
		return clave;
	}
	string get_valor(){
		return valor;
	}
	int* get_dir(){
		return dir;
	}
    /*Usa int* get_dir() si quieres devolver la dirección de memoria.

    Usa int get_dir() si quieres devolver el valor 
    almacenado en la dirección, asegurándote de que el puntero no sea nullptr.
    
    int get_dir() {
    return (dir != nullptr) ? *dir : 0;  // Devuelve 0 si el puntero es nulo
}
    */
		
	/*void set_TD(Datos a, string _valor){
		this->clave=a.clave;
		this->valor=valor;
		this->dir=a.dir;
	}*/
};
class Tabla_Indice{
public:
	Tabla_Indice(Datos _datos){
		this->TI_clave=_datos.clave;
		this->TI_dir=_datos.dir;
	}
	int get_TI_clave(){
		return TI_clave;
	}
	int get_TI_dir(){
		return &TI_dir;
	}
	/*void set_TI(Datos b){
		this->TI_clave=b.clave;
		this->TI_dir=b.dir;
	}*/
private:
	int TI_clave;
	int *TI_dir;
	
};

class Gestor{
private:
	vector<Tabla_Datos> TD;
	vector<Tabla_Indice> TI;
	int contador=0;
public:

string Consultar(int Clave_Usuario){
		auto I=find_if(TD.begin(), TD.end(),
					   [Clave_Usuario](Tabla_Datos &td) {
						   return td.get_clave() == Clave_Usuario;
					   });
		if (I!= TD.end()){
			return I->get_valor();}
			
		else{
			return "Clave no encontrada";
			}
 hola
	}
void Start(){
		
		TD.resize(30);
		TI.resize(3);
		
		/*srand(static_cast<unsigned int>(time(0)));
		
		for (int i = 0; i < 6; i++) {
			Datos aux;
			aux.clave = rand() % 7 + 9;
			aux.valor = "Valor :" + to_string(aux.clave+50);  
			aux.dir = i;  
			
			TD[i].set_TD(aux);
		}*/
}
void Insertar(int _clave, string _valor){
	Datos aux;
	aux.clave=_clave;
	aux.valor=_valor;
	aux.dir=NULL;
	TD.push_back(Tabla_Datos(aux));
	contador++;
	
	
	if((contador %4 ==0) && (contador<20)){
		TI.push_back( Tabla_Indice(aux));
		
	}
	
}
};



void prueba_consulta(Gestor &pepe) {
	
	int n;
	cout << "Clave a buscar: ";
	cin >> n;
	
	cout << pepe.Consultar(n) << endl;
}

int main(){
	Gestor BD;
	
	BD.Start();
	prueba_consulta(BD);

	
	
	return 0;
}


