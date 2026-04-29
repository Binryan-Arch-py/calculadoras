/*################################################################################\
# Copyright (C) 2026 Binryan-Arch-py                                              #
#                                                                                 #
# Este programa es software libre: puedes redistribuirlo y/o modificarlo          #
# bajo los terminos de la Licencia Publica General GNU publicada por la           #
# Free Software Foundation, ya sea la version 3 de la Licencia o                  #
# (a tu eleccion) cualquier version posterior                                     #
#                                                                                 #
# Este programa se distribuye con la esperanza de que sea util, pero              #
# SIN GARANTIA ALGUNA; ni siquiera garantia implicita de                          #
# MERCANTILIDAD o APTITUD PARA UN PROPOSITO DETERMINADO.                          #
# Consulte la Licencia Publica General GNU para obtener mas detalles.             #
#                                                                                 #
# Deberias haber recibido una copia de la Licencia Publica General GNU            #
# junto con este programa. Si no es asi, consulta <https://www.gnu.org/licenses/>.#
\################################################################################*/

#include <unordered_map>
#include <vector>
#include <iostream>
#include "utilidades.h"
#include <string>
#include <limits>

using std::string;

void sucesiones(), tablas(), promedios(), primos(), equivalencias();
float sucesiones_valor(const int& x), nota(const int& x);
int menu();

int main() {
    int modo = 0;
    char rep = 'n';
    do {
        modo = menu();
        switch (modo) {
            case 1:
                sucesiones();
                break;
            case 2:
                tablas();
                break;
            case 3:
                promedios();
                break;
            case 4:
                primos();
                break;
            case 5:
                equivalencias();
                break;
            default:
                std::cout << "[!] ERROR: opcion no disponible" << std::endl;
        }
        while (true) {
            std::cout << "quieres volver a usar el programa (s/n) ";
            std::cin >> rep;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ingresa solo 1 caracter por favor" << std::endl;
             } else {
                break;
            }
        }
    } while (rep == 's');
    return 0;
}

int menu() {
    int modo;
    string opciones[5] = {"1 = sucesiones", "2 = tablas de multiplicar", "3 = promedios", "4 = primos", "5 = equivalencias"};
    std::cout << "\nBIENVENIDO A LA CALCULADORA 5 EN 1" << std::endl;
    while (true) {
        std::cout << "seleccione el modo que quiere usar" << std::endl;
        for (string op : opciones) {
            std::cout << op << std::endl;
        }
        std::cout << "--> ";
        std::cin >> modo;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ingresa solo numeros enteros por favor" << std::endl;
        } else {
           break;
        }
    }
    return modo;
}
 
float sucesiones_valor(const int& x) {
    float num = 0;
    while (true) {
        std::cout << "ingresa el " << x << " numero de la sucesion: ";
        std::cin >> num;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "[!] ERROR: ingresa solo unicamente numeros.\n intente nuevamente\n";
            utils::sleep(0.7);
        } else {
            return num;
        }
    }
}

void sucesiones() {
    char rep = ' ';
    do {
        std::cout << "\nBIENVENIDO A LA CALCULADORA DE SUCESIONES" << std::endl;
        float primer_num = sucesiones_valor(1);
        float segundo_num = sucesiones_valor(2);
        float patron = segundo_num - primer_num;
        // comprobacion de entrada
        int longitud = 0;
        while (true) {
            std::cout << "que tan larga sera la sucesion: ";
            std::cin >> longitud;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[!] ERROR: ingresa solo numeros enteros\n" << std::endl;
                utils::sleep(0.7);
            } else {
                break;
            }
        }
        if (patron != primer_num) {
            float total = primer_num + patron;
            std::cout << "el numero 1 es " << primer_num << std::endl;
            for (int i = 2; i <= (longitud); i++) {
                std::cout << "el numero " << i << " es: " << total << std::endl;
                total += patron;
            }
        } else {
            float total = 0;
            for (int i = 1; i <= longitud; i++) {
                total = patron * i;
                std::cout << "el numero " << i << " es " << total << std::endl;
            }
        }
        while (true) {
            std::cout << "quieres volver a usar la calculadora de sucesiones? (s/n) ";
            std::cin >> rep;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "[!] ERROR: ingresa unicamente 1 caracter" << std::endl;
                utils::sleep(0.3);
            } else {
                break;
            }
        }
    } while (rep == 's');
}

void tablas() {
    char rep = ' ';
    do {
        std::cout << "\nBIENVENIDO A LAS TABLAS DE MULTIPLICAR" << std::endl;
        float valor = 0;
        while (true) {
            std::cout << "ingresa la tabla que quieres conocer: ";
            std::cin >> valor;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ingresa solo numeros por favor\n" << std::endl;
                utils::sleep(0.7);
            } else {
                break;
            }
        }
        int cantidad = 0;
        while (true) {
            std::cout << "ingresa la tabla que quieres conocer: ";
            std::cin >> cantidad;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ingresa solo numeros enteros por favor\n" << std::endl;
                utils::sleep(0.7);
            } else {
                break;
            }
        }
        for (int i = 1; i <= cantidad; i++) {
            std::cout << valor << " x " << i << " = " << valor * i << std::endl;
        }
        std::cout << "quieres volver a usar las tablas de multiplicar? (s/n) ";
        while (true) {
            std::cout << "quieres volver a usar las tablas de multiplicar? (s/n) ";
            std::cin >> rep;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "por favor ingresa solo 1 digito" << std::endl;
            } else {
                break;
            }
        }
    } while (rep == 's');
}

