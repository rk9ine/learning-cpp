// Side demo: why namespaces exist.
// Run it:  .\run.ps1 day01\extra_namespaces

#include <iostream>

// Pretend this is a drawing library someone else wrote.
namespace graphics {
    void draw() { std::cout << "drawing a circle on screen\n"; }
}

// Pretend this is a card game library from a totally different author.
namespace cards {
    void draw() { std::cout << "drawing a card from the deck\n"; }
}

int main() {
    // Both are named draw(). Both mean completely different things.
    // The surname tells the compiler which one you want.
    graphics::draw();
    cards::draw();

    // Same idea. cout's surname is std.
    std::cout << "and this cout belongs to the standard library\n";

    return 0;
}
