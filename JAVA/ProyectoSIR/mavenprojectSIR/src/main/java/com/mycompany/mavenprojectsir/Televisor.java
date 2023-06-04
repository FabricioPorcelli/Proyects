/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.mavenprojectsir;

import java.awt.Image;
import java.io.File;
import java.io.Serializable;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;

/**
 *
 * @author fabri
 */
class Televisor implements Serializable{
		
    private static final long serialVersionUID = -161729093814178516L;
    
    private Integer key;
    private String codigo;
    private String fechaDeIngreso;
    private String tipo;
    private String marca;
    private String modelo;
    private String accesorios;
    private String numueroDeSerie;
    private String falla;

    private boolean main = false;
    private boolean fuente = false;
    private boolean monoplaca = false;
    private boolean backlight = false;
    private boolean panel = false;
    private boolean inverter = false;
    private boolean tcon = false;
    private boolean parlantes = false;
    private boolean botonera = false;
    private boolean sensorRemoto = false;
    private boolean moduloWifi = false;
    private boolean base = false;
    private boolean patas = false;

    private HashMap<Integer,ImageIcon> listImagenes = new HashMap<>();
    private int indice;
    public Televisor(){
        indice = 0;
    }
    
    @Override
    public String toString() {
            return "TV: \t" + getMarca() + " " + getModelo() + " \n\t"
                            + getTipo() + " " + getFechaDeIngreso();
    }

    public void setListImagenes(LinkedList<ImageIcon> lklist) {
        
        for (ImageIcon img : lklist) {
            indice++;
            listImagenes.put(indice,img);
        }
    }

    public HashMap<Integer,ImageIcon> getListImagenes() {
        // no lo uso por
        
        return listImagenes;
    }
    
    public Integer getKey() {
        return key;
    }

    public void setKey(Integer key) {
        this.key = key;
    }
    
    public void setNumueroDeSerie(String numueroDeSerie) {
        this.numueroDeSerie = numueroDeSerie;
    }

    public void setFalla(String falla) {
        this.falla = falla;
    }

    public static long getSerialVersionUID() {
        return serialVersionUID;
    }

    public String getNumueroDeSerie() {
        return numueroDeSerie;
    }

    public String getFalla() {
        return falla;
    }

    public String getCodigo() {
            return codigo;
    }

    public void setCodigo(String codigo) {
            this.codigo = codigo;
    }

    public String getFechaDeIngreso() {
            return fechaDeIngreso;
    }

    public void setFechaDeIngreso(String fechaDeIngreso) {
            this.fechaDeIngreso = fechaDeIngreso;
    }

    public String getTipo() {
            return tipo;
    }

    public void setTipo(String tipo) {
            this.tipo = tipo;
    }

    public String getMarca() {
            return marca;
    }

    public void setMarca(String marca) {
            this.marca = marca;
    }

    public String getModelo() {
            return modelo;
    }

    public void setModelo(String modelo) {
            this.modelo = modelo;
    }

    public String getAccesorios() {
            return accesorios;
    }

    public void setAccesorios(String accesorios) {
            this.accesorios = accesorios;
    }

    public boolean isMain() {
            return main;
    }

    public void setMain(boolean main) {
            this.main = main;
    }

    public boolean isFuente() {
            return fuente;
    }

    public void setFuente(boolean fuente) {
            this.fuente = fuente;
    }

    public boolean isMonoplaca() {
            return monoplaca;
    }

    public void setMonoplaca(boolean monoplaca) {
            this.monoplaca = monoplaca;
    }

    public boolean isBacklight() {
            return backlight;
    }

    public void setBacklight(boolean backlight) {
            this.backlight = backlight;
    }

    public boolean isPanel() {
            return panel;
    }

    public void setPanel(boolean panel) {
            this.panel = panel;
    }

    public boolean isInverter() {
            return inverter;
    }

    public void setInverter(boolean inverter) {
            this.inverter = inverter;
    }

    public boolean isTcon() {
            return tcon;
    }

    public void setTcon(boolean tcon) {
            this.tcon = tcon;
    }

    public boolean isParlantes() {
            return parlantes;
    }

    public void setParlantes(boolean parlantes) {
            this.parlantes = parlantes;
    }

    public boolean isBotonera() {
            return botonera;
    }

    public void setBotonera(boolean botonera) {
            this.botonera = botonera;
    }

    public boolean isSensorRemoto() {
            return sensorRemoto;
    }

    public void setSensorRemoto(boolean sensorRemoto) {
            this.sensorRemoto = sensorRemoto;
    }

    public boolean isModuloWifi() {
            return moduloWifi;
    }

    public void setModuloWifi(boolean moduloWifi) {
            this.moduloWifi = moduloWifi;
    }

    public boolean isBase() {
            return base;
    }

    public void setBase(boolean base) {
            this.base = base;
    }

    public boolean isPatas() {
            return patas;
    }

    public void setPatas(boolean patas) {
            this.patas = patas;
    }
}
