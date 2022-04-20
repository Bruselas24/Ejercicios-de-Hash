#include <iostream>

using namespace std;

//Declaramos un string de 10 espacios y los dejamos con un string vacios para compraparlos despues
string claves[] = {"","","","","","","","","",""};

//Funcion de hash a utilizar
int fHash (string palabra){
    int valor = 0;

    for(int i = 0; i < palabra.length(); i++){
        //Iteramos sobre cada letra de la palabra y le sumamos su valor ASCII
        valor += palabra[i];
    };
    //Devolvemos el resto entre el valor y la longitud del array
    return (valor % 10);
};

//Funcion de Inserción
bool insercion(int indice, string palabra){

    //Verificamos si el indice que nos pasaron como parametro esta vacio
    if(claves[indice] != ""){
        //En caso de no estar vacio devolvemos false por que no podemos sobreescribir
        //la informacion guardada en la matriz
        return false;
    }

    //De lo contrario guardamos la informacion con el indice generado por la funcion de hash
    claves[indice] = palabra;
    return true;
};

int main()
{
    //Palabra que ingresara el ususario
    string clave;

    for(int i = 0; i < 10; i++){
        cout << "Ingrese su clave: ";
        //Leemos la palabra
        cin >> clave;

        //Calculamos con la funcion de hash el indice en el array
        int posicion = fHash(clave);
        cout << posicion << endl;

        //Mientras que la funcion de insercion se incapaz de almacenar la informacion
        //por que el espacio del array ya esta ocupado usaremos el metodo de "Prueba Lineal"
        //para encontrar un nuevo espacio
        while(!insercion(posicion,clave)){
            //en caso de no poder sumaremos 1 al indice
            posicion += 1;

            //Una vez que lleguemos a 10 debemos volver la posicion a 0
            //para evitar irnos del rango del array
            if(posicion == 10){
                posicion = 0;
            }
        }
    }


    //Mostramos el resultado
    cout << "Indice      Valor" << endl;
    for(int i = 0; i < 10; i++){
        cout << i <<"           "<< claves[i] <<endl;

    }

    return 0;
}
