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

bool cell_t::get_state(void) 
{
    return alive_;
}
int cell_t::get_next(void) 
{
    return next_;
}


void cell_t::set_state(bool state) 
{
    alive_ = state;
}

void cell_t::set_next(int next) 
{
    next_ = next;
}
