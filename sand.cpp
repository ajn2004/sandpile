// C++ code for the Sandpile Model

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
// #include <pybind11/pybind11.h>
// #include <pybind11/stl.h>

class SandpileModel {
private:
    std::vector<std::vector<int>> grid;
  int N, M, topples;

    bool isStable() {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(grid[i][j] >= 4) {
                    return false;
                }
            }
        }
        return true;
    }

    void topple(int x, int y) {
        grid[x][y] -= 4;

        // Top
        if(x - 1 >= 0) grid[x - 1][y]++;
        // Bottom
        if(x + 1 < N) grid[x + 1][y]++;
        // Left
        if(y - 1 >= 0) grid[x][y - 1]++;
        // Right
        if(y + 1 < M) grid[x][y + 1]++;
    }

public:
  SandpileModel(int n, int m) : N(n), M(m) {
        srand(time(nullptr));

        grid.resize(N);
        for(int i = 0; i < N; i++) {
            grid[i].resize(M);
            for(int j = 0; j < M; j++) {
                grid[i][j] = rand() % 4;
            }
        }
    }

    const std::vector<std::vector<int>>& getGrid() const{ return grid;}
  
    void iterate(int num_iterations) {
        for(int iter = 0; iter < num_iterations; iter++) {
            int x = rand() % N;
            int y = rand() % M;

            grid[x][y]++;
	    topples = 0;
            while(!isStable()) {
	      topples += 1;
                for(int i = 0; i < N; i++) {
                    for(int j = 0; j < M; j++) {
                        if(grid[i][j] >= 4) {
                            topple(i, j);
                        }
                    }
                }
            }
        }
    }

    int getTopples(){return topples;}
    void displayGrid() {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                std::cout << grid[i][j];
            }
            std::cout << std::endl;
        }
    }
};

// namespace py = pybind11;

// PYBIND11_MODULE(sandpile, m) {
//     py::class_<SandpileModel>(m, "SandpileModel")
//         .def(py::init<int, int>())
//         .def("displayGrid", &SandpileModel::displayGrid)
//         .def("getGrid", &SandpileModel::getGrid)
//         .def("getTopples", &SandpileModel::getTopples)
//         .def("iterate", &SandpileModel::iterate);
    
    
// }

// Sample usage

// int main() {
//     SandpileModel model(30, 150);
//     model.displayGrid();
//     std::cout << "--------------\n";
//     model.iterate(10000);
//     model.displayGrid();

//     return 0;
// }


// Note: The sample usage is commented out since the code is being run in a Python environment.
// However, in a C++ environment, you can uncomment the sample usage and run the program.
