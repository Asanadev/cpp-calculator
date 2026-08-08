#include <iostream>
#include <string>
#include <cctype>
#include <stdexcept>
#include <algorithm>
#include <cmath>

using std::cout;
using std::cin;
using std::string;

double answer;

double getNumbers(){
    string snum;
    while(true){
        cout << "Number: ";
        cin >> snum;
        for (char &c : snum){
            c = tolower(c);
        }
        if(snum == "ans" || snum == "answer"){
            return answer;
        }
        try{
            return stod(snum);
        }
        catch(const std::invalid_argument&){
            cout << "Invalid input! Enter a number or 'ans'\n";
        }
        catch(const std::out_of_range&){
            cout << "Number is too large. Try again\n";
        }
    }
}

double operate1(double num1){
    const double PI = 3.14159;
    string op;
    while(true){
        cout << "Operator (sqr, sqrt, round, abs, log, sin, cos, tan): ";
        cin >> op;
        transform(op.begin(), op.end(), op.begin(), ::tolower);
        if(op == "sqr"){
            return pow(num1, 2); 
        }
        else if(op == "sqrt"){
            if (num1 < 0){
                cout << "Math Error! Can't take sqrt of negative number.\n";
                continue;
            }
            return sqrt(num1); 
        }
        else if(op == "round"){
            return round(num1); 
        }
        else if(op == "abs" || op == "||"){
            return abs(num1); 
        }
        else if(op == "log"){
            if (num1 < 0){
                cout << "Math Error! Logarithm only for positive numbers.\n";
                continue;
            }
            return log10(num1); 
        }
        else if(op == "sin" || op == "s"){
            num1 = num1*PI/180;
            return sin(num1); 
        }
        else if(op == "cos" || op == "c"){
            num1 = num1*PI/180;
            return cos(num1); 
        }
        else if(op == "tan" || op == "t"){
            num1 = num1*PI/180;
            return tan(num1);
        }
        else{
            cout << "Please choose a valid operator.\n";
            continue;
        }
    }
}

char oP(){
    char op1;
    while(true){
        cout << "Operator (+ - * / ^ %): ";
        cin >> op1;
        if(op1 == '+' || op1 == '-' || op1 == '*' || op1 == '/' || op1 == '^' || op1 == '%' || op1 == 'x'){
            return op1;
        }
        else{
            cout << "Please type in a correct operator.\n";
        }
    }   
}

double operate2(double num1, char op1, double num2){
    switch (op1){
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case 'x':
        case '*':
            return num1 * num2;
        case '/':
            if(num2 ==0){
                cout << "Math Error! Cannot divide by zero";
                return 0;
            }
            return num1 / num2;
        case '^':
            return pow(num1, num2);
        case '%':
            if(num1 == (int)num1 && num2 == (int)num2){
                return (int)num1 % (int)num2;
            }
            else{
                return std::fmod(num1, num2);
            }
        default:
            printf("Please type in a correct operator\n");
            return 0;
            break;
    }
}



int main(){

    int numbers;
    double num;
    double num1;
    double num2;
    char op;
    string playAgain;

    cout << "---------------------------- CALCULATOR ----------------------------\n";
    do{
        if (playAgain.length() != 0){
            cout << "...............................................\n";
        }
        while(true){
            cout << "How many numbers for calculation (1 or 2): ";
            cin >> numbers;
            if(numbers == 1){
                num = getNumbers();
                answer = operate1(num);
                break;
            }        
            else if(numbers == 2){
                num1 = getNumbers();
                op = oP();
                num2 = getNumbers();
                answer = operate2(num1, op, num2);
                break;
            }    
            else{
                cout << "Enter 1 or 2 only.\n";
            }
        }

        cout << "The answer is " << answer << "\n";
        cout << "Continue? (Y/N): ";
        cin >> playAgain;
        transform(playAgain.begin(), playAgain.end(), playAgain.begin(), ::tolower); 
        
        if(playAgain == "no" || playAgain == "n"){
            break;
        }
    }while(true);

    cout << "------------------------------- END -------------------------------\n";

    return 0;
}