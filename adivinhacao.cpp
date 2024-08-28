#include <iostream>
#include <cstdlib>  // Para rand() e srand()
#include <ctime>    // Para time()

using namespace std;

int main() {
    cout << "***********************************" << endl;
    cout << "*Bem-vindos ao jogo da adivinhacao!*" << endl;
    cout << "***********************************" << endl;

    cout << "Escolha seu nível de dificuldade:" << endl;
    cout << "Facil (f), Medio (m), Dificil (d)" << endl;

    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;
    if (dificuldade == 'f') {
        numero_de_tentativas = 15;
    } else if (dificuldade == 'm') {
        numero_de_tentativas = 10;
    } else {
        numero_de_tentativas = 5;
    }

    srand(static_cast<unsigned>(time(nullptr)));  // Inicializa o gerador de números aleatórios
    const int numero_secreto = rand() % 99 + 1;    // Ajustado para intervalo de 1 a 99
   // cout << "numero secreto: " << numero_secreto << endl;//

    bool nao_acertou = true;
    int tentativas = 0;

    double pontos = 1000.0;

    for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++) {
        int chute;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual o seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - numero_secreto) / 2.0;
        pontos -= pontos_perdidos;

        cout << "O valor do seu chute é: " << chute << endl;

        if (chute == numero_secreto) {
            cout << "Parabens! Voce acertou!" << endl;
            nao_acertou = false;
            break; // Interrompe o loop se o usuário acertar
        } else if (chute > numero_secreto) {
            cout << "Seu chute foi maior que o numero secreto." << endl;
        } else {
            cout << "Seu chute foi menor que o numero secreto." << endl;
        }
    }

    cout << "Fim de jogo" << endl;
    if (nao_acertou) {
        cout << "Game over!" << endl;
    } else {
        cout << "Voce acertou em " << tentativas << " tentativa(s)." << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
    }

    return 0;
}
