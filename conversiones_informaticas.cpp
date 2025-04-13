# include <iostream>
# include <stab.h>
using namespace std;

void leer_variable(int &variable);
void leer_variable_float(float &variable);
void menu();
float bitsABytes(float bits);
float kilobytesABytes(float kb);
float megabytesAKilobytes(float mb);
float gigabytesAMegabytes(float gb);


int main(){
    int opcion = 0;
    float unidad = 0;
    char repetir;
    
    do
    {
        menu();
        do{
        leer_variable(opcion);
        if (opcion < 1 || opcion > 5)
        {
            cout << "Opcion invalida. Intenta de nuevo: ";
        }
    
        }while(opcion < 1 || opcion > 5);

    switch (opcion)
    {
    case 1:
        cout << "Ingrese los Bits: ";
        leer_variable_float(unidad);
        cout << bitsABytes(unidad) << "Bytes" << endl;
        break;
    case 2:
        cout << "Ingrese los KiloBytes (KB): ";
        leer_variable_float(unidad);
        cout << kilobytesABytes(unidad) << " Bytes" << endl;
        break;
    case 3: 
        cout << "Ingrese los Megabytes (MB): ";
        leer_variable_float(unidad);
        cout << megabytesAKilobytes(unidad) << " KB"<< endl;
        break;
    case 4: 
        cout << "Ingrese los Gigabytes (GB): ";
        leer_variable_float(unidad);
        cout << gigabytesAMegabytes(unidad) << "MB" << endl;
        break;
    case 5: 
        cout << "Saliendo del programa..." << endl;
        cout << "¡¡Hasta luego!!";
        exit(EXIT_SUCCESS);
        break;
    default:
        break;
    }
       cout << "¿Deseas continuar realizando conversiones (s/n)?";
       cin >> repetir;
    } while (repetir == 's' || repetir == 'S');

    return 0;
}

// Función para convertir de bits a bytes: 
float bitsABytes(float bits){
    float bytes = bits / 8;
    return bytes;
}

// Función para convertir de kilobytes a bytes:
float kilobytesABytes(float kb){
    float bytes = kb * 1024;
    return bytes;
}

// Función para convertir los Megabytes a Kilobytes:
float megabytesAKilobytes(float mb){
    float kilobytes = mb * 1024;
    return kilobytes;
}

// Función para convertir los Gigabytes a Megabytes: 
float gigabytesAMegabytes(float gb){
    float megabytes = gb * 1024;
    return megabytes;
}


void menu(){
    cout << "\n--- Selecciona una opcion ---" << endl;
    cout << "1. Bits a Bytes" << endl;
    cout << "2. Kilobytes a Bytes" << endl;
    cout << "3. Megabytes a Kilobytes" << endl;
    cout << "4. Gigabytes a Megabytes" << endl;
    cout << "5. Salir" << endl;
}

void leer_variable_float(float &variable){
    cin >> variable;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<float>::max(), '\n');
        cout << "Ingresa una unidad valida, por favor: ";
        cin >> variable;
    }
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