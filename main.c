#include <stdio.h>

int main() {

    float temperatura = 0;
    int energia = 0;
    int comunicacao = 1;
    int opcao;
    int dadosInseridos = 0;
    float historicoTemperaturas[5];
    int contadorHistorico = 0;

    do {
        printf("\n====================================\n");
        printf(" SISTEMA DE MONITORAMENTO ESPACIAL\n");
        printf("====================================\n");
        printf("1 - Inserir dados da missao\n");
        printf("2 - Visualizar status\n");
        printf("3 - Executar analise\n");
        printf("4 - Ver historico de temperaturas\n");
        printf("0 - Encerrar sistema\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("\n--- INSERIR DADOS ---\n");
                while (1) {
    printf("Digite a temperatura da nave: ");

    if (scanf("%f", &temperatura) == 1) {
        break;
    } else {
        printf("Valor invalido! Digite apenas numeros.\n");

        while (getchar() != '\n');
    }
}

                do {
                    printf("Digite o nivel de energia (0 a 100): ");
                    scanf("%d", &energia);
                    if (energia < 0 || energia > 100) {
                        printf("Valor invalido! Digite um valor entre 0 e 100.\n");
                    }
                } while (energia < 0 || energia > 100);

                do {
                    printf("Status da comunicacao (1 = ONLINE / 0 = OFFLINE): ");
                    scanf("%d", &comunicacao);
                    if (comunicacao != 0 && comunicacao != 1) {
                        printf("Valor invalido! Digite apenas 1 ou 0.\n");
                    }
                } while (comunicacao != 0 && comunicacao != 1);
                if (contadorHistorico < 5) {
                    historicoTemperaturas[contadorHistorico] = temperatura;
                    contadorHistorico++;
                }
                dadosInseridos = 1;

                printf("\nDados cadastrados com sucesso!\n");
                break;
            case 2:
                if (dadosInseridos == 1) {

                    printf("\n========== STATUS DA MISSAO ==========\n");

                    printf("Temperatura da nave: %.2f C\n", temperatura);
                    printf("Nivel de energia: %d%%\n", energia);

                    if (comunicacao == 1) {
                        printf("Comunicacao: ONLINE\n");
                    } else {
                        printf("Comunicacao: OFFLINE\n");
                    }
                    printf("======================================\n");
                } else {
                    printf("\nNenhum dado foi inserido ainda!\n");
                }
                break;
            case 3:
                if (dadosInseridos == 1) {

                    printf("\n========== ANALISE DA MISSAO ==========\n");

                    if (temperatura > 80) {
                        printf("ALERTA: Superaquecimento detectado!\n");
                    } else {
                        printf("Temperatura dentro do normal.\n");
                    }
                    if (energia < 20) {
                        printf("ALERTA: Ativar modo economia de energia!\n");
                    } else {
                        printf("Nivel de energia adequado.\n");
                    }
                    if (comunicacao == 0) {
                        printf("ALERTA: Falha de comunicacao!\n");
                    } else {
                        printf("Comunicacao funcionando normalmente.\n");
                    }
                    printf("=======================================\n");
                } else {
                    printf("\nNenhum dado foi inserido ainda!\n");
                }
                break;
            case 4:
                printf("\n===== HISTORICO DE TEMPERATURAS =====\n");
                if (contadorHistorico == 0) {
                    printf("Nenhum registro encontrado.\n");
                } else {
                    for (int i = 0; i < contadorHistorico; i++) {
                        printf("%d leitura: %.2f C\n", i + 1, historicoTemperaturas[i]);
                    }
                }
                printf("=====================================\n");
                break;
            case 0:
                printf("\nEncerrando sistema...\n");
                printf("Missao finalizada com sucesso!\n");
                break;
            default:
                printf("\nOpcao invalida!\n");

        }
    } while(opcao != 0);
    return 0;
}
