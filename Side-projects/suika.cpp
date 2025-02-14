#include <iostream>
#include <vector>
#include <random>
#include <ctime>

const int WIDTH = 10;
const int HEIGHT = 15;

class Fruit {
public:
    int size;
    int x;

    Fruit(int s, int posX) : size(s), x(posX) {}
};

class Game {
private:
    std::vector<std::vector<int>> board;
    std::vector<Fruit> fruits;
    std::mt19937 rng;

public:
    Game() : board(HEIGHT, std::vector<int>(WIDTH, 0)), rng(std::time(0)) {
        fruits.reserve(HEIGHT * WIDTH);
    }

    void spawnFruit() {
        int size = std::uniform_int_distribution<>(1, 3)(rng);
        int x = std::uniform_int_distribution<>(0, WIDTH - 1)(rng);
        fruits.emplace_back(size, x);
    }

    void moveFruit() {
        if (fruits.empty()) return;

        Fruit& fruit = fruits.back();
        int y = 0;

        while (y < HEIGHT - 1 && board[y + 1][fruit.x] == 0) {
            y++;
        }

        board[y][fruit.x] = fruit.size;
        fruits.pop_back();

        mergeFruits(fruit.x, y);
    }

    void mergeFruits(int x, int y) {
        if (y > 0 && board[y][x] == board[y - 1][x]) {
            board[y][x]++;
            board[y - 1][x] = 0;
            mergeFruits(x, y - 1);
        }
    }

    void display() {
        std::cout << std::string(WIDTH + 2, '-') << std::endl;
        for (const auto& row : board) {
            std::cout << '|';
            for (int cell : row) {
                std::cout << (cell == 0 ? ' ' : static_cast<char>('0' + cell));
            }
            std::cout << '|' << std::endl;
        }
        std::cout << std::string(WIDTH + 2, '-') << std::endl;
    }

    bool isGameOver() {
        for (int i = 0; i < WIDTH; i++) {
            if (board[0][i] != 0) return true;
        }
        return false;
    }

    void play() {
        while (!isGameOver()) {
            spawnFruit();
            display();

            std::cout << "Move left (-1), right (1), or drop (0): ";
            int move;
            std::cin >> move;

            if (move != 0) {
                fruits.back().x = std::max(0, std::min(WIDTH - 1, fruits.back().x + move));
            }

            moveFruit();
        }
        std::cout << "Game Over!" << std::endl;
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}