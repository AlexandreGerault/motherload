# Motherload rebirth

This project is an attempt to recreate a flash game I used to play as a child back then.
We control a digging machine. This digging machine also has the ability to fly.
We can dig in the ground in order to collect ores, sell them and upgrade the machine.
The upgrades allow for more digging power, flying speed etc.

This is a learning project. I don't intend to publish a clone of Motherload.
The original game can still be found online.

## Goals of this project

Practice game development (with SDL as a multimedia library) to understand better
how ECS (entity component system) works. I chosed C++ as I always wanted to make
a game in C++ and I believe this game is simple enough to enjoy working on it and
see some results, while learning bunch of things.

I want to be able to reproduce the basics of the original game. What I want to do
is :

- implement a basic physic system (not a physic engine, I'm focusing on simplicity here) ;
- implement basic collisions ;
- draw stuff to the screen ;
- move in an actual world (side scrolling game) ;
- maybe adding sounds.

I don't plan to actually recreate the whole game, with enemies, events and all.
However, some projects actually recreated the game in popular game engines such as
Unity.

## How to build

I'm not a huge fan of the C++ ecosystem for all that is related to compiling and
dependencies management. However, I used xmake, which I just heard of, and it seems
to work pretty well to start up this project.

### Build

```bash
xmake
```

### Run tests

Ensure you build the project first, then:

```bash
xmake run test
```

### Run the game

Ensure you build the project first, then:

```bash
xmake run motherload
```