float obtener_notas(const int& x) {
    float nota = 0;
    while (true) {
        std::cout << "ingresa tu " << x << "nota: ";
        std::cin >> nota;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "ingresa solo numeros por favor\n" << std::endl;
            utils::sleep(0.7);
        } else {
            break;
        }
    }
    while (nota < 0 || nota > 10) {
        std::cout << "[!] ERROR: la nota debe estart entre 0 y 10" << std::endl;
        while (true) {
            std::cout << "intenta nuevamente: ";
            std::cin >> nota;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ingresa solo numeros por favor\n" << std::endl;
                utils::sleep(0.7);
            } else {
                break;
            }
        }
    }
    return nota;
}

void promedios() {
    char rep = ' ';
    do {
        std::cout << "\nBIENVENIDO A LA CALCULADORA DE PROMEDIOS" << std::endl;
        std::cout << "ingresa tus calificaciones del 0-10" << std::endl;
        float primer_nota = obtener_notas('1');
        float segunda_nota = obtener_notas('2');
        float tercer_nota = obtener_notas('3');
        float total = (primer_nota + segunda_nota + tercer_nota) / 3;
        std::cout << "tu calificacion es: " << total << std::endl;
        std::vector<std::pair<int, string>> mensajes = {
            {10, "increible, calificacion perfecta"},
            {9, "muy bien, casi perfecto"},
            {8, "lo hiciste bien, sigue asi"},
            {7, "aprobaste pero puedes mejorar"},
            {6, "aprobaste pero debes mejorar"},
            {0, "reprobaste, tienes que estudiar mas"}
        };
        for (const auto& [calificacion, mensaje] : mensajes) {
            if (total >= calificacion) {
                std::cout << mensaje << '\n';
                break;
            }
        }
        while (true) {
            std::cout << "quieres volver a usar la calculadora de promedios? (s/n) ";
            std::cin >> rep;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ingresa solo 1 caracter" << std::endl;
            } else {
                break;
            }
        }
    } while (rep == 's');
}

void primos() {
    char rep = ' ';
    do {
        std::cout << "\nBIENVENIDO A LA CALCULADORA DE NUMEROS PRIMOS" << std::endl;
        int limite = 0;
        while (true) {
            std::cout << "ingresa hasta que numero quieres saber los numeros primos: ";
            std::cin >> limite;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ingresa solo numeros enteros por favor\n" << std::endl;
                utils::sleep(0.7);
            } else {
                for (int i = 2; i <= limite; i++) {
                    if (i >= 2) {
                        bool primo = true;
                        for (int j = 2; j < i; j++) {
                            if ((i % j) == 0) {
                                primo = false;
                                break;
                            }
                        }
                        if (primo) {
                            std::cout << i << std::endl;
                        }
                    } else {
                        std::cout << "no hay numeros primos" << std::endl;
                    }
                }
                break;
            }
            while (true) {
                std::cout << "\nquieres volver a usar la calculadora de numeros primos? (s/n) ";
                std::cin >> rep;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "ingresa solo 1 caracter por favor" << std::endl;
                } else {
                    break;
                }
            }
            if (rep == 'n') {
                break;
            }
        }
    } while (rep == 's');
}

void equivalencias() {
    std::unordered_map<string, float> medidas = {
        {"km", 1000},
        {"m", 1},
        {"cm", 0.01},
        {"mm", 0.001}
    };
    float valor = 0;
    string primer_medida = " ", medida_final = " ";
    char rep = ' ';
    do {
        while (true) {
            std::cout << "ingresa el valor que quieres saber la equivalencia: ";
            std::cin >> valor;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ingresa solo numeros por favor" << std::endl;
            } else {
                break;
            }
        }
        std::cout << "en que medida es ese valor (km/m/cm/mm): ";
        std::cin >> primer_medida;
        std::cout << "a que medida quieres convertir ese valor (km/m/cm/mm): ";
        std::cin >> medida_final;
        if (medidas.count(primer_medida) && medidas.count(medida_final)) {
            double total = valor * medidas[primer_medida] / medidas[medida_final];
            std::cout << valor << ' ' << primer_medida << " son " << total << ' ' << medida_final << std::endl;
        } else {
            std::cout << "[!] ERROR: eso no esta disponible" << std::endl;
        }
        while (true) {
            std::cout << "quieres volver a usar la calculadora de equivalencias> (s/n) ";
            std::cin >> rep;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "ingresa solo 1 caracter por favor" << std::endl;
            } else {
                break;
            }
        }
    } while (rep == 's');
}
