#pragma once
#include <iostream>
#include <string>

class Bureaucrat;

class AForm{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeSigned;
        const int _gradeExecute;

    public:
        AForm();
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        AForm(std::string name, int gradeSigned);
        AForm(std::string name, int gradeSigned, int gradeExecute);
        std::string getName() const;
        bool getSigned() const;
        int getGradeSigned() const;
        int getGradeExecute() const;
        void beSigned(Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
        virtual ~AForm();

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

std::ostream &operator<<(std::ostream &out, const AForm &obj);
