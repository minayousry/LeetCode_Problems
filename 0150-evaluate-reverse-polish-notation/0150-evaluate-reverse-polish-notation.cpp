#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdexcept>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> data;

        for (const auto& token : tokens) {
            if (isOperator(token)) {
                if (data.size() < 2) {
                    throw std::invalid_argument("Invalid RPN expression");
                }
                int num2 = data.top(); data.pop();
                int num1 = data.top(); data.pop();
                int result = evaluate(num1, num2, token);
                data.push(result);
            } else {
                try {
                    int num = std::stoi(token);
                    data.push(num);
                } catch (const std::invalid_argument&) {
                    throw std::invalid_argument("Invalid token: " + token);
                }
            }
        }

        if (data.size() != 1) {
            throw std::invalid_argument("Invalid RPN expression");
        }

        return data.top();
    }

private:
    bool isOperator(const std::string& token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }

    int evaluate(int num1, int num2, const std::string& op) {
        if (op == "+") return num1 + num2;
        if (op == "-") return num1 - num2;
        if (op == "*") return num1 * num2;
        if (op == "/") {
            if (num2 == 0) throw std::runtime_error("Division by zero");
            return num1 / num2;
        }
        throw std::invalid_argument("Invalid operator: " + op);
    }
};