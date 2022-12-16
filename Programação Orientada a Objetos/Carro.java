package projetocorrida;
import java.util.Random;
public class Carro {
    //atributos
    Random aleatorio = new Random();
    //relacionamento com a classe Roda
    private Roda[] rodas;
    private int placa;
    private int kilometragem;
    private boolean ipvaPago;
    private boolean calibragem;
    private float qtdeCombustivel;

//inicia as rodas do objeto carro
public Carro() {
    rodas = new Roda[4];
}
//metodos publicos
//metodo que realiza o pagamento do ipva
public void pagarIpva(){
    this.setIpvaPago(true);
}
//metodo que realiza a movimentação de cada objeto carro
public boolean mover(){
    int aux=0;
    //primeiro nos certificamos de que o ipva esta pago, apos isso validamos os outros requisitos
    if(this.getIpvaPago()){
        //verifica se ha combustivel necessario
        if(this.getQtdeCombustivel()>=0.55f){
            for(int i=0;i<4;i++){
                //nos certificamos de que todas as rodas estao calibradas
               if(this.rodas[i].getCalibragem()){
                   aux++;
               }
            }
            //se a variavel auxiliar chegou em 4 é porque todas as rodas estão calibradas
            if(aux==4){
                //ao movimentarmos o carro, atualizamos o valor dos atributos kilometragem e qtdeCombustivel
                this.setKilometragem(this.getKilometragem() + 5);
                this.setQtdeCombustivel(this.getQtdeCombustivel()-0.55f);
                return true;
            }
        }
    }
    //se o ipva não estiver pago retornamos falso pois não foi possível mover o carro
    return false;
}
//esvazia um pneu especifico, o qual foi escolhido pelo usuario
public void esvaziarPneu(int pneu){
    pneu = pneu-1;
    rodas[pneu].setCalibragem(false);
}
//calibra um pneu especifico, o qual foi escolhido pelo usuario
public void calibrarPneu(int pneu){
    pneu = pneu-1;
    rodas[pneu].setCalibragem(true);
}
//calibra todos os pneus
public void calibrarPneus(){
   //calibra pneu por pneu
   for(int i=0;i<4;i++){
       rodas[i].setCalibragem(true);
   }
}
//o metodo abastece o veiculo indicado
public void abastecer(float qtde){
    this.setQtdeCombustivel(this.getQtdeCombustivel()+qtde);
}
//o metodo imprime o veiculo na tela
public void desenharCarro(){
    String espaco = "";
    //o laço percorre a distância percorrida para imprimir os espaços
    for(int i=this.kilometragem;i>0;i--){
        espaco += "\t";
    }
    //após imprimir os espaços, imprimos o carro
    System.out.println(espaco+"Placa: "+this.getPlaca());
    System.out.print(espaco+"    ____\n");
    System.out.print(espaco+" __/  |_ \\_\n");
    System.out.print(espaco+"|  _     _``-\n");
    System.out.print(espaco+"'-(_)---(_)--'\n");
}
//imprime os dados de um veículo
public void imprimirDados(){
    System.out.println("Placa: "+this.getPlaca());
    System.out.println("Pneus calibrados?"+this.getCalibragem());
    System.out.println("Quantidade combustivel: "+this.getQtdeCombustivel());
    System.out.println("Distancia percorrida: "+this.getKilometragem());
}
//metodos especiais
//metodo construtor
public void iniciarCarro(){
    for(int i=0;i<4;i++){
        //realizamos um sorteio para determinar se as rodas estarão calibradas ou não
        int sorteio = aleatorio.nextInt(100);
        this.rodas[i] = new Roda();
        if(sorteio%2 != 0){
            this.rodas[i].setCalibragem(false);
        }
        else if(sorteio%2 == 0){
            this.rodas[i].setCalibragem(true);
        }
    }
    //realizamos um outro sorteio para definir se o ipva está pago ou nao
    int sorteio = aleatorio.nextInt(100);
    if(sorteio%2 != 0){
        this.setIpvaPago(false);
    }
    else if(sorteio%2 == 0){
        this.setIpvaPago(true);
    }
    //a quantidade inicial de combustivel deve ser de 3.5 litros para todos os carros
    this.qtdeCombustivel = 3.5f;
}
//getters e setters
//método getter que retorna o atributo placa
public int getPlaca() {
    return placa;
}
//método getter que retorna o atributo ipva
public boolean getIpvaPago() {
    return ipvaPago;
}
//método getter que retorna o atributo qtdeCombustivel
public float getQtdeCombustivel() {
        return qtdeCombustivel;
    }
//método getter que retorna o atributo kilometragem
public int getKilometragem() {
    return kilometragem;
}
//método getter que retorna o atributo calibragem
public boolean getCalibragem() {
    return calibragem;
}
//método setter usado para definir se um carro está devidamente calibrado    
public void setCalibragem(boolean calibragem) {
    this.calibragem = calibragem;
}
//método setter usado para definir o valor de uma placa   
public void setPlaca(int placa) {
        this.placa = placa;
}
//método setter usado para definir se o ipva está pago ou não
public void setIpvaPago(boolean ipvaPago) {
    this.ipvaPago = ipvaPago;
}
//método setter usado para definir a quantidade de combustível
public void setQtdeCombustivel(float qtdeCombustivel) {
    this.qtdeCombustivel = qtdeCombustivel;
}
//método setter usado para alterar a distância percorrida pelo veículo
public void setKilometragem(int kilometragem) {
    this.kilometragem = kilometragem;
}
    
}
