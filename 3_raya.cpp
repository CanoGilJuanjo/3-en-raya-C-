#include <iostream>
#include <array>
#include <math.h>
#include <cstdlib>


using namespace std;

//Variables constantes y matriz      Const variables and array matrix
const int DIMENSION_MATRIZ = 3; 
typedef array<int, DIMENSION_MATRIZ>Vfila;
typedef array<Vfila,DIMENSION_MATRIZ>Vmatriz;

//Referencia de funciones           function references
void interpretarPosicion(int posicion, int &i ,int &j);
void representar(Vmatriz &matriz);
bool ganador1(Vmatriz matriz);
bool ganador2(Vmatriz matriz);
bool empate(Vmatriz matriz);

//Main
int main(){
    //Creamos la matriz             Create the matrix
    Vmatriz matriz;

    //Inicializamos la matriz con 0      Set 0 as default value
    system("cls");
    for(int i = 0;i<DIMENSION_MATRIZ;i++){
        for(int j = 0;j<DIMENSION_MATRIZ;j++){
            matriz[i][j] = 0;
        }
    }

    representar(matriz);

    //Variables de control de victoria          win variables control       
    bool finJ1 = false;
    bool finJ2 = false;
    bool win = false;

    //Partida
    do
    {
        //Turno J1
        while (!finJ1)
        {
            int posicionSolicitada = 0;
            
            cout<<"Turno: Jugador 1"<<endl;
            while(!(cin >> posicionSolicitada) || posicionSolicitada<1 || posicionSolicitada > pow(DIMENSION_MATRIZ,2)){            
                cin.clear();
                cin.ignore(1000, '\n');
                cout<<"Posiciones erroneas, intentelo de nuevo"<<endl;
            }

            int i = 0, j = 0;
            interpretarPosicion(posicionSolicitada-1,i,j);
            if(matriz[i][j] == 0){
                matriz[i][j] = 1;
                finJ1 = true;
            }
            system("cls");
            representar(matriz);
            win = ganador1(matriz);
            if(win){
                cout<<"Victoria Jugador 1"<<endl;
                system("pause");
            }
        }
        finJ1 = false;

        //Comprobamos el caso de empate
        if(!win){
            win = empate(matriz);
            if(win){
                system("cls");
                cout<<"Empate"<<endl;
                system("pause");
            }
        }

        if(win){
            goto exit;
        }

        //Turno J2
        while (!finJ2)
        {
            int posicionSolicitada = 0;
            
            cout<<"Turno: Jugador 2"<<endl;
            while(!(cin >> posicionSolicitada) || posicionSolicitada<1 || posicionSolicitada > pow(DIMENSION_MATRIZ,2)){            
                cin.clear();
                cin.ignore(1000, '\n');
                cout<<"Posiciones erroneas, intentelo de nuevo"<<endl;
            }

            int i = 0, j = 0;
            interpretarPosicion(posicionSolicitada-1,i,j);
            if(matriz[i][j] == 0){
                matriz[i][j] = 2;
                finJ2 = true;
            }
            system("cls");
            representar(matriz);
            win = ganador2(matriz);
            if(win){
                cout<<"Victoria Jugador 2"<<endl;
                system("pause");
            }
        }
        finJ2 = false;

        //Comprobamos el caso de empate
        if(!win){
            win = empate(matriz);
            if(win){
                system("cls");
                cout<<"Empate"<<endl;
                system("pause");
            }
        }
    }while (!win);
    
    exit:
    return 0;
}

//Funciones         Funtions

void interpretarPosicion(int posicion, int &i ,int &j){
    if(posicion<=3){
        i = 0, j = posicion;
    }else if(posicion <= 6){
        i = 1, j = posicion-3;
    }else{
        i = 2, j = posicion-6;
    }
}

/*
    Para el jugador 1 tenemos la X
    Para el jugador 2 tenemos el O
    Si es 0 el valor sera vacio y no se representa
*/
void representar(Vmatriz &matriz){
    int contador = 1;
    for(int i = 0;i<DIMENSION_MATRIZ;i++){
        for (int j = 0; j < DIMENSION_MATRIZ; j++){
            cout<<"[";
            if(matriz[i][j] == 0){
                cout<<contador;
            }else if(matriz[i][j] == 1){
                cout<<"X";
            }else if(matriz[i][j] == 2){
                cout<<"O";
            }else{
                cout<<"E";
            }
            cout<<"] ";
            contador++;
        }
        cout<<endl;
    }
}

//Win control
bool ganador1(Vmatriz matriz){
    int contador = 0;
    
    //Diagonal principal
    for (int i = 0; i < DIMENSION_MATRIZ; i++)
    {
        if(matriz[i][i] == 1){
            contador++;
        }
        
    }
    if(contador == 3){
        return true;
    }

    //Diagonal inversa
    if(matriz[2][0] == 1 && matriz[1][1] == 1 && matriz[0][2] == 1){
        return true;
    }

    //Columnas
    contador = 0;
    for (int i = 0; i < DIMENSION_MATRIZ; i++)
    {
        for (int j = 0; j < DIMENSION_MATRIZ; j++)
        {
            if(matriz[j][i] == 1){
                contador++;
            }
        }
        if(contador == 3){
            return true;
        }else{
            contador = 0;
        }
        
    }
    
    //Filas
    for (int i = 0; i < DIMENSION_MATRIZ; i++)
    {
        for (int j = 0; j < DIMENSION_MATRIZ; j++)
        {
            if(matriz[i][j] == 1){
                contador++;
            }
        }
        if(contador == 3){
            return true;
        }else{
            contador = 0;
        }
        
    }

    return false;
}

bool ganador2(Vmatriz matriz){
    int contador = 0;
    
    //Diagonal principal
    for (int i = 0; i < DIMENSION_MATRIZ; i++)
    {
        if(matriz[i][i] == 1){
            contador++;
        }
    }
    if(contador == 3){
        return true;
    }

    //Diagonal inversa          
    if(matriz[2][0] == 2 && matriz[1][1] == 2 && matriz[0][2] == 2){
        return true;
    }

    //Columnas      columns
    contador = 0;
    for (int i = 0; i < DIMENSION_MATRIZ; i++)
    {
        for (int j = 0; j < DIMENSION_MATRIZ; j++)
        {
            if(matriz[j][i] == 2){
                contador++;
            }
        }
        if(contador == 3){
            return true;
        }else{
            contador = 0;
        }
        
    }
    
    //Filas         rows
    for (int i = 0; i < DIMENSION_MATRIZ; i++)
    {
        for (int j = 0; j < DIMENSION_MATRIZ; j++)
        {
            if(matriz[i][j] == 2){
                contador++;
            }
        }
        if(contador == 3){
            return true;
        }else{
            contador = 0;
        }
        
    }

    return false;
}

bool empate(Vmatriz matriz){
    int contador = 0;
    for (int i = 0; i < DIMENSION_MATRIZ; i++)
    {
        for (int j = 0; j < DIMENSION_MATRIZ && matriz[i][j] != 0; j++)
        {
            if(matriz[i][j] != 0){
                contador++;
            }
        }
    }
    if(contador == pow(DIMENSION_MATRIZ,2)){
        return true;
    }else {
        return false;
    }
    
}