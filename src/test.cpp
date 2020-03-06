#include <iostream>
#include <vector>

#include "cell_t.cpp"
#include "board_t.cpp"

int main(void) {
    int n_, m_;
    
    std::cout << "n: ";
    std::cin >> n_;
    std::cout << "\n";
    std::cout << "m: ";
    std::cin >> m_;

    board_t cells(n_, m_);

    cells.at(0,1).set_state(1);
    cells.write(std::cout);

    return 0;
}
