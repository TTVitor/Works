package l01e02_macacos;

public class Principal {

	public static void main(String[] args) {
		Ponte ponte = new Ponte();
		for (int i=1; i<=10; i++)
			new Macaco("macaco "+i, Lado.values()[i%2], ponte).start();
		System.out.println(">>>>> Macacos criados");
	}

}