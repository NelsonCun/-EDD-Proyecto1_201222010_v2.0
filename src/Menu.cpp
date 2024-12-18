//
// Created by Nelson Cún on 15/12/24.
//

#include "../includes/Menu.h"
#include <iostream>
#include <random>
#include <fstream>

using namespace std;

Menu::Menu(MatrizDispersa *matriz){
  this->matriz = matriz;
  matriz->insertarValor("elian_estrada", "1234", "guatemala", "igss");
  matriz->insertarValor("juanito", "4567", "jutiapa", "max");
  matriz->insertarValor("pedrito", "48956", "jalapa", "usac");
  matriz->insertarValor("mafer", "54312", "peten", "cinepolis");
  matriz->insertarValor("juanma", "32897", "guatemala", "usac");
  matriz->insertarValor("casimiro", "721896", "guatemala", "max");
  matriz->insertarValor("fuego03", "891346", "jutiapa", "cinepolis");
  matriz->insertarValor("azurdia", "780145", "jutiapa", "usac");
  //matriz->insertarValor("incrediboy", "201598", "jutiapa", "max");
  //matriz->insertarValor("alcachofan", "20435", "jalapa", "usac");
  menuPrincipal();
  }

void Menu::menuPrincipal(){
  int opcion = 0;
  while (opcion != 1 && opcion != 2){
    cout<< endl;
    cout<< "************************** MENÚ INICIAL ******************************" << endl;
    cout<< "1. Iniciar sesion" << endl;
    cout<< "2. Salir " << endl;
    cout<< "****************************************************************" << endl;
    cout << "Opción elegida: ";
    cin >> opcion;

    if (cin.fail()) {
      cin.clear();
      cin.ignore();
      limpiarPantalla();
      cout << "ERROR: Debes ingresar un número." << endl;
      opcion = 0;
    } else if (opcion != 1 && opcion != 2) {
      limpiarPantalla();
      cout << "ERROR: Opción inválida. Intenta nuevamente." << endl;
    }

  }

  if(opcion == 1) {
    limpiarPantalla();
    login();
    opcion = 0;
    return;
  }
  if (opcion == 2) {
    limpiarPantalla();
    cout << "Gracias por utilizar nuestro sistema." << endl;
    return;
  }
}

void Menu::login(){
    string usuario;
    string password;
    string usuarioAdmin = "Admin";
    string usuarioPassword = "Admin";

    cout << "******************************** LOGIN ***********************************+" << endl;
    cout << "Ingresar Usuario: ";
    cin >> usuario;
    cout << "Ingresar Contraseña: ";
    cin >> password;

    if (usuario == usuarioAdmin){
      if (password==usuarioPassword) {
        limpiarPantalla();
        menuAdmin();
        return;
      } else {
        limpiarPantalla();
        cout << "Usuario o contraseña incorrectas" << endl;
        login();
        return;
      }
    }

    string departamento;
    string empresa;

    cout << "Ingresar Departamento: ";
    cin >> departamento;
    cout << "Ingresar Empresa: ";
    cin >> empresa;


  NodeMat *nodo = buscarUsuario(usuario, departamento, empresa);

  if (nodo == nullptr) {
    limpiarPantalla();
    cout << "Usuario no encontrado." << endl;
    login();
    return;
  }

  if (nodo->getUsuario() == usuario && nodo->getPassword() == password) {
    limpiarPantalla();
    menuUsuario();
    return;
  }

    limpiarPantalla();
    cout << "Contraseña invalida." << endl;
    login();
    return;
}

void Menu::menuAdmin(){
  int opcion = 0;
  while (opcion < 1 || opcion > 9){
    cout<< endl;
    cout << "********************************* MENÚ ADMINISTRADOR *************************" << endl;
    cout << " 1. Registrar usuario" << endl;
    cout << " 2. Reporte matriz dispersa" << endl;
    cout << " 3. Reporte Activos Disponibles de un Departamento" << endl;
    cout << " 4. Reporte Activos Disponibles de una Empresa" << endl;
    cout << " 5. Reporte Transacciones" << endl;
    cout << " 6. Reporte Reporte Activos de un Usuario" << endl;
    cout << " 7. Activos rentados por un Usuario" << endl;
    cout << " 8. Ordenar Transacciones" << endl;
    cout << " 9. Salir" << endl;
    cout<< "*******************************************************************************" << endl;
    cout << "Opción elegida: ";
    cin >> opcion;

    if (cin.fail()) {
      cin.clear();
      cin.ignore();
      limpiarPantalla();
      cout << "ERROR: Debes ingresar un número." << endl;
      opcion = 0;
    } else if (opcion < 1 || opcion > 9) {
      limpiarPantalla();
      cout << "ERROR: Opción inválida. Intenta nuevamente." << endl;
    }
  }

  limpiarPantalla();

  switch (opcion) {
    case 1:
      crearUsuario();
      return;
    case 2:
      reporteMatrizDispersa();
      return;
    case 3:
      reporteDisponiblesxDep();
      return;
    case 4:
      reporteDisponiblesxEmp();
      return;
    case 5:
      reporteTransacciones();
      return;
    case 6:
      reporteActivosxUsuario();
      return;
    case 7:
      activosRentados();
      return;
    case 8:
      ordenarTransacciones();
      return;
    case 9:
      menuPrincipal();
      return;
  }
  menuAdmin();
}

void Menu::menuUsuario() {
  int opcion = 0;
  while (opcion < 1 || opcion > 7){
    cout<< endl;
    cout << "********************************* MENÚ USUARIO *************************" << endl;
    cout << " 1. Agregar Activo" << endl;
    cout << " 2. Eliminar Activo" << endl;
    cout << " 3. Modificar Activo" << endl;
    cout << " 4. Rentar Activo" << endl;
    cout << " 5. Activos rentados" << endl;
    cout << " 6. Mis activos rentados" << endl;
    cout << " 7. Cerrar sesión" << endl;
    cout<< "*******************************************************************************" << endl;
    cout << "Opción elegida: ";
    cin >> opcion;

    if (cin.fail()) {
      cin.clear();
      cin.ignore();
      limpiarPantalla();
      cout << "ERROR: Debes ingresar un número." << endl;
      opcion = 0;
    } else if (opcion < 1 || opcion > 7) {
      limpiarPantalla();
      cout << "ERROR: Opción inválida. Intenta nuevamente." << endl;
    }
  }

  limpiarPantalla();

  switch (opcion) {
    case 1:
      agregarActivo();
      return;
    case 2:
      eliminarActivo();
    case 3:
      modificarActivo();
    case 4:
      rentarActivo();
    case 5:
      activosRentados_Usuario();
      return;
    case 6:
      misActivosRentados();
      return;
    case 7:
      menuPrincipal();
      return;
  }

  return;
}

void Menu::crearUsuario() {
  string nombre;
  string password;
  string departamento;
  string empresa;
  cout << "********************************* CREAR USUARIO *************************" << endl;
  cout << "Ingresar nombre del nuevo usuario: ";
  cin >> nombre;
  cout << "Ingresar contraseña: ";
  cin >> password;
  cout << "Ingresar departamento: ";
  cin >> departamento;
  cout << "Ingresar empresa: ";
  cin >> empresa;

  bool existe = existeUsuario(nombre, departamento, empresa);

  if (existe) {
    limpiarPantalla();
    cout << "El usuario ya existe" << endl;
    menuAdmin();
    return;
  }

  NodeMat *cabeDep = matriz->cabeceraDepartamento(departamento);
  bool estaOcupado;

  while (cabeDep != nullptr) {
    if (matriz->enCabeceraEmp(cabeDep)->getUsuario() == empresa) {
      estaOcupado = true;
    }
    cabeDep = cabeDep->getAbajo();
  }

  if (estaOcupado) {
    int opcion = 0;
    while (opcion != 1 && opcion != 2){
      cout<< endl;
      cout<< "Ya hay un usuarios en esta empresa y departamento\n"
             "¿En dónde desea guardar el nuevo usuario?" << endl;
      cout<< "1. En frente" << endl;
      cout<< "2. Atrás " << endl;
      cout<< "****************************************************************" << endl;
      cout << "Opción elegida: ";
      cin >> opcion;

      if (cin.fail()) {
        cin.clear();
        cin.ignore();
        limpiarPantalla();
        cout << "ERROR: Debe ingresar un número." << endl;
        opcion = 0;
      } else if (opcion != 1 && opcion != 2) {
        limpiarPantalla();
        cout << "ERROR: Opción inválida. Intente nuevamente." << endl;
      }

    }

    switch (opcion) {
      case 1:
        insertarAlFrente(nombre, password, departamento, empresa);
        return;
      case 2:
        insertarAtras(nombre, password, departamento, empresa);
        return;
    }
  }

  crearUsuario(nombre, password, departamento, empresa);
  return;
}

void Menu::insertarAlFrente(std::string nombre, std::string password, std::string departamento, std::string empresa) {
  NodeMat *usuarioNuevo = new NodeMat(nombre, password);
  NodeMat *cabeDep = matriz->cabeceraDepartamento(departamento)->getAbajo();
  while (cabeDep != nullptr) {
    if (matriz->enCabeceraEmp(cabeDep)->getUsuario() == empresa) {
      usuarioNuevo->setAtras(cabeDep);
      cabeDep->setAdelante(usuarioNuevo);

      if (cabeDep->getArriba() != nullptr) {
        cabeDep->getArriba()->setAbajo(usuarioNuevo);
        usuarioNuevo->setArriba(cabeDep->getArriba());
      }

      if (cabeDep->getAbajo() != nullptr) {
        cabeDep->getAbajo()->setArriba(usuarioNuevo);
        usuarioNuevo->setAbajo(cabeDep->getAbajo());
      }

      if (cabeDep->getPrev() != nullptr) {
        cabeDep->getPrev()->setSig(usuarioNuevo);
        usuarioNuevo->setPrev(cabeDep->getPrev());
      }

      if (cabeDep->getSig() != nullptr) {
        cabeDep->getSig()->setPrev(usuarioNuevo);
        usuarioNuevo->setSig(cabeDep->getSig());
      }

      // Limpieza de conexiones innecesarias:
      cabeDep->setArriba(nullptr);
      cabeDep->setAbajo(nullptr);
      cabeDep->setPrev(nullptr);
      cabeDep->setSig(nullptr);
      menuAdmin();
      return;
    }
    cabeDep = cabeDep->getAbajo();
  }
};

void Menu::insertarAtras(std::string nombre, std::string password, std::string departamento, std::string empresa) {
  NodeMat *usuarioNuevo = new NodeMat(nombre, password);
  NodeMat *cabeDep = matriz->cabeceraDepartamento(departamento)->getAbajo();
  while (cabeDep != nullptr) {
    if (matriz->enCabeceraEmp(cabeDep)->getUsuario() == empresa) {
      usuarioNuevo->setAtras(cabeDep->getAtras());
      usuarioNuevo->setAdelante(cabeDep);
      if (cabeDep->getAtras() != nullptr) {
        cabeDep->getAtras()->setAdelante(usuarioNuevo);
      }
      cabeDep->setAtras(usuarioNuevo);
      menuAdmin();
      return;
    }
    cabeDep = cabeDep->getAbajo();
  }
};

void Menu::crearUsuario(std::string nombre, std::string password, std::string departamento, std::string empresa) {
  matriz->insertarValor(nombre, password, departamento, empresa);
  cout << "Usuario " + nombre + " creado exitosamente" << endl;
  menuAdmin();
  return;
}

bool Menu::existeUsuario(std::string nombre, std::string departamento, std::string empresa) {
  if (matriz->estaVacia()) return false;

  NodeMat *cabeDep = matriz->cabeceraDepartamento(departamento);
  NodeMat *cabeEmp = matriz->cabeceraEmpresa(empresa);

  if (cabeDep == nullptr || cabeEmp == nullptr) return false;

  NodeMat *auxNode = cabeDep;

  while (auxNode != nullptr) {
    if (auxNode->getUsuario() == nombre){
      if (matriz->enCabeceraEmp(auxNode)->getUsuario()==empresa) return true;
    }
    auxNode = auxNode->getAbajo();
  }

  return false;
};

NodeMat *Menu::buscarUsuario(std::string nombre, std::string departamento, std::string empresa) {
  if (matriz->estaVacia()) return nullptr;

  NodeMat *cabeDep = matriz->cabeceraDepartamento(departamento);
  NodeMat *cabeEmp = matriz->cabeceraEmpresa(empresa);

  if (cabeDep == nullptr || cabeEmp == nullptr) return nullptr;

  NodeMat *auxNode = cabeDep;

  while (auxNode != nullptr) {
    if (auxNode->getUsuario() == nombre) {
      if (matriz->enCabeceraEmp(auxNode)->getUsuario()==empresa) return auxNode;
    }
    auxNode = auxNode->getAbajo();
  }

  return nullptr;
};


void Menu::reporteMatrizDispersa() {
  std::string nombreArchivo = "matrizDispersa";
  std::ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    archivo << "digraph MatrizDispersa {\n";
    archivo << "    bgcolor=\"#9bd4ff\"\n;";
    archivo << "    fontcolor=black\n;";
    archivo << "    label=\"MATRIZ DE USUARIOS\"\n;";
    archivo << "    labelloc=\"t\"\n;";
    archivo << "    nodesep=0.5\n;";
    archivo << "    node [shape=box style=filled color=\"#ffea9b\"];\n";
    archivo << "    edge [fontcolor=white color=red];\n";

    archivo << "    head [label=\"Usuarios\" group=1];\n";

    // cabeceras de departamentos (horizontal)
    archivo << "    // Cabeceras de Departamentos\n";
    NodeMat *auxDep = matriz->cabeDep;
    int contadorDep = 2;
    while (auxDep != nullptr) {
        archivo << "    \"" << auxDep << "\" [label=\"" << auxDep->getUsuario() << "\" group=" << std::to_string(contadorDep) <<" color=\"#ff9b9b\"];\n";
        if (auxDep->getSig() != nullptr) {
            archivo << "    \"" << auxDep << "\" -> \"" << auxDep->getSig() << "\";\n";
            archivo << "    \"" << auxDep->getSig() << "\" -> \"" << auxDep << "\";\n";
        }
        if (auxDep == matriz->cabeDep) {
          archivo << "    \"" << auxDep << "\" -> head;\n";
          archivo << "     head -> \"" << auxDep << "\";\n";
        }
        auxDep = auxDep->getSig();
        contadorDep++;
    }

    // cabeceras de empresas (vertical)
    archivo << "    // Cabeceras de Empresas\n";
    NodeMat *auxEmp = matriz->cabeEmp;
    while (auxEmp != nullptr) {
        archivo << "    \"" << auxEmp << "\" [label=\"" << auxEmp->getUsuario() << "\" group=1 color=\"#7fa0ff\"];\n";
        if (auxEmp->getAbajo() != nullptr) {
            archivo << "    \"" << auxEmp << "\" -> \"" << auxEmp->getAbajo() << "\";\n";
            archivo << "    \"" << auxEmp->getAbajo() << "\" -> \"" << auxEmp << "\";\n";
        }
        if (auxEmp == matriz->cabeEmp) {
          archivo << "    \"" << auxEmp << "\" -> head;\n";
          archivo << "     head -> \"" << auxEmp << "\";\n";
        }
        auxEmp = auxEmp->getAbajo();
    }


    // Nodos internos y conexiones

    archivo << "    // Nodos Internos\n";
    auxDep = matriz->cabeDep;
    int contadorColumnas = 2;
    while (auxDep != nullptr) {
        NodeMat *auxNodo = auxDep->getAbajo();  // Comienza desde el primer nodo debajo de la cabecera
        while (auxNodo != nullptr) {
            // Crear nodo
            archivo << "    \"" << auxNodo << "\" [label=\"" << auxNodo->getUsuario() << "\" group=" << contadorColumnas<< " ];\n";

            // Conexión vertical con la cabecera del departamento
            if (auxNodo->getArriba() == auxDep) {
                archivo << "    \"" << auxDep << "\" -> \"" << auxNodo << "\";\n";
                archivo << "    \"" << auxNodo << "\" -> \"" << auxDep << "\";\n";
            }

            // Conexión horizontal con la cabecera de la empresa
            if (auxNodo->getPrev()->getPrev() == nullptr) {
                archivo << "    \"" << auxNodo->getPrev() << "\" -> \"" << auxNodo << "\";\n";
                archivo << "    \"" << auxNodo << "\" -> \"" << auxNodo->getPrev() << "\";\n";
            }

            // Conexión con otros nodos verticales
            if (auxNodo->getAbajo() != nullptr) {
                archivo << "    \"" << auxNodo->getAbajo() << "\" -> \"" << auxNodo << "\";\n";
                archivo << "    \"" << auxNodo << "\" -> \"" << auxNodo->getAbajo() << "\";\n";
            }

            // Conexión con otros nodos horizontales
            if (auxNodo->getSig() != nullptr) {
                archivo << "    \"" << auxNodo << "\" -> \"" << auxNodo->getSig() << "\";\n";
                archivo << "    \"" << auxNodo->getSig() << "\" -> \"" << auxNodo << "\";\n";
            }

            auxNodo = auxNodo->getAbajo();
        }
        auxDep = auxDep->getSig();
      contadorColumnas++;
    }

  archivo << "    // Encuadre" << std::endl;
  auxDep = matriz->cabeDep;
  archivo << "    { rank=same ; head; ";
  while (auxDep != nullptr) {
    archivo << "\"" << auxDep << "\"; ";
    auxDep = auxDep->getSig();
  }
  archivo << "};\n";

  auxEmp = matriz->cabeEmp;
  while (auxEmp != nullptr) {
    NodeMat *auxNodo = auxEmp;
    archivo << "    { rank=same ; ";
    while ( auxNodo != nullptr) {
      archivo << "\"" << auxNodo << "\"; ";
      auxNodo = auxNodo->getSig();
    }
    archivo << "};\n";
    auxEmp = auxEmp->getAbajo();
  }

    archivo << "}\n";
    archivo.close();
    std::cout << "Archivo DOT generado con éxito: " << nombreArchivo << std::endl;


  // Generar la imagen automáticamente
  std::string comando = "dot -Tpng " + nombreArchivo + " -o matrizDispersa.png";
  system(comando.c_str());

  // Abrir la imagen generada automáticamente
  system("open matrizDispersa.png");

  menuAdmin();
  return;
};

