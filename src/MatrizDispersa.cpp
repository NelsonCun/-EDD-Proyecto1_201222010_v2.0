//
// Created by Nelson Cún on 16/12/24.
//

#include "../includes/MatrizDispersa.h"

MatrizDispersa::MatrizDispersa() {
    this->cabeDep = nullptr;
    this->cabeEmp = nullptr;
}

void MatrizDispersa::insertarValor(std::string usuario, std::string password, std::string dep, std::string emp) {
    NodeMat *cabeDep = nullptr;
    NodeMat *cabeEmp = nullptr;
    NodeMat *usuarioNuevo = new NodeMat(usuario, password);

    if (estaVacia()) {

        cabeDep = insertarCabeceraDep(dep);
        cabeEmp = insertarCabeceraEmp(emp);

        insertarAlFinal(usuarioNuevo, cabeDep, cabeEmp);

        return;
    }

    cabeDep = cabeceraDepartamento(dep);
    cabeEmp = cabeceraEmpresa(emp);

    if (cabeDep == nullptr && cabeEmp == nullptr) {
        cabeDep = insertarCabeceraDep(dep);
        cabeEmp = insertarCabeceraEmp(emp);

        insertarAlFinal(usuarioNuevo, cabeDep, cabeEmp);
        return;
    }

    if (cabeDep == nullptr) {
        cabeDep = insertarCabeceraDep(dep);
        insertarAlFinal(usuarioNuevo, cabeDep, cabeEmp);
        return;
    }
    if (cabeEmp == nullptr) {
        cabeEmp = insertarCabeceraEmp(emp);
        insertarAlFinal(usuarioNuevo, cabeDep, cabeEmp);
        return;
    }

    NodeMat *auxDep = cabeDep->getAbajo();
    NodeMat *userCabEmp;
    bool abajo;

    while (auxDep != nullptr) {
        userCabEmp = enCabeceraEmp(auxDep);
        abajo = masAbajo(userCabEmp, emp);

        if (!abajo) break;

        auxDep = auxDep->getAbajo();
    }

    if (abajo) {
        insertarAlFinalDep(usuarioNuevo, cabeDep);
    } else {
        insertarAlMedioDep(usuarioNuevo, auxDep);
    }

    NodeMat *auxEmp = cabeEmp->getSig();
    NodeMat *userCabDep;
    bool siguiente;

    while (auxEmp != nullptr) {
        userCabDep = enCabeceraDep(auxEmp);
        siguiente = masDerecha(userCabDep, dep);

        if (!siguiente) break;

        auxEmp = auxEmp->getSig();
    }

    if (siguiente) {
        insertarAlFinalEmp(usuarioNuevo, cabeEmp);
    } else {
        insertarAlMedioEmp(usuarioNuevo, auxEmp);
    }
}

void MatrizDispersa::insertarAlFinal(NodeMat *usuario, NodeMat *cabeDep, NodeMat *cabeEmp) {
    insertarAlFinalDep(usuario, cabeDep);
    insertarAlFinalEmp(usuario, cabeEmp);
}


NodeMat *MatrizDispersa::insertarCabeceraDep(std::string dep) {
    NodeMat *nuevaCabecera = new NodeMat(dep, "0");

    if (this->cabeDep == nullptr) {
        this->cabeDep = nuevaCabecera;

        return nuevaCabecera;
    }

    NodeMat *aux = cabeDep;

    while (aux->getSig() != nullptr) {
        aux = aux->getSig();
    }

    aux->setSig(nuevaCabecera);
    nuevaCabecera->setPrev(aux);

    return nuevaCabecera;
}

void MatrizDispersa::insertarAlFinalDep(NodeMat *usuario, NodeMat *cabeDep) {
    NodeMat *aux = cabeDep;

    while (aux->getAbajo() != nullptr) {
        aux = aux->getAbajo();
    }

    aux->setAbajo(usuario);
    usuario->setArriba(aux);
}

void MatrizDispersa::insertarAlFinalEmp(NodeMat *usuario, NodeMat *cabeEmp) {
    NodeMat *aux = cabeEmp;

    while (aux->getSig() != nullptr) {
        aux = aux->getSig();
    }

    aux->setSig(usuario);
    usuario->setPrev(aux);
}

void MatrizDispersa::insertarAlMedioDep(NodeMat *usuario, NodeMat *departamento) {
    departamento->getArriba()->setAbajo(usuario);
    usuario->setAbajo(departamento);
    usuario->setArriba(departamento->getArriba());
    departamento->setArriba(usuario);
}

void MatrizDispersa::insertarAlMedioEmp(NodeMat *usuario, NodeMat *empresa) {

    empresa->getPrev()->setSig(usuario);
    usuario->setSig(empresa);
    usuario->setPrev(empresa->getPrev());
    empresa->setPrev(usuario);
}



NodeMat *MatrizDispersa::insertarCabeceraEmp(std::string emp) {

    NodeMat *nuevaCabecera = new NodeMat(emp, "0");

    if (this->cabeEmp == nullptr) {
        this->cabeEmp = nuevaCabecera;

        return nuevaCabecera;
    }

    NodeMat *aux = cabeEmp;

    while (aux->getAbajo() != nullptr) {
        aux = aux->getAbajo();
    }

    aux->setAbajo(nuevaCabecera);
    nuevaCabecera->setArriba(aux);

    return nuevaCabecera;

}

NodeMat *MatrizDispersa::cabeceraDepartamento(std::string dep) {

    if (estaVacia()) {
        return nullptr;
    }

    NodeMat *aux = cabeDep;

    while (aux != nullptr) {
        if (aux->getUsuario() == dep) return aux;
        aux = aux->getSig();
    }

    return nullptr;

}

NodeMat *MatrizDispersa::cabeceraEmpresa(std::string emp) {

    if (estaVacia()) {
        return nullptr;
    }

    NodeMat *aux = cabeEmp;

    while (aux != nullptr) {
        if (aux->getUsuario() == emp) return aux;

        aux = aux->getAbajo();
    }
    return nullptr;
}

NodeMat *MatrizDispersa::enCabeceraDep(NodeMat *node) {
    NodeMat *aux = node;
    while (aux->getArriba() != nullptr) {
        aux = aux->getArriba();
    }
    return aux;
}

NodeMat *MatrizDispersa::enCabeceraEmp(NodeMat *node) {
    NodeMat *aux = node;
    while (aux->getPrev() != nullptr) {
        aux = aux->getPrev();
    }
    return aux;
}

bool MatrizDispersa::masDerecha(NodeMat *cabeDep, std::string dep) {

    NodeMat *aux = cabeDep;
    while (aux != nullptr) {
        if (aux->getUsuario() == dep ) {
            return true;
        }
        aux = aux->getSig();
    }

    return false;

}

bool MatrizDispersa::masAbajo(NodeMat *cabeEmp, std::string emp) {

    NodeMat *aux = cabeEmp;
    while (aux != nullptr) {
        if (aux->getUsuario() == emp ) {
            return true;
        }
        aux = aux->getAbajo();
    }
    return false;
}



bool MatrizDispersa::estaVacia() {
    return this->cabeDep == nullptr;
}