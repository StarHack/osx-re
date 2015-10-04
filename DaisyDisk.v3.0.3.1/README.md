DaisyDisk v3.0.3.1 - Blacklist Patch
==============
DaisyDisk is a disk space analyzier. It's a useful tool making it easy to find and delete big files.

There are quite a few serial keys available online, but the problem with shared licenses is that they usually get tagged as compromised and blocked by the developer. Needless to say same goes for fraudulently obtained licenses.

You may use a Mach-O disassembler of your choice and after getting a sneak peek of the disassembly, we'll figure out that dozens of serials can be found in the resources section of the binary. Those serial keys are part of the blacklist and the program will refuse to activate, even though the keys might be valid. There are actually two lists which can be found in the binary - one of them is for compromised keys and the other one is for blocked keys.

In order to bypass the blacklist one could simply overwrite the entire byte range containing the blacklisted keys with dummy values but that wouldn't be a very elegant solution.

Thus we simply search for references to the beginning of each list and find two method called `isRegistrationKeyCompromised` and `isRegistrationKeyBlocked`. Both of these use the corresponding list and use hardcoded values for the length of each list which is being moved to r8d.

My approach was to patch the move command to trick the program into thinking the blacklist has a length of 0 bytes which means:

```asm
-[BlackList isRegistrationKeyCompromised]
mov r8d, 0x3E -> mov r8d, 0x00
```

and

```asm
-[BlackList isRegistrationKeyBlocked]
mov r8d, 0x5 -> mov r8d, 0x00
```

After applying those two changes, one could use any serial key (even those which can be found in the blacklist) in order to successfully register the application.
