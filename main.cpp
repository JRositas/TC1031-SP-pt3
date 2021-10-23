#include <iostream>
#include <fstream>
#include "BST.h"
using namespace std;

// Complejidad: O(n)
void ContEntradas(ifstream &txt){
    BST arb;
    string fecha, hora, ubi, pais = "";
    dataCS *aux;
    char puntoEntrada;
    int cont = 1;
    txt >> fecha >> hora >> puntoEntrada >> ubi;
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
    if(pais != ""){
        arb.add(*aux);
    }
    arb.print();
    cout << "-----------------------------------------------" << endl << endl;
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
