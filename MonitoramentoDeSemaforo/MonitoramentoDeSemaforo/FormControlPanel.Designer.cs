﻿namespace ControleDeReservatorio
{
    partial class FormControlPanel
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.panelMenu = new System.Windows.Forms.Panel();
            this.btnRegiterUser = new System.Windows.Forms.Button();
            this.panel3 = new System.Windows.Forms.Panel();
            this.pnl_serial = new System.Windows.Forms.Panel();
            this.cbBaudRate = new System.Windows.Forms.ComboBox();
            this.btnUpdateSerialPorts = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.cbSerialPort = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.btnConnect = new System.Windows.Forms.Button();
            this.panel2 = new System.Windows.Forms.Panel();
            this.pnl_nav = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.panel4 = new System.Windows.Forms.Panel();
            this.lbl_login_date = new System.Windows.Forms.Label();
            this.lbl_username = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.btnExit = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.label8 = new System.Windows.Forms.Label();
            this.btnStartVideo = new System.Windows.Forms.Button();
            this.pbVideo = new System.Windows.Forms.PictureBox();
            this.cbCamera = new System.Windows.Forms.ComboBox();
            this.btnEmergencia1 = new System.Windows.Forms.Button();
            this.pbSemaforo4 = new System.Windows.Forms.PictureBox();
            this.pbSemaforo3 = new System.Windows.Forms.PictureBox();
            this.pbSemaforo2 = new System.Windows.Forms.PictureBox();
            this.pbSemaforo1 = new System.Windows.Forms.PictureBox();
            this.bindingSource1 = new System.Windows.Forms.BindingSource(this.components);
            this.panel5 = new System.Windows.Forms.Panel();
            this.btnPedestre2 = new System.Windows.Forms.Button();
            this.btnPedestre1 = new System.Windows.Forms.Button();
            this.panelMenu.SuspendLayout();
            this.panel3.SuspendLayout();
            this.pnl_serial.SuspendLayout();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbVideo)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSemaforo4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSemaforo3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSemaforo2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSemaforo1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource1)).BeginInit();
            this.panel5.SuspendLayout();
            this.SuspendLayout();
            // 
            // serialPort1
            // 
            this.serialPort1.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_DataReceived);
            // 
            // panelMenu
            // 
            this.panelMenu.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(24)))), ((int)(((byte)(30)))), ((int)(((byte)(54)))));
            this.panelMenu.Controls.Add(this.btnRegiterUser);
            this.panelMenu.Controls.Add(this.panel3);
            this.panelMenu.Controls.Add(this.panel2);
            this.panelMenu.Dock = System.Windows.Forms.DockStyle.Left;
            this.panelMenu.Location = new System.Drawing.Point(0, 0);
            this.panelMenu.Name = "panelMenu";
            this.panelMenu.Size = new System.Drawing.Size(291, 747);
            this.panelMenu.TabIndex = 0;
            // 
            // btnRegiterUser
            // 
            this.btnRegiterUser.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnRegiterUser.FlatAppearance.BorderSize = 0;
            this.btnRegiterUser.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnRegiterUser.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRegiterUser.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(25)))), ((int)(((byte)(175)))), ((int)(((byte)(215)))));
            this.btnRegiterUser.Image = global::MonitoramentoDeSemaforo.Properties.Resources.Contact;
            this.btnRegiterUser.Location = new System.Drawing.Point(0, 174);
            this.btnRegiterUser.Name = "btnRegiterUser";
            this.btnRegiterUser.Size = new System.Drawing.Size(291, 59);
            this.btnRegiterUser.TabIndex = 5;
            this.btnRegiterUser.Text = "Cadastrar Usuário";
            this.btnRegiterUser.TextImageRelation = System.Windows.Forms.TextImageRelation.TextBeforeImage;
            this.btnRegiterUser.UseVisualStyleBackColor = true;
            this.btnRegiterUser.Visible = false;
            this.btnRegiterUser.Click += new System.EventHandler(this.btnRegiterUser_Click);
            // 
            // panel3
            // 
            this.panel3.Controls.Add(this.pnl_serial);
            this.panel3.Controls.Add(this.btnConnect);
            this.panel3.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.panel3.Location = new System.Drawing.Point(0, 494);
            this.panel3.Name = "panel3";
            this.panel3.Size = new System.Drawing.Size(291, 253);
            this.panel3.TabIndex = 1;
            // 
            // pnl_serial
            // 
            this.pnl_serial.Controls.Add(this.cbBaudRate);
            this.pnl_serial.Controls.Add(this.btnUpdateSerialPorts);
            this.pnl_serial.Controls.Add(this.label2);
            this.pnl_serial.Controls.Add(this.cbSerialPort);
            this.pnl_serial.Controls.Add(this.label3);
            this.pnl_serial.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnl_serial.Location = new System.Drawing.Point(0, 0);
            this.pnl_serial.Margin = new System.Windows.Forms.Padding(2);
            this.pnl_serial.Name = "pnl_serial";
            this.pnl_serial.Size = new System.Drawing.Size(291, 187);
            this.pnl_serial.TabIndex = 0;
            // 
            // cbBaudRate
            // 
            this.cbBaudRate.FormattingEnabled = true;
            this.cbBaudRate.Items.AddRange(new object[] {
            "4800",
            "9600",
            "19200",
            "115200"});
            this.cbBaudRate.Location = new System.Drawing.Point(9, 118);
            this.cbBaudRate.Name = "cbBaudRate";
            this.cbBaudRate.Size = new System.Drawing.Size(272, 24);
            this.cbBaudRate.TabIndex = 5;
            // 
            // btnUpdateSerialPorts
            // 
            this.btnUpdateSerialPorts.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnUpdateSerialPorts.FlatAppearance.BorderSize = 0;
            this.btnUpdateSerialPorts.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnUpdateSerialPorts.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Underline, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnUpdateSerialPorts.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(45)))), ((int)(((byte)(218)))), ((int)(((byte)(188)))));
            this.btnUpdateSerialPorts.Location = new System.Drawing.Point(0, 152);
            this.btnUpdateSerialPorts.Name = "btnUpdateSerialPorts";
            this.btnUpdateSerialPorts.Size = new System.Drawing.Size(291, 35);
            this.btnUpdateSerialPorts.TabIndex = 2;
            this.btnUpdateSerialPorts.Text = "Actualizar";
            this.btnUpdateSerialPorts.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnUpdateSerialPorts.UseVisualStyleBackColor = true;
            this.btnUpdateSerialPorts.Click += new System.EventHandler(this.btnUpdateSerialPorts_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(226)))), ((int)(((byte)(226)))), ((int)(((byte)(249)))));
            this.label2.Location = new System.Drawing.Point(15, 11);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(107, 23);
            this.label2.TabIndex = 0;
            this.label2.Text = "Porta Serial:";
            // 
            // cbSerialPort
            // 
            this.cbSerialPort.FormattingEnabled = true;
            this.cbSerialPort.Location = new System.Drawing.Point(9, 51);
            this.cbSerialPort.Name = "cbSerialPort";
            this.cbSerialPort.Size = new System.Drawing.Size(272, 24);
            this.cbSerialPort.TabIndex = 1;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(226)))), ((int)(((byte)(226)))), ((int)(((byte)(249)))));
            this.label3.Location = new System.Drawing.Point(9, 90);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(97, 23);
            this.label3.TabIndex = 4;
            this.label3.Text = "Baud Rate:";
            // 
            // btnConnect
            // 
            this.btnConnect.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnConnect.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnConnect.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnConnect.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.btnConnect.Location = new System.Drawing.Point(0, 190);
            this.btnConnect.Name = "btnConnect";
            this.btnConnect.Size = new System.Drawing.Size(291, 63);
            this.btnConnect.TabIndex = 3;
            this.btnConnect.Text = "Conectar";
            this.btnConnect.UseVisualStyleBackColor = true;
            this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.pnl_nav);
            this.panel2.Controls.Add(this.label1);
            this.panel2.Controls.Add(this.panel4);
            this.panel2.Controls.Add(this.lbl_login_date);
            this.panel2.Controls.Add(this.lbl_username);
            this.panel2.Controls.Add(this.pictureBox1);
            this.panel2.Dock = System.Windows.Forms.DockStyle.Top;
            this.panel2.Location = new System.Drawing.Point(0, 0);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(291, 174);
            this.panel2.TabIndex = 1;
            // 
            // pnl_nav
            // 
            this.pnl_nav.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(126)))), ((int)(((byte)(249)))));
            this.pnl_nav.Location = new System.Drawing.Point(0, 232);
            this.pnl_nav.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pnl_nav.Name = "pnl_nav";
            this.pnl_nav.Size = new System.Drawing.Size(3, 80);
            this.pnl_nav.TabIndex = 5;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.ForeColor = System.Drawing.Color.White;
            this.label1.Location = new System.Drawing.Point(36, 137);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(55, 15);
            this.label1.TabIndex = 3;
            this.label1.Text = "Ligado:";
            // 
            // panel4
            // 
            this.panel4.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(126)))), ((int)(((byte)(249)))));
            this.panel4.Location = new System.Drawing.Point(0, 193);
            this.panel4.Name = "panel4";
            this.panel4.Size = new System.Drawing.Size(3, 100);
            this.panel4.TabIndex = 2;
            // 
            // lbl_login_date
            // 
            this.lbl_login_date.AutoSize = true;
            this.lbl_login_date.Font = new System.Drawing.Font("Microsoft Sans Serif", 7.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_login_date.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(158)))), ((int)(((byte)(161)))), ((int)(((byte)(178)))));
            this.lbl_login_date.Location = new System.Drawing.Point(98, 137);
            this.lbl_login_date.Name = "lbl_login_date";
            this.lbl_login_date.Size = new System.Drawing.Size(63, 15);
            this.lbl_login_date.TabIndex = 2;
            this.lbl_login_date.Text = "14:31:02";
            // 
            // lbl_username
            // 
            this.lbl_username.AutoSize = true;
            this.lbl_username.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lbl_username.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(126)))), ((int)(((byte)(249)))));
            this.lbl_username.Location = new System.Drawing.Point(87, 101);
            this.lbl_username.Name = "lbl_username";
            this.lbl_username.Size = new System.Drawing.Size(94, 20);
            this.lbl_username.TabIndex = 1;
            this.lbl_username.Text = "Username";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::MonitoramentoDeSemaforo.Properties.Resources.Usuario;
            this.pictureBox1.Location = new System.Drawing.Point(92, 10);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(69, 78);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // btnExit
            // 
            this.btnExit.FlatAppearance.BorderSize = 0;
            this.btnExit.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnExit.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnExit.ForeColor = System.Drawing.Color.White;
            this.btnExit.Location = new System.Drawing.Point(486, 3);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(78, 74);
            this.btnExit.TabIndex = 13;
            this.btnExit.Text = "x";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click_2);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(226)))), ((int)(((byte)(226)))), ((int)(((byte)(249)))));
            this.label4.Location = new System.Drawing.Point(103, 322);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(105, 23);
            this.label4.TabIndex = 6;
            this.label4.Text = "Semaforo-1";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(226)))), ((int)(((byte)(226)))), ((int)(((byte)(249)))));
            this.label5.Location = new System.Drawing.Point(420, 322);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(105, 23);
            this.label5.TabIndex = 18;
            this.label5.Text = "Semaforo-2";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(226)))), ((int)(((byte)(226)))), ((int)(((byte)(249)))));
            this.label6.Location = new System.Drawing.Point(95, 658);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(105, 23);
            this.label6.TabIndex = 19;
            this.label6.Text = "Semaforo-3";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(226)))), ((int)(((byte)(226)))), ((int)(((byte)(249)))));
            this.label7.Location = new System.Drawing.Point(420, 658);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(105, 23);
            this.label7.TabIndex = 20;
            this.label7.Text = "Semaforo-4";
            // 
            // panel1
            // 
            this.panel1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(24)))), ((int)(((byte)(30)))), ((int)(((byte)(54)))));
            this.panel1.Controls.Add(this.label8);
            this.panel1.Controls.Add(this.btnStartVideo);
            this.panel1.Controls.Add(this.pbVideo);
            this.panel1.Controls.Add(this.cbCamera);
            this.panel1.Controls.Add(this.btnExit);
            this.panel1.Dock = System.Windows.Forms.DockStyle.Right;
            this.panel1.Location = new System.Drawing.Point(906, 0);
            this.panel1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(564, 747);
            this.panel1.TabIndex = 21;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Nirmala UI", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(226)))), ((int)(((byte)(226)))), ((int)(((byte)(249)))));
            this.label8.Location = new System.Drawing.Point(44, 554);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(76, 23);
            this.label8.TabIndex = 6;
            this.label8.Text = "Câmera:";
            // 
            // btnStartVideo
            // 
            this.btnStartVideo.BackColor = System.Drawing.Color.Transparent;
            this.btnStartVideo.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnStartVideo.Font = new System.Drawing.Font("Nirmala UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnStartVideo.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.btnStartVideo.Location = new System.Drawing.Point(189, 642);
            this.btnStartVideo.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnStartVideo.Name = "btnStartVideo";
            this.btnStartVideo.Size = new System.Drawing.Size(211, 45);
            this.btnStartVideo.TabIndex = 16;
            this.btnStartVideo.Text = "Iniciar Transmissão";
            this.btnStartVideo.UseVisualStyleBackColor = false;
            this.btnStartVideo.Click += new System.EventHandler(this.btnStartVideo_Click);
            // 
            // pbVideo
            // 
            this.pbVideo.Image = global::MonitoramentoDeSemaforo.Properties.Resources.AutomaTic;
            this.pbVideo.Location = new System.Drawing.Point(37, 83);
            this.pbVideo.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pbVideo.Name = "pbVideo";
            this.pbVideo.Size = new System.Drawing.Size(486, 469);
            this.pbVideo.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbVideo.TabIndex = 15;
            this.pbVideo.TabStop = false;
            // 
            // cbCamera
            // 
            this.cbCamera.FormattingEnabled = true;
            this.cbCamera.Location = new System.Drawing.Point(48, 588);
            this.cbCamera.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.cbCamera.Name = "cbCamera";
            this.cbCamera.Size = new System.Drawing.Size(453, 24);
            this.cbCamera.TabIndex = 14;
            // 
            // btnEmergencia1
            // 
            this.btnEmergencia1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(46)))), ((int)(((byte)(51)))), ((int)(((byte)(73)))));
            this.btnEmergencia1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnEmergencia1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnEmergencia1.Font = new System.Drawing.Font("Nirmala UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnEmergencia1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.btnEmergencia1.Location = new System.Drawing.Point(0, 684);
            this.btnEmergencia1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnEmergencia1.Name = "btnEmergencia1";
            this.btnEmergencia1.Size = new System.Drawing.Size(615, 63);
            this.btnEmergencia1.TabIndex = 17;
            this.btnEmergencia1.Text = "Emergência";
            this.btnEmergencia1.UseVisualStyleBackColor = false;
            this.btnEmergencia1.Click += new System.EventHandler(this.btnEmergencia_Click);
            // 
            // pbSemaforo4
            // 
            this.pbSemaforo4.Image = global::MonitoramentoDeSemaforo.Properties.Resources.yellow;
            this.pbSemaforo4.Location = new System.Drawing.Point(364, 366);
            this.pbSemaforo4.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pbSemaforo4.Name = "pbSemaforo4";
            this.pbSemaforo4.Size = new System.Drawing.Size(213, 286);
            this.pbSemaforo4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbSemaforo4.TabIndex = 17;
            this.pbSemaforo4.TabStop = false;
            // 
            // pbSemaforo3
            // 
            this.pbSemaforo3.Image = global::MonitoramentoDeSemaforo.Properties.Resources.yellow;
            this.pbSemaforo3.Location = new System.Drawing.Point(44, 366);
            this.pbSemaforo3.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pbSemaforo3.Name = "pbSemaforo3";
            this.pbSemaforo3.Size = new System.Drawing.Size(213, 286);
            this.pbSemaforo3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbSemaforo3.TabIndex = 16;
            this.pbSemaforo3.TabStop = false;
            // 
            // pbSemaforo2
            // 
            this.pbSemaforo2.Image = global::MonitoramentoDeSemaforo.Properties.Resources.yellow;
            this.pbSemaforo2.Location = new System.Drawing.Point(364, 26);
            this.pbSemaforo2.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pbSemaforo2.Name = "pbSemaforo2";
            this.pbSemaforo2.Size = new System.Drawing.Size(213, 286);
            this.pbSemaforo2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbSemaforo2.TabIndex = 15;
            this.pbSemaforo2.TabStop = false;
            // 
            // pbSemaforo1
            // 
            this.pbSemaforo1.Image = global::MonitoramentoDeSemaforo.Properties.Resources.yellow;
            this.pbSemaforo1.Location = new System.Drawing.Point(44, 26);
            this.pbSemaforo1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.pbSemaforo1.Name = "pbSemaforo1";
            this.pbSemaforo1.Size = new System.Drawing.Size(213, 286);
            this.pbSemaforo1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pbSemaforo1.TabIndex = 14;
            this.pbSemaforo1.TabStop = false;
            // 
            // panel5
            // 
            this.panel5.Controls.Add(this.btnPedestre1);
            this.panel5.Controls.Add(this.btnPedestre2);
            this.panel5.Controls.Add(this.btnEmergencia1);
            this.panel5.Controls.Add(this.pbSemaforo1);
            this.panel5.Controls.Add(this.label4);
            this.panel5.Controls.Add(this.pbSemaforo2);
            this.panel5.Controls.Add(this.label7);
            this.panel5.Controls.Add(this.label5);
            this.panel5.Controls.Add(this.pbSemaforo3);
            this.panel5.Controls.Add(this.pbSemaforo4);
            this.panel5.Controls.Add(this.label6);
            this.panel5.Dock = System.Windows.Forms.DockStyle.Fill;
            this.panel5.Location = new System.Drawing.Point(291, 0);
            this.panel5.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.panel5.Name = "panel5";
            this.panel5.Size = new System.Drawing.Size(615, 747);
            this.panel5.TabIndex = 22;
            // 
            // btnPedestre2
            // 
            this.btnPedestre2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(46)))), ((int)(((byte)(51)))), ((int)(((byte)(73)))));
            this.btnPedestre2.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnPedestre2.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnPedestre2.Font = new System.Drawing.Font("Nirmala UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnPedestre2.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(220)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.btnPedestre2.Location = new System.Drawing.Point(0, 621);
            this.btnPedestre2.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnPedestre2.Name = "btnPedestre2";
            this.btnPedestre2.Size = new System.Drawing.Size(615, 63);
            this.btnPedestre2.TabIndex = 21;
            this.btnPedestre2.Text = "Pedestre 2";
            this.btnPedestre2.UseVisualStyleBackColor = false;
            this.btnPedestre2.Click += new System.EventHandler(this.button1_Click);
            // 
            // btnPedestre1
            // 
            this.btnPedestre1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(46)))), ((int)(((byte)(51)))), ((int)(((byte)(73)))));
            this.btnPedestre1.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.btnPedestre1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnPedestre1.Font = new System.Drawing.Font("Nirmala UI", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnPedestre1.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(220)))), ((int)(((byte)(192)))), ((int)(((byte)(0)))));
            this.btnPedestre1.Location = new System.Drawing.Point(0, 558);
            this.btnPedestre1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.btnPedestre1.Name = "btnPedestre1";
            this.btnPedestre1.Size = new System.Drawing.Size(615, 63);
            this.btnPedestre1.TabIndex = 22;
            this.btnPedestre1.Text = "Pedestre 1";
            this.btnPedestre1.UseVisualStyleBackColor = false;
            this.btnPedestre1.Click += new System.EventHandler(this.btnPedestre1_Click);
            // 
            // FormControlPanel
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(46)))), ((int)(((byte)(51)))), ((int)(((byte)(73)))));
            this.ClientSize = new System.Drawing.Size(1470, 747);
            this.Controls.Add(this.panel5);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.panelMenu);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.MinimumSize = new System.Drawing.Size(1278, 644);
            this.Name = "FormControlPanel";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FormControlPanel_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.panelMenu.ResumeLayout(false);
            this.panel3.ResumeLayout(false);
            this.pnl_serial.ResumeLayout(false);
            this.pnl_serial.PerformLayout();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pbVideo)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSemaforo4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSemaforo3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSemaforo2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pbSemaforo1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.bindingSource1)).EndInit();
            this.panel5.ResumeLayout(false);
            this.panel5.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Panel panelMenu;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label lbl_login_date;
        private System.Windows.Forms.Label lbl_username;
        private System.Windows.Forms.Panel panel3;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.ComboBox cbSerialPort;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox cbBaudRate;
        private System.Windows.Forms.Panel panel4;
        private System.Windows.Forms.Button btnUpdateSerialPorts;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Panel pnl_nav;
        private System.Windows.Forms.Button btnRegiterUser;
        private System.Windows.Forms.BindingSource bindingSource1;
        private System.Windows.Forms.Panel pnl_serial;
        private System.Windows.Forms.Button btnExit;
        private System.Windows.Forms.PictureBox pbSemaforo1;
        private System.Windows.Forms.PictureBox pbSemaforo2;
        private System.Windows.Forms.PictureBox pbSemaforo3;
        private System.Windows.Forms.PictureBox pbSemaforo4;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Button btnStartVideo;
        private System.Windows.Forms.PictureBox pbVideo;
        private System.Windows.Forms.ComboBox cbCamera;
        private System.Windows.Forms.Button btnEmergencia1;
        private System.Windows.Forms.Panel panel5;
        private System.Windows.Forms.Button btnPedestre2;
        private System.Windows.Forms.Button btnPedestre1;
    }
}

