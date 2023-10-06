#include <iostream>

class new_grid {
public:
    std::string matrix[3][3] = {
        {" X ","   "," O "},
        {"   "," X ","   "},
        {" O ","   "," X "},
    };
    void render() {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                std::cout << matrix[row][col];
                if (col != 2) {
                    std::cout << "|";
                }
            };
            std::cout << "\n";
            if (row != 2) {
                std::cout << "---+---+--- \n";
            };
        };
    };
};

new_grid grid;

int main() {
    grid.render();
}