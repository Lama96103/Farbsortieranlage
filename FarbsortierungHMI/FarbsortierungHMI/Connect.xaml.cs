using System;
using System.Collections.Generic;
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
using System.Windows.Shapes;

namespace FarbsortierungHMI
{
    /// <summary>
    /// Interaction logic for Connect.xaml
    /// </summary>
    public partial class Connect : Window
    {
        public COM com;

        public Connect()
        {
            InitializeComponent();

            string[] ports = COM.GetPorts();

            foreach (var port in ports)
            {
                this.ports.Items.Add(port);
            }

            int[] rates = COM.GetRates();

            foreach (var rate in rates)
            {
                this.rates.Items.Add(rate);
            }

            this.rates.SelectedIndex = 4;
        }

        private void connect_Click(object sender, RoutedEventArgs e)
        {

            string port = (string)this.ports.SelectedValue;
            int rate = (int)this.rates.SelectedValue;

            if(port == null)
            {
                MessageBox.Show("Please Set Port");
                return;
            }

            if(com.OpenPort(rate, port))
            {
                MessageBox.Show("Connected");
                this.connectWindow.Close();
            }
            else
            {
                MessageBox.Show("Error connecting to Port");
            }
        }
    }
}
