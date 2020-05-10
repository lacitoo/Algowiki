using System;
using System.Collections.Generic;

namespace ELTE_Gyakorlas
{
    public class Program
    {
        private class Node
        {
            public int Distance;
            public int TotalDistance;
            public LinkedList<Node> Nodes;


            public Node(int distance)
            {
                Distance = distance;
                TotalDistance = distance;
                Nodes = new LinkedList<Node>();
            }
        }


        public static void Main()
        {
            int n, k;
            ReadInts(out n, out k);

            Node[] nodes = new Node[n];
            nodes[0] = new Node(0);
            for (int i = 1; i < n; ++i)
            {
                int parent, distance;
                ReadInts(out parent, out distance);
                nodes[parent - 1].Nodes.AddLast(nodes[i] = new Node(distance));
            }

            int min = 1;
            int max = 1000000000;
            int s = k;
            while (max > min)
            {
                int mid = (min + max) >> 1;
                s = k;
                if (Traverse(nodes[0], mid, ref s))
                    min = mid + 1;
                else max = mid - 1;
            }
            s = k;
            Console.WriteLine(Traverse(nodes[0], max, ref s) ? max - 1 : max);
        }

        private static bool Traverse(Node n, int dlim, ref int selectables)
        {
            int max = 0;
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

        private static void ReadInts(out int left, out int right)
        {
            string s = Console.ReadLine();
            int index = s.IndexOf(' ');
            left = int.Parse(s.Substring(0, index));
            right = int.Parse(s.Substring(index + 1));
        }
    }
}