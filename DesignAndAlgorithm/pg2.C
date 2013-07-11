using System;
using System.Collections;
using System.IO;

namespace AlgoClassQ2
{
    class Program
    {
        static int Rows = 10000;
        static int[] A = new int[Rows], B = new int[Rows]; // B - начальный, неотсортированный массив
        static int Comparisons = 0;

        // 0 для "Пивот -- первый элемент", 1 для "Пивот -- последний элемент", 
        // 2 для median-of-three pivot rule, 3 для рандомного пивота.
        static int Method = 0;

        static void Main(string[] args)
        {
            string Path = "C:\\QuickSort.txt";
            StreamReader SR = new StreamReader(Path);
            for (int i = 0; i < Rows; ++i) B[i] = Convert.ToInt32(SR.ReadLine());
            SR.Close();
            Console.WriteLine("The last element for checking {0}", B[Rows - 1]);

            A = (int[])B.Clone();
            Method = 0; 
            QuickSort(0, Rows - 1);
            Console.WriteLine(Comparisons);
            Console.WriteLine(Check().ToString());

            Comparisons = 0;
            A = (int[])B.Clone();
            Method = 1;
            QuickSort(0, Rows - 1);
            Console.WriteLine(Comparisons);
            Console.WriteLine(Check().ToString());

            Comparisons = 0;
            A = (int[])B.Clone(); 
            Method = 2;
            QuickSort(0, Rows - 1);
            Console.WriteLine(Comparisons);
            Console.WriteLine(Check().ToString());
            
            /*  Для рандомного выбора пивота
             * Comparisons = 0;
             * A = (int[])B.Clone();
             * Method = 3;
             * QuickSort(0, Rows - 1);
             * Console.WriteLine(Comparisons);
             * Console.WriteLine(Check().ToString()); */

            Console.Read();
        }

        // Recoursion
        static void QuickSort(int StartIndex, int EndIndex)
        {
            if (StartIndex < EndIndex)
            {
                int PivotIndex = ChoosePivot(StartIndex, EndIndex);
                Comparisons += EndIndex - StartIndex;
                PivotIndex = Partition(StartIndex, EndIndex, PivotIndex);
                if (PivotIndex > StartIndex) QuickSort(StartIndex, PivotIndex - 1);
                if (EndIndex > PivotIndex) QuickSort(PivotIndex + 1, EndIndex);
            }
        }

        // Subroutin
        static int Partition(int StartIndex, int EndIndex, int PivotIndex)
        {
            int Pivot = A[PivotIndex];
            if (PivotIndex > StartIndex) Replace(StartIndex, PivotIndex);
            int i = StartIndex + 1;
            for (int j = i; j <= EndIndex; ++j)
            {
                if (A[j] < Pivot)
                {
                    Replace(i, j);
                    ++i;
                }
            }
            if (StartIndex != i)
            {
                Replace(StartIndex, i - 1);
                return i - 1;
            }
            else return StartIndex;
            
        }

        // Выбор пивота в зависимости от способа ( 0 - первый, 1 - последний, 2 - метод трёх, 3 - рандомный)
        static int ChoosePivot(int StartIndex, int EndIndex)
        {
            switch (Method)
            {
                case 0: return StartIndex;
                case 1: return EndIndex;
                case 2:
                    {
                        int Median = (int)((StartIndex + EndIndex) / 2);
                        if (A[StartIndex] > A[Median])
                        {
                            if (A[StartIndex] > A[EndIndex])
                                return (A[Median] > A[EndIndex]) ? Median : EndIndex;
                            else return StartIndex;
                        }
                        else
                        {
                            if (A[Median] > A[EndIndex])
                                return (A[StartIndex] > A[EndIndex]) ? StartIndex : EndIndex;
                            else return Median;
                        }
                    }
                case 3:
                    {
                        Random R = new Random();
                        return StartIndex + R.Next(EndIndex - StartIndex);
                    }
                default: return StartIndex;
            }
        }

        // Обмен значениями
        static void Replace(int IndexA, int IndexB)
        {
            int Temp = A[IndexA];
            A[IndexA] = A[IndexB];
            A[IndexB] = Temp;
        }

        // Печать части массива (для дебага)
        static void Print(int StartIndex, int EndIndex)
        {
            for (int i = StartIndex; i <= EndIndex; ++i)
            {
                Console.Write(A[i]);
                Console.Write(" ");
            }
            Console.WriteLine();
        }

        // Проверка, если массив отсортирован
        static bool Check()
        {
            bool Temp = true;
            for (int i = 0; i < Rows - 1; ++i)
            {
                if (A[i] > A[i + 1]) return false;
            }
            return Temp;
        }
    }
}