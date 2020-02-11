/*
# Dijkstra's Algorithm #
The main idea behind applying the greedy method pattern to the single-source,
shortest-path problem is to perform a "weighted" breadth-first search
starting at v. Develop an algorithm that iteratively grows a "cloud" of
vertices out of v, with the vertices entering the cloud in order of their
distances from v. Thus, in each iteration, the next vertex chosen is the vertex
outside the cloud that is closest to v. The algorithm terminates when no more
vertices are outside the cloud, at which point we have a shortest path from v
to every other vertex of G.

Edge Relaxation:
if D[u] + w((u, z)) < D[z], then
D[z] <- D[u] + w((u, z))

Algorithm ShortestPath(G, v):
Initialize D[v] <- 0 and D[u] <- +inf for each vertex u != v.
Let a priority queue Q (heap) contain all the vertices of G using the D labels as keys.
while Q is not empty do
    {pull a new vertex u into the cloud}
    u <-Q.removeMin()
    for each vertex z adjacent to u such that z is in Q do
        {perform the relaxation procedure on edge (u, z)}
        if D[u] + w((u, z)) < D[z] then
            D[z] <- D[u] + w((u, z))
            Change to D[z] the key of vertex z in Q.
return the label D[u] of each vertex u.
*/

// Reference: http://www.shanql.cn/index.php/coding/20190625/204/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <deque>

using namespace std;

#define MAXSIZE 10         // 顶点最大个数
typedef string VertexType; // 顶点类型
typedef int EdgeType;      // 权值类型，有向图（0，1），无向图（权值，无穷大）
#define INFINITY 0xffff    // 定义正无穷

struct MGraph {
    VertexType Vexs[MAXSIZE];        // 顶点向量
    EdgeType arcs[MAXSIZE][MAXSIZE]; // 邻接矩阵，可看作为边表
    int iVexNum;                     // 顶点个数
    int iArcNum;                     // 边数
};

#define SUCCESS 1
#define UNSUCCESS 0
typedef int Status;

// 由顶点值得到顶点索引
int GetIndexByVertexVal( const MGraph& MG, VertexType val ) {
    for ( int i = 0; i < MG.iVexNum; ++i ) {
        if ( val == MG.Vexs[i] )
            return i;
    }
    return -1;
}

// 创建无向图
Status CreateGraph( MGraph& MG ) {
    cout << "输入顶点个数以及边数：";
    cin >> MG.iVexNum >> MG.iArcNum;
    cout << "请输入" << MG.iVexNum << "个顶点:";
    for ( int i = 0; i < MG.iVexNum; ++i ) {
        cin >> MG.Vexs[i];
    }
    for ( int i = 0; i < MG.iVexNum; ++i ) {
        for ( int j = 0; j < MG.iVexNum; ++j ) {
            MG.arcs[i][j] = INFINITY;
        }
    }
    cout << "请输入由两点构成的边及其权值:";
    for ( int i = 0; i < MG.iArcNum; ++i ) {
        VertexType first;
        VertexType second;
        EdgeType weight;
        cin >> first >> second >> weight;
        int m = GetIndexByVertexVal( MG, first );
        int n = GetIndexByVertexVal( MG, second ); 
        if ( m == -1 || n == -1 )
            return UNSUCCESS;
        MG.arcs[m][n] = MG.arcs[n][m] = weight;
    }
    return SUCCESS;
}

// 从v0开始，找到到各个点的最短路径长
// pathMatrix保存了路径信息，比如pathMatrix[3] = 4,表示v3的前趋为v4
// pathTable[i]保存了v0-->vi的路径长度
typedef int PathMatrix;
typedef int ShortPathTable;
void ShortestPath_Dijkstra( const MGraph& G, int v0, 
                            PathMatrix *pathMatrix, ShortPathTable* pathTable ) {
    int final[MAXSIZE]; // 指示已找到最短路径的顶点
    memset( final, 0, sizeof(final) );
    for ( int i = 0; i < G.iVexNum; ++i ) {
        final[i] = 0;
        pathTable[i] = G.arcs[v0][i];
        pathMatrix[i] = v0;  // 前趋
    }
    final[v0] = 1; // v0本身，不需要求
    pathMatrix[v0] = 0;
    pathTable[v0] = v0;

    for ( int i = 1; i < G.iVexNum; ++i ) { // 主循环，求v0到各个顶点的最短路径 
        int min = INFINITY;
        int k = 0;
        for ( int j = 0; j < G.iVexNum; ++j ) {
            if ( !final[j] && min > pathTable[j] ) {
                min = pathTable[j];
                k = j;
            }
        }
        final[k] = 1;

        // 重新调整当前到各个点的最短路径长
        for ( int j = 0; j < G.iVexNum; ++j ) {
            if ( !final[j] && (G.arcs[k][j] + min ) < pathTable[j] ) {
                pathTable[j] = G.arcs[k][j] + min;
                pathMatrix[j] = k; // 修改当前点的前趋
            }
        }
    }

}

// 打印出到各点的最短路径结果
void PrintShortestPath( int v0, int iVexNum, const PathMatrix *pathMatrix,
                       const ShortPathTable* pathTable ) {
    for ( int i = 1; i < iVexNum; ++i ) {
        deque<int> pathTemp;
        int k = i;
        pathTemp.push_front( k );
        while ( pathMatrix[k] != v0 ) {
            pathTemp.push_front( pathMatrix[k] );
            k = pathMatrix[k];
        }

        cout << "V" << v0 << "-->";
        for ( int j = 0; j < (int)pathTemp.size(); ++j ) {
            cout << "V" << pathTemp[j] << "-->";
        }
        cout << "NULL" << "路径长为：" << pathTable[i] << endl;
    }
}


int main()
{
    MGraph MG;
    CreateGraph( MG );

    PathMatrix pathMatrix[MAXSIZE];
    ShortPathTable pathTable[MAXSIZE];
    int v0 = 0;
    ShortestPath_Dijkstra( MG, v0, pathMatrix, pathTable );
    PrintShortestPath( v0, MG.iVexNum, pathMatrix, pathTable );

    return 0;
}
