using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FarbsortierungHMI
{
    public class COM
    {
        public SerialPort comPort;

        public COM()
        {
            comPort = new SerialPort();
        }

        public bool SendData(DataSend send)
        {
            if (!comPort.IsOpen)
            {
                Console.WriteLine("Trying to send without open Port");
                return false;
            }
            
            comPort.Write(send.ToString() + '$');
            return true;
        }

        public static string[] GetPorts()
        {
            return SerialPort.GetPortNames();
        }

        public static int[] GetRates()
        {
            List<int> rates = new List<int>();
            rates.Add(300);
            rates.Add(600);
            rates.Add(1200);
            rates.Add(2400);
            rates.Add(9600);
            rates.Add(14400);
            rates.Add(19200);
            rates.Add(38400);
            rates.Add(57600);
            rates.Add(115200);

            return rates.ToArray<int>();
        }

        public bool OpenPort(int baudRate, string portName)
        {
            try
            {
                comPort.BaudRate = baudRate;
                comPort.PortName = portName ?? throw new ArgumentNullException(nameof(comPort));
            }catch(ArgumentNullException e)
            {
                Console.WriteLine(e.Message);
                return false;
            }

            try
            {
                comPort.Open();
            }
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
                return false;
            }


            return true;
        }
    }

    public class DataSend
    {
        public DataSend(char indentifier, char[] data)
        {
            if(data.Length != 2)
            {
                throw new Exception("Data Length was not 2");
            }

            Indentifier = indentifier;
            Data = data;
        }

        public char Indentifier { get; set; }
        public char[] Data { get; set; }

        public override string ToString()
        {
            if (Data.Length != 2)
            {
                throw new Exception("Data Length was not 2");
            }
            return $"{Indentifier.ToString()}{Data[0]}{Data[1]}";
        }
    }


}
