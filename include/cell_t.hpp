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
#ifndef CELL_H
#define CELL_H


#include <iostream>
class board_t;
class cell_t
{
    private:
        bool alive_;
        bool next_;
        
        int i_, j_;

        int alive_neighbours_;

        int n_, m_;

    public:
        cell_t(void):
        alive_(false), 
        next_(false){};
        ~cell_t(void){};

        int get_state(void) const;
        int get_next(void);

        int set_state(int state);
        void set_next(int next);

        int get_i_pos(void);
        void set_i_pos(int i);

        int get_j_pos(void);
        void set_j_pos(int j);

        // int updateState(void);
        int count_neighbours(board_t& board);

        std::ostream& write( std::ostream& os);
        friend std::ostream& operator<< (std::ostream& os, cell_t& cell);

    private:
        //int left (int pos);
        //int righ (int pos);
        //int up (int pos);
        //int down (int pos);
};
#endif
