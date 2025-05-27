#include "MyStack1.h" 

bool checking(int i, int j, int size, int** maze, int** checked) {
    return i >= 0 && j >= 0 && i < size && j < size && maze[i][j] == 1 && checked[i][j] == 0;
}

void RatMaze(int** maze, int size) {
    MyStack obj1(size * size); 

    int** checked = new int* [size];
    int** solution = new int* [size];

    for (int i = 0; i < size; i++) {
        checked[i] = new int[size];
        solution[i] = new int[size];
        for (int j = 0; j < size; j++) {
            checked[i][j] = 0;  
            solution[i][j] = 0;  
        }
    }

    ofstream fout("output.txt");
    if (maze[0][0] == 0 || maze[size - 1][size - 1] == 0) {
        fout << "PATH NOT FOUND!" << endl;
        fout.close();

        for (int i = 0; i < size; i++) {
            delete[] checked[i];
            delete[] solution[i];
        }
        delete[] checked;
        delete[] solution;
        return;
    }

    obj1.push(0, 0); 
    checked[0][0] = 1;
    bool pathFound = false;

    while (!obj1.isEmpty()) {
        int i, j;
        obj1.pop(i, j);
        solution[i][j] = 1;

        if (i == size - 1 && j == size - 1) { 
            pathFound = true;
            break;
        }

        if (checking(i + 1, j, size, maze, checked)) {
            obj1.push(i, j);
            obj1.push(i + 1, j);
            checked[i + 1][j] = 1;
            continue;
        }

        if (checking(i, j + 1, size, maze, checked)) {
            obj1.push(i, j);
            obj1.push(i, j + 1);
            checked[i][j + 1] = 1;
            continue;
        }

        if (checking(i - 1, j, size, maze, checked)) {
            obj1.push(i, j);
            obj1.push(i - 1, j);
            checked[i - 1][j] = 1;
            continue;
        }

        if (checking(i, j - 1, size, maze, checked)) {
            obj1.push(i, j);
            obj1.push(i, j - 1);
            checked[i][j - 1] = 1;
            continue;
        }
        solution[i][j] = 0;
    }

    if (pathFound) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                fout << solution[i][j] << " ";
            }
            fout << endl;
        }
    }
    else {
        fout << "PATH NOT FOUND!" << endl;
    }

    fout.close();

    for (int i = 0; i < size; i++) {
        delete[] checked[i];
        delete[] solution[i];
    }
    delete[] checked;
    delete[] solution;
}

int main() {
    ifstream fin("input.txt");
    if (!fin.is_open()) {
        cout << "File not found" << endl;
        return 1;
    }

    int size;
    fin >> size;

    int** maze = new int* [size];
    for (int i = 0; i < size; i++) {
        maze[i] = new int[size];
        for (int j = 0; j < size; j++) {
            fin >> maze[i][j];
        }
    }
    fin.close();

    RatMaze(maze, size);

    for (int i = 0; i < size; i++) {
        delete[] maze[i];
    }
    delete[] maze;

    return 0;
}
