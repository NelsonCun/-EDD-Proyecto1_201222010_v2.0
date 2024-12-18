//
// Created by Nelson Cún on 15/12/24.
//

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "NodeMat.h"
#include "MatrizDispersa.h"
#include "NodeAVL.h"

class Menu {
private:
    void crearUsuario(std::string nombre, std::string contraseña, std::string departamento, std::string empresa);
    void agregarActivo(std::string nombreActivo, std::string descripcion, std::string idActivo);
    std::string generarAleatorio();

public:
    void inicio();
    void menuPrincipal();
    void login();
    void limpiarPantalla();
    void menuAdmin();
    void menuUsuario();
    void crearUsuario();
    void reporteMatrizDispersa();
    void reporteDisponiblesxDep();
    void reporteDisponiblesxEmp();
    void reporteTransacciones();
    void reporteActivosxUsuario();
    void activosRentados();
    void ordenarTransacciones();
    void agregarActivo();
    void eliminarActivo();
    void modificarActivo();
    void rentarActivo();
    void activosRentados_Usuario();
    void misActivosRentados();
    bool existeUsuario(std::string nombre, std::string departamento, std::string empresa);
    void insertarAlFrente(std::string nombre, std::string password, std::string departamento, std::string empresa);
    void insertarAtras(std::string nombre, std::string password, std::string departamento, std::string empresa);
    NodeMat *buscarUsuario(std::string nombre, std::string departamento, std::string empresa);

    Menu(MatrizDispersa *matriz);
    MatrizDispersa *matriz;

};



#endif //MENU_H
