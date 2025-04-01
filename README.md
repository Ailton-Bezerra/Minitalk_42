<p align="center">
  <img src="https://github.com/Ailton-Bezerra/Ailton-Bezerra/blob/main/badges/minitalkm.png" alt="gnl 42 project badge"/>
<p align="center">
<p align="center">
  <strong>125/100</strong> 🌟
</p>

## Description
`Minitalk` is a simple client-server messaging system using UNIX signals.
- This implementation uses a global variable to signal when the client should continue sending bits. This approach is more efficient than using `usleep`, which could potentially cause timing-related bugs.

### 1️⃣ Compile the programs:
```sh
make
```
- This will generate the server and client executables.

### 2️⃣ Run the server and send a message
#### Start the server:
```sh
./server
```
- The server will print its PID (Process ID), which is needed to send messages.
Example Output:
```sh
Server PID: 12345
```

Send a message from the client:
- Use the server PID obtained in the previous step to send a message:

```sh
./client 12345 "Hello, Minitalk!"
```

Server Output:
```sh
Hello, Minitalk!
```
---
## Contact Information
For any questions or suggestions, feel free to reach out to me via my [GitHub profile](https://github.com/Ailton-Bezerra).
