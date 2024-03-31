#include "Header.h"
#include "algorithms.h"
#include "time.h"

int main()
{

    string text, pattern;
    cout << "Enter the text:" << endl;
    cin >> text;
    cout << "Enter the pattern:" << endl;
    cin >> pattern;
    cout << endl;
    rabinkarp_time(pattern, text, 1e4);
    /*cout << "Result of rabinkarp algorithm:" << endl;
    rabinkarp(pattern, text);
    cout << endl;
    cout << "Result of BMH algorithm:" << endl;
    BMH(pattern, text);
    cout << endl;
    cout << "Result of KMP algorithm: " << endl;
    KMP(pattern, text);*/
     return 0;
}