# Gerenciador de Memória
Este projeto simula o gerenciamento de memória utilizando conceitos de alocação de memória não contígua. O programa é capaz de criar processos com tamanhos aleatórios, alocar páginas de memória para esses processos, e visualizar a utilização da memória física e as tabelas de páginas dos processos.
&nbsp; &nbsp; &nbsp;

## Estrutura do Projeto
```
├── Makefile
├── README.md
├── includes
    ├── memoria.h     Declarações das funções relacionadas à memória (Tamanho de memória física, memória lógica e página).
    ├── pagina.h      Definição da estrutura de Pagina.
    ├── processo.h    Declarações das funções relacionadas a processos e definição da estrutura Processo.
    ├── quadro.h      Declarações das funções relacionadas aos quadros de memória e definição da estrutura Quadro.
└── src
    ├── main.c        Contém a função principal e a lógica de interação com o usuário.
    ├── memoria.c     Função de visualização da memória física.
    ├── processo.c    Funções para criação de processos e visualização de tabelas de páginas.
    └── quadro.c      Função de criação dos quadros de memória e gestão do vetor de quadros livres.
```
&nbsp; &nbsp; &nbsp;

## Compilação e Execução

Na raiz do programa compile o programa usando o Makefile
```bash
make
```
Execute o programa
```bash
./main
```
&nbsp; &nbsp; &nbsp;

## Uso do Programa
Ao executar o programa, o usuário pode escolher entre as seguintes opções:

- `Visualizar memória`
  > Mostra a quantidade de memória usada e livre, bem como o estado de cada quadro (ocupado ou livre).

- `Criar processo`
  > Cria um novo processo com um tamanho aleatório e aloca páginas de memória para ele.

- `Visualizar tabela de páginas de um processo`
  > Mostra a tabela de páginas de um processo específico, mapeando páginas para quadros.

- `Sair`
  > Encerra o programa.

&nbsp; &nbsp; &nbsp;

## Casos de Teste

- Criar e Visualizar um Processo
  - Escolha a opção `2. Criar processo`.
  - Insira o ID do processo (por exemplo, 1).
  - O programa criará um processo com um tamanho aleatório e alocará as páginas de memória necessárias.
  - Escolha a opção `3. Visualizar tabela de páginas de um processo`.
  - Insira o ID do processo criado (por exemplo, 1).

  O programa mostrará a tabela de páginas do processo, indicando quais páginas estão mapeadas para quais quadros.


_Saída Esperada_
```
Informe o número do processo: 1
Processo 1 criado com tamanho de X bytes.

Informe o número do processo: 1
=-=-=-=-=-=-=-=-=-=-=-= Processo 1 =-=-=-=-=-=-=-=-=-=-=-=
Tamanho do processo: X bytes
Número de páginas: Y

Mapeamento entre páginas e quadros:
Página 0 -> Quadro A (Memória usada: B bytes)
Página 1 -> Quadro C (Memória usada: D bytes)
```
&nbsp; &nbsp; &nbsp;

- Visualizar Memória Física
  - Escolha a opção `1. Visualizar memória`.
  - O programa mostrará a quantidade de memória usada e livre, bem como o estado de cada quadro.

_Saída Esperada_
```
=-=-=-=-=-=-=-=-=-=-=-= Memória física =-=-=-=-=-=-=-=-=-=-=-=
Memória usada | N bytes (M%)
Memória livre | P bytes (Q%)

=-=-=-=-=-=-=-=-=-=-=-=-=-=-= Quadros =-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Quadro 0 | Ocupado | A/B bytes
Quadro 1 | Livre   | C/D bytes
```
&nbsp; &nbsp; &nbsp;
