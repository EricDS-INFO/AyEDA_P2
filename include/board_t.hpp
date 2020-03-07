// [board_t.hpp]
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
    This file contains the Board class definition.
*/

#ifndef BOARD_H
#define BOARD_H

#include <iostream>


class cell_t;
class board_t
{
private:
    int n_dim_;
    int m_dim_;
    cell_t** cell_grid_;
public:
      board_t(int n, int m);
     // ~board_t();
      
      inline  int get_n() const { return n_dim_ - 1; }

      inline  int get_m() const { return m_dim_ - 1; }

      cell_t& at(const int i, const int j) const;
      cell_t& at(const int i, const int j);

      std::ostream& write(std::ostream& os);

};
#endif