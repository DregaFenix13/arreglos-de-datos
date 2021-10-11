//arreglo de de datos que muestra 
//que hay en cada pocicon del arreglo

#include <iostream>
#include<conio.h>
using namespace std;

//funcion para mostar pocicion

int main(){
	
	//se declara el arreglo asi como su tamaño, varible del contador,
	//variable dentro del arreglo
	int n[100],c,i,p;
	char r;
	cout<<"indique el tamamño del arreglo:\n";//se pide el tammaño deseado
	cin>>c;									  //se guarda en su variable
	
	//contador
	
	for(i=1;i<=c;i++){//se utiliza un for para que el usuario guarde los valores del arreglo
	cout<<"digite un numero del arreglo:\n";
	cin>>n[i];
	}
	//mostrar resultados en pantala
	
	for(c,i=c;c!=0,i!=0;c--,i--){
		
		cout<<c<<"->";cout<<n[i]<<"\n";
		
	}
	
	//para indicar la posicion se le preguntara al usuario
	//que pocicion desea mostrar y su contenido
	cout<<"¿desea mostrar el contenio de alguna pocision?\n";
	cin>>r;
	
		//opocion cuando el usuario quiere indicar 
		// la pocicion que decea ver
	
	if(r='si'){
		
		//que posicion quiere mostrar
		cout<<"que pocisiondesea mostrar?:\n";
		fflush(stdin);
		cin>>p;	
		i=p,c=p;
		cout<<"esta es la pocision derl arreglo que indico:\n";
		cout<<c<<"->";cout<<n[i]<<"\n";
					
	}
	
	// opcion cuando el usuario no quiere este procedimiento

getch();
return 0;
}
