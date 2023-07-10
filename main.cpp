/*
Clase 1:
CPizza
-ingredientes:
-precio: double
------
+CPizza()
+CPizza(precio: double)
+listarlngredientes()
+preparar()


Clase 2: 
CHawaina
+CHawaina(precio: double)
+preparar()

Clase 3:
CPepperoni
-incluyeBordeDeQueso: bool
+CPepperoni(precio: double)
+preparar()

Corden
*Pizzas:
+C0rden()
CPizza*)
*/

#include <iostream>
#include <vector>

class CPizza
{
protected:
    std::vector<std::string> ingredientes;
    double precio;

public:
    CPizza()
    {
        precio = 0;
        this->ingredientes.push_back("Salsa de tomate");
        this->ingredientes.push_back("Queso mozzarella");
    }

    CPizza(double precio)
    {
        this->precio = precio;
    }

    void listarIngredientes()
    {
        for (int i = 0; i < ingredientes.size(); i++)
        {
            std::cout << ingredientes[i] << std::endl;
        }
    }
    virtual void preparar() = 0;
};

class CHawaiana : public CPizza
{
public:
    CHawaiana(double precio) : CPizza(precio)
    {
        this->ingredientes.push_back("PineApple");
        this->ingredientes.push_back("Jamon");
        this->ingredientes.push_back("Masa Blanda");
        
    }

    void preparar()
    {
        // listar los pasos para preparar una pizza hawaina
        std::cout << "Preparando pizza hawaina..." << std::endl;
        std::cout << "1. Untar uniformemente la salsa sobre la masa" << std::endl;
        std::cout << "2. Agregar queso mozzarella" << std::endl;
        std::cout << "3. Agregar PineApple" << std::endl;
        std::cout << "4. Agregar Jamon" << std::endl;
        std::cout << "5. Hornear" << std::endl;
    }
};

class CPepperoni : public CPizza
{
private:
    bool incluyeBordeDeQueso;

public:
    CPepperoni(double precio, bool incluyeBordeDeQueso) : CPizza(precio)
    {
        this->incluyeBordeDeQueso = incluyeBordeDeQueso;
        this->ingredientes.push_back("Pepperoni");
        this->ingredientes.push_back("Masa Gruesa");
        this->ingredientes.push_back("Jamon");
    }

    void preparar()
    {
        // listar los pasos para preparar una pizza hawaina
        std::cout << "Preparando pizza pepperoni..." << std::endl;
        std::cout << "1. Untar uniformemente la salsa sobre la masa" << std::endl;
        std::cout << "2. Agregar queso mozzarella" << std::endl;
        std::cout << "3. Agregar Pepperoni" << std::endl;
        std::cout << "4. Hornear" << std::endl;
        if (incluyeBordeDeQueso)
        {
            std::cout << "5. Agregar borde de queso" << std::endl;
        }
    }
};


// Clase orden
// No olvidar sobre escribir el operador <<
class COrden
{
private:
    std::vector<CPizza *> pizzas;

public:
    COrden()
    {
    }

    void agregar_pizza(CPizza *pizza)
    {
        this->pizzas.push_back(pizza);
    }

    friend std::ostream &operator<<(std::ostream &os, const COrden &orden)
    {
        os << "Orden de pizzas:" << std::endl;
        for (int i = 0; i < orden.pizzas.size(); i++)
        {
            os << "Pizza " << i + 1 << ":" << std::endl;
            orden.pizzas[i]->listarIngredientes();
            orden.pizzas[i]->preparar();
            os << std::endl;
        }
        return os;
    }
};







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