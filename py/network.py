#!/usr/bin/python
import matplotlib.pyplot as plt
import networkx as nx
#import pylab as P #
G=nx.dodecahedral_graph()
nx.draw(G)  # networkx draw()
P.draw()    # pylab draw()








'''


G=nx.Graph()

    
G.add_weighted_edges_from([(0,1,3.0),(1,2,7.5)])
nx.draw_spectral(G)
print(G.edges())

nx.draw(G)
nx.draw_random(G)
nx.draw_circular(G)
nx.draw_spectral(G)

import matplotlib.pyplot as plt
G=nx.Graph


for u, v in nx.barabasi_albert_graph(10,2,seed=1).edges():
    G.add_edge(u,v,weight=random.uniform(0,0.4))
    
    
G.add_node("spam")
G.add_edge(1,2)
print(G.nodes())
print(G.edges())
'''
