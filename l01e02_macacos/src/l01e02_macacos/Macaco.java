package l01e02_macacos;

import java.util.Random;

public class Macaco extends Thread {
	private Lado lado;
	private Ponte ponte;

	public Macaco(String nome, Lado lado, Ponte ponte) {
		super(nome);
		this.lado = lado;
		this.ponte = ponte;
		System.out.println(super.getName() +" nasceu. Esta no lado "+ this.lado.toString());

	}

	public void run() {
		try {
			while (true) {
				this.comer();
				this.atravessar();
			}
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}

	public void comer() throws InterruptedException {
		int tempo = (new Random()).nextInt(4000)+1000;
		System.out.println(super.getName() +" vai comer. Esta no lado "+ this.lado.toString());
		Thread.sleep(tempo);
		System.out.println(super.getName() +" parou de comer. Esta no lado "+ this.lado.toString());
	}

	public void atravessar() {
		System.out.println(super.getName() +" quer atravessar. Esta no lado "+ this.lado.toString());
		switch (this.lado) {
		case DIREITO: 
			this.ponte.atravessarDireitaEsquerda(super.getName());
			break;
		case ESQUERDO: 
			this.ponte.atravessarEsquerdaDireita(super.getName());
			break;
		}
		this.trocarLado();
		System.out.println(super.getName() +" atravessou. Esta no lado "+ this.lado.toString());
	}
	
	private void trocarLado() {
		this.lado = Lado.values()[(this.lado.ordinal()+1)%2];
	}
 
}