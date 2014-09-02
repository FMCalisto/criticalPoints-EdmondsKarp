/*
* 	ASA - P2
*
*  	Author: Francisco Maria Calisto
*
*  	Number: 70916
*
*
*  	Author: Carlos Costa
*
*  	Number: 69854
*
*
*	Algorithm: Edmonds-Karp
*
*	O Algoritmo de Edmonds-Karp e uma variacao do Algoritmo de
* 	Ford-Fulkerson que calcula o Fluxo Maximo numa rede de Fluxos,
* 	mas com um final garantido e com um tempo de execucao independente
* 	do valor do Fluxo Maximo, sendo que num caminho de aumento mais
* 	curto e usado em cada interaccao, este e percorrido e encontrado
*	atraves de uma BFS.
*
*/

#include <limits.h>
#include <string.h>
#include <stdio.h>

#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <functional>

using namespace std;

#define DEBUG 0

typedef pair<int, int> AEK;


/*	============================================================ 	*/

/*	============================================================ 	*/


 /*
  * BFS - Breadth-First Search
  * 
  * Retorna Verdadeiro no caso em que existe um dado caminho
  * proveniente da origem 's' (source) que vai ate ao final 't' (trace)
  * do Grafo Residual.
  * 
  * Tambem preenche a parentsList[].
  */
 
int bfs(vector<vector<int> > flowPassed, int s, int t, int parentsList[])
{    
    /*
     * 	Cria Vertices visitados e marca os restantes como nao visitados
     */
    
    bool visited[flowPassed.size()];
    
    memset(visited, 0, sizeof(visited));
    

    /*
     *	Cria uma lista onde lista a origem dos Vertices e marca-os
     * 	consuante a sua origem ja tenha sido visitada ou nao.
     */
    
    queue <int> q;
    q.push(s);
    visited[s] = true;
    
    parentsList[s] = -1;

    
    /*
     * 	Loop da BFS Normal
     */
    
    while (!q.empty())
    {
        int u = q.front();
        
        q.pop();
        
        for(int v = 0; v < (int) flowPassed.size(); v++)
        {
			if(visited[v] == false && flowPassed[u][v] > 0)
			{
				q.push(v);
				
				/*
				 * 	Actualizamos os pais do futuro no para que este
				 *	passe a ser o no actual.
				 */
				 
				 parentsList[v] = u;
				 visited[v] = true;
			 }
		 }
	 }
	 
	 /*
	  * 	Se chegamos ao fundo da BFS partindo da origem, entao,
	  * 	returnamos Verdadeiro, caso contrario retornamos Falso.
	  */
	
	return (visited[t] == true);
	
}


/*
 * 	Uma DFS com a funcionalidade basica de procurar todos os vertices
 * 	alcancaveis apartir de s. A funcao marca como visitado no caso
 * 	em que o indice do Array dos Vertices visitados e alcancavel
 * 	apartir de s. Os valores iniciais do nosso Array de Vertices
 * 	visitados devem ser falsos. Tambem podemos sempre usar a BFS para
 * 	encontrar os Vertices alcancados.
 */

void dfs(vector<vector<int> > flowPassed, int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < (int) flowPassed.size(); i++)
    {
       if (flowPassed[s][i] && !visited[i])
       {
           dfs(flowPassed, i, visited);
	   }
   }
}


/*	============================================================ 	*/

/*	============================================================ 	*/


/*
 *	Imprime o corte minimo entre s e t.
 */

