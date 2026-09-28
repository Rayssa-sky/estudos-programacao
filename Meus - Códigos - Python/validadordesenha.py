def validar_senha(senha):
    tem_numero = False
    tem_maiuscula = False
    tem_minuscula = False
    senha_ok = True
    especiais = "!@#$%&*"
    tem_especiais = False

    for letra in senha:
        if letra.isdigit():
            tem_numero = True
        if letra.isupper():
            tem_maiuscula = True
        if letra.islower():
            tem_minuscula = True
        if letra in especiais:
            tem_especiais = True


    if not tem_numero:
        print("Falta um número!")
        senha_ok = False
    if not tem_maiuscula:
        print("Falta pelo menos uma letra MAIÚSCULA!")
        senha_ok = False
    if not tem_minuscula:
        print("Falta pelo menos uma letra MINÚSCULA!")
        senha_ok = False
    if len(senha) < 8:
        print("A senha tem de ter pelo menos 8 caracteres!")
        senha_ok = False

    if not tem_especiais:
        print("Falta pelo menos uma letra especiais!")
        senha_ok = False

    if senha_ok == True:
        print("Senha forte!")
    return senha_ok

while True:
    texto = input("Digite uma senha: ")
    if validar_senha(texto):
        break
