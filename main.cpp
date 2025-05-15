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

struct Consulta {
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
void CadastrarAnimal(Animal animais[], int &tamanhoAnimal, Raca racas[], int tamanhoRaca, Tutor tutores[], int tamanhoTutor);
void RegistrarConsulta(Consulta consultas[], int &tamanhoConsulta, Animal animais[], int tamanhoAnimal, Veterinario veterinarios[], int tamanhoVeterinario);
bool BuscarCidade (Cidade cidades[], int tamanhoCidade, int cod);
bool BuscarRaca (Raca racas[], int tamanhoraca, int cod);
bool BuscarTutor (Tutor tutores[], int tamanhoTutor, int cod);
bool BuscarAnimal (Animal animais[], int tamanhoAnimal, int cod);
bool BuscarVeterinario (Veterinario veterinarios[], int tamanhoVeterinario, int cod);
void InserirTutor (Tutor tutores[], int tamanhoTutor, Tutor inserirTutores[], int tamanhoInserirTutor, Tutor tutoresAtualizada[], int &tamanhoAtualizadaTutor);
bool ValidarCpf(char cpf[]);

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int max = 100;
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

    int tamanhoAnimal;
    Animal animais[max];
    CadastrarAnimal(animais, tamanhoAnimal, racas, tamanhoRaca, tutores, tamanhoTutor);

    int tamanhoConsulta;
    Consulta consultas[max];
    RegistrarConsulta(consultas, tamanhoConsulta, animais, tamanhoAnimal, veterinarios, tamanhoVeterinario);

    int tamanhoInserirTutor;
    Tutor inserirTutores[max];
    CadastrarTutor(inserirTutores, tamanhoInserirTutor, cidades, tamanhoCidade);

    int tamanhoAtualizadaTutor;
    Tutor tutoresAtualizada[tamanhoTutor + tamanhoInserirTutor];
    InserirTutor(tutores, tamanhoTutor, inserirTutores, tamanhoInserirTutor, tutoresAtualizada, tamanhoAtualizadaTutor);

    return 0;
}

void CadastrarCidade(Cidade cidades[], int &tamanhoCidade) {
    cout<<"\nCadastrar Cidades (Para finalizar os cadastros, digite 0 no campo código): "<<endl;
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
    tamanhoCidade = i-1;
}

void CadastrarTutor(Tutor tutores[], int &tamanhoTutor, Cidade cidades[], int tamanhoCidade) {
    cout << "\nCadastrar Tutores (Para finalizar os cadastros, digite 0 no campo código): "<<endl;

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

            int codigoAux;
            bool verificador = false;

            while (!verificador) {
                cout << "\nCódigo da cidade: ";
                cin>>codigoAux;
                verificador = BuscarCidade(cidades, tamanhoCidade, codigoAux);
            }
            tutores[i].codigoCidade = cidades[codigoAux].codigo;
        }else saida = 0;
    }
    tamanhoTutor = i-1;
}

void CadastrarVeterinario(Veterinario veterinarios[], int &tamanhoVeterinario, Cidade cidades[], int tamanhoCidade) {
    cout << "\nCadastrar Veterinários (Para finalizar os cadastros, digite 0 no campo código): "<<endl;

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

            int codigoAux;
            bool verificador = false;

            while (!verificador) {
                cout << "\nCódigo da cidade: ";
                cin>>codigoAux;
                verificador = BuscarCidade(cidades, tamanhoCidade, codigoAux);
            }
            veterinarios[i].codigoCidade = cidades[codigoAux].codigo;
        }else saida = 0;
    }
    tamanhoVeterinario = i-1;
}

void CadastrarRaca(Raca racas[], int &tamanhoRaca) {
    cout << "\nCadastrar Raças (Para finalizar os cadastros, digite 0 no campo código): "<<endl;

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

void CadastrarAnimal(Animal animais[], int &tamanhoAnimal, Raca racas[], int tamanhoRaca, Tutor tutores[], int tamanhoTutor) {
    cout << "\nCadastrar Animais (Para finalizar os cadastros, digite 0 no campo código): "<<endl;

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
            animais[i].codigoRaca = racas[codigoAux].codigo;

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
            animais[i].codigoTutor = tutores[codigoAux].codigo;
        } else saida = 0;
    }
    tamanhoAnimal = i-1;
}

void RegistrarConsulta(Consulta consultas[], int &tamanhoConsulta, Animal animais[], int tamanhoAnimal, Veterinario veterinarios[], int tamanhoVeterinario) {
    cout << "\nRegistrar Consulta (Para finalizar os registros, digite 0 no campo código): "<<endl;

    int i = 0;
    for (int saida = 1; saida !=0; i++) {
        cout << "Código da consulta: ";
        cin >> consultas[i].codigo;

        cin.ignore();

        if (consultas[i].codigo > 0) {

            int codigoAux;
            bool verificador = false;

            while (!verificador) {
                cout << "\nCódigo do animal: ";
                cin>>codigoAux;
                verificador = BuscarAnimal(animais, tamanhoAnimal, codigoAux);
            }
            animais[i].codigoRaca = animais[codigoAux].codigo;

            verificador = false;

            while (!verificador) {
                cout << "\nCódigo do veterinário: ";
                cin>>codigoAux;
                verificador = BuscarVeterinario(veterinarios, tamanhoVeterinario, codigoAux);
            }
            animais[i].codigoRaca = veterinarios[codigoAux].codigo;


        }else saida = 0;
    }
    tamanhoConsulta = i-1;
}

