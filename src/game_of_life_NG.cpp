#include <iostream>
#include <vector>


#include "../include/cell_t.hpp"
#include "../include/board_t.hpp"

void write_pattern(int n, int m);
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



    std::cout << "SELECCIONE LAS POSICIONES DEL TABLERO DONDE HAY UNA CÉLULA VIVA: \n";

    select_1by1(n, m, cells);

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