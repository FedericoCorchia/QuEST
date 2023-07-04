#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include "QuEST.h"

std::vector<Complex> readAmpsFromFile(const std::string &filepath)
{
    std::ifstream file;
    file.open(filepath);
    if (!file)
    {
        std::cerr << "Failed to open the file.\n";
        return {};
    }
    std::vector<Complex> amps;
    std::string line;
    std::getline(file, line); // skip first line (header)
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        Complex c;
        ss >> c.real >> c.imag;
        amps.push_back(c);
    }
    file.close();
    return amps;
}

int main(int narg, char *varg[])
{
    // read complex amplitudes from input csv file
    std::string filename = "init_statevector.csv";
    std::vector<Complex> amps = readAmpsFromFile(filename);
    int size = amps.size();
    double reals[size], imags[size];
    for (int i = 0; i < size; i++)
    {
        reals[i] = amps[i].real;
        imags[i] = amps[i].imag;
    }

    // prepare QuEST environment
    QuESTEnv env = createQuESTEnv();

    // initialize quantum register
    int num_qubits = log2(size);
    Qureg qureg = createQureg(num_qubits, env);
    initStateFromAmps(qureg, reals, imags);

    // apply QFT to quantum register
    applyFullQFT(qureg);

    // write output csv file in chunks
    reportState(qureg);

    // free memory
    destroyQureg(qureg, env);

    // close environment
    destroyQuESTEnv(env);

    return 0;
}