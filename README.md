# stdout_dos

Spams all consoles in the system with the message "Hello", hence the name. It denies service of standard outputs, since usually a standard output is bound to a console of some sort.

Run `respawner.exe`, it will automatically spawn `stdout_dos.exe` and with for its termination and then it respawns it forever. This is necesarry since, there is a slight chance that a user closes a console which is currently attached to the `stdout_dos.exe` process which would terminte `stoud_dos.exe`, so it needs to be respawned if this happens any time.
