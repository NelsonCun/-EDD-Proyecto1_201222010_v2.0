//
// Created by Nelson Cún on 15/12/24.
//

#include "../includes/NodeMat.h"

using namespace std;

NodeMat::NodeMat(string usuario, string password) {
    this->usuario = usuario;
    this->password = password;
    this->raizAVL = nullptr;
    this->sig = nullptr;
    this->prev = nullptr;
    this->arriba = nullptr;
    this->abajo = nullptr;
    this->adelante = nullptr;
    this->atras = nullptr;
}

string NodeMat::getUsuario() {
    return this->usuario;
};

void NodeMat::setUsuario(string usuario) {
    this->usuario = usuario;
};

string NodeMat::getPassword() {
    return this->password;
};

void NodeMat::setPassword(std::string password) {
    this->password = password;
};

NodeAVL* NodeMat::getRaizAVL() {
    return this->raizAVL;
};

void NodeMat::setRaizAVL(NodeAVL* raiz) {
    this->raizAVL = raiz;
};

NodeMat* NodeMat::getSig() {
    return this->sig;
};

void NodeMat::setSig(NodeMat *sig) {
    this->sig = sig;
};

NodeMat* NodeMat::getPrev() {
    return this->prev;
};

void NodeMat::setPrev(NodeMat *prev) {
    this->prev = prev;
};

NodeMat* NodeMat::getArriba() {
    return this->arriba;
};

void NodeMat::setArriba(NodeMat *arriba) {
    this->arriba = arriba;
};

NodeMat* NodeMat::getAbajo() {
    return this->abajo;
};

void NodeMat::setAbajo(NodeMat *abajo) {
    this->abajo = abajo;
};

NodeMat* NodeMat::getAdelante() {
    return this->adelante;
};

void NodeMat::setAdelante(NodeMat *adelante) {
    this->adelante = adelante;
};

NodeMat* NodeMat::getAtras() {
    return this->atras;
};

void NodeMat::setAtras(NodeMat *atras) {
    this->atras = atras;
};