#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

bool isDigit(const string& numString) {
    for (char c : numString) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> numberList;
    string numString;
    int num;
    char continueProgram;
    int maxNumber = numeric_limits<int>::min();
    int maxPosition = -1;
    int primeCount = 0, sumPrimes = 0;
    int nonPrimeCount = 0, sumNonPrimes = 0;

    do {
        do {
            cout << "Ingrese un numero: ";
            cin >> numString;
            if (!isDigit(numString)) {
                cout << "Error: El numero de factura debe contener solo numeros.\n";
            }
        } while (!isDigit(numString));
        num = stoi(numString);
        numberList.push_back(num);

        if (num > maxNumber) {
            maxNumber = num;
            maxPosition = numberList.size();
        }

        if (isPrime(num)) {
            cout << "El numero " << num << " es un Numero Primo" << endl;
            primeCount++;
            sumPrimes += num;
        } else {
            cout << "El numero " << num << " No es un Numero Primo" << endl;
            nonPrimeCount++;
            sumNonPrimes += num;
        }

        cout << "Desea ingresar otro numero? (s/n): ";
        cin >> continueProgram;
    } while (continueProgram == 's' || continueProgram == 'S');

    cout << "Numero Mayor Ingresado: " << maxNumber << " en la posicion " << maxPosition << endl;
    cout << "Cantidad de Numeros Primos: " << primeCount << endl;
    cout << "Sumatoria de los Numeros Primos: " << sumPrimes << endl;
    cout << "Promedio de los Numeros Primos: " << (primeCount ? static_cast<double>(sumPrimes) / primeCount : 0) << endl;
    cout << "Cantidad de Numeros No Primos: " << nonPrimeCount << endl;
    cout << "Sumatoria de los Numeros No Primos: " << sumNonPrimes << endl;
    cout << "Promedio de los Numeros No Primos: " << (nonPrimeCount ? static_cast<double>(sumNonPrimes) / nonPrimeCount : 0) << endl;

    return 0;
}
