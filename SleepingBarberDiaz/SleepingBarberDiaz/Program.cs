using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace SleepingBarberDiaz
{
    class Program
    {
        public static bool isBarberChairOccupied = false;
        public static Queue<bool> SillasEspera = new Queue<bool>();
        public static Semaphore Turn { get; set; }
        public static Random randomizer = new Random();

        static void Main(string[] args)
        {
            Thread Barbero = new Thread(new ThreadStart(ComportamientoBarbero));
            List<Thread> Clientes = new List<Thread>();
            Turn = new Semaphore(1, 1);

            Barbero.Start();

            for (int i = 0; i < 5; i++)
            {
                Thread.Sleep(randomizer.Next(1000, 5500));
                Clientes.Add(new Thread(new ThreadStart(ComportamientoCliente)));
                Clientes[i].Start();
            }
        }

        static void ComportamientoBarbero()
        {
            while (true)
            {
                Turn.WaitOne();
                Console.WriteLine("Barber is checking if someone is in the chair ready for a haircut");
                if (isBarberChairOccupied == false)
                {
                    if (SillasEspera.Count > 0)
                    {
                        Console.WriteLine("Barber checks the waiting room, there's a client waiting");
                        Console.WriteLine("Barber calls the client and starts cutting his hair");
                        isBarberChairOccupied = true;
                        SillasEspera.Dequeue();
                        Turn.Release(1);
                        Thread.Sleep(randomizer.Next(3000,5000)); // cortando pelo
                        Console.WriteLine("Barber finishes cutting the hair, the client leaves satisfied");
                        isBarberChairOccupied = false; // Se acabo el corte de cabello.
                    }
                    else
                    {
                        Console.WriteLine("Barber goes to sleep since there were no people in the waiting room");
                        Turn.Release(1);
                        Thread.Sleep(randomizer.Next(2000,3500)); // Barbero Duerme
                    }
                }
                else
                { 
                //This code is executed when the barber was sleeping and a client arrived
                    Console.WriteLine("A client arrived while the barber was sleeping, the client wakes the barber and the barber starts cutting his hair");
                    Turn.Release(1);
                    Thread.Sleep(randomizer.Next(3000,5000));
                    isBarberChairOccupied = false; // El cliente se va
                    Console.WriteLine("Barber finishes cutting the hair, the client leaves satisfied");
                }
            
            }
        }
        static void ComportamientoCliente()
        {
            Turn.WaitOne();
            Console.WriteLine("A client arrives and is checking if he can get his haircut");
            if (isBarberChairOccupied == true)
            {
                if (SillasEspera.Count < 3)
                {
                    Console.WriteLine("The client goes to the waiting room");
                    SillasEspera.Enqueue(true); // A client is added to the chairs/queue
                    Turn.Release(1);
                }
                else
                {
                    Console.WriteLine("The waiting room was full so the client leaves");
                    Turn.Release(1);
                // Does nothing and just leaves.
                }
            }
            else if (isBarberChairOccupied == false && SillasEspera.Count == 0)
            {
                Console.WriteLine("The client notices the barber is asleep and gets in the barber chair ready for a haircut");
                isBarberChairOccupied = true; // get in the chair ready for haircut
                Turn.Release(1);
            }
            else if (isBarberChairOccupied == false && SillasEspera.Count < 3)
            {
                Console.WriteLine("The client goes to the waiting room");
                SillasEspera.Enqueue(true); // A client is added to the chairs/queue
                Turn.Release(1);
            }
            
        }

    }
}
