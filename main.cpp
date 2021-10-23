#include <iostream>
#include <fstream>
#include "BST.h"
using namespace std;

BST ContEntradas(ifstream &txt){
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
    return arb;
}

int main(){
    string archivoRojo, archivoMediterraneo;
    BST arbMRojo, arbMMed, arb;
    ifstream txtRojo, txtMed;

    cout << "Ingresa el nombre del archivo del Mar Rojo: ";
    cin >> archivoRojo;
    
    txtRojo.open(archivoRojo);
    arbMRojo = ContEntradas(txtRojo);
    cout << "Entradas del Mar Rojo:" << endl << endl;
    arbMRojo.print();
    cout << "-----------------------------------------------" << endl << endl;
    txtRojo.close();

    cout << "Ingresa el nombre del archivo del Mar Mediterraneo: ";
    cin >> archivoMediterraneo;

    txtMed.open(archivoMediterraneo);
    arbMMed = ContEntradas(txtMed);
    cout << "Entradas del Mar Mediterraneo:" << endl << endl;
    arbMMed.print();
    cout << "-----------------------------------------------" << endl << endl;
    txtMed.close();
}