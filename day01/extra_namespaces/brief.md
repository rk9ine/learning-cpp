# Side demo — namespaces (`std::`)

Run it:

```powershell
.\run.ps1 day01\extra_namespaces
```

You get:

```
drawing a circle on screen
drawing a card from the deck
and this cout belongs to the standard library
```

Two functions both named `draw`. No conflict — because each has a different surname.

---

## Now break it (this is the part that makes it click)

Delete both `namespace` wrappers so the file looks like this:

```cpp
#include <iostream>

void draw() { std::cout << "drawing a circle on screen\n"; }
void draw() { std::cout << "drawing a card from the deck\n"; }

int main() {
    draw();
    return 0;
}
```

Compile it. You get:

```
error: redefinition of 'void draw()'
```

The compiler has two different things with the same name and no way to tell them
apart, so it refuses. **That is exactly the problem namespaces solve.**

Now put the namespaces back.

---

## The shortcut, and why you shouldn't use it yet

You'll see this in tutorials everywhere:

```cpp
using namespace std;   // now you can write  cout  instead of  std::cout
```

It means "assume `std` when I don't give a surname." It saves five keystrokes.

Skip it. Reasons:

1. It drags **every** name in the standard library into your file — thousands of them.
   Your own variable named `count` or `data` can suddenly clash with one.
2. Reading someone else's code, `std::` instantly tells you "this is standard library,
   not something defined in this project." That's genuinely useful information.
3. Every professional C++ codebase writes `std::`. Build the habit now, not later.

Type the four extra characters.
