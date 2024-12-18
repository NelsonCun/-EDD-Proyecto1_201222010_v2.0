//
// Created by Nelson Cún on 16/12/24.
//

#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include "NodeMat.h"


class MatrizDispersa {
private:

public:
    // Cabecera horizontal
    NodeMat *cabeDep;

    // Cabecera vertical
    NodeMat *cabeEmp;

    MatrizDispersa();

    // Métodos de la matriz
    bool estaVacia();

    NodeMat *cabeceraDepartamento(std::string dep);
    NodeMat *cabeceraEmpresa(std::string emp);

    NodeMat *insertarCabeceraDep(std::string dep);
    NodeMat *insertarCabeceraEmp(std::string emp);

    void insertarValor(std::string usuario, std::string password, std::string Dep, std::string Emp);
    void insertarAlFinal(NodeMat *usuario, NodeMat *cabeDep, NodeMat *cabeEmp);
    void insertarAlFinalDep(NodeMat *usuario, NodeMat *cabeDep);
    void insertarAlFinalEmp(NodeMat *usuario, NodeMat *cabeEmp);
    void insertarAlMedioDep(NodeMat *usuario, NodeMat *departamento);
    void insertarAlMedioEmp(NodeMat *usuario, NodeMat *empresa);

    NodeMat *enCabeceraDep(NodeMat *node);
    NodeMat *enCabeceraEmp(NodeMat *node);

    bool masAbajo(NodeMat *cabeEmp, std::string dep);
    bool masDerecha(NodeMat *cabeDep, std::string emp);
};


#endif //MATRIZDISPERSA_H
