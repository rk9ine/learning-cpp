# Day 01 — Temperature Converter

**Build:** a program that asks for a Celsius value and prints the Fahrenheit.
**Learn:** what a C++ program *actually is*, and the #1 trap beginners hit.

---

## 1. What C++ actually does (this matters)

Python runs your text directly. **C++ does not.**

Imagine you write a recipe in French, but your kitchen only speaks English. Three steps happen:

```
Recipe (French)  →  [Translate]  →  Instructions (English)  →  [Cook]  →  Dinner
   your.py                             machine code              your computer
```

C++ is the same idea:

```
main.cpp  →  [Compiler]  →  machine code  →  [OS loads it]  →  app.exe runs
  text        converts       0s and 1s        raw CPU speed
```

**Why this matters:** By the time your program runs, there's no C++ left. It's pure CPU
instructions. That's why C++ is *fast*. It's also why the compiler is *strict* — it has
to know everything about your code (types, sizes, everything) *before* it translates it.

If Python has a question about your code, it asks at runtime: *"What is this thing?"*

C++ has a question about your code, it asks at compile time: *"What is this thing?"* If
the compiler can't figure it out before translating, compilation fails.

**Hold onto this: the compiler must know everything up front.**


---

## 2. Line by line, what your code does

Let's build it piece by piece.

### Line 1: `#include <iostream>`

Your code needs to print text to the terminal. But C++ doesn't have that built-in — it's
optional. So you have to ask for it.

`#include` literally means *"paste the contents of this file here, right now, before
compiling."* It's a copy-paste that happens automatically.

`<iostream>` is a file (the angle brackets mean "it's system-provided, not in this folder").
It declares `std::cout` (for printing) and `std::cin` (for reading from keyboard).

**Without this line, the compiler has never heard of `cout` or `cin`.** Compile fails.

Run this demo to see it:

```powershell
.\run.ps1 day01\demo_missing_include
```

You'll get a compile error that says `cout was not declared`.


### Line 2-3: `int main() {`

Every C++ program starts here. The operating system calls `main` when it runs your `.exe`.

`int` means `main` hands a whole number back to the OS when it's done. By convention:
- **0 means success** — the program worked fine
- **anything else means failure** — something went wrong

You'll see this in the output: `--- exit code: 0 ---` means the OS got `0` back.

There's exactly one `main()` per program. No more, no less.


### Line 5: `double celsius = 0.0;`

This reserves memory and creates a variable.

Break it down:

```
double    celsius    =    0.0   ;
  │         │        │     │    └─ End of statement
  │         │        │     └─ Initial value
  │         │        └─ Assign this value
  │         └─ Variable name
  └─ Type: decimal number
```

`double` is a type — it means "a decimal number, 8 bytes, with decimals."
`int` is a different type — "a whole number, 4 bytes, no decimals."

**The key rule: you must state the type.** The compiler will not guess.

If you write `celsius = 0.0;` without the `double`, compile fails:
`error: 'celsius' was not declared in this scope`

The compiler sees a name it's never heard of and refuses to guess what it is.


### Line 7: `std::cout << "Celsius: ";`

`cout` is a thing that prints text to the terminal.

`std::` is its surname (we covered this — see day01/extra_namespaces if you skipped it).

`<<` is an arrow pointing *into* cout. Think of cout as a mailbox, and `<<` pushes things
into it from the left:

```
"Celsius: "  <<  cout
    │             │
    └─ This thing goes into that mailbox
```

Wait, I wrote it backwards. Let me rewrite:

```
std::cout  <<  "Celsius: "
   │            │
   └─ mailbox   └─ thing going in
```

`<<` is an operator that means "push into". Read it left to right.

Here's the demo:

```cpp
std::cout << "Hello";
std::cout << " ";
std::cout << "World";
std::cout << "\n";
```

Output:

```
Hello World
```

Each `<<` pushes more text. Chain them:

```cpp
std::cout << "Hello" << " " << "World" << "\n";
```

Same output, one line.

`"\n"` is a newline (the Enter key).


### Line 9: `std::cin >> caesar;`

