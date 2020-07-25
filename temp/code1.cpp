#include <iostream>
#include <mpi.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    std::cout << "Hello world from " << rank << "-th process" << std::endl;

    MPI_Barrier(MPI_COMM_WORLD);
    if (rank == 0) {
        std::cout << "Press enter to close" << std::endl;
        std::cin.ignore(10000, '\n');
    }

    MPI_Finalize();

    return 0;
}