#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

// --- ENUMS ---
enum curso { CURSO_1 = 1, CURSO_2, CURSO_3, CURSO_4, CURSO_5 };
enum turno { MANHA = 1, TARDE, NOITE };

// --- AVISOS DE VARIÁVEIS GLOBAIS (EXTERN) ---
extern char *CURSOS[];
extern char *MATERIAS[][3];

// --- STRUCTS ---
typedef struct {
    int cod_curso; 
    int cod_turno; 
} matricula; 


typedef struct {
    char nome[50];
    int idade;      // CORREÇÃO: Sem "= 0" aqui. O zero é definido no main.
    int matricula;

    matricula *hist_matricula; //pontei para matriculas 

    int num_matriculas; //-> fala quantas matriculas o aluno tem 

} Aluno;

typedef struct {
    int curso, materia;
} Curso_Materia;

// --- PROTÓTIPOS DAS FUNÇÕES ---
// A função agora recebe "Aluno a" (a struct inteira)
void mostrar_dados(Aluno a, int cod_curso);
int validar_inteiros(char *mensagem, int min_val, int max_val);
int validar_turno(int cod_turno, int turnos_do_aluno[], int n);

int validar_matricula(int novo_curso, int novo_turno, 
                               matricula hist_matricula[], int n);

#endif