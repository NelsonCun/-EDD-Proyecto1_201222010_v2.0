//
// Created by Nelson Cún on 15/12/24.
//

#ifndef NODEMAT_H
#define NODEMAT_H

#include <iostream>
#include "NodeAVL.h"

class NodeMat {
private:
    // Valor
    std::string usuario;
    std::string password;
    NodeAVL* raizAVL;

    // 6 apuntadores
    NodeMat *sig;
    NodeMat *prev;

    NodeMat *arriba;
    NodeMat *abajo;

    NodeMat *adelante;
    NodeMat *atras;

public:
    NodeMat(std::string usuario, std::string password);

    std::string getUsuario();
    void setUsuario(std::string usuario);

    std::string getPassword();
    void setPassword(std::string password);

    NodeAVL* getRaizAVL();
    void setRaizAVL(NodeAVL* raiz);

    NodeMat *getSig();
    void setSig(NodeMat *sig);
    NodeMat *getPrev();
    void setPrev(NodeMat *prev);
    NodeMat *getArriba();
    void setArriba(NodeMat *arriba);
    NodeMat *getAbajo();
    void setAbajo(NodeMat *abajo);
    NodeMat *getAdelante();
    void setAdelante(NodeMat *adelante);
    NodeMat *getAtras();
    void setAtras(NodeMat *atras);

};



#endif //NODEMAT_H
