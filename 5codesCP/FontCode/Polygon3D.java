// UC19200602 Vítor Gabriel Barbosa dos Santos
// UCB - Universidade Católica de Brasília
// Polygon3D.java: Polígono em 3D, representado por números de vértices
// referindo -se a coordenadas armazenadas em um objeto Obj3d.
// Uses: Point2D (Section 1.5), Tria (Section 5.5.3), 
//       Obj3D (Section 5.6)
import java.util.*;

class Polygon3D {
   private int[] nrs;
   private double a, b, c, h;
   private Tria[] t;

   Polygon3D(Vector<Integer> vnrs) {
      int n = vnrs.size();
      nrs = new int[n];
      for (int i = 0; i < n; i++)
         nrs[i] = ((Integer) vnrs.elementAt(i)).intValue();
   }

   int[] getNrs() {return nrs;}
   double getA() {return a;}
   double getB() {return b;}
   double getC() {return c;}
   double getH() {return h;}

   void setAbch(double a, double b, double c, double h) {
      this.a = a; this.b = b; this.c = c; this.h = h;
   }

   Tria[] getT() {return t;}

   Tria[] triangulate(Obj3D obj) {
      // Números sucessivos de vértices (CCW) no vetor NRS.
      // triângulos resultantes serão colocados na matriz t.
      Point2D[] vScr = obj.getVScr();            
      Polygon2D polygon = new Polygon2D(vScr, nrs);
      t = polygon.triangulate();
      return t;
   }
}