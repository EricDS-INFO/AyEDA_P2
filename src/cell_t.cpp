// [cell_t.cpp]
//
// AUTOR: Eric Dürr Sierra.
// DATE:  February 2020
// 
// SUBJECT: AyEDA (Algoritmos y Estructuras de Datos Avanzadas)
//
// Ingeniería informática - ESIT ULL 
// (Escuela Superior de Ingeniería y Tecnología - Universidad de La Laguna)
//
// DESCRIPTION:
/*
    This file contains all the methods development from the cell class.
*/


#include "../include/cell_t.hpp"
#include "../include/board_t.hpp"

#include <iostream>


int cell_t::get_state(void) const 
{
    return alive_;
}
int cell_t::get_next(void) 
{
    return next_;
}


int cell_t::set_state(int state) 
{
    alive_ = state;
}

void cell_t::set_next(int next) 
{
    next_ = next;
}



int cell_t::get_i_pos(void)
{
    return i_;
}

void cell_t::set_i_pos(int i)
{
    i_ = i;
}

int cell_t::get_j_pos(void)
{
    return j_;
}

void cell_t::set_j_pos(int j)
{
    j_ = j;
}

std::ostream& cell_t::write( std::ostream& os) 
{
    if (alive_) os << "x";
    else        os << " ";

    return os;
}

std::ostream& operator<<(std::ostream& os, cell_t& cell)
{
    cell.write(os);

    return os;
}



int cell_t::count_neighbours(board_t& board)
{
    int neighbours = 0;
    for (int i = 0; i < board.get_n(); i++)
        for (int j = 0; i < board.get_m(); j++)
        {
            // Check the basic axis
            /* LEFT */
            if (board.at(i - 1, j).get_state())         neighbours++;
            /* RIGHT */
            if (board.at(i + 1, j).get_state())         neighbours++;
            /* UP */
            if (board.at(i, j - 1).get_state())         neighbours++;
            /* DOWN */
            if (board.at(i, j + 1).get_state())         neighbours++;

            //check the diagonal axis:

            /*1st square*/
            if (board.at(i - 1, j - 1).get_state())     neighbours++;
            /*2nd square*/
            if (board.at(i + 1, j - 1).get_state())     neighbours++;
            /*3rd square*/
            if (board.at(i - 1, j + 1).get_state())     neighbours++;
            /*4th square*/
            if (board.at(i + 1, j + 1).get_state())     neighbours++;
           


        }


    return neighbours;
}


