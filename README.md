# C++ — zero to pro, one small project a day

## The daily loop (25–40 min)

1. **Read the brief** — `dayNN/brief.md`. Max 5 min. Never longer.
2. **Type the code** — open `dayNN/main.cpp`, fill in the `TODO` blanks. Do NOT copy-paste.
3. **Run it** — `.\run.ps1 dayNN`
4. **THE REP** — delete `main.cpp`, write the whole thing again from memory.
   Get stuck? Peek, then delete and restart from zero. This step *is* the learning.
5. **Break it on purpose** — brief ends with "Break it" experiments. Do them. Read the compiler error.

Rule: if you didn't do step 4, the day doesn't count.

## Rules

- Never copy-paste code. Typing is how muscle memory forms.
- Compiler errors are the curriculum, not an interruption. Read them.
- Stuck >10 min on one thing: note it in `questions.md`, move on, ask me.
- One day missed is fine. Two in a row is a habit forming.

## Running

```powershell
.\run.ps1 day01        # compile + run
.\run.ps1 day01 -Rep   # wipes main.cpp back to a blank skeleton for step 4
```

Flags used: `-std=c++23 -Wall -Wextra -Wpedantic`
Warnings are ON hard on purpose. A warning is a bug that hasn't happened yet.

## Roadmap (phases, not a rigid calendar)

| Phase | Days | What you walk away with |
|---|---|---|
| 1. Mechanics | 1–14 | Types, control flow, functions, the compile→link→run model |
| 2. Memory | 15–30 | Pointers, references, stack vs heap, arrays, **this is where C++ becomes C++** |
| 3. Objects | 31–50 | Classes, RAII, constructors/destructors, the Rule of Five |
| 4. The STL | 51–70 | vector, map, string, iterators, algorithms, ranges |
| 5. Templates | 71–90 | Generics, concepts, compile-time programming |
| 6. Modern C++ | 91–110 | Move semantics, smart pointers, lambdas, `constexpr` |
| 7. Concurrency | 111–125 | Threads, mutexes, atomics, async |
| 8. Pro | 126+ | Build systems, testing, profiling, writing a real library |

Phase 2 is the one that separates C++ programmers from people who "know C++ syntax".
Everything after it depends on it. We go slow there.

## Progress

- [x] Day 01 — Unit converter · compile model, types, integer division
- [x] Day 02 — Guess the number · if/else, while loops, comparisons
- [ ] Day 03 — Multiplication table · for loops, nested loops
