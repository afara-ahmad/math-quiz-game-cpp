# Math Quiz Game (C++)

A console math quiz game written in C++. You choose the difficulty and the type of operation, then answer a set of randomly generated questions.

![Game screenshot](Images/screenshot.png)

## Features

- Choose how many questions to answer (1 to 10)
- Four difficulty levels:
  - Easy: numbers from 1 to 10
  - Medium: numbers from 10 to 50
  - Hard: numbers from 50 to 100
  - Mix: a random level for each question
- Five operation types: addition, subtraction, division, multiplication, or a random mix
- Instant feedback after every answer:
  - Green screen for a right answer
  - Red screen (with a beep) for a wrong answer, along with the correct answer
- Final results screen showing pass or fail, the level, the operation type, and the number of right and wrong answers
- Option to play again without restarting the program

## How It Works

- You pass the quiz when your right answers are equal to or more than your wrong answers
- Division questions use integer division, so the answer is the whole number without the remainder (for example, 7 / 2 = 3)

## How to Run

1. Clone the repository:
```
   git clone https://github.com/afara-ahmad/math-quiz-game-cpp.git
```
2. Open `Project2_After.sln` in Visual Studio
3. Press `Ctrl + F5` to build and run

This project runs on Windows, because it uses Windows console commands for colors and clearing the screen.

## What I Practiced

- Enums and structs to model questions and the quiz
- Arrays of structs
- Passing structs by reference
- Random number generation
- Splitting the program into small functions

## Author

Ahmad Afara