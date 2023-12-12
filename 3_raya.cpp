#include <iostream>
#include <array>
#include <exception>

using namespace std;

// ACLARACION: El codigo fue compilado antes de cambiar los mensajes de error

int main()
{
    //Creacion de variables
    typedef array<int,3>Vector;
    typedef array<Vector,3>Tablero;
    
    Tablero tablero;
    
    for(int i = 0; i<3;i++)
    {
        for(int j = 0; j<3;j++)
        {
            tablero[i][j] = 0;
        }
    }
    
    bool victoria = false;
    bool jugador = true;    //<- controlamos el jugador que ha ganado
    bool empate = true;
    do{
        //  Representacion
        empate = true;
        unsigned con = 0;
        double pos;
        system("cls");
        for(int i = 0; i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
                if(tablero[i][j] == 0)
                {
                    cout<<"[ "<<con+1<<" ] ";
                }else if(tablero[i][j] == 1)
                {
                    cout<<"[ X ] ";
                }else if(tablero[i][j] == 2)
                {
                    cout<<"[ O ] ";
                }
                con++;
            }
            cout<<"\n";
        }
        
        do
        {
            cout<<"-Que posicion desea Jugador 1?"<<endl;
            cout<<"opcion: ";
            cin>>pos;  
            if(pos>9 || pos<1)
            {
                cout<<"Error"<<endl;
            }
        }while(pos>9 || pos<1);
        
         if(pos<=3)
        {
            pos--;
            if(tablero[0][pos] != 0)
            {
                cout<<"Error"<<endl;
            }else
            {
                tablero[0][pos] = 1;
            }
        }else if(pos<=6)
        {
            pos -= 4;
            if(tablero[1][pos] != 0)
            {
                cout<<"Error"<<endl;
            }else
            {
                tablero[1][pos] = 1;
            }
        }else if(pos<=9)
        {
            pos -= 7;
            if(tablero[2][pos] == 0)
            {
                tablero[2][pos] = 1;
            }
        }
        
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                if(tablero[i][j] == 0)
                {
                    empate = false;
                }
            }
        }

        //  Representacion
        system("cls");
        con = 0;
        for(int i = 0; i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
                if(tablero[i][j] == 0)
                {
                    cout<<"[ "<<con+1<<" ] ";
                }else if(tablero[i][j] == 1)
                {
                    cout<<"[ X ] ";
                }else if(tablero[i][j] == 2)
                {
                    cout<<"[ O ] ";
                }
                con++;
            }
            cout<<"\n";
        }
        /*
            Comprobamos las victorias, si se cumple alguna de las siguientes condiciones, se acabo la partida
            Feature: Optimizar la condicion para desarrollarlo en menos lineas
        */
        if(
	    (tablero[0][0] != 0 && tablero[0][0] == tablero[0][1] && tablero[0][1] == tablero[0][2])||
        (tablero[1][0] != 0 && tablero[1][0] == tablero[1][1] && tablero[1][1] == tablero[1][2])||
        (tablero[2][0] != 0 && tablero[2][0] == tablero[2][1] && tablero[2][1] == tablero[2][2])||
	    (tablero[0][0] != 0 && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])||
        (tablero[0][2] != 0 && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])||
        (tablero[0][0] != 0 && tablero[0][0] == tablero[1][0] && tablero[1][0] == tablero[2][0])||
        (tablero[0][1] != 0 && tablero[0][1] == tablero[1][1] && tablero[1][1] == tablero[2][1])||
        (tablero[0][2] != 0 && tablero[0][2] == tablero[1][2] && tablero[1][2] == tablero[2][2]))
        {
            victoria = true;
        }
        
        // comprobamos empate
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                if(empate && tablero[i][j] == 0)
                {
                    empate = false;
                }
            }
        }
        
        if(empate)
        {
            goto exit;
        }

        if(victoria)
        {
            jugador = false;
            goto exit;
        }
        
        //Intento de control de excepciones
        do
        {
            cout<<"-Que posicion desea Jugador 2?"<<endl;
            cout<<"opcion: ";
            try{
                cin>>pos;
            }catch (runtime_error& e){
                throw e;
            }
            if (pos>9 || pos<1){
                cout<<"Error"<<endl;
            }
        }while(pos>9 || pos<1);
        
        if(pos<=3)
        {
            pos--;
            if(tablero[0][pos] != 0)
            {
                cout<<"Error"<<endl;
            }else
            {
                tablero[0][pos] = 2;
            }
        }else if(pos<=6)
        {
            pos -= 4;
            if(tablero[1][pos] != 0)
            {
                cout<<"Error"<<endl;
            }else
            {
                tablero[1][pos] = 2;
            }
        }else if(pos<=9)
        {
            pos -= 7;
            if(tablero[2][pos] != 0)
            {
                cout<<"Error"<<endl;
            }else
            {
                tablero[2][pos] = 2;
            }
        }

        /*
            Comprobamos las victorias, si se cumple alguna de las siguientes condiciones, se acabo la partida
        */
       if(
	    (tablero[0][0] != 0 && tablero[0][0] == tablero[0][1] && tablero[0][1] == tablero[0][2])||
        (tablero[1][0] != 0 && tablero[1][0] == tablero[1][1] && tablero[1][1] == tablero[1][2])||
        (tablero[2][0] != 0 && tablero[2][0] == tablero[2][1] && tablero[2][1] == tablero[2][2])||
        (tablero[0][0] != 0 && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])||
        (tablero[0][2] != 0 && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0])||
        (tablero[0][0] != 0 && tablero[0][0] == tablero[1][0] && tablero[1][0] == tablero[2][0])||
        (tablero[0][1] != 0 && tablero[0][1] == tablero[1][1] && tablero[1][1] == tablero[2][1])||
        (tablero[0][2] != 0 && tablero[0][2] == tablero[1][2] && tablero[1][2] == tablero[2][2]))
        {
            victoria = true;
        }

        // comprobamos empate
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                if(empate && tablero[i][j] == 0)
                {
                    empate = false;
                }
            }
        }
        
        if(empate)
        {
            goto exit;
        }

    }while(!victoria);

    //Salida, usada para el caso de la victoria del primer jugador, si no se usa pedira al segundo jugador la posicion aunque ya haya ganado
    exit:
    unsigned con = 0;
    system("cls");

    if(jugador && !empate)     //Caso de que gane el jugador 2
    {
        for(int i = 0; i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
                if(tablero[i][j] == 0)
                {
                    cout<<"[ "<<" "<<" ] ";
                }else if(tablero[i][j] == 1)
                {
                    cout<<"[   ] ";
                }else if(tablero[i][j] == 2)
                {
                    cout<<"[ O ] ";
                }
                con++;
            }
            cout<<"\n";
        }
    }else if(!jugador && !empate)
    {
        for(int i = 0; i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
                if(tablero[i][j] == 0)
                {
                    cout<<"[   ] ";
                }else if(tablero[i][j] == 1)
                {
                    cout<<"[ X ] ";
                }else if(tablero[i][j] == 2)
                {
                    cout<<"[   ] ";
                }
                con++;
            }
            cout<<"\n";
        }
    }else
    {
        for(int i = 0; i<3;i++)
        {
            for(int j = 0; j<3;j++)
            {
                if(tablero[i][j] == 1)
                {
                    cout<<"[ X ] ";
                }else if(tablero[i][j] == 2)
                {
                    cout<<"[ O ] ";
                }
                con++;
            }
            cout<<"\n";
        }
    }
    
    cout<<"Fin del Juego"<<endl;
    system("pause");
    return 0;
}