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


// Private methods

int cell_t::right(int pos)
{
    if (pos == X - 1 ) 
        pos = 0; 
    else 
        pos++;
    return pos;
}    

int cell_t::left(int pos)
{
    if (pos == 0 ) 
        pos = X - 1; 
    else 
        pos--;
    return pos;
}

int cell_t::up(int pos)
{
    if (pos == 0 ) 
        pos = Y - 1; 
    else 
        pos--;   
    return pos;
}

int cell_t::down(int pos)
{
    if (pos ==  Y - 1 ) 
        pos = 0; 
    else 
        pos++;   
    return pos;
} 
