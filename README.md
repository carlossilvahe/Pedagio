SISTEMA DE PEDAGIO EM C
=======================

Sistema de gerenciamento de passagens de veiculos em um pedagio, desenvolvido em linguagem C como projeto de aprendizagem em programacao.

O programa permite registrar veiculos por categoria, calcular tarifas e consultar relatorios de arrecadacao diaria e semanal pelo terminal.

FUNCIONALIDADES
---------------

- Registro de passagens por categoria e dia da semana.
- Calculo de tarifas de acordo com a categoria do veiculo.
- Relatorio diario com quantidade de veiculos e arrecadacao por categoria.
- Relatorio semanal com arrecadacao de cada dia e total semanal.
- Identificacao do dia com maior arrecadacao.
- Saudacao automatica conforme o horario do sistema.
- Validacao basica de entradas do usuario.

CATEGORIAS E TARIFAS
--------------------

As tarifas sao calculadas com base em uma tarifa de referencia de R$ 6,75.

Categoria  | Percentual da tarifa-base | Valor calculado
-----------|---------------------------|----------------
Moto       | 50%                       | R$ 3,375
Carro      | 100%                      | R$ 6,75
Caminhao   | 250%                      | R$ 16,875
Onibus     | 220%                      | R$ 14,85

Observacao: os valores sao calculados com ponto flutuante e exibidos com duas casas decimais.

TECNOLOGIAS UTILIZADAS
----------------------

- Linguagem C
- Biblioteca stdio.h para entrada e saida de dados
- Biblioteca time.h para consulta de data e hora
- Git e GitHub para versionamento do codigo

CONCEITOS DE PROGRAMACAO APLICADOS
----------------------------------

- Variaveis e constantes
- Diretivas de pre-processamento com #define
- Funcoes e valores de retorno
- Vetores e matrizes
- Estruturas condicionais (if, else if, else)
- Estrutura de selecao (switch)
- Lacos de repeticao (for e do-while)
- Entrada e saida de dados com scanf() e printf()
- Acumuladores e calculos aritmeticos
- Validacao basica de entradas
- Manipulacao de data e hora

COMO EXECUTAR
-------------

1. Clone o repositorio:

   git clone https://github.com/carlossilvahe/Pedagio.git


2. Acesse a pasta do projeto:

   cd pedagio

3. Compile o programa com o GCC:

   gcc Pedagio.c -o Pedagio

4. Execute o programa no Linux ou Codespaces:

   ./Pedagio

   No Windows, em um terminal compativel, execute:

   .\Pedagio.exe

Observacao: o nome do arquivo-fonte utilizado nos comandos e Pedagio.c. Se o arquivo tiver outro nome, ajuste o comando de compilacao.

LIMITACOES ATUAIS
-----------------

- Os registros sao mantidos apenas durante a execucao do programa.
- Ao encerrar o programa, os dados registrados sao perdidos.
- O relatorio diario consulta automaticamente o dia atual.
- Os relatorios nao armazenam historico por data ou por semana.
- O tratamento de entradas invalidas ainda pode ser aprimorado.

MELHORIAS FUTURAS
-----------------

- Salvar os registros em arquivos para manter os dados entre execucoes.
- Permitir consultar relatorios de datas especificas.
- Aprimorar a validacao das entradas do usuario.
- Melhorar a precisao dos calculos financeiros.
- Organizar o programa em funcoes especificas para cada operacao.

OBJETIVO DO PROJETO
-------------------

Este projeto tem como objetivo praticar fundamentos da linguagem C por meio da construcao de um sistema funcional, aplicando logica de programacao, organizacao de dados, calculos e relatorios.

O desenvolvimento tambem faz parte da minha evolucao nos estudos de programacao.

Projeto desenvolvido para fins educacionais.