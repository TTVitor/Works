// UC19200602 Vítor Gabriel Barbosa dos Santos
// UCB - Universidade Católica de Brasília
// Rota3DTest.java: Girar um cubo em torno de um eixo
// paralelo a uma diagonal do seu primeiro plano.
//    Uses: Point3D, Rota3D (discussed above).
public class Rota3DTest {
   public static void main(String[] args) {
      Point3D a = new Point3D(0, 0, 2), b = new Point3D(1, 1, 2);
      double alpha = Math.PI;
      // Especifique AB como eixo de rotação direcionado
      // e alfa como ângulo de rotação:
      Rota3D.initRotate(a, b, alpha);
      // vértices de um cubo;0, 1, 2, 3 na parte inferior,
      // 4, 5, 6, 7 no topo.Vertex 0 na origem o:
      Point3D[] v = {
            new Point3D(0, 0, 0), new Point3D(1, 0, 0),
            new Point3D(1, 1, 0), new Point3D(0, 1, 0),
            new Point3D(0, 0, 1), new Point3D(1, 0, 1),
            new Point3D(1, 1, 1), new Point3D(0, 1, 1)};
      System.out.println(
            "O cubo girou em 180 graus sobre a linha AB,");
      System.out.println("onde um = (0, 0, 2) e B = (1, 1, 2)");
      System.out.println("Vértices do cubo:");
      System.out.println("    Antes da rotação após a rotação");
      for (int i = 0; i < 8; i++) {
         Point3D p = v[i];
         // Calcule P1, resultado de P:
         Point3D p1 = Rota3D.rotate(p);
         System.out.println(i + ":  " + 
            p.x + " " + p.y + " " + p.z + "        " + 
            f(p1.x) + " " + f(p1.y) + " " + f(p1.z));
      }
   }

   static double f(double x) {return Math.abs(x) < 1e-10 ? 0.0 : x;}
}
