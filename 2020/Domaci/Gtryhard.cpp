#include<bits/stdc++.h>

using namespace std;

vector<vector<char>> AA;
vector<vector<char>> BB;
int n, m;
vector<pair<int, int>> movesA;
vector<pair<int, int>> movesB;


void printA()
{
    cout << "A\n";
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; j++)
        {
            cout << AA[i][j];
        }
        cout << endl;
    }
    cout << "----------------------\n";
}

void printB()
{
    cout << "B\n";
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; j++)
        {
            cout << BB[i][j];
        }
        cout << endl;
    }
    cout << "----------------------\n";
}

bool rotate(int x, int y, vector<pair<int, int>> &moves, vector<vector<char>> &A)
{
    if(!(x + 1 < n && y + 1 < m && x >= 0 && y >= 0))
        return false;
    if(A[x][y] == 'U' && A[x+1][y+1] == 'D')
    {
        pair<int, int> p;
        p.first = x+1;
        p.second = y+1;
        moves.push_back(p);
        A[x][y] = 'L';
        A[x][y+1] = 'R';
        A[x+1][y] = 'L';
        A[x+1][y+1] = 'R';

        return true;
    }
    if(A[x][y] == 'L' && A[x+1][y+1] == 'R')
    {
        pair<int, int> p;
        p.first = x+1;
        p.second = y+1;
        moves.push_back(p);
        A[x][y] = 'U';
        A[x][y+1] = 'U';
        A[x+1][y] = 'D';
        A[x+1][y+1] = 'D';

        return true;
    }
    if(A[x][y] == 'U')
    {
        if(y < m-1)
        {
            if(A[x][y+1] == 'D')
                rotate(x-1, y+1, moves, A);     
            rotate(x, y+1, moves, A);
            return rotate(x,y, moves, A);
        }
    }
    if(A[x][y] == 'L')
    {
        if(x < n-1)
        {
            if(A[x+1][y] == 'R')
                rotate(x+1, y-1, moves, A);
            rotate(x+1, y, moves, A);
            return rotate(x,y, moves, A);
        }
    }
    return false;
}

void set_verticaly(vector<vector<char>> &A, vector<pair<int,int>> &moves)
{
    bool process = true;
    int baba = 0;
    while(process)
    {
        process = false;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; ++j)
            {
                if(A[i][j] != 'U' && i % 2 == 0)
                {
                    if(A[i][j] == 'D')
                    {
                        if(!rotate(i-1,j, moves, A))
                            rotate(i-1,j-1, moves, A);
                        if(!rotate(i,j, moves, A))
                            rotate(i,j-1, moves, A);
                    }
                    else if(A[i][j] == 'L')
                    {
                        rotate(i,j, moves, A);
                    }
                    else if(A[i][j] == 'R')
                    {
                        rotate(i,j-1, moves, A);   
                    }
                    process = true;
                }
                else if(A[i][j] != 'D' && i % 2 == 1)              
                {
                    if(A[i][j] == 'U')
                    {
                        if(!rotate(i,j, moves, A))
                            rotate(i,j-1, moves, A);
                        if(!rotate(i-1,j, moves, A))
                            rotate(i-1, j-1, moves, A);
                    }
                    else if(A[i][j] == 'L')
                        rotate(i-1,j, moves, A);
                    else if(A[i][j] == 'R')
                        rotate(i-1, j-1, moves, A);
                    process = true;
                }
            }
        /*
        baba++;
        //printA();
        if(baba == 10000)
            break;*/
    }
}

void set_horizontaly(vector<vector<char>> &A, vector<pair<int, int>> &moves)
{
    bool process = true;
    //int baba = 0;
    while(process)
    {
        process = false;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; ++j)
            {
                if(A[i][j] != 'L' && j % 2 == 0)
                {
                    if(A[i][j] == 'R')
                    {
                        if(!rotate(i,j-1, moves, A))
                            rotate(i-1,j-1, moves, A);
                        if(!rotate(i,j, moves, A))
                            rotate(i-1,j, moves, A);
                    }
                    else if(A[i][j] == 'U')
                        rotate(i,j, moves, A);
                    else if(A[i][j] == 'D')
                        rotate(i-1,j, moves, A);
                    process = true;
                }
                else if(A[i][j] != 'R' && j % 2 == 1)              
                {
                    if(A[i][j] == 'L')
                    {
                        if(!rotate(i,j, moves, A))
                            rotate(i-1,j, moves, A);
                        if(!rotate(i,j-1, moves, A))
                            rotate(i-1,j-1, moves, A);
                    }
                    else if(A[i][j] == 'U')
                        rotate(i,j-1, moves, A);
                    else if(A[i][j] == 'D')
                        rotate(i-1,j-1, moves, A);
                    process = true;
                }
            }
            /*
        baba++;
        printA();
        if(baba == 10)
            break;
            */
            
    }
}

void solve_horizontaly(vector<vector<char>> &A, vector<pair<int, int>> &moves)
{
    bool process = true;
        while(process)
    {
        process = false;
        for(int j = 0; j < m; j++)
            for(int i = 0; i < n; ++i)
            {
                if(A[i][j] != BB[i][j])
                {
                    rotate(i,j, moves, A);
                    process = true;
                }
            }
            /*
        baba++;
        printA();
        if(baba == 10)
            break;
            */
            
    }
}




void solve()
{
    movesA = vector<pair<int, int>>();
    movesB = vector<pair<int, int>>();
    //int n, m;
    cin >> n >> m;
    //cout << n << " " << m << endl;
    AA = vector<vector<char>>();
    BB = vector<vector<char>>();
    for(int i = 0; i < n; ++i)
    {  
        AA.push_back(vector<char>(m, 'a'));
        for(int j = 0; j < m; ++j)
            cin >> AA[i][j];
    }
    for(int i = 0; i < n; ++i)
    {  
        BB.push_back(vector<char>(m, 'a'));
        for(int j = 0; j < m; ++j)
            cin >> BB[i][j];
    }
   // printA();
    if(n%2 == 0)
    {
        set_verticaly(AA, movesA);
        set_verticaly(BB, movesB);
    }
    else
    {
        set_horizontaly(AA, movesA);
        set_horizontaly(BB, movesB);
       // printA();
        //solve_horizontaly();
    }
   // printA();
    //printB();
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i)
    {
        solve();
        reverse(movesB.begin(), movesB.end());
        cout << movesA.size() + movesB.size() << endl;
        for(auto p : movesA)
            cout << p.first << " " << p.second << endl;
        for(auto p : movesB)
            cout << p.first << " " << p.second << endl;
        //break;
    }
    return 0;
}