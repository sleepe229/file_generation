
#include <iostream>
#include <fstream>
#include <set>
#include <random>

void generateFile(int N, int Q)
{
    std::ofstream file("test.txt");
    std::set<std::string> words;
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < N; i++)
    {
        std::string word;
        int length = std::uniform_int_distribution<int>(1, 2 * static_cast<int>(std::pow(10, 4)))(gen);
        for (int j = 0; j < length; j++)
        {
            char randomChar = static_cast<char>(std::uniform_int_distribution<int>('a', 'z')(gen));
            word += randomChar;
        }
        words.insert(word);
    }

    std::set<std::string> uniqueRequests;

    for (int i = 0; i < Q; i++)
    {
        int k = std::uniform_int_distribution<int>(1, static_cast<int>(std::pow(10, 9)))(gen);
        std::string p;
        int pLength = std::uniform_int_distribution<int>(1, static_cast<int>(std::pow(10, 3)))(gen);
        for (int j = 0; j < pLength; j++)
        {
            char randomChar = static_cast<char>(std::uniform_int_distribution<int>('a', 'z')(gen));
            p += randomChar;
        }
        std::string request = std::to_string(k) + " " + p;
        uniqueRequests.insert(request);
    }

    file << words.size() << " " << uniqueRequests.size() << "\n";

    for (const auto &word : words)
    {
        file << word << "\n";
    }

    for (const auto &request : uniqueRequests)
    {
        file << request << "\n";
    }
}

int main()
{
    int N = static_cast<int>(3 * std::pow(10, 5));
    int Q = static_cast<int>(5 * std::pow(10, 3));
    generateFile(N, Q);

    return 0;
}
