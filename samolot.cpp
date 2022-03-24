#include <iostream>
#include <vector>

using namespace std; 

typedef vector<vector<bool>> samolot;
int samolotX = 5;
int samolotY = 7;

void terminal(vector<vector<bool>> &s)
{
    int x,y;
    cin >> x >> y;
    if(s[x][y]==1)
        cout << "zajete" << endl;
    else
        cout << "zarezerwowano miejse X:" << x << " Y:" << y << endl;
    s[x][y] = 1;
}

samolot add(samolot s1, samolot s2)
{
    samolot w(samolotX, vector<bool>(samolotY));
    for(int i = 0; i < samolotX; i++)
        for(int j = 0; j < samolotY; j++)
            w[i][j] = s1[i][j]&&s2[i][j];
    
    return w;
}

samolot sub(samolot s1, samolot s2)
{
    samolot w(samolotX, vector<bool>(samolotY));
    for(int i = 0; i < samolotX; i++)
        for(int j = 0; j < samolotY; j++)
            w[i][j] = (s1[i][j]^s2[i][j]);
    
    return w;
}

int main()
{
    samolot s1(samolotX, vector<bool>(samolotY));
    samolot s2(samolotX, vector<bool>(samolotY));
    for(int i = 0; i < samolotX; i++)
        for(int j = 0; j < samolotY; j++)
            s1[i][j] = 0;
    
    srand(time(NULL));
    for(int i = 0; i < 8; i++)
    {
        int x = rand() % samolotX, y = rand() % samolotY;
        s1[x][y] = 1;
    }
    for(int i = 0; i < 13; i++)
    {
        int x = rand() % samolotX, y = rand() % samolotY;
        s2[x][y] = 1;
    }
    while(true)
    {
        string comm;
        cin >> comm;
        if(comm == "terminal")
        {
            string w;
            cin >> w;
            if(w == "1")
                terminal(s1);
            else
                terminal(s2);
        }
        else if(comm == "add")
        {
            samolot wynik = add(s1, s2);
            for(auto x: wynik)
            {
                for(auto y: x)
                    cout << y << " ";
                cout << endl;
            }
        }
        else if(comm == "sub")
        {
            samolot wynik = sub(s1, s2);
            for(auto x: wynik)
            {
                for(auto y: x)
                    cout << y << " ";
                cout << endl;
            }
        }
        else
            break;
    }

}