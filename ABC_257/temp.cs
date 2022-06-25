using System;
using System.Collections.Generic;
using System.Linq;

namespace ABC257
{
    internal class Program
    {
        public struct jump
        {
            public int x;
            public int y;
            public long p;
        }

        public static long[,] memo;
        public static int n;

        static void Main(string[] args)
        {
            n = int.Parse(Console.ReadLine());
            var jumps = new List<jump>();
            for (int i = 0; i < n; i++)
            {
                var input = Console.ReadLine().Split(' ').Select(int.Parse);
                var jump = new jump();
                jump.x = input.First();
                jump.y = input.Skip(1).First();
                jump.p = input.Last();
                jumps.Add(jump);
            }

            memo = new long[n, n];
            // i から飛んだ場合
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    var dist = Math.Abs(jumps[i].x - jumps[j].x) + Math.Abs(jumps[i].y - jumps[j].y);
                    memo[i, j] = (int)Math.Ceiling((double)dist / jumps[i].p); // 最小のS
                }
            }

            // 初期ジャンプ台
            var ans = long.MaxValue;
            for (int i = 0; i < n; i++)
            {
                // 最初のSの値
                for (int j = 0; j < n; j++)
                {
                    if (i == j) continue;
                    var s = memo[i, j];
                    var res = new bool[n];

                    dfs(i, s, res);

                    if (res.Any(v => v == false))
                        continue;

                    if (s < ans)
                        ans = s;
                }
            }

            Console.WriteLine(ans);
        }

        static void dfs(int index, long s, bool[] res)
        {
            if (res[index]) return;

            res[index] = true;
            for (var i = 0; i < n; i++)
            {
                if (memo[index, i] > s) continue;
                dfs(i, s, res);
            }
        }
    }
}
