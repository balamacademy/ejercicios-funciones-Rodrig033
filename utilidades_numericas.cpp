# include <iostream>
#include <stdlib.h>
using namespace std;


void menu();
void leer_variable(int &variable);
bool esPrimo(int n);
int factorial(int n);
int contarDigitos(int n);
int sumarDigitos(int n);



int main(){
    // Defino la opción:
    int opcion = 0;
    int numero = 0;
    char repetir;

do{
    menu();
    do{
    cout << "Elige una opcion: ";
    leer_variable(opcion);
    if (opcion < 1 || opcion > 5)
    {
        cout << "Opcion invalida. Intenta de nuevo." << endl;
    }
    

    }while(opcion < 1 || opcion > 5);
    

    switch (opcion)
    {
    case 1:
        // Verificar si es primo:
        cout << "Ingrese un numero entero: ";
        leer_variable(numero);
        if (esPrimo(numero)){
            cout << numero << " es un numero primo.";
        }else{
            cout << numero << " no es un numero primo.";
        }
        break;
    case 2:
        cout << "Ingrese un numero entero: ";
        leer_variable(numero);
        cout << "El factorial de " << numero << "es: "<< factorial(numero) << endl;
        break;
    case 3:
        cout << "Ingrese un numero entero: ";
        leer_variable(numero);
        cout << contarDigitos(numero) << endl;
        break;
    case 4: 
        cout << "Ingrese un numero entero: ";
        leer_variable(numero);
        cout << sumarDigitos(numero) << endl;
        break;
    case 5: 
        cout << "\nSaliendo del programa..." << endl;
        cout << "¡¡Hasta la proxima!!";
        exit(EXIT_SUCCESS);
        break;
    default:
        cout << "¡¡Hasta la proxima!!" << endl;
        break;
    }
    cout << "\n¿Desea seguir realizando calculos (s/n)?";
    cin >> repetir;
}while(repetir == 's' || repetir == 'S');
    cout << "\nGracias por usar el programa, ¡Adios!";
    return 0;
} 

   

// Función para verificar si es un número primo: 
bool esPrimo(int n){
    if (n <= 1)
    {
        return false;
    }else{
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

// Función para imprimir el factorial de un número:
int factorial(int n){
    int factorial = 1;
   for (int i = 1; i <= n; i++)
   {
     factorial = factorial * i;
   }
   return factorial;
}

// Función para contar cuantos digitos tiene un número:
int contarDigitos(int n){
    n = abs(n); // Convertir a positivo.
    int contador = 0;
    if (n == 0)
    {
        contador = 1; 
    }else{
        while (n != 0)
        {
            n /= 10;
            contador ++;
        }
    }
    return contador;
}

// Función para sumar los dígitos de un número:
int sumarDigitos(int n){
    n = abs(n); // Convertir a positivo
    int suma = 0;
    while (n > 0)
    {
        suma += n % 10;
        n /= 10;
    }
    return suma;
}



void menu(){

    cout << "\n--- Selecciona una opcion ---" << endl;
    cout << "1. Verificar si un numero es primo" << endl;
    cout << "2. Calcular el factorial de un numero" << endl;
    cout << "3. Contar cuantos digitos tiene un numero" << endl;
    cout << "4. Sumar los digitos de un numero" << endl;
    cout << "5. Salir" << endl;
}



void leer_variable(int &variable){
    cin >> variable;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Ingresa un numero entero, por favor: ";
        cin >> variable;
    }
}