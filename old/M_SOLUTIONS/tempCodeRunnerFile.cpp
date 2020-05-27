
                ns = G[from][i];
                Gnext[from].pb(G[from][i]);
                Gnext[G[from][i]].pb(from);