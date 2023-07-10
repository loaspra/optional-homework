#include <iostream>
#include <vector>
#include "pizza.h"




// Main
int main () {
    COrden o1 ;
    o1.agregar_pizza( new CHawaiana (10));
    o1.agregar_pizza( new CPepperoni (20 , true ));
    o1.agregar_pizza( new CHawaiana (15));
    o1.agregar_pizza( new CPepperoni (20 , false ));
    std::cout << o1 ; // --- se ha sobrecargado el operador <<
return 0;
}