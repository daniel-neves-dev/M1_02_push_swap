*This project has been created as part of the 42 curriculum by dneves-d and ------.*

<h1 align="center">📚 push swap</h1>

<p align="center">
  <b>The foundational framework of the 42 curriculum.</b><br>
  ????????????
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-00599C?style=flat-square&logo=c&logoColor=white" alt="Language" />
  <img src="https://img.shields.io/badge/Build-Makefile-9cc2e5?style=flat-square&logo=gnu&logoColor=black" alt="Build" />
  <img src="https://img.shields.io/badge/Norm-v3-success?style=flat-square" alt="Norm" />

</p>

---

## 📋 Description
**Push_swap** is an algorithmic project where a given stack of unique integers must be sorted in ascending order using two stacks (`a` and `b`) and a restricted set of instructions. The goal is to compute and output the shortest possible sequence of operations to perform the sort.

This implementation features a robust complexity-aware architecture. It calculates a mathematical "disorder metric" of the stack at runtime and utilizes four distinct sorting strategies depending on configuration flags and the state of the stack.

---

## Team Contributions
As a mandatory two-learner group project, the workload was divided to ensure both members fully understood all implemented concepts and algorithms:
* **`<login1>`**: Implemented stack data structures, input parsing/error handling, the baseline $O(n^2)$ simple sort, and the disorder computation metric.
* **`<login2>`**: Developed the medium $O(n\sqrt{n})$ and complex $O(n\log n)$ sorting algorithms, the adaptive strategy selector, and the optional `--bench` mode parsing.

---

## Instructions

### Compilation
The project is built using `make`, which compiles the source files with `-Wall -Wextra -Werror`:
```bash
# Compile the push_swap binary
make
```

Execution
Run push_swap by passing a list of integers as arguments:

```bash
./push_swap 2 1 3 6 5 8
```

### Command Line Flags
You can optionally force specific strategies or run the program in benchmark mode:
* --simple: Forces the $O(n^2)$ algorithm.
* --medium: Forces the $O(n\sqrt{n})$ algorithm.
* --complex: Forces the $O(n\log n)$ algorithm.
* --adaptive: (Default) Selects the optimal algorithm automatically based on the measured disorder.
* --bench: Outputs detailed execution statistics (disorder %, selected strategy, and operation counts) to stderr.

./push_swap --bench 4 67 3 87 23

### Algorithms & Technical Choices

1. Disorder Metric Calculation
Before executing any sorting moves, the program calculates the disorder metric of stack a.
The disorder $D$ is a normalized metric **(0 <= D <= 1)** defined by dividing the number of inversions (pairs where a larger number appears before a smaller one)
by the total number of unique pairs:

2. Implemented Strategies
* Simple Algorithm ****: Used for small inputs or baseline sorting. Implements a modified Selection Sort which finds the minimum element in stack a, pushes it to b, and repeats.
* Medium Algorithm ****: Designed to divide the stack dynamically into $\sqrt{n}$ logical chunks/blocks. Elements belonging to the lowest-valued chunks are progressively pushed to stack b to limit search-rotation operations.
* Complex Algorithm ($O(n\log n)$): Adaptation of a Radix Sort (LSD) or Quick Sort with stack partitioning to sort large datasets efficiently within standard recursion limits.

### Custom Adaptive Strategy: 
At runtime, if no strategy flag is explicitly forced, the adaptive selector measures the initial stack's disorder and selects the appropriate algorithm:
* Low Disorder ($D < 0.2$): Runs the Simple $O(n^2)$ algorithm.
* Medium Disorder ($0.2 \le D < 0.5$): Runs the Medium $O(n\sqrt{n})$ algorithm.
* High Disorder ($D \ge 0.5$): Runs the Complex $O(n\log n)$ algorithm.

### Resources
* Knuth, Donald. The Art of Computer Programming, Volume 3: Sorting and Searching.
* Big-O Algorithm Complexity Cheat Sheet.

### 🤖 AI Usage Disclaimer:
As per the 42 ICT training framework rules, AI tools were utilized responsibly during this project:

- **Tasks Assisted:** Conceptual explanations of static pointer arrays, understanding memory management edge cases during errors, and structuring documentation guidelines.

- **Control Practices:** No direct code generation or copy-pasting shortcuts were utilized. Code logic was built manually from foundational reasoning and peer collaboration to prepare for internet-free examination conditions.
All function implementations were written manually.
