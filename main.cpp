#include<iostream>
#include<string>
#include<conio.h>
#include <windows.h>
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

void CadastrarCidade(Cidade cidades[], int &tamanho);
void CadastrarTutor(Tutor tutores[], int &tamanhoTutor, Cidade cidades[], int tamanhoCidade);
void CadastrarVeterinario(Veterinario veterinarios[], int &tamanhoVeterinario, Cidade cidades[], int tamanhoCidade);
void CadastrarRaca(Raca racas[], int &tamanhoRaca);
bool BuscarCidade (Cidade cidades[], int tamanhoCidade, int cod);
bool BuscarRaca (Raca racas[], int tamanhoraca, int cod);
bool BuscarTutor (Tutor tutores[], int tamanhoTutor, int cod);
bool ValidarCpf(char cpf[]);

int main() {
    SetConsoleOutputCP(CP_UTF8);

    const int max = 100;
    int tamanhoCidade;
    Cidade cidades[max];
    CadastrarCidade(cidades, tamanhoCidade);

    int tamanhoTutor;
    Tutor tutores[max];
    CadastrarTutor(tutores, tamanhoTutor, cidades, tamanhoCidade);

    int tamanhoVeterinario;
    Veterinario veterinarios[max];
    CadastrarVeterinario(veterinarios, tamanhoVeterinario, cidades, tamanhoCidade);

    int tamanhoRaca;
    Raca racas[max];
    CadastrarRaca(racas, tamanhoRaca);

    return 0;
}

void CadastrarCidade(Cidade cidades[], int &tamanho) {
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

void CadastrarTutor(Tutor tutores[], int &tamanhoTutor, Cidade cidades[], int tamanhoCidade) {
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
                } else cout << "CPF inválido, insira um CPF válido.\n";
            }

            cout << "Endereço: ";
            cin.getline(tutores[i].endereco, 90);

            int codCidade;
            bool verificador = false;

            while (!verificador) {
                cout << "\nCódigo da cidade: ";
                cin>>codCidade;
                verificador = BuscarCidade(cidades, tamanhoCidade, codCidade);
            }
            tutores[i].codigoCidade = codCidade;
        }else saida = 0;
    }
    tamanhoTutor = i-1;
}

void CadastrarVeterinario(Veterinario veterinarios[], int &tamanhoVeterinario, Cidade cidades[], int tamanhoCidade) {
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

            int codCidade;
            bool verificador = false;

            while (!verificador) {
                cout << "\nCódigo da cidade: ";
                cin>>codCidade;
                verificador = BuscarCidade(cidades, tamanhoCidade, codCidade);
            }
            veterinarios[i].codigoCidade = codCidade;
        }else saida = 0;
    }
    tamanhoVeterinario = i-1;
}

void CadastrarRaca(Raca racas[], int &tamanhoRaca) {
    cout << "\nCadastrar Raças (Para finalizar o cadastro, digite 0 no campo código): "<<endl;

    int i = 0;
    for (int saida = 1; saida !=0; i++) {
        cout << "Código da raça: ";
        cin >> racas[i].codigo;

        cin.ignore();

        if (racas[i].codigo > 0) {
            cout << "Nome do raça: ";
            cin.getline(racas[i].descricao, 50);
        } else saida = 0;
    }
    tamanhoRaca = i-1;
}

void CadastrarAnimal(Animal animais[], int tamanhoAnimal, Raca racas[], int tamanhoRaca, Tutor tutores[], int tamanhoTutor) {
    cout << "\nCadastrar Animais (Para finalizar o cadastro, digite 0 no campo código): "<<endl;

    int i = 0;
    for (int saida = 1; saida !=0; i++) {
        cout << "Código do animal: ";
        cin >> animais[i].codigo;

        cin.ignore();

        if (animais[i].codigo > 0) {
            cout << "Nome do animal: ";
            cin.getline(animais[i].nome, 30);

            int codigoAux;
            bool verificador = false;

            while (!verificador) {
                cout << "\nCódigo da raça: ";
                cin>>codigoAux;
                verificador = BuscarRaca(racas, tamanhoRaca, codigoAux);
            }
            animais[i].codigoRaca = codigoAux;

            cout << "Idade do animal: ";
            cin >> animais[i].idade;

            cout << "Peso do animal: ";
            cin >> animais[i].peso;

            cin.ignore();

            verificador = false;

            while (!verificador) {
                cout << "\nCódigo da raça: ";
                cin>>codigoAux;
                verificador = BuscarTutor(tutores, tamanhoTutor, codigoAux);
            }
            animais[i].codigoTutor = codigoAux;
        } else saida = 0;
    }
    tamanhoAnimal = i-1;
}

bool BuscarCidade (Cidade cidades[], int tamanhoCidade, int cod){
    int i = 0, f = tamanhoCidade;
    int m = (i + f) / 2;
    for (; f > i && cod != cidades[m].codigo; m = (i + f) / 2){
        if (cod > cidades[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == cidades[m].codigo) return true;
    else {
        cout << "Código de cidade inválido, insira um código válido.\n";
        return false;
    }
}

bool BuscarRaca (Raca racas[], int tamanhoraca, int cod){
    int i = 0, f = tamanhoraca;
    int m = (i + f) / 2;
    for (; f > i && cod != racas[m].codigo; m = (i + f) / 2){
        if (cod > racas[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == racas[m].codigo) return true;
    else {
        cout << "Código de cidade inválido, insira um código válido.\n";
        return false;
    }
}

bool BuscarTutor (Tutor tutores[], int tamanhoTutor, int cod){
    int i = 0, f = tamanhoTutor;
    int m = (i + f) / 2;
    for (; f > i && cod != tutores[m].codigo; m = (i + f) / 2){
        if (cod > tutores[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == tutores[m].codigo) return true;
    else {
        cout << "Código de cidade inválido, insira um código válido.\n";
        return false;
    }
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