`cin` is a thing that reads from your keyboard. `>>` is an arrow pointing *out of* cin
into your variable:

```
std::cin  >>  celsius
   │          │
   └─ mailbox └─ variable receiving data
```

The program freezes here and waits. You type a number and press Enter. That number gets
stored in `celsius`.

If you type `25`, then `celsius` becomes `25.0` (remember, it's a `double`).


### Line 11: `double fahrenheit = celsius * 9.0 / 5.0 + 32.0;`

Math, like school. `*` and `/` run before `+`, same precedence rules.

**This is where the trap lives.** See Section 3.


### Line 13: `std::cout << celsius << "C = " << fahrenheit << "F\n";`

Chain multiple `<<` operations. Outputs:

```
25C = 77F
```


### Line 15: `return 0;`

Hand the number `0` back to the operating system. Means "I succeeded, everything is fine."

This is the last line in `main()`, so the program ends.

---

## 3. The trap — why this matters

Why did I write `9.0 / 5.0` and not `9 / 5`?

In C++, **the type of the answer depends on the types you divide.**

- `9.0 / 5.0` → both are `double` → answer is `double` → **1.8**
- `9 / 5` → both are `int` → answer is `int` → **1**

When you divide two `int`s, C++ throws away the remainder. No warning. No error. Just gone.

```cpp
std::cout << 9 / 5 << "\n";    // prints:  1
std::cout << 9.0 / 5.0 << "\n"; // prints:  1.8
```

Run this demo:

```powershell
.\run.ps1 day01\demo_integer_division
```

This bug has shipped in real production software and cost real money. I've seen it in code
that controls medical devices and financial calculations. The compiler *could* warn you,
but it doesn't — `int` division is valid, just different from `double` division.

Remember: **the type is part of the answer, not just decoration.**

---

## 4. Do it

1. Open `main.cpp`
2. Fill in every `TODO`
3. `.\run.ps1 day01`
4. Test: enter `100` → should print `212F`. Enter `0` → should print `32F`. Enter `-40` → should print `-40F`.

---

## 5. Break it on purpose (read the errors)

Do all four. This is where you learn error messages. They look scary, but each one is the
compiler trying to help.

### Break 1: Integer division trap

Change line 11 to:

```cpp
double fahrenheit = celsius * 9 / 5 + 32;
```

Run it. Enter `100`. You get `212` printed, not `212.0`. Actually, wait — that's fine, right?

Wrong. Enter `36`. You get `96` instead of `96.8`. The `.8` vanished.

Read the compiler output. It compiles fine — no error, no warning. That's the danger. Your code is broken and the compiler didn't tell you.

### Break 2: Missing header

Delete `#include <iostream>` and compile.

```powershell
.\run.ps1 day01
```

You get:

```
error: 'cout' was not declared in this scope
error: 'cin' was not declared in this scope
```

This is what missing `#include` looks like. The compiler has never heard of these names.

### Break 3: Type mismatch

Change `double celsius` to `int celsius`. Compile and run, then enter `36.5`.

It accepts the input but throws away the `.5`. The variable is `int`, so it only stores
whole numbers. No error, just silent data loss.

### Break 4: Missing semicolon

Delete the `;` at the end of any statement (try the `double fahrenheit =` line).

The error message might point to the *next* line, not the line with the missing `;`. This
confuses everyone. The compiler doesn't know it's missing until it reads the next line and
realizes something is wrong.

---

## 6. The rep (this is the learning part)

```powershell
.\run.ps1 day01 -Rep
```

This wipes `main.cpp` and puts back the skeleton with TODOs.

Write the whole thing from memory. Don't peek. If you get stuck:

1. Note what you forgot on a piece of paper
2. Peek at the original, just that line
3. Delete the file and start over from scratch

Do this until you can write the whole program without stopping. That's when it's locked in.

---

## Demos (optional, but they help)

`.\run.ps1 day01\extra_namespaces` — two functions with the same name, no collision
`.\run.ps1 day01\demo_missing_include` — what happens when you forget `#include`
`.\run.ps1 day01\demo_integer_division` — the trap, in action
