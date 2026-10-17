# Day 03 — Multiplication Table

**Build:** print a 10×10 multiplication table (1-10 times 1-10).
**Learn:** `for` loops, nested loops.

---

## 1. `for` loops vs `while` loops

Yesterday you used `while`:

```cpp
while (guess != number) {  // Check condition, then repeat
    std::cin >> guess;
    // ...
}
```

Today you use `for`. It's cleaner when you know how many times to repeat.

```cpp
for (int i = 1; i <= 10; i++) {  // Start, stop, step
    std::cout << i << "\n";
}
```

Output:
```
1
2
3
...
10
```

**Why `for` instead of `while`?** When you know the exact count, `for` is simpler and faster to read.

---

## 2. How `for` works

```cpp
for (int i = 1; i <= 10; i++) {
    // body
}
```

Four parts:

```
for (  init    ;  condition  ;  increment  ) {
        │         │              │
        │         │              └─ Run after each loop: i++
        │         └─ Check before each loop
        └─ Run once at start: i = 1
```

**Step by step:**

1. `int i = 1` — create `i`, set it to 1
2. Check: `i <= 10`? YES
3. Run the body
4. Run `i++` (increment: i becomes 2)
5. Check: `i <= 10`? YES
6. Run the body
7. Run `i++` (i becomes 3)
8. ... repeat ...
9. Check: `i <= 10`? NO → Exit loop

So `for (int i = 1; i <= 10; i++)` means: **"repeat 10 times, with i going from 1 to 10"**.

---

## 3. The difference: `i++` explained

`i++` means "increment i by 1". It's shorthand for `i = i + 1`.

You could also write:

```cpp
for (int i = 1; i <= 10; i = i + 1) {  // Same thing, more verbose
    std::cout << i << "\n";
}
```

Or:

```cpp
for (int i = 1; i <= 10; i += 2) {  // Increment by 2 each time
    std::cout << i << "\n";  // Prints: 1, 3, 5, 7, 9
}
```

The increment part is flexible. Use whatever makes sense.

---

## 4. Nested loops (loop inside a loop)

**Goal:** print a 10×10 table.

```
1   2   3   4   5   ...
2   4   6   8   10  ...
3   6   9   12  15  ...
...
```

The pattern:
- Outer loop: rows (1 to 10)
- Inner loop: columns (1 to 10)
- For each row, print all columns

```cpp
for (int row = 1; row <= 10; row++) {
    for (int col = 1; col <= 10; col++) {
        std::cout << row * col << "\t";  // \t is tab
    }
    std::cout << "\n";  // Newline after each row
}
```

How it runs:

```
row = 1:
  col = 1: print 1*1=1
  col = 2: print 1*2=2
  col = 3: print 1*3=3
  ... (all columns)
  newline

row = 2:
  col = 1: print 2*1=2
  col = 2: print 2*2=4
  col = 3: print 2*3=6
  ... (all columns)
  newline

... (all rows)
```

Output:
```
1	2	3	4	5	6	7	8	9	10
2	4	6	8	10	12	14	16	18	20
3	6	9	12	15	18	21	24	27	30
...
```

---

## 5. Do it

1. Open `main.cpp`, fill in every TODO
2. `.\run.ps1 day03`
3. Verify: you see a 10×10 multiplication table

---

## 6. Break it on purpose

1. Change the outer loop to `row <= 5`. What happens? (Only 5 rows instead of 10)
2. Change the inner loop condition to `col < 10` (not `<=`). What's different? (Missing last column)
3. Change `i++` to `i += 2`. What does the table look like? (Rows with odd numbers, columns with even numbers)
4. Remove the `std::cout << "\n";` after the inner loop. What happens? (All numbers on one line)

---

## 7. The rep

```powershell
.\run.ps1 day03 -Rep
```

Rewrite from memory. This time you need to remember the `for` loop syntax and nested loop structure. The rest (include, main, return) is the same as before.
