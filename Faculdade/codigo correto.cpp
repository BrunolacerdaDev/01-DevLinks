#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Pessoa {
    string nome;
    string data_nascimento;
    string cpf;
    int id;
};

void cadastrar_pessoa(vector<Pessoa>& pessoas, int& num_pessoas) {
    Pessoa nova_pessoa;

    cout << "Digite o nome completo: ";
    getline(cin, nova_pessoa.nome);

    cout << "Digite a data de nascimento (DD/MM/AAAA): ";
    getline(cin, nova_pessoa.data_nascimento);

    cout << "Digite o CPF: ";
    getline(cin, nova_pessoa.cpf);

    nova_pessoa.id = num_pessoas;

    pessoas.push_back(nova_pessoa);

    num_pessoas++;

    cout << "Pessoa cadastrada com sucesso!" << endl;
}

void listar_pessoas(vector<Pessoa>& pessoas) {
    if (pessoas.empty()) {
        cout << "Nenhuma pessoa cadastrada." << endl;
        return;
    }

    cout << "Lista de pessoas cadastradas:" << endl;

    for (int i = 0; i < pessoas.size(); i++) {
        cout << "[" << pessoas[i].id << "] " << pessoas[i].nome << endl;
    }
}

void excluir_pessoa(vector<Pessoa>& pessoas, int& num_pessoas) {
    int id;

    cout << "Digite o ID da pessoa que deseja excluir: ";
    cin >> id;

    if (id < 0 || id >= num_pessoas) {
        cout << "ID inválido." << endl;
        return;
    }

    pessoas.erase(pessoas.begin() + id);

    for (int i = id; i < num_pessoas - 1; i++) {
        pessoas[i].id--;
    }

    num_pessoas--;

    cout << "Pessoa excluída com sucesso!" << endl;
}

void ver_dados_pessoa(vector<Pessoa>& pessoas) {
    int id;

    cout << "Digite o ID da pessoa que deseja ver os dados: ";
    cin >> id;

    if (id < 0 || id >= pessoas.size()) {
        cout << "ID inválido." << endl;
        return;
    }

    Pessoa pessoa = pessoas[id];

    cout << "Nome completo: " << pessoa.nome << endl;
    cout << "Data de nascimento: " << pessoa.data_nascimento << endl;
    cout << "CPF: " << pessoa.cpf << endl;
}

void salvar_dados(vector<Pessoa>& pessoas) {
    ofstream arquivo("dados.txt");

    for (int i = 0; i < pessoas.size(); i++) {
        arquivo << pessoas[i].nome << endl;
        arquivo << pessoas[i].data_nascimento << endl;
        arquivo << pessoas[i].cpf << endl;
        arquivo << pessoas[i].id << endl;
        arquivo << "---" << endl;
    }

    arquivo.close();

    cout << "Dados salvos com sucesso!" << endl;
}

void carregar_dados(vector<Pessoa>& pessoas, int& num_pessoas) {
    ifstream arquivo("dados.txt");

    if (!arquivo.is_open()) {
        return;
    }

    string linha;

    while (getline(arquivo, linha)) {
        Pessoa nova_pessoa;

        nova_pessoa.nome = linha;

        getline(arquivo, linha);
        nova_pessoa.data_nascimento = linha;

        getline(arquivo, linha);
        nova_pessoa.cpf = linha;

        getline(arquivo, linha);
        nova_pessoa.id = stoi(linha);

        getline(arquivo, linha);

        pessoas.push_back(nova_pessoa);
        num_pessoas++;
    }

    arquivo.close();

}

int main() {
    
	vector<Pessoa> pessoas;
	int num_pessoas = 0;

	carregar_dados(pessoas, num_pessoas);

	while (true) {
		cout<<endl<<"[1] Cadastrar pessoa"<<endl<<"[2] Listar pessoas"<<endl<<"[3] Excluir pessoa"<<endl<<"[4] Ver dados da pessoa"<<endl<<"[5] Sair"<<endl<<endl<<"Digite sua opção: ";

		int opcao;
		cin >> opcao;

		cin.ignore();

		switch
