# SuperHero
SuperHero Battle Arena is a C++ console game where famous superheroes face off in turn-based combat using attacks, special powers, and magical artifacts. Strategic choices and unique abilities determine who survives the battle!

# 🦸‍♂️ SuperHero Battle Arena

**A console-based C++ game where iconic superheroes fight using attacks, special abilities, and magical artifacts. Each character has unique powers and stats.**

## 🕹️ Gameplay

- Turn-based combat system
- Choose between normal attack, special ability, or using an artifact
- Fight continues until only one superhero remains standing

## 🔧 Features

- 👊 Attack or use special powers
- 🧪 Use magical artifacts like:
  - Health Potion (restore health)
  - Power Amulet (boost power)
  - Cursed Stone (random effects)
- 🧠 Input validation and interactive prompts
- 🧼 Memory management with dynamic allocation and cleanup

## 🛠️ Technologies

- C++ (Standard Library)
- OOP (Object-Oriented Programming)
- Classes & Inheritance
- Polymorphism & Dynamic binding

## 📁 Files

- `main.cpp`: Main game logic and fight loop
- `SuperHero.cpp`: Abstract base class
- `SpiderMan.cpp`, `IronMan.cpp`, `Hulk.cpp`, `DoctorStrange.cpp`: Derived superhero classes
- `Artifact.cpp`, `HealthPotion.cpp`, `PowerAmulet.cpp`, `CursedStone.cpp`: Artifact hierarchy

## ▶️ How to Run

1. Make sure you have a C++ compiler (e.g. `g++`)
2. Compile all files:

   ```bash
   g++ main.cpp SuperHero.cpp SpiderMan.cpp IronMan.cpp Hulk.cpp DoctorStrange.cpp Artifact.cpp HealthPotion.cpp PowerAmulet.cpp CursedStone.cpp -o battle
3. Run the executable:
   ./battle

🧹 Memory Management
All superheroes and artifacts are dynamically allocated and properly deleted at the end of the program to avoid memory leaks.

📜 License
This project is for educational and entertainment purposes. No official affiliation with Marvel or superhero franchises.
