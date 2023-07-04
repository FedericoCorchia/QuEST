# distributedQFT
The project aims to run the Quantum Fourier Transform (QFT) algorithm on an arbitrary *n*-qubits statevector by leveraging a multi-node geographically distributed infrastructure set up on the AWS Elastic Compute Cloud (EC2).
The application designed for the QFT simulation is based on QuEST, a multithreaded, and distributed simulator of quantum computers.

The ultimate goal of the project is to study **how the performance of the simulation scales with the AWS resources in terms of time and costs**.
Remember that the full-statevector simulation of a quantum system requires an amount of classical hardware resorces that scales exponentially with the number of qubits. Today, high-performance computers can go up to ~50 qubits: beyond this limit, the simulation of quantum computers becomes classically untractable.

## Install and compile
The basic requirements for running the application are `python>=3.8` and the IBM Quantum Qiskit SDK:
```
pip install qiskit
```
Once you locally cloned the repository, move to the `/distributedQFT` directory and run the `compile_qft.sh` shell script:
```
cd distributedQFT
./compile_qft.sh
```
This will use CMake (version `3.7` or higher) to dynamically compile the whole QuEST library together with the `qft.cpp` source code and finally build the `qft.out` executable.

## Run application
First of all, run the python script to generate a random initial statevector and write it on a CSV file:
```
python write_random_statevector.py
```
Then you can run the QFT application by simply running the qft.out executable just created:
```
./qft.out
```
This will generate a new `state_rank_<i>.csv` file for each node `i` of the distributed infrastructure. Each of these CSV files contains a part of the QFT output statevector amplitudes (same format of the input file).

## Set configurations
By default, the application is compiled for a single node with no multithreading. To change the configurations look at the CMake options in the `compile_qft.sh` script (further details in the "Compiling" section of the `QuEST/examples/README.md` file).

To set a custom number of qubits and control the random seed for the statevector generation, look at the available settings in the Python script.