#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4)
        return (0);

    if (!argv[1] || !argv[2] || !argv[3])
        return (0);

    // ouvre le fichier d'entree
    std::string filename = argv[1];
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << std::endl;
        return 1;
    }

    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string output_filename = filename + ".replace";
    std::string content;
    std::string line;
    std::string result;
    size_t pos = 0;
    size_t found = 0;

    // on lit le fichier
    while (std::getline(file, line))
    {
        content += line + "\n";
    }
    file.close();

    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(pos, found - pos);

        // + chaine de remplacement
        result += s2;

        // chaine trouvee, avancer
        pos = found + s1.length();
    }
    // reste de la chaine
    result += content.substr(pos);

    std::ofstream outfile(output_filename.c_str());
    if (!outfile.is_open())
    {
        std::cerr << "Erreur : impossible de creer " << output_filename << std::endl;
        return 1;
    }
    outfile << result;
    outfile.close();

    return 0;
}