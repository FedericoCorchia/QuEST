from qiskit.quantum_info import random_statevector


# SETTINGS
#########################################
num_qubits = 3
seed = 42
#########################################


if __name__ == '__main__':

    statevector = random_statevector(dims=2**num_qubits, seed=seed)
    filepath = './init_statevector.csv'

    with open(filepath, mode='w') as file:
        file.write('real, imag\n')
        for amp in statevector.data:
            file.write(f'{amp.real}, {amp.imag}\n')

    print(f'Written random statevector in file "{filepath}"')
    print(f'  num_qubits = {num_qubits}')
    print(f'  random_seed = {seed}')
