#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Unknown"), _signed(false), _gradeSigned(150), _gradeExecute(150)
{
    std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeSigned(other._gradeSigned), _gradeExecute(other._gradeExecute)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

AForm::AForm(std::string name, int grade) : _name(name), _signed(false), _gradeSigned(grade), _gradeExecute(grade)
{
    if (grade < 1)
        throw AForm::GradeTooHighException();
    if (grade > 150)
        throw AForm::GradeTooLowException();

    std::cout << "AForm parametric constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeSigned, int gradeExecute) : _name(name), _signed(false), _gradeSigned(gradeSigned), _gradeExecute(gradeExecute)
{
    if (gradeSigned < 1 || gradeExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeSigned > 150 || gradeExecute > 150)
        throw AForm::GradeTooLowException();

    std::cout << "AForm parametric constructor (name, sign, exec) called" << std::endl;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSigned)
        throw AForm::GradeTooLowException();

    _signed = true;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeSigned() const
{
    return _gradeSigned;
}

int AForm::getGradeExecute() const
{
    return _gradeExecute;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("AForm grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("grade too low");
}

std::ostream &operator<<(std::ostream &out, const AForm &obj)
{
    out << "AForm " << obj.getName() << ", signed: ";
    if (obj.getSigned())
        out << "yes";
    else
        out << "no";
    out << ", grade required to sign: " << obj.getGradeSigned()
        << ", grade required to execute: " << obj.getGradeExecute();
    return out;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called" << std::endl;
}
