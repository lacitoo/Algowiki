using System;
using System.Collections.Generic;

namespace ELTE_Gyakorlas
{
    public class Program
    {
        private class Node
        {
            public long Distance;
            public long TotalDistance;
            public LinkedList<Node> Nodes;


            public Node(long distance)
            {
                Distance = distance;
                TotalDistance = distance;
                Nodes = new LinkedList<Node>();
            }
        }


        public static void Main()
        {
            long n, k;
            ReadInts(out n, out k);

            Node[] nodes = new Node[n];
            nodes[0] = new Node(0);
            for (long i = 1; i < n; ++i)
            {
                long parent, distance;
                ReadInts(out parent, out distance);
                nodes[parent - 1].Nodes.AddLast(nodes[i] = new Node(distance));
            }

            for (long i = 0; i <= 100000000000000; ++i)
            {
                long s = k;
                if (!Traverse(nodes[0], i, ref s))
                {
                    Console.WriteLine(i);
                    break;
                }
            }
        }

        private static bool Traverse(Node n, long dlim, ref long selectables)
        {
            long max = 0;
            foreach (Node _n in n.Nodes)
            {
                if (Traverse(_n, dlim, ref selectables))
                    return true;
                if (_n.TotalDistance > max)
                    max = _n.TotalDistance;
            }
            n.TotalDistance = n.Distance + max;
            if (n.TotalDistance > dlim)
            {
                n.TotalDistance = 0;
                if (--selectables == -1)
                    return true;
            }
            return false;
        }

        private static void ReadInts(out long left, out long right)
        {
            string s = Console.ReadLine();
            int index = s.IndexOf(' ');
            left = long.Parse(s.Substring(0, index));
            right = long.Parse(s.Substring(index + 1));
        }
    }
}