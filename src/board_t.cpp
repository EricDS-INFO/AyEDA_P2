// [board_t.cpp]
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
    This file contains all the methods development from the board class.
*/

#include "../include/board_t.hpp"
#include "../include/cell_t.hpp"

#include <iostream>

board_t::board_t(int n = 300, int m = 300)
{
    dimensions_.first = n + 2;
    dimensions_.second = m + 2;
    /*dynamic matrix of cells is created*/
    cell_grid_ = new cell_t *[dimensions_.first];
    
    for (int i = 0; i < dimensions_.first; i++) {
        cell_grid_[i] = new cell_t[dimensions_.second];
        
    }

    /*this sets the default state of the cells as dead*/
    for (int i = 0; i < dimensions_.first ; i++)  
        for (int j = 0; j < dimensions_.second; j++ )
        {
            cell_grid_[i][j].set_state(false);
            cell_grid_[i][j].set_next(false);
            cell_grid_[i][j].set_i_pos(i);
            cell_grid_[i][j].set_j_pos(j);
        }
}

board_t::board_t(int n = 300, int m = 300, int cell_size = 5)
{
    dimensions_.first = n + 2;
    dimensions_.second = m + 2;
    cell_size_ = cell_size;
    /*dynamic matrix of cells is created*/
    cell_grid_ = new cell_t *[dimensions_.first];
    
    for (int i = 0; i < dimensions_.first; i++) {
        cell_grid_[i] = new cell_t[dimensions_.second];
        
    }

    /*this sets the default state of the cells as dead*/
    for (int i = 0; i < dimensions_.first ; i++)  
        for (int j = 0; j < dimensions_.second; j++ )
        {
            cell_grid_[i][j].set_state(false);
            cell_grid_[i][j].set_next(false);
            cell_grid_[i][j].set_i_pos(i);
            cell_grid_[i][j].set_j_pos(j);
        }
}

board_t::~board_t()
{    
    for (int i = 0; i < dimensions_.first ; i++) 
    {
        delete[] cell_grid_[i];
    }

    dimensions_.first = 0;
    dimensions_.second = 0;

        
    delete[] cell_grid_;

}

cell_t& board_t::at(const int i, const int j ) const
{
   return cell_grid_[i][j];
}

cell_t& board_t::at(const int i, const int j)
{
   return cell_grid_[i][j];
}

std::ostream& board_t::write(std::ostream& os)
{
    os << "\n╔";
    for (int i = 1; i < (dimensions_.second - 1); i++)
        os << "═══";
    os << "╗\n";
    for (int i = 1; i < dimensions_.first - 1; i++)  
    {
        os << "║";
        for (int j = 1; j < dimensions_.second - 1; j++ )
        {
            os << " " << cell_grid_[i][j] << " ";       
        }
        os << "║\n";
    }
    os << "╚";
    for (int i = 1; i < (dimensions_.second - 1 ); i++)
        os << "═══";
    os << "╝\n";

    return os;
}

cell_t& board_t::operator[](std::pair<int,int>& index) 
{
    return cell_grid_[index.first][index.second];
}