#include "Oscar.h"

Oscar::Oscar(){
    m_activo = "";

    for(int i = 0; i < 100; i++)
    {
        m_valores[i] = 0.0f;
    }

    m_dimension = 0;

    m_nInstancias++;
}

Oscar::Oscar(String activo, double valores[100]){
    m_activo = activo;

    for(int i = 0; i < 100; i++)
    {
        m_valores[i] = valores[i];
    }

    m_dimension = 0;
}

Oscar::Oscar(String activo, int dimension){
    m_activo = activo;

    m_dimension = dimension;

    m_valoresDinamico = new double[m_dimension];

    for(int i = 0; i < m_dimension; i++)
    {
        m_valoresDinamico[i] = 0.0f;
    }
}

Oscar::Oscar(const Oscar &obj_copiado){
    m_activo = obj_copiado.m_activo;
    

    for(int i = 0; i < 100; i++)
    {
        m_valores[i] = obj_copiado.m_valores[i];
    }

    m_dimension = obj_copiado.m_dimension;

    m_nInstancias++;
}

Oscar::~Oscar(){
    delete[] m_valoresDinamico;
}


String Oscar::getActivo(){ return m_activo; }
double Oscar::getValor(int indice){ return m_valores[indice]; }

void Oscar::setActivo(String activo){
    m_activo = activo;
}
void Oscar::setValor(int indice, double valor){
    m_valores[indice] = valor;
}

static void sayHello(){
    cout << "Hello!" << endl;
}

Oscar::operator-(){
    for(int i = 0; i < 100; i++)
    {
        m_valores[i] = -m_valores[i];
    }

    return Oscar(m_activo, m_valores)
}

Oscar::operator+(const Oscar &rh){
    double resultado[100];

    for(int i = 0; i < 100; i++)
    {
        resultado[i] = m_valores[i] + rh.m_valores[i];
    }

    return Oscar(m_activo, resultado);

}

friend ostream &operator<<( ostream &output, const Oscar &objeto ) { 
    output << "Activo: " << objeto.m_activo << endl <<" Valor 1: " << objeto.m_activo[0];
    return output;            
}


template <class miTipo1, class miTipo2>
miTipo sum(miTipo1 a, miTipo2 b) { return a + b; }


void main(){
    Oscar objeto1;
    Oscar objeto2("EUR", arr);
    Oscar objeto3("USD", 20);

    double activo5 = objeto1.getValor(5);

    Oscar.sayHello();

    objeto1 = -objeto1;

    objeto1 = objeto1 + objeto2;

    cout << objeto1;

    int a = 2, b = 3;
    int c = sum<int, int>(a, b);

    Plantilla<int, float> obj;
}