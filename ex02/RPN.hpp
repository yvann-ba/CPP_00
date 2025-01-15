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

    // This function takes an RPN expression (e.g. "8 9 * ...")
    // and returns the result as an integer.
    // If there's an error in the expression, we throw an exception (or return false, etc.).
    // We'll use an exception approach for demonstration.
    int calculateExpression(const std::string &expr);

private:
    bool isOperator(const std::string &token) const;
    int  applyOperation(const std::string &op, int a, int b) const;
};

#endif
