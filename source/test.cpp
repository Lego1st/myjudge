#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

string s,p,c,t;
string ti,to;
string prob;
vector<string> RES;
vector<string> Inp,Out;
string timer;
string hide;

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    FILE *f1,*f2;
    printf("File name : ");
    cin >> prob;
    printf("Time limit (ms): ");
    cin >> timer;
    printf("Show the diff (y/n) ? ");
    cin >> hide;
    if(hide != "y" && hide != "n")
        printf("Failed! The diff will be showed\n");
    if(hide == "n") hide = ">nul";
    else hide = "";
    //c++:
    s = "g++ " + prob + ".cpp -O2 -static -lm -s -o " + prob;
    //pascal:
    //s = "fpc " + prob + ".pas";
    if(system(s.c_str())) {
        SetConsoleTextAttribute(hConsole, (FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY));
        printf("Compile Error");
        SetConsoleTextAttribute(hConsole, (FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE));
        return 0;
    }
    double poi = 0.0;
    int test = 0;
    f1 = freopen("input.inp","r",stdin);
    while(getline(cin,ti)) {
        getline(cin,to);
        test++;
        Inp.push_back(ti);
        Out.push_back(to);
    }
    for(int i = 0; i < test; i++) {
        ti = Inp[i];
        to = Out[i];
        //p = prob + ".exe < " + ti + " > output.ans";
        cout << "run test " << i+1 << " : ";
        p = "timer.exe -t " + timer + " -b " + prob +".exe<" + ti + ">output.ans";
        c = "fc /w output.ans " + to + hide;
        system(p.c_str());
        if(!system(c.c_str())) RES.push_back("Correct"),poi = poi + 1.0;
        else RES.push_back("Wrong");
    }
    //f2 = freopen("result.txt","w",stdout);
    fclose(f1);
    printf("\n\n\n\t\t    RESULT\n\n");
    for(int i = 0; i < RES.size(); i++) {
        SetConsoleTextAttribute(hConsole, (FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY));
        cout << "\t\tTest " << (i+1) << ": ";
        if(RES[i][0]=='C') {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_GREEN|FOREGROUND_INTENSITY));
            cout << RES[i] << endl;
        } else if(RES[i][0] == 'W') {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_RED|FOREGROUND_INTENSITY));
            cout << RES[i] << endl;
        } else {
            SetConsoleTextAttribute(hConsole, (FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY));
            cout << RES[i] << endl;
        }
        SetConsoleTextAttribute(hConsole, (FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE));

    }
    cout << endl;
    cout << "\t\t   ";
    SetConsoleTextAttribute(hConsole, (FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE));
    cout << "Point: " ;
    printf("%.3lf",poi*100.0/test);
    //if(fabs(poi - 100.0) <= 1e-9) printf("Accepted\n");
    //fclose(f2);
    s = "del output.ans " + prob +".exe";
    system(s.c_str());
    SetConsoleTextAttribute(hConsole, (FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE));
    return 0;
}
