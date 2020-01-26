//广度优先搜索
void BFS(Graph G,int v)
{
    cout<<v;visited[v] =true; //访问第v个顶点，并置访问标志数组相应分量值为true
    InitQueue(Q);//辅助队列Q初始化，置空
    EnQueue(Q,v);//v进队
    while(!QueueEmpty(Q))//队列非空
    {
          DeQueue(Q,u);
          for(w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
          {//依次检查u的所有邻接点w，FirstAdjVex(G,u)表示u的第一个邻接点
//NextAdjVex(G,u,w)表示u相对于w的下一个邻接点，w>=0表示存在邻接点
                  if(!visited[w])//w为u的尚未访问的邻接顶点
                  {
                          cout<<w;visited[w]=true;//访问w
                          EnQueue(Q,w);//w进队
                  }
            }
    }
}