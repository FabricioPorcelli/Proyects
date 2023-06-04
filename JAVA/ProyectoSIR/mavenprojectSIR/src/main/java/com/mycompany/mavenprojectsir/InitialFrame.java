/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mavenprojectsir;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JWindow;

public class InitialFrame extends JWindow{
    private static final long serialVersionUID = -7728697886172831623L;
    ImagenFondo img = new ImagenFondo();

//	Font fuenteTitulo = new java.awt.Font("Tahoma", 1, 20);
//	Font fuenteCuerpo = new java.awt.Font("Tahoma", 1, 12);

    InitialFrame() {
        setContentPane(img);		
        // Dimensiones
        Dimension d = new Dimension(450, 300);
        setMinimumSize(d);
        setPreferredSize(d);
        setMaximumSize(d);
        setLocationRelativeTo(null);	
    }

    class ImagenFondo extends JPanel{
        Image imagen;
        private static final long serialVersionUID = 1L;
        public void paint(Graphics g) {
            imagen = new ImageIcon(getClass().getResource("/images/sir2.jpg")).getImage();
            g.drawImage(imagen, 0, 0, getWidth(), getHeight(), this);
            setOpaque(false);
            super.paint(g);
        }
    }
}	