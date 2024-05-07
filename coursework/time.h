#pragma once
#include "Header.h"
#include "algorithms.h"


void naiveSearch_time(string& pattern, string& text, int range)
{
    srand(time(0));
    ofstream dataFile("naiveSearch.txt");
    dataFile << "Size,Time\n";
    for (int n = 0; n <= range; n++)
    {
        int tempchar = 0;
        while ((tempchar > 90 && tempchar < 97) || tempchar == 0) tempchar = 65 + rand() % 58;
        text += (char)tempchar;

        auto start = high_resolution_clock::now();
        //cout << "Result of rabinkarp algorithm:" << endl;
        naiveSearch_t(pattern, text);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        dataFile << n << " " << duration << endl;


    } dataFile.close();
}

void rabinkarp_time(string& pattern, string& text, int range)
{
    srand(time(0));
    ofstream dataFile("rabinkarp.txt");
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

void KMP_time(string& pattern, string& text, int range)
{
    srand(time(0));
    ofstream dataFile("KMP.txt");
    dataFile << "Size,Time\n";
    for (int n = 0; n <= range; n++)
    {
        int tempchar = 0;
        while ((tempchar > 90 && tempchar < 97) || tempchar == 0) tempchar = 65 + rand() % 58;
        text += (char)tempchar;

        auto start = high_resolution_clock::now();
        //cout << "Result of rabinkarp algorithm:" << endl;
        KMP_t(pattern, text);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        dataFile << n << " " << duration << endl;


    } dataFile.close();
}

void BMH_time(string& pattern, string& text, int range)
{
    srand(time(0));
    ofstream dataFile("BMH.txt");
    dataFile << "Size,Time\n";
    for (int n = 0; n <= range; n++)
    {
        int tempchar = 0;
        while ((tempchar > 90 && tempchar < 97) || tempchar == 0) tempchar = 65 + rand() % 58;
        text += (char)tempchar;

        auto start = high_resolution_clock::now();
        //cout << "Result of rabinkarp algorithm:" << endl;
        BMH_t(pattern, text);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start).count();
        dataFile << n << " " << duration << endl;


    } dataFile.close();
}






