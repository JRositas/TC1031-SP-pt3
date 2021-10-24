
/*
El presente programa tiene como propósito solicitar los archivos que se habían generado con anterioridad,
con respecto a los mares Rojo y Mediterraneo, y de tal manera se contabilice las entradas que han tenido cada buque 
(los primeros 3 caracteres de la serie UBI), por lo que se va a almacenar como data unico UBI + Cantidad de Entradas en 2 arboles binarios,
efectivamente un arbol por mar. Por último se despliega en pantalla la información de cada arbol (de cada mar) de forma descendiente.
*/

// Integrantes (Equipo 12) :
// Daniel Evaristo Escalera Bonilla - A00831289
// José Arnoldo Rositas Salinas - A00829760
// Ángela Felicia Guajardo Olveda - A00829821

// SP TC1031
// 23 Oct 2021


#include <iostream>
#include <fstream>
#include "BST.h"
using namespace std;

// Función que nos permite contabilizar las Entradas
// Complejidad: O(n)
void ContEntradas(ifstream &txt){
    BST arb;
    string fecha, hora, ubi, pais = "";
    dataCS *aux;
    char puntoEntrada;
    int cont = 1;
    txt >> fecha >> hora >> puntoEntrada >> ubi;
    if(ubi != ""){
        pais = ubi.substr(0,3);
        while (txt >> fecha >> hora >> puntoEntrada >> ubi){
            if(ubi.substr(0,3) == pais){
                cont++;
            } else{
                aux = new dataCS(cont, pais);
                arb.add(*aux);
                cont = 1;
                pais = ubi.substr(0,3);
            }
        }
        aux = new dataCS(cont, pais);
        arb.add(*aux);
        arb.print();
        cout << "-----------------------------------------------" << endl << endl;
    }
}

int main(){
    string archivoRojo, archivoMediterraneo;
    ifstream txtRojo, txtMed;

    cout << "Ingresa el nombre del archivo del Mar Rojo: ";
    cin >> archivoRojo;
    txtRojo.open(archivoRojo);
    cout << "Entradas del Mar Rojo:" << endl << endl;
    ContEntradas(txtRojo);
    txtRojo.close();

    cout << "Ingresa el nombre del archivo del Mar Mediterraneo: ";
    cin >> archivoMediterraneo;
    txtMed.open(archivoMediterraneo);
    cout << "Entradas del Mar Mediterraneo:" << endl << endl;
    ContEntradas(txtMed);
    txtMed.close();
    
    return 0;
}
