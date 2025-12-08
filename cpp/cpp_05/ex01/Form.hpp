#pragma once
#include <iostream>
#include <string>

class Bureaucrat;

class Form{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSigned;
        const int _gradeExecute;

    public:
        Form();
        Form(const Form &other);
        Form &operator=(const Form &other);
        Form(std::string name, int gradeSigned);
        Form(std::string name, int gradeSigned, int gradeExecute);
        std::string getName() const;
        bool getSigned() const;
        int getGradeSigned() const;
        int getGradeExecute() const;
        void beSigned(Bureaucrat &bureaucrat);
        ~Form();

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

std::ostream &operator<<(std::ostream &out, const Form &obj);
