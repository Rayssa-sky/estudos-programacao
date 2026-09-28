###PROJETO APOSTA NO LUTADOR
from random import randint
from time import sleep

def lutadores():
    lutador = [
        {
            "nome": "Xuxu",
            "idade": "23",
            "Peso": 70.2,
            "Altura" : 1.78,
            "Nacionalidade": "Brasil",
            "HP": 200
        },
        {
            "nome": "Pidão",
            "idade": "27",
            "Peso": 68.9,
            "Altura": "1.75",
            "Nacionalidade": "Portugal",
            "HP": 200
        },
        {
            "nome": "Chola",
            "idade": "29",
            "Peso": 75.0,
            "Altura": "1.79",
            "Nacionalidade": "Argentina",
            "HP": 200
        },
        {
            "nome": "Bundão",
            "idade": "32",
            "Peso": 77.1,
            "Altura": "1.77",
            "Nacionalidade": "Austrália",
            "HP": 200
        },
        {
            "nome": "Bola oito",
            "idade": "35",
            "Peso": 79.7,
            "Altura": "1.85",
            "Nacionalidade": "Alemanha",
            "HP": 200
        },
        {
            "nome": "Ferrudo",
            "idade": "28",
            "Peso": 80.8,
            "Altura": "1.89",
            "Nacionalidade": "Angola",
            "HP": 200
        },
    ]

    def mostrar_lutadores():
        print("-=" * 40)
        print("\033[1;37;41mLUTADORES DISPONÍVEIS\n\033[0m".center(80))
        print("-=" * 40)
        for fight in lutador:

            print(
                f"Nome: {fight['nome']:<15} | "
                f"Idade: {fight['idade']:<6} |"
                f" Peso: {fight['Peso']:8.1f}Kg |"
                f" Altura: {fight['Altura']:<8} |"
                f" Nacionalidade: {fight['Nacionalidade']:<15}"
            )


    mostrar_lutadores()
    return lutador


def mostrar_peso(lista_lutadores):
    print("-=" * 40)
    print("\033[33;44mTABELA DOS LUTADORES POR CATEGORIA\033[0m \n".center(80))
    print("-=" * 40)

    print("\033[30;43m-- 1. PESO LEVE --\033[0m\n")
    for fight in lista_lutadores:
        sleep(0.5)
        if 65.8 < fight['Peso'] <= 70.3:
            print(f"Nome: {fight['nome']} | Peso: {fight['Peso']}Kg \n")
    print("\033[30;43m-- 2. PESO MEIO-MÉDIO --\033[0m\n")
    for fight in lista_lutadores:
        sleep(0.5)
        if 70.3 < fight['Peso'] <= 77.1:
            print(f"Nome: {fight['nome']} | Peso: {fight['Peso']}Kg \n")
    print("\033[30;43m-- 3. PESO MÉDIO --\033[0m\n")
    for fight in lista_lutadores:
        sleep(0.5)
        if 77.1 < fight['Peso'] <= 83.9:
            print(f"Nome: {fight['nome']} | Peso: {fight['Peso']}Kg \n")



def combate(meu_lutador, lutador_pc, valor_aposta):

    print("-=" * 20)

    golpe_cruzado = 65
    golpe_gancho = 50

    while meu_lutador["HP"] > 0 and lutador_pc["HP"] > 0:
     sleep(1)
     print(f"SEU HP ({meu_lutador['nome']}): {meu_lutador['HP']}")
     print(f"HP PC ({lutador_pc['nome']}): {lutador_pc['HP']}")

     print("-=-" * 20)
     print("Rolando os dados...")
     sleep(1)

     dado_usuario = randint(1,6)
     dado_computador  = randint(1,6)


     print( f"Dado Você ({meu_lutador['nome']}): {dado_usuario} | Dado PC ({lutador_pc['nome']}): {dado_computador}"
        )

     if dado_usuario > dado_computador:
         print("Você ganhou a Rodada!")
         print("-=-" * 20)
         escolha_golpe = int(input("Escolha um dos golpes:\n1. Golpe Cruzado\n2. Golpe Gancho\nOpção: "))

         dano = golpe_cruzado if  escolha_golpe == 1 else golpe_gancho
         lutador_pc["HP"] -= dano
         print("--" * 20)
         print(f"Você acertou o golpe e causou {dano} de dano em {lutador_pc['nome']}")

     elif dado_computador > dado_usuario:
         print(f"\nO computador ganhou a rodada e te atacou!")
         dano = randint(40, 55)  # Danos variados do PC
         meu_lutador["HP"] -= dano
         print(
             f"{lutador_pc['nome']} acertou um golpe e te causou {dano} de dano!"
         )

     else:
         print("\nEmpate nos dados! Ninguém ataca nesta rodada.")

    print("\n" + "=-" * 20)
    if meu_lutador["HP"] > 0:
        print(
            f"PARABÉNS! {meu_lutador['nome']} VENCEU A LUTA!"
        )
        print(
            f"Você ganhou sua aposta! Recebeu R$ {valor_aposta * 2:.2f}"
        )
    else:
        print(
            f"QUE PENA! {lutador_pc['nome']} VENCEU A LUTA!"
        )
        print(f"Você perdeu sua aposta de R$ {valor_aposta:.2f}")
    print("=-" * 20)



dados_lutadores = lutadores()
mostrar_peso(dados_lutadores)



lutadores_categoria = []

print("-=" * 20)
while True:
    try:
      escolha = int(input("Digite o categoria que deseja escolher: "))
      if escolha in [1,2,3,4]:
           break
    except ValueError:
        print("Escolha somente número.")



if escolha == 1:
    print("- LUTADORES DISPONÍVEIS NA CATEGORIA PESO LEVE - \n")

    for fight in dados_lutadores:
        if 65.8 < fight['Peso'] <= 70.3:
            print(f"Nome: {fight['nome']} com {fight['Peso']}Kg \n")
            lutadores_categoria.append(fight)



elif escolha == 2:
    print("- LUTADORES DISPONÍVEIS NA CATEGORIA PESO MEIO-MÉDIO - \n")
    for fight in dados_lutadores:
        if 70.3 < fight['Peso'] <= 77.1:
            print(f"Nome: {fight['nome']} com {fight['Peso']}Kg \n")
            lutadores_categoria.append(fight)

elif escolha == 3:
    print("- LUTADORES DISPONÍVEIS NA CATEGORIA PESO MÉDIO - \n")
    for fight in dados_lutadores:
        if 77.1 < fight['Peso'] <= 83.9:
            print(f"Nome: {fight['nome']} com {fight['Peso']}Kg \n")
            lutadores_categoria.append(fight)

elif escolha == 4:
     print("Saindo ...")
     exit()

else:
    print("Escolha inválida!")


nomes_validos = [f["nome"].lower() for f in lutadores_categoria]

lutador_apostado = ""

meu_lutador = None
lutador_pc = None

while True:
    resposta = (input("Em qual dos dois lutadores você quer apostar : ")).strip().lower()

    if resposta in nomes_validos:
        for f in lutadores_categoria:
            if f["nome"].lower() == resposta:
                meu_lutador = f  # <- Guarda o lutador que você escolheu
            else:
                lutador_pc = f  # <- Guarda o lutador que sobrou para o PC
        break


print(f"Você escolheu o lutador {resposta} para apostar!")


while True:
    try:
        aposta = float(input("Qual o valor você irá apostar: (50R$ - 2500R$)"))
        if 50 <= aposta <= 2500:
            break
        print("Valor acima do limite permitido!")
    except ValueError:
        print("Digite apenas números.")



combate(meu_lutador,lutador_pc, aposta)






