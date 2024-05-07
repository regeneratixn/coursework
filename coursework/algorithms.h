#pragma once
#include "Header.h"

// Хэш-функция для строки
unsigned long long hashFunc(const string& str, int start, int end) {
    unsigned long long hash = 0;
    int prime = 101; // Простое число для хэширования
    for (int i = start; i <= end; i++) {
        hash += (str[i] * pow(prime, i - start));
    }
    return hash;
}

// Алгоритм Рабина-Карпа для поиска подстроки в строке
void rabinkarp(const string& pattern, const string& text) {
    int pattern_size = pattern.size();
    int text_size = text.size();
    int prime = 101; // Простое число для хэширования
    unsigned long long patternHash = hashFunc(pattern, 0, pattern_size - 1);
    unsigned long long textHash = hashFunc(text, 0, pattern_size - 1);
    bool found = false;

    for (int i = 0; i <= text_size - pattern_size; i++) {
        if (patternHash == textHash) {
            bool match = true;
            for (int j = 0; j < pattern_size; j++) {
                if (pattern[j] != text[i + j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                cout << "Pattern found at index " << i << endl;
                found = true;
            }
        }
        if (i < text_size - pattern_size) {
            textHash = (textHash - text[i] * pow(prime, 0)) / prime + text[i + pattern_size] * pow(prime, pattern_size - 1);
        }
    }

    if (!found) {
        cout << "Pattern not found." << endl;
    }
}


void rabinkarp_t(const string& pattern, const string& text) {
    int pattern_size = pattern.size();
    int text_size = text.size();
    int prime = 101; 
    unsigned long long patternHash = hashFunc(pattern, 0, pattern_size - 1);
    unsigned long long textHash = hashFunc(text, 0, pattern_size - 1);
    bool found = false;

    for (int i = 0; i <= text_size - pattern_size; i++) {
        if (patternHash == textHash) {
            bool match = true;
            for (int j = 0; j < pattern_size; j++) {
                if (pattern[j] != text[i + j]) {
                    match = false;
                    break;
                }
            }
            if (match) {

                found = true;
            }
        }
        if (i < text_size - pattern_size) {
            textHash = (textHash - text[i] * pow(prime, 0)) / prime + text[i + pattern_size] * pow(prime, pattern_size - 1);
        }
    }

    if (!found) {
        ;

    }
}

//Алгоритм Бойера-Мура-Хорспула
vector<int> preprocess(string& substring, int start_index, int end_index)
{
    vector<int> a;
    for (int i = 0; i < end_index - start_index + 1; i++)
    {
        a.push_back(substring.size());
    }
    for (int i = 0; i < substring.size() - 1; i++)
    {
        a[(int)substring[i] - start_index] = substring.size() - i - 1;
    }
    return a;
}

void BMH(string& substring, string& text)
{
    if (substring.size() > text.size())
    {
        cout << "The pattern is longer than the text" << endl;
    }
    bool flag = false;
    int i = substring.size() - 1;
    int n = i;
    int start_index = int(' ');
    int end_index = int('~');
    vector<int> a = preprocess(substring, start_index, end_index);
    while (i < text.size())
    {
        bool match = false;
        int kk = 0;
        for (int k = i - n; k < i + 1; k++)
        {
            if (text[k] != substring[kk]) match = true;
            if (match) break;
            kk++;
        }
        if (match == 0) {
            cout << "Pattern found at index " << i - n << endl;
            flag = true;
        }
        i = i + a[(int)text[i] - start_index];
    } if (flag == false) cout << "Pattern not found." << endl;


}
void BMH_t(string& substring, string& text)
{
    if (substring.size() > text.size())
    {
        cout << "The pattern is longer than the text" << endl;
    }
    bool flag = false;
    int i = substring.size() - 1;
    int n = i;
    int start_index = int(' ');
    int end_index = int('~');
    vector<int> a = preprocess(substring, start_index, end_index);
    while (i < text.size())
    {
        bool match = false;
        int kk = 0;
        for (int k = i - n; k < i + 1; k++)
        {
            if (text[k] != substring[kk]) match = true;
            if (match) break;
            kk++;
        }
        if (match == 0) {
            //cout << "Pattern found at index " << i - n << endl;
            flag = true;
        }
        i = i + a[(int)text[i] - start_index];
    } if (flag == false) ; //cout << "Pattern not found." << endl;


}

vector<int> prefix_function(string& substring)
{
    int substring_size = substring.size();
    vector<int> pi;
    for (int i = 0; i < substring_size; i++)
    {
        pi.push_back(0);
    }
    for (int i = 1; i < substring_size; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && substring[j] != substring[i])
            j = pi[j - 1];
        if (substring[i] == substring[j])
            j++;
        pi[i] = j;
    }return pi;

}
//Алгоритм Кнута-Морриса-Пратта
void KMP(string& substring, string& text, int start_index = 0)
{
    int j = 0;
    vector<int> resultOfprefixfunction = prefix_function(substring);
    bool flag = false;
    for (int i = 0; i < text.size(); i++)
    {
        while (j > 0 && text[i] != substring[j])
        {
            j = resultOfprefixfunction[j - 1];
        }
        if (text[i] == substring[j])
        {
            j++;
        }
        if (j >= substring.size())
        {
            cout << "Pattern found at index " << i - j + 1 << endl;
            flag = true;
        }
    } if (flag == false) cout << "Pattern not found." << endl;
}
void KMP_t(string& substring, string& text, int start_index = 0)
{
    int j = 0;
    vector<int> resultOfprefixfunction = prefix_function(substring);
    bool flag = false;
    for (int i = 0; i < text.size(); i++)
    {
        while (j > 0 && text[i] != substring[j])
        {
            j = resultOfprefixfunction[j - 1];
        }
        if (text[i] == substring[j])
        {
            j++;
        }
        if (j >= substring.size())
        {
            //cout << "Pattern found at index " << i - j + 1 << endl;
            flag = true;
        }
    } if (flag == false) ; //cout << "Pattern not found." << endl;
}

//Наивный алгоритм
void naiveSearch(const string& pattern, const string& text) {
    int n = text.length();
    int m = pattern.length();
    bool found = false;
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
            found = true;
           // return;  // Нашли вхождение подстроки, завершаем функцию
        }
    }

    if(!found) cout << "Pattern not found." << endl;
}

void naiveSearch_t(const string& pattern, const string& text) 
{
    int n = text.length();
    int m = pattern.length();
    bool found = false;
    for (int i = 0; i <= n - m; ++i) {
        int j = 0;
        //if(i%100==0) cout << "i = " << i << endl;
        while (j < m && text[i + j] == pattern[j]) {
            ++j;
        }
        if (j == m) {
            //cout << "Pattern found at index " << i << endl;
            found = true;
            // return;  // Нашли вхождение подстроки, завершаем функцию
        }
    }

    if (!found) cout << "Pattern not found." << endl;
}