vector<AEK> fordFulkerson(vector<vector<int> > graph, int s, int t)
{    
    int u, v;
    
    
    /*
     * 	Vector que aloca os Cortes Minimos.
     */
    
    vector<AEK> minCut;
    
    
    /*
     * 	Cria um Grafo Residual e preenche-o com as capacidades dadas
     * 	no Grafo original como se tratassem de capacidades residuais
     * 	dentro do Grafo.
     */
     
    vector<vector<int> > flowPassed;
    

	/*
	 * 	Realoca a capacidade residual entre dois Edges.
	 */
    
    flowPassed.resize(graph.size());
    
    for(int i = 0; i < (int) graph.size(); i++)
    {
		flowPassed[i].resize(graph.size());
	}
    

    for (u = 0; u < (int) graph.size(); u++)
    {
        for (v = 0; v < (int) graph.size(); v++)
        {
             flowPassed[u][v] = graph[u][v];
		 }
	 }
             

    int parentsList[flowPassed.size()];  // Este Array e preenchido pela BFS
    
    
    /*
     * 	Procura pela capacidade residual minima dos Edges pelo caminho
     * 	preenchido pela BFS. Por outras palavras, procura o
     * 	Fluxo Maximo atraves do caminho encontrado.
     */
    
    while (bfs(flowPassed, s, t, parentsList))
    {
		// procurando pelo caminho de aumento
		
		int path_flow = INT_MAX;
        
        
        for (v = t; v != s; v = parentsList[v])
        {
            u = parentsList[v];
            path_flow = min(path_flow, flowPassed[u][v]);
        }

        
        /*
         * 	Actualizar a capacidade residual do edge reservando-o ao
         * 	longo do caminho percorrido.
         */
        
        for (v = t; v != s; v = parentsList[v])
        {
            u = parentsList[v];
            flowPassed[u][v] -= path_flow;
            flowPassed[v][u] += path_flow;
        }
    }

    
    /*
     * 	Fluxo Maximo ja atingido, procura agora o Vertice alcancavel s.
     */

    bool visited[flowPassed.size()];
    
    memset(visited, false, sizeof(visited));
    
    dfs(flowPassed, s, visited);

    /*
     * 	Contabiliza o numero de Cortes Minimos possiveis.
     */
    
    for (int i = 0; i < (int) flowPassed.size(); i++)
    {
      for (int j = 0; j < (int) flowPassed.size(); j++)
      {
         if (visited[i] && !visited[j] && graph[i][j])
         {			 
              minCut.push_back(make_pair(i,j));
		  }
		}
	}
	
	// cout << minCut;

    return minCut;
}

/*	============================================================ 	*/

/*	============================================================ 	*/

int main()
{
	int nodesCount, edgesCount;
	
	cin >> nodesCount >> edgesCount;
	
	vector<vector<int> > Capacities;
	
	
	Capacities.resize(nodesCount);
	
	for(int i = 0; i < nodesCount; i++)
	{
		Capacities[i].resize(nodesCount);
	}
	
	
	for (int edge = 0; edge < edgesCount; edge++)
	{
		int from, to; // capacity = 1
		
		cin >> from >> to; //>> capacity;

		Capacities[from][to] = 1;
		Capacities[to][from] = 1;
	}
	
	int k; // Constante do numero de linhas para os Pontos Criticos
	
	cin >> k;
	
	for(int i = 0; i < k; ++i)
	{		
		int ncp; // Numero de pontos criticos
		
		cin >> ncp;
		
		vector<int> ncpV(ncp);
		vector<AEK> pnt;
		
		// NOTA: alterar i / j <--- e fazer ++j

		for(int i = 0; i < ncp; i++)
		{			
			cin >> ncpV[i];
		}
		
		int mC = INT_MAX;
		
		for(int i = 1; i < (int) ncpV.size(); i++)
		{
			pnt = fordFulkerson(Capacities, ncpV[0], ncpV[i]);
			mC = min(mC, (int) pnt.size());
		}
		
		cout << mC << endl;
	}
	
	
	// imprime uma matriz preenchida para debug, acrescentando
	// uma flag debug
	
	if(DEBUG)
	{
		for(int i = 0; i < nodesCount; i++)
		{
			for(int j = 0; j < nodesCount; j++)
			{
				cout << Capacities[i][j] << " ";
			}
			cout << endl;
		}
	}

    return 0;
}
