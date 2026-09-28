#include <stdio.h>

#define max 100

void initial(int adj[max][max],int v) {
    for (int i=0; i<v; i++) {
        for (int j=0; j<v; j++) {
            adj[i][j]=0;
        }
    }
}

void addEdge(int adj[max][max],int u,int v) {
    adj[u][v]=1;
    adj[v][u]=1;
}

void bfs(int adj[max][max], int v, int snode) {
    int queue[max];
    int f=0;
    int r=0;
    int visited[max]={0};
    visited[snode]=1;
    queue[r++]=snode;
    while (f<r){
        int cur=queue[f++];
        printf("%d ",cur);

        for (int i=0;i<v;i++){
            if (adj[cur][i]==1&&!visited[i]){
                visited[i]=1;
                queue[r++]=i;
            }
        }
    }
}

void dfs(int adj[max][max],int v,int cur, int visited[max]) {
    visited[cur] = 1;
    printf("%d ", cur);

    for (int i = 0; i < v; i++) {
        if (adj[cur][i] == 1 && !visited[i]) {
            dfs(adj, v, i, visited);
        }
    }
}
int main(){
    int v=4;
    int adj[max][max];
    int n,ch,ui,vi;
    initial(adj,v);

    do{
        printf("---------menu--------\n");
        printf("1.Creation\n2.BSF traversal.\n3.DFS traversal.\n");
        printf("Enter an option(1/2/3):");
        scanf("%d",&n);
        printf("---------------------\n");
        switch(n){
            case 1:
            for(int i=0;i<4;i++){
                printf("Enter starting vertex:");
                scanf("%d",&ui);
                printf("Enter ending vertex:");
                scanf("%d",&vi);
                addEdge(adj,ui,vi);
            }
            break;

            case 2:
            printf("BFS traversal of graph:\n");
            bfs(adj,v,0);
            printf("\n");
            break;

            case 3:
            printf("DFS traversal of graph:\n");
            int visited[max] = {0};
            dfs(adj,v,0,visited);
            printf("\n");
            break;

            default:
            printf("enter valid option\n");
            break;
        }
        printf("Want to continue (0/1):");
        scanf("%d",&ch);
    }while (ch==1);

return 0;
}