bool BuscarCidade (Cidade cidades[], int tamanhoCidade, int &cod){
    int i = 0, f = tamanhoCidade;
    int m = (i + f) / 2;
    for (; f > i && cod != cidades[m].codigo; m = (i + f) / 2){
        if (cod > cidades[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == cidades[m].codigo) {
        cod = m;
        return true;
    }
    else {
        cout << "Código inválido, insira um código válido.\n";
        return false;
    }
}

bool BuscarRaca (Raca racas[], int tamanhoraca, int &cod){
    int i = 0, f = tamanhoraca;
    int m = (i + f) / 2;
    for (; f > i && cod != racas[m].codigo; m = (i + f) / 2){
        if (cod > racas[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == racas[m].codigo) {
        cod = m;
        return true;
    }
    else {
        cout << "Código inválido, insira um código válido.\n";
        return false;
    }
}

bool BuscarTutor (Tutor tutores[], int tamanhoTutor, int &cod){
    int i = 0, f = tamanhoTutor;
    int m = (i + f) / 2;
    for (; f > i && cod != tutores[m].codigo; m = (i + f) / 2){
        if (cod > tutores[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == tutores[m].codigo) {
        cod = m;
        return true;
    }
    else {
        cout << "Código inválido, insira um código válido.\n";
        return false;
    }
}

bool BuscarAnimal (Animal animais[], int tamanhoAnimal, int &cod) {
    int i = 0, f = tamanhoAnimal;
    int m = (i + f) / 2;
    for (; f > i && cod != animais[m].codigo; m = (i + f) / 2){
        if (cod > animais[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == animais[m].codigo) {
        cod = m;
        return true;
    }
    else {
        cout << "Código inválido, insira um código válido.\n";
        return false;
    }
}

bool BuscarVeterinario (Veterinario veterinarios[], int tamanhoVeterinario, int &cod) {
    int i = 0, f = tamanhoVeterinario;
    int m = (i + f) / 2;
    for (; f > i && cod != veterinarios[m].codigo; m = (i + f) / 2){
        if (cod > veterinarios[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == veterinarios[m].codigo) {
        cod = m;
        return true;
    }
    else {
        cout << "Código inválido, insira um código válido.\n";
        return false;
    }
}

void InserirTutor (Tutor tutores[], int tamanhoTutor, Tutor inserirTutores[], int tamanhoInserirTutor, Tutor tutoresAtualizada[], int &tamanhoAtualizadaTutor){
    int i = 0, j = 0, k = 0;
    for (;i < tamanhoTutor && j < tamanhoInserirTutor;k++){
        if (tutores[i].codigo < inserirTutores[j].codigo){
            tutoresAtualizada[k].codigo = tutores[i].codigo;
            strcpy (tutoresAtualizada[k].nome,tutores[i].nome);
            strcpy (tutoresAtualizada[k].cpf,tutores[i].cpf);
            strcpy (tutoresAtualizada[k].endereco,tutores[i].endereco);
            tutoresAtualizada[k].codigoCidade = tutores[i].codigoCidade;
            i++;
        }
        else {
            tutoresAtualizada[k].codigo = inserirTutores[j].codigo;
            strcpy (tutoresAtualizada[k].nome,inserirTutores[j].nome);
            strcpy (tutoresAtualizada[k].cpf,inserirTutores[j].cpf);
            strcpy (tutoresAtualizada[k].endereco,inserirTutores[j].endereco);
            tutoresAtualizada[k].codigoCidade = inserirTutores[j].codigoCidade;
            j++;
        }
    }
    while (i < tamanhoTutor){
        tutoresAtualizada[k].codigo = tutores[i].codigo;
        strcpy (tutoresAtualizada[k].nome,tutores[i].nome);
         strcpy (tutoresAtualizada[k].cpf,tutores[i].cpf);
         strcpy (tutoresAtualizada[k].endereco,tutores[i].endereco);
         tutoresAtualizada[k].codigoCidade = tutores[i].codigoCidade;
         i++;
         k++;
     }
    while (j < tamanhoInserirTutor){
         tutoresAtualizada[k].codigo = inserirTutores[j].codigo;
         strcpy (tutoresAtualizada[k].nome,inserirTutores[j].nome);
         strcpy (tutoresAtualizada[k].cpf,inserirTutores[j].cpf);
         strcpy (tutoresAtualizada[k].endereco,inserirTutores[j].endereco);
         tutoresAtualizada[k].codigoCidade = inserirTutores[j].codigoCidade;
         j++;
         k++;
    }
    tamanhoAtualizadaTutor = k;
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
