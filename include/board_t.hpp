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
    std::pair<int,int> dimensions_;
    int cell_size_;
    cell_t** cell_grid_;
public:

    board_t(int n, int m);
    board_t(int n, int m, int cell_size);
    ~board_t();
      
    inline  int get_n() const { return dimensions_.first ; }
    inline  int get_m() const { return dimensions_.second ; }
    inline  int  size() const { return cell_size_; } 
    

    cell_t& at(int i, int j) const;
    cell_t& at(int i,  int j);

    //cell_t& const operator[](int i ) const;

    cell_t& operator[](std::pair<int,int>& index);
    std::ostream& write(std::ostream& os);

};
#endif