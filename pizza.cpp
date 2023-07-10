#include "Pizza.h"

CPizza::CPizza()
{
    precio = 0;
    this->ingredientes.push_back("Salsa de tomate");
    this->ingredientes.push_back("Queso mozzarella");
}

CPizza::CPizza(double precio)
{
    this->precio = precio;
}

void CPizza::listarIngredientes()
{
    for (int i = 0; i < ingredientes.size(); i++)
    {
        std::cout << ingredientes[i] << std::endl;
    }
}

CHawaiana::CHawaiana(double precio) : CPizza(precio)
{
    this->ingredientes.push_back("PineApple");
    this->ingredientes.push_back("Jamon");
    this->ingredientes.push_back("Masa Blanda");
}

void CHawaiana::preparar()
{
    std::cout << "Preparando pizza hawaina..." << std::endl;
    std::cout << "1. Untar uniformemente la salsa sobre la masa" << std::endl;
    std::cout << "2. Agregar queso mozzarella" << std::endl;
    std::cout << "3. Agregar PineApple" << std::endl;
    std::cout << "4. Agregar Jamon" << std::endl;
    std::cout << "5. Hornear" << std::endl;
}

CPepperoni::CPepperoni(double precio, bool incluyeBordeDeQueso) : CPizza(precio)
{
    this->incluyeBordeDeQueso = incluyeBordeDeQueso;
    this->ingredientes.push_back("Pepperoni");
    this->ingredientes.push_back("Masa Gruesa");
    this->ingredientes.push_back("Jamon");
}

void CPepperoni::preparar()
{
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

COrden::COrden()
{
}

void COrden::agregar_pizza(CPizza *pizza)
{
    this->pizzas.push_back(pizza);
}

std::ostream &operator<<(std::ostream &os, const COrden &orden)
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