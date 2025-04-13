# include <iostream>
# include <limits>
using namespace std;

void menu();
void leer_variable(int &variable);
void leer_variable_decimal(float &variable);
void decimalABinario(int n);
void decimalAOctal(int n);
void decimalAHexadecimal(int n); // muestra dígito por dígito

int main(){
    // Defino mis variables: 
    int opcion = 0;
    int unidad = 0;
    menu();
    do{
    leer_variable(opcion);
    if (opcion < 1 || opcion > 4)
    {
        cout << "Opcion invalida. Intenta de nuevo: ";
    }

    }while(opcion < 1 || opcion > 4);

    switch (opcion)
    {
    case 1:
        cout << "Ingresa un número: ";
        leer_variable(unidad);
        decimalABinario(unidad);
        break;
    case 2:
        cout << "Ingresa un número: ";
        leer_variable(unidad);
        decimalAOctal(unidad);
        break;
    case 3: 
        cout << "Ingresa un número: ";
        leer_variable(unidad);
        decimalAHexadecimal(unidad);
        break;
    case 4:
        cout << "Saliendo del programa..." << endl;
        cout << "¡¡Hasta luego!!";
        exit(EXIT_SUCCESS);
        break;
    default:
        cout << "¡¡Hasta luego camarada!!";
        break;
    }
    return 0;
}





void menu(){
    cout << "\n--- Selecciona una opcion ---" << endl;
    cout << "1. Decimal a Binario" << endl;
    cout << "2. Decimal a Octal" << endl;
    cout << "3. Decimal a Hexadecimal" << endl;
    cout << "4. Salir" << endl;
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

void leer_variable_decimal(float &variable){
    cin >> variable;
    while (cin.fail())
    {
       cin.clear();
       cin.ignore(std::numeric_limits<float>::max(), '\n');
       cout << "Ingresa un decimal, por favor: ";
       cin >> variable;
    }
    
}

// Función para convertir de decimal a binario: 
void decimalABinario(int n){
    if (n < 2)
    {
        cout << n;
    }else{
        decimalABinario(n / 2);
        cout << n % 2;
    }
}

// Función para convertir de decimal a octal: 
void decimalAOctal(int n){
    if (n < 8)
    {
        cout << n;
    }else{
        decimalAOctal(n / 8);
        cout << n % 8;
    }
}

// Función para convertir de decimal a hexadecimal: 
void decimalAHexadecimal(int n){
    if(n < 16){
        if (n < 10)
        {
            cout << n;
        }else{
            char letra = (n - 10 + 'A'); // ASCII
            cout << letra;
        }

    }else{
        decimalAHexadecimal(n / 16);
        int resto = n % 16;
        if (resto < 10)
        {
            cout << resto;
        }else{
            char letra = (resto - 10 + 'A'); // ASCII
            cout << letra;
        }
    }
}