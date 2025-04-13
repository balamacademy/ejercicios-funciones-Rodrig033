# include <iostream>
# include <limits>
# include <stdlib.h>
using namespace std;

void menu();
void leer_variable(short int &variable);
void leer_variable_float(float &variable);
float celsiusAFahrenheit(float unidad);
float fahrenheitACelsius(float unidad);
float metrosAPies(float unidad);
float kilogramosALibras(float unidad);

int main(){
    float unidad = 0;
    short int indice = 0;
    char repetir;

    do
    {
        menu();
        do{
        cout << "Elige una opcion: ";
        leer_variable(indice);
        if (indice < 1 || indice > 5)
        {
            cout << "Opcion invalida. Intenta de nuevo." << endl;
        }
    
        }while(indice < 1 || indice > 5);
        

        switch (indice)
        {
        case 1:
            cout << "Ingrese el valor en celsius: " ;
            leer_variable_float(unidad);
            cout << "Farenheit: " << celsiusAFahrenheit(unidad);
            break;
        case 2: 
            cout << "Ingrese el valor en Farenheit: ";
            leer_variable_float(unidad);
            cout << "Fahrenheit: " << fahrenheitACelsius(unidad);
            break;
        case 3:
            cout << "Ingrese el valor en metros: ";
            leer_variable_float(unidad);
            cout << metrosAPies(unidad);
            break;
        case 4:
            cout << "Ingrese el valor en kilogramos: ";
            leer_variable_float(unidad);
            cout << kilogramosALibras(unidad);
            break;
        case 5:
            cout << "Saliendo del programa..." << endl;
            cout << "¡¡Hasta luego!!";
            exit(EXIT_SUCCESS);
            break;
        default:
            cout << "¡¡Hasta luego camarada!!";
            break;
        }
    
        cout << "\n¿Deseas continuar realizando conversiones (s/n)?";
        cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}

void menu(){
    cout << "---- Elige una opción ---- " << endl;
    cout << "1. Celsius a Fahreheit" << endl;
    cout << "2. Fahrenheit a Celsius" << endl;
    cout << "3. Metros a pies" << endl;
    cout << "4. Kilogramos a Libras" << endl;
    cout << "5. Salir" << endl;
}

float celsiusAFahrenheit(float unidad){
    float celsius_to_faren = (unidad * 9/5) + 32;
    return celsius_to_faren;
}
float fahrenheitACelsius(float unidad){
    float farenheit_to_cels = ((unidad - 32) * 5) / 9;
    return farenheit_to_cels;
}

float metrosAPies(float unidad){
    float metros_to_pies = unidad * 3.281;
    cout << unidad << " metros a pies son: " << metros_to_pies;
    return metros_to_pies;
}

float kilogramosALibras(float unidad){
    float kilo_to_libra = unidad * 2.205;
    cout << unidad << " Kilos a libras son: " << kilo_to_libra;
    return kilo_to_libra;
}

void leer_variable(short int &variable){
    cout << "\nIngrese un valor: ";
    cin >> variable;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(), '\n');
        cout << "Ingresa un numero entero, por favor: ";
        cin >> variable;
    }
}

void leer_variable_float(float &variable){
    cin >> variable;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<float>::max(), '\n');
        cout << "Ingresa un numero entero, por favor: ";
        cin >> variable;
    }
}
