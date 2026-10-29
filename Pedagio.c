#include <stdio.h> // Biblioteca responsavel pelas funcoes de entrada e saida, como printf() e scanf().
#include <time.h> // Biblioteca responsavel por trabalhar com data e hora do sistema.

// Define constantes para evitar repetir valores fixos pelo codigo.
#define NUM_CATEGORIAS 4 // Quantidade de categorias de veiculos cadastradas.
#define NUM_DIAS 7 // Quantidade de dias da semana.

// Define a tarifa-base do pedagio.
#define VALOR_TARIFA 6.75 // Valor de referencia usado para calcular as tarifas.

// Define a porcentagem da tarifa-base cobrada por cada categoria.
#define TARIFA_MOTO 50.0 // Motos pagam 50% da tarifa-base.
#define TARIFA_CARRO 100.0 // Carros pagam 100% da tarifa-base.
#define TARIFA_CAMINHAO 250.0 // Caminhoes pagam 250% da tarifa-base.
#define TARIFA_ONIBUS 220.0 // Onibus pagam 220% da tarifa-base.

// ==========================================================
// FUNCAO: Saudacoes
// OBJETIVO: Retornar uma saudacao de acordo com a hora atual.
// RETORNO: Uma string (sequencia de caracteres) constante.
// ==========================================================
const char *Saudacoes(void){
    time_t agora = time(NULL);
    struct tm *horaAtual = localtime(&agora);
    int hora = horaAtual->tm_hour;
    if (hora < 12) {
        return "Bom Dia";
    }else if(hora >= 12 && hora < 18){
        return "Boa Tarde";
    }else{
        return "Boa Noite";
    }


}
// ==========================================================
// FUNCAO: obter_dia
// OBJETIVO: Descobrir o dia da semana atual.
// RETORNO: Um numero inteiro entre 0 e 6.
//
// Convencao utilizada pela funcao localtime():
// 0 = Domingo
// 1 = Segunda-feira
// 2 = Terca-feira
// 3 = Quarta-feira
// 4 = Quinta-feira
// 5 = Sexta-feira
// 6 = Sabado
// ==========================================================
int obter_dia(void){
        time_t agora = time(NULL);
        struct tm *diaAtual = localtime(&agora);
        int dia = diaAtual->tm_wday;
        return dia;
}

