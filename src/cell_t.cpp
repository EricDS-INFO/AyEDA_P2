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



int cell_t::count_neighbours(const board_t& board)
{
    int neighbours = 0;
    // Check the basic axis
    /* LEFT */
    if (board.at(i_ - 1, j_).get_state() == 1)         neighbours++;
    /* RIGHT */
    if (board.at(i_ + 1, j_).get_state() == 1)         neighbours++;
    /* UP */
    if (board.at(i_, j_ - 1).get_state() == 1)         neighbours++;
    /* DOWN */
    if (board.at(i_, j_ + 1).get_state() == 1)         neighbours++;
    
    //check the diagonal axis:
    /*1st square*/
    if (board.at(i_ - 1, j_ - 1).get_state() == 1)     neighbours++;
    /*2nd square*/
    if (board.at(i_ + 1, j_ - 1).get_state() == 1)     neighbours++;
    /*3rd square*/
    if (board.at(i_ - 1, j_ + 1).get_state() == 1)     neighbours++;
    /*4th square*/
    if (board.at(i_ + 1, j_ + 1).get_state() == 1)     neighbours++;
            

    return neighbours;
}


