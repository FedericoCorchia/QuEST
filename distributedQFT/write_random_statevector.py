from qiskit.quantum_info import random_statevector

# set configs
num_qubits = 3
dims = 2**num_qubits
filepath = './init_statevector.csv'
seed = 42


if __name__ == '__main__':

    statevector = random_statevector(dims=dims, seed=seed)

    with open(filepath, mode='w') as file:
        file.write('real, imag\n')
        for amp in statevector.data:
            file.write(f'{amp.real}, {amp.imag}\n')

    print(f'Written random statevector in file "{filepath}"')
    print(f'  num_qubits = {num_qubits}')
    print(f'  random_seed = {seed}')
