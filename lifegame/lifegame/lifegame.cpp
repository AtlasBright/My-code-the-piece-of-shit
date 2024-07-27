#include <fstream>
#include <iostream>
#include <windows.h>

char** create_pf(int size_ro, int size_col) {
    char** pf = new char* [size_ro];
    for (int i = 0; i < size_ro; i++) {
        pf[i] = new char[size_col];
    }
    return pf;
}

void fill_pf(char** pf, int size_ro, int size_col) {
    for (int i = 0; i < size_ro; i++) {
        for (int j = 0; j < size_col; j++) {
            pf[i][j] = 45;
        }
    }

}

void fill_copy(char** pf, char** pf2, int size_ro, int size_col) {
        for (int i = 0; i < size_ro; i++) {
            for (int j = 0; j < size_col; j++) {
                pf2[i][j] = pf[i][j];


            }

        }

  
}

void cell_in(char** pf, int size_ro, int size_col, int cell_r, int cell_c) {
    for (int i = 0; i < size_ro; i++) {
        for (int j = 0; j < size_col; j++) {
            if (i == cell_r && j == cell_c) {
                pf[i][j] = 42;
            }
        }
    }
}

void neighbour_cell(char** pf,char** pf2, int size_ro, int size_col, int cell_r, int cell_c) {
    int life_count = 0;
    for (int i = cell_r - 1; i <= cell_r + 1; i++) {
        if (i < 0 || i >= size_ro) {
            continue;
        }
        for (int j = cell_c - 1; j <= cell_c + 1; j++) {
            if (j < 0 || j >= size_col) {
                continue;
            }
            if (i == cell_r && j == cell_c) {
                continue;
            }
            if (pf2[i][j] == 42) {
                ++life_count;
            }

        }
    }
    if (pf[cell_r][cell_c] == 42 && life_count < 2 || life_count > 3) {
        pf[cell_r][cell_c] = 45;
    }
    if (pf[cell_r][cell_c] == 45 && life_count == 3) {
        pf[cell_r][cell_c] = 42;
    }
}

void print_pf(char** pf, int size_ro, int size_col) {
    for (int i = 0; i < size_ro; i++) {
        for (int j = 0; j < size_col; j++) {
            std::cout << pf[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int cell_count(char** pf, int size_ro, int size_col) {
    int cellcount = 0;
    for (int i = 0; i < size_ro; i++) {
        for (int j = 0; j < size_col; j++) {
            if (pf[i][j] == 42) {
                cellcount++;
            }
      
        }
    }
    return cellcount;
}

bool pf_analize(char** pf, char** pf2, int size_ro, int size_col) {
    for (int i = 0; i < size_ro; ++i) {
        for (int j = 0; j < size_col; ++j) {
            if (pf[i][j] != pf2[i][j]) {
                return false;
            }
        }
    }
    return true;
}



int main() {
    int rows, cols, cell_r, cell_c, gen_count;
    gen_count = 1;
    std::ifstream da_so("datasource.ini");
    da_so >> rows >> cols;
    char** playfield = create_pf(rows, cols);
    char** copy_pf = create_pf(rows, cols);
    fill_pf(playfield, rows, cols);
    fill_pf(copy_pf, rows, cols);
    for (;;) {
        da_so >> cell_r >> cell_c;
        cell_in(playfield, rows, cols, cell_r, cell_c);
        if (da_so.eof()) {
            break;
        }
    }
    print_pf(playfield, rows, cols);
    std::cout << "Generation: 0"  << " Alive cell:" << cell_count(playfield, rows, cols);
    std::cout << std::endl;
    Sleep(1000);
    system("cls");
    


    for (;;) { 
        fill_copy(playfield, copy_pf, rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                neighbour_cell(playfield,copy_pf, rows, cols, i, j);
            }
        }
        print_pf(playfield, rows, cols);
        std::cout << "Generation: " << gen_count++ << " Alive cell:" << cell_count(playfield, rows, cols);
        std::cout << std::endl;
        if (bool flag = pf_analize(playfield, copy_pf, rows, cols) == true) {
            std::cout << "game over. autism wins";
            break;
        }
        
        Sleep(1000);

        if (int cell = cell_count(playfield, rows, cols) == 0) {
            std::cout << "game over. all cells dead.";
            break;
        }
        system("cls");
    }
   


    
    da_so.close();
    return 0;
}

