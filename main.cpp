#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <ctime>

using namespace std;

int main() {

    int monedas, ganancias = 0;

    srand(time(NULL));

    do {

        cout << "Ingrese la cantidad de monedas que desee jugar (1-10)" << endl;
        cin >> monedas;
        if (monedas < 1 || monedas > 10) {

            cout << "El número de monedas debe encontrarse entre 1 y 10. Intente nuevamente" << endl;

        }

    }

    while (monedas < 1 || monedas > 10);

    for (int i = 0; i < monedas; i++) {

        char tecla;
        
        do {
    
            cout << "Presione 'p' para tirar la palanca" << endl;
            
            tecla = _getch();
    
        }
    
        while (tecla != 'p' && tecla != 'P');

        int num1, num2, num3;

        num1 = rand() % 3 + 1;
        num2 = rand() % 3 + 1;
        num3 = rand() % 3 + 1;
        
        cout << "Número 1: " << num1 << endl;
        cout << "Número 2: " << num2 << endl;
        cout << "Número 3: " << num3 << endl;
        
        if (num1 == num2 && num2 == num3) {

            ganancias++;

        }

    }

    cout << "Usted ha ganado " << ganancias << " veces." << endl;

    return 0;

    
}