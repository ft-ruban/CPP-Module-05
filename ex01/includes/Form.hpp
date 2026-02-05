

#include <string>
#include "Bureaucrat.hpp"

class Form{
    public:
        class GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        
        Form(std::string given_name, int given_req_grade_to_sign, int given_req_grade_to_exec);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        std::string getName()const;
        bool        getIsSigned()const;
        int         getReqGradeToSign()const;
        int         getReqGradeToExec()const;
    
        void beSigned(const Bureaucrat &bureaucrat);


    private:
        const std::string name_;
        bool              is_signed_;
        const int         req_grade_to_sign_;
        const int         req_grade_to_exec_;
};