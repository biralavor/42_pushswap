#!/usr/bin/env python3

import random
import subprocess


"""
Esse programa ira testar o seu push_swap
Siga as instruções abaixo para executar
Ele irá contar o número de instruções e verificar se foi ordenado
Se ele encontar um caso que não foi ordenado, ele irá mostrar na tela

É necessário ter o `checker_linux` no mesmo lugar do `push_swap`
"""

push_swap_path = "../push_swap"
checker_path = "../checker_linux"
run_with_valgrind = False				# Mude para True se quiser rodar com o valgrind

# Aqui você deve por por quais quantidade de número vc deseja testar
# Por exemplo [3, 5, 10]:
# Vai ser testado vários testes com 3 números
# Depois vários testes com 5 números
# E por fim, vários testes./p	 com 10 números
# Pode por quantos números quiser
# Mas na régua só será testado: [3, 5, 100, 500]
test_groups = [3, 5, 10, 15, 100, 500]
#test_groups = range(1, 5)

# -7 -4 -1 -6 3 2 -5 -3 1 -2
# 3 -5 -2 2 -6 1 4 -3 -4 -1

# Aqui você deve por o range de números que deseja considerar ao fazer os testes
# range_start - menor número
# range_end - maior número
range_start = -2**31
# range_start = 0
range_end = 2**31 - 1
# range_end = 1000


# Aqui você deve por a quantidade de testes que você quer fazer com cada grupo de
# números do `test_groups`
# Se colocar muito, vai demorar demais para acabar
# Padrão = 100
test_num = 100


# Daqui para baixo não precisa mexer
for n in test_groups:
	outputs = []
	max_sequence = []
	min_sequence = []
	print(f"\n\nFor n = {n}:\n", flush=True)

	try:
		for _ in range(test_num):
			# print(".", end="", flush=True)
			numbers = random.sample(range(range_start, range_end + 1), n)
			numbers_string = ' '.join(map(str, numbers))

			if (run_with_valgrind):
				command = f"valgrind -q --track-origins=yes --leak-check=full --show-leak-kinds=all {push_swap_path} {numbers_string}"
				process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
				output, output_error = process.communicate()
				output_error = output_error.decode()
				if (output_error != ""):
					print(f"leak sequence: {numbers_string}")
			else:
				print(f"{push_swap_path} {numbers_string}")
				output = subprocess.check_output(f"{push_swap_path} {numbers_string}", shell=True)
			output = output.decode()

			checker = subprocess.check_output(f'{push_swap_path} {numbers_string} | {checker_path} {numbers_string}', shell=True)
			checker = checker.decode()

			if (checker == "KO\n"):
				print(f"ko sequence: {numbers_string}")
				exit()

			num_newlines = output.count('\n')
			outputs.append(num_newlines)

			if num_newlines == max(outputs):
				max_sequence = numbers
			if num_newlines == min(outputs):
				min_sequence = numbers

		averages = sum(outputs) / len(outputs)
		maximum = max(outputs)
		minimum = min(outputs)

		print("\nAverage:", averages)
		print("Maximum:", maximum)
		print("Minimum:", minimum)
		print()
		print("Maximum Sequence:", *max_sequence)
		print()
		print("Minimum Sequence:", *min_sequence)
		print()
		print(flush=True)
	except Exception:
		print(f"ko sequence: {numbers_string}")
		exit()