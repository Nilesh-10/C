#include<stdio.h>
#define INF 9999
void floyd(int g[][4])
{
    int b[4][4];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            b[i][j]=g[i][j];
        }
    }
    for(int k=0; k<4; k++)
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                if(b[i][k]+b[k][j]<b[i][j])
                    b[i][j]=b[i][k]+b[k][j];
            }
        }
    }
    for(int i=0; i<4; i++)
    {
        printf("\n");
        for(int j=0; j<4; j++)
        {
            if(b[i][j]==9999)
                printf("%7s","INF");
            else
            {
                printf("%7d",b[i][j]);
            }
        }
    }
}
int main()
{
    int g[4][4]= {{0,   5,  INF, 10},
        {INF, 0,   3, INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };
    floyd(g);
    return 1;
}
