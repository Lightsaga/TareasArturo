using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LRUJorge
{
    class Program
    {
        static int[,] matrix = new int[4, 4];
        static void Main(string[] args)
        {
            Console.WriteLine("He aqui una matrix 4x4");
            DibujarMatrix();
            while (true)
            {
                try
                {
                    Console.Write("\nEscriba un numero de acceso del 0 al 3: ");
                    int numeroAccesoLRU = int.Parse(Console.ReadLine());
                    if (numeroAccesoLRU > 3 || numeroAccesoLRU < 0)
                    {
                        throw new Exception();
                    }
                    ModificarMatrix(numeroAccesoLRU);
                    DibujarMatrix();
                    break;
                }
                catch
                {
                    Console.WriteLine("Numero no valido");
                }
            }

            while (true)
            {
                try
                {
                    Console.Write("\nEscriba otro numero de acceso del 0 al 3 o escriba 5 para salir del programa: ");
                    int numeroAccesoLRU = int.Parse(Console.ReadLine());
                    if (numeroAccesoLRU == 5)
                    {
                        break;
                    }
                    else if (numeroAccesoLRU > 3 || numeroAccesoLRU < 0)
                    {
                        throw new Exception();
                    }
                    ModificarMatrix(numeroAccesoLRU);
                    DibujarMatrix();
                    
                }
                catch
                {
                    Console.WriteLine("Numero no valido");
                }
            }

        }
        public static void DibujarMatrix()
        {
            for (int i = 0; i < 4; i++)
            {
                Console.WriteLine();
                for (int j = 0; j < 4; j++)
                {
                    Console.Write(matrix[i, j] + " ");
                }

            }
        }
        public static void ModificarMatrix(int numero)
        {
            if (numero == 0)
            {
                for (int i = 0; i < 4; i++)
                {
                    matrix[0, i] = 1;
                }
                for (int i = 0; i < 4; i++)
                {
                    matrix[i, 0] = 0;
                }
            }
            if (numero == 1)
            {
                for (int i = 0; i < 4; i++)
                {
                    matrix[1, i] = 1;
                }
                for (int i = 0; i < 4; i++)
                {
                    matrix[i, 1] = 0;
                }
            }
            if (numero == 2)
            {
                for (int i = 0; i < 4; i++)
                {
                    matrix[2, i] = 1;
                }
                for (int i = 0; i < 4; i++)
                {
                    matrix[i, 2] = 0;
                }
            }
            if (numero == 3)
            {
                for (int i = 0; i < 4; i++)
                {
                    matrix[3, i] = 1;
                }
                for (int i = 0; i < 4; i++)
                {
                    matrix[i, 3] = 0;
                }
            }
        }
    }
}
