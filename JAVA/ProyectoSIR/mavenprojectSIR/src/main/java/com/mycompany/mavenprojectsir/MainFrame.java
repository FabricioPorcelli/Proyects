/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package com.mycompany.mavenprojectsir;
import java.awt.Image;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.LinkedList;
import java.util.List;
import java.util.Objects;
import javax.swing.ImageIcon;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.table.DefaultTableModel;
/**
 *
 * @author fabri
 */
public class MainFrame extends javax.swing.JFrame {

    /**
     * Creates new form MainFrame
     */
    public MainFrame() {
        setTitle("SIR");
       
        initComponents();
        DefaultTableModel model = (DefaultTableModel) tablaBuscar.getModel();
        numTV();
        
        ImageIcon icon = new ImageIcon("images/rueda.png");
        setIconImage(icon.getImage());
        
        List<Televisor> teles = readData();
        // modelo marca tipo fecha de ingreso
        for (Televisor t : teles) {
            model.addRow(new Object[]{t.getKey(),t.getModelo(),t.getMarca(),t.getTipo(),t.getFechaDeIngreso()});
        }       
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        buttonGroup1 = new javax.swing.ButtonGroup();
        buttonGroup2 = new javax.swing.ButtonGroup();
        buttonGroup3 = new javax.swing.ButtonGroup();
        buttonGroup4 = new javax.swing.ButtonGroup();
        buttonGroup5 = new javax.swing.ButtonGroup();
        buttonGroup6 = new javax.swing.ButtonGroup();
        buttonGroup7 = new javax.swing.ButtonGroup();
        buttonGroup8 = new javax.swing.ButtonGroup();
        buttonGroup9 = new javax.swing.ButtonGroup();
        buttonGroup10 = new javax.swing.ButtonGroup();
        buttonGroup11 = new javax.swing.ButtonGroup();
        tabbedPane = new javax.swing.JTabbedPane();
        jPanel1 = new javax.swing.JPanel();
        buttonImageUpload = new javax.swing.JButton();
        componentesPanel = new javax.swing.JPanel();
        checkBoxFuenteIngresar = new javax.swing.JCheckBox();
        checkBoxBacklightIngresar = new javax.swing.JCheckBox();
        checkBoxPanelIngresar = new javax.swing.JCheckBox();
        checkBoxTconIngresar = new javax.swing.JCheckBox();
        checkBoxModuloWifiIngresar = new javax.swing.JCheckBox();
        checkBoxMonoplacaIngresar = new javax.swing.JCheckBox();
        checkBoxInverterIngresar = new javax.swing.JCheckBox();
        checkBoxBotoneraIngresar = new javax.swing.JCheckBox();
        checkBoxMainIngresar = new javax.swing.JCheckBox();
        checkBoxParlantesIngresar = new javax.swing.JCheckBox();
        checkBoxSensorRemotoIngresar = new javax.swing.JCheckBox();
        checkBoxPatasIngresar = new javax.swing.JCheckBox();
        checkBoxBaseIngresar = new javax.swing.JCheckBox();
        jPanel4 = new javax.swing.JPanel();
        textFechaDeIngreso = new javax.swing.JTextField();
        tipoLabelIngresar = new javax.swing.JLabel();
        textNumeroDeSerie = new javax.swing.JTextField();
        numSerieLabelIngresar = new javax.swing.JLabel();
        accesoriosLabelIngresar = new javax.swing.JLabel();
        tipoSMARTRadioButtonIngresar = new javax.swing.JRadioButton();
        textModelo = new javax.swing.JTextField();
        tipoLEDRadioButtonIngresar = new javax.swing.JRadioButton();
        fechaIngresoLabelIngresar = new javax.swing.JLabel();
        tipoLCDRadioButtonIngresar = new javax.swing.JRadioButton();
        modeloLabelIngresar = new javax.swing.JLabel();
        marcaLabelIngresar = new javax.swing.JLabel();
        comboBoxMarca = new javax.swing.JComboBox<>();
        textCodigo = new javax.swing.JTextField();
        textAccesorios = new javax.swing.JTextField();
        codigoLabelIngresar = new javax.swing.JLabel();
        datosAIngresarLabel = new javax.swing.JLabel();
        componentesLabelIngresar = new javax.swing.JLabel();
        imageLabelIngresar = new javax.swing.JLabel();
        jSeparator1 = new javax.swing.JSeparator();
        jScrollPane3 = new javax.swing.JScrollPane();
        textFalla = new javax.swing.JTextArea();
        fallaLabelIngresar = new javax.swing.JLabel();
        buttonUploadIngresar = new javax.swing.JButton();
        jPanel2 = new javax.swing.JPanel();
        marcaLabelBuscar = new javax.swing.JLabel();
        comboBoxMarcaBuscar = new javax.swing.JComboBox<>();
        modeloLabelBuscar = new javax.swing.JLabel();
        textModeloBuscar = new javax.swing.JTextField();
        jScrollPane1 = new javax.swing.JScrollPane();
        tablaBuscar = new javax.swing.JTable();
        buttonEliminar = new javax.swing.JButton();
        buttonComponentes = new javax.swing.JButton();
        buttonBuscar = new javax.swing.JButton();
        buttonMostrarImagenes = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setResizable(false);

        buttonImageUpload.setText("subir");
        buttonImageUpload.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonImageUploadActionPerformed(evt);
            }
        });

        checkBoxFuenteIngresar.setText("fuente");
        checkBoxFuenteIngresar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                checkBoxFuenteIngresarActionPerformed(evt);
            }
        });

        checkBoxBacklightIngresar.setText("backlight");
        checkBoxBacklightIngresar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                checkBoxBacklightIngresarActionPerformed(evt);
            }
        });

        checkBoxPanelIngresar.setText("panel");

        checkBoxTconIngresar.setText("tcon");

        checkBoxModuloWifiIngresar.setText("placa wifi");

        checkBoxMonoplacaIngresar.setText("monoplaca");
        checkBoxMonoplacaIngresar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                checkBoxMonoplacaIngresarActionPerformed(evt);
            }
        });

        checkBoxInverterIngresar.setText("inverter");

        checkBoxBotoneraIngresar.setText("botonera");

        checkBoxMainIngresar.setText("main");
        checkBoxMainIngresar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                checkBoxMainIngresarActionPerformed(evt);
            }
        });

        checkBoxParlantesIngresar.setText("parlantes");

        checkBoxSensorRemotoIngresar.setText("sensor remoto");

        checkBoxPatasIngresar.setText("patas");

        checkBoxBaseIngresar.setText("base");

        javax.swing.GroupLayout componentesPanelLayout = new javax.swing.GroupLayout(componentesPanel);
        componentesPanel.setLayout(componentesPanelLayout);
        componentesPanelLayout.setHorizontalGroup(
            componentesPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(componentesPanelLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(componentesPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(componentesPanelLayout.createSequentialGroup()
                        .addComponent(checkBoxMainIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 85, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(checkBoxBotoneraIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 85, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(checkBoxModuloWifiIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 85, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(componentesPanelLayout.createSequentialGroup()
                        .addComponent(checkBoxFuenteIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 85, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(checkBoxInverterIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 85, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(checkBoxParlantesIngresar))
                    .addGroup(componentesPanelLayout.createSequentialGroup()
                        .addGroup(componentesPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(checkBoxBacklightIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 85, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(checkBoxPatasIngresar))
                        .addGap(18, 18, 18)
                        .addGroup(componentesPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(checkBoxBaseIngresar)
                            .addComponent(checkBoxPanelIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 85, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(componentesPanelLayout.createSequentialGroup()
                        .addComponent(checkBoxMonoplacaIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 85, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(checkBoxTconIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 85, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(checkBoxSensorRemotoIngresar)))
                .addContainerGap())
        );
        componentesPanelLayout.setVerticalGroup(
            componentesPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(componentesPanelLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(componentesPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(checkBoxMainIngresar)
                    .addComponent(checkBoxBotoneraIngresar)
                    .addComponent(checkBoxModuloWifiIngresar))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(componentesPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(checkBoxFuenteIngresar)
                    .addComponent(checkBoxInverterIngresar)
                    .addComponent(checkBoxParlantesIngresar))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(componentesPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(checkBoxMonoplacaIngresar)
                    .addComponent(checkBoxTconIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(checkBoxSensorRemotoIngresar))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(componentesPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(checkBoxBacklightIngresar)
                    .addComponent(checkBoxPanelIngresar))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(componentesPanelLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(checkBoxPatasIngresar)
                    .addComponent(checkBoxBaseIngresar))
                .addContainerGap(10, Short.MAX_VALUE))
        );

        textFechaDeIngreso.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                textFechaDeIngresoActionPerformed(evt);
            }
        });

        tipoLabelIngresar.setText("Tipo");

        textNumeroDeSerie.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                textNumeroDeSerieActionPerformed(evt);
            }
        });

        numSerieLabelIngresar.setText("Numero de serie");

        accesoriosLabelIngresar.setText("Accesorios");

        tipoSMARTRadioButtonIngresar.setText("SMART");

        textModelo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                textModeloActionPerformed(evt);
            }
        });

        tipoLEDRadioButtonIngresar.setText("LED");
        tipoLEDRadioButtonIngresar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tipoLEDRadioButtonIngresarActionPerformed(evt);
            }
        });

        fechaIngresoLabelIngresar.setText("Fecha de ingreso");

        tipoLCDRadioButtonIngresar.setText("LCD");

        modeloLabelIngresar.setText("Modelo");

        marcaLabelIngresar.setText("Marca");

        comboBoxMarca.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { " ", "Samsung", "Noblex", "Philco", "Phillips", "LG", "JVC", "Sony", "Hisense", "TCL", "Hitachi", "Sanyo", " ", " " }));
        comboBoxMarca.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                comboBoxMarcaActionPerformed(evt);
            }
        });

        textCodigo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                textCodigoActionPerformed(evt);
            }
        });

        textAccesorios.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                textAccesoriosActionPerformed(evt);
            }
        });

        codigoLabelIngresar.setText("Codigo");

        javax.swing.GroupLayout jPanel4Layout = new javax.swing.GroupLayout(jPanel4);
        jPanel4.setLayout(jPanel4Layout);
        jPanel4Layout.setHorizontalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                        .addGroup(jPanel4Layout.createSequentialGroup()
                            .addGap(48, 48, 48)
                            .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(tipoLabelIngresar)
                                    .addGroup(jPanel4Layout.createSequentialGroup()
                                        .addComponent(codigoLabelIngresar)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                        .addComponent(textCodigo, javax.swing.GroupLayout.PREFERRED_SIZE, 173, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addGroup(jPanel4Layout.createSequentialGroup()
                                        .addGap(6, 6, 6)
                                        .addComponent(marcaLabelIngresar)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                        .addComponent(comboBoxMarca, javax.swing.GroupLayout.PREFERRED_SIZE, 173, javax.swing.GroupLayout.PREFERRED_SIZE)))
                                .addGroup(jPanel4Layout.createSequentialGroup()
                                    .addComponent(modeloLabelIngresar)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                    .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                        .addComponent(tipoLEDRadioButtonIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(textModelo, javax.swing.GroupLayout.PREFERRED_SIZE, 172, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(tipoLCDRadioButtonIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addComponent(tipoSMARTRadioButtonIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 115, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addGap(1, 1, 1))))
                        .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel4Layout.createSequentialGroup()
                            .addComponent(fechaIngresoLabelIngresar)
                            .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                            .addComponent(textFechaDeIngreso, javax.swing.GroupLayout.PREFERRED_SIZE, 170, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGap(9, 9, 9)))
                    .addGroup(jPanel4Layout.createSequentialGroup()
                        .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(accesoriosLabelIngresar)
                            .addComponent(numSerieLabelIngresar))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(textNumeroDeSerie, javax.swing.GroupLayout.DEFAULT_SIZE, 174, Short.MAX_VALUE)
                            .addComponent(textAccesorios))))
                .addContainerGap(19, Short.MAX_VALUE))
        );
        jPanel4Layout.setVerticalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(codigoLabelIngresar)
                    .addComponent(textCodigo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(fechaIngresoLabelIngresar)
                    .addComponent(textFechaDeIngreso, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(marcaLabelIngresar)
                    .addComponent(comboBoxMarca, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(modeloLabelIngresar)
                    .addComponent(textModelo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(tipoLabelIngresar)
                    .addComponent(tipoLEDRadioButtonIngresar))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(tipoLCDRadioButtonIngresar)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(tipoSMARTRadioButtonIngresar)
                .addGap(18, 18, 18)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(textNumeroDeSerie, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(numSerieLabelIngresar))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(textAccesorios, javax.swing.GroupLayout.PREFERRED_SIZE, 73, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(accesoriosLabelIngresar))
                .addGap(104, 104, 104))
        );

        datosAIngresarLabel.setText("Datos a ingresar");

        componentesLabelIngresar.setText("Componentes disponibles");

        imageLabelIngresar.setText("Imagenes");

        jSeparator1.setOrientation(javax.swing.SwingConstants.VERTICAL);

        textFalla.setColumns(20);
        textFalla.setRows(5);
        jScrollPane3.setViewportView(textFalla);

        fallaLabelIngresar.setText("Falla");

        buttonUploadIngresar.setText("CARGAR");
        buttonUploadIngresar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonUploadIngresarActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addGap(72, 72, 72)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(datosAIngresarLabel)
                    .addComponent(jPanel4, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, 18, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 220, Short.MAX_VALUE)
                        .addComponent(buttonUploadIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 127, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(51, 51, 51))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(componentesLabelIngresar)
                                .addGroup(jPanel1Layout.createSequentialGroup()
                                    .addComponent(fallaLabelIngresar)
                                    .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                    .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 305, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addComponent(componentesPanel, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(imageLabelIngresar)
                            .addComponent(buttonImageUpload, javax.swing.GroupLayout.PREFERRED_SIZE, 101, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(fallaLabelIngresar)
                                    .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addGap(18, 18, 18)
                                .addComponent(componentesLabelIngresar)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(componentesPanel, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(imageLabelIngresar)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(buttonImageUpload, javax.swing.GroupLayout.PREFERRED_SIZE, 33, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(buttonUploadIngresar, javax.swing.GroupLayout.PREFERRED_SIZE, 51, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(10, 10, 10))
                            .addComponent(jSeparator1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 435, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(22, 22, 22)
                        .addComponent(datosAIngresarLabel)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jPanel4, javax.swing.GroupLayout.PREFERRED_SIZE, 413, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addContainerGap(13, Short.MAX_VALUE))
        );

        tabbedPane.addTab("Ingresar", jPanel1);

        marcaLabelBuscar.setText("Marca");

        comboBoxMarcaBuscar.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { " ", "Samsung", "Noblex", "Philco", "Phillips", "LG", "JVC", "Sony", "Hisense", "TCL", "Hitachi", "Sanyo" }));
        comboBoxMarcaBuscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                comboBoxMarcaBuscarActionPerformed(evt);
            }
        });

        modeloLabelBuscar.setText("Modelo");

        textModeloBuscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                textModeloBuscarActionPerformed(evt);
            }
        });

        tablaBuscar.setFont(new java.awt.Font("sansserif", 0, 14)); // NOI18N
        tablaBuscar.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "nº", "modelo", "marca", "tipo", "fecha de ingreso"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.Integer.class, java.lang.String.class, java.lang.String.class, java.lang.String.class, java.lang.String.class
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }
        });
        tablaBuscar.setAutoResizeMode(javax.swing.JTable.AUTO_RESIZE_ALL_COLUMNS);
        tablaBuscar.setName(""); // NOI18N
        tablaBuscar.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        tablaBuscar.setShowGrid(true);
        tablaBuscar.getTableHeader().setReorderingAllowed(false);
        jScrollPane1.setViewportView(tablaBuscar);

        buttonEliminar.setText("eliminar");
        buttonEliminar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonEliminarActionPerformed(evt);
            }
        });

        buttonComponentes.setText("componentes");
        buttonComponentes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonComponentesActionPerformed(evt);
            }
        });

        buttonBuscar.setText("buscar");
        buttonBuscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonBuscarActionPerformed(evt);
            }
        });

        buttonMostrarImagenes.setText("imagenes");
        buttonMostrarImagenes.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                buttonMostrarImagenesActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(30, 30, 30)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(marcaLabelBuscar)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(comboBoxMarcaBuscar, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGap(28, 28, 28)
                        .addComponent(modeloLabelBuscar)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(textModeloBuscar, javax.swing.GroupLayout.PREFERRED_SIZE, 116, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(buttonBuscar)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(buttonMostrarImagenes, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(buttonComponentes))
                        .addGap(18, 18, 18)
                        .addComponent(buttonEliminar, javax.swing.GroupLayout.PREFERRED_SIZE, 104, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 743, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(27, Short.MAX_VALUE))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(43, 43, 43)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(marcaLabelBuscar)
                    .addComponent(comboBoxMarcaBuscar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(modeloLabelBuscar)
                    .addComponent(textModeloBuscar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(buttonComponentes)
                    .addComponent(buttonBuscar)
                    .addComponent(buttonEliminar))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 9, Short.MAX_VALUE)
                .addComponent(buttonMostrarImagenes)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 323, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(27, 27, 27))
        );

        tabbedPane.addTab("Buscar", jPanel2);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(tabbedPane)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(tabbedPane)
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void comboBoxMarcaBuscarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_comboBoxMarcaBuscarActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_comboBoxMarcaBuscarActionPerformed

    private void textModeloBuscarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_textModeloBuscarActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_textModeloBuscarActionPerformed

    private void textAccesoriosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_textAccesoriosActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_textAccesoriosActionPerformed

    private void textCodigoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_textCodigoActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_textCodigoActionPerformed

    private void comboBoxMarcaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_comboBoxMarcaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_comboBoxMarcaActionPerformed

    private void tipoLEDRadioButtonIngresarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tipoLEDRadioButtonIngresarActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tipoLEDRadioButtonIngresarActionPerformed

    private void textModeloActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_textModeloActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_textModeloActionPerformed

    private void textNumeroDeSerieActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_textNumeroDeSerieActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_textNumeroDeSerieActionPerformed

    private void textFechaDeIngresoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_textFechaDeIngresoActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_textFechaDeIngresoActionPerformed

    private void checkBoxMainIngresarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_checkBoxMainIngresarActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_checkBoxMainIngresarActionPerformed

    private void checkBoxMonoplacaIngresarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_checkBoxMonoplacaIngresarActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_checkBoxMonoplacaIngresarActionPerformed

    private void checkBoxBacklightIngresarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_checkBoxBacklightIngresarActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_checkBoxBacklightIngresarActionPerformed

    private void checkBoxFuenteIngresarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_checkBoxFuenteIngresarActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_checkBoxFuenteIngresarActionPerformed

    private void buttonComponentesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonComponentesActionPerformed
        // TODO add your handling code here:
        String modelo = textModeloBuscar.getText();
        
        int index = tablaBuscar.getSelectedRow();
        String modeloDelTV = tablaBuscar.getModel().getValueAt(index, 1).toString();
        String marcaDelTV = tablaBuscar.getModel().getValueAt(index, 2).toString();
        String fechaDelTV = tablaBuscar.getModel().getValueAt(index, 4).toString();

        System.out.println(modeloDelTV + " " + marcaDelTV + " "+ fechaDelTV);
        
        LinkedList<Televisor> listaTV = readData();
        Televisor t1 = new Televisor();
        
        // encuentro el tv seleccionado y lo traigo a una variable local
        for (Televisor t : listaTV) {
            if ((t.getMarca().equals(marcaDelTV))&&(t.getModelo().equals(modeloDelTV))&&(t.getFechaDeIngreso().equals(fechaDelTV))) {
                t1 = t;
            }
        }
        
        // genero el edit frame pasandole el televisor seleccionado
        EditFrame ef = new EditFrame(t1);
        ef.setVisible(true);
        
        
        t1 = ef.devolverValores(t1);
                
        // traigo el televisor y lo guardo 
        for (Televisor t : listaTV) {
            if ((t.getMarca().equals(marcaDelTV))&&(t.getModelo().equals(modeloDelTV))&&(t.getFechaDeIngreso().equals(fechaDelTV))) {
                t = ef.devolverValores(t1);
            }
        }
        
        writeData(listaTV);
    }//GEN-LAST:event_buttonComponentesActionPerformed

    private void buttonUploadIngresarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonUploadIngresarActionPerformed
        // TODO add your handling code here:
        if ((!textModelo.getText().equals(""))||(!textFechaDeIngreso.getText().equals(""))) {
            writeData();
            clearFields();
        }else{
            JOptionPane.showConfirmDialog(null, "Faltan datos necesarios.", "Warning!", JOptionPane.DEFAULT_OPTION);
        }
        cargarTabla();
    }//GEN-LAST:event_buttonUploadIngresarActionPerformed

    private void buttonBuscarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonBuscarActionPerformed
        // TODO add your handling code here:
        String marca = comboBoxMarcaBuscar.getItemAt(comboBoxMarcaBuscar.getSelectedIndex());
        String modelo = textModeloBuscar.getText();
        if ((comboBoxMarcaBuscar.getSelectedIndex() == 0)&&(textModeloBuscar.getText().equals(""))){
            cargarTabla();
        } else if((comboBoxMarcaBuscar.getSelectedIndex() != 0)&&(textModeloBuscar.getText().equals(""))){
            buscarData(marca);
        } else {
            buscarData(modelo,marca);
        }
        comboBoxMarcaBuscar.setSelectedIndex(0);
        textModeloBuscar.setText("");
    }//GEN-LAST:event_buttonBuscarActionPerformed

    private void buttonEliminarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonEliminarActionPerformed
        // TODO add your handling code here:
        int index = tablaBuscar.getSelectedRow();
        String aux = tablaBuscar.getModel().getValueAt(index, 0).toString();
        Integer key = Integer.valueOf(aux);
        LinkedList<Televisor> listAux = readData();
        
        for (Televisor t : listAux) {
            if (Objects.equals(t.getKey(), key)) {
                listAux.remove(t);
            }
        }
        writeData(listAux);
        
        cargarTabla();
    }//GEN-LAST:event_buttonEliminarActionPerformed

    private void buttonImageUploadActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonImageUploadActionPerformed
        // TODO add your handling code here:    
        JFileChooser jFileChooser = new JFileChooser();
        
        FileNameExtensionFilter filtrado = new FileNameExtensionFilter("JPG, PNG o GIF", "jpg", "png", "gif");
        jFileChooser.setFileFilter(filtrado);
        
        int respuesta = jFileChooser.showOpenDialog(this);
        
        if (respuesta == JFileChooser.APPROVE_OPTION) {

            String url = jFileChooser.getSelectedFile().getPath();
            Image mImagen = new ImageIcon(url).getImage();
            ImageIcon mIcono = new ImageIcon(mImagen.getScaledInstance(1920, 1080, Image.SCALE_REPLICATE));
            listaImagenes.add(mIcono); // retengo la imagen cargada
        }
    }//GEN-LAST:event_buttonImageUploadActionPerformed

    private void buttonMostrarImagenesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_buttonMostrarImagenesActionPerformed
        // TODO add your handling code here:
        if (tablaBuscar.getSelectedRow() != -1) {
            
            String index = tablaBuscar.getValueAt(tablaBuscar.getSelectedRow(),0).toString(); // +1
            System.out.println("INDEX = " + index);

            LinkedList<Televisor> listaTV = readData();
            Televisor t1 = new Televisor();
            for (Televisor t : listaTV) {
                System.out.println("t.getKey()" + t.getKey() + " == " + index + " index");
                if (Objects.equals(t.getKey(),Integer.valueOf(index))) {
                    t1 = t;
                }
            }
            if (t1.getListImagenes().isEmpty()) {
                JOptionPane.showConfirmDialog(null, "No hay imagenes cargadas de este televisor.", "Warning!", JOptionPane.DEFAULT_OPTION);
            } else{
                NavigationFrame nf = new NavigationFrame(t1);
                nf.setVisible(true);
            }
        }
        else{
            JOptionPane.showConfirmDialog(null, "No selecciono ningun registro.", "Warning!", JOptionPane.DEFAULT_OPTION);
        }
    }//GEN-LAST:event_buttonMostrarImagenesActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel accesoriosLabelIngresar;
    private javax.swing.JButton buttonBuscar;
    private javax.swing.JButton buttonComponentes;
    private javax.swing.JButton buttonEliminar;
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.ButtonGroup buttonGroup10;
    private javax.swing.ButtonGroup buttonGroup11;
    private javax.swing.ButtonGroup buttonGroup2;
    private javax.swing.ButtonGroup buttonGroup3;
    private javax.swing.ButtonGroup buttonGroup4;
    private javax.swing.ButtonGroup buttonGroup5;
    private javax.swing.ButtonGroup buttonGroup6;
    private javax.swing.ButtonGroup buttonGroup7;
    private javax.swing.ButtonGroup buttonGroup8;
    private javax.swing.ButtonGroup buttonGroup9;
    private javax.swing.JButton buttonImageUpload;
    private javax.swing.JButton buttonMostrarImagenes;
    private javax.swing.JButton buttonUploadIngresar;
    private javax.swing.JCheckBox checkBoxBacklightIngresar;
    private javax.swing.JCheckBox checkBoxBaseIngresar;
    private javax.swing.JCheckBox checkBoxBotoneraIngresar;
    private javax.swing.JCheckBox checkBoxFuenteIngresar;
    private javax.swing.JCheckBox checkBoxInverterIngresar;
    private javax.swing.JCheckBox checkBoxMainIngresar;
    private javax.swing.JCheckBox checkBoxModuloWifiIngresar;
    private javax.swing.JCheckBox checkBoxMonoplacaIngresar;
    private javax.swing.JCheckBox checkBoxPanelIngresar;
    private javax.swing.JCheckBox checkBoxParlantesIngresar;
    private javax.swing.JCheckBox checkBoxPatasIngresar;
    private javax.swing.JCheckBox checkBoxSensorRemotoIngresar;
    private javax.swing.JCheckBox checkBoxTconIngresar;
    private javax.swing.JLabel codigoLabelIngresar;
    private javax.swing.JComboBox<String> comboBoxMarca;
    private javax.swing.JComboBox<String> comboBoxMarcaBuscar;
    private javax.swing.JLabel componentesLabelIngresar;
    private javax.swing.JPanel componentesPanel;
    private javax.swing.JLabel datosAIngresarLabel;
    private javax.swing.JLabel fallaLabelIngresar;
    private javax.swing.JLabel fechaIngresoLabelIngresar;
    private javax.swing.JLabel imageLabelIngresar;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JLabel marcaLabelBuscar;
    private javax.swing.JLabel marcaLabelIngresar;
    private javax.swing.JLabel modeloLabelBuscar;
    private javax.swing.JLabel modeloLabelIngresar;
    private javax.swing.JLabel numSerieLabelIngresar;
    private javax.swing.JTabbedPane tabbedPane;
    private javax.swing.JTable tablaBuscar;
    private javax.swing.JTextField textAccesorios;
    private javax.swing.JTextField textCodigo;
    private javax.swing.JTextArea textFalla;
    private javax.swing.JTextField textFechaDeIngreso;
    private javax.swing.JTextField textModelo;
    private javax.swing.JTextField textModeloBuscar;
    private javax.swing.JTextField textNumeroDeSerie;
    private javax.swing.JRadioButton tipoLCDRadioButtonIngresar;
    private javax.swing.JRadioButton tipoLEDRadioButtonIngresar;
    private javax.swing.JLabel tipoLabelIngresar;
    private javax.swing.JRadioButton tipoSMARTRadioButtonIngresar;
    // End of variables declaration//GEN-END:variables
    
    private Integer numeroDeTelevisor ;
    
    private void numTV(){
        if (readData().isEmpty()) {
            numeroDeTelevisor = 0;
        }else{
            numeroDeTelevisor = readData().getLast().getKey();
        }    
    }
    
    private LinkedList<ImageIcon> listaImagenes = new LinkedList<>();    
    
    public void writeData() {
        List<Televisor> teles = readData(); // OJO SI NO TENGO NADA EN EL ARCHIVO
        Televisor tv = setearValores();
        teles.add(tv);
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("tvdesarme.bin"));
             ObjectOutputStream oosbk = new ObjectOutputStream(new FileOutputStream("tvdesarmeBACKUP.bin"));) {
            for (Televisor t : teles) {
                oos.writeObject(t);
                oosbk.writeObject(t);
            }
//            oos.close();
//            oosbk.close();
        } catch (Exception e) {
            e.printStackTrace();
        } 
    }
    
    public void writeData(List<Televisor> teles) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("tvdesarme.bin"));) {
            for (Televisor t : teles) {
                oos.writeObject(t);
            }
//            oos.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public Televisor setearValores(){
        Televisor tv = new Televisor();
        tv.setCodigo(textCodigo.getText());
        tv.setFechaDeIngreso(textFechaDeIngreso.getText());
        if (tipoLEDRadioButtonIngresar.isSelected()) {
            tv.setTipo("LED");
        } else if (tipoLCDRadioButtonIngresar.isSelected()) {
            tv.setTipo("LCD");
        } else if (tipoSMARTRadioButtonIngresar.isSelected()) {
            tv.setTipo("SMART");
        }
        tv.setMarca(comboBoxMarca.getItemAt(comboBoxMarca.getSelectedIndex()));
        tv.setModelo(textModelo.getText());
        tv.setAccesorios(textAccesorios.getText());
        tv.setMain(checkBoxMainIngresar.isSelected());
        tv.setFuente(checkBoxFuenteIngresar.isSelected());
        tv.setMonoplaca(checkBoxMonoplacaIngresar.isSelected());
        tv.setBacklight(checkBoxBacklightIngresar.isSelected());
        tv.setPanel(checkBoxPanelIngresar.isSelected());
        tv.setInverter(checkBoxInverterIngresar.isSelected());
        tv.setTcon(checkBoxInverterIngresar.isSelected());
        tv.setParlantes(checkBoxParlantesIngresar.isSelected());
        tv.setBotonera(checkBoxBotoneraIngresar.isSelected());
        tv.setSensorRemoto(checkBoxSensorRemotoIngresar.isSelected());
        tv.setModuloWifi(checkBoxModuloWifiIngresar.isSelected());
        tv.setBase(checkBoxBaseIngresar.isSelected());
        tv.setPatas(checkBoxPatasIngresar.isSelected());
        numeroDeTelevisor++;
        tv.setKey(numeroDeTelevisor);
        tv.setListImagenes(listaImagenes); // !!!!!!!!!!
        System.out.println("IS NULL? " + listaImagenes.isEmpty());
        
        return tv;
    }
    
    public void clearFields() {
        
        textCodigo.setText("");
        textFechaDeIngreso.setText("");
        comboBoxMarcaBuscar.setSelectedIndex(0);
        textModelo.setText("");
        tipoLCDRadioButtonIngresar.setSelected(false);
        tipoLEDRadioButtonIngresar.setSelected(false);
        tipoSMARTRadioButtonIngresar.setSelected(false);   
        textNumeroDeSerie.setText("");
        textAccesorios.setText("");
        textFalla.setText("");
              
        checkBoxBacklightIngresar.setSelected(false);
        checkBoxBotoneraIngresar.setSelected(false);
        checkBoxPanelIngresar.setSelected(false);
        checkBoxMainIngresar.setSelected(false);
        checkBoxBacklightIngresar.setSelected(false);
        checkBoxFuenteIngresar.setSelected(false);
        checkBoxMonoplacaIngresar.setSelected(false);
        checkBoxModuloWifiIngresar.setSelected(false);
        checkBoxInverterIngresar.setSelected(false);
        checkBoxTconIngresar.setSelected(false);
        checkBoxParlantesIngresar.setSelected(false);
        checkBoxPatasIngresar.setSelected(false);
        checkBoxBaseIngresar.setSelected(false);
        checkBoxSensorRemotoIngresar.setSelected(false);
        
    }

    private LinkedList<Televisor> readData() {
        Object tv = new Televisor();
        LinkedList<Televisor> listAux = new LinkedList<>();  
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream("tvdesarme.bin"));){
            while (tv!=null){
                tv = ois.readObject();
                listAux.add((Televisor) tv);
            }
            ois.close();
        } catch (IOException e) {

        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
        return listAux;
    }
    
    public void buscarData(String modelo, String marca){
        List<Televisor> teles = readData(); // OJO SI NO TENGO NADA EN EL ARCHIVO
        DefaultTableModel model = (DefaultTableModel) tablaBuscar.getModel();
        borrarRows();
        for (Televisor t : teles) {
            if (((t.getModelo().equals(modelo))&&(t.getMarca().equals(marca)))) {
               model.addRow(new Object[]{t.getKey(),t.getModelo(),t.getMarca(),t.getTipo(),t.getFechaDeIngreso()});
            }
        }
    }
    public void buscarData(String marca){
        List<Televisor> teles = readData(); // OJO SI NO TENGO NADA EN EL ARCHIVO
        
        DefaultTableModel model = (DefaultTableModel) tablaBuscar.getModel();
        borrarRows();
        for (Televisor t : teles) {
            String marca1 = t.getMarca();
            if (Objects.equals(marca,marca1)) {
               model.addRow(new Object[]{t.getKey(),t.getModelo(),t.getMarca(),t.getTipo(),t.getFechaDeIngreso()});
            }
        }
    }
    
    public void borrarRows(){
        DefaultTableModel model = (DefaultTableModel) tablaBuscar.getModel();
        model.setRowCount(0);
        int rows = model.getRowCount();
        for (int i = 1; i < rows; i++) {
            model.removeRow(0);
        }
    }    
    public void cargarTabla(){
        DefaultTableModel modelo = (DefaultTableModel) tablaBuscar.getModel();
        List<Televisor> teles = readData();
        borrarRows();
        // modelo marca tipo fecha de ingreso
        for (Televisor t : teles) {
            modelo.addRow(new Object[]{t.getKey(),t.getModelo(),t.getMarca(),t.getTipo(),t.getFechaDeIngreso()});
        }
    }   
}

