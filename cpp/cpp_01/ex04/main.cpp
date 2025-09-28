#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if(argc != 4)
        return(0);
    
    if(!argv[1] || !argv[2] || !argv[3])
        return(0);

    std::string filename = argv[1];
    std::ifstream file(filename.c_str());

    if (!file.is_open()) {
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

    while (std::getline(file, line)) {
        content += line + "\n";
    }

    while ((found = content.find(s1, pos)) != std::string::npos) {
        // Ajouter la partie avant la correspondance
        result += content.substr(pos, found - pos);
    
        // Ajouter la chaîne de remplacement
        result += s2;
    
        // Avancer après la chaîne trouvée
        pos = found + s1.length();
    }

    result += content.substr(pos);
    std::ofstream outfile(output_filename.c_str());
    if(!outfile.is_open()){
        std::cerr << "Erreur : impossible de creer " << output_filename << std::endl;
        return 1;
    }
    outfile << result;
}