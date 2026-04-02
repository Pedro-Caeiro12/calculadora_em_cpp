/*
 * ============================================================
 *  Tipo de Projeto: Calculadora
 *  Autor: Pedro Caeiro
 *  Data:  02/04/2026
 * ============================================================
 *  Funcionalidades da Calculadora:
 *    1. Soma
 *    2. Subtracao
 *    3. Multiplicacao
 *    4. Divisao
 *    5. Formula Resolvente
 *    0. Sair
 * ============================================================
 */

#include <iostream>
#include <cmath>
#include <limits>
#include <locale> 
#include <string>

using namespace std;

void limparBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double lerNumero(const string& mensagem) {
    double valor;
    while (true) {
        cout << mensagem;
        if (cin >> valor) {
            limparBuffer();
            return valor;
        }
        cout << "  [Erro] Entrada inválida. Introduza um número válido.\n";
        limparBuffer();
    }
}

void separador(char c = '-', int tamanho = 44) {
    cout << string(tamanho, c) << "\n";
}

void operacaoSoma() {
    separador();
    cout << " ------ Soma ------\n";
    separador();
    double a = lerNumero("  Primeiro número  : ");
    double b = lerNumero("  Segundo número   : ");
    double resultado = a + b;
    separador();
    cout << "  Resultado: " << a << " + " << b << " = " << resultado << "\n";
    separador();
}

void operacaoSubtracao() {
    separador();
    cout << "  ------ Subtração ------\n";
    separador();
    double a = lerNumero("  Primeiro número  : ");
    double b = lerNumero("  Segundo número  : ");
    double resultado = a - b;
    separador();
    cout << "  Resultado: " << a << " - " << b << " = " << resultado << "\n";
    separador();
}

void operacaoMultiplicacao() {
    separador();
    cout << "  ------ Multiplicação ------\n";
    separador();
    double a = lerNumero("  Primeiro número  : ");
    double b = lerNumero("  Segundo número   : ");
    double resultado = a * b;
    separador();
    cout << "  Resultado: " << a << " x " << b << " = " << resultado << "\n";
    separador();
}

void operacaoDivisao() {
    separador();
    cout << "  ------ Divisão ------\n";
    separador();
    double a = lerNumero("  Dividendo : ");
    double b;

    while (true) {
        b = lerNumero("  Divisor   : ");
        if (b != 0.0) break;
        cout << "  [Erro] Divisão por zero não e permitida!\n";
    }

    double resultado = a / b;
    separador();
    cout << "  Resultado: " << a << " / " << b << " = " << resultado << "\n";
    separador();
}

void operacaoFormulaResolvente() {
    separador();
    cout << "  ------ Fórmula Resolvente ------n";
    cout << "     ax^2 + bx + c = 0\n";
    separador();
    double a = lerNumero("  Coeficiente A : ");

    while (a == 0.0) {
        cout << "  [Erro] O coeficiente 'A' não pode ser zero (não seria equação do 2o grau).\n";
        a = lerNumero("  Coeficiente A : ");
    }

    double b = lerNumero("  Coeficiente B : ");
    double c = lerNumero("  Coeficiente C : ");

    double delta = (b * b) - (4.0 * a * c);

    separador();
    cout << "  Delta (discriminante) = " << delta << "\n";
    separador();

    if (delta > 0.0) {
        double x1 = (-b + sqrt(delta)) / (2.0 * a);
        double x2 = (-b - sqrt(delta)) / (2.0 * a);
        cout << "  Duas raizes reais distintas:\n";
        cout << "    x1 = " << x1 << "\n";
        cout << "    x2 = " << x2 << "\n";
    } else if (delta == 0.0) {
        double x = -b / (2.0 * a);
        cout << "  Uma raiz real dupla:\n";
        cout << "    x = " << x << "\n";
    } else {
        double parteReal      =  -b / (2.0 * a);
        double parteImaginaria =  sqrt(-delta) / (2.0 * a);
        cout << "  Duas raizes complexas conjugadas:\n";
        cout << "    x1 = " << parteReal << " + " << parteImaginaria << "i\n";
        cout << "    x2 = " << parteReal << " - " << parteImaginaria << "i\n";
    }

    separador();
}

void mostrarMenu() {
    separador('=');
    cout << " ------ CALCULADORA C++ ------\n";
    separador('=');
    cout << "  [1]  Soma\n";
    cout << "  [2]  Subtração\n";
    cout << "  [3]  Multiplicação\n";
    cout << "  [4]  Divisão\n";
    cout << "  [5]  Fórmula Resolvente\n";
    separador();
    cout << "  [0]  Sair\n";
    separador('=');
    cout << "  Opção: ";
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    do {
        mostrarMenu();

        if (!(cin >> opcao)) {
            limparBuffer();
            cout << "\n  [Erro] Introduza um número inteiro válido.\n\n";
            continue;
        }
        limparBuffer();
        cout << "\n";

        switch (opcao) {
            case 1:
                operacaoSoma();
                break;
            case 2:
                operacaoSubtracao();
                break;
            case 3:
                operacaoMultiplicacao();
                break;
            case 4:
                operacaoDivisao();
                break;
            case 5:
                operacaoFormulaResolvente();
                break;
            case 0:
                cout << "  Encerrando a calculadora. Até logo!\n";
                break;
            default:
                cout << "  [Erro] Opção inválida. Escolha entre 0 e 5.\n";
                break;
        }

        cout << "\n";

    } while (opcao != 0);

    return 0;
}