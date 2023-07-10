#ifndef PIZZA_H
#define PIZZA_H

#include <iostream>
#include <vector>
#include <string>

class CPizza
{
protected:
    std::vector<std::string> ingredientes;
    double precio;

public:
    CPizza();
    CPizza(double precio);
    void listarIngredientes();
    virtual void preparar() = 0;
};

class CHawaiana : public CPizza
{
public:
    CHawaiana(double precio);
    void preparar();
};

class CPepperoni : public CPizza
{
private:
    bool incluyeBordeDeQueso;

public:
    CPepperoni(double precio, bool incluyeBordeDeQueso);
    void preparar();
};

class COrden
{
private:
    std::vector<CPizza *> pizzas;

public:
    COrden();
    void agregar_pizza(CPizza *pizza);
    friend std::ostream &operator<<(std::ostream &os, const COrden &orden);
};

#endif  // PIZZA_H