#################################################################################
# Copyright (C) 2026 Binryan-Arch-py
#
# Este programa es software libre: puedes redistribuirlo y/o modificarlo
# bajo los terminos de la Licencia Publica General GNU publicada por la 
# Free Software Foundation, ya sea la version 3 de la Licencia o 
# (a tu eleccion) cualquier version posterior
#
# Este programa se distribuye con la esperanza de que sea util, pero 
# SIN GARANTIA ALGUNA; ni siquiera garantia implicita de 
# MERCANTILIDAD o APTITUD PARA UN PROPOSITO DETERMINADO.
# Consulte la Licencia Publica General GNU para obtener mas detalles.
#
# Deberias haber recibido una copia de la Licencia Publica General GNU 
# junto con este programa. Si no es asi, consulta <https://www.gnu.org/licenses/>.
##################################################################################

import time

def menu():
    opciones = ['1 = sucesiones', '2 = tablas de multiplicar', '3 = promedios', '4 = primos', '5 = equivalencias']
    print("\nBIENVENIDO A LA CALCULADORA 5 EN 1")
    print("seleccione el modo que quiere usar")
    for op in opciones:
        print(op)
    modo = input()
    return modo


def sucesiones():
    while True:
        print("\nBIENVENIDO A LA CALCULADORA DE SUCESIONES")
        primer_num = sucesiones_valor(1)
        segundo_num = sucesiones_valor(2)
        patron = segundo_num - primer_num
        while True:
            try:
                longitud = int(input("que tan larga sera la sucesion: "))
            except ValueError:
                print("ingresa solo numeros enteros por favor\n")
                time.sleep(0.7)
            else: break
        if patron != primer_num:
            total = primer_num + patron
            print(f"el numero 1 es {primer_num}")
            for i in range(2, longitud + 1):
                print(f"el numero {i} es {total}")
                total += patron
        else:
            for i in range(1, longitud + 1):
                total = patron * i
                print(f"el numero {i} es {total}")
        repeticion = input("quieres volver a usar la calculadora de sucesiones? (s/n) ")
        if repeticion == 'n': break


def sucesiones_valor(x):
    while True:
        try:
            num = float(input(f"ingresa el {x} numero de la sucesion: "))
        except ValueError:
            print("ingresa solo numeros por favor\n")
            time.sleep(0.7)
        else: break
    return num


def tablas():
    while True:
        print("\nBIENVENIDO A LAS TABLAS DE MULTIPLICAR")
        while True:
            try:
                valor = float(input("ingresa la tabla quieres conocer: "))
            except ValueError:
                print("ingresa solo numeros por favor\n")
                time.sleep(0.7)
            else: break
        while True:
            try:
                cantidad = int(input("ingresa las tablas que quieres conocer: "))
            except ValueError:
                print("ingresa solo numers enteros por favor")
                time.sleep(0.7)
            else: break
        for i in range(1, cantidad + 1):
            print(f"{valor} x {i} = {valor * i}")
        repeticion = input("quieres volver a usar las tablas de multiplicar? (s/n) ")
        if repeticion == 'n': break

def promedios():
    while True:
        print("\nBIENVENIDO A LA CALCULADORA DE PROMEDIOS")
        print("ingresa las calificaciones del 0-10")
        primer_nota = notas(1)
        segunda_nota = notas(2)
        tercer_nota = notas(3)
        total = (primer_nota + segunda_nota + tercer_nota) / 3
        print(f"tu calificacion es: {total}")
        mensajes = [
            (10, 'increible, calificacion perfecta'),
            (9, 'muy bien, casi perfecto'),
            (8, 'lo hiciste bien, sigue asi'),
            (7, 'aprobaste pero puedes mejorar'),
            (6, 'aprobaste pero tienes que mejorar'),
            (0, 'reprobaste, tienes que estudiar mas')
        ]
        for calificacion, mensaje in mensajes:
            if total >= calificacion:
                print(mensaje)
                break
        repeticion = input("quieres volver a usar la calculadora de promedios? (s/n) ")
        if repeticion == 'n': break


def notas(i):
    while True:
        try:
            nota = float(input(f"ingresa tu {i} nota: "))
        except ValueError:
            print("ingresa solo numeros por favor\n")
            time.sleep(0.7)
        else: break
    while nota < 0 or nota > 10:
        print("ERROR, LA NOTA DEBE ESTAR ENTRE 0 Y 10")
        while True:
            try:
                nota = float(input("intenta nuevamente: "))
            except ValueError:
                print("ingresa solo numeros por favor\n")
                time.sleep(0.7)
            else: break
    return nota


def primos():
    while True:
        print("\nBIENVENIDO A LA CALCULADORA DE NUMEROS PRIMOS")
        while True:
            try:
                limite = int(input("ingresa hasta que numero quieres saber los numeros primos: "))
            except ValueError:
                print("ingresa solo numeros enteros por favor\n")
                time.sleep(0.7)
            else:
                for n in range(2, limite + 1):
                    if n >= 2:
                        for i in range(2, n):
                            if (n % i) == 0: break
                        else: print(n)
                    else: print("no hay numeros primos")
                else: break
        repeticion = input("\nquieres volver a usar la calculadora de numeros primos? (s/n) ")
        if repeticion == 'n': break

def equivalencias():
    medidas = {
        'km': 1000,
        'm': 1,
        'cm': 0.01,
        'mm': 0.001
    }
    while True:
        while True:
            try:
                valor = float(input("ingresa el valor que quieres saber la equivalencia: "))
            except ValueError:
                print("ingresa solo numeros por favor")
                time.sleep(0.7)
            else: break
        primer_medida = input("en que medida es ese valor (km/m/cm/mm): ")
        medida_final = input("a que medida quieres convertir ese valor (km/m/cm/mm): ")
        if primer_medida in medidas and medida_final in medidas:
            total = valor * medidas[primer_medida] / medidas[medida_final]
            print(f"{valor} {primer_medida} son {total} {medida_final}")
        else: print("ERROR, eso no esta disponible")
        repeticion = input("quieres volver a usar la calculadora de equivalencias? (s/n): ")
        if repeticion == 'n': break

 
def main():
    while True:
        modo = menu()
        if modo == '1': sucesiones()
        elif modo == '2': tablas()
        elif modo == '3': promedios()
        elif modo == '4': primos()
        elif modo == '5': equivalencias()
        else: print("ERROR, opcion no disponible")
        repeticion = input("quieres volver a usar el programa? (s/n): ")
        if repeticion == 'n': break

if __name__ == "__main__":
    main()
