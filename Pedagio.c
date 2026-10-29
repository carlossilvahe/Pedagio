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
    // Variaveis de controle utilizadas nos lacos for.
    // i percorre categorias ou dias.
    // j percorre as categorias dentro de cada dia.
    int i;
    int j;

    // ------------------------------------------------------
    // TELA DE BOAS-VINDAS
    // ------------------------------------------------------

    // Exibe o cabecalho do sistema.

    printf("==========================================================\n");
    printf("=================== SISTEMA DE PEDAGIO ===================\n"); 
    printf("==========================================================\n");
    printf("%s Usuario(a), Seja bem-vindo ao nosso sistema\n", Saudacoes());  // Chama a funcao Saudacoes() e imprime a saudacao retornada.
    printf("==========================================================\n");

    // ------------------------------------------------------
    // MENU PRINCIPAL
    // ------------------------------------------------------

    // O do-while executa o menu pelo menos uma vez.
    // Depois de cada execucao, verifica se o usuario escolheu sair.

    do{
        // Apresenta as opcoes disponiveis no sistema.
        printf("1 - REGISTRAR PASSAGEM DE VEICULO\n"); // 
        printf("2 - CONSULTAR RELATORIO DIARIO \n"); // 
        printf("3 - CONSULTAR RELATORIO SEMANAL \n"); //
        printf("0 - SAIR \n"); // 
        printf("POR FAVOR DIGITE UMA DAS OPCOES ACIMA:\n");
    

        // scanf() tenta ler um numero inteiro para a variavel opcao.
        //
        // Se retornar 1, conseguiu ler um inteiro.
        // Se nao retornar 1, a entrada nao foi lida como inteiro.
        if(scanf("%d", &opcao) != 1){
            printf("\nENTRADA INVALIDA! DIGITE APENAS NUMEROS! \n"); // Informa que a entrada nao foi valida.
            // Descarta os caracteres restantes da linha de entrada.
            // Isso evita que uma entrada invalida fique no buffer
            // e atrapalhe a proxima leitura.
            while(getchar() != '\n');
             // Define uma opcao invalida para nao executar uma
            // operacao normal do menu.
            opcao = -1;
        }
        switch (opcao) // switch seleciona qual bloco executar conforme o valor de opcao.
        {
        // ==================================================
        // CASE 1: REGISTRAR PASSAGEM DE VEICULO
        // ==================================================
        case 1:

            printf("==========================================================\n");
            printf("============= REGISTRO DE PASSAGEM DE VEICULO ============\n");
            printf("==========================================================\n");
         
            // Percorre o vetor de categorias para exibir as opcoes.
            //
            // i comeca em 0.
            // O laco continua enquanto i for menor que 4.
            // i++ incrementa i em uma unidade a cada repeticao.
            for(i = 0; i < NUM_CATEGORIAS; i++){
                 // Exibe o numero da opcao e o nome da categoria.
                //
                // i + 1 faz as opcoes aparecerem de 1 a 4,
                // embora os indices do vetor sejam de 0 a 3.
                printf("%d - %s \n", i+1,categorias_veiculos[i]);                
            }
            // Tenta ler o numero da categoria escolhida.
            if(scanf("%d", &categoria_escolhida ) == 1 ){
                // Verifica se a categoria esta dentro do intervalo valido.
                // As opcoes permitidas sao 1, 2, 3 e 4.
                if(categoria_escolhida >= 1 && categoria_escolhida <= 4){
                    dia = obter_dia(); // Descobre o dia da semana atual.
                    // Exibe a categoria e o valor da tarifa correspondente.
                    //
                    // categoria_escolhida - 1 transforma a opcao
                    // digitada (1 a 4) em indice de vetor (0 a 3).
                    printf("==========================================================\n");
                    printf("Para a categoria %s cobre o valor de R$:%.2f e libere o veiculo\n", categorias_veiculos[categoria_escolhida-1], tarifas[categoria_escolhida-1]);
                    // Incrementa em 1 a quantidade registrada.
                    //
                    // dia identifica a linha da matriz.
                    // categoria_escolhida - 1 identifica a coluna.
                    //
                    // O operador ++ soma uma unidade ao valor existente.
                    veiculos[dia][categoria_escolhida-1]++;

                }else
                {
                    // Executado quando o numero informado nao corresponde
                    // a nenhuma categoria cadastrada.
                    printf("Voce digitou uma categoria invalida!");
                }
            
            }else{
                // Se a leitura nao receber um inteiro, limpa a entrada
                // restante para evitar problemas na proxima leitura.
                while(getchar() != '\n');
                printf("Digite apenas numeros!");
            }
            // Encerra o case 1 e retorna ao fluxo do switch.
            break;
        // ==================================================
        // CASE 2: CONSULTAR RELATORIO DIARIO
        // ==================================================
        case 2:
            // Reinicia o acumulador antes de calcular o relatorio.
            // Isso evita somar valores de uma consulta anterior.
            total = 0;
            printf("==========================================================\n");
            printf("=================== RELATORIO DIARIO =====================\n");
            dia = obter_dia(); // Descobre qual dia da semana deve ser consultado.
            for(i = 0; i < NUM_CATEGORIAS; i++){ // Percorre todas as categorias de veiculos.
                // Exibe o nome da categoria e a quantidade registrada
                // para o dia atual.
                //
                // veiculos[dia][i]:
                // dia escolhe a linha da matriz.
                // i escolhe a coluna da categoria.
                printf("Categoria: %s  Quantidade: %d\n",categorias_veiculos[i],veiculos[dia][i]); 
                // Calcula a arrecadacao da categoria no dia.
                //
                // tarifa da categoria * quantidade de veiculos.
                // %.2f exibe o valor com duas casas decimais.               
                printf("Dia: %s Total: R$%.2f\n", dias[dia], tarifas[i] * veiculos[dia][i]);
                // Soma a arrecadacao desta categoria ao total do dia.
                //
                // O operador += equivale a:
                // total = total + tarifas[i] * veiculos[dia][i];
                total = total + tarifas[i] * veiculos[dia][i];
            }
            // Exibe a soma da arrecadacao de todas as categorias do dia.
            printf("Total Arrecadado(todas categorias): R$%.2f\n", total);

            break;  // Encerra o case 2
        case 3:
            printf("==========================================================\n");
            printf("=================== RELATORIO SEMANAL ====================\n");

            // Reinicializa as variaveis usadas no relatorio semanal.
            //
            // maior_arrecadacao comeca em zero para comparar os valores.
            // dia_maior_arrecadacao comeca em -1 para indicar que
            // ainda nao foi encontrado um dia com arrecadacao positiva.
            // total comeca em zero para somar a semana inteira.
            maior_arrecadacao = 0;
            dia_maior_arrecadacao = -1;
            total = 0;
            // Percorre os sete dias da semana.
            // i representa o indice do dia atual do relatorio.
            for(i = 0; i < NUM_DIAS; i++){
                // Zera a arrecadacao antes de calcular cada dia.
                // Assim, os valores de um dia nao se misturam com os do outro.
                arrecadacao_dia = 0;
                // Percorre as quatro categorias de veiculos
                // dentro do dia selecionado pelo laco externo.
                for(j = 0; j < NUM_CATEGORIAS; j++){
                    // Calcula a arrecadacao de cada categoria:
                    // tarifa da categoria * quantidade registrada no dia.
                    //
                    // O resultado e somado a arrecadacao do dia.
                    arrecadacao_dia += tarifas[j] * veiculos[i][j];
                }
                // Exibe o total arrecadado no dia analisado.
                // dias[i] fornece o nome do dia correspondente.
                printf("%s: R$ %.2f\n", dias[i], arrecadacao_dia);

                // Adiciona a arrecadacao diaria ao total semanal.
                total += arrecadacao_dia;

                // Compara a arrecadacao deste dia com o maior valor
                // encontrado ate o momento.
                if(arrecadacao_dia > maior_arrecadacao){

                    // Se o dia atual arrecadou mais, atualiza o recorde.
                    maior_arrecadacao = arrecadacao_dia;

                    // Guarda o indice do dia que teve a maior arrecadacao.
                    dia_maior_arrecadacao = i;
                }
                // Ao terminar esta repeticao, o laco externo passa
                // para o proximo dia da semana.
            }
         // Depois de analisar todos os dias, exibe a arrecadacao semanal.
        printf("Total arrecadado na semana: R$ %.2f\n", total);

        // Verifica se algum dia teve arrecadacao maior que zero.
        //
        // Se dia_maior_arrecadacao for diferente de -1,
        // um dia com arrecadacao positiva foi encontrado.
        if(dia_maior_arrecadacao != -1){
            // Exibe o nome do dia de maior arrecadacao e seu valor.
            //
            // dias[dia_maior_arrecadacao] busca o nome do dia.
            // maior_arrecadacao guarda o valor encontrado.
            printf("O dia que mais arrecadou foi %s, com R$ %.2f\n",
            dias[dia_maior_arrecadacao],
            maior_arrecadacao);
        }else{
        // Se todos os dias estiverem com arrecadacao zero,
        // informa que ainda nao houve passagens registradas.
        printf("Ainda nao houve passagens registradas na semana.\n");
        }

    break;  // Encerra o case 3.
        
        // ==================================================
        // CASE 0: SAIR DO SISTEMA
        // ==================================================
        case 0:
         // Exibe a mensagem de despedida.
        printf("VOCE ESCOLHEU SAIR! ATÉ A PROXIMA!! \n"); 

            // Encerra o case 0.
            // A condicao do-while determinara o encerramento do menu.
            break;


        // ==================================================
        // DEFAULT: OPCAO NAO CADASTRADA
        // ==================================================
        default:
            // Executado quando opcao nao corresponde a 0, 1, 2 ou 3.
            printf("OPCAO INVALIDA, POR FAVOR USE UMA DAS OPCOES VALIDAS. \n"); //
            break;
        }

        // --------------------------------------------------
        // PAUSA ANTES DE MOSTRAR O MENU NOVAMENTE
        // --------------------------------------------------

        // A pausa so acontece se o usuario nao escolheu sair.
        if (opcao != 0) {
        printf("\nPressione ENTER para continuar...");

        // Consome o caractere '\n' que pode ter ficado no buffer
        // depois da leitura feita por scanf().
        getchar();
         // Aguarda o usuario pressionar ENTER para continuar.
        getchar();
        }


     // Repete o menu enquanto a opcao digitada for diferente de zero.
    } while (opcao != 0);   


     // Retorna 0 ao sistema operacional, indicando encerramento normal.
    return 0;
}