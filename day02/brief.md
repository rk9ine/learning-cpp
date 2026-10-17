# Day 02 — Guess the Number

**Build:** a program that picks a random number 1–100, you guess, it tells you "too high", "too low", or "correct".
**Learn:** `if` / `else`, comparison operators, loops.

---

## 1. The control flow problem (why this matters)

Yesterday your program did A, then B, then C — straight line, no decisions.

Real programs branch: "if the user entered garbage, error. If it's valid, continue. If it's negative, handle differently."

C++ has three tools for this:

1. **`if` / `else`** — make a decision once
2. **`while` loop** — repeat until something becomes true
3. **`for` loop** — repeat a known number of times

Today you learn the first two. By the end, your program will loop: ask for a guess, check it, keep looping until correct.

---

## 2. Comparison operators (the building blocks)

Before you can make decisions, you need to compare things.

```cpp
5 == 5      // true (equals)
5 != 3      // true (not equals)
5 > 3       // true (greater than)
5 < 3       // false (less than)
5 >= 5      // true (greater than or equal)
5 <= 3      // false (less than or equal)
```

**Important:** `==` is "equals". `=` is "assign". Mixing them up is a classic trap:

```cpp
if (x = 5)  // BUG: assigns 5 to x, doesn't check if x equals 5
if (x == 5) // CORRECT: checks if x equals 5
```

The compiler won't stop you. It'll just do the wrong thing.

---

## 3. `if` and `else`

Making a decision:

```cpp
int guess = 42;
int number = 50;

if (guess < number) {
    std::cout << "Too low\n";
}
else if (guess > number) {
    std::cout << "Too high\n";
}
else {
    std::cout << "Correct!\n";
}
```

How to read this:

- `if (condition) { do this }`
- `else if (other condition) { do this instead }`
- `else { do this if none of the above matched }`

Only one block runs. The others are skipped.

---

## 4. `while` loops (repeat until)

You want to ask for a guess, check it, ask again if wrong, repeat until right.

```cpp
int guess = 0;
int number = 50;

while (guess != number) {
    std::cout << "Guess: ";
    std::cin >> guess;

    if (guess < number) {
        std::cout << "Too low\n";
    }
    else if (guess > number) {
        std::cout << "Too high\n";
    }
}

std::cout << "Correct!\n";
```

How it works:

1. Check the condition: `guess != number` (is the guess wrong?)
2. If true: run the block, loop back to step 1
3. If false: skip the block, keep going after the `}`

So it **keeps looping as long as the condition is true**. When it becomes false, it exits.

---

## 5. Picking a random number

C++ doesn't have built-in "pick a random number" — you have to use a library.

```cpp
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    int number = dis(gen);
    // now 'number' is a random int from 1 to 100
}
```

This looks scary. Don't memorize it. **Just copy this exact block.** It's boilerplate.

What it does:
- `std::random_device rd` — seed (get randomness from the OS)
- `std::mt19937 gen(rd())` — the random generator
- `std::uniform_int_distribution<> dis(1, 100)` — "give me ints from 1 to 100"
- `dis(gen)` — "generate one"

You'll use this exact pattern forever. Memorize it by copying it multiple times.

---

## 6. Do it

1. Open `main.cpp`, fill in TODOs
2. `.\run.ps1 day02`
3. Guess a few numbers, verify "too low", "too high", "correct" all work
4. Verify the program loops correctly (keeps asking until you get it right)

---

## 7. Break it on purpose

1. Change `while (guess != number)` to `while (guess == number)`. What happens? (It never loops.)
2. Delete the `else if` block. What happens? (It'll say "too low" even when too high.)
3. Change `<` to `>` in one of the comparisons. Break the logic on purpose and see what happens.
4. Remove the `std::cin >> guess` line from inside the loop. Watch it loop forever (Ctrl+C to kill it).

---

## 8. The rep

```powershell
.\run.ps1 day02 -Rep
```

Rewrite from memory. You only need to remember the new parts: the boilerplate random number code and the `if`/`else`/`while` structure. Everything else is like day 01.
