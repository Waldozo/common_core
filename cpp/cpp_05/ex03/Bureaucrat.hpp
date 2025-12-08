#pragma once
#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat
{

private:
    int _grade;
    const std::string _name;

public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat &name);
    Bureaucrat &operator=(const Bureaucrat &other);
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    int IncrementGrade();
    int DecrementGrade();
    std::string getName() const;
    int getGrade() const;
    void signForm(AForm &form);
    void executeForm(AForm const &form) const;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj);