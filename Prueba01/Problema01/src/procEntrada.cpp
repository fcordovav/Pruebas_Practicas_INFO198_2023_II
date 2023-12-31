#include "../include/funciones.h"

// Esta funcion valida que las entradas no sean vacias.
bool algunParametroVacio(const string &param, const string &nombreParametro) {
    if (param.empty()) {
        cerr << "El parámetro " << nombreParametro << " es OBLIGATORIO\n";
        return true;
    }
    return false;
}


bool usuarioExiste(const string& usuario, const string& contrasena, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombreArchivo << endl;
        exit(EXIT_FAILURE);
    }
    
    string linea;
    while (getline(archivo, linea)) {
        size_t igual = linea.find('=');
        if (igual != string::npos) {
            if (linea.substr(0, igual) == usuario && linea.substr(igual + 1) == contrasena) {
                archivo.close(); 
                return true;
            }
        }
    }

    archivo.close();
    return false;
}
