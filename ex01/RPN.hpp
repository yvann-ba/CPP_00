#ifndef RPN_HPP
# define RPN_HPP

# include <string>

class RPN
{
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int calculateExpression(const std::string &expr);

private:
    bool isOperator(const std::string &token) const;
    int  applyOperation(const std::string &op, int a, int b) const;
};

#endif
