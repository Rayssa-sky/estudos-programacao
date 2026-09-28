from time import sleep
import json

def carregar():
    try:
       with open("agendamentos.json", "r") as arquivo:
         dados = json.load(arquivo)
         return dados
    except FileNotFoundError:
        return []

lista_animal = carregar()

def ler_texto(pergunta):
    while True:
        texto = input(pergunta)
        if texto.replace(" ", "").isalpha():
            return texto
        print("Somente letras!")


def salvar():
    with open("agendamentos.json", "w") as arquivo:
        json.dump(lista_animal, arquivo)


def agendar():
    nome = ler_texto("Nome do animal: ")
    especie = ler_texto("Espécie do animal: ")
    dono = ler_texto("Dono do animal(nome): ")

    while True:
        try:
            idade = int(input("Idade do animal: "))
            break
        except ValueError:
            print("Somente número inteiro!")

    animal = {
        "nome": nome,
        "especie": especie,
        "idade": idade,
        "dono": dono,
    }
    lista_animal.append(animal)
    print(f"{nome} agendado com sucesso!")
    salvar()

def listar():
    print("*" * 30)
    if not lista_animal:
        sleep(2)
        print("Nenhum animal encontrado!")
        print("*" * 30)
        return
    for animal in lista_animal:
        sleep(2)
        print(f"Nome: {animal['nome']} | Espécie: {animal['especie']} | Idade: {animal['idade']} | Dono(a): {animal['dono']}")
    print("*" * 30)


def buscar():
    print("-=" * 30)
    busca = input("Digite o nome do animal que deseja buscar: ").lower()
    achou = False
    for animal in lista_animal:
        if busca == animal['nome'].lower():
            achou = True
            print(f"Nome: {animal['nome']} | Espécie: {animal['especie']} | Idade: {animal['idade']} | Dono(a): {animal['dono']}")
    if not achou:
        print("Nenhum animal encontrado")


def remover():
    print("-=" * 30)
    busca = input("Digite o nome do animal que deseja remover: ").lower()
    achou = False
    for animal in lista_animal:
        if busca == animal['nome'].lower():
            achou = True
            lista_animal.remove(animal)
            sleep(2)
            print(f"Agendamento do animal - {animal['nome']} - removido!")
            salvar()
            break
    if not achou:
        sleep(2)
        print("Nenhum animal encontrado")


def menu():
    while True:
        sleep(2)
        print("-=-=-=-=-=- MENU -=-=-=-=-=-=\n")
        print("Escolha uma opção: \n")
        print("1. Cadastrar um animal.\n")
        print("2. Listar os animais.\n")
        print("3. Buscar um animal.\n")
        print("4. Remover um animal.\n")
        print("0. Sair do programa.\n")
        try:
            escolha = int(input("Escolha (1, 2, 3, 4 ou 0 para sair): "))
        except ValueError:
            print("Caractere inválido.")
            continue
        if escolha == 1:
            agendar()
        elif escolha == 2:
            listar()
        elif escolha == 3:
            buscar()
        elif escolha == 4:
            remover()
        elif escolha == 0:
            print("Saindo do programa....")
            break
        else:
            print("Opção inválida.")


menu()