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
        int n_, m_;

        int alive_neighbours_;

        

    public:
        cell_t():
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

        int updateState(void);
        int count_neighbours(const board_t& board);

        std::ostream& write( std::ostream& os);
        friend std::ostream& operator<< (std::ostream& os, cell_t& cell);

    private:
        int left(int pos, int n);
        int right(int pos, int n);
        int up(int pos, int m);
        int down(int pos, int m);
};
#endif
