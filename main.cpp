#include <iostream>
#include <string>
using namespace std;

class Cliente {
private:
    string nome;
    string cpf;

public:
    // Construtor para inicializar nome e cpf
    Cliente(string nome, string cpf) : nome(nome), cpf(cpf) {}

    // Métodos getter para acessar nome e cpf
    string getNome() const { return nome; }
    string getCpf() const { return cpf; }
};

class ContaBancaria {
private:
    int numero;
    double saldo;
    Cliente titular;

public:
    // Construtor para inicializar numero, saldo e titular
    ContaBancaria(int numero, Cliente titular, double saldo = 0.0)
        : numero(numero), saldo(saldo), titular(titular) {}

    // Método para depositar um valor na conta
    void depositar(double valor) {
        saldo += valor;
       
    }

    // Método para sacar um valor da conta
    void sacar(double valor) {
        if (valor > saldo) {
            cout << "Saldo insuficiente para saque na conta " << numero << endl;
        } else {
            saldo -= valor;
            cout << "Sacado: R$ " << valor << " da conta " << numero << endl;
        }
    }

    //  método transferir para uma única conta destino
    void transferir(double valor, ContaBancaria &destino) {
        if (valor > saldo) {
            cout << "Saldo insuficiente para transferir da conta " << numero << endl;
        } else {
            saldo -= valor;
            destino.depositar(valor);
            cout << "Transferido: R$ " << valor << " da conta " << numero << " para a conta " << destino.numero << endl;
        }
    }

    //  método transferir para duas contas destino
    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2) {
        if (valor > saldo) {
            cout << "Saldo insuficiente para transferir da conta " << numero << endl;
        } else {
            double metade = valor / 2;
            saldo -= valor;
            destino1.depositar(metade);
            destino2.depositar(metade);
            cout << "Transferido: R$ " << metade << " para cada conta (" << destino1.numero << " e " << destino2.numero << ") da conta " << numero << endl;
        }
    }

    // Método para exibir o saldo atual da conta
    void exibirSaldo() const {
        cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
    }

    // Método para exibir as informações do titular e da conta
    void exibirInformacoes() const {
        cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << endl;
        cout << "Número da Conta: " << numero << ", Saldo: R$ " << saldo << endl;
    }
};

int main() {
    // Criação dos clientes
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    // Criação das contas bancárias com saldos iniciais
    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2);
    ContaBancaria conta3(1003, cliente3);

    // Exibe o saldo inicial da conta de Ana
    conta1.exibirSaldo();

    // Ana transfere R$200 para Bruno
    conta1.transferir(200.0, conta2);

    // Ana transfere R$300 divididos entre Bruno e Carla
    conta1.transferir(300.0, conta2, conta3);

    // Exibição dos saldos finais
    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}
