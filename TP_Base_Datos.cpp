#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstdlib>



using namespace std;
class Tabla_Datos;
struct Datos{
	int clave;
	Tabla_Datos* dir;
	string valor;
};

class Tabla_Datos{	

private:
	int clave;
	string valor;
	Tabla_Datos *dir;
	
public:
	Tabla_Datos(){
		this->clave=0;
		this->valor="";
		this->dir=nullptr;
	}
	 Tabla_Datos ( Datos _datos){
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
	Tabla_Datos* get_dir(){
		return dir;
	}
	void set_TD_clave(int _datos){
		this->clave=_datos;
	}

};

class Tabla_Indice{
private:
	int TI_clave;
	Tabla_Datos *TI_dir;

public:
	Tabla_Indice(){
	this->TI_clave=0;
	this->TI_dir=nullptr;
	}
	Tabla_Indice(Datos _datos){
		this->TI_clave=_datos.clave;
		this->TI_dir=_datos.dir;
	}
	int get_TI_clave(){
		return TI_clave;
	}
	Tabla_Datos* get_TI_dir(){
		return TI_dir;
	}
	void set_TI_dir(Tabla_Datos _datos){
		this->TI_dir=&_datos;
	}
	void set_TI_clave(int _datos){
		this->TI_clave=_datos;
	}
	
};

class Gestor{
private:
	vector<Tabla_Datos> TD;
	vector<Tabla_Indice> TI;
	int contador;
	size_t TD_maxTamanio;
	size_t TI_maxTamanio;
public:

void set_dir(){
	this->TI[0].set_TI_dir(TD[0]);
	this->TI[1].set_TI_dir(TD[4]);
	this->TI[2].set_TI_dir(TD[8]);
	this->TI[3].set_TI_dir(TD[12]);
	this->TI[4].set_TI_dir(TD[16]);
}
void set_clave(){
	this->TI[0].set_TI_clave(TD[0].get_clave());
	this->TI[1].set_TI_clave(TD[4].get_clave());
	this->TI[2].set_TI_clave(TD[8].get_clave());
	this->TI[3].set_TI_clave(TD[12].get_clave());
	this->TI[4].set_TI_clave(TD[16].get_clave());
}

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
	contador=0;
	TD_maxTamanio=30;
	TI_maxTamanio=5;
		for(auto tablita : TD)
		{
		tablita.set_TD_clave(0);
		}
}
void Verificar_Tabla_Indice(Tabla_Datos _dato){

	for(int i=0;i<5;i++){

		if(TI[i].get_TI_clave()==0){
			TI[i].set_TI_clave(_dato.get_clave());
			TI[i].set_TI_dir(*_dato.get_dir());
		}
		if(_dato.get_clave()>TI[i].get_TI_clave() && _dato.get_clave()<TI[i+1].get_TI_clave()){
			
		}
	}
}

void Ordenar_Bloque(){
	
	sort(TD.begin(),TD.begin()+4,[] (Tabla_Datos &a , 
		Tabla_Datos &b ){return a.get_clave() < b.get_clave();});
	
	sort(TD.begin()+4,TD.begin()+8,[] (Tabla_Datos &a ,
		Tabla_Datos &b ){return a.get_clave() < b.get_clave();});
		
	sort(TD.begin()+8,TD.begin()+12,[] (Tabla_Datos &a , 
		Tabla_Datos &b ){return a.get_clave() < b.get_clave();});
		
	sort(TD.begin()+12,TD.begin()+16,[] (Tabla_Datos &a , 
		Tabla_Datos &b ){return a.get_clave() < b.get_clave();});
	
	sort(TD.begin()+16,TD.begin()+20,[] (Tabla_Datos &a , 
		Tabla_Datos &b ){return a.get_clave() < b.get_clave();});
}



void Mostrar(){
	for(auto tablita : TD)
	{
		cout<<"\n"<<tablita.get_clave()<<endl;
	}
}
void Insertar(int _clave, string _valor){
	if (contador >=30){
		cout<<"No hay mas lugar en el vector"<<endl;
		return;
	}
	Datos aux;
	aux.clave=_clave;
	aux.valor=_valor;
	aux.dir=NULL;

	//cout<<"\nEL tamanio del vector de datos actualmente es de :"<<TD.size()<<endl;
	//cout<<"EL tamanio del vector de indices actualmente es de :"<<TI.size()<<endl<<endl;
	
	TD.push_back(Tabla_Datos(aux));
	
	
	
	


	if ((contador >= 20)){
		cout<<endl<<"Se guardo en el overflow"<<endl;
	}
	contador++;
	}
};
/*if((contador %4 ==0) && (contador<20)){
		aux.dir=&TD[contador];
		if(aux.dir==nullptr){
			cout<<"ERROR -> NO EXISTE";
			return;
		}
		TI.push_back(Tabla_Indice(aux));
		cout<<"Se agrego la clave "<<_clave<<" en la posicion "<<TI.size()-1<<endl;
	}*/
void prueba_consulta(Gestor &pepe) {
	
	int n;
	cout << "Clave a buscar: ";
	cin >> n;
	
	cout << pepe.Consultar(n) << endl;
}



void Menu() {
    cout << "\n###### MENU ######" << endl;
    cout << "1. Ingresar clave" << endl;
    cout << "2. Consultar clave" << endl;
	cout<<"3. Mostrar menu"<<endl;
    cout << "4. Salir" << endl;
    cout << "Elige una opcion: "<<endl;
}

int main() {
    Gestor BD;
    BD.Start();
	
    //BD.set_clave();
	//BD.set_dir();
	BD.Insertar(5,"pepe");
	BD.Insertar(10,"pepe1");
	BD.Insertar(12,"pep2FIN B1");
	BD.Insertar(11,"pepe3 ");
	BD.Insertar(7,"pepe4");
	BD.Insertar(80,"pep5FIN B2");
	BD.Insertar(70,"pep6");
	BD.Insertar(60,"pep7 ");
	BD.Insertar(77,"pep8Fin B3");
	BD.Insertar(14,"pep9");
	BD.Insertar(17,"pep10");
	BD.Insertar(19,"pepe11 ");
	BD.Insertar(24,"pepe12");

	cout<<"ANTES de ORDENAR";

	BD.Ordenar_Bloque();

	BD.Mostrar();

    int opcion;
        Menu();
	do{
        cin >> opcion;
        switch (opcion) {
            case 1: {
                int clave;
                string valor;
                cout << "Ingrese clave: ";
                cin >> clave;
                cout << "Ingrese valor: ";
                cin.ignore();  // Evita problemas con getline
                getline(cin, valor);
                BD.Insertar(clave, valor);
				cout<<"\nOpcion: "<<endl;break;
            }
            case 2:
                prueba_consulta(BD);
				cout<<"\nOpcion: "<<endl;break;
			case 3:Menu();break;
            case 4:
                cout << "Saliendo del programa" << endl;break;
            default:
                cout << "Opción inválida" << endl;
        }
    } while (opcion != 4);

    return 0;
}