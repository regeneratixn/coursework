#pragma once
#include "Header.h"
#include "algorithms.h"


void rabinkarp_time(string& pattern, string& text, int range)
{
    srand(time(0));
    ofstream dataFile("data.txt");
    dataFile << "Size,Time\n";
    for (int n = 0; n <= range; n++)
    {
        int tempchar = 0;
        while ((tempchar > 90 && tempchar < 97) || tempchar == 0) tempchar = 65 + rand() % 58;
        text += (char)tempchar;

        auto start = high_resolution_clock::now();
        //cout << "Result of rabinkarp algorithm:" << endl;
        rabinkarp_t(pattern, text);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        dataFile << n << " " << duration << endl;


    } dataFile.close();
}

