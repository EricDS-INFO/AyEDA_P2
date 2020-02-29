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

board_t::board_t(int n = 300, int m = 300)
{
    n_dim_ = n;
    m_dim_ = m;

    /*dynamic matrix of cells is created*/
    cell_grid_ = new cell_t *[n_dim_];
    for (int i = 0; i < n_dim_; i++) {
        cell_grid_[i] = new cell_t[m_dim_];
        
    }

    /*this sets the default state of the cells as dead*/
    for (int i = 0; i < n_dim_; i++)  
        for (int j = 0; j < m_dim_; j++ )
        {
            cell_grid_[i][j].set_state(false);
            cell_grid_[i][j].set_next(false);
            cell_grid_[i][j].set_i_pos(i);
            cell_grid_[i][j].set_j_pos(j);
        }
}


cell_t& board_t::get_at(int i, int j)
{
    return cell_grid_[i][j];
}

void board_t::set_at(int i, int j, bool state)
{
    cell_grid_[i][j].set_state(state);
}

std::ostream& board_t::write(std::ostream& os)
{
    os << "\n╔";
    for (int i = 0; i < m_dim_*3; i++)
        os << "═";
    os << "╗\n";
    for (int i = 0; i < n_dim_; i++)  
    {
        os << "║";
        for (int j = 0; j < m_dim_; j++ )
        {
            os << " " << cell_grid_[i][j] << " ";       
        }
        os << "║\n";
    }
    os << "╚";
    for (int i = 0; i < m_dim_*3; i++)
        os << "═";
    os << "╝\n";

    return os;
}