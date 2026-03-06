#pragma once
#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>

class PmergeMe{
    private:
        std::vector<int> _vect;
        std::deque<int> _deque;
        double           _vecTime;
        double           _deqTime;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        
        void parseInput(int ac, char **av);
        void execute();
        void displayResults() const;
        void displayBefore() const;
        void sortVector(std::vector<int>& container);
        void sortDeque(std::deque<int>& container);
        std::vector<int> getJacobsthalIndices(size_t size);
};