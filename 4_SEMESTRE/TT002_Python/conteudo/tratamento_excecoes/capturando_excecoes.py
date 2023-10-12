def dividir(a, b):
    try:
        resultado = a / b
        print("Resultado da divisao: ", resultado)
    except ZeroDivisionError:
        print("Erro: Divisao por zero não e permitida.")
    except TypeError:
        print("Erro: Tipos incompativeis para a divisão.")
    except Exception as e:
        print("Ocorreu uma excecao: ", str(e))
    else:
        print("Nenhuma excecao ocorreu.")
    finally:
        print("Execucao finalizada.")
    
dividir(10, 2)
dividir(10, '2')
dividir(10, 0)