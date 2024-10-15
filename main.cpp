#include <iostream>
#include <vector>

using namespace std;

enum players
{
    p1, p2
};

void printField(const vector<vector<int>>& vv)
{
    cout << "  0  1  2" << endl;
    for (int i = 0; i < vv.size(); ++i)
    {
        cout << i << ' ';
        
        for (int j = 0; j < vv[i].size(); ++j)
        {
            if (vv[i][j] == 1) cout << "@@";
            else if (vv[i][j] == 2) cout << "XX";
            else if (i != 2) cout << "__";
            else cout << "  ";  
            if (j != 2)
            cout << "|";
        }
        cout << endl;
    }
}

bool checkWin(const vector<vector<int>>& vv)
{
    if (vv[0][0] == 1 && vv[0][1] == 1 && vv[0][2] == 1 ||
        vv[0][0] == 2 && vv[0][1] == 2 && vv[0][2] == 2) return true;
    if (vv[1][0] == 1 && vv[1][1] == 1 && vv[1][2] == 1 ||
        vv[1][0] == 2 && vv[1][1] == 2 && vv[1][2] == 2) return true;
    if (vv[1][0] == 1 && vv[1][1] == 1 && vv[1][2] == 1 ||
        vv[2][0] == 2 && vv[2][1] == 2 && vv[2][2] == 2) return true;

    if (vv[0][0] == 1 && vv[1][1] == 1 && vv[2][2] == 1 ||
        vv[0][0] == 2 && vv[1][1] == 2 && vv[2][2] == 2) return true;
    if (vv[0][2] == 1 && vv[1][1] == 1 && vv[2][0] == 1 ||
        vv[0][2] == 2 && vv[1][1] == 2 && vv[2][0] == 2) return true;

    if (vv[0][0] == 1 && vv[1][0] == 1 && vv[2][0] == 1 ||
        vv[0][0] == 2 && vv[1][0] == 2 && vv[2][0] == 2) return true;
    if (vv[0][1] == 1 && vv[1][1] == 1 && vv[2][1] == 1 ||
        vv[0][1] == 2 && vv[1][1] == 2 && vv[2][1] == 2) return true;
    if (vv[0][2] == 1 && vv[1][2] == 1 && vv[2][2] == 1 ||
        vv[0][2] == 2 && vv[1][2] == 2 && vv[2][2] == 2) return true;
    return false;
}

players player()
{
    static int i = -1;
    if (i == -1) 
    {
        i = 1;
        return p1;
    }
    else
    {
        i = -1;
        return p2;
    }
}

void game(vector<vector<int>>& vv)
{
    while (1)
    {
        players pp = player();

        printField(vv);

        if (pp == p1) cout << "enter number p1, ex: 0 0 -> ";
        else cout << "enter number p2, ex: 0 0 -> ";

        int n1, n2;
        cin >> n1 >> n2;

        if (n1 == 3 || n2 == 3) return;
        else if (n1 > 3 || n2 > 3) throw runtime_error("error: n1 > 3 || n2 > 3");

        if (pp == p1 && (vv[n1][n2] != 1 && vv[n1][n2] != 2))
            vv[n1][n2] = 1;
        else if (vv[n1][n2] != 1 && vv[n1][n2] != 2)
            vv[n1][n2] = 2;
        else throw runtime_error("error");

        if (checkWin(vv))
        {
            printField(vv);
            if (pp == p1)
            {
                cout << "p1 win!" << endl;
                return;
            }
            else 
            {
                cout << "p2 win!" << endl;
                return;
            }
        }
    }
}

vector<vector<int>> set_v()
{
    vector<vector<int>> numbers(3, vector<int>(3));
    return numbers;
}

int main()
{
    vector<vector<int>> vv = set_v();
    char playAgain;
    try 
    {   
        while (1)
        {
            game(vv);
            cout << "play again? y or n -> ";
            cin >> playAgain;
            if (playAgain == 'n') break;
            else vv = set_v();
        }
        
        return 0;
    }
    catch(runtime_error& e)
    {
        cerr << e.what() << endl;
        return 1;
    }
    catch(...)
    {
        cerr << "exception" << endl;
        return 2;
    }
}