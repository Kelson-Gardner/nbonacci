//
//  main.cpp
//  nbonacci
//
//  Created by Kelson on 9/6/24.
//

#include <iostream>
#include <string>
#include <array>

long nbonacci(unsigned int series, unsigned int n){
    if(n < series){
        return 1;
    }
    long sum{0};
    for(int i{1}; i <= series; i++){
        sum += nbonacci(series, n - i);
    }
    return sum;
}

void computeNbonacciRatio(std::string title, unsigned int series){
    double ratioDiff{1.0000000};
    double currDiff{0};
    unsigned int index{series + 1};
    double prevRatio = nbonacci(series, index) / static_cast<double>(nbonacci(series, index - 1));
    while(ratioDiff > .000001){
        double currRatio = nbonacci(series, index + 1) / static_cast<double>(nbonacci(series, index));
        ratioDiff = std::abs(currRatio - prevRatio);
        index += 1;
        if(ratioDiff <= .000001){
            std::cout << title << " ratio approaches " << currRatio << " after " << index << " iterations\n";
        }
        prevRatio = currRatio;
    }
}

int main(int argc, const char * argv[]) {
    std::array<std::string, 4> naccis = {"Fibonacci", "Tribonacci", "Fourbonacci", "Fivebonacci"};
    
    for(int series{0}; series < 4; series++){
        std::cout << "--- " << naccis[series] << " Sequence" << " ---\n";
        for(int n{0}; n < 20; n++){
            long output = nbonacci(series + 2, n);
            std::cout << output << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    for(int i{0}; i < 4; i++){
        computeNbonacciRatio(naccis[i], i + 2);
    }
    return 0;
}
