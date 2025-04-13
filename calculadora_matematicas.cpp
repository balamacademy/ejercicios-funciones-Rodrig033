# include <iostream>
# include <limits>
#include <stdlib.h>
using namespace std;

void exit(int status);
void menu();
void leer_variable(int &variable);
int sumar(int &n1, int &n2);
int resta(int &n1, int &n2);
int multiplicar(int &n1, int&n2);
float dividir(int &n1, int&n2);

int main(){

    int n1 = 0;
    int n2 = 0;
    int opcion = 0;
    int resultado = 0;

    cout << "\n¡¡Bienvenido a la calculadora!!\n";
    while (opcion != 5)
    {
        menu();
        do{
        leer_variable(opcion);
        if (opcion < 1 || opcion > 5)
        {
            cout << "Opcion invalida. Intenta de nuevo." << endl;
        }
    
        }while(opcion < 1 || opcion > 5);
        
        switch(opcion){
            case 1:
            cout << "Ingrese valor 1: ";
            leer_variable(n1);
            cout << "Ingrese el valor 2: ";
            leer_variable(n2);
            resultado = sumar(n1, n2);
            cout << "La suma es: " << resultado << "\n";
            break;
            case 2:
            cout << "Ingrese valor 1: ";
            leer_variable(n1);
            cout << "Ingrese el valor 2: ";
            leer_variable(n2);
            resultado = resta(n1, n2);
            cout << "La resta es: " << resultado << "\n";
            break;
            case 3:
            cout << "Ingrese valor 1: ";
            leer_variable(n1);
            cout << "Ingrese el valor 2: ";
            leer_variable(n2);
            resultado = multiplicar(n1, n2);
            cout << "La multilicacion es: " << resultado << "\n";
            break;
            case 4:
            cout << "Ingrese el valor para el dividendo: ";
            leer_variable(n1);
            do
            {
               cout << "Ingrese el valor para el divisor:  ";
               leer_variable(n2);
               if (n2 == 0)
               {
                   cout << "¡¡Error matematico!!, no puedes dividir entre cero." << endl;
               }   
            } while (n2 == 0);
            cout << "La division es: " << dividir(n1, n2);
            break;
            case 5:
            cout << "Saliendo del programa..." << endl;
            cout << "¡¡Gracias por usar el programa, adios!!";
            exit(EXIT_FAILURE);
            break;
            
        }
    }
    return 0;

}
void menu(){
    cout << "\n--- Elige una opcion ---\n";
    cout << "1. Suma\n";
    cout << "2. Resta\n";
    cout << "3. Multiplicacion\n";
    cout << "4. Division\n";
    cout << "5. Salir\n";
}

void leer_variable(int &variable){
    cin >> variable;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Ingresa un numero entero, por favor: ";
        cin >> variable;
    }
    
}


int sumar(int &n1, int &n2){
    return n1+n2;
}

int resta(int &n1, int&n2){
    return n1-n2;
}

int multiplicar(int &n1, int&n2){
    return n1*n2;
}

float dividir(int &n1, int&n2){
    return static_cast <float> (n1) / n2;
}
