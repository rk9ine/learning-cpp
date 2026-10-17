// This demo INTENTIONALLY has a bug. It won't compile.
// Run it:  .\run.ps1 day01\demo_missing_include
//
// You will see:
//   error: 'cout' was not declared in this scope
//
// That's what happens when you forget #include <iostream>

// NOTE: The #include line is commented out on purpose:
// #include <iostream>

int main() {
    std::cout << "Hello\n";
    return 0;
}
