﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Media;
using ControleDeReservatorio.Models;
using AForge.Video;
using AForge.Video.DirectShow;


namespace ControleDeReservatorio
{

    public partial class FormControlPanel : Form
    {
        private FormRegister formRegister;
        private UserModel user;
        private FilterInfoCollection filterInfoCollection;
        private VideoCaptureDevice videoCaptureDevice;


        public FormControlPanel()
        {
            InitializeComponent();
            initSerial();
            lbl_login_date.Text = DateTime.Now.ToString("dd/MM/yyyy HH:mm:ss");
        }

        public FormControlPanel(UserModel user)
        {
            InitializeComponent();
            initSerial();
            this.user = user;
            lbl_username.Text = user.getUsername();
            lbl_login_date.Text = DateTime.Now.ToString("dd/MM/yyyy HH:mm:ss");
            
            //formRegister = new FormRegister(this.user) { Dock = DockStyle.Fill, TopLevel = false, TopMost = true };
            //formRegister.FormBorderStyle = FormBorderStyle.None;
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            closeCOMPort();
            Application.Exit();
        }


        private void btnConnect_Click(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                closeCOMPort();
                btnConnect.Text = "Conectar";
                btnConnect.ForeColor = Color.Green;
                cbBaudRate.Enabled = true;
                cbSerialPort.Enabled = true;
                btnUpdateSerialPorts.Enabled = true;
                pnl_serial.Visible = true;
            }
            else
            {
                serialPort1.PortName = cbSerialPort.Text;
                serialPort1.BaudRate = Int16.Parse(cbBaudRate.Text);
                try
                {
                    serialPort1.Open();
                    btnConnect.Text = "Desconectar";
                    btnConnect.ForeColor = Color.Red;
                    cbBaudRate.Enabled = false;
                    cbSerialPort.Enabled = false;
                    btnUpdateSerialPorts.Enabled = false;
                    pnl_serial.Visible = false;
                    MessageBox.Show("Comunicação com os Reservatórios Estabelecida com Sucesso!", "Comunicação", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                catch
                {
                    MessageBox.Show("Porta \"" + cbSerialPort.Text + "\" já está sendo usada por outro programa!", "Erro de Conexão com a COM", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }

       
        private void Form1_Load(object sender, EventArgs e)
        {
            loadSerialPorts();
            filterInfoCollection = new FilterInfoCollection(FilterCategory.VideoInputDevice);
            foreach (FilterInfo filterInfo in filterInfoCollection)
                cbCamera.Items.Add(filterInfo.Name);
            cbCamera.SelectedIndex = 0;
            videoCaptureDevice = new VideoCaptureDevice();
        }

        private void btnUpdateSerialPorts_Click(object sender, EventArgs e)
        {
            loadSerialPorts();
        }
        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            this.Invoke(new EventHandler(receiveDataFromArduino));
        }




        /********************************  My personal fuctions ************************************************/
        private void initSerial()
        {
            cbBaudRate.SelectedIndex = 1;
            loadSerialPorts();
        }

        private void loadSerialPorts()
        {
            cbSerialPort.Items.Clear();
            foreach (string port in SerialPort.GetPortNames())
                cbSerialPort.Items.Add(port);

            if (SerialPort.GetPortNames().Length > 0)
                cbSerialPort.SelectedIndex = 0;
        }


        private void sendDataToArduino(String data)
        {
            serialPort1.Write(data);
        }

        private void closeWebCam()
        {
            if (videoCaptureDevice != null && videoCaptureDevice.IsRunning)
                videoCaptureDevice.Stop();
            
        }

        private void closeCOMPort()
        {
            if (serialPort1!=null && serialPort1.IsOpen)
                serialPort1.Close();
        }

        private void setImage(String value, PictureBox image)
        {
            if (value == "r") value = "red";
            else if (value == "g") value = "green";
            else value = "yellow";
            image.Load("../../Resources/"+value+".png");
        }
        private void receiveDataFromArduino(object sender, EventArgs e)
        {
            // 0-D, 1-semaforo1, 2-semaforo2, 3-semaforo3, 4-semaforo4
            String[] dados = serialPort1.ReadLine().Split('*');
            if (dados.Length == 6 && dados[0] == "D")
            {
                setImage(dados[1], pbSemaforo1);
                setImage(dados[2], pbSemaforo2);
                setImage(dados[3], pbSemaforo3);
                setImage(dados[4], pbSemaforo4);
            }
        }

        private void cleanAllBackground()
        {
            btnRegiterUser.BackColor = Color.FromArgb(24, 30, 54);
        }

        private void hideFields()
        {
            //formRegister.Hide();
        }
        

        private void btnRegiterUser_Click(object sender, EventArgs e)
        {
            /*
            cleanAllBackground();
            pnl_nav.Height = btnRegiterUser.Height;
            pnl_nav.Top = btnRegiterUser.Top;
            pnl_nav.Left = btnRegiterUser.Left;
            btnRegiterUser.BackColor = Color.FromArgb(46, 51, 73);

            hideFields();
            this.pnl_form_loader.Controls.Add(formRegister);
            formRegister.Show();
            */
        }

        private void btnExit_Click_2(object sender, EventArgs e)
        {
            closeCOMPort();
            closeWebCam();
            Application.Exit();
        }
        
        private void btnStartVideo_Click(object sender, EventArgs e)
        {
            if (videoCaptureDevice.IsRunning)
            {
                this.closeWebCam();
                btnStartVideo.Text = "Iniciar Transmissão";
                btnStartVideo.ForeColor = Color.Green;
                pbVideo.Image = null;
                cbCamera.Enabled = true;
            }
            else
            {
                videoCaptureDevice = new VideoCaptureDevice(filterInfoCollection[cbCamera.SelectedIndex].MonikerString);
                videoCaptureDevice.NewFrame += VideoCaptureDevice_NewFrame;
                videoCaptureDevice.Start();
                btnStartVideo.Text = "Parar Transmissão";
                btnStartVideo.ForeColor = Color.Red;
                cbCamera.Enabled = false;
            }
        }
        private void VideoCaptureDevice_NewFrame(object sender, NewFrameEventArgs eventArgs)
        {
            pbVideo.Image = (Bitmap)eventArgs.Frame.Clone();
        }


        private void FormControlPanel_FormClosing(object sender, FormClosingEventArgs e)
        {
            closeCOMPort();
            closeWebCam();
        }
    }
}
