////////////////////////
// INCLUDES
////////////////////////

#include <iostream>
#include <string>

////////////////////////
// EASY FUNCTIONS
////////////////////////

std::string input(std::string prompt) {
    std::string response;
    std::cout << prompt;
    std::cin >> response;
    return response;
}

int intput(std::string prompt) {
    std::string response;
    std::cout << prompt;
    std::cin >> response; 
    int num = stoi(response);
    return num;
}

////////////////////////
// GRID
////////////////////////

class new_grid {
public:
    std::string matrix[3][3] = {
        {"   ","   ","   "},
        {"   ","   ","   "},
        {"   ","   ","   "},
    };
    void render(std::string mode) {
        if (mode == "none") {
            std::cout << "            \n";
            for (int row = 0; row < 3; row++) {
                std::cout << " ";
                for (int col = 0; col < 3; col++) {
                    std::cout << matrix[row][col];
                    if (col != 2) {
                        std::cout << "|";
                    }
                };
                std::cout << "\n";
                if (row != 2) {
                    std::cout << " ---+---+--- \n";
                };
            };
        };
        if (mode == "row") {
            std::cout << "            \n";
            for (int row = 0; row < 3; row++) {
                std::cout << row + 1;
                for (int col = 0; col < 3; col++) {
                    std::cout << matrix[row][col];
                    if (col != 2) {
                        std::cout << "|";
                    }
                };
                std::cout << "\n";
                if (row != 2) {
                    std::cout << " ---+---+--- \n";
                };
            };
        }
        if (mode == "col") {
            std::cout << " 1   2   3  \n";
            for (int row = 0; row < 3; row++) {
                std::cout << " ";
                for (int col = 0; col < 3; col++) {
                    std::cout << matrix[row][col];
                    if (col != 2) {
                        std::cout << "|";
                    }
                };
                std::cout << "\n";
                if (row != 2) {
                    std::cout << " ---+---+--- \n";
                };
            };
        }
    };
};

new_grid grid;

////////////////////////
// CHECK WIN
////////////////////////

bool win(std::string turn) {

    std::cout << "called win() \n";

    // HORIZONTAL

    int count = 0;

    for (int row = 0; row < 3; row++) {
        count = 0;
        for (int col = 0; col < 3; col++) {
            if (grid.matrix[row][col] == turn) {
                count += 1;
            }
        }
    }
    if (count == 3) {
        return true;
    }
    if (count < 3) {
        return false;
    }

    for (int row = 0; row < 3; row++) {
        count = 0;
        for (int col = 0; col < 3; col++) {
            if (grid.matrix[row][col] == turn) {
                count += 1;
            }
        }
    }
}

////////////////////////
// GAME
////////////////////////

std::string turn = "X";

void switch_turn() {
    if (turn == "X") {
        turn = "O";
    }
    else {
        turn = "X";
    }
}

////////////////////////
// SCENES PROTOTYPES
////////////////////////

void main_menu();
void game();
void game_end();

////////////////////////
// SCENES
////////////////////////

void game_end(std::string winner) {
    system("cls");
    std::cout << "+-----------+ \n";
    std::cout << "| " << winner << " Wins!   | \n";
    std::cout << "+-----------+ \n";
    std::cout << "| 1) Re-Play| \n";
    std::cout << "| 2) Menu   | \n";
    std::cout << "+-----------+ \n";
    system("pause");
    main_menu();
}

void game() {
    system("cls");
    std::cout << turn + "'s Turn \n";
    grid.render("row");
    int row = intput("$row>");
    system("cls");
    std::cout << turn + "'s Turn \n";
    grid.render("col");
    int col = intput("$col>");
    if (grid.matrix[row - 1][col - 1] == "   ") {
        grid.matrix[row - 1][col - 1] = " " + turn + " ";
        if (win(" " + turn + " ")) {
            game_end(turn);
        }
        switch_turn();
    }
    game();
}

void main_menu() {
    system("cls");
    std::cout << "+-----------+ \n";
    std::cout << "| Main Menu | NEW VERSION \n";
    std::cout << "+-----------+ \n";
    std::cout << "| 1) Play   | \n";
    std::cout << "| 2) Exit   | \n";
    std::cout << "+-----------+ \n";
    std::string choice = input("$choice>");
    if (choice == "1") {
        game();
    };
    main_menu();
}

////////////////////////
// MAIN
////////////////////////

int main() {
    main_menu();
    system("pause");
}