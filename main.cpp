#include <iostream>
#include <fstream>
#include "BST.h"
using namespace std;

BST ContEntradas(ifstream &txt){
    BST Arb;
    string fecha, hora, ubi, pais = "";
    char puntoEntrada;
    int cont = 1;
    txt >> fecha >> hora >> puntoEntrada >> ubi;
    pais = ubi.substr(0,3);
    while (txt >> fecha >> hora >> puntoEntrada >> ubi){
        if(ubi.substr(0,3) == pais){
            cont++;
        } else{
            //dataCS(cont, pais).print();
            Arb.add(dataCS(cont, pais));
            cont=1;
            pais = ubi.substr(0,3);
        }
    }
    return Arb;
}

main(){
    BST ArbMRojo, ArbMMed;
    ifstream txtRojo, txtMed;

    txtRojo.open("Rojo.txt"); // FALLA AL IMPRIMIR EL LA RAIZ DEL ARBOL D9A 30
    ArbMRojo = ContEntradas(txtRojo);
    cout << "Entradas del Mar Rojo:" << endl << endl;
    ArbMRojo.print();
    cout << "-----------------------------------------------" << endl << endl;
    txtRojo.close();

    txtMed.open("Mediterraneo.txt");
    ArbMMed = ContEntradas(txtMed);
    cout << "Entradas del Mar Mediterraneo:" << endl << endl;
    ArbMMed.print();
    cout << "-----------------------------------------------" << endl << endl;
    txtMed.close();
}