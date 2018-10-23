using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace FarbsortierungHMI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public COM comConnect;

        public MainWindow()
        {
            InitializeComponent();

            comConnect = new COM();

            System.Windows.Threading.DispatcherTimer dispatcherTimer = new System.Windows.Threading.DispatcherTimer();
            dispatcherTimer.Tick += OnDataUpdate;
            dispatcherTimer.Interval = TimeSpan.FromSeconds(1);
            dispatcherTimer.Start();


            comConnect.comPort.DataReceived += DataReceived;
        }

        public void DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = (SerialPort)sender;
            char indata = (char)sp.ReadChar();
            Console.WriteLine($"Data Received: {indata}");
        }

        private void OnDataUpdate(object sender, EventArgs e)
        {
            this.ports.Text = comConnect.comPort.PortName;
            this.rates.Text = comConnect.comPort.BaudRate.ToString();
            this.connected.Text = comConnect.comPort.IsOpen.ToString();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Connect con = new Connect();
            con.Show();
            con.com = comConnect;
        }

        private void send_Click(object sender, RoutedEventArgs e)
        {
            


            comConnect.SendData(new DataSend('3', new char[2] { 'h', 'a' }));
        }
    }

}
