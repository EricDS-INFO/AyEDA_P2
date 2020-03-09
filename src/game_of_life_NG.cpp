#include <iostream>
#include <vector>


#include "../include/cell_t.hpp"
#include "../include/board_t.hpp"

void write_pattern(int n, int m);

void create_osc(int n, int m, board_t& cells);
void create_ship(int n, int m, board_t& cells);

void select_1by1(int n, int m, board_t& cells);


int main(void) {
    int n, m, it;


    std::cout << "INTRODUZCA LAS DIMENSIONES DEL TABLERO: \n";
    std::cout << "filas: ";
    std::cin >> n;
    std::cout << "\n";
    std::cout << "columnas: ";
    std::cin >> m;
    std::cout << "\nINTRODUZCA AHORA EL NÚMERO DE TURNOS: ";
    std::cin >> it;
    std::cout << "\n\n\n";

    board_t cells(n, m);

    int opt = 5;
        std::cout << "SELECCIONE UNA OPCIÓN DE INICIO: " << std::endl;
        std::cout << "Seleccionar oscilador de 3 células     --> introducir 1 \n";
        std::cout << "Seleccionar planeador pequeño          --> introducir 2 \n";
        std::cout << "Seleccionar manualmente las posiciones --> introducir 3 \n";
        std::cout << "--------------------------------------------------------\n";
        std::cout << "salir                                  --> introducir 0 \n\n";
        std::cout << "Introduzca una opción: ";
        std::cin >> opt;

        switch (opt)
        {
            case 1:

                create_osc(n,m, cells);
                break;

            case 2:

                break;

            case 3:

                std::cout << "SELECCIONE LAS POSICIONES DEL TABLERO DONDE HAY UNA CÉLULA VIVA: \n";
                select_1by1(n, m, cells);
                break;

            case 0:
                cells.~board_t();
                return 0;
                break;

            default:
                break;
        }
    


    std::cout << "Turno 0: \n";
    cells.write(std::cout);

    for (int i = 0; i < it; i++) 
    {

        for (int i = 1 ; i < n + 1; i++)
        {
            for (int j = 1 ; j < m + 1; j++)
            {
                cells.at(i,j).count_neighbours(cells);
            }
        }
        
        for (int i = 1 ; i < n + 1; i++)
        {
            for (int j = 1 ; j < m + 1; j++)
            {
                cells.at(i,j).updateState();
            }
        }


        std::cout << "Turno" << it <<  ": \n";
        cells.write(std::cout);        
    }


    


    cells.~board_t();
    return 0;
}


void write_pattern(int n, int m)
{
    std::cout << "Este es el patrón que sigue el tablero: \n";

    std::cout << "\n╔";
    for (int i = 0; i < m; i++)
        std::cout << "════════";
    std::cout << "╗\n\n";
    for  (int i = 0; i < n; i++ ) 
    {

        std::cout << "║";
        for (int j = 0; j < m; j++ )
        {
            std::cout << " " 
            << "[" << i << "][" <<  j << "]"
            << " ";
        }
        std::cout << "║\n\n";
    }
        std::cout << "╚";
    for (int i = 0; i < m; i++)
        std::cout << "════════";

    std::cout << "╝\n\n";


}



void create_osc(int n, int m, board_t& cells)
{

    if(((n + m) % 2) == 1)
    {
        cells.at(n/2 + 20, m/2 ).set_state(1);
        cells.at(n/2 + 20, m/2 + 1).set_state(1);
        cells.at(n/2 + 20, m/2 + 2).set_state(1);
    } 
    if (((n + m) % 2) == 0)
    {
        cells.at(n/2 + 1 , m/2  ).set_state(1);
        cells.at(n/2 + 1 , m/2 + 1).set_state(1);
        cells.at(n/2 + 1 , m/2 + 2 ).set_state(1);
    }
}
void create_ship(int n, int m, board_t& cells);

void select_1by1(int n, int m, board_t& cells)
{

    write_pattern(n ,m);   

    std::cout << "Pulse 1 para indicar que está viva y enter para no hacer nada\n\n";
    
    for (int i = 1 ; i < n + 1; i++)
    {
        for (int j = 1 ; j < m + 1; j++)
        {
            int op = 0;
            std::cout << "Célula" 
            << "[" << i - 1 << "][" <<  j - 1 << "]: ";
            std::cin >> op; 
            if (op == 1 || op == 0)
                cells.at(i, j).set_state(op);
        }
    }
} 

