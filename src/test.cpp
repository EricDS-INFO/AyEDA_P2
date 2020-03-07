#include <iostream>
#include <vector>


#include "../include/cell_t.hpp"
#include "../include/board_t.hpp"


int main(void) {
    int n_, m_;
    
    std::cout << "n: ";
    std::cin >> n_;
    std::cout << "\n";
    std::cout << "m: ";
    std::cin >> m_;

    board_t cells(n_, m_);

    cells.at(0,0).set_state(1);
    cells.write(std::cout);

    //std::cout 
    //<< cells.at(1,1).count_neighbours(cells)
    //<< "\n";
    //std::cout 
    //<< cells.at(1,2).count_neighbours(cells)
    //<< "\n";
        
    return 0;
}
