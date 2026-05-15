#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 5;
const int MINES = 6;

struct Cell {
    bool isMine = false;
    bool isRevealed = false;
    int neighboringMines = 0;
};

vector<vector<Cell>> board(SIZE, vector<Cell>(SIZE));

bool inBounds(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

void calculateMines() {
    int dx[] = { -1,-1,-1,0,1,1,1,0 };
    int dy[] = { -1,0,1,1,1,0,-1,-1 };

    for (int x = 0; x < SIZE; x++) {
        for (int y = 0; y < SIZE; y++) {
            if (board[x][y].isMine) continue;

            int count = 0;
            for (int d = 0; d < 8; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (inBounds(nx, ny) && board[nx][ny].isMine)
                    count++;
            }
            board[x][y].neighboringMines = count;
        }
    }
}

void placeMines(int avoidX, int avoidY) {
    srand(time(NULL));

    int placed = 0;

    while (placed < MINES) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        // Do not place mines around the first clicked cell
        if (!board[x][y].isMine &&
            !(abs(x - avoidX) <= 1 && abs(y - avoidY) <= 1)) {

            board[x][y].isMine = true;
            placed++;
        }
    }

    calculateMines();
}

void reveal(int x, int y) {
    if (!inBounds(x, y)) return;
    if (board[x][y].isRevealed) return;
    if (board[x][y].isMine) return;

    queue<pair<int, int>> q;
    q.push({ x, y });

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        if (!inBounds(cx, cy)) continue;
        if (board[cx][cy].isRevealed) continue;
        if (board[cx][cy].isMine) continue;

        board[cx][cy].isRevealed = true;

        if (board[cx][cy].neighboringMines != 0)
            continue;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) continue;
                q.push({ cx + dx, cy + dy });
            }
        }
    }
}

void printBoard() {
    cout << "  ";
    for (int i = 0; i < SIZE; i++) cout << i << " ";
    cout << "\n";

    for (int i = 0; i < SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j].isRevealed)
                cout << "# ";
            else if (board[i][j].isMine)
                cout << "* ";
            else
                cout << board[i][j].neighboringMines << " ";
        }
        cout << "\n";
    }
}

bool isWin() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j].isMine && !board[i][j].isRevealed)
                return false;
        }
    }
    return true;
}

void play() {
    bool firstMove = true;

    while (true) {
        printBoard();

        int x, y;
        cout << "Enter coordinates (x y): ";
        cin >> x >> y;

        if (!inBounds(x, y)) {
            cout << "Out of range. Try again.\n";
            continue;
        }

        if (firstMove) {
            placeMines(x, y);
            reveal(x, y);
            firstMove = false;
            continue;
        }

        if (board[x][y].isMine) {
            board[x][y].isRevealed = true;
            printBoard();
            cout << "You hit a mine. Game over.\n";
            break;
        }

        reveal(x, y);

        if (isWin()) {
            printBoard();
            cout << "You win!\n";
            break;
        }
    }
}

int main() {
    cout << "Minesweeper started!\n";
    play();
    return 0;
}
