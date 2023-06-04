/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package com.mycompany.mavenprojectsir;

/**
 *
 * @author fabri
 */
public class MavenprojectSIR {

    public static void main(String args[]) {
        
        InitialFrame ifr = new InitialFrame();
        ifr.setVisible(true);
        try {
            Thread.sleep(2000);
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        ifr.setVisible(false);
        
        MainFrame mf = new MainFrame();
        mf.setVisible(true);
        
    }
}
