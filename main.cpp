#include<iostream>
#include<string>
#include<conio.h>
#include <windows.h>
#include <cstring>
#include <cstdlib>

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
bool BuscarConsulta (Consulta consultas[], int tamanhoConsulta, int &cod);

void InserirTutor (Tutor tutores[], int &tamanhoTutor, Tutor inserirTutores[], int tamanhoInserirTutor, Tutor tutoresAtualizada[], int &tamanhoAtualizadaTutor);
void InserirAnimais(Animal animais[], int &tamanhoAnimal, Animal inserirAnimal[], int tamanhoInserirAnimal, Animal animaisAtualizada[], int &tamanhoAtualizadaAnimal);
void InserirConsulta(Consulta consultas[], int &tamanhoConsulta, Animal animais[], int tamanhoAnimal, Veterinario veterinarios[], int tamanhoVeterinario, Raca racas[], int tamanhoRaca, Cidade cidades[], int tamanhoCidade, Tutor tutores[], int tamanhoTutor);

void PesquisarConsultaPorData(Consulta consultas[], int tamanhoConsulta, Animal animais[], int tamanhoAnimal, Veterinario veterinarios[], int tamanhoVeterinario);

bool ValidarCpf(char cpf[]);

void Menu();

int main() {
    SetConsoleOutputCP(CP_UTF8);

    int max = 50;
    //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\\
    //1
    int tamanhoCidade;
    Cidade cidades[max];
    CadastrarCidade(cidades, tamanhoCidade);
    //2
    int tamanhoTutor;
    Tutor tutores[max];
	CadastrarTutor(tutores, tamanhoTutor, cidades, tamanhoCidade);
    //3
    int tamanhoVeterinario;
    Veterinario veterinarios[max];
	CadastrarVeterinario(veterinarios, tamanhoVeterinario, cidades, tamanhoCidade);
    //4
    int tamanhoRaca;
    Raca racas[max];
	CadastrarRaca(racas, tamanhoRaca);
    //5
    int tamanhoAnimal;
    Animal animais[max];
	CadastrarAnimal(animais, tamanhoAnimal, racas, tamanhoRaca, tutores, tamanhoTutor, cidades, tamanhoCidade);
    //6
    int tamanhoConsulta;
    Consulta consultas[max];
	CadastrarConsulta(consultas, tamanhoConsulta, animais, tamanhoAnimal, veterinarios, tamanhoVeterinario);
    //-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\\

    int opcao = 0;


    while (opcao != 5) {
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
                PesquisarConsultaPorData(consultas, tamanhoConsulta,animais, tamanhoAnimal, veterinarios, tamanhoVeterinario);
                break;
            }

            case 5: {
                system("cls");
                cout << "Saindo do programa...\n";
                break;
            }

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
    cout << "4. Pesquisar Consulta por Data\n";
    cout << "5. Sair\n";
    cout << "Escolha uma opção: ";
}

void CadastrarCidade(Cidade cidades[], int &tamanhoCidade) {
    system("cls");
    cout<<"\t------Cadastrar Cidades------ \n(Para finalizar os cadastros, digite 0 no campo código): "<<endl;
    int i = 0;
    int codigo;
    for (int saida = 1; saida !=0; i++) {

        int codigoAux;
        bool verificador = false;

        while (!verificador) {
            cout<<"Código da cidade: ";
            cin>>codigo;
            codigoAux = codigo;
            if (BuscarCidade(cidades, tamanhoCidade, codigoAux) && codigo > 0) {
                cout << "Código já utilizado, por favor insira um código não utilizado." << endl;
                cout << "\n";
            } else verificador = true;
        }

        cin.ignore();

        if (codigo > 0) {
            cidades[i].codigo = codigo;

            cout<<"Cidade: ";
            cin.getline(cidades[i].nome, 70);

            cout<<"UF: ";
            cin.getline(cidades[i].uf, 3);
            cout<<"\n";
        }else {
            saida = 0;
        }
    }
    tamanhoCidade = i-1;
}

void CadastrarTutor(Tutor tutores[], int &tamanhoTutor, Cidade cidades[], int tamanhoCidade) {
    system("cls");
    cout << "\t------Cadastrar Tutores------ \n(Para finalizar os cadastros, digite 0 no campo código): "<<endl;

    int i = 0;
    int codigo;
    for (int saida = 1; saida !=0; i++) {

        int codigoAux;
        bool verificador = false;

        while (!verificador) {
            cout<<"Código de tutor: ";
            cin>>codigo;
            codigoAux = codigo;
            if (BuscarTutor(tutores, tamanhoTutor, codigoAux) && codigo > 0) {
                cout << "\nCódigo já utilizado, por favor insira um código não utilizado." << endl;
                cout << "\n";
            } else verificador = true;
        }

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

            verificador = false;

            while (!verificador) {
                cout << "Código da cidade: ";
                cin>>codigoAux;
                verificador = BuscarCidade(cidades, tamanhoCidade, codigoAux);
                if (!verificador) cout << "\nCódigo inválido, insira um código válido.\n";
            }
            tutores[i].codigoCidade = cidades[codigoAux].codigo;
            cout << "Cidade: "<<cidades[codigoAux].nome<<endl;
            cout << "UF: "<<cidades[codigoAux].uf<<endl;

            cout<<"\n";
        }else {
            saida = 0;
        }
    }
    tamanhoTutor = i-1;
}

