#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>

std::string file_content_to_string(const std::string &filename, std::string filein_content)
{
    std::ostringstream filein_buffer;
    std::ifstream infile(filename.c_str());
    
    if (!infile.is_open())
    {
        std::cerr << "Error opening original file" << std::endl;
        return "";
    }
    filein_buffer << infile.rdbuf();
    infile.close();

    filein_content = filein_buffer.str();
    return (filein_content);
}

std::string replace_occurences(std::string filein_content, std::string s1, std::string s2)
{
    size_t pos = 0;
    while((pos = filein_content.find(s1, pos)) != std::string::npos)
    {
        filein_content.erase(pos, s1.length());
        filein_content.insert(pos, s2);
        pos += s2.length();
    }
    return (filein_content);
}

int write_to_new_file(std::string filename, std::string fileout_content)
{
    filename.append(".replace");
    std::ofstream outfile(filename.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Error opening new file" << std::endl;
        return 1;
    }
    outfile << fileout_content;
    outfile.close();
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 4)
    {
        std::string filename = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];
        std::string filein_content;

        filein_content = file_content_to_string(filename, filein_content);
        if (filein_content.empty())
            return (1);
        std::string fileout_content = replace_occurences(filein_content, s1, s2);
        if (write_to_new_file(filename, fileout_content) == 1)
            return 1;
    }
    else
        std::cerr << "You need to provide 3 parameters [filename, s1, s2]" << std::endl;
    return 0;
}