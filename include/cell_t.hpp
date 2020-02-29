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



class cell_t
{
private:
    bool alive_;
    int next_;
public:
   // cell_t(/* args */);
   // ~cell_t();

    bool get_state();
    int get_next();

    void set_state(bool state);
    void set_next(int next);
};