void CadastrarVeterinario(Veterinario veterinarios[], int &tamanhoVeterinario, Cidade cidades[], int tamanhoCidade) {
    system("cls");
    cout << "\t------Cadastrar Veterinários------ \n(Para finalizar os cadastros, digite 0 no campo código): "<<endl;

    int i = 0;
    int codigo;
    for (int saida = 1; saida !=0; i++) {

        int codigoAux;
        bool verificador = false;

        while (!verificador) {
            cout<<"Código do veterinario: ";
            cin>>codigo;
            codigoAux = codigo;
            if (BuscarVeterinario(veterinarios, tamanhoVeterinario, codigoAux) && codigo > 0) {
                cout << "\nCódigo já utilizado, por favor insira um código não utilizado." << endl;
                cout << "\n";
            } else verificador = true;
        }

        cin.ignore();

        if (codigo > 0) {
            veterinarios[i].codigo = codigo;

            cout << "Nome do veterinário: ";
            cin.getline(veterinarios[i].nome, 70);

            cout << "Endereço: ";
            cin.getline(veterinarios[i].endereco, 90);

            verificador = false;

            while (!verificador) {
                cout << "Código da cidade: ";
                cin >> codigoAux;
                verificador = BuscarCidade(cidades, tamanhoCidade, codigoAux);
                if (!verificador) cout << "\nCódigo inválido, insira um código válido.\n";
            }
            veterinarios[i].codigoCidade = cidades[codigoAux].codigo;
            cout << "\n";
        }else saida = 0;
    }
    tamanhoVeterinario = i-1;
}

void CadastrarRaca(Raca racas[], int &tamanhoRaca) {
    system("cls");
    cout << "\t------Cadastrar Raças------ \n(Para finalizar os cadastros, digite 0 no campo código): "<<endl;

    int i = 0;
    int codigo;
    for (int saida = 1; saida !=0; i++) {

        int codigoAux;
        bool verificador = false;

        while (!verificador) {
            cout<<"Código da raça: ";
            cin>>codigo;
            codigoAux = codigo;
            if (BuscarRaca(racas, tamanhoRaca, codigoAux) && codigo > 0) {
                cout << "\nCódigo já utilizado, por favor insira um código não utilizado." << endl;
                cout << "\n";
            } else verificador = true;
        }

        cin.ignore();

        if (codigo > 0) {
            racas[i].codigo = codigo;
            cout << "Nome do raça: ";
            cin.getline(racas[i].descricao, 50);
            cout<<"\n";
        } else saida = 0;
    }
    tamanhoRaca = i-1;
}

void CadastrarAnimal(Animal animais[], int &tamanhoAnimal, Raca racas[], int tamanhoRaca, Tutor tutores[], int tamanhoTutor, Cidade cidades[], int tamanhoCidade) {
    system("cls");
    cout << "\t------Cadastrar Animais------ \n(Para finalizar os cadastros, digite 0 no campo código): "<<endl;

    int i = 0;
    int codigo;
    for (int saida = 1; saida !=0; i++) {

        int codigoAux;
        bool verificador = false;

        while (!verificador) {
            cout<<"Código do animal: ";
            cin>>codigo;
            codigoAux = codigo;
            if (BuscarAnimal(animais, tamanhoAnimal, codigoAux) && codigo > 0) {
                cout << "\nCódigo já utilizado, por favor insira um código não utilizado." << endl;
                cout << "\n";
            } else verificador = true;
        }

        cin.ignore();

        if (codigo > 0) {
            animais[i].codigo = codigo;
            cout << "Nome do animal: ";
            cin.getline(animais[i].nome, 30);

            verificador = false;

            while (!verificador) {
                cout << "Código da raça: ";
                cin>>codigoAux;
                verificador = BuscarRaca(racas, tamanhoRaca, codigoAux);
                if (!verificador) cout << "\nCódigo inválido, insira um código válido.\n";
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
                if (!verificador) cout << "\nCódigo inválido, insira um código válido.\n";
            }
            animais[i].codigoTutor = tutores[codigoAux].codigo;
            cout << "Tutor:  " << tutores[codigoAux].nome<<endl;

            verificador = false;

            while (!verificador) {
                codigoAux = tutores[codigoAux].codigoCidade;
                verificador = BuscarCidade(cidades, tamanhoCidade, codigoAux);
            }
            cout << "Cidade: "<< cidades[codigoAux].nome<<endl;

            cout<<"\n";
        } else saida = 0;
    }
    tamanhoAnimal = i-1;
}

