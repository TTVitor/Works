// UC19200602 Vítor Gabriel Barbosa dos Santos
// UCB - Universidade Católica de Brasília
// DefPoly.java: Desenhando um polígono.
// Uses: CvDefPoly (discussed below).

// Copied from Section 1.5 of
//    Ammeraal, L. and K. Zhang (2007). Computer Graphics for Java Programmers, 2nd Edition,
//       Chichester: John Wiley.

import java.awt.*;
import java.awt.event.*;

public class DefPoly extends Frame {
   public static void main(String[] args) {new DefPoly();}

   DefPoly() {
      super("Defina vértices de polígonos clicando");
      addWindowListener(new WindowAdapter() {
         public void windowClosing(WindowEvent e) {System.exit(0);}
      });
      setSize(500, 300);
      add("Centro", new CvDefPoly());
      setCursor(Cursor.getPredefinedCursor(Cursor.CROSSHAIR_CURSOR));
      setVisible(true);
   }
}