int main() {
    
    float total = 0; // Guarda o valor total calculado em um relatorio.
    int dia; // Armazena o numero do dia atual, de 0 a 6.
    int opcao;  // Recebe a opcao digitada pelo usuario no menu.
    int categoria_escolhida = 0; // Recebe a categoria de veiculo escolhida pelo usuario.
    float arrecadacao_dia = 0; // Armazena a arrecadacao calculada para um dia especifico.
    float maior_arrecadacao = 0; // Guarda o maior valor de arrecadacao encontrado no relatorio semanal.
    int dia_maior_arrecadacao = -1; // Guarda o indice do dia que teve a maior arrecadacao.

    // Vetor de ponteiros para caracteres (strings).
    // Cada posicao guarda o nome de uma categoria de veiculo.
    //
    // Indices:
    // 0 = Motos
    // 1 = Carros
    // 2 = Caminhoes
    // 3 = Onibus
    const char *categorias_veiculos[NUM_CATEGORIAS] = {
        "Motos", "Carros", "Caminhoes", "Onibus" 
    };

    // Vetor de strings com os nomes dos dias da semana.
    // Os nomes seguem a mesma numeracao retornada por obter_dia().
    const char *dias[NUM_DIAS] = {
        "Domingo",
        "Segunda-feira",
        "Terca-Feira",
        "Quarta-feira",
        "Quinta-feira",
        "Sexta-feira",
        "Sabado"
    };

    // Matriz que registra a quantidade de veiculos por dia e categoria.
    //
    // NUM_DIAS = quantidade de linhas (7 dias).
    // NUM_CATEGORIAS = quantidade de colunas (4 categorias).
    //
    // Exemplo:
    // veiculos[1][0] representa a quantidade de motos registradas
    // na segunda-feira.
    //
    // veiculos[2][1] representa a quantidade de carros registradas
    // na terca-feira.
    //
    // O {0} inicializa todas as posicoes da matriz com zero.
    int veiculos[NUM_DIAS][NUM_CATEGORIAS] = {0};

    // Vetor que armazena a tarifa calculada para cada categoria.
    //
    // A formula utilizada e:
    // porcentagem / 100 * tarifa-base.
    //
    // Exemplo para motos:
    // 50 / 100 * 6.75 = R$ 3.375.
    //
    // A ordem das tarifas corresponde a ordem das categorias
    // no vetor categorias_veiculos.
    float tarifas[NUM_CATEGORIAS] = {
        TARIFA_MOTO / 100 * VALOR_TARIFA,
        TARIFA_CARRO / 100 * VALOR_TARIFA,
        TARIFA_CAMINHAO / 100 * VALOR_TARIFA,
        TARIFA_ONIBUS / 100 * VALOR_TARIFA
    };
    int i;
    int j;
    printf("==========================================================\n");
    printf("=================== SISTEMA DE PEDAGIO ===================\n"); 
    printf("==========================================================\n");
    printf("%s Usuario(a), Seja bem-vindo ao nosso sistema\n", Saudacoes());
    printf("==========================================================\n");

    do{

        printf("1 - REGISTRAR PASSAGEM DE VEICULO\n"); // 
        printf("2 - CONSULTAR RELATORIO DIARIO \n"); // 
        printf("3 - CONSULTAR RELATORIO SEMANAL \n"); //
        printf("0 - SAIR \n"); // 
        printf("POR FAVOR DIGITE UMA DAS OPCOES ACIMA:\n");
    
        if(scanf("%d", &opcao) != 1){
            printf("\nENTRADA INVALIDA! DIGITE APENAS NUMEROS! \n");
            while(getchar() != '\n');
            opcao = -1;
        }
        switch (opcao)
        {
        case 1:

            printf("==========================================================\n");
            printf("============= REGISTRO DE PASSAGEM DE VEICULO ============\n");
            printf("==========================================================\n");
            for(i = 0; i < NUM_CATEGORIAS; i++){
                printf("%d - %s \n", i+1,categorias_veiculos[i]);                
            }
            if(scanf("%d", &categoria_escolhida ) == 1 ){
                if(categoria_escolhida >= 1 && categoria_escolhida <= 4){
                    dia = obter_dia();
                    printf("==========================================================\n");
                    printf("Para a categoria %s cobre o valor de R$:%.2f e libere o veiculo\n", categorias_veiculos[categoria_escolhida-1], tarifas[categoria_escolhida-1]);
                    veiculos[dia][categoria_escolhida-1]++;

                }else
                {
                    printf("Voce digitou uma categoria invalida!");
                }
            
            }else{
                while(getchar() != '\n');
                printf("Digite apenas numeros!");
            }
            break;
        case 2:
            total = 0;
            printf("==========================================================\n");
            printf("=================== RELATORIO DIARIO =====================\n");
            dia = obter_dia();
            for(i = 0; i < NUM_CATEGORIAS; i++){
                printf("Categoria: %s  Quantidade: %d\n",categorias_veiculos[i],veiculos[dia][i]);                
                printf("Dia: %s Total: R$%.2f\n", dias[dia], tarifas[i] * veiculos[dia][i]);
                total = total + tarifas[i] * veiculos[dia][i];
            }
            printf("Total Arrecadado(todas categorias): R$%.2f\n", total);

            break;
        case 3:
            printf("==========================================================\n");
            printf("=================== RELATORIO SEMANAL ====================\n");

            maior_arrecadacao = 0;
            dia_maior_arrecadacao = -1;
            total = 0;

            for(i = 0; i < NUM_DIAS; i++){
                arrecadacao_dia = 0;

                for(j = 0; j < NUM_CATEGORIAS; j++){
                    arrecadacao_dia += tarifas[j] * veiculos[i][j];
                }

                printf("%s: R$ %.2f\n", dias[i], arrecadacao_dia);

                total += arrecadacao_dia;

                if(arrecadacao_dia > maior_arrecadacao){
                    maior_arrecadacao = arrecadacao_dia;
                    dia_maior_arrecadacao = i;
                }
            }

        printf("Total arrecadado na semana: R$ %.2f\n", total);

        if(dia_maior_arrecadacao != -1){
            printf("O dia que mais arrecadou foi %s, com R$ %.2f\n",
            dias[dia_maior_arrecadacao],
            maior_arrecadacao);
        }else{
        printf("Ainda nao houve passagens registradas na semana.\n");
        }

    break;
        
        case 0:
        printf("VOCE ESCOLHEU SAIR! ATÉ A PROXIMA!! \n"); //
            break;

        default:
            printf("OPCAO INVALIDA, POR FAVOR USE UMA DAS OPCOES VALIDAS. \n"); //
            break;
        }
        if (opcao != 0) {
        printf("\nPressione ENTER para continuar...");
        getchar();
        getchar();
        }



    } while (opcao != 0);   

    return 0;
}