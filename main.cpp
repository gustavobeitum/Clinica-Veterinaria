#include<iostream>
#include<string>
#include<conio.h>
#include<locale>
#include <cstring>

using namespace std;

struct Cidade{
    int codigo;
    char nome[70];
    char uf[3];
};

struct Tutor {
    int codigo;
    char nome[70];
    char cpf[12];
    char endereco[90];
    int codigoCidade;
};

struct Veterinario {
    int codigo;
    char nome[70];
    char endereco[90];
    int codigoCidade;
};

struct Raca {
    int codigo;
    char descricao[50];
};

struct Animal {
    int codigo;
    char nome[30];
    int codigoRaca;
    int idade;
    float peso;
    int codigoTutor;
};

struct Cosulta {
    int codigo;
    int codigoAnimal;
    int codigoVeterinario;
    char data[10];
    float valor;
};

void CadastrarCidade(struct Cidade cidades[], int &tamanho);
void CadastrarTutor(struct Tutor tutores[], int &tamanhoTutor, struct Cidade cidades[], int tamanhoCidade);
void CadastrarVeterinario(struct Veterinario veterinarios[], int &tamanhoVeterinario, struct Cidade cidades[], int tamanhoCidade);
void CadastrarRaca(struct Raca racas[], int &tamanhoRaca, struct Cidade cidades[], int tamanhoCidade);
bool ValidarCpf(char cpf[]);

int main() {
    setlocale(LC_ALL, "portuguese");

    const int max = 100;
    int tamanhoCidade;
    struct Cidade cidades[max];
    CadastrarCidade(cidades, tamanhoCidade);

    int tamanhoTutor;
    struct Tutor tutores[max];
    CadastrarTutor(tutores, tamanhoTutor, cidades, tamanhoCidade);

    int tamanhoVeterinario;
    struct Veterinario veterinarios[max];
    CadastrarVeterinario(veterinarios, tamanhoVeterinario, cidades, tamanhoCidade);

    return 0;
}

void CadastrarCidade(struct Cidade cidades[], int &tamanho) {
    cout<<"\nCadastrar Cidades (Para finalizar o cadastro, digite 0 no campo código): "<<endl;
    int i = 0;
    for (int saida = 1; saida !=0; i++) {

        cout<<"Código da cidade: ";
        cin>>cidades[i].codigo;

        cin.ignore();

        if (cidades[i].codigo > 0) {

            cout<<"Cidade: ";
            cin.getline(cidades[i].nome, 70);

            cout<<"UF: ";
            cin.getline(cidades[i].uf, 3);
        }else {
            saida = 0;
        }
    }
    tamanho = i-1;
}

void CadastrarTutor(struct Tutor tutores[], int &tamanhoTutor, struct Cidade cidades[], int tamanhoCidade) {
    cout << "\nCadastrar Tutores (Para finalizar o cadastro, digite 0 no campo código): "<<endl;

    int i = 0;
    for (int saida = 1; saida !=0; i++) {

        cout << "Código do tutor: ";
        cin >> tutores[i].codigo;

        cin.ignore();

        if (tutores[i].codigo > 0) {

            cout << "Nome do tutor: ";
            cin.getline(tutores[i].nome, 70);

            bool cpfInvalido = true;
            char cpf[12];

            while (cpfInvalido) {
                cout << "CPF (somente números, 11 dígitos): ";
                cin >> cpf;
                if (ValidarCpf(cpf)) {
                    strcpy(tutores[i].cpf , cpf);
                    cpfInvalido = false;
                    cin.ignore();
                } else cout<<"CPF inválido, insira um CPF válido.\n";
            }

            cout << "Endereço: ";
            cin.getline(tutores[i].endereco, 90);

            bool cidadeInvalida = true;
            int codCidade;

            while (cidadeInvalida) {
                cout << "Código da cidade: ";
                cin>>codCidade;

                for(i = 0; i < tamanhoCidade; i++) {
                    if (codCidade == cidades[i].codigo) {
                        tutores[i].codigoCidade = codCidade;
                        cidadeInvalida = false;
                    } else cout<<"Código de cidade inválido, insira um código válido.\n";
                }
            }
        }else saida = 0;
    }
    tamanhoTutor = i-1;
}

void CadastrarVeterinario(struct Veterinario veterinarios[], int &tamanhoVeterinario, struct Cidade cidades[], int tamanhoCidade) {
    cout << "\nCadastrar Veterinários (Para finalizar o cadastro, digite 0 no campo código): "<<endl;

    int i = 0;
    for (int saida = 1; saida !=0; i++) {
        cout << "Código do veterinário: ";
        cin >> veterinarios[i].codigo;

        cin.ignore();

        if (veterinarios[i].codigo > 0) {
            cout << "Nome do veterinário: ";
            cin.getline(veterinarios[i].nome, 70);

            cout << "Endereço: ";
            cin.getline(veterinarios[i].endereco, 90);

            bool cidadeInvalida = true;
            int codCidade;

            while (cidadeInvalida) {
                cout << "Código da cidade: ";
                cin>>codCidade;

                for(i = 0; i < tamanhoCidade; i++) {
                    if (codCidade == cidades[i].codigo) {
                        veterinarios[i].codigoCidade = codCidade;
                        cidadeInvalida = false;
                    } else cout<<"Código de cidade inválido, insira um código válido.\n";
                }
            }
        }else saida = 0;
    }
    tamanhoVeterinario = i-1;
}

void CadastrarRaca(struct Raca racas[], int &tamanhoRaca, struct Cidade cidades[], int tamanhoCidade) {
    cout << "\nCadastrar Veterinários (Para finalizar o cadastro, digite 0 no campo código): "<<endl;

    int i = 0;
    for (int saida = 1; saida !=0; i++) {
        cout << "Código da raça: ";
        cin >> racas[i].codigo;

        cin.ignore();

        if (racas[i].codigo > 0) {
            cout << "Nome do raca: ";
            cin.getline(racas[i].descricao, 50);
        } else saida = 0;
    }
    tamanhoRaca = i-1;
}

bool ValidarCpf(char cpf[]) {
    if (strlen(cpf) != 11) return false;

    bool todosIguais = true;
    int p= 1;
    while (todosIguais && p < 11) {
        if (cpf[0] != cpf[p]) todosIguais = false;
        else p++;
    }
    if (todosIguais) return false;

    int cont = 10, soma = 0, i = 0;
    for (; cont >= 2; cont--) {
        soma += (cpf[i] - '0') * (cont);
        i++;
    }
    soma = soma * 10;
    int digito1 = soma % 11;

    digito1 = (digito1 > 9) ? 0 : digito1;

    if ((cpf[9] - '0') != digito1) {
        return false;
    }

    cont = 11, soma = 0, i = 0;
    for (; cont >= 2; cont--) {
        soma += (cpf[i] - '0') * (cont);
        i++;
    }
    soma = soma * 10;
    int digito2 = soma % 11;

    digito2 = (digito2 > 9) ? 0 : digito2;

    if ((cpf[10] - '0') != digito2) {
        return false;
    }
    return true;
}
