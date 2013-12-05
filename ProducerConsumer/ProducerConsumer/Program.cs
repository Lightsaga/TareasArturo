using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace ProducerConsumer
{
    // Here's a source of how to use Semaphores that I used to do this homework: http://stackoverflow.com/questions/34519/what-is-a-semaphore

    class Program
    {
        const int buffer = 50;
        static int spentBufferResources;
        public static Semaphore Turn { get; set; }

        static void Main(string[] args)
        {
            Thread consumer = new Thread(new ThreadStart(ConsumirDelBuffer));
            Thread producer = new Thread(new ThreadStart(AgregarAlBuffer));
            // Thread consumer2 = new Thread(new ThreadStart(ConsumirDelBuffer)); 
            Turn = new Semaphore(1, 1);

            consumer.Start();
            //consumer2.Start();
            producer.Start();
        }

        static void AgregarAlBuffer()
        {
            while (true)
            {
                Turn.WaitOne();
                while (spentBufferResources > buffer-10)
                {
                    Console.WriteLine("Not enough space in buffer, wait for resources to be consumed");
                    Turn.Release(1);
                    Thread.Sleep(1500);
                    Turn.WaitOne();
                }
                spentBufferResources += 10;
                Console.WriteLine("Producer adds resources to buffer, +10. Buffer: {0}/{1}", spentBufferResources, buffer);
                Thread.Sleep(2000);
                Turn.Release(1);
                
            }
            
        }

        static void ConsumirDelBuffer()
        {
        while (true)
            {    
                Turn.WaitOne();
                while (spentBufferResources < 5)
                {
                    Console.WriteLine("No resources in Buffer, consumer goes to sleep until there's resources");
                    Turn.Release(1);
                    Thread.Sleep(1500);
                    Turn.WaitOne();
                }
                spentBufferResources -= 5;
                Console.WriteLine("Consumer consume resources out of the buffer, -5. Buffer: {0}/{1}", spentBufferResources, buffer);
                Thread.Sleep(2000);
                Turn.Release(1);
                
                
            }
        }
    }
}
