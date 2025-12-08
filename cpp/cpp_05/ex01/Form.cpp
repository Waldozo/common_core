#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Unknown"), _signed(false), _gradeSigned(150), _gradeExecute(150)
{
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeSigned(other._gradeSigned), _gradeExecute(other._gradeExecute)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_signed = other._signed;
    }
    return (*this);
}

Form::Form(std::string name, int grade) : _name(name), _signed(false), _gradeSigned(grade), _gradeExecute(grade)
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();

    std::cout << "Form parametric constructor called" << std::endl;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeSigned)
        throw Form::GradeTooLowException();

    _signed = true;
}

std::string Form::getName() const
{
    return _name;
}

bool Form::getSigned() const
{
    return _signed;
}

int Form::getGradeSigned() const
{
    return _gradeSigned;
}

int Form::getGradeExecute() const
{
    return _gradeExecute;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("grade too low");
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << "Form " << obj.getName() << ", signed: ";
    if (obj.getSigned())
        out << "yes";
    else
        out << "no";
    out << ", grade required to sign: " << obj.getGradeSigned()
        << ", grade required to execute: " << obj.getGradeExecute();
    return out;
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}
