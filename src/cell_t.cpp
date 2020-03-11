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
#define INFINITE 1

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
    return alive_;
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


int cell_t::updateState(void)
{
    if ( alive_ == 1 )
    {
        if (alive_neighbours_ != 2 &&
            alive_neighbours_ != 3 )
            alive_ = 0;
        else
            alive_ = 1;
    }
    
    if ( alive_ == 0 )
    {
        if (alive_neighbours_ == 3)
            alive_ = 1;
        else
            alive_ = 0;
    }

    return alive_;   
}


int cell_t::count_neighbours(const board_t& board)
{
    int neighbours = 0;
    
    if (!INFINITE)
    {
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
    }
    if (INFINITE)
    {
        int n = board.get_n();
        int m = board.get_m();
        // Check the basic axis
        /* LEFT */
        if (board.at(left(i_, n), j_).get_state() == 1)         neighbours++;
        /* RIGHT */
        if (board.at(right(i_, n), j_).get_state() == 1)         neighbours++;
        /* UP */
        if (board.at(i_, up(j_, m)).get_state() == 1)         neighbours++;
        /* DOWN */
        if (board.at(i_, down(j_, m)).get_state() == 1)         neighbours++;

        //check the diagonal axis:
        /*1st square*/
        if (board.at(left(i_, n), up(j_, m)).get_state() == 1)     neighbours++;
        /*2nd square*/
        if (board.at(right(i_, n), up(j_, m)).get_state() == 1)     neighbours++;
        /*3rd square*/
        if (board.at(left(i_, n), down(j_, m)).get_state() == 1)     neighbours++;
        /*4th square*/
        if (board.at(right(i_, n), down(j_, m)).get_state() == 1)     neighbours++;   
       
    }
        
    alive_neighbours_ = neighbours;

    return neighbours;
}




// this function captures the left cell values
int cell_t::left(int pos, int n)
{
    if (pos == 0 ) 
        pos = n - 1; 
    else 
        pos--;
 return pos;
}


// this function captures the right cell values
int cell_t::right(int pos, int n)
{
    if (pos == n - 1 ) 
        pos = 0; 
    else 
        pos++;
 return pos;
}

// this function captures the up cell values
int cell_t::up(int pos, int m)
{
    if (pos == 0 ) //if actual position is 0 in y axis in matrix, we get the greater number
        pos = m - 1; 
    else 
        pos--;     // we decrease one position in y axis.
 return pos;
}

// this function captures the down cell values
int cell_t::down(int pos, int m)
{
    if (pos == m - 1 ) 
        pos = 0; 
    else 
        pos++;
 return pos;
}