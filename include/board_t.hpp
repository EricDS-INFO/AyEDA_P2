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

#include <iostream>
#include <vector>

#include "cell_t.hpp"

class board_t
{
private:
    int n_dim_;
    int m_dim_;
    cell_t** cell_grid_;
public:
      board_t(int n, int m);
     // ~board_t();
      
      cell_t& get_at(int i, int j);
      void set_at(int i, int j, bool state);

      std::ostream& write(std::ostream& os);

};
