package projetocorrida;

import java.util.Scanner;

public class Corrida {
    private static Carro[] carros = new Carro[20];
    public static void main(String[] args) {
        menu();
    }
    //métodos públicos
    //método menu, utilizado para que o usuário acesse outros métodos
    public static void menu(){
        int escolha=13;
        do{
            //imprime o menu na tela
            System.out.println("Simulador de corrida Formula 13!");
            System.out.println("\n                  =====================================================");
	    System.out.println("                  |     1 - Incluir veiculo                             |");
	    System.out.println("                  |     2 - Remover veiculo                             |");
	    System.out.println("                  |     3 - Abastecer veiculo                           |");
	    System.out.println("                  |     4 - Movimentar um veiculo                       |");
            System.out.println("                  |     5 - Movimentar todos                            |");
	    System.out.println("                  |     6 - Imprimir todos os dados de todos os veiculos|");
	    System.out.println("                  |     7 - Esvaziar um pneu especifico                 |");
            System.out.println("                  |     8 - Calibrar um pneu especifico                 |");
            System.out.println("                  |     9 - Calibrar todos os pneus de um veiculo       |");
	    System.out.println("                  |     10 - Imprimir pista                             |");
            System.out.println("                  |     11 - Pagar IPVA                                 |");
            System.out.println("                  |     12 - Sair                                        |");
	    System.out.println("                  =====================================================\n");
            System.out.print("\n");
            System.out.println("Insira a opção desejada: ");
            Scanner teclado = new Scanner(System.in);
            escolha = teclado.nextInt();
            if(escolha == 1){
                incluirCarro();
                atualizarMenu();
            }
            else if(escolha == 2){
                removerCarro();
                atualizarMenu();
            }
            else if(escolha==3){                  
                abastecerCarro();
                atualizarMenu();
            }
            else if(escolha==4){
                movimentarCarro();
                atualizarMenu();
            }
            else if(escolha==5){
                movimentarTodos();
                atualizarMenu();
            }
            else if(escolha==6){
                imprimirDadosGeral();
                atualizarMenu();
            }
            else if(escolha==7){
                esvaziarPneu();
                atualizarMenu();
            }
            else if(escolha==8){
                calibrarPneu();
                atualizarMenu();
            }
            else if(escolha==9){
                calibrarTodos();
                atualizarMenu();
            }
            else if(escolha==10){
                imprimirPista();
                atualizarMenu();
            }
            else if(escolha==11){
                pagarImposto();
                atualizarMenu();
            }
            if(escolha == 12){
                System.exit(0);
            }
        }while(escolha != 0);
    }
    //método usado para atualizar o menu e melhorar a experiência do usuário
    public static void atualizarMenu(){
        Scanner teclado = new Scanner(System.in);
        System.out.println("\n");
        System.out.println("Pressione a tecla enter para voltar ao menu: ");
        teclado.nextLine();
    }
    //metodo usado para buscar um carro pelo numero da placa
    public static int buscarPlaca(){
        int placa;
        System.out.println("Insira a placa do carro desejado: ");
        Scanner teclado = new Scanner(System.in);
        placa = teclado.nextInt();
        if(placa > carros.length+1){
                return -1;
        }
        for(Carro carro: carros){
            if(carro.getPlaca() == placa){
                //retorna a posicao em que o carro foi encontrado
                int i = carro.getPlaca();
                return i;
            }
           
        }
        //caso nao seja encontrado, retorna 0
        return -1;
    }
    //método usado para inserir um novo carro, com limite max de 20 carros
    public static void incluirCarro(){
        if(carros.length > 20){
            System.out.println("Erro! O limite de veiculos competindo ja foi alcançado!");
        }
        else{
        for(int i=0;i<carros.length;i++){
            //verifica se ha espaco disponivel para inserir um novo carro
            if(carros[i] == null){
                carros[i] = new Carro();
                carros[i].iniciarCarro();
                carros[i].setPlaca(i+1);
                i = carros.length;
                System.out.println("O veiculo esta participando da corrida!");
            }
        }
        }
    }
    //método usado para remover um carro
    public static void removerCarro(){
        //primeiro chamamos um método para realizar a busca da placa que desejamos remover
        int aux = buscarPlaca();
        //caso seja um valor diferente de -1 o veículo é removido
        if(aux != -1){
            carros[aux-1] = null;
            System.out.println("Veiculo removido com sucesso!");
        }
        //senão não é possível remover
        else{
            System.out.println("Erro! Veiculo nao encontrado.");
        }
    }
    //método usado para movimentar um carro
    public static void movimentarCarro(){
        //o método buscarPlaca retorna um valor
        int aux = buscarPlaca();
        //caso o retorno seja diferente de -1, então o veículo existe
        if(aux != -1){
            //caso o método mover retorne verdadeiro o veículo é dado como movimentado
            if(carros[aux-1].mover()){
                System.out.println("O veiculo foi movimentado com sucesso!");
            }
            //senão, o veículo é dado como parado
            else{
                System.out.println("Erro! O veiculo nao pode movimentar-se!");
            }
        }
        //caso o veículo não exista
        else{
            System.out.println("Erro! Placa nao encontrada.");
        }
    }
    //método usado para movimentar todos os veículos que atendem as condições necessárias
    public static void movimentarTodos(){
        int aux = 0;
        //percorre o vetor Carro
        for(Carro carro: carros){
            //caso o espaço de memória não esteja vazio, ele move o veículo
            if(carro != null){
                carro.mover();
                aux = 1;
            }
        }
        //se aux retorna 1, todos os veículos que podem ser movidos foram movidos
        if(aux==1){
            System.out.println("Todos os carros que atendem as condições necessárias foram movimentados!");
        }
        else{
            System.out.println("Nenhum carro foi movimentado!");
        }
    }
    //método usado para imprimir os dados de todos os carros que estão na pista
    public static void imprimirDadosGeral(){
        //percorre o vetor Carro
        for(Carro carro: carros){
            //caso o espaço de memória não esteja vazio, ele imprime os dados do veículo
            if(carro != null){
             carro.imprimirDados();
            }
        }
    }
    //método usado para esvaziar um pneu específico
    public static void esvaziarPneu(){
        //o método buscarPlaca retorna a posição em que o carro está no vetor
        int aux = buscarPlaca();
        int pneu;
        if(aux != -1){
            System.out.println("Qual pneu deseja esvaziar?");
            //realiza a leitura do pneu desejado
            Scanner teclado = new Scanner(System.in);
            pneu = teclado.nextInt();
            carros[aux-1].esvaziarPneu(pneu);
            System.out.println("O pneu foi esvaziado");
        }
        //caso buscarPlaca retorne um valor inválido
        else{
            System.out.println("Erro! Veiculo nao encontrado!");
        }
    }
    //método usado para calibrar um pneu específico de um carro
    public static void calibrarPneu(){
        //o método buscarPlaca retorna a posição em que o carro está no vetor
        int aux = buscarPlaca();
        int pneu;
        if(aux != -1){
            System.out.println("Qual pneu deseja esvaziar?");
            Scanner teclado = new Scanner(System.in);
            pneu = teclado.nextInt();
            carros[aux].calibrarPneu(pneu);
            System.out.println("Pneus do veiculo "+aux+" calibrados");
        }
        //caso aux retorne um número inválido o pneu não é calibrado
        else{
            System.out.println("Erro! Veiculo nao encontrado!");
        }
    }
    //método usado para calibrar todos os pneus de um carro
    public static void calibrarTodos(){
        //o método buscarPlaca retorna a posição em que o carro está no vetor
        int aux = buscarPlaca();
        if(aux != -1){
            carros[aux-1].calibrarPneus();
            System.out.println("Pneus do veiculo "+aux+" calibrados");
        }
    }
    //método usado para imprimir os veículos existentes na pista
    public static void imprimirPista(){
        //percorre o vetor Carro
        for(Carro carro: carros){
            //se o espaço não estiver vazio ele chama o método desenharCarro
            if(carro != null){
             carro.desenharCarro();
            }
        }
    }
    //método usado para abastecer um carro
    public static void abastecerCarro(){
        //o método buscarPlaca retorna a posição em que o carro está no vetor
        int aux = buscarPlaca();
        float qtde;
        if(aux != -1){
            System.out.println("Quanto de combustivel deseja abastecer?");
            //lê a quantidade desejada pelo usuário
            Scanner teclado = new Scanner(System.in);
            qtde = teclado.nextFloat();
            //abastece o veículo desejado
            carros[aux-1].abastecer(qtde);
            System.out.println("Veiculo "+aux+" abastecido.");
        }
        //caso aux retorne um número inválido o veículo não é abastecido
        else{
            System.out.println("Erro! Veiculo nao encontrado!");
        }
    }
    //método usado para pagar imposto de um veículo
    public static void pagarImposto(){
        //o método buscarPlaca retorna a posição em que o carro está no vetor
        int aux = buscarPlaca();
         if(aux != -1){
            carros[aux-1].pagarIpva();
             System.out.println("O pagamento do IPVA do veiculo "+aux+ " foi realizado com sucesso!");
        }
        //caso aux retorne um número inválido o IPVA não é pago
        else{
            System.out.println("Erro! Veiculo nao encontrado!");
        }
    }
}
