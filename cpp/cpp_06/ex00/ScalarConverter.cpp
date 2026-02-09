#include "ScalarConverter.hpp"

// Constructeur par défaut (vide car classe statique)
ScalarConverter::ScalarConverter(){
}

// Constructeur de copie (inutilisé, copy est casté en void pour éviter warning)
ScalarConverter::ScalarConverter(const ScalarConverter &copy){
    (void)copy;
}

// Opérateur d'affectation (inutilisé, copy est casté en void pour éviter warning)
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy){
    (void)copy;
    return *this;
}

// Destructeur (vide car rien à libérer)
ScalarConverter::~ScalarConverter(){   
}

// Fonction pour afficher un caractère
void ScalarConverter::printChar(char c)
{
    // Vérifie si le caractère est affichable (entre espace=32 et tilde=126 en ASCII)
    if (c < 32 || c > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        // Affiche le caractère entre guillemets simples
        std::cout << "char: '" << c << "'" << std::endl;
}

// Vérifie si un nombre double a une partie décimale non nulle
bool hasDecimal(double value) {
    // Compare le nombre original avec sa version tronquée en int
    // Si différent, c'est qu'il y a des décimales (ex: 3.14 != 3.0)
    return value != static_cast<int>(value);
}

// Vérifie si la chaîne contient des caractères autres que chiffres, point, tiret ou 'f'
bool isWord(const std::string &str) {
    // Cherche le premier caractère qui n'est PAS dans "0123456789.-f"
    // Si trouvé (!= npos), c'est un "mot" plutôt qu'un nombre valide
    return str.find_first_not_of("0123456789.-f") != std::string::npos;
}


// Fonction principale de conversion d'une chaîne vers char/int/float/double
void ScalarConverter::convert(const std::string str)
{
    // Vérifie si la chaîne est vide
    if (str.empty())
    {
        std::cout << "Error: Empty string" << std::endl;
        return;
    }
    
    // Déclaration des variables pour stocker les valeurs converties
    int intValue = 0;
    float floatValue = 0.0f;
    double doubleValue = 0.0;
    
    // Cas spécial : un seul caractère qui n'est pas un chiffre (ex: 'a', 'Z', '$')
    if (str.length() == 1 && !isdigit(str[0])) {
        char c = str[0];
        // Convertit le caractère vers les autres types (utilise la valeur ASCII)
        intValue = static_cast<int>(c);
        floatValue = static_cast<float>(c);
        doubleValue = static_cast<double>(c);
        
        // Affiche les résultats
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << intValue << std::endl;
        std::cout << "float: " << floatValue << "f" << std::endl;
        std::cout << "double: " << doubleValue << std::endl;
        return;
    }

    // Si c'est un "mot" (contient des lettres) ET que ce n'est pas une valeur spéciale (nan, inf)
    // alors la conversion est impossible
    if (isWord(str) && str != "nan" && str != "nanf" && str != "+inf" && str != "+inff" && str != "-inf" && str != "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // Tente de convertir la chaîne en int avec istringstream
    std::istringstream iss(str);
    if (!(iss >> intValue))
    {
        // Si la conversion en int échoue (ex: "nan", "inf", texte)
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        // Conversion réussie : affiche le char correspondant
        if (intValue >= 32 && intValue <= 126)
            // Si dans la plage ASCII affichable, affiche le caractère
            std::cout << "char: '" << static_cast<char>(intValue) << "'" << std::endl;
/        else
            // Sinon, c'est un caractère de contrôle non affichable
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << intValue << std::endl;
    }

    // Convertit la chaîne en double avec strtod (gère nan, inf, etc.)
    floatValue = static_cast<float>(std::strtod(str.c_str(), NULL));
    doubleValue = std::strtod(str.c_str(), NULL);

    // Affiche le float : ajoute ".0" si c'est un nombre entier pour la lisibilité
    if (hasDecimal(floatValue))
        std::cout << "float: " << floatValue << "f" << std::endl;
    else
        std::cout << "float: " << floatValue << ".0f" << std::endl;
    
    // Affiche le double : ajoute ".0" si c'est un nombre entier pour la lisibilité
    if (hasDecimal(doubleValue))
        std::cout << "double: " << doubleValue << std::endl;
    else
        std::cout << "double: " << doubleValue << ".0" << std::endl;
}