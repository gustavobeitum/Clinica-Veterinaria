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
    char data[12];
    float valor;
};

void CadastrarCidade(Cidade cidades[], int &tamanho);
void CadastrarTutor(Tutor tutores[], int &tamanhoTutor, Cidade cidades[], int tamanhoCidade);
void CadastrarVeterinario(Veterinario veterinarios[], int &tamanhoVeterinario, Cidade cidades[], int tamanhoCidade);
void CadastrarRaca(Raca racas[], int &tamanhoRaca);
void CadastrarAnimal(Animal animais[], int &tamanhoAnimal, Raca racas[], int tamanhoRaca, Tutor tutores[], int tamanhoTutor, Cidade cidades[], int tamanhoCidade);
void CadastrarConsulta(Consulta consultas[], int &tamanhoConsulta, Animal animais[], int tamanhoAnimal, Veterinario veterinarios[], int tamanhoVeterinario);

bool BuscarCidade (Cidade cidades[], int tamanhoCidade, int &cod);
bool BuscarRaca (Raca racas[], int tamanhoraca, int &cod);
bool BuscarTutor (Tutor tutores[], int tamanhoTutor, int &cod);
bool BuscarAnimal (Animal animais[], int tamanhoAnimal, int &cod);
bool BuscarVeterinario (Veterinario veterinarios[], int tamanhoVeterinario, int &cod);

void InserirTutor (Tutor tutores[], int &tamanhoTutor, Tutor inserirTutores[], int tamanhoInserirTutor, Tutor tutoresAtualizada[], int &tamanhoAtualizadaTutor);
void InserirAnimais(Animal animais[], int &tamanhoAnimal, Animal inserirAnimal[], int tamanhoInserirAnimal, Animal animaisAtualizada[], int &tamanhoAtualizadaAnimal);
void InserirConsulta(Consulta consultas[], int &tamanhoConsulta, Animal animais[], int tamanhoAnimal, Veterinario veterinarios[], int tamanhoVeterinario, Raca racas[], int tamanhoRaca, Cidade cidades[], int tamanhoCidade, Tutor tutores[], int tamanhoTutor);

bool ValidarCpf(char cpf[]);

void Menu();

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int max = 1000;
    //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\\
    //1
    int tamanhoCidade = 2;
    Cidade cidades[max];
    cidades[0] = {1, "Assis", "SP"};
    cidades[1]  = {2, "Londrina", "PR"};
    //CadastrarCidade(cidades, tamanhoCidade);
    //2
    int tamanhoTutor = 2;
    Tutor tutores[max];
    tutores[0] = {1, "Gustavo", "52911693892", "Rua A", 1};
    tutores[1] = {2, "Artur", "52911693892", "Rua B", 2};
    //CadastrarTutor(tutores, tamanhoTutor, cidades, tamanhoCidade);
    //3
    int tamanhoVeterinario = 2;
    Veterinario veterinarios[max];
    veterinarios[0] = {1, "Caio", "Rua B", 2};
    veterinarios[1] = {2, "Eduardo", "Rua V", 1};
    //CadastrarVeterinario(veterinarios, tamanhoVeterinario, cidades, tamanhoCidade);
    //4
    int tamanhoRaca = 2;
    Raca racas[max];
    racas[0] = {1, "Basset"};
    racas[1] = {2, "BlueHiller"};
    //CadastrarRaca(racas, tamanhoRaca);
    //5
    int tamanhoAnimal = 2;
    Animal animais[max];
    animais[0] = {1, "Ted", 1,11,12,1};
    animais[1] = {2, "Apollo", 2,1,17,1};
    //CadastrarAnimal(animais, tamanhoAnimal, racas, tamanhoRaca, tutores, tamanhoTutor, cidades, tamanhoCidade);
    //6
    int tamanhoConsulta = 2;
    Consulta consultas[max];
    consultas[0] = {1, 1,1, "1505", 150};
    consultas[1] = {2, 2,2, "1405", 200};
    //RegistrarConsulta(consultas, tamanhoConsulta, animais, tamanhoAnimal, veterinarios, tamanhoVeterinario);
    //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\\

    int opcao = 0;


    while (opcao != 4) {
        Menu();
        cin >> opcao;
        switch(opcao) {
            case 1: {
                int tamanhoInserirTutor;
                Tutor inserirTutores[max];
                CadastrarTutor(inserirTutores, tamanhoInserirTutor, cidades, tamanhoCidade);

                int tamanhoAtualizadaTutor;
                Tutor tutoresAtualizada[tamanhoTutor + tamanhoInserirTutor];
                InserirTutor(tutores, tamanhoTutor, inserirTutores, tamanhoInserirTutor, tutoresAtualizada, tamanhoAtualizadaTutor);

                break;
            }

            case 2: {
                int tamanhoInserirAnimal;
                Animal inserirAnimal[max];
                CadastrarAnimal(inserirAnimal, tamanhoInserirAnimal, racas, tamanhoRaca, tutores, tamanhoTutor, cidades, tamanhoCidade);

                int tamanhoAtualizadaAnimal;
                Animal animaisAtualizada[tamanhoAnimal + tamanhoInserirAnimal];
                InserirAnimais(animais, tamanhoAnimal, inserirAnimal, tamanhoInserirAnimal, animaisAtualizada,  tamanhoAtualizadaAnimal);

                break;
            }

            case 3: {
                InserirConsulta(consultas, tamanhoConsulta, animais, tamanhoAnimal, veterinarios, tamanhoVeterinario, racas, tamanhoRaca, cidades, tamanhoCidade, tutores, tamanhoTutor);
                break;
            }

            case 4: {
                system("cls");
                cout << "Saindo do programa...\n";
            }
            break;

            default: {
                system("cls");
                cout << "Opção inválida. Tente novamente.\n";
            }
        }
    }
    return 0;
}

