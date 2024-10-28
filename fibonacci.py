prom, sumat, cont = 0, 0, 0

for i in range(1, 7):
    num = int(input("Digite un numero: "))
    if num < 0:
        sumat = sumat + num
    else:
        prom = prom + num
        cont = cont + 1
print(f"La suma de los numeros negativos fue: {sumat}")
if cont == 0:
    print("No se ha introducido ningun numero positivo")
else:
    print(f"El promedio de los numeros positivos fue: {prom/cont}")