#!/usr/bin/python
import matplotlib.pyplot as plt
import networkx as nx
import random
#import pylab as P #
#G =nx.random_graphs.barabasi_albert_graph(100,1)
G=nx.Graph()
list=[("home","cot", 0.5),("home","con",0.14),("cot","con",0.03)]

G.add_edge(1, 2, weight=4.7 )
G.add_edges_from([(3,4),(4,5)], color='blue')
G.add_edges_from([(1,2,{'color':'blue'}), (2,3,{'weight':8})])
nx.draw(G)
plt.savefig("ba3.png")
plt.show()


'''
edgewidth=[]
for u in list:
    edgewidth.append(u[2]*20)
    G.add_edge(u[0],u[1],weight=u[2])
pos=nx.spring_layout(G,iterations=20)
nx.draw_networkx_edges(G,pos,width=edgewidth)
nx.draw_networkx_nodes(G,pos)
plt.savefig("ba3.png")
plt.show()


G.add_weighted_edges_from(list);
print G.get_edge_data("home","cot")
nx.draw(G)
plt.savefig("ba3.png")
plt.show()



edgewidth=[]
for u in list:
    edgewidth.append(u[2]*20)
    G.add_edge(u[0],u[1],weight=u[2])
pos=nx.spring_layout(G,iterations=20)
nx.draw_networkx_edges(G,pos,width=edgewidth)
nx.draw_networkx_nodes(G,pos)
plt.savefig("ba3.png")
plt.show()


for u, v in nx.barabasi_albert_graph(10,2,seed=1).edges():
    G.add_edge(u,v,weight=random.uniform(0,0.4))
    
pos=nx.spring_layout(G,iterations=20)
edgewidth=[]
for (u,v,d) in G.edges(data=True):
     edgewidth.append(round(G.get_edge_data(u,v).values()[0]*20,2))
     
print edgewidth
nx.draw_networkx_edges(G,pos,width=edgewidth)
nx.draw_networkx_nodes(G,pos)
plt.savefig("ba2.png")
plt.show()



#G.add_edges_from([(1,2),(2,3)], weight=13)
G.add_weighted_edges_from([("home","cot",3.0),("home","con",7.5),("cot","con",109)],"weight")
G.add_weighted_edges_from([(0,1,32.0),(1,2,72.5),(2,3,72.5),(3,2,72.5)],'weight')

nx.draw(G)
plt.savefig("ba2.png")
plt.show()



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
