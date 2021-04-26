#include <iostream>
#include <string>
#include <fstream>

# define docentes 10
using namespace std;

struct profesores{

    int id;
    char nombre[10];
};



int main() {

    ofstream archivo;
    archivo.open("archivo.txt");

    if(!archivo){
        cout<<"Error abriendo el Archivo"<<endl;
    }
    else {

        profesores *profesor = new profesores[docentes];

        for (int i = 0; i < docentes; i++) {
            cout << "Ingresa el id del docente " << i << " : ";
            cin >> profesor[i].id;
            archivo << profesor[i].id;


            cout << "Ingresa el nombre del docente " << i << " (10 carcteres) : ";
            cin >> profesor[i].nombre;
            archivo << profesor[i].nombre<<endl;
        }
    }

    FILE *txt =fopen("archivo.txt","r");
     int c;
    while((c=fgetc(txt))!=EOF){
        putchar(c);
    }
    
    archivo.close();
    
    return 0;
}

