#include <sys/time.h>
#include "PmergeMe.hpp"
#include <iomanip>

PmergeMe::PmergeMe(){
}

PmergeMe::~PmergeMe(){
}

PmergeMe::PmergeMe(const PmergeMe &other) : _vect(other._vect), _deque(other._deque){
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other){
    if(this != &other){
        _vect = other._vect;
        _deque = other._deque;
    }
    return *this;
}

void PmergeMe::execute() {
    struct timeval start, end;

    //Chrono pour le Vecteur
    gettimeofday(&start, NULL);
    sortVector(_vect);
    gettimeofday(&end, NULL);
    // Calcul en microsecondes
    _vecTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    // Chrono pour le Deque
    gettimeofday(&start, NULL);
    sortDeque(_deque);
    gettimeofday(&end, NULL);
    _deqTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}


void PmergeMe::displayResults() const {
    //affichage du After
    std::cout << "After:  ";
    for (size_t i = 0; i < _vect.size(); ++i) {
       if(i > 0){
        std::cout << " ";
       }
       std::cout << _vect[i];
    }
    std::cout << std::endl;

    std::cout << std::fixed << std::setprecision(5);

    //affichage des temps
    std::cout << "Time to process a range of " << _vect.size() 
              << " elements with std::vector : " << _vecTime << " us" << std::endl;
              
    std::cout << "Time to process a range of " << _vect.size() 
              << " elements with std::deque  : " << _deqTime << " us" << std::endl;
}

//affichage avant
void PmergeMe::displayBefore() const{
    std::cout << "Before: ";
    for(size_t i = 0; i < _vect.size(); ++i){
        std::cout << _vect[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::parseInput(int argc, char **argv){
    if(argc < 2){
        throw std::runtime_error("Error: No arguments provided");
    }
    for (int i = 1; i < argc; ++i){
        char *endptr = NULL;
        long val = std::strtol(argv[i], &endptr, 10);

        if(*endptr != '\0'){
            throw std::runtime_error("Error: Invalid character");
        }


        
        if(val < 0 || val > 2147483647){
            throw std::runtime_error("Error: Invalid number range");
        }

        _vect.push_back(static_cast<int>(val));
        _deque.push_back(static_cast<int>(val));
    }
}


void PmergeMe::sortVector(std::vector<int>& container){

    if(container.size() <= 1){
        return;
    }
    std::vector<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;

    //separation des winners et losers
    for(size_t i = 0; i < container.size() - 1; i += 2){
        if(container[i] < container[i + 1]){
            pairs.push_back(std::make_pair(container[i + 1], container[i]));
        }
        else{
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
        }
    }
    if(container.size() % 2 != 0){
        straggler = container.back();
        hasStraggler = true;
    }

    // trie des winners
    std::vector<int> winners;
    for(size_t i = 0; i < pairs.size(); ++i){
        winners.push_back(pairs[i].first);
    }

    // appel recursif
    sortVector(winners);

    std::vector<int> mainChain;
    std::vector<int> pend;

    //retrouve le premier loser
    for(size_t i = 0; i < pairs.size(); ++i){
        if(pairs[i].first == winners[0]){
            mainChain.push_back(pairs[i].second);
            pairs.erase(pairs.begin() + i); // pour pas de doublons
            break;
        }
    }

    //ajout des winners tries
    for(size_t i = 0; i < winners.size(); ++i){
        mainChain.push_back(winners[i]);
    }

    //on met les autres losers dans pend
    for(size_t i = 1; i < winners.size(); ++i){
        for(size_t j = 0; j < pairs.size(); ++j){
            if (pairs[j].first == winners[i]){
                pend.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }
    if(hasStraggler){
        pend.push_back(straggler);
    }

    //insertion jacobsthal
    std::vector<int> indices = getJacobsthalIndices(pend.size());

    for(size_t i = 0; i < indices.size(); ++i){
        int idx = indices[i];
    
        //verif si l'index existe
        if(static_cast<size_t>(idx) < pend.size()){
            int valinsert = pend[idx];


            // recherche binaire
            std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), valinsert);
            mainChain.insert(it, valinsert);
        }
    }

    //remplace le container d'origine par la mainChain triee
    container = mainChain;
}

std::vector<int> PmergeMe::getJacobsthalIndices(size_t size){
    std::vector<int> jacobIndices;
    if(size == 0){
        return jacobIndices;
    }

    std::vector<int> jacobSeq;
    jacobSeq.push_back(0);
    jacobSeq.push_back(1);

    //generation de la suite jacobsthal
    while(jacobSeq.back() < (int)size){
        int next = jacobSeq[jacobSeq.size() - 1] + 2 * jacobSeq[jacobSeq.size() - 2];
        jacobSeq.push_back(next);
    }   

    std::vector<bool> added(size, false);
    //transformer en indice pour inserer les losers
    for(size_t i = 2; i < jacobSeq.size(); ++i){
        int current = jacobSeq[i];
        int last = jacobSeq[i - 1];

        int startval;
        if(current > static_cast<int>(size)){
            startval = static_cast<int>(size);
        }
        else{
            startval = current;
        }
        while (startval > last) {
            int idx = startval - 1;
            if (idx >= 0 && idx < static_cast<int>(size) && !added[idx]) {
                jacobIndices.push_back(idx);
                added[idx] = true;
            }
            startval--;
        }
    }
    
    //on ajoute les indices restants
    for (int i = 0; i < static_cast<int>(size); ++i) {
        if (!added[i]) {
            jacobIndices.push_back(i);
        }
    }
    return jacobIndices;
}


void PmergeMe::sortDeque(std::deque<int>& container){

    if(container.size() <= 1){
        return;
    }
    std::deque<std::pair<int, int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;

    //separation des winners et losers
    for(size_t i = 0; i < container.size() - 1; i += 2){
        if(container[i] < container[i + 1]){
            pairs.push_back(std::make_pair(container[i + 1], container[i]));
        }
        else{
            pairs.push_back(std::make_pair(container[i], container[i + 1]));
        }
    }
    if(container.size() % 2 != 0){
        straggler = container.back();
        hasStraggler = true;
    }

    // trie des winners
    std::deque<int> winners;
    for(size_t i = 0; i < pairs.size(); ++i){
        winners.push_back(pairs[i].first);
    }

    // appel recursif
    sortDeque(winners);

    std::deque<int> mainChain;
    std::deque<int> pend;

    //retrouve le premier loser
    for(size_t i = 0; i < pairs.size(); ++i){
        if(pairs[i].first == winners[0]){
            mainChain.push_back(pairs[i].second);
            pairs.erase(pairs.begin() + i); // pour pas de doublons
            break;
        }
    }

    //ajout des winners tries
    for(size_t i = 0; i < winners.size(); ++i){
        mainChain.push_back(winners[i]);
    }

    //on met les autres losers dans pend
    for(size_t i = 1; i < winners.size(); ++i){
        for(size_t j = 0; j < pairs.size(); ++j){
            if (pairs[j].first == winners[i]){
                pend.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }
    if(hasStraggler){
        pend.push_back(straggler);
    }

    //insertion jacobsthal
    std::vector<int> indices = getJacobsthalIndices(pend.size());

    for(size_t i = 0; i < indices.size(); ++i){
        int idx = indices[i];
    
        //verif si l'index existe
        if(static_cast<size_t>(idx) < pend.size()){
            int valinsert = pend[idx];


            // recherche binaire
            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), valinsert);
            mainChain.insert(it, valinsert);
        }
    }

    //remplace le container d'origine par la mainChain triee
    container = mainChain;
}