package encapsulamento.ex01;

public class Pessoa {
    private String nome;
    private int idade;

    public Pessoa(String nome, int idade) {
        this.nome = nome;
        this.idade = idade;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String novoNome) {
        this.nome = novoNome;
    }

    public static void main(String[] args) {
        Pessoa pessoa = new Pessoa("Felipe", 19);
        System.out.println("Nome: " + pessoa.getNome());
        pessoa.setNome("Osvaldo");
        System.out.println("Novo nome: " + pessoa.getNome());

    }
}