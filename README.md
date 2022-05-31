# MiniTalk.                  -->  [minitalk.pdf](https://github.com/athmanenaciri/Minitalk/files/8500851/minitalk.pdf) <--

## Project Information

### About

The purpose of this project is to code a small data exchange program using *UNIX signals*.

### Mandatory

- Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**

### Bonus

- Add reception acknowledgement system
- Support Unicode characters

### Allowed Functions

- [`malloc`]
- [`free`]
- [`write`]
- [`getpid`]
- [`signal`]
- [`sigemptyset & sigaddset`]
- [`sigaction`]
- [`pause`]
- [`kill`]
- [`sleep`]
- [`usleep`]
- [`exit`]

to break my code use : ./client PID $(printf "%.s@" {1..100000})
