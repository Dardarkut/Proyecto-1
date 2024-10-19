#include <iostream>
#include <string>

using namespace std;

bool isDigit(const string& input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    string input;
    int number, reverseNum;
    char isContinueProgram;

    do {
        do {
            cout << "Ingrese un numero entero (maximo 5 digitos): ";
            cin >> input;

            // Verificar si la cadena contiene solo dígitos
            if (!isDigit(input)) {
                cout << "Error: Solo se permiten numeros. Intente nuevamente.\n";
                continue;
            }

            // Verificar si el tamaño del input es mayor a 5 dígitos
            if (input.length() > 5) {
                cout << "Error: El numero tiene mas de 5 digitos. Intente nuevamente.\n";
                continue;
            }

            // Intentar convertir la cadena a número y verificar rango
            try {
                number = stoi(input); // Convertir la cadena a número
                if (number < 0 || number > 99999) {
                    cout << "Numero fuera de rango. Intente nuevamente." << endl;
                }
            } catch (const out_of_range& e) {
                cout << "Numero fuera de rango. Intente nuevamente." << endl;
                continue;
            }

        } while (!isDigit(input) || input.length() > 5 || number < 0 || number > 99999); // Validaciones combinadas

        reverseNum = 0;
        int temp = number;

        while (temp > 0) {
            reverseNum = reverseNum * 10 + (temp % 10);
            temp /= 10;
        }

        cout << "Numero ingresado: " << number << endl;
        cout << "Numero inverso: " << reverseNum << endl;

        cout << "Desea ingresar otro numero? (s/n): ";
        cin >> isContinueProgram;
    } while (isContinueProgram == 's' || isContinueProgram == 'S');

    return 0;
}
