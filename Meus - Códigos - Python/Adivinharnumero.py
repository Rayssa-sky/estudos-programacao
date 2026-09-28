from random import randint

jogar_de_novo = "S"

while jogar_de_novo == "S":

 computador = randint(1,100)

 contador = 0


 while True:
     try:
        adivinha = int(input("Adivinhe um numero entre 1 e 100: (10 CHANCES) \n"))

        contador += 1
        if adivinha == computador:

         print(f"Você acertou! Seu numero : {adivinha}| Numero adivinhado: {computador} \n")

         print(f"Tentativas: {contador}")
         break
        elif adivinha > computador:
         print(f"Seu numero foi {adivinha}, e passou do numero da adivinhação.\n")
        elif adivinha < computador:
         print(f"Seu numero foi {adivinha} , e é menor que o número da adivinhação.\n")
     except ValueError:
         print("Digite apenas números inteiros!")
     if contador == 10:
      print(f"Tentativas esgotadas! O número do computador era: {computador}. ")
      break
 jogar_de_novo= str(input("Você quer continuar ? [S/N]: ")).upper()


