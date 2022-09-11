#include <iostream>
using namespace std;

class Oscar
{
private:
    String m_activo;
    double m_valores[100];

    //DINAMICA
    int m_dimension;
    double* m_valoresDinamico;

    static int m_nInstancias = 0;

public:
    Oscar();
    Oscar(String activo, double valores[100]);
    Oscar(const Oscar &obj_copiado); 

    //DINAMICA
    Oscar(String activo, int dimension);
    ~Oscar();

    //GETTERS
    String getActivo() const;
    double getValor(int indice) const;

    //SETTERS
    void setActivo(String activo);
    void setValor(int indice, double valor);

    Oscar operator-();
    Oscar operator+(const Oscar &rh);
    friend ostream &operator<<( ostream &output, const Oscar &objeto );

    static void sayHello();

};

class Derivada : public Oscar{

    public:

    private:


}

template <class miTipo1, class miTipo2>
class Plantilla{
    public:

    miTipo sum(miTipo1 a, miTipo2 b) { return a + b; }

    private:

    miTipo1 m_valor1;
    miTipo2 m_valor2;

}