void Menu::reporteDisponiblesxDep() {
  cout << "Reporte de activos disponibles de un departamento, creado" << endl;
  menuAdmin();
};

void Menu::reporteDisponiblesxEmp() {
  cout << "Reporte de activos disponibles de una empresa, creado" << endl;
  menuAdmin();
};

void Menu::reporteTransacciones() {
  cout << "Reporte de transacciones, creado." << endl;
  menuAdmin();
};

void Menu::reporteActivosxUsuario() {
  cout << "Reporte de activos de un usuario, creado." << endl;
  menuAdmin();
};

void Menu::activosRentados() {
  cout << " Reporte de activos rentados por un usuario, creado." << endl;
  menuAdmin();
};

void Menu::ordenarTransacciones() {
  cout << "Transacciones ordenadas." << endl;
  menuAdmin();
};


// /////////////////////////////////////////MÉTODOS UTILIZADOS POR EL USUARIO //////////////////////////////////////////////


void Menu::agregarActivo() {
  string nombreActivo;
  string descripcion;
  string idActivo;

  cout << "********************************* CREAR ACTIVO *************************" << endl;
  cout << "Ingresar nombre del activo: ";
  cin >> nombreActivo;
  cout << "Ingresar descripción: ";
  cin >> descripcion;

  idActivo = generarAleatorio();

  agregarActivo(nombreActivo, descripcion, idActivo);
  return;
};

void Menu::agregarActivo(std::string nombreActivo, std::string descripcion, std::string idActivo) {
  cout << "Se creó el activo " + nombreActivo + " exitosamente: ";
  menuUsuario();
}

void Menu::eliminarActivo() {
  menuUsuario();
};

void Menu::modificarActivo() {
  menuUsuario();
};

void Menu::rentarActivo() {
  menuUsuario();
};

void Menu::activosRentados_Usuario() {
  menuUsuario();
};

void Menu::misActivosRentados() {
  menuUsuario();
};

string Menu::generarAleatorio() {
  const string caracteres = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  random_device rd;
  mt19937 generador(rd());
  uniform_int_distribution<> distribucion(0, caracteres.size() - 1);

  std::string codigo;
  for (int i = 0; i < 15; ++i) {
    codigo += caracteres[distribucion(generador)];
  }

  return codigo;
}

void Menu::limpiarPantalla(){
  cout << string(50, '\n');
  return;
  }