void Menu() {
    system("cls");
    cout << "\n===== MENU PRINCIPAL =====\n";
    cout << "1. Adicionar novo Tutor\n";
    cout << "2. Adicionar novo Animal\n";
    cout << "3. Cadastrar nova Consulta\n";
    cout << "4. Sair\n";
    cout << "Escolha uma opção: ";
}

void CadastrarCidade(Cidade cidades[], int &tamanhoCidade) {
    system("cls");
    cout<<"\n\nCadastrar Cidades (Para finalizar os cadastros, digite 0 no campo código): "<<endl;
    int i = 0;
    int codigo;
    for (int saida = 1; saida !=0; i++) {
        cout<<"\nCódigo da cidade: ";
        cin>>codigo;

        cin.ignore();

        if (codigo > 0) {
            cidades[i].codigo = codigo;

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
    system("cls");
    cout << "\n\nCadastrar Tutores (Para finalizar os cadastros, digite 0 no campo código): "<<endl;

    int i = 0;
    int codigo;
    for (int saida = 1; saida !=0; i++) {
        cout << "\nCódigo do tutor: ";
        cin >> codigo;

        cin.ignore();

        if (codigo > 0) {
            tutores[i].codigo = codigo;

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
                cout << "Código da cidade: ";
                cin>>codigoAux;
                verificador = BuscarCidade(cidades, tamanhoCidade, codigoAux);
            }
            tutores[i].codigoCidade = cidades[codigoAux].codigo;
            cout << "Cidade: "<<cidades[codigoAux].nome<<endl;
            cout << "UF: "<<cidades[codigoAux].uf<<endl;
        }else {
            saida = 0;
        }
    }
    tamanhoTutor = i-1;
}

void CadastrarVeterinario(Veterinario veterinarios[], int &tamanhoVeterinario, Cidade cidades[], int tamanhoCidade) {
    system("cls");
    cout << "\n\nCadastrar Veterinários (Para finalizar os cadastros, digite 0 no campo código): "<<endl;

    int i = 0;
    int codigo;
    for (int saida = 1; saida !=0; i++) {
        cout << "\nCódigo do veterinário: ";
        cin >> codigo;

        cin.ignore();

        if (codigo > 0) {
            veterinarios[i].codigo = codigo;

            cout << "Nome do veterinário: ";
            cin.getline(veterinarios[i].nome, 70);

            cout << "Endereço: ";
            cin.getline(veterinarios[i].endereco, 90);

            int codigoAux;
            bool verificador = false;

            while (!verificador) {
                cout << "Código da cidade: ";
                cin >> codigoAux;
                verificador = BuscarCidade(cidades, tamanhoCidade, codigoAux);
            }
            veterinarios[i].codigoCidade = cidades[codigoAux].codigo;
        }else saida = 0;
    }
    tamanhoVeterinario = i-1;
}

void CadastrarRaca(Raca racas[], int &tamanhoRaca) {
    system("cls");
    cout << "\n\nCadastrar Raças (Para finalizar os cadastros, digite 0 no campo código): "<<endl;

    int i = 0;
    int codigo;
    for (int saida = 1; saida !=0; i++) {
        cout << "\nCódigo da raça: ";
        cin >> codigo;

        cin.ignore();

        if (codigo > 0) {
            racas[i].codigo = codigo;
            cout << "Nome do raça: ";
            cin.getline(racas[i].descricao, 50);
        } else saida = 0;
    }
    tamanhoRaca = i-1;
}

void CadastrarAnimal(Animal animais[], int &tamanhoAnimal, Raca racas[], int tamanhoRaca, Tutor tutores[], int tamanhoTutor, Cidade cidades[], int tamanhoCidade) {
    system("cls");
    cout << "\n\nCadastrar Animais (Para finalizar os cadastros, digite 0 no campo código): "<<endl;

    int i = 0;
    int codigo;
    for (int saida = 1; saida !=0; i++) {
        cout << "\nCódigo do animal: ";
        cin >> codigo;

        cin.ignore();

        if (codigo > 0) {
            animais[i].codigo = codigo;
            cout << "Nome do animal: ";
            cin.getline(animais[i].nome, 30);

            int codigoAux;
            bool verificador = false;

            while (!verificador) {
                cout << "Código da raça: ";
                cin>>codigoAux;
                verificador = BuscarRaca(racas, tamanhoRaca, codigoAux);
            }
            animais[i].codigoRaca = racas[codigoAux].codigo;
            cout << "Raça: " << racas[codigoAux].descricao << endl;

            cout << "Idade do animal: ";
            cin >> animais[i].idade;

            cout << "Peso do animal: ";
            cin >> animais[i].peso;

            cin.ignore();

            verificador = false;

            while (!verificador) {
                cout << "Código do tutor: ";
                cin>>codigoAux;
                verificador = BuscarTutor(tutores, tamanhoTutor, codigoAux);
            }
            animais[i].codigoTutor = tutores[codigoAux].codigo;
            cout << "Tutor:  " << tutores[codigoAux].nome<<endl;

            verificador = false;

            while (!verificador) {
                codigoAux = tutores[codigoAux].codigoCidade;
                verificador = BuscarCidade(cidades, tamanhoCidade, codigoAux);
            }
            cout << "Cidade: "<< cidades[codigoAux].nome<<endl;
        } else saida = 0;
    }
    tamanhoAnimal = i-1;
}

void CadastrarConsulta(Consulta consultas[], int &tamanhoConsulta, Animal animais[], int tamanhoAnimal, Veterinario veterinarios[], int tamanhoVeterinario) {
    system("cls");
    cout << "\n\nRegistrar Consulta (Para finalizar os registros, digite 0 no campo código): "<<endl;

    int i = 0;
    int codigo;
    for (int saida = 1; saida !=0; i++) {
        cout << "\nCódigo da consulta: ";
        cin >> codigo;

        cin.ignore();

        if (codigo > 0) {
            consultas[i].codigo = codigo;

            int codigoAux;
            bool verificador = false;

            while (!verificador) {
                cout << "Código do animal: ";
                cin>>codigoAux;
                verificador = BuscarAnimal(animais, tamanhoAnimal, codigoAux);
            }
            consultas[i].codigoAnimal = animais[codigoAux].codigo;

            verificador = false;

            while (!verificador) {
                cout << "Código do veterinário: ";
                cin>>codigoAux;
                verificador = BuscarVeterinario(veterinarios, tamanhoVeterinario, codigoAux);
            }
            consultas[i].codigoVeterinario = veterinarios[codigoAux].codigo;

            cin.ignore();

            cout << "Data da consulta: ";
            cin.getline(consultas[i].data, 12);

            cout << "Valor: ";
            cin >> consultas[i].valor;

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

void InserirTutor (Tutor tutores[], int &tamanhoTutor, Tutor inserirTutores[], int tamanhoInserirTutor, Tutor tutoresAtualizada[], int &tamanhoAtualizadaTutor){
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

    i = 0;
    while (i < tamanhoAtualizadaTutor) {
        tutores[i].codigo = tutoresAtualizada[i].codigo;
        strcpy (tutores[i].nome,tutoresAtualizada[i].nome);
        strcpy (tutores[i].cpf,tutoresAtualizada[i].cpf);
        strcpy (tutores[i].endereco,tutoresAtualizada[i].endereco);
        tutores[i].codigoCidade = tutoresAtualizada[i].codigoCidade;
        i++;
    }
    tamanhoTutor = tamanhoAtualizadaTutor;
}

void InserirAnimais(Animal animais[], int &tamanhoAnimal, Animal inserirAnimal[], int tamanhoInserirAnimal, Animal animaisAtualizada[], int &tamanhoAtualizadaAnimal) {
    int i = 0, j = 0, k = 0;
    for (; i < tamanhoAnimal && j < tamanhoInserirAnimal; k++) {
        if (animais[i].codigo < inserirAnimal[j].codigo) {
            animaisAtualizada[k].codigo = animais[i].codigo;
            strcpy (animaisAtualizada[k].nome,animais[i].nome);
            animaisAtualizada[k].codigoRaca = animais[i].codigoRaca;
            animaisAtualizada[k].idade = animais[i].idade;
            animaisAtualizada[k].peso = animais[i].peso;
            animaisAtualizada[k].codigoTutor = animais[i].codigoTutor;
            i++;
        }
        else {
            animaisAtualizada[k].codigo = inserirAnimal[j].codigo;
            strcpy (animaisAtualizada[k].nome,inserirAnimal[j].nome);
            animaisAtualizada[k].codigoRaca = inserirAnimal[j].codigoRaca;
            animaisAtualizada[k].idade = inserirAnimal[j].idade;
            animaisAtualizada[k].peso = inserirAnimal[j].peso;
            animaisAtualizada[k].codigoTutor = inserirAnimal[j].codigoTutor;
            j++;
        }
    }
    while (i < tamanhoAnimal){
        animaisAtualizada[k].codigo = animais[i].codigo;
        strcpy (animaisAtualizada[k].nome,animais[i].nome);
        animaisAtualizada[k].codigoRaca = animais[i].codigoRaca;
        animaisAtualizada[k].idade = animais[i].idade;
        animaisAtualizada[k].peso = animais[i].peso;
        animaisAtualizada[k].codigoTutor = animais[i].codigoTutor;
        i++;
        k++;
    }
    while (j < tamanhoInserirAnimal){
        animaisAtualizada[k].codigo = inserirAnimal[j].codigo;
        strcpy (animaisAtualizada[k].nome,inserirAnimal[j].nome);
        animaisAtualizada[k].codigoRaca = inserirAnimal[j].codigoRaca;
        animaisAtualizada[k].idade = inserirAnimal[j].idade;
        animaisAtualizada[k].peso = inserirAnimal[j].peso;
        animaisAtualizada[k].codigoTutor = inserirAnimal[j].codigoTutor;
        j++;
        k++;
    }
    tamanhoAtualizadaAnimal = k;

    i = 0;
    while (i < tamanhoAtualizadaAnimal) {
        animais[i].codigo = animaisAtualizada[i].codigo;
        animais[i].codigoRaca = animaisAtualizada[i].codigoRaca;
        animais[i].idade = animaisAtualizada[i].idade;
        animais[i].peso = animaisAtualizada[i].peso;
        animais[i].codigoTutor = animaisAtualizada[i].codigoTutor;
        i++;
    }
    tamanhoAnimal = tamanhoAtualizadaAnimal;
}

void InserirConsulta(Consulta consultas[], int &tamanhoConsulta, Animal animais[], int tamanhoAnimal, Veterinario veterinarios[], int tamanhoVeterinario, Raca racas[], int tamanhoRaca, Cidade cidades[], int tamanhoCidade, Tutor tutores[], int tamanhoTutor) {
    if (tamanhoConsulta == 0) {
        consultas[tamanhoConsulta].codigo = 1;
    } else {
        consultas[tamanhoConsulta].codigo = consultas[tamanhoConsulta - 1].codigo + 1;
    }

    int codigoAux;
    bool verificador = false;

    while (!verificador) {
        cout << "Código do animal: ";
        cin>>codigoAux;
        verificador = BuscarAnimal(animais, tamanhoAnimal, codigoAux);
    }
    consultas[tamanhoConsulta].codigoAnimal = animais[codigoAux].codigo;

    cout << "Nome do animal: " << animais[codigoAux].nome;
    int codAnimal = codigoAux;

    verificador = false;

    while (!verificador) {
        codigoAux = animais[codigoAux].codigoRaca;
        verificador = BuscarRaca(racas, tamanhoRaca, codigoAux);
    }
    cout << "Raça: " << racas[codigoAux].descricao << endl;

    verificador = false;

    while (!verificador) {
        codigoAux = animais[codAnimal].codigoTutor;
        verificador = BuscarTutor(tutores, tamanhoTutor, codigoAux);
    }
    cout << "Nome do tutor: " << tutores[codigoAux].nome << endl;

    verificador = false;

    while (!verificador) {
        cout << "Código do veterinário: ";
        cin>>codigoAux;
        verificador = BuscarVeterinario(veterinarios, tamanhoVeterinario, codigoAux);
    }
    consultas[tamanhoConsulta].codigoVeterinario = veterinarios[codigoAux].codigo;

    verificador = false;

    while (!verificador) {
        codigoAux = veterinarios[codigoAux].codigoCidade;
        verificador = BuscarCidade(cidades, tamanhoCidade, codigoAux);
    }
    cout << "Cidade do veterinário: " << cidades[codigoAux].nome << endl;

    cin.ignore();

    cout << "Data da consulta: ";
    cin.getline(consultas[tamanhoConsulta].data, 12);

    cout << "Valor: ";
    cin >> consultas[tamanhoConsulta].valor;

    tamanhoConsulta++;
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
