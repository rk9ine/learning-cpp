// Demo: why 9 / 5 is NOT 1.8
// Run it:  .\run.ps1 day01\demo_integer_division

#include <iostream>

int main() {
    // Integer division: throw away the remainder
    std::cout << "9 / 5 = " << 9 / 5 << "\n";

    // Decimal division: keep the decimal
    std::cout << "9.0 / 5.0 = " << 9.0 / 5.0 << "\n";

    // Real danger: the formula with int division
    double celsius = 36.0;
    int wrong_result = (9 / 5) * celsius;     // 9/5 = 1, then 1*36 = 36
    double correct_result = (9.0 / 5.0) * celsius; // 1.8 * 36 = 64.8

    std::cout << "\nMultiplying 36 by 9/5:\n";
    std::cout << "  9 / 5 (int) = " << 9 / 5 << "\n";
    std::cout << "  wrong: (9/5) * 36 = " << wrong_result << "\n";
    std::cout << "  correct: (9.0/5.0) * 36 = " << correct_result << "\n";

    return 0;
}
