// [cell_t.hpp]
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
    This file contains the Cell class definition.
*/
#pragma once
#include <iostream>
//#include "board_t.hpp"

class cell_t
{
private:
    bool alive_;
    bool next_;
    int i_, j_;

public:
    cell_t(void):
    alive_(false), 
    next_(false){};
    ~cell_t(void){};

    bool get_state(void);
    int get_next(void);

    void set_state(bool state);
    void set_next(int next);

    int get_i_pos(void);
    void set_i_pos(int i);

    int get_j_pos(void);
    void set_j_pos(int j);

    // int updateState(void);
    // int neighbours(const board_t& board);

    std::ostream& write( std::ostream& os);

    friend std::ostream& operator<< (std::ostream& os, cell_t& cell);
};
