#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Sale {
    int invoiceNumber;
    string customerID;
    string customerName;
    int customerType;
    int ticketType;
    int ticketQuantity;
    double unitPrice;
    double saleAmount;
    double discount;
    double subtotal;
    double tax;
    double totalToPay;
};

bool isDigit(const string& id) {
    for (char c : id) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool isString(const string& name) {
    for (char c : name) {
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

bool isValidCustomerType(int customerType) {
    return customerType == 1 || customerType == 2;
}

bool isValidTicketType(int ticketType) {
    return ticketType == 1 || ticketType == 2;
}

bool isValidTicketQuantity(int ticketQuantity) {
    return ticketQuantity >= 1 && ticketQuantity <= 4;
}

int main() {
    int invoiceNumber = 1;
    int totalTicketsGallery = 0;
    double accumulatedGallery = 0;
    int totalTicketsBox = 0;
    double accumulatedBox = 0;
    int totalGeneralTickets = 0;
    double totalGeneralAmount = 0;

    char continueInput;
    do {
        Sale sale;

        // Validación del ID del cliente
        do {
            cout << "Ingrese cedula del cliente: ";
            cin >> sale.customerID;
            if (!isDigit(sale.customerID)) {
                cout << "Error: La cedula debe contener solo numeros.\n";
            }
        } while (!isDigit(sale.customerID));

        // Validación del nombre del cliente
        do {
            cout << "Ingrese nombre del cliente: ";
            cin.ignore();
            getline(cin, sale.customerName);
            if (!isString(sale.customerName)) {
                cout << "Error: El nombre solo debe contener letras.\n";
            }
        } while (!isString(sale.customerName));

        // Validación del tipo de cliente
        do {
            cout << "Tipo de cliente (1=Nino/Adulto mayor, 2=Adulto): ";
            cin >> sale.customerType;
            if (!isValidCustomerType(sale.customerType)) {
                cout << "Error: Tipo de cliente invalido. Ingrese 1 o 2.\n";
            }
        } while (!isValidCustomerType(sale.customerType));

        // Validación del tipo de tiquete
        do {
            cout << "Tipo de tiquete (1=Tiquete Galeria, 2=Tiquete Palco): ";
            cin >> sale.ticketType;
            if (!isValidTicketType(sale.ticketType)) {
                cout << "Error: Tipo de tiquete invalido. Ingrese 1 o 2.\n";
            }
        } while (!isValidTicketType(sale.ticketType));

        // Validación de la cantidad de tiquetes
        do {
            cout << "Cantidad de tiquetes a comprar (1-4): ";
            cin >> sale.ticketQuantity;
            if (!isValidTicketQuantity(sale.ticketQuantity)) {
                cout << "Error: La cantidad de tiquetes debe estar entre 1 y 4.\n";
            }
        } while (!isValidTicketQuantity(sale.ticketQuantity));

        // Asignación del precio del tiquete
        if (sale.ticketType == 1) {
            sale.unitPrice = 6000;
            totalTicketsGallery += sale.ticketQuantity;
        } else {
            sale.unitPrice = 12000;
            totalTicketsBox += sale.ticketQuantity;
        }

        sale.saleAmount = sale.unitPrice * sale.ticketQuantity;

        // Cálculo del descuento
        if (sale.customerType == 1) {
            sale.discount = sale.saleAmount * 0.3;
        } else {
            sale.discount = 0;
        }

        // Cálculos de subtotal, impuesto y total
        sale.subtotal = sale.saleAmount - sale.discount;
        sale.tax = sale.subtotal * 0.13;
        sale.totalToPay = sale.subtotal + sale.tax;

        // Actualización de totales generales
        totalGeneralTickets += sale.ticketQuantity;
        totalGeneralAmount += sale.totalToPay;
        if (sale.ticketType == 1) {
            accumulatedGallery += sale.totalToPay;
        } else {
            accumulatedBox += sale.totalToPay;
        }

        // Mostrar resumen de la venta
        cout << fixed << setprecision(2);
        cout << "\n--- Resumen de la Venta ---\n";
        cout << "Numero de Factura: " << invoiceNumber++ << endl;
        cout << "Cedula: " << sale.customerID << endl;
        cout << "Nombre: " << sale.customerName << endl;
        cout << "Tipo de Cliente: " << (sale.customerType == 1 ? "Nino/Adulto mayor" : "Adulto") << endl;
        cout << "Tipo de Tiquete: " << (sale.ticketType == 1 ? "Galeria" : "Palco") << endl;
        cout << "Cantidad de Tiquetes: " << sale.ticketQuantity << endl;
        cout << "Monto Unitario: " << sale.unitPrice << endl;
        cout << "Monto de Venta: " << sale.saleAmount << endl;
        cout << "Descuento: " << sale.discount << endl;
        cout << "Subtotal: " << sale.subtotal << endl;
        cout << "Impuesto: " << sale.tax << endl;
        cout << "Total a Pagar: " << sale.totalToPay << endl;

        // Continuar o no con otra venta
        cout << "\nDesea registrar otra venta? (s/n): ";
        cin >> continueInput;
    } while (continueInput == 's' || continueInput == 'S');

    // Mostrar estadísticas generales
    cout << "\n--- Estadisticas ---\n";
    cout << "Cantidad de Entradas Tiquetes Galeria: " << totalTicketsGallery << endl;
    cout << "Acumulado Dinero por Tiquetes Galeria: " << accumulatedGallery << endl;
    cout << "Cantidad de Entradas Tiquetes Palco: " << totalTicketsBox << endl;
    cout << "Acumulado Dinero por Tiquetes Palco: " << accumulatedBox << endl;
    cout << "Cantidad General de Entradas: " << totalGeneralTickets << endl;
    cout << "Acumulado General Dinero por Entradas: " << totalGeneralAmount << endl;
    cout << "Promedio General por Ventas: " << (totalGeneralTickets ? totalGeneralAmount / totalGeneralTickets : 0) << endl;

    return 0;
}
