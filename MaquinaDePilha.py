#!/usr/bin/python
#-*- coding: UTF-8 -*-

pilha = []

while True:
	try:
		entrada = raw_input()
	except EOFError:
		break

	exp=entrada.split("\n")

	
	if exp[0] == "ADD":
		a1 = pilha.pop()
		a2 = pilha.pop()
		pilha.append(a1+a2) 
	elif exp[0] == "SUB":
		a1 = pilha.pop()
		a2 = pilha.pop()
		pilha.append(a2-a1) 
	elif exp[0] == "DIV":
		a1 = pilha.pop()
		a2 = pilha.pop()
		pilha.append(a2/a1) 
	elif exp[0] == "MULT":
		a1 = pilha.pop()
		a2 = pilha.pop()
		pilha.append(a2*a1) 
	elif exp[0] == "PRINT":
		print pilha[-1]
	else:
		exp = entrada.split(" ")
		pilha.append(int(exp[1]))
