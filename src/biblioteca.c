#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "biblioteca.h" //conecta com o .h

// vetores
char *CURSOS[] = {
    "",
    "Curso de Matematica",
    "Curso de Historia",
    "Curso de Literatura",
    "Curso de Filosofia",
    "Curso de Sociologia"
};

char *MATERIAS[][3] = { 
    { "", "", "" }, 
    { "Algebra", "Calculo", "Geometria" }, 
    { "Antiga", "Medieval", "Moderna" }, 
    { "Classica", "Contemporanea", "Poesia" }, 
    { "Metafisica", "Etica", "Logica" }, 
    { "Cultura", "Politica", "Economia" } 
};

//funções:

// Recebe a struct Aluno inteira
void mostrar_dados(Aluno a, int cod_curso) {
    printf("_\n");
    //acessa os dados usando ponto (.) pois 'a' é uma struct
    printf("Aluno: %s\nIdade: %d\nMatricula: %d\n", a.nome, a.idade, a.matricula);

    printf("Curso: %s (Codigo %d)\n", CURSOS[cod_curso], cod_curso);
    printf("Materias do curso:\n");

    for (int j = 0; j < 3; j++) {
        printf("- %s\n", MATERIAS[cod_curso][j]);
    }
    printf("_\n");
    printf("Aluno(a) %s matriculado(a) com sucesso!\n", a.nome);
}

// função para validar inteiros
int validar_inteiros(char *mensagem, int min_val, int max_val) {
    int valor;
    do {
        printf("%s", mensagem);
        if (scanf("%d", &valor) != 1) {
            printf("Entrada invalida! Digite um numero:\n");
            while (getchar() != '\n');
            valor = min_val - 1;
            continue;
        }
        while (getchar() != '\n'); 
        
        if (valor < min_val || valor > max_val) {
            printf("Valor invalido! Digite um numero entre %d e %d.\n", min_val, max_val);
        }
    } while (valor < min_val || valor > max_val);
    return valor;
}

//validaor de turno
int validar_turno(int cod_turno, int turnos_do_aluno[], int n) {
    for (int i = 0; i < n; i++) {
        if (turnos_do_aluno[i] == cod_turno) {
            return 1; //já está matriculado
        }
    }
    return 0;
}

//validador de curso
int validar_curso(int cod_curso, int cursos_do_aluno[], int n) {
    for (int i = 0; i < n; i++) {
        if (cursos_do_aluno[i] == cod_curso) {
            return 1; //já está matriculado 
        }
    }
    return 0;
}

//validador de matricula
int validar_matricula(int novo_curso, int novo_turno, 
                               matricula hist_matricula[], int n) {
  //Obs: se retornar 0 é porque a validação foi inválida, caso retornar 1 a validação ocorreu bem.
    
    
    for (int i = 0; i < n; i++) {
        
        //não pode fazer o mesmo curso em turno diferente.
        
        if (hist_matricula[i].cod_curso == novo_curso) {
            printf("\n Voce ja possui matricula nesse curso:  %s!\n", 
                   CURSOS[novo_curso]);
            return 0; // matrícula inválida.
        }
    //faz com que o aluno não consiga fazer mais de um curso no mesmo turno.
        if (hist_matricula[i].cod_turno == novo_turno) {
            printf("\nVoce nao pode realizar mais de um curso no mesmo turno.\n");
            return 0; //inválida
        }
    }

    return 1;  //caso dê tudo certo   
    
}