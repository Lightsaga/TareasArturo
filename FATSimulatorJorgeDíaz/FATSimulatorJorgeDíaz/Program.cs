using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FATSimulatorJorgeDíaz
{
    class Program
    {
        public static List<MemoryBlock> listaDeBloques = new List<MemoryBlock>();
        public static Random Randomizer = new Random();

        static void Main(string[] args)
        {
            int InicioArchivo;
            int indice;
            int indiceSiguiente;
            int contador = 0;
            CrearBloques();
            Console.WriteLine("A continuación se presenta una tabla que simula un bloque de memoria fisica de un sistema de archivos FAT");
            Console.Write("-2 representa que no hay nada EN ESTE CASO\n\n");

            foreach(MemoryBlock n in listaDeBloques)
            {
                Console.Write(n.nextBlockForFileAccess + " ");
            }
            Console.WriteLine("\n\nSe insertara un 'archivo' de 8 bytes y se colocara aleatoriamente en la tabla\n");

            //Primera iteracion

            indice = Randomizer.Next(0, 16);
            InicioArchivo = indice;
            indiceSiguiente = Randomizer.Next(0, 16);
            if (listaDeBloques[indice].isBeingUsed == false)
            {
                while (true)
                {
                    indiceSiguiente = Randomizer.Next(0, 16);
                    if (listaDeBloques[indiceSiguiente].isBeingUsed == false)
                        break;
                }
                listaDeBloques[indice].isBeingUsed = true;
                listaDeBloques[indice].nextBlockForFileAccess = indiceSiguiente;
            }
            // El resto
            while(contador <7)
            {
                if (contador == 6)
                {
                    indice = indiceSiguiente;
                    indiceSiguiente = -1;
                    listaDeBloques[indice].isBeingUsed = true;
                    listaDeBloques[indice].nextBlockForFileAccess = indiceSiguiente;
                    contador++;
                }

                else
                {
                    indice = indiceSiguiente;
                    while (true)
                    {
                        indiceSiguiente = Randomizer.Next(0, 16);
                        if (listaDeBloques[indiceSiguiente].isBeingUsed == false)
                            break;
                    }
                    listaDeBloques[indice].isBeingUsed = true;
                    listaDeBloques[indice].nextBlockForFileAccess = indiceSiguiente;
                    contador++;
                }
            }

            Console.WriteLine("\nA Continuacion la tabla de bloques de memoria como si fuera en formato FAT\n");

            foreach (MemoryBlock n in listaDeBloques)
            {
                Console.Write(n.nextBlockForFileAccess + " ");
            }

            Console.WriteLine("\n\nDonde el bloque {0} (de izquierda a derecha) es el inicio del archivo y -1 donde termina", InicioArchivo);
            Console.WriteLine("\n NOTA: Los numeros que se imprimen en cada bloque indican el siguiente bloque a leer para el archivo!");
            Console.ReadLine();
        }

        private static void CrearBloques()
        {
            for (int i = 0; i < 16; i++)
            {
                    listaDeBloques.Add(new MemoryBlock());
                
                // crear la lista de bloques
            }
        }
    }
}
