#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "biblioteca.h"

int main() {
    Aluno aluno = {0}; 
    aluno.hist_matricula = NULL;
    aluno.num_matriculas = 0;


    //vaeráveis para o usuário conseguir realizar as escolhas corretas, estão sendo iniciadas com um determinado "valor"
    int curso_min, curso_max;
    int curso_temp = 0; 
    int turno_temp = 0; 
    int continuar = 1;


    // Vetores de histórico
    //int turnos_matriculados[3] = {0}; 
    //int cursos_matriculados[3] = {0}; // <--- NOVO: Guarda os cursos já feitos
    
   // int num_matriculas = 0; // Mudei o nome de 'num_turnos_matriculados' para ficar mais genérico

    printf("Bem-vindo a Escola Socratica!\n_\n");

    printf("Digite o nome do aluno: ");
    fgets(aluno.nome, sizeof(aluno.nome), stdin);
    aluno.nome[strcspn(aluno.nome, "\n")] = '\0';
    
    aluno.idade = validar_inteiros("Digite sua idade: ", 1, 75);
    aluno.matricula = validar_inteiros("Digite sua matricula: ", 1, 999999);
    
    do {

        int validacao_valida = 0;
        // --- Realização da matrícula com a escolha do turno e curso ---
        do {
            printf("\nOPCOES DE TURNOS\n| 1 = MANHA | 2 = TARDE | 3 = NOITE |\n");
            turno_temp = validar_inteiros("Escolha o turno: ", MANHA, NOITE);

             // Mostra o menu dependendo do turno escolhido
            if (turno_temp == MANHA || turno_temp == TARDE) {
                printf("OPCOES DE CURSOS (Manha/Tarde)\n");
                printf("| %d = %s | %d = %s | %d = %s |\n", CURSO_1, CURSOS[CURSO_1], CURSO_2, CURSOS[CURSO_2], CURSO_3, CURSOS[CURSO_3]);
                curso_min = CURSO_1;
                curso_max = CURSO_3;
            } else {
                printf("OPCOES DE CURSOS (Noite)\n");
                printf("| %d = %s | %d = %s |\n", CURSO_4, CURSOS[CURSO_4], CURSO_5, CURSOS[CURSO_5]);
                curso_min = CURSO_4;
                curso_max = CURSO_5;
            }

            curso_temp = validar_inteiros("Escolha o curso: ", curso_min, curso_max);

           if (validar_matricula(curso_temp, turno_temp, 
                                   aluno.hist_matricula, aluno.num_matriculas)) {
                
                validacao_valida = 1; // deu certo

            } else {
                
                printf("Deseja tentar outra combinacao de curso/turno? (1 = Sim, 0 = Nao): ");
                scanf("%d", &continuar);
                while (getchar() != '\n');

                if (continuar == 0) {
                    break; // Sai do loop e segue 
                }
            }
        } while (validacao_valida == 0 && continuar != 0);

        // se der tudo certo, a matricula é "guardada"
        if (validacao_valida) {
            
            aluno.num_matriculas++; // aumenta o cont antes de guardar
            
            matricula *temp = realloc(aluno.hist_matricula, aluno.num_matriculas * sizeof(matricula));
            
            if (temp == NULL) {
                printf("\nmatricula nao salva\n");
                aluno.num_matriculas--; // tira a matrícula 
                continuar = 0;
            } else {
                aluno.hist_matricula = temp;
                
                // Salva
                int i = aluno.num_matriculas - 1;
                aluno.hist_matricula[i].cod_curso = curso_temp;
                aluno.hist_matricula[i].cod_turno = turno_temp;
                
                mostrar_dados(aluno, curso_temp);
            }
        }
        
        if (continuar != 0 && validacao_valida) { // Só pergunta se ainda estiver rodando
            printf("Deseja cadastrar outro curso? (1 = Sim, 0 = Nao): ");
            scanf("%d", &continuar);
            while (getchar() != '\n');
        }

    } while (continuar != 0);

    // Limpeza da memória
    if (aluno.hist_matricula != NULL) {
        free(aluno.hist_matricula);
    }
        
    printf("Encerrando...\n");
    return 0;
}

         