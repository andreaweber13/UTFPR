package projetocorrida;
public class Roda {
    //atributos
    private boolean calibragem;
    //metodo construtor
    public Roda(){
        //o objeto Roda inicia não calibradocc
        this.calibragem = false;
    }
    //setters e getters
    //método getter usado para retornar se uma roda está calibrada ou não
    public boolean getCalibragem() {
        return calibragem;
    }
    //método setter usado para definir se a roda está calibrada ou não
    public void setCalibragem(boolean calibragem) {
        this.calibragem = calibragem;
    }
    
}
