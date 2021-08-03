package l01e02_macacos;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Ponte {
	private Lock cadeado;
	private Condition podeDireitaEsquerda;
	private Condition podeEsquerdaDireita;
	private int qtdMacacosVindoDireita;
	private int qtdMacacosVindoEsquerda;

	public Ponte() {
		this.cadeado = new ReentrantLock();
		this.podeDireitaEsquerda = this.cadeado.newCondition();
		this.podeEsquerdaDireita = this.cadeado.newCondition();
		this.qtdMacacosVindoDireita = 0;
		this.qtdMacacosVindoEsquerda = 0;
	}

	public void atravessarDireitaEsquerda(String nomeMacaco) {
		boolean atravessou=false;
		try {
			do {
				System.out.println("--> "+ nomeMacaco +" quer atravessar para ESQUERDA");
				this.cadeado.lock();
				if (this.qtdMacacosVindoDireita == 0) { // nenhum vindo, pode atravessar
					this.qtdMacacosVindoEsquerda++;
					System.out.println("--> "+ nomeMacaco +" autorizado atravessar para ESQUERDA. Atravessando="+ this.qtdMacacosVindoEsquerda);
					this.cadeado.unlock();
					Thread.sleep(3000); // Atravessando...
					atravessou = true;
					this.cadeado.lock();
					this.qtdMacacosVindoEsquerda--;
					if (this.qtdMacacosVindoEsquerda == 0) // todos chegaram
						this.podeEsquerdaDireita.signalAll();
					System.out.println("--> "+ nomeMacaco +" atravessou atravessar para ESQUERDA. Atravessando="+ this.qtdMacacosVindoEsquerda);
					this.cadeado.unlock();
				}
				else { // tem macaco(s) vindo, precisa esperar
					System.out.println("--> "+ nomeMacaco +" ESPERAR atravessar para ESQUERDA +++++++++++++++++++++++++++++++++++");
					this.podeDireitaEsquerda.await(); // vai esperar
					System.out.println("--> "+ nomeMacaco +" SAIU da espera atravessar para ESQUERDA ----------------------------");
					this.cadeado.unlock();
				}
			} while (!atravessou);
		} catch (InterruptedException e) { 
			e.printStackTrace(); 
		}
	}

	public void atravessarEsquerdaDireita(String nomeMacaco) {
		boolean atravessou=false;
		try {
			do {
				System.out.println("--> "+ nomeMacaco +" quer atravessar para DIREITA");
				this.cadeado.lock();
				if (this.qtdMacacosVindoEsquerda == 0) { // nenhum vindo, pode atravessar
					this.qtdMacacosVindoDireita++;
					System.out.println("--> "+ nomeMacaco +" autorizado atravessar para DIREITA. Atravessando="+ this.qtdMacacosVindoDireita);
					this.cadeado.unlock();
					Thread.sleep(3000); // Atravessando...
					atravessou = true;
					this.cadeado.lock();
					this.qtdMacacosVindoDireita--;
					if (this.qtdMacacosVindoDireita == 0) // todos chegaram
						this.podeDireitaEsquerda.signalAll();
					System.out.println("--> "+ nomeMacaco +" atravessou atravessar para DIREITA. Atravessando="+ this.qtdMacacosVindoDireita);
					this.cadeado.unlock();
				}
				else { // tem macaco(s) vindo, precisa esperar
					System.out.println("--> "+ nomeMacaco +" ESPERAR atravessar para DIREITA ++++++++++++++++++++++++++++++++++++");
					this.podeEsquerdaDireita.await(); // vai esperar
					System.out.println("--> "+ nomeMacaco +" SAIU da espera atravessar para DIREITA -----------------------------");
					this.cadeado.unlock();
				}
			} while (!atravessou);
		} catch (InterruptedException e) { 
			e.printStackTrace(); 
		}
	}

}