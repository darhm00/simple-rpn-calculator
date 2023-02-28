# Simple RPN Calculator
Simple [RPN](https://en.wikipedia.org/wiki/Reverse_Polish_notation) calculator made in C++

# Tutorial
Before using the calculator we need to compile it, we can compile it with `make`:
```sh
make
```
This command will produce an executable file, execute it, and now we're in the
calculator:
```sh
$ make
$ ./.a.out
Welcome to the Simple RPN Calculator,
Copyright (C) 2023 Dar. H. M.
>>
```
The calculator uses RPN, so every operation must be written like this:

| RPN         | Normal notatation |
|-------------|-------------------|
| `1 1 +`     | `1 + 1`           |
| `1 1 -`     | `1 - 1`           |
| `1 1 + 1 -` | `1 + 1 - 1`       |

If we want to execute one of these expressions we type them in the
prompt (`>>`) and then we press `ENTER`, we don't need to type the
expression in one prompt, we can also put it in several prompts:
```
>> 1
>> 1
>> +
```
is the same as:
```
>> 1 1 +
```
There are 3 operations we can do:
 - Addition (e.g. `1 1 +`) -- arithmetic addition;
 - Subtraction (e.g. `1 1 -`) -- arithmetic subtraction;
 - Output (e.g. `1 #`) -- prints the result;
 - Exit (`.`) -- exits;
**NOTE**: Binary operations require at least 2 elements (`1 +`:
invalid, `1 1 +`: valid), if we don't put enough values the
calculator will throw an error:
```
ERROR: Stack underflow
```
By default operation results are not printed, so to output the
result we type `#`
```
1 1 + #
```
will print:
```
1
```
