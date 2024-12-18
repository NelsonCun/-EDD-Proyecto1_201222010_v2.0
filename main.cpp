#include <iostream>

#include "includes/MatrizDispersa.h"
#include "includes/Menu.h"

int main() {
    MatrizDispersa *matriz = new MatrizDispersa();
    Menu *inicio = new Menu(matriz);

    return 0;
}