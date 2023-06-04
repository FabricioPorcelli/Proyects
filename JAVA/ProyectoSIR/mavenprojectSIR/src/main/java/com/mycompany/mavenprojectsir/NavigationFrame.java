/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package com.mycompany.mavenprojectsir;

import java.awt.Image;
import java.util.HashMap;
import javax.swing.ImageIcon;

/**
 *
 * @author fabri
 */
public class NavigationFrame extends javax.swing.JFrame {

    int pos = 1;
    Televisor t1 = new Televisor();
    HashMap<Integer,ImageIcon> listaTV ;
    
    public NavigationFrame(Televisor t) {
        t1 = t;
        initComponents();
        listaTV = t1.getListImagenes();
//        System.out.println("t1 IS NULL? " + t1.getListImagenes().isEmpty());
//        System.out.println("listaTV IS NULL? " + listaTV.isEmpty());

        showImage(pos);
    }
    
    public void showImage(int index){

        System.out.println("listaTV get pos " +listaTV.get(pos));
        System.out.println("pos = "+pos);
        ImageIcon icon = listaTV.get(pos);
        Image image = icon.getImage().getScaledInstance(jLabel_Imagenes.getWidth(), jLabel_Imagenes.getHeight(), Image.SCALE_SMOOTH);
        jLabel_Imagenes.setIcon(new ImageIcon(image));
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel_Imagenes = new javax.swing.JLabel();
        buttonPrimera = new javax.swing.JButton();
        buttonSiguiente = new javax.swing.JButton();
        buttonAnterior = new javax.swing.JButton();
        buttonUltima = new javax.swing.JButton();

        setResizable(false);

        jLabel_Imagenes.setAlignmentX(0.5F);
        jLabel_Imagenes.setDebugGraphicsOptions(javax.swing.DebugGraphics.NONE_OPTION);

        buttonPrimera.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/primero.png"))); // NOI18N
        buttonPrimera.setText("Primera");
        buttonPrimera.setToolTipText("");
        buttonPrimera.setHorizontalAlignment(javax.swing.SwingConstants.LEFT);
        buttonPrimera.setOpaque(true);
        buttonPrimera.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/images/primero.png"))); // NOI18N
        buttonPrimera.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonPrimeraActionPerformed(evt);
            }
        });

        buttonSiguiente.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/proximo.png"))); // NOI18N
        buttonSiguiente.setText("Siguiente");
        buttonSiguiente.setToolTipText("");
        buttonSiguiente.setBorderPainted(false);
        buttonSiguiente.setIconTextGap(0);
        buttonSiguiente.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/images/proximo.png"))); // NOI18N
        buttonSiguiente.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonSiguienteActionPerformed(evt);
            }
        });

        buttonAnterior.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/anterior.png"))); // NOI18N
        buttonAnterior.setText("Anterior");
        buttonAnterior.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        buttonAnterior.setHorizontalTextPosition(javax.swing.SwingConstants.LEADING);
        buttonAnterior.setIconTextGap(0);
        buttonAnterior.setMultiClickThreshhold(4L);
        buttonAnterior.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/images/anterior.png"))); // NOI18N
        buttonAnterior.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonAnteriorActionPerformed(evt);
            }
        });

        buttonUltima.setIcon(new javax.swing.ImageIcon(getClass().getResource("/images/ultimo.png"))); // NOI18N
        buttonUltima.setText("Última");
        buttonUltima.setHorizontalTextPosition(javax.swing.SwingConstants.LEADING);
        buttonUltima.setSelectedIcon(new javax.swing.ImageIcon(getClass().getResource("/images/ultimo.png"))); // NOI18N
        buttonUltima.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonUltimaActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap(226, Short.MAX_VALUE)
                .addComponent(buttonPrimera, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(75, 75, 75)
                .addComponent(buttonAnterior, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(71, 71, 71)
                .addComponent(buttonSiguiente, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(81, 81, 81)
                .addComponent(buttonUltima, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(287, 287, 287))
            .addComponent(jLabel_Imagenes, javax.swing.GroupLayout.DEFAULT_SIZE, 1200, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(jLabel_Imagenes, javax.swing.GroupLayout.DEFAULT_SIZE, 688, Short.MAX_VALUE)
                .addGap(28, 28, 28)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(buttonPrimera, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(buttonSiguiente, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(buttonAnterior, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(buttonUltima, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(34, 34, 34))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void buttonSiguienteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonSiguienteActionPerformed
        // TODO add your handling code here:
        pos = pos + 1;
        if (pos > listaTV.size()) {
            pos = listaTV.size();
        }
        showImage(pos);
    }//GEN-LAST:event_buttonSiguienteActionPerformed

    private void buttonPrimeraActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonPrimeraActionPerformed
        // TODO add your handling code here:
        pos = 1;
        showImage(pos);
        
    }//GEN-LAST:event_buttonPrimeraActionPerformed

    private void buttonUltimaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonUltimaActionPerformed
        // TODO add your handling code here:
        pos = listaTV.size();
        showImage(pos);
    }//GEN-LAST:event_buttonUltimaActionPerformed

    private void buttonAnteriorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonAnteriorActionPerformed
        // TODO add your handling code here:
        pos = pos - 1;
        if (pos <= 1) {
            pos = 1;
        }
        showImage(pos);
    }//GEN-LAST:event_buttonAnteriorActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton buttonAnterior;
    private javax.swing.JButton buttonPrimera;
    private javax.swing.JButton buttonSiguiente;
    private javax.swing.JButton buttonUltima;
    private javax.swing.JLabel jLabel_Imagenes;
    // End of variables declaration//GEN-END:variables
}
