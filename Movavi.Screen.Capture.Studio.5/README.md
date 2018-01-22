Movavi Screen Capture Studio 5 - Trial => Full Patch
==============
The Movavi Screen Capture Studio is an application allowing one to capture screen activity on a Mac, edit videos, record audio or record the webcam.

There are patches available online for the Windows version, thus' I decided to give the macOS version a try.

Use a Mach-O disassembler of your choice and take a look at the disassembly of the function:

`MacRegistrationControllerWrapper::DaysLeft()`

We could simply replace the first two lines of code with:


```asm
mov eax, 0x5a
ret
```

...in order to get 0x5a (= 90) days of trial period forever. However, for all trial users a watermark gets applied to the video, so this solution isn't quite ideal.

Take a look at the isTrial function of the RegistrationController:

`-[MacRegistrationController isTrial]`

After patching the first two instructions to:

```asm
mov eax, 0
ret
```

The application magically gets licensed without further questions asked (all watermarks and nagscreens are gone, too). The same patch has to be applied for all sub applications of the suite.