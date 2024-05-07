#include "Header.h"
#include "algorithms.h"
#include "time.h"

int main()
{
    
    string text, pattern;
    cout << "Enter the pattern:" << endl;
    cin >> pattern;
    cout << "Enter the text:" << endl;
    cin >> text;
    cout << endl;
    int size = 50000;
    naiveSearch_time(pattern, text,size);
    //rabinkarp_time(pattern, text, size);
    //KMP_time(pattern, text, size);
    //BMH_time(pattern, text, size);

   /* naiveSearch(pattern, text);
    rabinkarp(pattern, text);
    KMP(pattern, text);
    BMH(pattern, text);
    */
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