void CadastrarConsulta(Consulta consultas[], int &tamanhoConsulta, Animal animais[], int tamanhoAnimal, Veterinario veterinarios[], int tamanhoVeterinario) {
    system("cls");
    cout << "\t------Registrar Consulta------ \n(Para finalizar os registros, digite 0 no campo código): "<<endl;

    int i = 0;
    int codigo;
    for (int saida = 1; saida !=0; i++) {

        int codigoAux;
        bool verificador = false;

        while (!verificador) {
            cout<<"Código da consulta: ";
            cin>>codigo;
            codigoAux = codigo;
            if (BuscarConsulta(consultas, tamanhoConsulta, codigoAux) && codigo > 0) {
                cout << "\nCódigo já utilizado, por favor insira um código não utilizado." << endl;
                cout << "\n";
            } else verificador = true;
        }

        cin.ignore();

        if (codigo > 0) {
            consultas[i].codigo = codigo;

            verificador = false;

            while (!verificador) {
                cout << "Código do animal: ";
                cin>>codigoAux;
                verificador = BuscarAnimal(animais, tamanhoAnimal, codigoAux);
                if (!verificador) cout << "\nCódigo inválido, insira um código válido.\n";
            }
            consultas[i].codigoAnimal = animais[codigoAux].codigo;

            verificador = false;

            while (!verificador) {
                cout << "Código do veterinário: ";
                cin>>codigoAux;
                verificador = BuscarVeterinario(veterinarios, tamanhoVeterinario, codigoAux);
                if (!verificador) cout << "\nCódigo inválido, insira um código válido.\n";
            }
            consultas[i].codigoVeterinario = veterinarios[codigoAux].codigo;

            cin.ignore();

            cout << "Data da consulta (aaaa-mm- dd): ";
            cin.getline(consultas[i].data, 12);

            cout << "Valor: ";
            cin >> consultas[i].valor;

            cout<<"\n";
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
    else return false;
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
    else return false;
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
    else return false;
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
    else return false;
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
    else return false;
}

bool BuscarConsulta (Consulta consultas[], int tamanhoConsulta, int &cod) {
    int i = 0, f = tamanhoConsulta;
    int m = (i + f) / 2;
    for (; f > i && cod != consultas[m].codigo; m = (i + f) / 2){
        if (cod > consultas[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == consultas[m].codigo) {
        return true;
    }
    else return false;
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
    system("cls");
    cout << "\t------Registrar Consulta------ \n";
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
    cout << "\nRaça: " << racas[codigoAux].descricao << endl;

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

    cout << "Nome do veterinário: " << veterinarios[codigoAux].nome << endl;

    verificador = false;

    while (!verificador) {
        codigoAux = veterinarios[codigoAux].codigoCidade;
        verificador = BuscarCidade(cidades, tamanhoCidade, codigoAux);
    }
    cout << "Cidade do veterinário: " << cidades[codigoAux].nome << endl;

    cin.ignore();

    cout << "Data da consulta (aaaa-mm-dd): ";
    cin.getline(consultas[tamanhoConsulta].data, 12);

    cout << "Valor: ";
    cin >> consultas[tamanhoConsulta].valor;

    tamanhoConsulta++;
}

void PesquisarConsultaPorData(Consulta consultas[], int tamanhoConsulta, Animal animais[], int tamanhoAnimal, Veterinario veterinarios[], int tamanhoVeterinario) {

    system("cls");

    char dataInicio[12], dataFinal[12];
    float somaConsultas = 0;

    cin.ignore();

    cout << "Data de inicio (aaaa-mm-dd): ";
    cin.getline(dataInicio, 12);

    cout << "Data de final (aaaa-mm-dd): ";
    cin.getline(dataFinal, 12);

    for (int i = 0; i < tamanhoConsulta; i++) {
        if (strcmp(consultas[i].data, dataInicio) >= 0 && strcmp(consultas[i].data, dataFinal) <= 0) {

            cout << "\n\t------Dados da Consulta " << i + 1 << "------\n";
            int codigoAux =  consultas[i].codigoAnimal;
            BuscarAnimal(animais, tamanhoAnimal, codigoAux);
            cout << "Nome do animal: " << animais[codigoAux].nome << endl;

            codigoAux = consultas[i].codigoVeterinario;
            BuscarVeterinario(veterinarios, tamanhoVeterinario, codigoAux);
            cout << "Nome do veterinário: " << veterinarios[codigoAux].nome << endl;

            cout << "Data da Consulta: " <<  consultas[i].data << endl;
            cout << "Valor R$" <<  consultas[i].valor << endl;
            somaConsultas += consultas[i].valor;
        }
    }
    cout << "Valor total das consultas nesse periodo de " << dataInicio << " até " << dataFinal << " é de R$" << somaConsultas << "." << endl;
    _getch();
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
