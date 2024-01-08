#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::string input_file_name = "input_file.txt";

int main(int, char**)
{
    std::cout << "\nExample program for sorting words from text file\n";

    //open file
    std::fstream file_to_open(input_file_name);

    try
    {
        if (!file_to_open.is_open())
        {
            throw std::runtime_error("Error while opening file " + input_file_name + ". Check if file exists.");
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    };

    //read lines into vector
    std::vector<std::string> list_of_words;

    std::string line;
    while(std::getline(file_to_open, line))
    {
        list_of_words.push_back(line);
    };

    //close file
    file_to_open.close();

    std::cout << "\n==============================\n";

    //print vector
    std::cout << "Unsorted list:\n\n";
    for (auto it=list_of_words.begin(); it < list_of_words.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "\n==============================\n";

    //sort vector
    std::sort(list_of_words.begin(), list_of_words.end(), [](std::string a, std::string b){return (a < b);});

    //print sorted vector
    std::cout << "Sorted list:\n\n";
    for (auto it=list_of_words.begin(); it < list_of_words.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << "\n==============================\n";

    //create new file and clear it
    std::ofstream output_file("output_file.txt", std::ios::trunc);

    try
    {
        if(!output_file.is_open())
        {
            throw std::runtime_error("Error while creating output_file.txt");
        }
    }
    catch (std::runtime_error & e)
    {
        std::cerr << e.what() << std::endl;
        return 1; 
    };

    //write all vector sorted members into output file
    for(auto it = list_of_words.begin(); it < list_of_words.end(); it++)
    {
        output_file << *it << std::endl;
    }

    //close file
    output_file.close();

    std::cout << "\nSorted file saved succesfully.\n\n";
    
}
